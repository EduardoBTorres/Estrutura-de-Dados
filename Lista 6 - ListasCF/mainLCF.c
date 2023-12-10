/*--------------------------------
Arquivo: mainListaCF.c
----------------------------------*/

#include <stdio.h>
#include "ListaCF.h"


int main() {
	ListaCF lista;
	Dado dado;
	int cod, r;
	
	criaLista(&lista);
	do {
		printf("0-Fim\n");
		printf("1-Inclui no fim\n");
		printf("2-Exibe lista\n");		
		printf("3-Quantidade de nodos\n");
		printf("4-Exibe situacao da lista\n");
		printf("5-Exclui do fim\n");
		printf("6-Inclui no inicio\n");
		printf("7-Exclui do inicio\n");
		printf("8-Consulta por codigo\n");	
		printf("9-Inclui antes\n");		
		printf("10-Exclui nodo\n\n");	
		printf("Informe a operacao: ");
		scanf("%d",&cod);
		
		switch (cod)
			{
			case 1 : printf("Informe o codigo: ");
					 scanf("%d",&dado.cod);
					 printf("Informe o peso: ");
					 scanf("%f",&dado.peso);
					 r= incluiNoFim(&lista, dado);
					 break;
					 
			case 2 : exibe(lista);
					 break;
					 
			case 3 : r= quantidadeDeNodos(lista);
					 break;
					 
			case 4 : exibeSituacao(lista); 
					 break;
					 
			case 5 : r= excluiDoFim(&lista, &dado); 
					 break;
					 
			case 6 : printf("Digite um codigo: ");
					 scanf("%d", &dado.cod);
					 printf("Digite o peso: ");
					 scanf("%f", &dado.peso);
					r= incluiNoInicio(&lista, dado);
					 break;
					 
			case 7 : r= excluiDoInicio(&lista, &dado);
					 break;
					 
			case 8 : printf("Informe o codigo: ");
					 scanf("%d",&dado.cod);
					 r= consultaPorCodigo(lista, dado);
					 break;
					 
			case 9 : printf("Informe o codigo: ");
					 scanf("%d",&dado.cod);
					 printf("Informe o peso: ");
					 scanf("%f",&dado.peso);
					r= incluiAntes(&lista, cod, dado);
					 break;
					 
			case 10: printf("Digite o nodo que deseja excluir: ");
					 scanf("%d", &dado.cod);
					 r=excluiNodo(&lista, &dado);  
					 break;
			}
		if (cod != 2)
			exibe(lista);

	} while (cod !=0);

	return 0;
}
