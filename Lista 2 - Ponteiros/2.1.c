#include<stdio.h>

void duplaCrescente(int *a, int *b){
	
	if(a>b){
		printf("%d ", *a);
		printf("%d\n", *b);
	}
	if(b>a){
		printf("%d ", *b);
		printf("%d\n", *a);
	}
}

main(){
	
	int a, b;
	
	do{
		printf("Digite um numero inteiro: ");
		scanf("%d", &a);
		
		printf("Digite outro inteiro: ");
		scanf("%d", &b);
		
		if(a==b){
		}
		
		duplaCrescente(&a,&b);
	}while(a!=b);	
}
