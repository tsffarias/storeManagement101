#include <stdio.h>
#include <stdlib.h>

/* ----------------------

Aluno: Thiago Silva Farias
SI - UFMS
Algoritmos 2

------------------------ */

#ifdef WIN32  //se for windows
	#define limpa_tela system("cls") //limpa tela
	#define espera Sleep(500) //tempo de delay
#else //senão, ex.: linux
	#define limpa_tela system("/usr/bin/clear") //limpa tela
	#define espera Sleep(1) //tempo de delay
#endif

void menu_vendas(celulaCliente *listaCli, celulaProduto *listaProd);
void venda(celulaCliente *listaCli, celulaProduto *listaProd);

void menu_vendas(celulaCliente *listaCli, celulaProduto *listaProd){
	limpa_tela;
	int op, aux = 1;
	printf("\n----------------------\n");
	printf("_____Opcao Vendas____\n");
	printf("1 - Vender\n");
	printf("2 - Voltar\n");
	printf("_____________________\n\n");
	printf("Digite a sua opcao = ");
	scanf("%d", &op);

	switch(op){
		case 1:
			limpa_tela;
			while(aux == 1){
				if(listaCli->proximo != NULL || listaProd->proximo != NULL){
					venda(listaCli, listaProd);
					
					printf("\nDeseja vender mais um produto? (S=1, N=0) = ");
					scanf("%d", &aux);
					if(aux == 0)
						break;
				} else{
					puts("Lista cliente ou lista produto esta vazia.");
					printf("\nDeseja voltar para o menu? (S=1) = ");
					scanf("%d", &aux);
					if(aux == 1)
						break;
				}
			}			
			break;
		case 2:
		
			break;
		default:
			printf("codigo invalido.\n");		
	}

	
}

void venda(celulaCliente *listaCli, celulaProduto *listaProd){
	char codigo[5];	
	celulaProduto *buscaProd;
	limpa_tela;

	puts("\n----------- Vender Produto ----------\n");
	printf("Digite o codigo do produto: ");
	scanf("%s", codigo);
	
	buscaProd = listaProd->proximo;
	while (buscaProd != NULL && atol(buscaProd->codigo) != atol(codigo))
  		buscaProd = buscaProd->proximo;
	
	if(buscaProd != NULL){

		char cpf[12];
		celulaCliente *buscaCpf;
		printf("Digite o seu CPF: ");
		scanf("%s", cpf);
		
		buscaCpf = listaCli->proximo;
		while (buscaCpf != NULL && atol(buscaCpf->cpf) != atol(cpf))
       		buscaCpf = buscaCpf->proximo;
		
		if(buscaCpf != NULL){
			int qtd, conf;
			printf("Informe a quantidade que deseja comprar: ");
			scanf("%d", &qtd);
			if(buscaProd->qtdEstoque >= qtd){
				double total = (buscaProd->valor * qtd);
				limpa_tela;
				puts("\n------------ Venda -------------\n");
				printf("Produto: %s\n", buscaProd->nomeProduto);
				printf("Quantidade vendida: %d\n", qtd);
				printf("Total da compra: R$%.2lf\n", total);
				puts("\n--------------------------------\n");
				printf("Confirmar venda: (S=1, N=0): ");
				scanf("%d", &conf);
				if(conf == 1){
					buscaProd->qtdEstoque = buscaProd->qtdEstoque - qtd;
					puts("\n-- Venda Realizada com Sucesso --");
				}
			} else{
				puts("Infelizmente nao temos esta quantidade em estoque.");
			}
		} else{
			puts("CPF nao existe na base de dados.");
		}

	} else{
		puts("Produto nao existe na base de dados.");
	}
}