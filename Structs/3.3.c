#include<stdio.h>

//Estrutura
typedef struct{
	
	int num_conta;
	float saldo_conta;
	
} CONTA;

//Funções
void criaConta(CONTA *conta, int num_conta);

void depositaNaConta(CONTA *conta, float valor_deposito);

void retiraDaConta(CONTA *conta, float valor_retirada);

float obtemSaldo(CONTA num_conta);

//Programa Principal
int main(){
	
	CONTA conta_corr, conta_poup;
	int codigo_op;
	float valor_movimento, saquepoupemp;
	
	printf("Ola Sr Silva, crie uma conta para voce!\n");
	
	printf("Digite o numero da sua conta corrente : ");
	scanf("%d", &conta_corr.num_conta);
	
	criaConta(&conta_corr, conta_corr.num_conta);
	
	printf("Saldo da CONTA CORRENTE: ");
	scanf("%f", &conta_corr.saldo_conta);
	
	printf("Digite o numero da sua conta poupanca : ");
	scanf("%d", &conta_poup.num_conta);
	
	criaConta(&conta_poup, conta_poup.num_conta);
	
	printf("Saldo da CONTA POUPANCA: ");
	scanf("%f", &conta_poup.saldo_conta);
	
	do{
		printf("Escolha a operacao que deseja realizar:\n ");
		printf("1- Deposito conta corrente, 2- Deposito conta poupanca, 3- Retirada conta corrente, 4- Retirada poupanca, 5- Fim:\n ");
		scanf("%d", &codigo_op);
		
		if(codigo_op==5){
			printf("FIM");
			break;
		}
		
		printf("Valor do Movimento: ");
		scanf("%f", &valor_movimento);
		
		if(codigo_op==1){
			depositaNaConta(&conta_corr, valor_movimento);
		}
		
		if(codigo_op==2){
			depositaNaConta(&conta_poup, valor_movimento);
		}
		
		if(codigo_op==3){
			if(conta_corr.saldo_conta < valor_movimento){
				if(conta_poup.saldo_conta >= (conta_corr.saldo_conta - valor_movimento)){
					saquepoupemp = valor_movimento - conta_corr.saldo_conta;
					retiraDaConta(&conta_poup, saquepoupemp);
					conta_corr.saldo_conta = 0;
				}
				else{
					printf("\n Saldo Insuficiente! \n");
				}
			}
			else {
				retiraDaConta(&conta_corr, valor_movimento);				
			}
		}
		
		if(codigo_op==4){
			retiraDaConta(&conta_poup, valor_movimento);
		}
		
		printf("Saldo Atualizado: \n");
		printf("Saldo Conta Corrente: = %f\n", conta_corr.saldo_conta);
		printf("Saldo Conta Poupanca: = %f\n", conta_poup.saldo_conta);
		
	}while(codigo_op!=5);
	
	return 0;
}

//Programando as funções

void criaConta(CONTA *conta, int num_conta){
	
	conta-> num_conta = num_conta;
	conta->saldo_conta = 0;	
}

void depositaNaConta(CONTA *conta, float valor_deposito){
	
	conta->saldo_conta = conta->saldo_conta + valor_deposito;
}

void retiraDaConta(CONTA *conta, float valor_retirada){
	
	if(conta->saldo_conta >= valor_retirada){
		conta->saldo_conta = conta->saldo_conta - valor_retirada;
	}
	else{
		printf("\n Saldo Insuficiente! \n");
	}
}

float obtemSaldo(CONTA num_conta){
	
	return num_conta.saldo_conta;	
}

