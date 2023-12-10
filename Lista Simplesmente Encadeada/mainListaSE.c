#include <stdio.h>
#include <stdlib.h>
#include "listaSE.h"

int main()
{
    int op,cd,peso, r;
    ListaSE lt;
    Dado d;
    
    criaLista(&lt);

    do {
      printf("\n0. Fim                         5. Exclui do Inicio         10. Exclui Nodo\n");    
      printf("1. Inclui no Inicio            6. Inclui no Fim            \n");    
      printf("2. Exibe Lista                 7. Exclui do Fim            \n");    
      printf("3. Quantidade de Nodos         8. Consulta por Codigo      \n");    
      printf("4. Exibe Situacao da Lista     9. Inclui Depois.           \n");
      printf("Operacao: ");    
      scanf("%d", &op);

      switch(op){
            case 1:
                 printf("[cd][peso]\n");
                 scanf (" %d %f", &d.cod,&d.peso);
                 if (incluiNoInicio(&lt, d)==SUCESSO)
                    printf("Operacao Realizada com Sucesso!\n");
                 else
                    printf("Operacao NAO realizada: Faltou Memoria!");
                 break;
                 
            case 2: 
            	exibe(lt);
            	break;
            	
            case 3:
                 printf("Quantidade de Nodos= %d\n", quantidadeDeNodos(lt));
                 break;
                 
            case 4: 
            	if(exibeSituacao(lt) == LISTA_VAZIA){
            		printf("Lista Vazia!");
				}
            	else{
            		printf("A lista possui 1 ou mais nodos!");
				}
				break;
				
			case 5: 
				r= excluiDoInicio(&lt, &d);
            	break;
            	
            case 6: 
            	printf("[cd][peso]\n");
                 scanf (" %d %f", &d.cod,&d.peso);
                 if (incluiNoFim(&lt, d)==SUCESSO)
                    printf("Operacao Realizada com Sucesso!\n");
                 else
                    printf("Operacao NAO realizada: Faltou Memoria!");
                 break;
            	
            case 7:
            	r= excluiDoFim(&lt, &d);
            	break;
            	
            case 8: 
            	printf("Insira o codigo de referencia: \n");
            	scanf("%d", &cd);
                if (consultaPorCodigo(lt, cd, &d)==SUCESSO)
                	printf("Operacao Realizada com Sucesso!\n");
                else
                    printf("Codigo inexistente!");
                break;
            	
            case 9:
            	printf("Insira o codigo de referencia: \n");
            	scanf("%d", &cd);
            	printf("Insira o codigo e o peso: \n");
                scanf (" %d %f", &d.cod, &d.peso);
            	
            	if (incluiDepois(&lt, cd, d)==SUCESSO)
                	printf("Operacao Realizada com Sucesso!\n");
                else
                    printf("Operacao NAO realizada: Faltou Memoria!");
                break;
            	
            	
            case 10:
            	printf("Informe um codigo: ");
				scanf("%d",&cd);
				if (excluiNodo(&lt, cd, &d) == LISTA_VAZIA) {
					printf("ERRO: Lista Vazia!\n");
				}
				if (excluiNodo(&lt, cd, &d) == CODIGO_INEXISTENTE) {
					printf("ERRO: Codigo Inexistente!\n");
				} 
				if (excluiNodo(&lt, cd, &d) == SUCESSO) {
					printf("Dados excluidos com SUCESSO!\n");
				}
				
				break;            	
      }
      exibe(lt);            
    } while (op!=0);  

  return(0);
}
