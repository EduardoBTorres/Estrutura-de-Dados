#include <stdio.h>
#include <stdlib.h>
#include "pilhaSE.h"

int main(){
    int op, r;
    Pilha pl;
    Dado d;
    
    criaPilha(&pl);

    do {
      printf("\n0. Fim\n ");    
      printf("1. Empilha\n");    
      printf("2. Desempilha\n");    
      printf("3. Quantidade de Nodos\n");    
      printf("4. Exibe Situacao da Pilha\n");
      printf("5. Exibe Pilha\n");
      printf("6. Consulta Topo\n");
      printf("Operacao: ");    
      scanf("%d", &op);

      switch(op){
            case 1:
            	printf("Digite um codigo: ");
            	scanf("%d", &d.cod);
            	printf("Digite um peso: ");
            	scanf("%f", &d.peso);
            	
            	r= empilha(&pl, d);
                break;
                
            case 2:
            	r= desempilha(&pl, &d);
            	
                 break;
                 
            case 3:
            	 r= quantidadeNodos(&pl);

                 break;
                 
            case 4:
            	r= situacaoPilha(pl);

                 break;
                 
            case 5:
            	exibe(pl);
                break;
            case 6:
            	r= consultaTopo(pl, &d);
                 break;   
      }
      exibe(pl);            
    } while (op!=0);  
                 
  return 0;
}
