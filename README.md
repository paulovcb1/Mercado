# Sistema de Supermercado

> Um sistema simples de gerenciamento de supermercado que utiliza estruturas de dados, como structs, arrays e funções, implementado na linguagem C.

---

## Índice

- [Sobre o Projeto](#sobre-o-projeto)
- [Funcionalidades](#funcionalidades)
- [Requisitos](#requisitos)
- [Instalação e Execução](#instalacao-e-execucao)
- [Como Usar](#como-usar)
- [Estrutura do Projeto](#estrutura-do-projeto)
- [Exemplos de Uso](#exemplos-de-uso)
- [Contribuição](#contribuicao)
- [Licença](#licenca)
- [Contato](#contato)

---

## Sobre o Projeto

Este projeto é um sistema simples de supermercado, implementado em C, que permite realizar operações como cadastro de produtos, adição de itens ao carrinho, visualização do carrinho e fechamento do pedido. O código utiliza estruturas como `struct` para organizar as informações de produtos e itens no carrinho, além de conceitos de arrays e funções.

## Funcionalidades

- Cadastrar produtos no sistema.
- Listar todos os produtos disponíveis.
- Adicionar produtos ao carrinho de compras.
- Visualizar os itens no carrinho de compras.
- Fechar pedido e calcular o valor total da compra.
- Remover itens do carrinho.
- Exportar dados para arquivos CSV.

## Estrutura de Dados

- **Structs**
  - `codigo`: Código único do produto.
  - `nome`: Nome do produto
  - `preco`: Preço do produto
- **Item Carrinho**:
  - `produto`: Um produto da struct Produto.
  - `quantidade`: Quantidade do produto adicionada ao carrinho.
- **Arrays**:
  - `estoque[MAX_PRODUTOS]`: Um array que armazena os produtos cadastrados.
  - `carrinho[MAX_CARRINHO]`: Um array que armazena os itens adicionados ao carrinho.
 
## Exportação para uma planilha
O sistema permite exportar as listas de produtos e carrinho de compras para arquivos CSV:
- **Atenção** no caso de compilar o codigo em um compilador online as funcoes de exportar para planilhas não funcionará corretamente

## Requisitos

- **Linguagem de Programação**: C
- **Compilador**: GCC ou qualquer outro compilador que suporte a linguagem C.
- **Sistema Operacional**: Windows ou Linux (em Linux/MacOs, substitua o comando `system("cls")` por `system("clear")`).

## Instalação e Execução

```Bash
Clone o repositorio em seu computador usando o seguinte comando
git clone https://github.com/paulovcb1/Mercado/tree/main "nome-da-pasta"




