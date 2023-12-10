#ifndef Cheque_H
#define Cheque_H

typedef struct {
	
	int numero, situacao;
	float valor;
	
} Cheque;

void criaCheque(Cheque *cheque, int numero);

void exibeCheque(Cheque cheque );

int obtemSituacao(Cheque cheque);

float obtemValor(Cheque cheque);

int obtemNumero(Cheque cheque);

int compensaCheque(Cheque *cheque);

int emiteCheque(Cheque *cheque, float valor);

#endif

