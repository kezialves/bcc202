#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "ordenacao.h"

int leTotalObjetos(int *totalObjetos) {

    scanf("%d", totalObjetos);

    if(*totalObjetos < 1) 
        return 0;

    return 1;
}

int leTotalPontos(int *totalPontos) {
    
    scanf("%d", totalPontos);

    if(*totalPontos < 1) 
        return 0;

    return 1;
}

Objeto * alocaObjetos(int totalObjetos, int totalPontos) {

    Objeto *objetos = (Objeto*) malloc(totalObjetos * sizeof(Objeto));

    alocaPontos(objetos, totalObjetos, totalPontos);

    return objetos;
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

    // A precis??o de compara????o entre dois n??meros de ponto flutuante ?? igual a 0.01
    // Se o m??dulo da diferen??a entre os n??meros for <= 0.01, eles s??o iguais
    // Caso contr??rio, compara-se para ver qual ?? o maior
    // Se A - B > 0.01, A ?? maior
    // Se B - A > 0.01, B ?? maior
    
    // Ordena as dist??ncias de forma decrescente
    if((fabsf(objeto1->distancia - objeto2->distancia)) > 0.01) {

        if((objeto1->distancia - objeto2->distancia) > 0.01)
            return -1;

        else if((objeto2->distancia - objeto1->distancia) > 0.01)
            return 1;
    }

    // Se as dist??ncias forem iguais
    // Ordena os deslocamentos de forma crescente
    else {

        if((fabsf(objeto1->deslocamento - objeto2->deslocamento)) > 0.01) {

            if((objeto1->deslocamento - objeto2->deslocamento) > 0.01)
                return 1;

            else if((objeto2->deslocamento - objeto1->deslocamento) > 0.01)
                return -1;
        }

        // Se os deslocamentos forem iguais
        // Ordena em ordem alfab??tica de forma crescente
        else {

            // A fun????o strcmp retorna a soma dos valores de duas strings
            // Se a soma for == 0, as strings s??o iguais
            // Sen??o, se a soma for < 0, a segunda string ?? maior
            // Sen??o, a soma ?? > 0, ou seja, a primeira string ?? maior
            // A maior string ?? a ??ltima em ordem alfab??tica

            if(strcmp(objeto1->nome, objeto2->nome) > 0)
                return 1;

            else
                return 0;
        }
    }

    return 0;
}

//Shell sort
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

    // Aloca um vetor auxiliar in??cio
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

    // Desaloca um vetor auxiliar in??cio
    desalocaPontos(vetorInicio, fim + 1);
    desalocaObjetos(vetorInicio);

    // Desloca um vetor auxiliar fim
    desalocaPontos(vetorFim, fim + 1);
    desalocaObjetos(vetorFim);
} */