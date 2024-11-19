// inventario.c
#include <stdio.h>
#include "inventario.h"

int main() {
    Ferramenta inventario[100];  // Limitar o número de ferramentas
    int tamanho = carregarInventario(inventario);  // Carregar inventário de um arquivo

    int opcao;
    do {
        printf("\n--- Sistema de Inventario de Ferramentas ---\n");
        printf("1. Adicionar ferramenta\n");
        printf("2. Atualizar quantidade\n");
        printf("3. Listar ferramentas\n");
        printf("4. Salvar e sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            int quantidade;
            char nome[100];
            printf("Digite o nome da ferramenta: ");
            getchar();  // Limpar o buffer
            fgets(nome, 100, stdin);
            nome[strcspn(nome, "\n")] = '\0';  // Remover o newline no final
            printf("Digite a quantidade: ");
            scanf("%d", &quantidade);

            adicionarFerramenta(inventario, &tamanho, nome, quantidade);
            printf("Ferramenta %s adicionada com sucesso! ID gerado: %d\n", nome, tamanho);  // Confirmação
        } else if (opcao == 2) {
            int id, quantidade;
            printf("Digite o ID da ferramenta para atualizar a quantidade: ");
            scanf("%d", &id);
            printf("Digite a nova quantidade: ");
            scanf("%d", &quantidade);

            atualizarQuantidade(inventario, tamanho, id, quantidade);
        } else if (opcao == 3) {
            listarFerramentas(inventario, tamanho);
        } else if (opcao == 4) {
            salvarInventario(inventario, tamanho);
            printf("Inventário salvo. Saindo...\n");
        } else {
            printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 4);

    return 0;
}
