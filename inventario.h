// inventario.h
#ifndef INVENTARIO_H
#define INVENTARIO_H

// Definindo a estrutura para representar uma ferramenta
typedef struct {
    int id;
    char nome[100];
    int quantidade;
} Ferramenta;

// Funções para manipulação de inventário
void adicionarFerramenta(Ferramenta *inventario, int *tamanho, const char *nome, int quantidade);
void atualizarQuantidade(Ferramenta *inventario, int tamanho, int id, int quantidade);
void listarFerramentas(Ferramenta *inventario, int tamanho);
void salvarInventario(Ferramenta *inventario, int tamanho);
int carregarInventario(Ferramenta *inventario);

// Função para obter o próximo ID disponível (autoincremento)
int obterProximoId(int tamanho);

#endif // INVENTARIO_H
