#include <stdio.h>
#include <stdlib.h>
#include "pilhacf.h"

//5.2 - Escrevendo o programa

int main(){
    int op;
    PilhaCF pl;
    int d, r, c, c1;
    c1=0;
    
    criaPilha(&pl);

    do {
      printf("\n0. Fim                       4. Exibe Situacao da Pilha\n");    
      printf("1. Empilha                     5. ConsultaTopo\n");    
      printf("2. Desempilha                  6. Pesquisa\n");        
      printf("3. Quantidade de nodos\n");
      printf("Operacao: ");    
      scanf("%d", &op);

      switch(op){
            case 1:
            do{
				printf("Codigo: ");
            	scanf("%d", &pl);
            	printf("Peso de uma pessoa: ");
            	scanf("%d", &d);
            	r= empilha(&pl, d);
            	c1++;
            }while(c1<5);
                break;
            case 2:
				r= desempilha(&pl, &d);
                 break;
            case 3:
				nodosPilha(pl);
                 break;
            case 4:
				r= situacaoPilha(pl);
                 break;
            case 5:
            	r= consulta(pl, &d);
                 break;    
			case 6:
				printf("Digite um codigo: ");
				scanf("%d", &d);
				r= pesquisa(pl, c, &d);
				 break; 
      }
      exibePilha(pl);     
	  if(op==SUCESSO){
	  	printf("Operacao realizada com sucesso!");
	  }       
    } while (op!=0);  
                 
  return 0;
}
