#include <stdio.h>
#include <stdlib.h>
#include "filaSE.h"

int main(){
	int op, r, v;
	FilaSE f;
	Dado d;
	
	criaFila(&f);
	
	do{
		printf("\n0. Fim\n ");    
      	printf("1. Insere\n");    
      	printf("2. Retira\n");    
      	printf("3. Quantidade de Nodos\n");    
      	printf("4. Exibe Situacao da Fila\n");
      	printf("5. Consulta Frente\n");
      	printf("Operacao: ");    
      	scanf("%d", &op);
      	
      	 switch(op){
            case 1:
            	printf("Digite um codigo: ");
            	scanf("%d", &d.cod);
            	
				printf("Digite um peso: ");
            	scanf("%f", &d.peso);
            	
            	r= insere(&f, d);
                break;
                
            case 2:
            	r= retira(&f, &d);
                 break;
                 
            case 3:
            	 r= quantidadeNodos(&f);
                 break;
                 
            case 4:
            	r= estaVazia(f);
                 break;
                 
            case 5:
            	r= consulta(f, &d);
                break;
      }
      v= exibe(f);            
    } while (op!=0);  
    
    return 0;
}
