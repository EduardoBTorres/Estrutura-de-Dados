/*--------------------------------
* Arquivo: ListaCF.c
----------------------------------*/

#include <stdio.h>
#include "ListaCF.h"

/*-----------------
* S: uma lista
*/
void criaLista(ListaCF *lt) {
	lt->n = 0;
}

/*-----------------
* E/S: uma lista
* E: um dado
* R: SUCESSO ou LISTA_CHEIA
*/
int incluiNoFim(ListaCF *lt, Dado d) {
	if (lt->n == MAX_NODOS)
		return LISTA_CHEIA;
	else {
		lt->v[lt->n] = d;
		lt->n++;
		return SUCESSO;
	}	
}

/*-----------------
* E: uma lista
*/
void exibe(ListaCF lt) {
	int i;
	
	printf("-------------\n");
	printf("Lista:\n");
	for (i=0; i<lt.n; i++) 
		printf("   %d %.2f\n", lt.v[i].cod,lt.v[i].peso);
	printf("-------------\n\n");			
}


int quantidadeDeNodos(ListaCF lt){
	if(lt.n == 1){
		return LISTA_VAZIA;
		}
		else{
			return lt.n;
		}
	}

int estaCheia(ListaCF lt){
	if(lt.n == MAX_NODOS){
		return LISTA_CHEIA;
	}
	else
		return SUCESSO;
}

int estaVazia(ListaCF lt){
	if(lt.n == 0){
		return LISTA_VAZIA;
	}
	else
		return SUCESSO;
}

int excluiDoFim(ListaCF *lt, Dado *dado){
	int i;
	if(lt->n == 0){
		return LISTA_VAZIA;
	}
	else{
		*dado= lt->v[4];
		for(i=lt->n; i>0; i--){
			lt->v[i-4] = lt->v[i];
		}
		lt->n--;
		return SUCESSO;		
	}
}

int incluiNoInicio(ListaCF *lt, Dado dado){
	int i;
	if(lt->n == MAX_NODOS){
		return LISTA_CHEIA;
	}
	else{
		for(i=lt->n; i>=0; i--){
			lt->v[i+1]=lt->v[i];
			}
		
		lt->v[0] = dado;
		lt->n++;
		return SUCESSO;
	}
}

int excluiDoInicio(ListaCF *lt, Dado *dado){
	int i;
	if(lt->n == 0){
		return LISTA_VAZIA;
	}
	else{
		*dado= lt->v[0];
		for(i=1; i<lt->n; i++)
			lt->v[i-1] = lt->v[i];
		lt->n--;
		return SUCESSO;
	}
}

int consultaPorCodigo(ListaCF lt, Dado dado){
	int i;
	for(i=0; i<=lt.n; i++){
		if(lt.v[i].cod == dado.cod){
			printf("Dado encontrado com sucesso!: %d", lt.v[i].cod, lt.v[i].peso);
			return SUCESSO;
		}
		else{
			printf("Dado nao encontrado!");
			return CODIGO_INEXISTENTE;
		}
	}
}

int incluiAntes(ListaCF *lt, int codigo, Dado dado){
	int i, j;
	if(lt->n == MAX_NODOS){
		return LISTA_CHEIA;
	}
	if(lt->n == 0){
		return LISTA_VAZIA;
	}
	if(lt->n!=MAX_NODOS && lt->n!=0){
		for(i=0; i<=lt->n; i++){
			if(codigo==lt->v[i].cod){
				for(j=0; j<=lt->n; j++){
					lt->v[j]=lt->v[j-1];
				}
				lt->v[i].cod=dado.cod;
				lt->v[i].peso=dado.peso;
				lt->n++;
				return SUCESSO;
			}
			else{
				return CODIGO_INEXISTENTE;
			}
		}
	}
}


int excluiNodo(ListaCF *lt, Dado *d){
	int i,j,achou;
	if (lt->n == 0){
			printf("\nLista vazia!\n");
			return LISTA_VAZIA;
		}
		else{
			for(i=0;i<=lt->n;i++){
				if(lt->v[i].cod==d->cod){
					for(j=i;j<=lt->n;j++){
						lt->v[j]=lt->v[j+1];
					}
					achou=1;
					lt->n--;
					printf("\nDado excluido com sucesso!\n");
				} if(achou==1) break;
			}if (achou==1){
					return SUCESSO;
				}else return CODIGO_INEXISTENTE;
		}
}

// funções criadas para 6.2

void exibeSituacao(ListaCF lt){
	if(lt.n == 0){
		printf("A lista esta vazia\n");
	}
	
	if(lt.n == MAX_NODOS){
		printf("A lista esta cheia\n");
	}
	else{
		printf("A lista possui 1 ou mais nodos\n");
	}
}
