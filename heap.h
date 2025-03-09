#ifndef HEAP_H
#define HEAP_H


#include <stdio.h>

typedef struct{
    long int numinsc;
    double nota;
    char estado[3];
    char cidade[51];
    char curso[31];
}Aluno;

typedef struct {
    Aluno dados[19];
    int tamanho;
} Heap;

// Inicializa o heap como tamanho 0
void inicializarHeap(Heap *heap);

// Reconstroi o heap
void heapRefaz(Heap *heap, int indice);

// Função para trocar do is registros no heap
void trocar(Aluno *a, Aluno *b);

// Insere um aluno no heap
void inserirHeap(Heap *heap, Aluno novo);

// Remove um aluno do heap
Aluno removerHeap(Heap *heap);

// Imprime o heap
void imprimirHeap(Heap *heap);


#endif // HEAP_H