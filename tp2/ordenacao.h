#ifndef _ORDENACAO_H_
#define _ORDENACAO_H_

// TAD que armazena os dados de um objeto
typedef struct {
    char nome[4];
    Ponto *trajetoria;
    float distancia;
    float deslocamento;
} Objeto;

// TAD que armazena as coordenadas de um ponto
typedef struct {
    float x;
    float y;
} Ponto;

// aloca um vetor de TAD Objeto
Objeto ** alocaObjetos(int totalObjetos);

// aloca um vetor de TAD Ponto
void alocaPontos(Objeto *objetos, int totalObjetos, int totalPontos);

// desaloca um vetor de TAD Ponto
void desalocaPontos(Objeto *objetos, int totalPontos, int totalObjetos);

// desaloca os objetos
void desalocaObjetos(Objeto *objetos, int totalObjetos);

// apenas Pitágoras
float teoremaPitagoras(int x1, int y1, int x2, int y2);

//  calcula a distância percorrida considerando os pontos que estão em um vetor de TAD Ponto
void calcularDistancia(Objeto **objetos, int totalObjetos, int totalPontos);

// calcula o deslocamento considerando os pontos que estão em um vetor de TAD Ponto
void calcularDeslocamento(Objeto **objetos, int totalObjetos, int totalPontos);

// ordena um vetor de trajetórias, onde cada trajetória é um vetor de TAD Ponto
void ordenaVetor(Ponto *vetorTrajetorias);

// imprime o vetor de TAD Ponto ordenado
void imprimeVetor(Objeto *objetos, int totalObjetos);

#endif