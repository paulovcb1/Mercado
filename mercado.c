#include <stdio.h>
#include <string.h>

#define max_produtos 50
#define max_carrinho 50

typedef struct {
    int codigo;
    char nome[50];
    float preco;
} Produto;

typedef struct {
    Produto produto;
    int quantidade;
} ItemCarrinho;

// Variáveis globais
Produto estoque[max_produtos];
ItemCarrinho carrinho[max_carrinho];
int totalProdutos = 0;
int totalItensCarrinhos = 0;
FILE *csv;
FILE *csv_carrinho;

// Função de cadastro de produto
void cadastrarProduto() {
    if (totalProdutos < max_produtos) {
        Produto novoProduto;

        printf("Digite aqui o codigo do produto: ");
        scanf("%d", &novoProduto.codigo);
        printf("Digite aqui o nome do produto: ");
        scanf("%s", novoProduto.nome);
        printf("Digite aqui o preco do produto: ");
        scanf("%f", &novoProduto.preco);

        estoque[totalProdutos] = novoProduto;
        totalProdutos++;
        printf("Produto cadastrado com sucesso!\n");
        system("pause");
        system("cls");
    } else {
        printf("Estoque cheio, não foi possivel cadastrar o produto!\n");
        system("pause");
        system("cls");
    }
}

// Função para listar todos os produtos cadastrados
void listarProdutos() {
    if (totalProdutos > 0) {
        printf("Produtos disponiveis:\n");
        printf("----------------------------------\n");

        for (int i = 0; i < totalProdutos; i++) {
            printf("Codigo: %d || Nome: %s || Preco: %.2f\n", estoque[i].codigo, estoque[i].nome, estoque[i].preco);
        }
        printf("----------------------------------\n");

    } else {
        printf("Não há nenhum produto cadastrado no sistema!\n");
    }

}

// Função para adicionar ao carrinho
void comprarProduto() {
    listarProdutos();
    int codigo, quantidade;

    printf("Digite o codigo do produto: ");
    scanf("%d", &codigo);

    int encontrado = -1;

    for (int i = 0; i < totalProdutos; i++) {
        if (estoque[i].codigo == codigo) {
            encontrado = i;
            break;
        }
    }

    if (encontrado >= 0) {
        printf("Digite a quantidade: ");
        scanf("%d", &quantidade);

        if (totalItensCarrinhos < max_carrinho) {
            carrinho[totalItensCarrinhos].produto = estoque[encontrado];
            carrinho[totalItensCarrinhos].quantidade = quantidade;
            totalItensCarrinhos++;
            printf("Produto adicionado ao carrinho!\n");
        } else {
            printf("Carrinho cheio! Não é possivel adicionar itens\n");
        }
    } else {
        printf("Produto não encontrado\n");
    }

    system("pause");
    system("cls");
}

// Função para visualizar itens do carrinho
void visualizarCompra() {
    if (totalItensCarrinhos > 0) {
        printf("--------------------------------------------------------------------\n");
        for (int i = 0; i < totalItensCarrinhos; i++) {
            printf("Codigo: %d || Quantidade: %d || Produto: %s || Preco unitário: %.2f || Subtotal: %.2f\n",
                   carrinho[i].produto.codigo, carrinho[i].quantidade, carrinho[i].produto.nome, 
                   carrinho[i].produto.preco, carrinho[i].produto.preco * carrinho[i].quantidade);
        }
        printf("--------------------------------------------------------------------\n");
    } else {
        printf("O carrinho está vazio\n");
    }
    system("pause");
    system("cls");
}

// Função para fechar o pedido
void fecharPedido() {
    if (totalItensCarrinhos > 0) {
        float totalCompra = 0;
        printf("Fatura: \n");

        for (int i = 0; i < totalItensCarrinhos; i++) {
            float subtotal = carrinho[i].quantidade * carrinho[i].produto.preco;
            printf("Nome: %s || Preco: %.2f || Quantidade: %d || Subtotal: %.2f\n",
                   carrinho[i].produto.nome, carrinho[i].produto.preco, carrinho[i].quantidade, subtotal);
            totalCompra += subtotal;
        }
        printf("Valor total da compra: %.2f\n", totalCompra);

        totalItensCarrinhos = 0; // Limpa o carrinho
        printf("Pedido finalizado com sucesso\n");
    } else {
        printf("O carrinho está vazio. Não há pedido a ser finalizado.\n");
    }
    system("pause");
    system("cls");
}

   // funcao para verificar se tem o item passado no carrinho
    void temNoCarrinho (int codigo){
        int encontrado = 0;
        for (int i = 0; i < totalItensCarrinhos; i++){
            if (codigo == carrinho[i].produto.codigo){
                printf("O produto ja esta no carrinho!\n");
                printf("Nome: %s || Codigo: %d || Preco: %2.f\n", carrinho[i].produto.nome, carrinho[i].produto.codigo, carrinho[i].produto.preco);
                encontrado = 1;
                break;
            } 
        }
        if(!encontrado){
                printf("Produto nao encontrado no carrinho\n");
        }

    }

    // funcao para verificar existencia do produto com base do id
    void infoProduto(int codigo){
        int encontrado = 0;
        for(int i = 0; i < totalProdutos; i++){
            if(codigo == estoque[i].codigo){
                printf("Produto encontrado!\n");
                printf("Nome: %s || Codigo: %d || Preco: %2.f\n", estoque[i].nome, estoque[i].codigo, estoque[i].preco);
                encontrado = 1;
                break;
            }
        }    
            if(!encontrado){
                printf("Produto nao cadastrado!\n");
            }
        

    }

    void removerItensCarrinho (int codigo){
        
        int encontrado = 1;

        for(int i = 0; i < totalItensCarrinhos; i++){
            if(codigo == carrinho[i].produto.codigo){
                encontrado = i;
                break;
            }
        }

        if(!encontrado){
            for (int i = encontrado; i < totalItensCarrinhos - 1; i++) {
                carrinho[i] = carrinho[i + 1];  // Reajustar a ordem dos itens no carrinho
            }
            totalItensCarrinhos --;

            printf("Produto removido com sucesso\n");
            system("pause");
            system("cls");

        } else{
            printf("Produto nao encontrado no carrinho\n");
            system("pause");
            system("cls");
        }

    }


    void procurarProdutoNoCarrinho() {
        int codigoProduto;
        printf("Insira o codigo do produto\n");
        scanf("%d", &codigoProduto);
        temNoCarrinho(codigoProduto); // Função que verifica se o produto está no carrinho
        system("pause");
        system("cls");
    }


        void procurarProdutoNoEstoque() {
        int codigoProduto;
        printf("Insira o codigo do produto\n");
        scanf("%d", &codigoProduto);
        infoProduto(codigoProduto); // Função que verifica se o produto está no carrinho
        system("pause");
        system("cls");
    }


        void TirarItensDoCarrinho() {
        int codigoProduto;
        printf("Itens do carrinho\n");
        for (int i = 0; i < totalItensCarrinhos; i++){
            printf("Codigo: %d || Nome: %s || Preco: %2.f || Quantidade: %d\n",carrinho[i].produto.codigo, carrinho[i].produto.nome, carrinho[i].produto.preco, carrinho[i].quantidade);
        }
        printf("Insira o codigo do produto que deseha remover\n");
        scanf("%d", &codigoProduto);
        removerItensCarrinho(codigoProduto); // Função que verifica se o produto está no carrinho
        system("pause");
        system("cls");
    }


    void importarExcelCarrinho() {
        float totalCompra = 0;
        FILE *csv_carrinho = fopen("Carrinho.csv", "w");
        if (csv_carrinho == NULL) {
            printf("Erro ao abrir o arquivo!\n");
            return;  
        }

        fprintf(csv_carrinho, "Codigo;Nome;Preco;Quantidade;Subtotal;Total\n");
        
        for (int i = 0; i < totalItensCarrinhos; i++) {
            float subtotal = carrinho[i].produto.preco * carrinho[i].quantidade;
            totalCompra += subtotal;

            fprintf(csv_carrinho, "%d;%s;%.2f;%d;%.2f;%.2f\n", 
                    carrinho[i].produto.codigo, carrinho[i].produto.nome, carrinho[i].produto.preco, 
                    carrinho[i].quantidade, subtotal, totalCompra);
        }

        fclose(csv_carrinho);
        printf("Dados Convertidos com sucesso para o excel!\n");
        system("start Carrinho.csv");  
    }

    void importarExcelProdutos() {
        FILE *csv = fopen("Produtos.csv", "w");
        if (csv == NULL) {
            printf("Erro ao abrir o arquivo!\n");
            return;  
        }

        fprintf(csv, "Codigo;Nome;Preco\n");
        
        for (int i = 0; i < totalProdutos; i++) {
           
            fprintf(csv, "%d;%s;%.2f\n", estoque[i].codigo, estoque[i].nome, estoque[i].preco);
        }

        fclose(csv);
        printf("Dados Convertidos com sucesso para o excel!\n");
        system("start Produtos.csv");  
    }


    void menu_excel() {
        int opcao;
        printf("\n--- Menu ---\n");
        printf("1. Importar Carrinho\n");
        printf("2. Importar Produto\n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                importarExcelCarrinho();
                break;
            case 2: 
                importarExcelProdutos();
                break;
            default:
                printf("Opcao invalida!\n");
                break;
        }
    }


    void editarProduto (int codigo){

            int encontrado_carrinho, encontrado = -1;
            
            for (int i = 0; i < totalProdutos; i++){
                if (codigo == estoque[i].codigo){
                    encontrado = i;
                }
            }
            for (int i2 = 0; i2 < totalItensCarrinhos; i2++) {
                if (codigo == carrinho[i2].produto.codigo){
                    encontrado_carrinho = i2;
            }
            if (encontrado != -1){
                printf("Insira o novo nome do produto: \n");
                scanf("%s", estoque[encontrado].nome);

                printf("Insira o novo preco do produto: \n");
                scanf("%f", &estoque[encontrado].preco);
            
        
                if(encontrado_carrinho != -1){
                    strcpy(carrinho[encontrado_carrinho].produto.nome, estoque[encontrado].nome);
                    carrinho[encontrado_carrinho].produto.preco = estoque[encontrado].preco;
                    visualizarCompra();
                }

            printf("Produto editado com sucesso!\n");

            } else {
                printf("Produto nao encontrado\n");
            }
            system("pause");
            system("cls");
            
        }
    }

    void atualizarProduto () {
        int editarOpcao;
        listarProdutos();

        printf("Digite o codigo do produto que deseja atualizar: \n");
        scanf("%d", &editarOpcao);

        editarProduto(editarOpcao);

    }

    void editarCarrinho (int codigo){
        int encontrado = -1;

        for (int i = 0; i < totalItensCarrinhos; i++){
            if(codigo == carrinho[i].produto.codigo){
                encontrado = i;
                break;
            }
        }
        printf("Digite a nova quantidade: \n");
        scanf("%d", &carrinho[encontrado].quantidade);

    }

    void atualizarCarrinho (){
        int editarOpcao;
        visualizarCompra();

        printf("Digite o codigo do produto que deseja atualizar: \n");
        scanf("%d", &editarOpcao);

        editarCarrinho(editarOpcao);
        
    }

// Menu principal
void exibirMenu() {
    printf("\n--- Menu ---\n");
    printf("1. Cadastrar Produto\n");
    printf("2. Listar Produtos\n");
    printf("3. Informacoes do Produto\n");
    printf("4. Editar Produto\n");
    printf("5. Remover Item do Carrinho\n");
    printf("6. Adicionar Produto ao Carrinho\n");
    printf("7. Visualizar Carrinho\n");
    printf("8. Verificar Produto no Carrinho\n");
    printf("9. Editar Carrinho\n");
    printf("10. Fechar Pedido\n");
    printf("11. Menu Excel\n");
    printf("12. Sair\n");
    printf("Escolha uma opcao: ");
}

void fluxo() {
    int opcao;

    do {
        exibirMenu();
        scanf("%d", &opcao);
        system("cls");
        switch (opcao) {
            case 1:
                cadastrarProduto();
                break;
            case 2:
                listarProdutos();
                system("pause");
                system("cls");
                break;
            case 3:
                procurarProdutoNoEstoque();
                break;
            case 4:
                atualizarProduto();
                break;
            case 5:
                TirarItensDoCarrinho();
                break;
            case 6:
                comprarProduto();
                break;
            case 7:
                visualizarCompra();
                break;
            case 8:
                procurarProdutoNoCarrinho();
                break;
            case 9:
                atualizarCarrinho();
                break;
            case 10:
                fecharPedido();
                break;
            case 11:
                menu_excel();
                break;
            case 12:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao inválida! Tente novamente.\n");
        }
    } while (opcao != 12);
}

int main() {
    fluxo();
    return 0;
}
