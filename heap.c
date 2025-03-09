#include "heap.h"


void inicializarHeap(Heap *heap){
    heap->tamanho = 0;
}

void heapRefaz(Heap *heap, int indice){
    int menor = indice;
    int esq = indice * 2 + 1;
    int dir = esq + 1;

    if(esq < heap->tamanho && heap->dados[esq].nota < heap->dados[menor].nota)
        menor = esq;

    if (dir < heap->tamanho && heap->dados[dir].nota < heap->dados[menor].nota)
        menor = dir;

    if(menor != indice) {
        trocar(&heap->dados[indice], &heap->dados[menor]);
        heapRefaz(heap, menor);
    }
}

// Troca dois alunos de lugar no heap
void trocar(Aluno *a, Aluno *b){
    Aluno temp = *a;
    *a = *b;
    *b = temp;
}

// Função para inserir um novo elemento no heap
void inserirHeap(Heap *heap, Aluno novo) {
    // Verifica se há espaço no heap
    if (heap->tamanho >= 19) {
        printf("Erro: Heap cheio!\n");
        return;
    }

    // Coloca o novo elemento no final do heap
    heap->dados[heap->tamanho] = novo;

    // Aumenta o tamanho do heap
    heap->tamanho++;

    // Reorganiza o heap manualmente
    int indice = heap->tamanho - 1;  // Último índice (novo elemento inserido)
    
    // Enquanto o índice não atingir a raiz e o valor do pai for maior que o atual
    while (indice > 0) {
        int pai = (indice - 1) / 2; // Índice do pai

        // Se o valor do pai é maior que o valor do atual, trocamos
        if (heap->dados[pai].nota > heap->dados[indice].nota) {
            // Utilizando a função troca
            trocar(&heap->dados[pai], &heap->dados[indice]);

            // Atualiza o índice para o pai, pois o elemento subiu para lá
            indice = pai;
        } else {
            break;  // Se o pai não for maior, o heap está em ordem
        }
    }
}

// Remove um aluno heap
Aluno removerHeap(Heap *heap){

    Aluno removido = heap->dados[0];
    
    // A raiz é substituída pelo último item
    heap->dados[0] = heap->dados[heap->tamanho - 1];

    heap->tamanho--;
    
    heapRefaz(heap, 0);

    return removido;
}

void imprimirHeap(Heap *heap) {
    for (int i = 0; i < heap->tamanho; i++) {
        printf("%ld %.1f %s %s %s\n", heap->dados[i].numinsc, heap->dados[i].nota, 
               heap->dados[i].estado, heap->dados[i].cidade, heap->dados[i].curso);
    }
}


