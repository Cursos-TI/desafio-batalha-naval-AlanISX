#include <stdio.h>

int main()
{
    // Letras das linhas do tabuleiro
    char linha[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    // Números das colunas do tabuleiro
    int coluna[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // Matriz 10x10 para o estado do tabuleiro
    int tabuleiro[10][10];

    // Inicializando o tabuleiro com 0 (água)
    for (int i = 0; i < 10; i++) {  
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
            printf("%d ", tabuleiro[i][j]); // Imprime o valor inicial
        }
        printf("\n"); // Nova linha após cada linha do tabuleiro
    }

    // Preenchendo navios no tabuleiro
    for (int i = 6; i < 9; i++) {
        tabuleiro[4][i] = 3; // Navio na linha 4, colunas 6 a 8
    }

    for (int i = 6; i < 9; i++) {
        tabuleiro[i][2] = 3; // Navio na coluna 2, linhas 6 a 8
    }

    for (int i = 3; i < 6; i++) {
        tabuleiro[i][i] = 3; // Navio na diagonal primária
    }

    // Diagonal secundária: soma dos índices igual a 9
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (i + j == 9) {
                tabuleiro[i][j] = 3; // Navio na diagonal secundária
            }
        }
    }

    // Exibindo o tabuleiro
    printf("-=- TABULEIRO BATALHA NAVAL -=-\n\n");

    printf("   "); // Alinhamento das colunas
    for (int i = 0; i < 10; i++) {
        printf("%c ", linha[i]); // Letras das colunas
    }
    printf("\n");

    for (int i = 0; i < 10; i++) {
        printf(" %d", coluna[i]); // Números das linhas
        for (int j = 0; j < 10; j++) {
            printf(" %d", tabuleiro[i][j]); // Valores da célula
        }
        printf("\n"); // Nova linha após cada linha do tabuleiro
    }

    return 0; 
}
