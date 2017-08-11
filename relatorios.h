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

void menu_relatorio(celulaCliente *listaCli, celulaProduto *listaProd);

void menu_relatorio(celulaCliente *listaCli, celulaProduto *listaProd){
	limpa_tela;
	int op, aux = 0;

	printf("\n----------------------\n");
	printf("_____Opcao Relatorios____\n");
	printf("1 - Cliente\n");
	printf("2 - Produto\n");
	printf("3 - Voltar\n");
	printf("_____________________\n\n");
	printf("Digite a sua opcao = ");
	scanf("%d", &op);

	switch(op){
		case 1:
			//Relatorio_cliente
			limpa_tela;
			while(aux == 0){
				
				if(listaCli->proximo == NULL){
					printf("\n-------- Relatorio Clientes --------\n");
					puts("Nao ha clientes cadastrados. Lista vazia.");
				} else{
					printf("\n-------- Relatorio Clientes --------\n");
					imprime_lista_cliente(listaCli);
				}			

				printf("\nDeseja voltar para o menu? (S=1) = ");
				scanf("%d", &aux);
				if(aux == 1)
					break;
			}			
			break;
		case 2:
			//Relatorio_produto
			limpa_tela;
			while(aux == 0){
				
				if(listaProd->proximo == NULL){
					printf("\n-------- Relatorio Produtos --------\n");
					puts("Nao ha produtos cadastrados. Lista vazia.");
				} else{
					printf("\n-------- Relatorio Produtos --------\n");
					imprime_lista_produto(listaProd);
				}

				printf("\nDeseja voltar para o menu? (S=1) = ");
				scanf("%d", &aux);
				if(aux == 1)
					break;
			}	
			break;
		case 3:
			
			break;	
		default:
			printf("codigo invalido.\n");
	}
}

