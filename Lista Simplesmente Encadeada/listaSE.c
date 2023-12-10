#include <stdio.h>
#include <stdlib.h>
#include "listaSE.h"

void criaLista(ListaSE *lt){
     lt->inicio = NULL;
}

int incluiNoInicio(ListaSE *lt, Dado d){
    Nodo *pNodo;
    pNodo = (Nodo *) malloc (sizeof (Nodo));
    if (pNodo == NULL)
       return(FALTOU_MEMORIA);
    else {
       pNodo->info = d;
       pNodo->prox = lt->inicio;
       lt->inicio = pNodo;
       return(SUCESSO);
    }
}
 
void exibe(ListaSE lt){
     Nodo *pAux;
     pAux = lt.inicio;
     printf("\nInicio: %p \n", lt.inicio);
     printf("Exibindo a Lista\n");
     printf("[EndNodo] [cd] [peso] [EndProx]\n");
     while (pAux != NULL) {
           printf("%p - %3d %.2f - %p\n", pAux, pAux->info.cod, pAux->info.peso, pAux->prox);
           pAux = pAux->prox;
     }
}

int quantidadeDeNodos(ListaSE lt){
    int conta=0;
    Nodo *pAux;
    
    pAux = lt.inicio;
    while (pAux != NULL) {
           conta++;
           pAux = pAux->prox;
    }
    return(conta);
}

int estaVazia(ListaSE lt){
    if (lt.inicio==NULL)
       return(LISTA_VAZIA);
    else
       return(0);     
}

int excluiDoInicio(ListaSE *lt, Dado *dado){
	if(lt->inicio == NULL){
		printf("Lista Vazia!");
		return (LISTA_VAZIA);
	}
	else{
		Nodo *nodoRemovido = lt->inicio;
		*dado = nodoRemovido->info;
		lt->inicio = nodoRemovido->prox;
		printf("Nodo Removido: %d\n", *dado);
		free(nodoRemovido);
		return (SUCESSO);
	}
}

int incluiNoFim(ListaSE *lt, Dado d){
	Nodo *pNodo;
	pNodo = (Nodo *) malloc(sizeof (Nodo));
	if(pNodo == NULL)
		return (FALTOU_MEMORIA);
	else{
		pNodo->info = d;
		pNodo->prox = NULL;
		
		if(lt->inicio == NULL){
			lt->inicio = pNodo; 
			return (SUCESSO);
		}
		else{
			Nodo *ultimo = lt->inicio;
			while(ultimo->prox != NULL){
				ultimo = ultimo->prox;
			}
			
		ultimo->prox = pNodo;
		return (SUCESSO);
		}
	}
}

int excluiDoFim(ListaSE *lt, Dado *d){
	if(lt->inicio == NULL){
		printf("A lista esta vazia!");
		return (LISTA_VAZIA);
	}
	else{
		Nodo *penultimo = NULL, *ultimo = lt->inicio;

		while(ultimo->prox != NULL){
			penultimo = ultimo;
			ultimo = ultimo->prox;
		}
		*d = ultimo->info; // Copia o dado do último elemento para o ponteiro 'd'
		printf("Nodo Removido: %d\n", *d);
		if (penultimo != NULL) {
			penultimo->prox = NULL; // Atualiza o ponteiro do penúltimo para NULL
		} else {
			lt->inicio = NULL; // Se o último elemento era o primeiro, atualize o início da lista
		}
		free(ultimo); // Libera o nó removido

		return (SUCESSO);
	}
}


int incluiDepois(ListaSE *lt, int codigo, Dado d){
	Nodo *pNodo;
	pNodo = (Nodo *) malloc(sizeof (Nodo));
	if(pNodo == NULL)
		return (FALTOU_MEMORIA);
		
	 else {
    	pNodo->info = d;

		if (lt->inicio==NULL) {
	       	pNodo->prox=NULL;
	        lt->inicio=pNodo;
	    } else {
        Nodo *atual=lt->inicio;

        while(atual!=NULL && atual->info.cod != codigo) {
            atual = atual->prox;
        }

        if (atual==NULL) {
            free(pNodo);
            return CODIGO_INEXISTENTE;
        }

        pNodo->prox=atual->prox;
        atual->prox=pNodo;
    }
    return SUCESSO;
	}
}

int excluiNodo(ListaSE *lt, int cd, Dado *d) {
    if (lt->inicio == NULL) {
        return LISTA_VAZIA;
    } else {
        Nodo *excluido = lt->inicio;
        Nodo *anterior = NULL;
        while (excluido != NULL){
        	if(excluido->info.cod == cd){
            	*d = excluido->info;
            	if(anterior == NULL){
            		lt->inicio = excluido->prox;
				} else{
					anterior->prox = excluido->prox;
				}
            	printf("Nodo excluido: %d\n", *d);
            	free(excluido);
            	return SUCESSO;
        	}
        	else{
        		anterior = excluido;
        		excluido = excluido->prox;
			}
   		 }
		return CODIGO_INEXISTENTE;   
	}
}

int consultaPorCodigo(ListaSE lt, int cd, Dado *d){
	if (lt.inicio == NULL) {
		printf("Lista Vazia!");
        return LISTA_VAZIA;
    }
    else{
		Nodo *atual = lt.inicio;
		int codigoEncontrado = 0;
		while(atual != NULL){
			if(atual->info.cod == cd){
				*d= atual->info;
				printf("Dados da pesquisa: %d %f\n", d->cod, d->peso);
				codigoEncontrado = 1;
			}
			atual = atual->prox;
		}
		if(codigoEncontrado = 1){
			return (SUCESSO);
		}
		else{
				return CODIGO_INEXISTENTE;
			}	
	}
}

int exibeSituacao(ListaSE lt){
	if(lt.inicio == NULL){
		return (LISTA_VAZIA);
	}
	else{
		return (SUCESSO);
	}
}


