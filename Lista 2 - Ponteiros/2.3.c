#include<stdio.h>

void duplaClassificada(int *codigo, int *a, int *b){
	
	
	if(*codigo==0){
		printf("%d\n", *a);
		printf("%d", *b);	
	}
	if(*codigo==1){
		printf("%d\n", *b);
		printf("%d\n", *a);
	}
}

main(){
	
	int a, b, codigo, x;
	
	do{

		printf("Digite um inteiro: ");
		scanf("%d", &a);
		
		printf("Digite um inteiro: ");
		scanf("%d", &b);
			
		if(a==b){
			break;
		}
		
		printf("Digite codigo: ");
		scanf("%d",  &codigo);
		
		x=a+b;
		
		if(x%2==0){
			duplaClassificada(&codigo, &a, &b);
		}
	
		if(x%2>0){
			duplaClassificada(&codigo, &a, &b);
		}
		
	
	}while(codigo==0 || codigo==1);
}

