#include <stdio.h>
#include "ordenacao.h"

int main() {

    int totalObjetos, totalPontos;
    Objeto *objetos;

    if(!leTotalObjetos(&totalObjetos)) {
        printf("\nERRO: Número de objetos inválido. O mínimo é 1.\n");
        return 0;
    }

    if(!leTotalPontos(&totalPontos)) {
        printf("\nERRO: Número de pontos inválido. O mínimo é 1.\n");
        return 0;
    }

    objetos = alocaObjetos(totalObjetos, totalPontos);

    leObjetos(objetos, totalObjetos, totalPontos);

    calculaDistancia(objetos, totalObjetos, totalPontos);
    calculaDeslocamento(objetos, totalObjetos, totalPontos);

    // mergeSort(objetos, totalPontos, 0, totalObjetos - 1);

    // Se tiver apenas 1 objeto, não é necessário ordenar
    if(totalObjetos != 1)
        ordenaObjetos(objetos, totalObjetos);

    imprimeVetor(objetos, totalObjetos);

    desalocaObjetos(objetos, totalObjetos);
    
    return 0;
}