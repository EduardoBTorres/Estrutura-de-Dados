#include <stdio.h>
#include <stdlib.h>
#include "pilhacf.h"

//5.1 - Implementando as operações
//5.2 - Usando as operações 

void criaPilha(PilhaCF *pl){
     pl->topo= -1;
}

void exibePilha(PilhaCF pl){
     int f;
     printf("Exibindo a Pilha\n");
     printf("[dado]\n");
     for (f=pl.topo;f >= 0;f--)
         printf("%4d\n", pl.v[f]);     
}

int empilha(PilhaCF *pl, int d){
	if(pl->topo == MAX_NODOS-1)
		return (PILHA_CHEIA);
	else{
		pl->topo++;
		pl->v[pl->topo] = d;
		return (SUCESSO);
	}
}

int desempilha(PilhaCF *pl,int *d){
	if(pl->topo == -1)
		return (PILHA_VAZIA);
	else{
		*d= pl->v[pl->topo];
		printf("Dados do topo da pilha: %d", *d);
		pl->topo--;
		return (SUCESSO);
	}
}

int estaVazia(PilhaCF pl){
	if(pl.topo == -1){
		return (PILHA_VAZIA);
	}
	else{
		return (SUCESSO);
	}
}

int estaCheia(PilhaCF pl){
	if(pl.topo == pl.v[MAX_NODOS] - 1){
		return (PILHA_CHEIA);
	}
	else{
		return (SUCESSO);
	}
}

int consulta(PilhaCF pl, int *d){
	if(pl.topo > 1){
		d= pl.v[pl.topo];
		printf("Dados do topo da pilha: %d", d); //consulta topo com problemas
		return (SUCESSO);
	}
	else{
		return (PILHA_VAZIA);
	}
}

void nodosPilha(PilhaCF pl){
	printf("Nodos da pilha: %d", pl.v[MAX_NODOS]);
}

int pesquisa(PilhaCF pl, int codigo, int *d){
	int i;
			for(i=pl.topo; i<0; i--){
	
				if(codigo== pl.v[i]){
					d[codigo]= pl.v[i];
					printf("Dados do nodo solicitado: %d", d[codigo]);
					return (SUCESSO);
				}
			
				if(codigo!=pl.v[MAX_NODOS]){
				return (DADO_INEXISTENTE);
				}
			
				if(pl.topo==-1){
				return (PILHA_VAZIA);
				}
			}
}

int situacaoPilha(PilhaCF pl){
	if(pl.topo == -1){
		return printf("A pilha esta vazia");
	}
	if(pl.topo == pl.v[MAX_NODOS] - 1){
		return printf("A pilha esta cheia");
	}
	else{
		return printf("A pilha possui um ou mais nodos");
	}
}

