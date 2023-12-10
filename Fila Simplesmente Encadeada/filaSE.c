#include <stdio.h>
#include <stdlib.h>
#include "filaSE.h"

void criaFila(FilaSE *f){
	f->frente =  NULL;
	f->re = NULL;
}

int insere(FilaSE *f, Dado d){
	Nodo *pNodo;
	pNodo = (Nodo *) malloc(sizeof (Nodo));
	if(pNodo == NULL)
		return (FALTOU_MEMORIA);
	else{
		pNodo->info = d;
		pNodo->prox = NULL;
		
		if(f->frente == NULL){
			f->frente = pNodo;
			f->re = pNodo;
		}
		else{
			Nodo *ultimo = f->re;
			while(ultimo->prox != NULL){
				ultimo = ultimo->prox;
			}
			
		ultimo->prox = pNodo;
		f->re = pNodo;
		}
		
	}
	return (SUCESSO);
}

int retira(FilaSE *f, Dado *d){
	if(f->frente == NULL && f->re == NULL){
		return (FILA_VAZIA);
	}
	else{
		Nodo *nodoRemovido = f->frente;
		*d = nodoRemovido->info;
		f->frente = nodoRemovido->prox;
		printf("Nodo Removido: %d\n", *d);
		free(nodoRemovido);
		if(f->frente == NULL){
			f->frente = NULL;
			f->re = NULL;
		}
		return (SUCESSO);
	}
}

int estaVazia(FilaSE f){
	if(f.frente == NULL && f.re == NULL){
		printf("Fila Vazia!\n");
		return 1;
	}
	else{
		printf("A fila possui 1 ou mais nodos!\n");
		return 0;
	}
}

int consulta(FilaSE f, Dado *d){
	if(f.frente == NULL && f.re == NULL){
		return (FILA_VAZIA);
}
	else{
		*d = f.frente->info;
		printf("Dados no inicio da fila: %d %f\n", d->cod, d->peso);
		return (SUCESSO);
	}
}

int exibe(FilaSE f){
	if(f.frente == NULL && f.re == NULL){
		printf("A fila esta vazia!\n");
		return (FILA_VAZIA);
	}
	Nodo *atual = f.frente;
	do{
		printf("Fila SE: %d %f\n ", atual->info.cod, atual->info.peso);
		atual= atual->prox;
	}while(atual!=NULL);
	
	return (SUCESSO);
}

int quantidadeNodos(FilaSE *f){
	int contador = 0;
	if(f->frente == NULL && f->re == NULL){
		printf("Quantidade de Nodos: %d\n", contador);
		return (FILA_VAZIA);
	}

	else{
		Nodo *atual = f->frente; 
		do{
			contador++;	
			atual = atual->prox;
		}while(atual != NULL);
		
		printf("Quantidade de Nodos: %d\n", contador);
		return contador;
	}
}


