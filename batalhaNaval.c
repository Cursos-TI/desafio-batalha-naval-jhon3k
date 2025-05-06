#include <stdio.h>

int main() {
    int tabuleiro[10][10] = {0}; // Inicializa tudo com 0
    int linha, coluna;
    char colunaChar;

    // POSICIONAR NAVIO HORIZONTAL
    printf("Posicione o navio HORIZONTAL (3 posições).\n");
    while (1) {
        printf("Digite a linha (1-10): ");
        scanf("%d", &linha);
        printf("Digite a coluna inicial (A-H): "); // A-H para caber 3 colunas
        scanf(" %c", &colunaChar);
        coluna = colunaChar - 'A';

        if (linha >= 1 && linha <= 10 && coluna >= 0 && coluna <= 7) {
            linha -= 1; // Ajusta para índice 0
            // Posiciona o navio horizontal
            if (tabuleiro[linha][coluna] == 0 &&
                tabuleiro[linha][coluna + 1] == 0 &&
                tabuleiro[linha][coluna + 2] == 0) {
                for (int i = 0; i < 3; i++) {
                    tabuleiro[linha][coluna + i] = 3;
                }
                break;
            } else {
                printf("As posições já estão ocupadas. Tente novamente.\n");
            }
        } else {
            printf("Coordenada inválida. Tente novamente.\n");
        }
    }

    // POSICIONAR NAVIO VERTICAL
    printf("\nPosicione o navio VERTICAL (3 posições).\n");
    while (1) {
        printf("Digite a linha inicial (1-8): "); // 1-8 para caber 3 linhas
        scanf("%d", &linha);
        printf("Digite a coluna (A-J): ");
        scanf(" %c", &colunaChar);
        coluna = colunaChar - 'A';

        if (linha >= 1 && linha <= 8 && coluna >= 0 && coluna <= 9) {
            linha -= 1;
            // Verifica se as posições estão livres
            if (tabuleiro[linha][coluna] == 0 &&
                tabuleiro[linha + 1][coluna] == 0 &&
                tabuleiro[linha + 2][coluna] == 0) {
                for (int i = 0; i < 3; i++) {
                    tabuleiro[linha + i][coluna] = 3;
                }
                break;
            } else {
                printf("As posições já estão ocupadas. Tente novamente.\n");
            }
        } else {
            printf("Coordenada inválida. Tente novamente.\n");
        }
    }

    // EXIBIR TABULEIRO
    printf("\nTabuleiro Batalha Naval:\n\n");

    // Cabeçalho com letras A-J
    printf("   ");
    for (char c = 'A'; c <= 'J'; c++) {
        printf(" %c", c);
    }
    printf("\n");

    // Corpo do tabuleiro
    for (int i = 0; i < 10; i++) {
        printf("%2d ", i + 1); // rótulo da linha
        for (int j = 0; j < 10; j++) {
            printf(" %d", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}