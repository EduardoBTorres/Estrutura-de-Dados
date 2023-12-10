#include<stdio.h>

float calcDivisao(float *a, float *b){
	
	float div;
	
	div= *a / *b;
	return div;
	
	if(*b==0){
		printf("Divisao por zero ");
		return 1;
	}
	else{
		return 0;
	}
}

main(){
	
	float n, a, b, i, v;
	
	printf("Digite um valor N: ");
	scanf("%f", &n);
	
	for(i=0; i<n; i++){
		printf("Ler um valor: ");
		scanf("%f", &a);
		
		printf("Ler outro valor: ");
		scanf("%f", &b);
		
		v= calcDivisao(&a, &b);
		printf("%f", v);
	}

}
