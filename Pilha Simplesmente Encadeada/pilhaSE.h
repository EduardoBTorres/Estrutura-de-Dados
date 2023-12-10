#ifndef PilhaSE_H
#define PilhaSE_H

#define SUCESSO 0 
#define PILHA_VAZIA 1
#define FALTOU_MEMORIA 2

typedef struct {
	int cod;
	float peso;
} Dado;

typedef struct nodo Nodo;

struct nodo {
	Dado info;
	Nodo *prox;
};

typedef struct {
	Nodo *topo;
} Pilha;

void criaPilha(Pilha *pl);
int empilha(Pilha *pl, Dado d);
int desempilha(Pilha *pl, Dado *d);
int estaVazia(Pilha pl);
int consultaTopo(Pilha pl, Dado *d);
void exibe(Pilha pl);
int situacaoPilha(Pilha pl);
int quantidadeNodos(Pilha *pl);
#endif
