#include <stdio.h>
#include <stdlib.h>
#include "listade.h"

int main()
{
    int op, codigo, peso, r;
    ListaDE lt;
    Dado d;
    char nomeArquivo[] = "dados.txt";
    char conteudo[] = "Exemplo";
    
    criaLista(&lt);

    do {
      printf("\n0. Fim                         5. Exclui do Inicio         10. Exclui Nodo\n");    
      printf("1. Inclui no Inicio            6. Inclui no Fim            11. Grava em arquivo de texto\n");    
      printf("2. Exibe Lista                 7. Exclui do Fim            12. Le de arquivo de texto\n");    
      printf("3. Quantidade de Nodos         8. Consulta por Codigo      \n");    
      printf("4. Exibe Situacao da Lista     9. Inclui Depois 	 		 \n");
      printf("Operacao: ");    
      scanf("%d", &op);

      switch(op){
            case 1:
                 printf("[cd][peso]\n");
                 scanf (" %d %f", &d.cod,&d.peso);
                 if (incluiNoInicio(&lt, d)==0)
                    printf("Operacao Realizada com Sucesso!\n");
                 else
                    printf("Operacao NAO realizada: Faltou Memoria!");
                 break;
                 
            case 2: 
            	exibe(lt);
            	break;
            	
            case 3:
            	r = quantidadeDeNodos(lt);
            	printf("Quantidade de Nodos: %d", r);
            	break;
            	
            case 4: 
            	if(exibeSituacao(lt) == LISTA_VAZIA)
            		printf("A lista esta vazia!");
            	else
            		printf("A lista possui 1 ou mais nodos!");	
				break;
				
			case 5:
				if(excluiDoInicio(&lt, &d) == LISTA_VAZIA)
					printf("Lista Vazia!\n");
				else
					printf("Operacao realizada com SUCESSO!\n");
				break;
				
			case 6: 
				printf("[cd][peso]\n");
                scanf (" %d %f", &d.cod,&d.peso);
                if (incluiNoFim(&lt, d) == SUCESSO)
                    printf("Operacao Realizada com Sucesso!\n");
                else
                	printf("Operacao NAO realizada: Faltou Memoria!\n");
                break;
            	
            case 7:
            	if(excluiDoFim(&lt, &d) == LISTA_VAZIA)
					printf("Lista Vazia!\n");
				else
					printf("Operacao realizada com SUCESSO!\n");
				break;
				
			case 8:
				printf("Insira o codigo: ");
				scanf("%d", &codigo);
				
				r = consultaPorCodigo(lt, codigo, &d);
				if(r == LISTA_VAZIA)
					printf("Lista Vazia!\n");
				if(r == SUCESSO)
					printf("Codigo Encontrado!\n");
            	else
            		printf("Codigo Inexistente!\n");
            	break;
            	
            case 9: 
            	printf("Insira um codigo de referencia: ");
            	scanf("%d", &codigo);
            	printf("Insira o codigo: ");
            	scanf("%d", &d.cod);
            	printf("Insira o peso: ");
            	scanf("%f", &d.peso);
            	
            	r = incluiDepois(&lt, codigo, d);
            	if(r == FALTOU_MEMORIA)
            		printf("Operacao NAO realizada: Faltou Memoria!\n");
            	if(r == CODIGO_INEXISTENTE)
            		printf("Codigo Inexistente!\n");
            	else
            		printf("Operacao realizada com SUCESSO!");
            	break;
            	
            case 10:
            	printf("Insira o codigo do nodo que deseja excluir: ");
            	scanf("%d", &codigo);
            	
            	r = excluiNodo(&lt, codigo, &d);
            	if(r == LISTA_VAZIA)
					printf("Lista Vazia!\n");
				if(r == SUCESSO)
					printf("Operacao realizada com SUCESSO!\n");
				else
					printf("Codigo Inexistente!\n");
				break;
				
			case 11:
				gravarEmArquivo("dados.txt", lt);
				break;
				
			case 12:
				lerDeArquivo("dados.txt", &lt);
				break;
      }
      exibe(lt);            
    } while (op!=0);  

  return(0);
}
