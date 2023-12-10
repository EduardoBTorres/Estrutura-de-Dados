#include "3.4_Header.h"
#include <stdio.h>

int main(){
	
	Cheque cheque1, cheque2;
	float v, w, x;
	int z, y, u, s;
	
	printf("Digite numero do cheque 1:\n ");
	scanf("%d", &cheque1.numero);
	
	criaCheque(&cheque1, cheque1.numero);
	
	printf("Digite numero do cheque 2:\n ");
	scanf("%d", &cheque2.numero);
	
	criaCheque(&cheque2, cheque2.numero);
	
	printf("Digite valor do cheque 1:\n ");
	scanf("%f", &cheque1.valor);
	
	emiteCheque(&cheque1, cheque1.valor);
	
	printf("Digite valor do cheque 2: ");
	scanf("%f", &cheque2.valor);
	
	emiteCheque(&cheque2, cheque2.valor);
	
	exibeCheque(cheque1);
	
	exibeCheque(cheque2);
	
	v= obtemValor(cheque1);
	printf("Valor cheque 1: %f\n", v);
	
	w= obtemValor(cheque2);
	printf("Valor cheque 2: %f\n", w);
	
	if(obtemValor(cheque1) > obtemValor(cheque2)){
		x= compensaCheque(&cheque1);
	} else{
		x= compensaCheque(&cheque2);
	}
	
	z= obtemSituacao(cheque1);
	printf("Situacao cheque 1: %d\n", z);
	
	y= obtemSituacao(cheque2);
	printf("Situacao cheque 2: %d\n", y);
	
	u= obtemNumero(cheque1);
	printf("Numero do cheque 1: %d\n", u);
	
	s= obtemNumero(cheque2);
	printf("Numero do cheque 2: %d\n", s);
	
	return 0;			
}
