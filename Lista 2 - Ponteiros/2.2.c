#include<stdio.h>

void duplaCrescente(int a, int b){
	
	int *p, *p2;
	
	p=&a;
	p2=&b;
	
	if(a<b){
		*p=1;
		*p2=2;
		printf("%d ", *p);
		printf("%d\n", *p2);
	}
	if(b<a){
		*p=1;
		*p2=2;
		printf("%d ", *p);
		printf("%d\n", *p2);
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
			break;
		}
		if(a<b){
			printf("%d ", a);
			printf("%d\n",b);
		}
			
			else{
				printf("%d ", b);
				printf("%d\n", a);
				
			}
			
			duplaCrescente(a,b);
	}while(a!=b);	
}
