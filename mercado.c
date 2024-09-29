#include <stdio.h>
#include <string.h>

#define MAX_PRODUTOS 100
#define MAX_CARRINHO 50

// Estrutura para representar um produto
typedef struct {
    int codigo;
    char nome[50];
    float preco;
} Produto;

// Estrutura para o carrinho de compras
typedef struct {
    Produto produto;
    int quantidade;
} ItemCarrinho;

// Variáveis globais
Produto estoque[MAX_PRODUTOS];
ItemCarrinho carrinho[MAX_CARRINHO];
int totalProdutos = 0;
int totalItensCarrinho = 0;

// Função para cadastrar um produto1
void cadastrarProduto() {
    if (totalProdutos < MAX_PRODUTOS) {
        Produto novoProduto;
        printf("Digite o código do produto: ");
        scanf("%d", &novoProduto.codigo);
        printf("Digite o nome do produto: ");
        scanf("%s", novoProduto.nome);
        printf("Digite o preço do produto: ");
        scanf("%f", &novoProduto.preco);
        
        estoque[totalProdutos] = novoProduto;
        totalProdutos++;
        printf("Produto cadastrado com sucesso!\n");
    } else {
        printf("Estoque cheio! Não é possível cadastrar mais produtos.\n");
    }
}

// Função para listar os produtos
void listarProdutos() {
    if (totalProdutos > 0) {
        printf("Produtos disponíveis:\n");
        for (int i = 0; i < totalProdutos; i++) {
            printf("Código: %d | Nome: %s | Preço: %.2f\n", estoque[i].codigo, estoque[i].nome, estoque[i].preco);
        }
    } else {
        printf("Nenhum produto cadastrado!\n");
    }
}

// Função para adicionar um produto ao carrinho
void adicionarAoCarrinho() {
    int codigo, quantidade;
    printf("Digite o código do produto que deseja comprar: ");
    scanf("%d", &codigo);

    int encontrado = -1;
    for (int i = 0; i < totalProdutos; i++) {
        if (estoque[i].codigo == codigo) {
            encontrado = i;
            break;
        }
    }

    if (encontrado != -1) {
        printf("Digite a quantidade: ");
        scanf("%d", &quantidade);
        
        if (totalItensCarrinho < MAX_CARRINHO) {
            carrinho[totalItensCarrinho].produto = estoque[encontrado];
            carrinho[totalItensCarrinho].quantidade = quantidade;
            totalItensCarrinho++;
            printf("Produto adicionado ao carrinho!\n");
        } else {
            printf("Carrinho cheio! Não é possível adicionar mais itens.\n");
        }
    } else {
        printf("Produto não encontrado!\n");
    }
}

// Função para visualizar o carrinho
void visualizarCarrinho() {
    if (totalItensCarrinho > 0) {
        printf("Itens no carrinho:\n");
        for (int i = 0; i < totalItensCarrinho; i++) {
            printf("Nome: %s | Quantidade: %d | Preço Unitário: %.2f | Subtotal: %.2f\n",
                   carrinho[i].produto.nome, carrinho[i].quantidade, 
                   carrinho[i].produto.preco, 
                   carrinho[i].quantidade * carrinho[i].produto.preco);
        }
    } else {
        printf("O carrinho está vazio.\n");
    }
}

// Função para fechar o pedido e calcular o total
void fecharPedido() {
    if (totalItensCarrinho > 0) {
        float totalCompra = 0;
        printf("Fatura:\n");
        for (int i = 0; i < totalItensCarrinho; i++) {
            float subtotal = carrinho[i].quantidade * carrinho[i].produto.preco;
            printf("Nome: %s | Quantidade: %d | Preço Unitário: %.2f | Subtotal: %.2f\n",
                   carrinho[i].produto.nome, carrinho[i].quantidade, 
                   carrinho[i].produto.preco, subtotal);
            totalCompra += subtotal;
        }
        printf("Valor total da compra: %.2f\n", totalCompra);
        
        // Limpar o carrinho
        totalItensCarrinho = 0;
        printf("Pedido finalizado com sucesso!\n");
    } else {
        printf("O carrinho está vazio. Não há pedido a ser finalizado.\n");
    }
}

// Função para exibir o menu
void exibirMenu() {
    printf("\n--- Menu ---\n");
    printf("1. Cadastrar Produto\n");
    printf("2. Listar Produtos\n");
    printf("3. Adicionar Produto ao Carrinho\n");
    printf("4. Visualizar Carrinho\n");
    printf("5. Fechar Pedido\n");
    printf("6. Sair\n");
    printf("Escolha uma opção: ");
}

// Função principal
int main() {
    int opcao;
    do {
        exibirMenu();
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                cadastrarProduto();
                break;
            case 2:
                listarProdutos();
                break;
            case 3:
                adicionarAoCarrinho();
                break;
            case 4:
                visualizarCarrinho();
                break;
            case 5:
                fecharPedido();
                break;
            case 6:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 6);

    return 0;
}
