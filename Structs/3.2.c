#include<stdio.h>

struct Data{
	int dia, mes, ano;
};

struct Aluno{
	int matricula;
	struct Data dtNasc;
};

int main(){
	
	struct Data dt_hj;
	struct Aluno dados;
	
	printf("Informe a data de hoje: ");
	scanf("%d", &dt_hj.dia);
	scanf("%d", &dt_hj.mes);
	scanf("%d", &dt_hj.ano);
	
	do{
		printf("Informe dados do aluno:\n ");
		
		printf("Informe Nascimento do aluno: ");	
		scanf("%d", &dados.dtNasc.dia);
		scanf("%d", &dados.dtNasc.mes);
		scanf("%d", &dados.dtNasc.ano);
		
		printf("Informe matricula do aluno: ");
		scanf("%d", &dados.matricula);
		
		if(dt_hj.ano - dados.dtNasc.ano>=18){
			printf("Aluno maior de idade\n");
		}
			else{
				printf("Aluno nao completou 18 anos\n");
			}
		
		
		if(dados.matricula<=0){
			break;
		}	
		
	}while(dados.matricula>0);
}
