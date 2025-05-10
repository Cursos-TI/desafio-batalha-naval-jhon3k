#include <stdio.h>
#include <stdlib.h>

#define TAM_TAB 10
#define TAM_HAB 5

void inicializarTabuleiro(int tabuleiro[TAM_TAB][TAM_TAB]) {
    for (int i = 0; i < TAM_TAB; i++) {
        for (int j = 0; j < TAM_TAB; j++) {
            tabuleiro[i][j] = 0;
        }
    }
    // Colocar navios (exemplo fixo)
    tabuleiro[2][4] = 3;
    tabuleiro[3][4] = 3;
    tabuleiro[4][4] = 3;
    tabuleiro[5][5] = 3;
    tabuleiro[6][5] = 3;
}

void imprimirTabuleiro(int tabuleiro[TAM_TAB][TAM_TAB]) {
    for (int i = 0; i < TAM_TAB; i++) {
        for (int j = 0; j < TAM_TAB; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Cria matriz em forma de cone
void criarCone(int matriz[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (j >= (TAM_HAB / 2 - i) && j <= (TAM_HAB / 2 + i))
                matriz[i][j] = 1;
            else
                matriz[i][j] = 0;
        }
    }
}

// Cria matriz em forma de cruz
void criarCruz(int matriz[TAM_HAB][TAM_HAB]) {
    int meio = TAM_HAB / 2;
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (i == meio || j == meio)
                matriz[i][j] = 1;
            else
                matriz[i][j] = 0;
        }
    }
}

// Cria matriz em forma de octaedro (losango)
void criarOctaedro(int matriz[TAM_HAB][TAM_HAB]) {
    int meio = TAM_HAB / 2;
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (abs(meio - i) + abs(meio - j) <= meio)
                matriz[i][j] = 1;
            else
                matriz[i][j] = 0;
        }
    }
}

// Aplica a matriz da habilidade ao tabuleiro, respeitando navios
void aplicarHabilidade(int tabuleiro[TAM_TAB][TAM_TAB], int habilidade[TAM_HAB][TAM_HAB], int origemX, int origemY) {
    int offset = TAM_HAB / 2;

    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            int x = origemX + i - offset;
            int y = origemY + j - offset;

            if (x >= 0 && x < TAM_TAB && y >= 0 && y < TAM_TAB) {
                if (habilidade[i][j] == 1 && tabuleiro[x][y] != 3) {
                    tabuleiro[x][y] = 5;
                }
            }
        }
    }
}

int main() {
    int tabuleiro[TAM_TAB][TAM_TAB];
    int cone[TAM_HAB][TAM_HAB], cruz[TAM_HAB][TAM_HAB], octaedro[TAM_HAB][TAM_HAB];

    inicializarTabuleiro(tabuleiro);

    criarCone(cone);
    aplicarHabilidade(tabuleiro, cone, 2, 4); 

    criarCruz(cruz);
    aplicarHabilidade(tabuleiro, cruz, 5, 5); 

    criarOctaedro(octaedro);
    aplicarHabilidade(tabuleiro, octaedro, 7, 2); 

    imprimirTabuleiro(tabuleiro);

    return 0;
}