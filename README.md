# Sistema de Supermercado

> Um sistema simples de gerenciamento de supermercado que utiliza estruturas de dados, como structs, arrays e funções, implementado na linguagem C.

![Licença](https://img.shields.io/badge/license-MIT-blue.svg)
---

## Índice

- [Sobre o Projeto](#sobre-o-projeto)
- [Funcionalidades](#funcionalidades)
- [Requisitos](#requisitos)
- [Exportação para uma planilha](#Exportação-para-uma-planilha)
- [Instalação e Execução](#Instalação-e-Execução)

---

## Sobre o Projeto

Este projeto é um sistema simples de supermercado, implementado em C, que permite realizar operações como cadastro de produtos, adição de itens ao carrinho, visualização do carrinho e fechamento do pedido. O código utiliza estruturas como struct para organizar as informações de produtos e itens no carrinho, além de conceitos de arrays e funções.

## Funcionalidades

- Cadastrar produtos no sistema.
- Listar todos os produtos disponíveis.
- Adicionar produtos ao carrinho de compras.
- Editar Produtos.
- Editar Produtos do carrinho.
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
 
## Funções Principais
- **Cadastrar Produto** `(cadastrarProduto())`: Adiciona um novo produto ao estoque.
- **Listar Produtos** `(listarProdutos())`: Exibe todos os produtos cadastrados no sistema.
- **Comprar Produto** `(comprarProduto())`: Adiciona produtos ao carrinho utilizando o código do produto.
- **Visualizar Carrinho** `(visualizarCompra())`: Exibe todos os itens no carrinho de compras, com suas quantidades e subtotais.
- **Fechar Pedido** `(fecharPedido())`: Finaliza o pedido, exibe o valor total e esvazia o carrinho.
- **Remover Produto do Carrinho** `(removerItensCarrinho())`: Remove um produto do carrinho com base no código do produto.
- **Exportar para CSV**:
  - `importarExcelCarrinho()`: Exporta os itens do carrinho para um arquivo CSV.
  - `importarExcelProdutos()`: Exporta os produtos cadastrados no estoque para um arquivo CSV.
- **Verificar Produto no Estoque** `(infoProduto(int codigo))`: Verifica se um produto com determinado código existe no estoque.
- **Verificar Produto no Carrinho** `(temNoCarrinho(int codigo))`: Verifica se um produto com determinado código está no carrinho.
 
## Exportação para uma planilha
O sistema permite exportar as listas de produtos e carrinho de compras para arquivos CSV:
- **Atenção** no caso de compilar o codigo em um compilador online as funções de exportar para planilhas não funcionaram corretamente

## Requisitos

- **Linguagem de Programação**: C
- **Compilador**: GCC ou qualquer outro compilador que suporte a linguagem C.
- **Sistema Operacional**: Windows ou Linux (em Linux/MacOs, substitua o comando `system("cls")` por `system("clear")`).
- **Atenção** no caso de compilar o codigo em um compilador online algumas funções da biblioteca `<stdli.h>` como `system("cls")` e `system("pause")` não funcionaram corretamente

## Instalação e Execução

**Arquivo Executavel** 
  - Baixe o arquivo executavel e o execute

**Codigo Fonte**
  - Caso tenha o GIT instalado em sua maquina
  - Clone o repositorio usando o seguinte comando
```Bash
git clone https://github.com/paulovcb1/Mercado "nome-da-pasta"




