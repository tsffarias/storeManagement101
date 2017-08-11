#include <stdio.h>
#include <stdlib.h>

/* ----------------------

Aluno: Thiago Silva Farias
SI - UFMS
Algoritmos 2

------------------------ */


void fileWriterCliente(celulaCliente *lista){
	
	FILE *ptArq = fopen("listaCliente.txt", "w");
	if(ptArq != NULL){
		celulaCliente *pt;
		for(pt = lista; pt != NULL; pt = pt->proximo){
			fprintf(ptArq, "%s;%s\n", pt->cpf, pt->nomeCompleto);	
		}
		fclose(ptArq);
	} else{
		printf("erro ao abrir arquivo cliente...\n");
		exit(0);
	}
}


void fileReaderCliente(celulaCliente *cadCli){	
	char tmp[50];
    char cpf[12];
	char nome[30];

    FILE *arqCliente;
    char ch;
	int cmp = 0;

    arqCliente = fopen("listaCliente.txt", "r");

   	if(arqCliente != NULL){
		while( (ch = fgetc(arqCliente)) != EOF)
        {

            switch(ch){
            case ';':  tmp[cmp] = '\0'; strcpy(cpf, tmp);  cmp = 0; break;
            case '\n':
                tmp[cmp] = '\0';
                strcpy(nome, tmp);
                cadastro_Cliente(cadCli, cpf, nome);
                cmp = 0;
                break;
            default:
                tmp[cmp] = ch;
                cmp++;
                break;
            }

        }
        fclose(arqCliente);
    }
} 

void fileWriterProduto(celulaProduto *lista){
	
	FILE *ptArq = fopen("listaProduto.txt", "w");
	if(ptArq != NULL){
		celulaProduto *pt;
		for(pt = lista; pt != NULL; pt = pt->proximo){
			fprintf(ptArq, "%s;%s;%d;%lf\n", pt->codigo, pt->nomeProduto, pt->qtdEstoque, pt->valor);	
		}			
		fclose(ptArq);
	} else{
		printf("erro ao abrir arquivo produto...\n");
		exit(0);
	}
}

void fileReaderProduto(celulaProduto *cadprod){
	
	char tmp[100];
    char codigo[5];
	char nomeProduto[30];
	int qtdEstoque = 0;
	double valor = 0.00;

    FILE *arqProduto;
    char ch;
    int proxcmp = 0;
    int cmp = 0;

    arqProduto = fopen("listaProduto.txt", "r");

   	if(arqProduto != NULL){

        while( (ch = fgetc(arqProduto)) != EOF){
            switch(ch){
            case ';':
                switch(proxcmp){
                case 0: tmp[cmp] = '\0'; strcpy(codigo, tmp); cmp = 0;  break;
                case 1: tmp[cmp] = '\0'; strcpy(nomeProduto, tmp); cmp = 0;  break;
                case 2: qtdEstoque = atol(tmp); cmp = 0;  break;
                }
                proxcmp++;
                break;
            case '\n':
                valor = atof(tmp);
                cadastro_Produto(cadprod, codigo, nomeProduto, &qtdEstoque, &valor);               
                cmp = 0;
                proxcmp = 0;
                break;
            default:
                tmp[cmp] = ch;
                cmp++;
                break;
            }
        }
        fclose(arqProduto);
    }
}