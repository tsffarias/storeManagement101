#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void menu_editar(celulaCliente *listaCli, celulaProduto *listaProd);
void editaCliente(celulaCliente *lista);
void editarProduto(celulaProduto *lista);

void menu_editar(celulaCliente *listaCli, celulaProduto *listaProd){
	limpa_tela;
	int op, aux = 1;

	printf("\n----------------------\n");
	printf("_____Opcao Editar____\n");
	printf("1 - Cliente\n");
	printf("2 - Produto\n");
	printf("3 - Voltar\n");
	printf("_____________________\n\n");
	printf("Digite a sua opcao = ");
	scanf("%d", &op);

	switch(op){
		case 1:
			//Editar_cliente
			limpa_tela;
			while(aux == 1){
				if(listaCli->proximo == NULL){
					printf("\n----------- Editar Cliente ----------\n");
					puts("Nao ha clientes a serem editados. Lista vazia.");
					
					printf("\nDeseja voltar para o menu? (S=1) = ");
					scanf("%d", &aux);
					if(aux == 1)
						break;
				} else{
					editaCliente(listaCli);
					printf("\nDeseja editar mais um Cliente? (S=1, N=0) = ");
					scanf("%d", &aux);
					if(aux == 0)
						break;
				}
			}
			break;
		case 2:
			//Editar_produto
			limpa_tela;
			while(aux == 1){
				if(listaProd->proximo == NULL){
					printf("\n------------ Editar Produto ----------\n");
					puts("Nao ha produtos a serem editados. Lista vazia.");
					
					printf("\nDeseja voltar para o menu? (S=1) = ");
					scanf("%d", &aux);
					if(aux == 1)
						break;
				} else{
					editarProduto(listaProd);
					printf("\nDeseja editar mais um Produto? (S=1, N=0) = ");
					scanf("%d", &aux);
					if(aux == 0)
						break;
				}				
			}
			break;
		case 3:
			//voltar
			break;	
		default:
			printf("codigo invalido.\n");
	}
}

void editaCliente(celulaCliente *lista){

	celulaCliente *p;

	char cpf[11];

	limpa_tela;
	puts("\n----------- Editar Cliente ----------\n");
	printf("Informe o CPF do cliente a ser editado: ");
	scanf("%s", cpf);

	p = lista->proximo;
	while (p != NULL && atol(p->cpf) != atol(cpf))
        p = p->proximo;

	if(p != NULL){
		printf("Nome Atual: %s\n", p->nomeCompleto);

		printf("-> Digite um novo nome: ");
		scanf("%s", p->nomeCompleto);
		
		puts("\n-- Cliente editado com Sucesso --\n");
	} else{
		puts("Nao existe cliente com este CPF.");
	}
}


void editarProduto(celulaProduto *lista){
	celulaProduto *p;

	char codigo[5];

	limpa_tela;
	puts("\n------------ Editar Produto ----------\n");
	printf("Informe o codigo do produto a ser editado: ");
	scanf("%s", codigo);

	p = lista->proximo;
	while (p != NULL && atol(p->codigo) != atol(codigo))
        p = p->proximo;

	if(p != NULL){
		printf("Nome Produto Atual.: %s\n", p->nomeProduto);
		printf("-> Digite novo nome do produto: ");
		scanf("%s", p->nomeProduto);
		printf("Quantidade Atual: %d\n", p->qtdEstoque);
		printf("-> Digite nova quantidade: ");
		scanf("%d", &p->qtdEstoque);
		printf("Preco  Atual...: R$%.2lf\n", p->valor);
		printf("-> Digite novo preço: R$");
		scanf("%lf", &p->valor);
		//fileWriterProduto(p);
		puts("\n-- Produto editado com Sucesso --\n");
	} else{
		puts("Nao existe produto com este codigo.");
	}
}
