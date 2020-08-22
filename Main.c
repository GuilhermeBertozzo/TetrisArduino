#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void iniciarMatriz();//inicia o campo de jogo com valor 0
void jogar();
void delay(unsigned int milliseconds);
void criarNovaPeca();
void gerarL();

int jogo [20][10];

int main()
{
    iniciarMatriz();
    jogar();
    return 0;     
}


void iniciarMatriz()
{
    for(int i=0; i<20; i++)
    {
        for(int j=0; i<10; i++)
        {
            jogo[i][j] = 0;
        }
    }
}
typedef struct peca
{
   char estado[4][4];
   int posX;
   int posY;
}peca;

void jogar()
{
    int fimDeJogo = 0;
    while(fimDeJogo == 0)
    {
        int pecaCaiu = 0;
        criarNovaPeca();
        while (pecaCaiu == 0)
        {
            clock_t start = clock();
            unsigned int atualEmMillis = start / CLOCKS_PER_SEC * 1000;
            unsigned int fimEmMillis = atualEmMillis + 1000;
            while (atualEmMillis < fimEmMillis)
            {
                clock_t momentoAtual = clock();
                atualEmMillis = momentoAtual / CLOCKS_PER_SEC;
                jogada(getch());
            }
            descerPeca();
        }
    }
}

void criarNovaPeca()
{
    srand(time(0));
    int indice = rand() % 7;
    switch (indice)
    {
        case 0:gerarL();
        break;
        case 1:gerarJ();
        break;
        case 2:gerarS();
        break;
        case 3:gerarZ();
        break;
        case 4:gerarT();
        break;
        case 5:gerarO();
        break;
        case 6:gerarI();
        break;
        default:
        break;
    }

}

void gerarL()
{
    peca pecaAtual;
    pecaAtual.posX = 0;
    pecaAtual.posY = 4;
    pecaAtual.estado[0][0]= 0;
    pecaAtual.estado[0][1]= 0;
    pecaAtual.estado[0][2]= 0;
    pecaAtual.estado[0][3]= 0;
    pecaAtual.estado[1][0]= 0;
    pecaAtual.estado[1][1]= 0;
    pecaAtual.estado[1][2]= 1;
    pecaAtual.estado[1][3]= 0;
    pecaAtual.estado[2][0]= 1;
    pecaAtual.estado[2][1]= 1;
    pecaAtual.estado[2][2]= 1;
    pecaAtual.estado[2][3]= 0;
    pecaAtual.estado[3][0]= 0;
    pecaAtual.estado[3][1]= 0;
    pecaAtual.estado[3][2]= 0;
    pecaAtual.estado[3][3]= 0;
}
/*
    ....
    ..X.
    XXX.
    ....
*/
void gerarI()
{
    peca pecaAtual;
    pecaAtual.posX = 0;
    pecaAtual.posY = 4;
    pecaAtual.estado[0][0]= 1;
    pecaAtual.estado[0][1]= 0;
    pecaAtual.estado[0][2]= 0;
    pecaAtual.estado[0][3]= 0;
    pecaAtual.estado[1][0]= 1;
    pecaAtual.estado[1][1]= 0;
    pecaAtual.estado[1][2]= 0;
    pecaAtual.estado[1][3]= 0;
    pecaAtual.estado[2][0]= 1;
    pecaAtual.estado[2][1]= 0;
    pecaAtual.estado[2][2]= 0;
    pecaAtual.estado[2][3]= 0;
    pecaAtual.estado[3][0]= 1;
    pecaAtual.estado[3][1]= 0;
    pecaAtual.estado[3][2]= 0;
    pecaAtual.estado[3][3]= 0;
} 
/*

    X...
    X...
    X...
    X...
*/
void gerarO()
{
    peca pecaAtual;
    pecaAtual.posX = 0;
    pecaAtual.posY = 4;
    pecaAtual.estado[0][0]= 1;
    pecaAtual.estado[0][1]= 0;
    pecaAtual.estado[0][2]= 0;
    pecaAtual.estado[0][3]= 0;
    pecaAtual.estado[1][0]= 1;
    pecaAtual.estado[1][1]= 0;
    pecaAtual.estado[1][2]= 0;
    pecaAtual.estado[1][3]= 0;
    pecaAtual.estado[2][0]= 1;
    pecaAtual.estado[2][1]= 0;
    pecaAtual.estado[2][2]= 0;
    pecaAtual.estado[2][3]= 0;
    pecaAtual.estado[3][0]= 1;
    pecaAtual.estado[3][1]= 0;
    pecaAtual.estado[3][2]= 0;
    pecaAtual.estado[3][3]= 0;
} 








void delay(unsigned int milliseconds){//funcao que permite criar delays para debugging

    clock_t start = clock();

    while((clock() - start) * 1000 / CLOCKS_PER_SEC < milliseconds);
}

