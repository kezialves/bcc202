#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "ordenacao.h"

void alocaObjetos(Objeto *objetos, int totalObjetos, int totalPontos) {

    objetos = (Objeto*) malloc(totalObjetos * sizeof(Objeto));

    alocaPontos(objetos, totalObjetos, totalPontos);
}

void alocaPontos(Objeto *objetos, int totalObjetos, int totalPontos) {

    for(int i = 0; i < totalObjetos; i++) {
        objetos[i].trajetoria = (Ponto*) malloc(totalPontos * sizeof(Ponto));
    }
}

void desalocaPontos(Objeto *objetos, int totalObjetos) {   

    for(int i = 0; i < totalObjetos; i++) {
        free(objetos[i].trajetoria);
    }
}

void desalocaObjetos(Objeto *objetos, int totalObjetos) {

    desalocaPontos(objetos, totalObjetos);

    free(objetos);
}

void leObjetos(Objeto *objetos, int totalObjetos, int totalPontos) {

    for(int i = 0; i < totalObjetos; i++) {
        scanf("%s", objetos[i].nome);

        for(int j = 0; j < totalPontos; j++) {
            scanf("%f %f", &objetos[i].trajetoria[j].x, &objetos[i].trajetoria[j].y);
        }
    }
}

float teoremaPitagoras(int x1, int y1, int x2, int y2) {

    float resultado = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));

    return resultado;
}

void calculaDistancia(Objeto *objetos, int totalObjetos, int totalPontos) {

    float distancia = 0.0;

    for(int i = 0; i < totalObjetos; i++) {
        for(int j = 0; j < totalPontos - 1; j++) {
            distancia += teoremaPitagoras(objetos[i].trajetoria[j].x,
                objetos[i].trajetoria[j].y,
                objetos[i].trajetoria[j + 1].x,
                objetos[i].trajetoria[j + 1].y);
        }

        objetos[i].distancia = distancia;
        distancia = 0.0;
    }
}

void calculaDeslocamento(Objeto *objetos, int totalObjetos, int totalPontos) {

    for(int i = 0; i < totalObjetos; i++) {
        objetos[i].deslocamento = teoremaPitagoras(objetos[i].trajetoria[0].x,
            objetos[i].trajetoria[0].y,
            objetos[i].trajetoria[totalPontos - 1].x,
            objetos[i].trajetoria[totalPontos - 1].y);
    }
}

int comparaObjetos(Objeto *objeto1, Objeto *objeto2) {

    // Analisar se o módulo da diferença entre os dois números é < 0.01
    
    if(objeto1->distancia < objeto2->distancia)
        return -1;

    else if(objeto1->distancia > objeto2->distancia)
        return 1;

    else {

        if(objeto1->deslocamento > objeto2->deslocamento)
            return 1;

        else if(objeto1->deslocamento < objeto2->deslocamento)
            return -1;

        else {

            if(strcmp(objeto1->nome, objeto2->nome) < 0)
                return -1;

            else if(strcmp(objeto1->nome, objeto2->nome) == 0)
                return 0;

            else
                return 1;
        }
    }
}

void ordenaObjetos(Objeto *objetos, int totalObjetos) {

    int h, j;
    Objeto auxiliar;
	
    for(h = 1; h < totalObjetos;) {
        h = 3 * h + 1;
    }

    do {
        h = (h - 1) / 3;

        for(int i = h; i < totalObjetos; i++) {
            auxiliar = objetos[i];
            j = i;

            while(comparaObjetos(&objetos[j - h], &auxiliar) == 1) {
                objetos[j] = objetos[j - h];
                j = j - h;

                if(j < h) {
                    break;
                }
            }

            objetos[j] = auxiliar;
        }
    } while(h != 1);
}

void imprimeVetor(Objeto *objetos, int totalObjetos) {

    for(int i = 0; i < totalObjetos; i++) {
        printf("%s %.2f %.2f\n", objetos[i].nome, objetos[i].distancia, objetos[i].deslocamento);
    }
}

/* void mergeSort(Objeto *objetos, int totalPontos, int inicio, int fim) {

    int meio;
    
    if(inicio < fim) {
        meio = (inicio + fim) / 2;
        mergeSort(objetos, totalPontos, inicio, meio);
        mergeSort(objetos, totalPontos, meio + 1, fim);
        merge(objetos, totalPontos, inicio, meio, fim);
    }
}

void merge(Objeto *objetos, int totalPontos, int inicio, int meio, int fim) {

    int tamanhoInicio, tamanhoFim, i, j, k;
    
    tamanhoInicio = meio - inicio + 1;
    tamanhoFim = fim - meio;

    Objeto *vetorInicio, *vetorFim;

    // Aloca um vetor auxiliar início
    alocaObjetos(&vetorInicio, fim + 1);
    alocaPontos(&vetorInicio, fim + 1, totalPontos);

    // Aloca um vetor auxiliar fim
    alocaObjetos(&vetorFim, fim + 1);
    alocaPontos(&vetorFim, fim + 1, totalPontos);

    for(i = 0; i < tamanhoInicio; i++) {
        vetorInicio = &objetos[i + inicio];
    }

    for(j = 0; j < tamanhoFim; j++) {
        vetorFim = &objetos[j + meio + 1];
    }

    i = 0;
    j = 0;

    for(k = inicio; k <= fim; k++) {

        if(i == tamanhoInicio) {
            objetos[k] = vetorFim[j++];
        }

        else if(j == tamanhoInicio) {
            objetos[k] = vetorInicio[i++];
        }

        else if(comparaObjetos(&vetorInicio[i], &vetorFim[j]) < 1) {
            objetos[k] = vetorInicio[i++];
        }

        else {
            objetos[k] = vetorFim[j++];
        }
    }

    // Desaloca um vetor auxiliar início
    desalocaPontos(vetorInicio, fim + 1);
    desalocaObjetos(vetorInicio);

    // Desloca um vetor auxiliar fim
    desalocaPontos(vetorFim, fim + 1);
    desalocaObjetos(vetorFim);
} */