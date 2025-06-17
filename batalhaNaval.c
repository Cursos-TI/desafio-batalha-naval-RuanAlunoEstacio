#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.
    
    //Variável com a colunas do tabuleiro
    char linha[11] = {' ','A','B','C','D','E','F','G','H','I','J'};
    
    //Inicialização tabuleiro
    int tabuleiro [10][10];
    for(int i = 0; i<10 ; i++){
        for(int j = 0; j<10; j++){
            tabuleiro[i][j] = 0;
        }
    }

    //Inicialização dos navios
    int shipA[3] = {3,3,3};
    int shipB[3] = {3,3,3};
    int shipC[3] = {3,3,3};
    int shipD[3] = {3,3,3};

    //Inicialização dos ataques especiais
    int cone[3][5] = {
        {0,0,1,0,0},
        {0,1,1,1,0},
        {1,1,1,1,1}
    };

    int octahedron[3][5] = {
        {0,0,1,0,0},
        {0,1,1,1,0},
        {0,0,1,0,0}
    };

    int cross[3][5] = {
        {0,0,1,0,0},
        {1,1,1,1,1},
        {0,0,1,0,0}
    };

    //inserção do navio horizontal
    for(int i = 0; i < 3; i++){
        tabuleiro[2][5+i] = shipA[i];
    }

    //inserção do navio vertical
    for(int i = 0; i < 3; i++){
        tabuleiro[5+i][8] = shipB[i];
    }
    
    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    //inserção dos navios diagonais
    for(int i = 0; i < 3; i++){
        tabuleiro[2+i][1+i] = shipC[i];
    }

    for(int i = 0; i < 3; i++){
        tabuleiro[8-i][1+i] = shipD[i];
    }

    //Imprime o tabuleiro
    printf(" TABULEIRO BATALHA NAVAL\n");
    for(int i = 0; i <= 10 ; i++){
        printf(" %c", linha[i]);
    }
    for(int i = 0; i< 10; i++){
        if(i<9){
            printf("\n %d ",i+1);
        } else {
            printf("\n%d ",i+1);
        }
        for(int j = 0; j<10; j++){
            printf("%d ", tabuleiro[i][j]);
        }
    }
    printf("\n\n");
    
    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.
    
    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    //Adição do ataque cone ao tabuleiro
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 5; j++){
            if(cone[i][j] == 0){
                continue;
            } else {
                if(tabuleiro[0+i][0+j]==0) {
                    tabuleiro[0+i][0+j] = cone[i][j];
                } else {
                    tabuleiro[0+i][0+j] = 5;
                }
            }
        }
    }

    //Adição do ataque cruz ao tabuleiro
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 5; j++){
            if(cross[i][j] == 0){
                continue;
            } else {
                if(tabuleiro[5+i][5+j]==0){
                    tabuleiro[5+i][5+j] = cross[i][j];
                } else {
                    tabuleiro[5+i][5+j] = 5;
                }
            }
        }
    }

    //Adição do ataque octaedro ao tabuleiro
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 5; j++){
            if(octahedron[i][j] == 0){
                continue;
            } else {
                if(tabuleiro[6+i][0+j]==0){
                    tabuleiro[6+i][0+j] = octahedron[i][j];
                } else {
                    tabuleiro[6+i][0+j] = 5;
                }
            }
        }
    }


    //Imprime o tabuleiro após os ataques
    printf(" TABULEIRO BATALHA NAVAL\n");
    for(int i = 0; i <= 10 ; i++){
        printf(" %c", linha[i]);
    }
    for(int i = 0; i< 10; i++){
        if(i<9){
            printf("\n %d ",i+1);
        } else {
            printf("\n%d ",i+1);
        }
        for(int j = 0; j<10; j++){
            printf("%d ", tabuleiro[i][j]);
        }
    }
    printf("\n\n");

    return 0;
}
