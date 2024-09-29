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


 Produto estoque [max_produtos];
 ItemCarrinho carrinho [max_carrinho];
 int totalProdutos = 0;
 int totalItensCarrinhos = 0;


 
    void cadastrarProduto(){
        if (totalProdutos < max_produtos){
            Produto novoProduto;

            printf("Digite aqui o codigo do produto: ");
            scanf("%d", &novoProduto.codigo);
            printf("Digite aqui o nome do produto: ");
            scanf("%s", novoProduto.nome);
            printf("Digite aqui o preco do produto: ");
            scanf("%f", &novoProduto.preco);

            estoque[totalProdutos] = novoProduto;
            totalProdutos++;
            printf("produto cadastrado com sucesso!");
        } else {
            printf("Estoque cheio, nao foi possivel cadastrar o produto!\n");
        }
    }

    void listarProdutos (){
        if(totalProdutos > 0){
            printf("Produtos disponiveis:\n");

            for (int i = 0; i < totalProdutos; i++){
                printf("Codigo: %d || Nome: %s || preco: %f\n", estoque[i].codigo, estoque[i].nome, estoque[i].preco);
            }
            
        } else {
            printf("bnao ha nenhum produto cadastrado no sistema!");
        }
    }

    void comprarProduto(){

        int codigo, quantidade;

        printf("Digite o codigo do produto");
        scanf("%d", &codigo);

        int encontrado = 0;

        for (int i = 0; i < totalProdutos; i++){
            if(estoque[i].codigo == codigo){
                encontrado = i;
                break;
            }
        }
        
        if (encontrado != 1){
            printf("Digite a quantidade: ");
            scanf("%d", &quantidade);

            if(totalItensCarrinhos < max_carrinho){
                carrinho[totalItensCarrinhos].produto = estoque[encontrado];
                carrinho[totalItensCarrinhos].quantidade = quantidade;
                totalItensCarrinhos++;
                printf("Produto adicionado ao carrinho!\n");

            }  else {
                printf("Carrinho cheio! Nao e possivel adicionar itens");
            }

        }   else {
            printf("produto nao encontrado");
        }

    }

    void visualizarCompra (){

        if(totalItensCarrinhos > 0){
            for(int i = 0; i < totalItensCarrinhos; i++){
                
                printf("Quantidade: %d || Produto: %s || preco unitario: %2.f || subtotal: %2.f\n", carrinho[i].quantidade, carrinho[i].produto.nome, carrinho[i].produto.preco, carrinho[i].produto.preco * carrinho[i].quantidade);
            }
        }   else {
            printf("O carrinho esta vazio");
        }
    }

    void fecharPedido(){
        if(totalItensCarrinhos > 0){

            float totalCompra = 0;
            printf("Fatura: \n");

            for (int i = 0; i < totalItensCarrinhos; i++){
                float subtotal = (float)carrinho[i].quantidade * (float)carrinho[i].produto.preco;

                printf("Nome: %s || Preco: %2.f || Quantidade: %d || Total: %2.f\n", carrinho[i].produto.nome, carrinho[i].produto.preco, carrinho[i].quantidade, subtotal);
                totalCompra += subtotal;
            }
            printf("Valor Total da compra: %2.f\n", totalCompra);


            totalItensCarrinhos = 0;
            printf("Pedido Finalizado com sucesso");
        }   else {
            printf("O carrinho esta vazio. Nao ha pedido a ser finalizado. \n");
        }

    }


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
                printf("Produto nao encontrado no carrinho");
        }

    }

    void infoProduto(int codigo){
        int encontrado = 0;
        for(int i = 0; i < totalProdutos; i++){
            if(codigo == estoque[i].codigo){
                printf("Produto encontrado");
                printf("Nome: %s || Codigo: %d || Preco: %2.f", estoque[i].nome, estoque[i].codigo, estoque[i].preco);
                encontrado = 1;
                break;
            }
            if(!encontrado){
                printf("Produto nao cadastrado!");
            }
        }

    }


    void exibirMenu() {
    printf("\n--- Menu ---\n");
    printf("1. Cadastrar Produto\n");
    printf("2. Listar Produtos\n");
    printf("3. Adicionar Produto ao Carrinho\n");
    printf("4. Visualizar Carrinho\n");
    printf("5. Verificar Produto no Carrinho\n");
    printf("6. Fechar Pedido\n");
    printf("7. Sair\n");
    printf("Escolha uma opcao: ");

}



    





int main (){
    int opcao, codigoProduto;

    do{
        exibirMenu();
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                system("cls");
                cadastrarProduto();
                system("cls");
                break;
            case 2:
            system("cls");
                listarProdutos();
                system("cls");
                break;
            case 3:
            system("cls");
                comprarProduto();
                system("cls");
                break;
            case 4:
            system("cls");
                visualizarCompra();
                system("cls");
                break;
            case 5:
                printf("Insira o codigo do produto\n");
                scanf("%d", &codigoProduto);
                temNoCarrinho(codigoProduto);
                system("pause");
                break;
             case 6:
            system("cls");
                fecharPedido();
                system("cls");
                break;

            case 7:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while (opcao != 6);
    
    return 0;


}