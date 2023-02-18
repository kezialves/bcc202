#include <stdio.h>
#include "ordenacao.h"

int main() {

    int totalObjetos, totalPontos;
    Objeto *objetos;

    scanf("%d %d", &totalObjetos, &totalPontos);

    objetos = alocaObjetos(totalObjetos, totalPontos);

    leObjetos(objetos, totalObjetos, totalPontos);

    calculaDistancia(objetos, totalObjetos, totalPontos);
    calculaDeslocamento(objetos, totalObjetos, totalPontos);

    // mergeSort(objetos, totalPontos, 0, totalObjetos - 1);

    ordenaObjetos(objetos, totalObjetos);

    imprimeVetor(objetos, totalObjetos);

    desalocaObjetos(objetos, totalObjetos);
    
    return 0;
}