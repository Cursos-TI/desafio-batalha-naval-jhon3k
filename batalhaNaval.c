#include <stdio.h>

#define TAM 10
#define NAVIO 3

// Inicializa todas as posições do tabuleiro com 0 (representando água)
void inicializarTabuleiro(int tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

// Verifica se é possível posicionar um navio de determinado tamanho e direção sem sair dos limites ou sobrepor outro navio
int podeColocarNavio(int tabuleiro[TAM][TAM], int linha, int coluna, int tamanho, char direcao) {
    for (int i = 0; i < tamanho; i++) {
        int l = linha, c = coluna;
        if (direcao == 'H') c += i;
        else if (direcao == 'V') l += i;
        else if (direcao == 'D') { l += i; c += i; }
        else if (direcao == 'E') { l += i; c -= i; }

        if (l < 0 || l >= TAM || c < 0 || c >= TAM || tabuleiro[l][c] != 0)
            return 0;
    }
    return 1;
}

// Posiciona o navio no tabuleiro nas coordenadas fornecidas com a direção e tamanho especificados
void colocarNavio(int tabuleiro[TAM][TAM], int linha, int coluna, int tamanho, char direcao) {
    for (int i = 0; i < tamanho; i++) {
        if (direcao == 'H') tabuleiro[linha][coluna + i] = NAVIO;
        else if (direcao == 'V') tabuleiro[linha + i][coluna] = NAVIO;
        else if (direcao == 'D') tabuleiro[linha + i][coluna + i] = NAVIO;
        else if (direcao == 'E') tabuleiro[linha + i][coluna - i] = NAVIO;
    }
}

// Exibe o tabuleiro no console com cabeçalhos de linha (1-10) e coluna (A-J)
void exibirTabuleiro(int tabuleiro[TAM][TAM]) {
    printf("   ");
    for (char c = 'A'; c < 'A' + TAM; c++) {
        printf(" %c", c);
    }
    printf("\n");

    for (int i = 0; i < TAM; i++) {
        printf("%2d ", i + 1);
        for (int j = 0; j < TAM; j++) {
            printf(" %d", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAM][TAM];
    inicializarTabuleiro(tabuleiro);

    // Dois navios horizontais/verticais
    if (podeColocarNavio(tabuleiro, 0, 0, 3, 'H')) colocarNavio(tabuleiro, 0, 0, 3, 'H');
    if (podeColocarNavio(tabuleiro, 2, 2, 3, 'V')) colocarNavio(tabuleiro, 2, 2, 3, 'V');

    // Dois navios diagonais
    if (podeColocarNavio(tabuleiro, 4, 0, 3, 'D')) colocarNavio(tabuleiro, 4, 0, 3, 'D');
    if (podeColocarNavio(tabuleiro, 0, 9, 3, 'E')) colocarNavio(tabuleiro, 0, 9, 3, 'E');

    exibirTabuleiro(tabuleiro);

    return 0;
}