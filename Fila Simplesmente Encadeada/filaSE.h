#ifndef FilaSE_H
#define FilaSE_H

#define SUCESSO 0 
#define FILA_VAZIA 1
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
	Nodo *frente;
	Nodo *re;
} FilaSE;

void criaFila(FilaSE *f);
int insere(FilaSE *f, Dado d);
int retira(FilaSE *f, Dado *d);
int estaVazia(FilaSE f);
int consulta(FilaSE f, Dado *d);
int exibe(FilaSE f);
int quantidadeNodos(FilaSE *f);

#endif
