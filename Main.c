#include <stdio.h>
#include <stdlib.h>
#include "structs.h"
#include "cadastros.h"
#include "busca_imprime.h"
#include "editar.h"
#include "remover.h"
#include "relatorios.h"
#include "reader_writer.h"
#include "vendas.h"


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

void menu_opcoes();
void opcao(celulaCliente *cli, celulaProduto *prod, int op);

int main(int argc, char const *argv[])
{

	celulaCliente *listaCli;
	listaCli = (celulaCliente*)malloc(sizeof(celulaCliente));
	listaCli->anterior = NULL;
	listaCli->proximo = NULL;

	celulaProduto *listaProd;
	listaProd = (celulaProduto*)malloc(sizeof(celulaProduto));
	listaProd->anterior = NULL;
	listaProd->proximo = NULL;

	fileReaderCliente(listaCli);
    fileReaderProduto(listaProd);

	int op = -1;
	while(op != 6){
		menu_opcoes();
		scanf("%d", &op);

		opcao(listaCli, listaProd, op);
	}

	return 0;
}

void menu_opcoes(){
	limpa_tela;
	printf("\n_________MENU_________\n");
	printf("1 - Cadastrar\n");
	printf("2 - Editar\n");
	printf("3 - Remover\n");
	printf("4 - Relatorio\n");
	printf("5 - Vendas\n");
	printf("6 - Sair\n");
	printf("_____________________\n\n");
	printf("Digite a sua opcao = ");
}

void opcao(celulaCliente *cli, celulaProduto *prod, int op){
	switch(op){
		case 1:
			//cadastrar
			menu_cadastrar(cli, prod);
			break;
		case 2:
			//editar
			menu_editar(cli, prod);
			break;
		case 3:
			//remover
			menu_remover(cli, prod);
			break;
		case 4:
			//relatorio
			menu_relatorio(cli, prod);
			break;
		case 5:
			//vendas
			menu_vendas(cli, prod);
			break;	
		case 6:
			printf("Finalizando programa...\n");
			fileWriterCliente(cli->proximo);
			fileWriterProduto(prod->proximo);
			exit(0);
			break;
		default:
			printf("codigo invalido.\n");
	}
}

