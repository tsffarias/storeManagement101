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

void menu_remover(celulaCliente *listaCli, celulaProduto *listaProd);
void remove_Cliente(celulaCliente *lista);
void remove_Produto(celulaProduto *lista);

void menu_remover(celulaCliente *listaCli, celulaProduto *listaProd){
	limpa_tela;
	int op, aux = 1;

	printf("\n----------------------\n");
	printf("_____Opcao Remover____\n");
	printf("1 - Cliente\n");
	printf("2 - Produto\n");
	printf("3 - Voltar\n");
	printf("_____________________\n\n");
	printf("Digite a sua opcao = ");
	scanf("%d", &op);

	switch(op){
		case 1:
			//Remover_cliente
			limpa_tela;
			while(aux == 1){
				if(listaCli->proximo == NULL){
					printf("\n------------ Remover Cliente ----------\n");
					puts("Nao ha clientes a serem removidos. Lista vazia.");

					printf("\nDeseja voltar para o menu? (S=1) = ");
					scanf("%d", &aux);
					if(aux == 1)
						break;
				} else{
					remove_Cliente(listaCli);
					printf("\nDeseja remover mais um Cliente? (S=1, N=0) = ");
					scanf("%d", &aux);
					if(aux == 0)
						break;
				}				
			}
			break;
		case 2:
			//Remover_produto
			limpa_tela;
			while(aux == 1){
				if(listaProd->proximo == NULL){
					printf("\n------------ Remover Produto ----------\n");
					puts("Nao ha produtos a serem removidos. Lista vazia.");
					
					printf("\nDeseja voltar para o menu? (S=1) = ");
					scanf("%d", &aux);
					if(aux == 1)
						break;
				} else{
					remove_Produto(listaProd);
					printf("\nDeseja remover mais um Produto? (S=1, N=0) = ");
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

void remove_Cliente(celulaCliente *lista){
	celulaCliente *p;
	p = lista->proximo;

	char cpf[12];

	limpa_tela;
	puts("\n------------ Remover Cliente ----------\n");
	printf("Informe o CPF do cliente a ser removido: ");
	scanf("%s", cpf);

    while (p != NULL && atol(p->cpf) != atol(cpf)) {
    	p = p->proximo;
    }
	if(p != NULL){
		p->anterior->proximo = p->proximo;
		if(p->proximo != NULL)
			p->proximo->anterior = p->anterior;
		free(p);
		puts("Cliente Removido com Sucesso");
	} else{
		puts("Nao existe cliente com este CPF.");
	}
}

void remove_Produto(celulaProduto *lista){

	celulaProduto *p;
	p = lista->proximo;

	char codigo[5];
	limpa_tela;
	puts("\n------------ Remover Produto -------------\n");
	printf("Informe o codigo do produto a ser removido: ");
	scanf("%s", codigo);

	while (p != NULL && atol(p->codigo) != atol(codigo)) {
		p = p->proximo;
    }
	if(p != NULL){
		p->anterior->proximo = p->proximo;
		if(p->proximo != NULL)
			p->proximo->anterior = p->anterior;
		free(p);
		puts("Produto Removido com Sucesso");
	} else{
		puts("Nao existe produto com este codigo.");
	}
}

