#include <stdio.h>
#include <stdlib.h>
#include "pilhaSE.h"

// 8.1 criando as funções 
//8.2 Utilizando as operações

void criaPilha(Pilha *pl){
	pl->topo = NULL;
}

int empilha(Pilha *pl, Dado d){
	Nodo *novoNodo;
	novoNodo = (Nodo *) malloc(sizeof (Nodo));
	if(novoNodo == NULL){
		return FALTOU_MEMORIA;
	}
	else{
		novoNodo->info = d;
		novoNodo->prox = pl->topo;
		pl->topo = novoNodo;
		return SUCESSO;
	}
}

int desempilha(Pilha *pl, Dado *d){
	if(pl->topo == NULL){
		printf("Pilha Vazia!\n");
		return PILHA_VAZIA;
	}
	else{
		Nodo *nodoRemovido = pl->topo;
		*d= pl->topo->info;
		nodoRemovido = pl->topo->prox;
		free(pl->topo);
		pl->topo = nodoRemovido;
		printf("Nodo removido: %d\n ", *d);
		return SUCESSO;
	}
}

int estaVazia(Pilha pl){
	if(pl.topo== NULL){
		return PILHA_VAZIA;
	}
	else{
		return 0;
	}
}

int consultaTopo(Pilha pl, Dado *d){
	if(pl.topo==NULL){
		return PILHA_VAZIA;
	}
	else{
		*d= pl.topo->info;
		printf("Dados no topo da pilha: %d %f\n", d->cod, d->peso);
		return SUCESSO;
	}
}

void exibe(Pilha pl){
	if(pl.topo==NULL){
		printf("A pilha esta vazia!\n");
	}
	else{
		Nodo *atual = pl.topo;
		do{
			printf("Pilha SE: %d %f\n ", atual->info.cod, atual->info.peso);
			atual= atual->prox;
		}while(atual!=NULL);
}
}

int situacaoPilha(Pilha pl){
	if(pl.topo==NULL){
		printf("A pilha esta vazia\n");
		return PILHA_VAZIA;
	}
	else{
		printf("A pilha possui 1 ou mais nodos\n");
		return SUCESSO;
	}
}

int quantidadeNodos(Pilha *pl){
	if(pl->topo==NULL){
		printf("A pilha esta vazia\n");
		return PILHA_VAZIA;
}

	else{
		int contador = 0;
		Nodo *atual = pl->topo; 
		do{
			contador++;	
			atual = atual->prox;
		}while(atual != NULL);
		
		return contador;
	}
}

