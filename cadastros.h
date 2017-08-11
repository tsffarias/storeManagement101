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

void menu_cadastrar(celulaCliente *listaCli, celulaProduto *listaProd);
int valida_Cliente(celulaCliente *lista, celulaCliente *nova);
void dadosCliente(celulaCliente *lista);
void cadastro_Cliente(celulaCliente *lista, char *cpf, char *nomeCompleto);
void dadosProduto(celulaProduto *lista);
int valida_Produto(celulaProduto *lista, celulaProduto *nova);
void cadastro_Produto(celulaProduto *lista, char *codigo, char *nomeProduto, int *qtdEstoque, double *valor);
void imprime_lista_produto(celulaProduto *lista);
void imprime_lista_cliente(celulaCliente *lista);

void menu_cadastrar(celulaCliente *listaCli, celulaProduto *listaProd){
	limpa_tela;
	int op, aux = 1;;

	printf("\n----------------------\n");
	printf("____Opcao Cadastrar____\n");
	printf("1 - Cliente\n");
	printf("2 - Produto\n");
	printf("3 - Voltar\n");
	printf("_____________________\n\n");
	printf("Digite a sua opcao = ");
	scanf("%d", &op);

	switch(op){
		case 1:
			//Cadastrar_cliente
			while(aux == 1){
				dadosCliente(listaCli);
				printf("\nDeseja cadastrar mais um cliente? (S=1, N=0) = ");
				scanf("%d", &aux);
				if(aux == 0)
					return;
			}
			break;
		case 2:
			//Cadastrar_produto
			while(aux == 1){
				dadosProduto(listaProd);
				printf("\nDeseja cadastrar mais um produto? (S=1, N=0) = ");
				scanf("%d", &aux);
				if(aux == 0)
					break;
			}
			break;
		case 3:
			//voltar
			break;	
		default:
			printf("codigo invalido.\n");
	}
}

int valida_Cliente(celulaCliente *lista, celulaCliente *nova){
	celulaCliente *pt;
	pt = lista;

	while(pt != NULL){
		if(strcmp(pt->cpf, nova->cpf) == 0){ 
			puts("CPF já existe. Operacao foi cancelada.");
			return -1;
		}
		pt = pt->proximo;
	}

    return 1;
}

void dadosCliente(celulaCliente *lista){
	limpa_tela;
	char cpf[12];
	char nomeCompleto[30];

	puts("\n----- Cadastro Cliente -----\n");
 	printf("Digite o CPF: ");
 	scanf("%s", cpf);
	printf("Digite nome completo: ");
	scanf("%s", nomeCompleto);

	cadastro_Cliente(lista, cpf, nomeCompleto);
}

void cadastro_Cliente(celulaCliente *lista, char *cpf, char *nomeCompleto){
	celulaCliente *nova;
	nova = (celulaCliente*) malloc(sizeof(celulaCliente));

	if(nova != NULL){
		limpa_tela;
		strcpy(nova->cpf, cpf);
	    strcpy(nova->nomeCompleto, nomeCompleto);
		nova->proximo = NULL;

		if(lista->proximo == NULL){
			lista->proximo = nova;
			nova->anterior = lista;
		} else{
			int valida = valida_Cliente(lista, nova);
			if(valida == -1){
				return;
			} else{

				celulaCliente *pt;
				pt = lista->proximo;

				//procurando melhor posicao para inserir o cliente
				while((pt->proximo != NULL) && (atol(pt->cpf) < (atol(nova->cpf)))){
					pt = pt->proximo;
				}

				if(pt->proximo == NULL){
					if(atol(pt->cpf) < (atol(nova->cpf))){
						pt->proximo = nova;
						nova->anterior = pt;
					} else{
						pt->anterior->proximo = nova;
	                    nova->anterior = pt->anterior;
	                    nova->proximo = pt;
	                    pt->anterior = nova;
					}
				} else{
					nova->anterior = pt->anterior;
	                pt->anterior = nova;
	                nova->proximo = pt;
	                nova->anterior->proximo = nova;
				}
			}
		}
		puts("\n* Cliente cadastrado com sucesso *");
	} else{
		printf("Impossivel alocar espaco para o cliente.\n");
	}


}


int valida_Produto(celulaProduto *lista, celulaProduto *nova){
	celulaProduto *pt;
	pt = lista;

	while(pt != NULL){
		if(strcmp(pt->codigo, nova->codigo) == 0){
			puts("Codigo já existe. Operacao foi cancelada.");
			return -1;
		}
		pt = pt->proximo;
	}

    return 1;
}

void dadosProduto(celulaProduto *lista){
	limpa_tela;
	char codigo[5];
	char nomeProduto[30];
	int qtdEstoque;
	double valor;

	puts("\n----- Cadastro Produto -----\n");
 	printf("Digite o Codigo: ");
 	scanf("%s", codigo);
	printf("Digite nome do produto: ");
	scanf("%s", nomeProduto);
	printf("Digite a quantidade: ");
	scanf("%d", &qtdEstoque);
	printf("Digite preco: ");
	scanf("%lf", &valor);

	cadastro_Produto(lista, codigo, nomeProduto, &qtdEstoque, &valor);
}

void cadastro_Produto(celulaProduto *lista, char *codigo, char *nomeProduto, int *qtdEstoque, double *valor){
	celulaProduto *nova;
	nova = (celulaProduto*) malloc(sizeof(celulaProduto));

	if(nova != NULL){

		limpa_tela;
		strcpy(nova->codigo, codigo);
	    strcpy(nova->nomeProduto, nomeProduto);
	    nova->qtdEstoque  = *qtdEstoque;
	    nova->valor = *valor;
		nova->proximo = NULL;

		if(lista->proximo == NULL){
			lista->proximo = nova;
			nova->anterior = lista;
		} else{
			int valida = valida_Produto(lista, nova);
			if(valida == -1){
				return;
			} else{

				celulaProduto *pt;
				pt = lista->proximo;

				//procurando melhor posicao para inserir o produto
				while((pt->proximo != NULL) && (atol(pt->codigo) < (atol(nova->codigo)))){
					pt = pt->proximo;
				}

				if(pt->proximo == NULL){
					if(atol(pt->codigo) < (atol(nova->codigo))){
						pt->proximo = nova;
						nova->anterior = pt;
					} else{
						pt->anterior->proximo = nova;
	                    nova->anterior = pt->anterior;
	                    nova->proximo = pt;
	                    pt->anterior = nova;
					}
				} else{
					nova->anterior = pt->anterior;
	                pt->anterior = nova;
	                nova->proximo = pt;
	                nova->anterior->proximo = nova;
				}
			}
		}
		puts("\n* Produto cadastrado com sucesso *");
	} else{
		printf("Impossivel alocar espaco para o produto.\n");
	}
}

