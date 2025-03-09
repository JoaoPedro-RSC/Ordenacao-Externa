
#include "heap.h"
#include "substituicao.h"

int main() {
/*     Heap heap;
    inicializarHeap(&heap);

    // Criando alguns registros de exemplo
    Aluno a1 = {170838, 34.8, "MT", "CUIABA", "ADMINISTRACAO"};
    Aluno a2 = {111954, 27.5, "MT", "CUIABA", "ADMINISTRACAO"};
    Aluno a3 = {23133, 28.0, "MT", "PRIMAVERA DO LESTE", "ADMINISTRACAO"};
    Aluno a4 = {336015, 46.0, "MT", "PRIMAVERA DO LESTE", "ADMINISTRACAO"};

    // Inserindo no heap
    inserirHeap(&heap, a1);
    inserirHeap(&heap, a2);
    inserirHeap(&heap, a3);
    inserirHeap(&heap, a4);

    printf("Heap antes da remoção:\n");
    imprimirHeap(&heap);

    printf("\nRemovendo os elementos ordenados:\n");
    while (heap.tamanho > 0) {
        Aluno min = removerHeap(&heap);
        printf("%ld %.1f %s %s %s\n", min.numinsc, min.nota, min.estado, min.cidade, min.curso);
    }

    imprimirHeap(&heap); */

    Heap memP;

    FILE* arquivo = fopen("teste.txt", "r");
    FILE *fitasEntrada[19];  // Array de ponteiros para arquivos
    char nomeArquivo[30];     // Buffer para armazenar o nome do arquivo

    for (int j = 0; j < 19; j++) {
        sprintf(nomeArquivo, "fitas/fita%d.txt", j + 1);  // Caminho do arquivo

        // Tenta abrir o arquivo para leitura
        fitasEntrada[j] = fopen(nomeArquivo, "w");

        // Se o arquivo não existir, cria o arquivo
        if (fitasEntrada[j] == NULL) {
            printf("Arquivo %s não encontrado. Criando o arquivo...\n", nomeArquivo);
            fitasEntrada[j] = fopen(nomeArquivo, "w");  // Abre para escrita, cria o arquivo
            if (fitasEntrada[j] == NULL) {
                perror("Erro ao criar o arquivo");
            } else {
                printf("Arquivo %s criado com sucesso!\n", nomeArquivo);
            }
        } else {
            printf("Arquivo %s aberto com sucesso!\n", nomeArquivo);
        }
    }


    //int i = 0;

    selecaoPorSub(arquivo, memP, fitasEntrada);
    


    fclose(arquivo);

        // Fechar os arquivos abertos
        for (int j = 0; j < 19; j++) {
            if (fitasEntrada[j] != NULL) {
                fclose(fitasEntrada[j]);
            }
        }
    
    return 0;
}




