#ifndef _ORDENACAO_H_
#define _ORDENACAO_H_

// TAD que armazena as coordenadas de um ponto
typedef struct {
    float x;
    float y;
} Ponto;

// TAD que armazena os dados de um objeto
typedef struct {
    char nome[5];
    Ponto *trajetoria;
    float distancia;
    float deslocamento;
} Objeto;

// Aloca um vetor de TAD Objeto
Objeto * alocaObjetos(int totalObjetos, int totalPontos);

// Aloca um vetor de TAD Ponto
void alocaPontos(Objeto *objetos, int totalObjetos, int totalPontos);

// Desaloca um vetor de TAD Ponto
void desalocaPontos(Objeto *objetos, int totalObjetos);

// Desaloca os objetos
void desalocaObjetos(Objeto *objetos, int totalObjetos);

// Lê e preenche o vetor de TAD Objeto
void leObjetos(Objeto *objetos, int totalObjetos, int totalPontos);

// Apenas Pitágoras
float teoremaPitagoras(int x1, int y1, int x2, int y2);

// Calcula a distância percorrida considerando os pontos que estão em um vetor de TAD Ponto
void calculaDistancia(Objeto *objetos, int totalObjetos, int totalPontos);

// Calcula o deslocamento considerando os pontos que estão em um vetor de TAD Ponto
void calculaDeslocamento(Objeto *objetos, int totalObjetos, int totalPontos);

// Compara os nomes dos objetos para colocar em ordem alfabética
int comparaObjetos(Objeto *objeto1, Objeto *objeto2);

// Ordena um vetor de objetos utilizando o ShellSort
void ordenaObjetos(Objeto *objetos, int totalObjetos);

// Imprime o vetor de TAD Objeto ordenado
void imprimeVetor(Objeto *objetos, int totalObjetos);

// Ordena um vetor de objetos utilizando o MergeSort
// void mergeSort(Objeto *objetos, int totalPontos, int inicio, int fim);

// Auxiliar do MergeSort
// void merge(Objeto *objetos, int totalPontos, int inicio, int meio, int fim);

#endif