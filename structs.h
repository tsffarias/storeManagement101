#include <stdio.h>

/* ----------------------

Aluno: Thiago Silva Farias
SI - UFMS
Algoritmos 2

------------------------ */ 

typedef struct cliente celulaCliente;
struct cliente{
	char cpf[12];
	char nomeCompleto[30];
	struct cliente *anterior;
	struct cliente *proximo;
};

typedef struct produto celulaProduto;
struct produto{
	char codigo[5];
	char nomeProduto[30];
	int qtdEstoque;
	double valor;
	struct produto *anterior;
	struct produto *proximo;
}; 