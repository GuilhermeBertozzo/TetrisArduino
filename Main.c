#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int **iniciarCampoDeJogo();  //inicia o campo de jogo com valor 0 // feito
void jogar(int **campoDeJogo);
void delay(unsigned int milliseconds);  // feito
void criarNovaPeca();                   //
void gerarL();
void gerarJ();
void gerarS();
void gerarZ();
void gerarT();
void gerarO();
void gerarI();
void renderizar(int **campoDeJogo);
void descerPeca();
void jogada(char);

int main() {
    int **campoDeJogo = iniciarCampoDeJogo();
    renderizar(campoDeJogo);
    jogar(campoDeJogo);
    free(campoDeJogo);
    return 0;
}

int** iniciarCampoDeJogo() {
    int **campoDeJogo;
    campoDeJogo = malloc(20 * sizeof(int*));
    for (int i = 0; i < 20; i++) {
        campoDeJogo[i] = malloc(10 * sizeof(int));
    }
    for(int i = 0; i < 20; i++){
        for(int j = 0; j < 10; j++){
            campoDeJogo[i][j] = 0;
        }
    }
    
    return campoDeJogo;
}
typedef struct peca {
    char estado[4][4];
    int posX;
    int posY;
} peca;

void jogar(int **campoDeJogo) {
    int fimDeJogo = 0;
    while (!fimDeJogo) {
        int pecaCaiu = 0;
        criarNovaPeca();
        while (!pecaCaiu) {
            clock_t start = clock();
            unsigned int atualEmMillis = start / CLOCKS_PER_SEC * 1000;
            unsigned int fimEmMillis = atualEmMillis + 1000;
            while (atualEmMillis < fimEmMillis) {
                clock_t momentoAtual = clock();
                atualEmMillis = momentoAtual / CLOCKS_PER_SEC;
            }
            descerPeca();
            renderizar(campoDeJogo);
        }
    }
}

void jogada(char tecla) {
    return;
}
void descerPeca() {
    return;
}
void criarNovaPeca() {
    srand(time(NULL));
    int indice = rand() % 7;
    switch (indice) {
        case 0:
            gerarL();
            break;
        case 1:
            gerarJ();
            break;
        case 2:
            gerarS();
            break;
        case 3:
            gerarZ();
            break;
        case 4:
            gerarT();
            break;
        case 5:
            gerarO();
            break;
        case 6:
            gerarI();
            break;
        default:
            break;
    }
}

void renderizar(int **campoDeJogo) {
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", campoDeJogo[i][j]);
        }
        printf("\n");
    }
}

void gerarL() {
    peca pecaAtual;
    pecaAtual.posX = 0;
    pecaAtual.posY = 4;
    pecaAtual.estado[0][0] = 0;
    pecaAtual.estado[0][1] = 0;
    pecaAtual.estado[0][2] = 0;
    pecaAtual.estado[0][3] = 0;
    pecaAtual.estado[1][0] = 0;
    pecaAtual.estado[1][1] = 0;
    pecaAtual.estado[1][2] = 1;
    pecaAtual.estado[1][3] = 0;
    pecaAtual.estado[2][0] = 1;
    pecaAtual.estado[2][1] = 1;
    pecaAtual.estado[2][2] = 1;
    pecaAtual.estado[2][3] = 0;
    pecaAtual.estado[3][0] = 0;
    pecaAtual.estado[3][1] = 0;
    pecaAtual.estado[3][2] = 0;
    pecaAtual.estado[3][3] = 0;
}
/*
     0123
    0....
    1..X.
    2XXX.
    3....
*/
void gerarI() {
    peca pecaAtual;
    pecaAtual.posX = 0;
    pecaAtual.posY = 4;
    pecaAtual.estado[0][0] = 0;
    pecaAtual.estado[0][1] = 0;
    pecaAtual.estado[0][2] = 1;
    pecaAtual.estado[0][3] = 0;
    pecaAtual.estado[1][0] = 0;
    pecaAtual.estado[1][1] = 0;
    pecaAtual.estado[1][2] = 1;
    pecaAtual.estado[1][3] = 0;
    pecaAtual.estado[2][0] = 0;
    pecaAtual.estado[2][1] = 0;
    pecaAtual.estado[2][2] = 1;
    pecaAtual.estado[2][3] = 0;
    pecaAtual.estado[3][0] = 0;
    pecaAtual.estado[3][1] = 0;
    pecaAtual.estado[3][2] = 1;
    pecaAtual.estado[3][3] = 0;
}
/*
     0123
    0..X.
    1..X.
    2..X.
    3..X.
*/

void gerarO() {
    peca pecaAtual;
    pecaAtual.posX = 0;
    pecaAtual.posY = 4;
    pecaAtual.estado[0][0] = 0;
    pecaAtual.estado[0][1] = 0;
    pecaAtual.estado[0][2] = 0;
    pecaAtual.estado[0][3] = 0;
    pecaAtual.estado[1][0] = 0;
    pecaAtual.estado[1][1] = 1;
    pecaAtual.estado[1][2] = 1;
    pecaAtual.estado[1][3] = 0;
    pecaAtual.estado[2][0] = 0;
    pecaAtual.estado[2][1] = 1;
    pecaAtual.estado[2][2] = 1;
    pecaAtual.estado[2][3] = 0;
    pecaAtual.estado[3][0] = 0;
    pecaAtual.estado[3][1] = 0;
    pecaAtual.estado[3][2] = 0;
    pecaAtual.estado[3][3] = 0;
}
/*
     0123
    0....
    1.XX.
    2.XX.
    3....
*/

void gerarT() {
    peca pecaAtual;
    pecaAtual.posX = 0;
    pecaAtual.posY = 4;
    pecaAtual.estado[0][0] = 0;
    pecaAtual.estado[0][1] = 0;
    pecaAtual.estado[0][2] = 0;
    pecaAtual.estado[0][3] = 0;
    pecaAtual.estado[1][0] = 0;
    pecaAtual.estado[1][1] = 0;
    pecaAtual.estado[1][2] = 0;
    pecaAtual.estado[1][3] = 0;
    pecaAtual.estado[2][0] = 0;
    pecaAtual.estado[2][1] = 1;
    pecaAtual.estado[2][2] = 0;
    pecaAtual.estado[2][3] = 0;
    pecaAtual.estado[3][0] = 1;
    pecaAtual.estado[3][1] = 1;
    pecaAtual.estado[3][2] = 1;
    pecaAtual.estado[3][3] = 0;
}
/*
     0123    
    0....
    1....
    2.X..
    3XXX.
*/

void gerarJ() {
    peca pecaAtual;
    pecaAtual.posX = 0;
    pecaAtual.posY = 4;
    pecaAtual.estado[0][0] = 0;
    pecaAtual.estado[0][1] = 0;
    pecaAtual.estado[0][2] = 0;
    pecaAtual.estado[0][3] = 0;
    pecaAtual.estado[1][0] = 1;
    pecaAtual.estado[1][1] = 0;
    pecaAtual.estado[1][2] = 0;
    pecaAtual.estado[1][3] = 0;
    pecaAtual.estado[2][0] = 1;
    pecaAtual.estado[2][1] = 1;
    pecaAtual.estado[2][2] = 1;
    pecaAtual.estado[2][3] = 0;
    pecaAtual.estado[3][0] = 0;
    pecaAtual.estado[3][1] = 0;
    pecaAtual.estado[3][2] = 0;
    pecaAtual.estado[3][3] = 0;
}
/*
     0123    
    0....
    1X...
    2XXX.
    3....
*/

void gerarS() {
    peca pecaAtual;
    pecaAtual.posX = 0;
    pecaAtual.posY = 4;
    pecaAtual.estado[0][0] = 0;
    pecaAtual.estado[0][1] = 0;
    pecaAtual.estado[0][2] = 0;
    pecaAtual.estado[0][3] = 0;
    pecaAtual.estado[1][0] = 0;
    pecaAtual.estado[1][1] = 1;
    pecaAtual.estado[1][2] = 1;
    pecaAtual.estado[1][3] = 0;
    pecaAtual.estado[2][0] = 1;
    pecaAtual.estado[2][1] = 1;
    pecaAtual.estado[2][2] = 0;
    pecaAtual.estado[2][3] = 0;
    pecaAtual.estado[3][0] = 0;
    pecaAtual.estado[3][1] = 0;
    pecaAtual.estado[3][2] = 0;
    pecaAtual.estado[3][3] = 0;
}
/*
     0123    
    0....
    1.XX.
    2XX..
    3....
*/

void gerarZ() {
    peca pecaAtual;
    pecaAtual.posX = 0;
    pecaAtual.posY = 4;
    pecaAtual.estado[0][0] = 0;
    pecaAtual.estado[0][1] = 0;
    pecaAtual.estado[0][2] = 0;
    pecaAtual.estado[0][3] = 0;
    pecaAtual.estado[1][0] = 1;
    pecaAtual.estado[1][1] = 1;
    pecaAtual.estado[1][2] = 0;
    pecaAtual.estado[1][3] = 0;
    pecaAtual.estado[2][0] = 0;
    pecaAtual.estado[2][1] = 1;
    pecaAtual.estado[2][2] = 1;
    pecaAtual.estado[2][3] = 0;
    pecaAtual.estado[3][0] = 0;
    pecaAtual.estado[3][1] = 0;
    pecaAtual.estado[3][2] = 0;
    pecaAtual.estado[3][3] = 0;
}
/*
     0123    
    0....
    1XX..
    2.XX.
    3....
*/

void delay(unsigned int milliseconds) {  //funcao que permite criar delays para debugging

    clock_t start = clock();

    while ((clock() - start) * 1000 / CLOCKS_PER_SEC < milliseconds)
        ;
}