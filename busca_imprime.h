#include <stdio.h>
#include <stdlib.h>
#include <string.h>

celulaCliente *busca_cliente(celulaCliente *lista, char *cpf);
celulaProduto *busca_Produto(celulaProduto *lista, char *codigo);
void imprime_lista_produto(celulaProduto *lista);
void imprime_lista_cliente(celulaCliente *lista);


celulaCliente *busca_cliente(celulaCliente *lista, char *cpf){
	celulaCliente *pt;

	pt = lista->proximo;
	while((pt->proximo != NULL) && (strcmp(pt->cpf, cpf) != 0)){
		pt = pt->proximo;
	}

	return pt;
}

celulaProduto *busca_Produto(celulaProduto *lista, char *codigo){
	celulaProduto *pt;

	pt = lista->proximo;
	while((pt->proximo != NULL) && (strcmp(pt->codigo, codigo) != 0)){
		pt = pt->proximo;
	}

	return pt;
}


void imprime_lista_produto(celulaProduto *lista){

    celulaProduto *pt;
    pt = lista->proximo;

    if(lista->proximo != NULL){
	    while(pt != NULL){
	        puts("\n======================");
	        printf("Codigo: %s\nDescricao: %s\nQuantidade em Estoque: %d\nPreco: R$%.2lf\n", pt->codigo, pt->nomeProduto, pt->qtdEstoque, pt->valor);
	        puts("======================");
	        pt = pt->proximo;
	    }
	} else{
		printf("Lista de produtos vazia.\n");
	}
}

void imprime_lista_cliente(celulaCliente *lista){

    celulaCliente *pt;
    pt = lista->proximo;

    if(lista->proximo != NULL){
    	while(pt != NULL){
	        puts("\n======================");
	        printf("CPF: %s\nNome Completo: %s\n", pt->cpf, pt->nomeCompleto);
	        puts("======================");
	        pt = pt->proximo;
    	}
    } else{
    	printf("Lista de clientes vazia.\n");
    }
}
