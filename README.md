### Sistema de Inventário de Ferramentas

Descrição do Projeto

Este projeto é um sistema de inventário para gerenciar ferramentas, desenvolvido em C com foco em modularidade. Ele permite cadastrar, listar, atualizar e remover ferramentas, além de salvar e carregar o inventário de um arquivo.

### Funcionalidades

1. Obter o próximo ID disponível
Função para gerar IDs exclusivos automaticamente, incrementando a partir do maior ID atual.


2. Adicionar uma ferramenta ao inventário
Insere novas ferramentas no inventário com informações como nome, quantidade e ID gerado.


3. Atualizar a quantidade de uma ferramenta
Permite modificar a quantidade de uma ferramenta já cadastrada.


4. Listar todas as ferramentas no inventário
Exibe todos os itens cadastrados, mostrando ID, nome e quantidade.


5. Salvar o inventário em um arquivo
Armazena os dados do inventário em um arquivo para garantir persistência.


6. Carregar o inventário de um arquivo
Lê os dados de um arquivo existente e carrega as ferramentas para uso no programa.



### Estrutura do Projeto

inventario.c: Funções principais para operação do sistema.

inventario_functions.c: Funções auxiliares organizadas para facilitar manutenção e expansão.

inventario.h: Arquivo de cabeçalho com definições e protótipos das funções.

CMakeLists.txt: Configuração do CMake para compilação do projeto.


### Como Executar

1. Pré-requisitos: Tenha o CMake e um compilador C instalados.


2. Clone o repositório:

git clone https://github.com/modenadev/ProjetoC.git


3. Compile o projeto:

cd ProjetoC
cmake .
make


4. Execute o programa:

./inventario


