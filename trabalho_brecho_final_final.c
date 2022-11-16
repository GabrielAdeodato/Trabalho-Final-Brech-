//bibliotecas
#include<locale.h> //permite escrever acentos.
#include<stdio.h>
#include<math.h>
#include<string.h>

int main () {
	
	setlocale(LC_ALL, "Portuguese");
	
	//decla��o de vari�veis
	char nomeProduto[100], marcaProduto[100];
	char desconto;
	char dados;
	int qntProduto, descontoInvalido, opcaoInvalida, codigoProduto, quantProduto, dia, mes, ano, verificaData, verificaQuantidade;
	float precoProduto, precoVenda, precoDesconto, precoCompra;
	
	//requerimento de informa��es sobre o produto que est� sendo adicionado
	
	
	

		printf("Digite o produto que est� sendo vendido: ");
		fgets(nomeProduto, 100, stdin);
		nomeProduto[strcspn(nomeProduto, "\n")] = 0;
		
		printf("\nDigite a marca do produto: ");
		fgets(marcaProduto, 100, stdin);
		marcaProduto[strcspn(marcaProduto, "\n")] = 0;
		
		do{
		
			printf("\nDigite a quantidade adiquirida do produto: ");
			scanf("%d", &quantProduto); 
			if(quantProduto<1){
				printf("Quantidade Inv�lida");
				verificaQuantidade = 0;
			}
			else{
				verificaQuantidade = 1;
			}
		}while(verificaQuantidade != 1);
		
		do{
			
			printf("\nData de compra: (dia mes ano) ");
			scanf("%d%d%d", &dia, &mes, &ano);
			if(dia>31 || mes<1 || mes>12 || ano>2022 || ano<2020){
				printf("Data inv�lida");
				verificaData = 0;
			}
			else{
				verificaData = 1;
			}
		}while(verificaData != 1);
		
		printf("\nValor da compra: ");
		scanf("%f", &precoCompra);
		
		printf("\nPre�o do produto (UN): ");
		scanf("%f", &precoProduto);
		
		
		fflush(stdin);
		do{

				printf("\nProduto possui desconto? ");
				scanf("%c",&desconto);
				opcaoInvalida = 0;
		
			
			switch (desconto){
				case 's':
				case 'S':{
					
					printf("\nQuanto de desconto? ");
					scanf("%f", &precoDesconto);
					
					precoVenda = precoProduto - precoDesconto;
					
					printf("\nR$%.2f � o valor final do produto: %s", precoVenda, nomeProduto);
				
				break;
				
				}
						case 'n':
						case 'N':{
					precoDesconto = 0;
					precoVenda = precoProduto - precoDesconto;
					printf("\nR$%.2f � o valor final do produto: %s ", precoProduto, nomeProduto);
		
				break;
				
				}
				default:{
					
					printf("\nOp��o inv�lida!\n\n");
					opcaoInvalida = 1;
					break;		
				}
			
			}
		} while (opcaoInvalida);
		
		
		//confirma��o dos dados


		srand(time(NULL));
		printf("\n\n************");
		printf("\n\nO c�digo do produto �: %d", rand() % 10000);
		printf("\nNome: %s", nomeProduto);
		printf("\nMarca: %s", marcaProduto);
		printf("\nQuantidade: %d", quantProduto);
		printf("\nData aquisi��o: %d/%d/%d", dia, mes, ano);
		printf("\nPre�o da compra (UN): R$%.2f", precoCompra);
		printf("\nPre�o Bruto (UN): R$%.2f", precoProduto);
		printf("\nDesconto (UN): R$%.2f", precoDesconto);
		printf("\nPre�o Final (UN): R$%.2f", precoVenda);
		printf("\n\n************");
		
		

		
	return 0;	
}
