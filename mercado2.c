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

// variavel global
 Produto estoque [max_produtos];
 ItemCarrinho carrinho [max_carrinho];
 int totalProdutos = 0;
 int totalItensCarrinhos = 0;
 FILE *csv;


//  funcao de cadastro de produto
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
            printf("produto cadastrado com sucesso!\n");
             system("pause");
             system("cls");
        } else {
            printf("Estoque cheio, nao foi possivel cadastrar o produto!\n");
            system("pause");
            system("cls");
        }
    }


// funcao para listar todos os produtos cadastrados
    void listarProdutos (){
        if(totalProdutos > 0){
            printf("Produtos disponiveis:\n");
            printf("----------------------------------\n");

            for (int i = 0; i < totalProdutos; i++){
                printf("Codigo: %d || Nome: %s || preco: %2.2f\n", estoque[i].codigo, estoque[i].nome, estoque[i].preco);
            }
            printf("----------------------------------\n");

        } else {
            printf("nao ha nenhum produto cadastrado no sistema!\n");
            system("pause");
            system("cls");
        }
    }

// funcao para adicionar ao carrinho
    void comprarProduto(){
        listarProdutos();
        int codigo, quantidade;

        printf("Digite o codigo do produto: ");
        scanf("%d", &codigo);

        int encontrado = -1;

        for (int i = 0; i < totalProdutos; i++){
            if(estoque[i].codigo == codigo){
                encontrado = i;
                break;
            }
        }
        
        if (encontrado >= 0){
            printf("Digite a quantidade: ");
            scanf("%d", &quantidade);

            if(totalItensCarrinhos < max_carrinho){
                carrinho[totalItensCarrinhos].produto = estoque[encontrado];
                carrinho[totalItensCarrinhos].quantidade = quantidade;
                totalItensCarrinhos++;
                printf("Produto adicionado ao carrinho!\n");
                system("pause");
            system("cls");

            }  else {
                printf("Carrinho cheio! Nao e possivel adicionar itens\n");
                system("pause");
            system("cls");
            }

        }   else {
            printf("produto nao encontrado\n");
            system("pause");
            system("cls");
        }

    }

    // funcao para ver os itens do carrinho
    void visualizarCompra (){

        if(totalItensCarrinhos > 0){
            for(int i = 0; i < totalItensCarrinhos; i++){
                
                printf("Quantidade: %d || Produto: %s || preco unitario: %2.f || subtotal: %2.f\n", carrinho[i].quantidade, carrinho[i].produto.nome, carrinho[i].produto.preco, carrinho[i].produto.preco * carrinho[i].quantidade);
            }
            system("pause");
            system("cls");
        }   else {
            printf("O carrinho esta vazio\n");
            system("pause");
            system("cls");
        }
    }

    // funcao que soma o total do valor do carrinho e ao final retiroa os itens do carrinho
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
            printf("Pedido Finalizado com sucesso\n");
            system("pause");
            system("cls");
        }   else {
            printf("O carrinho esta vazio. Nao ha pedido a ser finalizado. \n");
            system("pause");
            system("cls");
        }

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
            if(codigo = carrinho[i].produto.codigo){
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


    void exibirMenu() {
    printf("\n--- Menu ---\n");
    printf("1. Cadastrar Produto\n");
    printf("2. Listar Produtos\n");
    printf("3. Informacao do produto\n");
    printf("4. Remover Item do carrinho\n");
    printf("5. Adicionar Produto ao Carrinho\n");
    printf("6. Visualizar Carrinho\n");
    printf("7. Verificar Produto no Carrinho\n");
    printf("8. Fechar Pedido\n");
    printf("9. Sair\n");
    printf("Escolha uma opcao: ");

}

    void menu_excel(){
        int opcao;
        printf("\n--- Menu ---\n");
        printf("1. Importar Carrinho\n");
        printf("2. Importar Produto\n");
        scanf("%d", &opcao);

        switch (opcao){
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


void importarExcelCarrinho (){

    float totalCompra = 0;
    csv = fopen("Carrinho.csv", "wb");
    if(csv == NULL){
        printf("Erro ao abrir o arquivo!\n");
    }

    fprintf(csv, "Codigo;Nome;Preco;Quantidade;Subtotal;Total\n");
    
    for(int i = 0; i < totalItensCarrinhos; i++){
        float subtotal = carrinho[i].produto.preco * carrinho[i].quantidade;
        totalCompra += subtotal;
        fprintf(csv, "%d;%s;%2.f;%d;%2.2f;%2.f;\n", carrinho[i].produto.codigo, carrinho[i].produto.nome, carrinho[i].produto.preco, carrinho[i].quantidade, subtotal, totalCompra);
        
    }
    

    fclose(csv);
    printf("Dados Convertidos com sucesso para o excel!");
    system("Carrinho.csv");

}


void importarExcelProdutos (){

    csv = fopen("Produtos.csv", "wb");
    if(csv == NULL){
        printf("Erro ao abrir o arquivo!\n");
    }

    fprintf(csv, "Codigo;Nome;Preco;\n");
    
    for(int i = 0; i < totalItensCarrinhos; i++){
        fprintf(csv, "%d;%s;%2.2f;\n", estoque[i].codigo, estoque[i].nome, estoque[i].preco);
    }

    fclose(csv);
    printf("Dados Convertidos com sucesso para o excel!");
    system("Produtos.csv");

}






int main (){
    int opcao;

    do{
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
                TirarItensDoCarrinho();
                
                break;
            case 5:
            
                comprarProduto();
                
                break;
            case 6:
            
                visualizarCompra();
                
                break;
            case 7:
                procurarProdutoNoCarrinho();
                
                break;
             case 8:
            
                fecharPedido();
                
                break;

            case 9:

                printf("Saindo...\n");

                break;

            case 10:

                menu_excel();

                break;

            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while (opcao != 9);
    
    return 0;


}