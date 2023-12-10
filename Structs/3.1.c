#include<stdio.h>

struct Horario {
	int hora, minuto, segundo;
};

int main(){
	
	struct Horario hr, hs;
	
	printf("Informe a hora: ");
	scanf("%d", &hr.hora);
	
	printf("Informe o minuto: ");
	scanf("%d", &hr.minuto);
	
	printf("Informe o segundo: ");
	scanf("%d", &hr.segundo);
	
	printf("Horario 2: \n");
	
	printf("Informe a hora: ");
	scanf("%d", &hs.hora);
	
	printf("Informe o minuto: ");
	scanf("%d", &hs.minuto);
	
	printf("Informe o segundo: ");
	scanf("%d", &hs.segundo);
	
	if(hr.hora>hs.hora || hr.minuto>hs.minuto || hr.segundo>hs.segundo){
		printf("Menor horario: %d:%d:%d\n", hs.hora, hs.minuto, hs.segundo);
	}
	if(hr.hora<hs.hora || hr.minuto<hs.minuto || hr.segundo<hs.segundo){
		printf("Menor horario: %d:%d:%d\n", hr.hora, hr.minuto, hr.segundo);
	}
	if(hr.hora==hs.hora && hr.minuto==hs.minuto && hr.segundo==hs.segundo){
		printf("Horario iguais");
	}
	
	return 0;	
}
