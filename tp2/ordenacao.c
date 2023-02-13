#include <stdio.h>
#include "ordenacao.h"
#include <math.h>

Objeto ** alocaObjetos(int totalObjetos) {
    
    Objeto *objetos = (Objeto*) malloc(totalObjetos * sizeof(Objeto));

    return objetos;
}

void alocaPontos(Objeto *objetos, int totalObjetos, int totalPontos) {

    for(int i = 0; i < totalObjetos; i++) {
        objetos[i].trajetoria = (Ponto*) malloc(totalPontos * sizeof(Ponto));
    }
}

void desalocaPontos(Objeto *objetos, int totalPontos, int totalObjetos) {
    
    for(int i = 0; i < totalObjetos; i++) {
        for(int j = 0; j < totalPontos; j++) {
            free(objetos[i].trajetoria[j]);
        }
    }
}

void desalocaObjetos(Objeto *objetos, int totalObjetos) {
    
    for(int i = 0; i < totalObjetos; i++) {
        free(objetos[i]);
    }
}

float teoremaPitagoras(int x1, int y1, int x2, int y2) {

    float resultado = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));

    return resultado;
}

void calcularDistancia(Objeto **objetos, int totalObjetos, int totalPontos) {

    float distancia = 0.0;

    for(int i = 0; i < totalObjetos; i++) {
        for(int j = 0; j < totalPontos - 1; j++) {
            distancia += teoremaPitagoras(objetos[i].trajetoria[j].x, objetos[i].trajetoria[j].y, objetos[i].trajetoria[j + 1].x, objetos[i].trajetoria[j + 1].y);
        }

        *objetos[i].distancia = distancia;
        distancia = 0.0;
    }
}

void calcularDeslocamento(Objeto **objetos, int totalObjetos, int totalPontos) {

    for(int i = 0; i < totalObjetos; i++) {
        *objetos[i].deslocamento = teoremaPitagoras(objetos[i].trajetoria[0].x, objetos[i].trajetoria[0].y, objetos[i].trajetoria[totalPontos - 1].x, objetos[i].trajetoria[totalPontos - 1].y);
    }
}

void ordenaVetor(Ponto *vetorTrajetorias) {

}

void imprimeVetor(Objeto *objetos, int totalObjetos) {

    for(int i = 0; i < totalObjetos; i++) {
        printf("%s %.2f %.2f\n", objetos[i].nome, objetos[i].distancia, objetos[i].deslocamento);
    }
}
