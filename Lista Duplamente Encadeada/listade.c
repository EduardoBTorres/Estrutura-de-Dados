#include <stdio.h>
#include <stdlib.h>
#include "listade.h"

void criaLista(ListaDE *lt){
     lt->inicio = NULL;
     lt->fim = NULL;
     lt->n = 0;
}

int incluiNoInicio(ListaDE *lt, Dado d){
    Nodo *pNodo;
    pNodo = (Nodo *) malloc (sizeof (Nodo));
    if (pNodo == NULL)
       return(FALTOU_MEMORIA);
    else {
       pNodo->info = d;
       pNodo->prox = lt->inicio;
       pNodo->ant = NULL;
       
       if (lt->n == 0)
          lt->fim = pNodo;
       else
          lt->inicio->ant = pNodo;  

       lt->inicio = pNodo;
       lt->n++;
       return(SUCESSO);
    }
}

void exibe(ListaDE lt){
     Nodo *pAux;
     pAux = lt.inicio;
     printf("\nExibindo a Lista\n");
     printf("Inicio: %p \n", lt.inicio);
     printf("[End Ant]        [cd]       [End Nodo]     [peso]      [End Prox]\n");
     while (pAux != NULL) {
           printf("%p - %3d %p %.2f - %p\n", pAux->ant, pAux->info.cod, pAux, pAux->info.peso, pAux->prox);
           pAux = pAux->prox;
     }
     printf("Fim: %p - N= %d\n", lt.fim, lt.n);
}

int quantidadeDeNodos(ListaDE lt){
	return lt.n;
}

int estaVazia(ListaDE lt){
	if(lt.n == 0)
		return 1;
	else
		return 0;
}

int excluiDoInicio(ListaDE *lt, Dado *d){
	Nodo *pNodo;
	if(lt->n == 0)
		return (LISTA_VAZIA);
		
	else{
		*d = lt->inicio->info;
		pNodo = lt->inicio;
		lt->inicio = lt->inicio->prox;
		if(lt->n == 1)
			lt->fim = NULL;
		else
			lt->inicio->ant = NULL;
		lt->n--;
		printf("Dado Removido: %d\n", *d);
		free(pNodo);
		return (SUCESSO);
	}
}

int incluiNoFim(ListaDE *lt, Dado d){
	Nodo *pNodo;
	pNodo = (Nodo *) malloc(sizeof (Nodo));
	if(pNodo == NULL)
		return (FALTOU_MEMORIA);
	else{
		pNodo->info = d;
		pNodo->ant = lt->fim;
       	pNodo->prox = NULL;
		      
       	if (lt->n == 0)
          	lt->inicio = pNodo;
       	else
          	lt->fim->prox = pNodo;  

       	lt->fim = pNodo;
       	lt->n++;
       	return (SUCESSO);
	}
}

int excluiDoFim(ListaDE *lt, Dado *d){
	if(lt->n == 0)
		return (LISTA_VAZIA);
	else{
		Nodo *pNodo = lt->fim;
		*d = pNodo->info;
		lt->fim = pNodo->ant;
		
		if(lt->fim != NULL)
			lt->fim->prox = NULL;
		else
			lt->inicio = NULL;
		printf("Dado Removido: %d\n", *d);
		free(pNodo);
		lt->n--;
		return (SUCESSO);
	}		
}

int incluiDepois(ListaDE *lt, int codigo, Dado d){
	Nodo *pNodo;
	pNodo = (Nodo *) malloc(sizeof (Nodo));
	if(pNodo == NULL)
		return (FALTOU_MEMORIA);
		
	else{
		pNodo->info = d;
		
		if(lt->inicio == NULL){
			pNodo->prox = NULL;
			lt->inicio = pNodo;
			lt->fim = pNodo;
		} 
		else{
			Nodo *atual = lt->inicio;
			Nodo *anterior = NULL;
			while(atual != NULL && atual->info.cod != codigo){
				anterior = atual;
				atual = atual->prox;
			}
			
			if(atual == NULL){
				free(pNodo);
				return (CODIGO_INEXISTENTE);
			}
			
			pNodo->prox = atual->prox;
       	    atual->prox = pNodo;
       	    
       	    if(atual == lt->fim){
       	    	lt->fim = pNodo;
			}	
		}
	lt->n++;
	return (SUCESSO);	
	}
}

int excluiNodo(ListaDE *lt, int codigo, Dado *d){
	if(lt->n == 0)
		return (LISTA_VAZIA);
		
	else 
		if (lt->n == 1) {
        // Caso especial: apenas um nó na lista.
        Nodo *pNodo = lt->inicio;
        *d = pNodo->info;
        lt->inicio = NULL;
        lt->fim = NULL;
        free(pNodo);
        lt->n = 0;
        printf("Dado Removido: %d\n", *d);
        return (SUCESSO);
    }
		
	else{
		Nodo *pNodo = lt->inicio;
		while(pNodo != NULL){
			if(pNodo->info.cod == codigo){
				*d = pNodo->info;
				if(pNodo->ant != NULL)
					pNodo->ant->prox = pNodo->prox;
				else
					lt->inicio = pNodo->prox;
					
				if(pNodo->prox != NULL)
					pNodo->prox->ant = pNodo->ant;
					
				else
					lt->fim = pNodo->ant;
					
				printf("Dado Removido: %d\n", *d);	
				free(pNodo);
				lt->n--;
				return (SUCESSO);
			}
			pNodo = pNodo->prox;
		}
		return (CODIGO_INEXISTENTE);
	}
}

int consultaPorCodigo(ListaDE lt, int codigo, Dado *d){
	if(lt.n == 0)
		return (LISTA_VAZIA);
		
	else{
		int codigoEncontrado = 0;
		Nodo *atual = lt.inicio;
		while(atual != NULL){
			if(atual->info.cod == codigo){
				*d = atual->info;
				printf("Dados da pesquisa: %d %f\n", d->cod, d->peso);
				codigoEncontrado = 1;
				break;
			}
			atual = atual->prox;
		}
		if(codigoEncontrado == 1)
			return (SUCESSO);
		
		else
			return (CODIGO_INEXISTENTE);
	}
}

int exibeSituacao(ListaDE lt){
	if(lt.n == 0)
		return (LISTA_VAZIA);
		
	else
		return (SUCESSO);
}

int gravarEmArquivo(const char *nomeArquivo, ListaDE lt) {
    FILE *arquivo;

    arquivo = fopen(nomeArquivo, "w"); // Abre o arquivo para escrita ("w" sobrescreve o arquivo existente ou cria um novo)

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return FALTOU_MEMORIA;
    }

    Nodo *pAux = lt.inicio;

    while (pAux != NULL) {
        fprintf(arquivo, "%d %.2f\n", pAux->info.cod, pAux->info.peso);
        pAux = pAux->prox;
    }

    fclose(arquivo);

    printf("Situacao atual da lista gravada com sucesso no arquivo '%s'.\n", nomeArquivo);
    return SUCESSO;
}

int lerDeArquivo(const char *nomeArquivo, ListaDE *lt) {
    FILE *arquivo;
    Dado d;
    int cod;
    float peso;

    arquivo = fopen(nomeArquivo, "r"); 

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return FALTOU_MEMORIA;
    }

    while (fscanf(arquivo, "%d %f\n", &cod, &peso) == 2) {
        d.cod = cod;
        d.peso = peso;
        incluiNoFim(lt, d);
    }

    fclose(arquivo);

    printf("Dados lidos do arquivo '%s' e inseridos na lista com sucesso.\n", nomeArquivo);
    return SUCESSO;
}


