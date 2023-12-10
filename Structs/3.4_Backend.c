#include "3.4_Header.h"
#include <stdio.h>

void criaCheque(Cheque *cheque, int numero){
	
	cheque-> situacao = 0;
	cheque->numero = numero;
}

void exibeCheque(Cheque cheque){
	
	printf("Condicoes do cheque: %d, %d, %f", cheque.numero, cheque.situacao, cheque.valor);
}

int obtemSituacao(Cheque cheque){
	
	if(cheque.situacao==0){
		printf("Em branco");
	}
	
	if(cheque.situacao==1){
		printf("Emitido");
	}
	
	if(cheque.situacao==2){
		printf("Compensado");
	}
	return cheque.situacao;
}

float obtemValor(Cheque cheque){
	
	return cheque.valor;
}

int obtemNumero(Cheque cheque){
	
	return cheque.numero;
}

int compensaCheque(Cheque *cheque){
	
	if(cheque->situacao==1){
		cheque->situacao = 2;
		printf("Sucesso!");
		return 0;
	}
	else{
		printf("Erro!");
		return 1;
	}
}

int emiteCheque(Cheque *cheque, float valor){
	
	cheque->valor = valor;
	if(cheque->situacao==0){
		cheque->situacao = 1;
		return 0;
	}
	else{
		return 1;
	}
}
