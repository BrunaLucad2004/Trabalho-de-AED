#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Dados dos produtos
char produtos[100][50];
int quantidades[100];
float precos[100];
float vendas_totais[100];

// Dados das vendas
int vendas_id_produto[100];
int vendas_quantidade[100];
float vendas_valor_individual[100]; 
int contador = 0;
int contador_vendas = 0;

// Prototipo das funções
void Cadastrar_Produto(char *nome, int quantidade, float preco);
void Adicionar_Produto();
void Listar_Produtos();
void Consultar_Item();
void Ver_Matriz_Estoque();
void Vender_Produto(int id, int pecas);
void Calcular_Total_Vendas();
void Ver_Matriz_Vendas();

// Main
int main(void) {
    // Exemplo de produtos
    Cadastrar_Produto("Camisa", 10, 35.0);
    Cadastrar_Produto("Calca", 5, 20.0);

    // Menu
    int opcao;
    do {
        printf("\nMenu:\n");
        printf("1 - Listar produtos\n");
        printf("2 - Vender produto\n");
        printf("3 - Adicionar produto\n");
        printf("4 - Consultar estoque\n");
        printf("5 - Consultar item\n");
        printf("6 - Calcular total de vendas\n");
        printf("0 - Sair\n");
        printf("\nDigite a opcao desejada: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                Listar_Produtos();
                break;
            case 2:
                printf("\nDigite o ID do produto a ser vendido: ");
                int index;
                scanf("%d", &index);
                printf("\nDigite a quantidade de produtos a ser vendido: ");
                int quantidade;
                scanf("%d", &quantidade);
                Vender_Produto(index, quantidade);
                break;
            case 3:
                Adicionar_Produto();
                break;
            case 4:
                Ver_Matriz_Estoque();
                break;
            case 5:
            	Consultar_Item();
            	break;
            case 6:
                Calcular_Total_Vendas();
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida\n");
                break;
        }
    } while (opcao != 0);

    return 0;
}

// Funções

void Cadastrar_Produto(char *nome, int quantidade, float preco) {
    strcpy(produtos[contador], nome);
    quantidades[contador] = quantidade;
    precos[contador] = preco;
    vendas_totais[contador] = 0;
    contador++;
}

void Adicionar_Produto() {
    int quantidade;
    float preco;
    char nome[50];
    printf("Digite o Nome do produto: ");
    scanf("%s", nome);
    printf("Digite a Quantidade de produtos: ");
    scanf("%d", &quantidade);
    printf("Digite o Preco do produto: ");
    scanf("%f", &preco);

    Cadastrar_Produto(nome, quantidade, preco);
}

void Listar_Produtos() {
    int i;
    for (i = 0; i < contador; i++) {
        printf("%d - %s\n", i, produtos[i]);
    }
}

void Consultar_Item() {
    int id;
    printf("Digite o ID do produto: ");
    scanf("%d", &id);

    if (id >= 0 && id < contador) {
        printf("Nome: %s\n", produtos[id]);
        printf("Quantidade: %d\n", quantidades[id]);
        printf("Preco: %.2f\n", precos[id]);
        printf("Vendas totais: %.2f\n", vendas_totais[id]);
    } else {
        printf("Produto nao encontrado.\n");
    }
}

void Ver_Matriz_Estoque() {
    int i;

    printf("ID\tQuantidade\tPreco\n");

    for (i = 0; i < contador; i++) {
        printf("%d\t%d\t\t%.2f\n", i, quantidades[i], precos[i]);
    }
}

void Vender_Produto(int id, int pecas) {
    if (quantidades[id] >= pecas) {
        quantidades[id] -= pecas;
        float valor_venda = precos[id] * pecas;

        vendas_totais[id] += valor_venda;
        vendas_id_produto[contador_vendas] = id;
        vendas_quantidade[contador_vendas] = pecas;
        vendas_valor_individual[contador_vendas] = valor_venda;

        contador_vendas++;
    } else {
        printf("Estoque insuficiente.\n");
    }
}

void Ver_Matriz_Vendas() {
    printf("ID\tQuantidade Vendida\tValor da Venda\n");
	int i;
    for ( i = 0; i < contador_vendas; i++) {
        printf("%d\t%d\t\t\t%.2f\n", vendas_id_produto[i], vendas_quantidade[i], vendas_valor_individual[i]);
    }
}

void Calcular_Total_Vendas() {
    float total = 0;
    int i;
    for (i = 0; i < contador; i++) {
        total += vendas_totais[i];
    }
    printf("Total de vendas: R$ %.2f\n", total);

    printf("\nMatriz de Vendas:\n");
    Ver_Matriz_Vendas();
}
