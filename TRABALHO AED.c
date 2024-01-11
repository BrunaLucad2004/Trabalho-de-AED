#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Dados dos produtos
char *produtos[100];
int quantidades[100];
int estoque[100][3];
float vendas_totais[100];

// Contador de produtos
int contador = 0;

//Função para adicionar produto
void adicionar_produto(){
	int quantidade, categoria = 0, preco;
	char *nome[25];
	printf("Digite o Nome do produto: ");
	scanf("%s", nome);
	printf("Digite a Quantidade de produtos: ");
	scanf("%d", &quantidade);
	printf("Digite o Preco do produto: ");
	scanf("%d", &preco);
            	
    cadastrar_produto(*nome, quantidade, preco, categoria);
}


// Função para cadastrar produto
void cadastrar_produto(char *nome, int quantidade, int preco, int categoria) {
    produtos[contador] = nome;
    quantidades[contador] = quantidade;
    estoque[contador][0] = preco;
    estoque[contador][1] = categoria;
    estoque[contador][2] = 0;
    vendas_totais[contador] = 0;
    contador++;
}

// Função para listar produtos
void listar_produtos() {
	int i;
    for ( i = 0; i < contador; i++) {
        printf("%d - %s\n", i, produtos[i]);
    }
}

// Função para consultar estoque
void consultar_estoque(){
    
	int id;
    printf("Digite o ID do produto: ");
    scanf("%d", &id);

    if (id >= 0 && id < contador) {
        printf("Nome: %s\n", produtos[id]);
        printf("Quantidade: %d\n", quantidades[id]);
        printf("Preco: %d\n", estoque[id][1]);
        printf("Vendas totais: %.2f\n", vendas_totais[id]);
    } else {
        printf("Produto nao encontrado.\n");
    }
}

//ver a matriz de estoque

void ver_Matriz(){
	int i, j;
	for(i=0; i<=contador; i++){
		for(j=0; j< 3; j++){
			printf(estoque[i][j]);
			printf(" ");
		}
		printf(" ");
	}
}

// Função para vender produto
void vender_produto(int id, int pecas){
    if (quantidades[id] > 0) {
        quantidades[id] = quantidades[id] - pecas;
        estoque[id][2]= estoque [id][2] + pecas;
        vendas_totais[id] = vendas_totais[id] + (estoque[id][0] * pecas);
    } else {
        printf("Estoque insuficiente.\n");
    }
}

// Função para calcular o total de vendas
void calcular_total_vendas() {
    float total = 0;
    int i;
    for ( i = 0; i < contador; i++) {
        total += vendas_totais[i];
    }
    printf("Total de vendas: R %.2f\n", total);
}

int main(void){
	
	// Exemplo de produtos
    cadastrar_produto("Camisa", 10, 35, 0);
    cadastrar_produto("Calca", 5, 20, 0);
	
    // Menu
    int opcao;
    do {
        printf("\nMenu:\n");
        printf("1 - Listar produtos\n");
        printf("2 - Vender produto\n");
        printf("3 - Adicionar produto\n");
        printf("4 - Consultar estoque\n");
        printf("5 - Calcular total de vendas\n");
        printf("0 - Sair\n");
        printf("\nDigite a opcao desejada: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                listar_produtos();
                break;
            case 2:
                printf("\nDigite o ID do produto a ser vendido: ");
                int index;
                scanf("%d", &index);
                printf("\nDigite a quantidade de produtos a ser vendido: ");
                int quantidade;
                scanf("%d", &quantidade);
                vender_produto(index, quantidade);
                break;
            case 3:
                adicionar_produto();
                break;
            case 4:
                ver_Matriz();
                break;
            case 5:
                calcular_total_vendas();
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
            	printf("Opcao invalida\n");
            	break;
        }
    }while(opcao != 0);

	return 0;
}
