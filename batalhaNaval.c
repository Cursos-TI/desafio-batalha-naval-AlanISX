#include <stdio.h>
#include <stdlib.h> // Para usar abs()

int main() {
    // Letras das linhas do tabuleiro
    char linha[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    // Números das colunas do tabuleiro
    int coluna[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // Matriz 10x10 para o estado do tabuleiro
    int tabuleiro[10][10] = {0}; // Inicializando o tabuleiro com 0 (água)

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

    // Definindo os pontos de origem para cada habilidade
    int origemCone[2] = {0, 2}; // Ponto de origem do Cone
    int origemCruz[2] = {4, 4}; // Ponto de origem da Cruz
    int origemOctaedro[2] = {3, 3}; // Ponto de origem do Octaedro

    // Criando a habilidade Cone (5x5)
    int cone[5][5] = {0}; // Inicializa a matriz do cone
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j <= i; j++) {
            cone[i][j] = 1; // Marca a área afetada
            cone[i][4 - j] = 1; // Marca a área afetada
        }
    }

    // Sobrepondo a habilidade Cone no tabuleiro
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (cone[i][j] == 1) { // Se a posição é afetada
                int linha = origemCone[0] + i;
                int coluna = origemCone[1] + j;
                if (linha < 10 && coluna < 10) {
                    tabuleiro[linha][coluna] = 5; // Marca no tabuleiro
                }
            }
        }
    }

    // Criando a habilidade Cruz (5x5)
    int cruz[5][5] = {0}; // Inicializa a matriz da cruz
    for (int i = 0; i < 5; i++) {
        cruz[2][i] = 1; // Marca horizontal
        cruz[i][2] = 1; // Marca vertical
    }

    // Sobrepondo a habilidade Cruz no tabuleiro
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (cruz[i][j] == 1) { // Se a posição é afetada
                int linha = origemCruz[0] - 2 + i; // Ajusta para o centro
                int coluna = origemCruz[1] - 2 + j; // Ajusta para o centro
                if (linha >= 0 && linha < 10 && coluna >= 0 && coluna < 10) {
                    tabuleiro[linha][coluna] = 5; // Marca no tabuleiro
                }
            }
        }
    }

    // Criando a habilidade Octaedro (5x5)
    int octaedro[5][5] = {0}; // Inicializa a matriz do octaedro
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (abs(2 - i) + abs(2 - j) <= 2) { // Verifica o formato losango
                octaedro[i][j] = 1; // Marca a área afetada
            }
        }
    }

    // Sobrepondo a habilidade Octaedro no tabuleiro
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (octaedro[i][j] == 1) { // Se a posição é afetada
                int linha = origemOctaedro[0] - 2 + i; // Ajusta para o centro
                int coluna = origemOctaedro[1] - 2 + j; // Ajusta para o centro
                if (linha >= 0 && linha < 10 && coluna >= 0 && coluna < 10) {
                    tabuleiro[linha][coluna] = 5; // Marca no tabuleiro
                }
            }
        }
    }

    // Exibindo o tabuleiro
    printf("-=- TABULEIRO BATALHA NAVAL -=-\n\n");

    // Imprimindo a letra das colunas
    printf("   "); 
    for (int i = 0; i < 10; i++) {
        printf("%c ", linha[i]);
    }
    printf("\n");

    // Imprimindo as linhas do tabuleiro com números
    for (int i = 0; i < 10; i++) {
        printf(" %d", coluna[i]);
        for (int j = 0; j < 10; j++) {
            printf(" %d", tabuleiro[i][j]); // Valores da célula
        }
        printf("\n");
    }

    return 0; 
}
