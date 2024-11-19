// inventario_functions.c
#include <stdio.h>
#include <string.h>
#include "inventario.h"

// Função para obter o próximo ID disponível (autoincremento)
int obterProximoId(int tamanho) {
    return tamanho + 1;  // O ID será o tamanho atual do inventário + 1
}

// Função para adicionar uma ferramenta ao inventário
void adicionarFerramenta(Ferramenta *inventario, int *tamanho, const char *nome, int quantidade) {
    int novoId = obterProximoId(*tamanho);  // ID autoincrementado

    inventario[*tamanho].id = novoId;
    strcpy(inventario[*tamanho].nome, nome);
    inventario[*tamanho].quantidade = quantidade;
    (*tamanho)++;
}

// Função para atualizar a quantidade de uma ferramenta
void atualizarQuantidade(Ferramenta *inventario, int tamanho, int id, int quantidade) {
    for (int i = 0; i < tamanho; i++) {
        if (inventario[i].id == id) {
            inventario[i].quantidade = quantidade;
            printf("Quantidade atualizada para a ferramenta %d\n", id);
            return;
        }
    }
    printf("Ferramenta nao encontrada!\n");
}

// Função para listar todas as ferramentas no inventário
void listarFerramentas(Ferramenta *inventario, int tamanho) {
    printf("\n--- Lista de Ferramentas ---\n");
    for (int i = 0; i < tamanho; i++) {
        printf("ID: %d | Nome: %s | Quantidade: %d\n", inventario[i].id, inventario[i].nome, inventario[i].quantidade);
    }
}

// Função para salvar o inventário no arquivo
void salvarInventario(Ferramenta *inventario, int tamanho) {
    FILE *arquivo = fopen("inventario.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para salvar!\n");
        return;
    }

    for (int i = 0; i < tamanho; i++) {
        fprintf(arquivo, "%d;%s;%d\n", inventario[i].id, inventario[i].nome, inventario[i].quantidade);
    }

    fclose(arquivo);
}

// Função para carregar o inventário de um arquivo
int carregarInventario(Ferramenta *inventario) {
    FILE *arquivo = fopen("inventario.txt", "r");
    if (arquivo == NULL) {
        printf("Nenhum inventario encontrado, comecando do zero.\n");
        return 0;
    }

    int tamanho = 0;
    while (fscanf(arquivo, "%d;%99[^;];%d\n", &inventario[tamanho].id, inventario[tamanho].nome, &inventario[tamanho].quantidade) == 3) {
        tamanho++;
    }

    fclose(arquivo);
    return tamanho;
}
