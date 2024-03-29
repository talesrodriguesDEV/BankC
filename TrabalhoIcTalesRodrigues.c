#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>

int ContClientes = 0;
int ContContas = 0;
int ContTransacoes = 0;
int NumContas[101] = {0};
int NumTransacoes[201] = {0};

struct conta{
	long int agencia;
	long int NumConta;
	float saldo;		
};

struct conta contas[201];

struct transacao{
	char tipo;
	float valor;
	char data[10];	
	char descricao[100];
	struct conta contas[1];		
}; 

struct transacao transacoes[1001];

struct cliente{
	long int codigo;
	char nome[50];
	long int CPF;
	long int CNPJ;
	long int telefone;
	char endereco[50];
	struct conta contas[2];	
	struct transacao transacoes[10];	
};

struct cliente clientes[101];

void AdcionarClientes(){
	
	system("cls");		
	ContClientes++;			
	
	printf("Insira os dados do novo cliente.\n");
	printf("C�digo: ");	
	fflush(stdin);
	scanf("%d", &clientes[ContClientes].codigo);
		
	printf("Nome: ");								
	fflush(stdin);
	scanf("%[^\n]s", clientes[ContClientes].nome);								
			
	char pessoa;
	printf("Pessoa F�sica ou Jur�dica ?\n");
	printf("F - Pessoa F�sica.\n");
	printf("J - Pessoa Jur�dica.\n");	
	person:
	fflush(stdin);
	scanf("%c", &pessoa);
	
	switch(pessoa){
		case 'F':
		case 'f':
			printf("Digite o seu CPF: ");
			fflush(stdin);
			scanf("%d", &clientes[ContClientes].CPF);
		break;
		
		case 'J':
		case 'j':
			printf("Digite o seu CNPJ: ");
			fflush(stdin);
			scanf("%d", &clientes[ContClientes].CNPJ);	
		break;
		
		default:						
			printf("Por favor, digite um comando v�lido.\n");
			system("pause");																				
			goto person;
		
	}
		
	printf("Telefone: ");
	fflush(stdin);
	scanf("%d", &clientes[ContClientes].telefone);
		
	printf("Endere�o: ");								
	fflush(stdin);
	scanf("%[^\n]s", clientes[ContClientes].endereco);	
								
} 

void PrintNotas50(){
	printf("\nVoc� receber�:\n");
	printf("5 notas de 2 reais,\n");
	printf("2 notas de 5 reais,\n");
	printf("1 nota de 10 reais e\n");
	printf("1 nota de 20 reais.\n\n");
}

void PrintNotas100(){
	printf("\nVoc� receber�:\n");
	printf("5 notas de 2 reais.\n");
	printf("2 notas de 5 reais.\n");
	printf("1 nota de 10 reais.\n");
	printf("1 nota de 20 reais.\n");
	printf("1 nota de 50 reais.\n\n");
}

void PrintNotas200(){
	printf("\nVoc� receber�:\n");
	printf("5 notas de 2 reais.\n");
	printf("2 notas de 5 reais.\n");
	printf("1 nota de 10 reais.\n");
	printf("1 nota de 20 reais.\n");
	printf("1 nota de 50 reais.\n");
	printf("1 nota de 100 reais.\n\n");
}

void PrintNotas500(){
	printf("\nVoc� receber�:\n");
	printf("5 notas de 2 reais.\n");
	printf("2 notas de 5 reais.\n");
	printf("1 nota de 10 reais.\n");
	printf("1 nota de 20 reais.\n");
	printf("1 nota de 50 reais.\n");
	printf("2 notas de 100 reais.\n");
	printf("1 nota de 200 reais.\n\n");
}

int main(void) {
	
	//FORMATA��O	
	setlocale(LC_ALL, "Portuguese");	
	system("color F9");
	
	//DATA
	time_t rawtime;
	struct tm *timeinfo;		
	time(&rawtime);
	timeinfo = localtime(&rawtime);
		
	//PONTEIROS
	FILE *ArquivoClientes;
	FILE *ArquivoContas;
	FILE *ArquivoTransacoes;
		
	//MENU PRINCIPAL
	MenuPrincipal:
	printf("=============== Bem vindo! =================\n");
	printf("Digite um comando para prosseguir:\n");
	printf("C - Gerenciar Clientes\n");
	printf("T - Gerenciar Contas\n");
	printf("S - Sair\n");		
	
	char comando;
	fflush(stdin);
	comando = getc(stdin);	
	
	switch(comando){
	
		//GEST�O DE CLIENTES
		case 'C':
		case 'c':	
			MenuClientes:
			system("cls");
			printf("============ Gerenciar Clientes ============\n");
			printf("Digite um comando para prosseguir:\n");
			printf("C - Cadastrar um cliente\n");
			printf("L - Listar todos os clientes cadastrados\n");
			printf("B - Buscar cliente j� cadastrado\n");
			printf("A - Atualizar um cliente cadastrado\n");
			printf("E - Excluir um cliente cadastrado\n");
			printf("S - Sair\n");		
					
						char comando2;
						fflush(stdin);
						comando2 = getc(stdin);	
						
						switch(comando2){
							
							//CADASTRAR CLIENTE				
							case 'C':
							case 'c':					
								system("cls");									
								AdcionarClientes();								
								ArquivoClientes = fopen("Clientes.txt", "a");																
								fprintf(ArquivoClientes, "C�digo: %d\n", clientes[ContClientes].codigo);
								fprintf(ArquivoClientes, "Nome: %s\n", clientes[ContClientes].nome);
								if(clientes[ContClientes].CNPJ == 0){								
									fprintf(ArquivoClientes, "CPF: %d\n", clientes[ContClientes].CPF);
								}else{
									fprintf(ArquivoClientes, "CNPJ: %d\n", clientes[ContClientes].CNPJ);
								}								
								fprintf(ArquivoClientes, "Telefone: %d\n", clientes[ContClientes].telefone);
								fprintf(ArquivoClientes, "Endere�o: %s\n\n", clientes[ContClientes].endereco);								 																								
								fclose(ArquivoClientes);								
								system("cls");
								printf("Dados salvos com sucesso.\n");
								system("pause");
								goto MenuClientes;																														
							break;		
							
							//LISTAR CLIENTES CADASTRADOS
							case 'L':
							case 'l':	
								system("cls");
								if(ContClientes == 0){
									printf("Nenhum cliente cadastrado.\n");
									system("pause");
									system("cls");
									goto MenuClientes;
								}
								else{																
									int i = 1;									
									for(i = 1; i <= ContClientes; i++){																													
										printf("C�digo: %d\n", clientes[i].codigo);
										printf("Nome: %s\n", clientes[i].nome);
										if(clientes[i].CNPJ == 0){
											printf("CPF: %d\n", clientes[i].CPF);
										} else{
											printf("CNPJ: %d\n", clientes[i].CNPJ);
											}																			
										printf("Telefone: %d\n", clientes[i].telefone);
										printf("Endere�o: %s\n", clientes[i].endereco);	
										printf("\n");											
									}																								
									system("pause"); 
									system("cls");
									goto MenuClientes;								
								}															
							break;
		
							//BUSCAR CLIENTE
							case 'B':
							case 'b':	
								BuscaClientes:
								system("cls");								
								printf("Deseja buscar atrav�s de c�digo, nome ou CPF/CNPJ ?\n");
								printf("C - C�digo\n");
								printf("N - Nome\n");
								printf("F - CPF\n");
								printf("J - CNPJ\n");								
								char comando2a;
								int codbusca;
								char codbusca2[50];
								int j = 1;
								fflush(stdin);
								scanf("%c", &comando2a);
								switch(comando2a){
									case 'C':
									case 'c':																														
										printf("Digite o c�digo do cliente procurado: ");
										fflush(stdin);
										scanf("%d", &codbusca);
										for(j = 1; j <= ContClientes; j++){	
											if(codbusca == clientes[j].codigo && codbusca != 0){																																													
												printf("C�digo: %d\n", clientes[j].codigo);
												printf("Nome: %s\n", clientes[j].nome);
												if(clientes[j].CNPJ == 0){
													printf("CPF: %d\n", clientes[j].CPF);
												} else{
													printf("CNPJ: %d\n", clientes[j].CNPJ);
													}																			
												printf("Telefone: %d\n", clientes[j].telefone);
												printf("Endere�o: %s\n", clientes[j].endereco);	
												printf("\n");
												system("pause");
												system("cls");
												goto MenuClientes;
											}												
										} 
										system("cls");
										printf("Cliente n�o encontrado.\n");
										system("pause");
										system("cls");
										goto MenuClientes;												
																														
									break;
									
									case 'N':
									case 'n':										
										printf("Digite o Nome do cliente procurado: ");
										fflush(stdin);
										scanf("%[^\n]s", codbusca2);
										for(j = 1; j <= ContClientes; j++){
											if(strncmp(codbusca2, clientes[j].nome, 50) == 0){																																												
												printf("C�digo: %d\n", clientes[j].codigo);
												printf("Nome: %s\n", clientes[j].nome);
												if(clientes[j].CNPJ == 0){
													printf("CPF: %d\n", clientes[j].CPF);
												} else{
													printf("CNPJ: %d\n", clientes[j].CNPJ);
												}																			
												printf("Telefone: %d\n", clientes[j].telefone);
												printf("Endere�o: %s\n", clientes[j].endereco);	
												printf("\n");
												system("pause");
												system("cls");
												goto MenuClientes;
											} 											
										} 
											system("cls");
											printf("Cliente n�o encontrado.\n");
											system("pause");
											system("cls");
											goto MenuClientes;												
																														
									break;
																											
									case 'F':
									case 'f':
										printf("Digite o CPF do cliente procurado: ");
										fflush(stdin);
										scanf("%d", &codbusca);											
										for(j = 1; j <= ContClientes; j++){	
											if(codbusca == clientes[j].CPF && codbusca != 0){																																	
												printf("C�digo: %d\n", clientes[j].codigo);
												printf("Nome: %s\n", clientes[j].nome);
												if(clientes[j].CNPJ == 0){
													printf("CPF: %d\n", clientes[j].CPF);
												} else{
													printf("CNPJ: %d\n", clientes[j].CNPJ);
												}																			
												printf("Telefone: %d\n", clientes[j].telefone);
												printf("Endere�o: %s\n", clientes[j].endereco);	
												printf("\n");
												system("pause");
												system("cls");
												goto MenuClientes;
											} 											
										} 
										system("cls");
										printf("Cliente n�o encontrado.\n");
										system("pause");
										system("cls");
										goto MenuClientes;												
																														
									break;
									
									case 'J':
									case 'j':
										printf("Digite o CNPJ do cliente procurado: ");
										fflush(stdin);
										scanf("%d", &codbusca);											
										for(j = 1; j <= ContClientes; j++){	
											if(codbusca == clientes[j].CNPJ && codbusca != 0){																																	
												printf("C�digo: %d\n", clientes[j].codigo);
											printf("Nome: %s\n", clientes[j].nome);
											if(clientes[j].CNPJ == 0){
												printf("CPF: %d\n", clientes[j].CPF);
											} else{
												printf("CNPJ: %d\n", clientes[j].CNPJ);
											}																			
											printf("Telefone: %d\n", clientes[j].telefone);
											printf("Endere�o: %s\n", clientes[j].endereco);	
											printf("\n");
											system("pause");
											system("cls");
											goto MenuClientes;
											} 											
										} 
										system("cls");
										printf("Cliente n�o encontrado.\n");
										system("pause");
										system("cls");
										goto MenuClientes;																																										
									break;	
																									
									default:								
										system("cls");
										printf("Por favor, digite um comando v�lido.\n");
										system("pause");														
										system("cls");
										goto BuscaClientes;									
								}																
							break;
		
							//ATUALIZAR CLIENTE
							case 'A':
							case 'a':	
								AtualizarCliente:
								system("cls");								
								printf("Digite o c�digo o CPF ou o CNPJ do cliente: ");										
								int codbusca3;								
								int k = 1;								
								fflush(stdin);
								scanf("%d", &codbusca3);
								for(k = 1; k <= ContClientes; k++){	
									if((codbusca3 == clientes[k].codigo && codbusca3 != 0) ||
									(codbusca3 == clientes[k].CPF && codbusca3 != 0) ||
									(codbusca3 == clientes[k].CNPJ && codbusca3 != 0)){																						
										system("cls");
										int novocodigo;
										printf("Digite o novo c�digo: ");
										fflush(stdin);
										scanf("%d", &novocodigo);
										clientes[k].codigo = novocodigo;
										char novonome[50];
										printf("Digite o novo nome: ");
										fflush(stdin);
										scanf("%[^\n]s", novonome);
										strcpy(clientes[k].nome, novonome);
										if(clientes[k].CPF == 0){
											long int novoCNPJ;
											printf("Digite o novo CNPJ: ");
											fflush(stdin);
											scanf("%d", &novoCNPJ);
											clientes[k].CNPJ = novoCNPJ;
										} else{												
											long int novoCPF;
											printf("Digite o novo CPF: ");
											fflush(stdin);
											scanf("%d", &novoCPF);
											clientes[k].CPF = novoCPF;													
											}
										long int novoTEL;
										printf("Digite o novo telefone: ");
										fflush(stdin);
										scanf("%d", &novoTEL);
										clientes[k].telefone = novoTEL;	
										char novoEND[50];
										printf("Digite o novo endere�o: ");
										fflush(stdin);
										scanf("%[^\n]s", novoEND);
										strcpy(clientes[k].endereco, novoEND);
										system("cls");
										printf("Dados do cliente atualizados com sucesso.\n");
										system("pause");
										system("cls");
										goto MenuClientes;																									
									}																					
								} 
								system("cls");
								printf("Cliente n�o encontrado.\n");
								system("pause");
								system("cls");
								goto MenuClientes;												
																																							
							break;
				
							//EXCLUIR CLIENTE
							case 'E':
							case 'e':	
								ExcluirClientes:
								system("cls");								
								printf("Digite o c�digo ou o CPF/CNPJ do cliente: ");																								
								int codbusca5;								
								int l = 1;																																																							
								fflush(stdin);
								scanf("%d", &codbusca5);
								for(l = 1; l <= ContClientes; l++){	
									if((codbusca5 == clientes[l].codigo && codbusca5 != 0) ||
									(codbusca5 == clientes[l].CPF && codbusca5 != 0) ||
									(codbusca5 == clientes[l].CNPJ && codbusca5 != 0)){																					
										system("cls");
										printf("C�digo: %d\n", clientes[l].codigo);
										printf("Nome: %s\n", clientes[l].nome);
										if(clientes[l].CNPJ == 0){
											printf("CPF: %d\n", clientes[l].CPF);
										} else{
											printf("CNPJ: %d\n", clientes[l].CNPJ);
											}																			
										printf("Telefone: %d\n", clientes[l].telefone);
										printf("Endere�o: %s\n", clientes[l].endereco);	
										printf("\n");
										ExcluirClientes2:
										printf("Deseja realmente excluir os dados acima ?\n");
										printf("S - Sim\n");
										printf("N - N�o\n");
										char ConfExc;												
										fflush(stdin);
										scanf("%c", &ConfExc);
										switch(ConfExc){
											case 'S':
											case 's':
												for(l; l <= ContClientes; l++){
													clientes[l].codigo = clientes[l + 1].codigo;
													strcpy(clientes[l].nome, clientes[l + 1].nome);															
													clientes[l].CPF = clientes[l + 1].CPF;															
													clientes[l].CNPJ = clientes[l + 1].CNPJ;																
													clientes[l].telefone = clientes[l + 1].telefone;
													strcpy(clientes[l].endereco, clientes[l + 1].endereco);
												}
												ContClientes-=1;
												system("cls");
												printf("Dados exclu�dos com sucesso.\n");
												system("pause");
												system("cls");
												goto MenuClientes;	
											break;
													
											case 'N':
											case 'n':
												system("cls");
												goto ExcluirClientes;	
											break;
													
											default:
												system("cls");
												printf("Por favor, digite um comando v�lido.\n");
												system("pause");														
												system("cls");
												goto ExcluirClientes2;														
										}												
									}												
								} 
								system("cls");
								printf("Cliente n�o encontrado.\n");
								system("pause");
								system("cls");
								goto MenuClientes;																										
							break;
						
							//SAIR
							case 'S':
							case 's':	
								system("cls");	
								goto MenuPrincipal;
							break;
				
							//ERRO
							default:								
								system("cls");
								printf("Por favor, digite um comando v�lido.\n");
								system("pause");														
								system("cls");
								goto MenuClientes;
						}
		break;				
	
		//GEST�O DE CONTAS
		case 'T':
		case 't':	
			MenuContas:
			system("cls");
			printf("Digite um comando para prosseguir:\n");
			printf("C - Cadastrar uma conta para um cliente.\n");
			printf("R - Listagem de todas as contas cadastradas.\n");			
			printf("L - Listar todas as contas de um cliente.\n");
			printf("W - Realizar um saque em uma conta.\n");
			printf("D - Realizar um dep�sito em uma conta.\n");
			printf("T - Realizar transfer�ncia entre contas.\n");
			printf("E - Exibir extrato de uma conta.\n");
			printf("S - Sair\n");						
															
						char comando3;
						fflush(stdin);
						comando3 = getc(stdin);	
						
						switch(comando3){
							//CADASTRAR UMA CONTA
							case 'C':
							case 'c':																	
								system("cls");											
								printf("Digite o c�digo ou o CPF/CNPJ do cliente: ");
								int CodConta;
								fflush(stdin);
								scanf("%d", &CodConta);	
								int m = 1;
								int v = 1;									
								for(m = 1; m <= ContClientes; m++){
									if(CodConta == clientes[m].codigo || CodConta == clientes[m].CPF
									|| CodConta == clientes[m].CNPJ){																				
										ContContas++;
										NumContas[m]++;			
										switch(NumContas[m]){			
											case 1:
												printf("Digite a ag�ncia: ");				
												fflush(stdin);
												scanf("%d", &clientes[m].contas[m].agencia);			
												printf("Digite o n�mero da conta: ");
												fflush(stdin);
												scanf("%d", &clientes[m].contas[m].NumConta);			
												clientes[m].contas[m].saldo = 0;
												ArquivoContas = fopen("Contas.txt", "a");
												fprintf(ArquivoContas, "Conta %d\n", ContContas);
												fprintf(ArquivoContas, "Cliente: %s\n", clientes[m].nome);
												fprintf(ArquivoContas, "C�digo: %d\n", clientes[m].codigo);										
												fprintf(ArquivoContas, "Ag�ncia: %d\n", clientes[m].contas[m].agencia);
												fprintf(ArquivoContas, "N�mero: %d\n", clientes[m].contas[m].NumConta);
												fprintf(ArquivoContas, "Saldo: %d\n\n", clientes[m].contas[m].saldo);
												fclose(ArquivoContas);			
											break;
				
											case 2:
												printf("Digite a ag�ncia: ");
												fflush(stdin);
												scanf("%d", &clientes[m].contas[m + 100].agencia);			
												printf("Digite o n�mero da conta: ");
												fflush(stdin);
												scanf("%d", &clientes[m].contas[m + 100].NumConta);			
												clientes[m].contas[m + 100].saldo = 0;	
												ArquivoContas = fopen("Contas.txt", "a");
												fprintf(ArquivoContas, "Conta %d\n", ContContas);
												fprintf(ArquivoContas, "Cliente: %s\n", clientes[m].nome);
												fprintf(ArquivoContas, "C�digo: %d\n", clientes[m].codigo);										
												fprintf(ArquivoContas, "Ag�ncia: %d\n", clientes[m].contas[100 + m].agencia);
												fprintf(ArquivoContas, "N�mero: %d\n", clientes[m].contas[100 + m].NumConta);
												fprintf(ArquivoContas, "Saldo: %d\n\n", clientes[m].contas[100 + m].saldo);	
												fclose(ArquivoContas);			
											break;
										}										
										system("cls");
										printf("Conta cadastrada com sucesso.\n");
										system("pause");
										system("cls");
										goto MenuContas;																			
									} 
								}																
								system("cls");						
								printf("Cliente n�o encontrado.\n");
								system("pause");
								system("cls");
								goto MenuContas;																																								
							break;
							
							//LISTAR CONTAS CADASTRADAS
							case 'R':
							case 'r':	
								system("cls");
								int n = 1;
								if(ContContas == 0){									
									system("cls");
									printf("Nenhuma conta cadastrada.\n");
									system("pause");
									system("cls");
									goto MenuContas;								
								} else {									
									for(n = 1; n <= ContClientes; n++){
										if(clientes[n].contas[n].agencia != 0){									
											printf("Cliente: %s\n", clientes[n].nome);
											printf("C�digo: %d\n", clientes[n].codigo);
											if(clientes[n].contas[n + 100].agencia != 0){																																								
												printf("Conta 1\n");
												printf("Ag�ncia: %d\n", clientes[n].contas[n].agencia);
												printf("N�mero: %d\n", clientes[n].contas[n].NumConta);
												printf("Saldo: %.2f\n", clientes[n].contas[n].saldo);
												printf("Conta 2\n");
												printf("Ag�ncia: %d\n", clientes[n].contas[n + 100].agencia);
												printf("N�mero: %d\n", clientes[n].contas[n + 100].NumConta);
												printf("Saldo: %.2f\n", clientes[n].contas[n + 100].saldo);																																									
											} else{
												printf("Conta 1\n");
												printf("Ag�ncia: %d\n", clientes[n].contas[n].agencia);
												printf("N�mero: %d\n", clientes[n].contas[n].NumConta);
												printf("Saldo: %.2f\n", clientes[n].contas[n].saldo);
												}																							
											printf("\n");																					
										}
									}
									system("pause");
									system("cls");
									goto MenuContas;
								}								
							break;
														
							//LISTAR CONTAS DE UM CLIENTE
							case 'L':
							case 'l':								
								system("cls");											
								printf("Digite o c�digo ou o CPF/CNPJ do cliente: ");
								int CodConta2;
								int o = 1;
								fflush(stdin);
								scanf("%d", &CodConta2);
								for(o = 1; o <= ContClientes; o++){
									if(NumContas[o] != 0){
										if(CodConta2 == clientes[o].codigo || CodConta2 == clientes[o].CPF
										|| CodConta2 == clientes[o].CNPJ){
											system("cls");
											printf("Cliente: %s\n", clientes[o].nome);
											switch(NumContas[o]){
												case 1:
													printf("\nConta 1\n");
													printf("Ag�ncia: %d\n", clientes[o].contas[o].agencia);
													printf("N�mero: %d\n", clientes[o].contas[o].NumConta);
													printf("Saldo: %.2f\n", clientes[o].contas[o].saldo);
													system("pause");
													system("cls");
													goto MenuContas;
												break;
												
												case 2:
													printf("\nConta 1\n");
													printf("Ag�ncia: %d\n", clientes[o].contas[o].agencia);
													printf("N�mero: %d\n", clientes[o].contas[o].NumConta);
													printf("Saldo: %d\n", clientes[o].contas[o].saldo);
													printf("\nConta 2\n");
													printf("Ag�ncia: %d\n", clientes[o].contas[100 + o].agencia);
													printf("N�mero: %d\n", clientes[o].contas[100 + o].NumConta);
													printf("Saldo: %.2f\n\n", clientes[o].contas[100 + o].saldo);
													system("pause");
													system("cls");
													goto MenuContas;
												break;	
											}
										}
									} else{
										system("cls");
										printf("Nenhuma conta cadastrada.\n");
										system("pause");
										system("cls");
										goto MenuContas;
										}
								}								
								system("cls");
								printf("Clientes n�o encontrado.\n");
								system("pause");
								system("cls");
								goto MenuContas;									
							break;
						
							//REALIZAR SAQUE
							case 'W':
							case 'w':																	
								system("cls");
								int NumAgencia;
								int NummConta;
								int p = 1;	
								int opcao;							
								printf("Digite a ag�ncia: ");
								fflush(stdin);
								scanf("%d", &NumAgencia);
								printf("Digite o n�mero da conta: ");
								fflush(stdin);
								scanf("%d", &NummConta);
								for(p = 1; p <= ContClientes; p++){
									if(NumAgencia == clientes[p].contas[p].agencia
									&& NummConta == clientes[p].contas[p].NumConta){
										printf("Cliente: %s\n", clientes[p].nome);
										printf("C�digo: %d\n", clientes[p].codigo);
										printf("Saldo: %.2f\n\n", clientes[p].contas[p].saldo);
										ValorSaque1:
										printf("Selecione o valor que deseja sacar:\n");
										printf("1 - R$ 50,00\n");
										printf("2 - R$ 100,00\n");
										printf("3 - R$ 200,00\n");
										printf("4 - R$ 500,00\n");
										fflush(stdin);
										scanf("%d", &opcao);
										switch(opcao){
											case 1:
												if(clientes[p].contas[p].saldo >= 50){												
													ContTransacoes++;
													NumTransacoes[p]++;
													printf("Forne�a uma descri��o para este saque: ");
													fflush(stdin);
													scanf("%[^\n]s", clientes[p].transacoes[NumTransacoes[p]].descricao);
													clientes[p].contas[p].saldo = clientes[p].contas[p].saldo - 50;
													clientes[p].transacoes[NumTransacoes[p]].tipo = 'D';
													strftime(clientes[p].transacoes[NumTransacoes[p]].data, 10, "%d/%m/%y", timeinfo);
													clientes[p].transacoes[NumTransacoes[p]].valor = 50;																																							
													ArquivoTransacoes = fopen("Transacoes.txt", "a");
													fprintf(ArquivoTransacoes, "Saque\n");
													fprintf(ArquivoTransacoes, "Ag�ncia: %d\n", clientes[p].contas[p].agencia);
													fprintf(ArquivoTransacoes, "N�mero: %d\n", clientes[p].contas[p].NumConta);
													fprintf(ArquivoTransacoes, "Data: %s\n", clientes[p].transacoes[NumTransacoes[p]].data);
													fprintf(ArquivoTransacoes, "Tipo: %c\n", clientes[p].transacoes[NumTransacoes[p]].tipo);													
													fprintf(ArquivoTransacoes, "Valor: %.2f\n", clientes[p].transacoes[NumTransacoes[p]].valor);
													fprintf(ArquivoTransacoes, "Descri��o: %s\n\n", clientes[p].transacoes[NumTransacoes[p]].descricao);
													fclose(ArquivoTransacoes);
													PrintNotas50();
													system("pause");
													system("cls");
													goto MenuContas;
												} else{
													system("cls");
													printf("Saldo insuficiente.\n");
													system("pause");
													system("cls");
													goto MenuContas;
													}
											break;	
											
											case 2:
												if(clientes[p].contas[p].saldo >= 100){												
													ContTransacoes++;
													NumTransacoes[p]++;
													printf("Forne�a uma descri��o para este saque: ");
													fflush(stdin);
													scanf("%[^\n]s", clientes[p].transacoes[NumTransacoes[p]].descricao);
													clientes[p].contas[p].saldo = clientes[p].contas[p].saldo - 100;
													clientes[p].transacoes[NumTransacoes[p]].tipo = 'D';
													strftime(clientes[p].transacoes[NumTransacoes[p]].data, 10, "%d/%m/%y", timeinfo);
													clientes[p].transacoes[NumTransacoes[p]].valor = 100;										
													ArquivoTransacoes = fopen("Transacoes.txt", "a");
													fprintf(ArquivoTransacoes, "Saque\n");
													fprintf(ArquivoTransacoes, "Ag�ncia: %d\n", clientes[p].contas[p].agencia);
													fprintf(ArquivoTransacoes, "N�mero: %d\n", clientes[p].contas[p].NumConta);
													fprintf(ArquivoTransacoes, "Data: %s\n", clientes[p].transacoes[NumTransacoes[p]].data);
													fprintf(ArquivoTransacoes, "Tipo: %c\n", clientes[p].transacoes[NumTransacoes[p]].tipo);													
													fprintf(ArquivoTransacoes, "Valor: %.2f\n", clientes[p].transacoes[NumTransacoes[p]].valor);
													fprintf(ArquivoTransacoes, "Descri��o: %s\n\n", clientes[p].transacoes[NumTransacoes[p]].descricao);
													fclose(ArquivoTransacoes);
													PrintNotas100();
													system("pause");
													system("cls");
													goto MenuContas;
												} else{
													system("cls");
													printf("Saldo insuficiente.\n");
													system("pause");
													system("cls");
													goto MenuContas;
													}
											break;
											
											case 3:
												if(clientes[p].contas[p].saldo >= 200){												
													ContTransacoes++;
													NumTransacoes[p]++;
													printf("Forne�a uma descri��o para este saque: ");
													fflush(stdin);
													scanf("%[^\n]s", clientes[p].transacoes[NumTransacoes[p]].descricao);
													clientes[p].contas[p].saldo = clientes[p].contas[p].saldo - 200;
													clientes[p].transacoes[NumTransacoes[p]].tipo = 'D';
													strftime(clientes[p].transacoes[NumTransacoes[p]].data, 10, "%d/%m/%y", timeinfo);
													clientes[p].transacoes[NumTransacoes[p]].valor = 200;													
													ArquivoTransacoes = fopen("Transacoes.txt", "a");
													fprintf(ArquivoTransacoes, "Saque\n");
													fprintf(ArquivoTransacoes, "Ag�ncia: %d\n", clientes[p].contas[p].agencia);
													fprintf(ArquivoTransacoes, "N�mero: %d\n", clientes[p].contas[p].NumConta);
													fprintf(ArquivoTransacoes, "Data: %s\n", clientes[p].transacoes[NumTransacoes[p]].data);
													fprintf(ArquivoTransacoes, "Tipo: %c\n", clientes[p].transacoes[NumTransacoes[p]].tipo);													
													fprintf(ArquivoTransacoes, "Valor: %.2f\n", clientes[p].transacoes[NumTransacoes[p]].valor);
													fprintf(ArquivoTransacoes, "Descri��o: %s\n\n", clientes[p].transacoes[NumTransacoes[p]].descricao);
													fclose(ArquivoTransacoes);
													PrintNotas200();
													system("pause");
													system("cls");
													goto MenuContas;
												} else{
													system("cls");
													printf("Saldo insuficiente.\n");
													system("pause");
													system("cls");
													goto MenuContas;
													}
											break;
											
											case 4:
												if(clientes[p].contas[p].saldo >= 500){												
													ContTransacoes++;
													NumTransacoes[p]++;
													printf("Forne�a uma descri��o para este saque: ");
													fflush(stdin);
													scanf("%[^\n]s", clientes[p].transacoes[NumTransacoes[p]].descricao);
													clientes[p].contas[p].saldo = clientes[p].contas[p].saldo - 500;
													clientes[p].transacoes[NumTransacoes[p]].tipo = 'D';
													strftime(clientes[p].transacoes[NumTransacoes[p]].data, 10, "%d/%m/%y", timeinfo);
													clientes[p].transacoes[NumTransacoes[p]].valor = 500;													
													ArquivoTransacoes = fopen("Transacoes.txt", "a");
													fprintf(ArquivoTransacoes, "Saque\n");
													fprintf(ArquivoTransacoes, "Ag�ncia: %d\n", clientes[p].contas[p].agencia);
													fprintf(ArquivoTransacoes, "N�mero: %d\n", clientes[p].contas[p].NumConta);
													fprintf(ArquivoTransacoes, "Data: %s\n", clientes[p].transacoes[NumTransacoes[p]].data);
													fprintf(ArquivoTransacoes, "Tipo: %c\n", clientes[p].transacoes[NumTransacoes[p]].tipo);													
													fprintf(ArquivoTransacoes, "Valor: %.2f\n", clientes[p].transacoes[NumTransacoes[p]].valor);
													fprintf(ArquivoTransacoes, "Descri��o: %s\n\n", clientes[p].transacoes[NumTransacoes[p]].descricao);
													fclose(ArquivoTransacoes);
													PrintNotas500();
													system("pause");
													system("cls");
													goto MenuContas;
												} else{
													system("cls");
													printf("Saldo insuficiente.\n");
													system("pause");
													system("cls");
													goto MenuContas;
													}
											break;
											
											default:
												system("cls");
												printf("Por favor, digite um comando v�lido.\n");
												system("pause");														
												system("cls");
												goto ValorSaque1;											
										}
											
									} 
									else{
										if(NumAgencia == clientes[p].contas[100 + p].agencia
										&& NummConta == clientes[p].contas[100 + p].NumConta){
											printf("Cliente: %s\n", clientes[p].nome);
											printf("C�digo: %d\n", clientes[p].codigo);
											printf("Saldo: %.2f\n\n", clientes[p].contas[100 + p].saldo);
											ValorSaque2:
											printf("Selecione o valor que deseja sacar:\n");
											printf("1 - R$ 50,00\n");
											printf("2 - R$ 100,00\n");
											printf("3 - R$ 200,00\n");
											printf("4 - R$ 500,00\n");
											fflush(stdin);
											scanf("%d", &opcao);
											switch(opcao){
												case 1:
													if(clientes[p].contas[100 + p].saldo >= 50){												
														ContTransacoes++;
														NumTransacoes[100 + p]++;
														printf("Forne�a uma descri��o para este saque: ");
														fflush(stdin);
														scanf("%[^\n]s", clientes[100 + p].transacoes[NumTransacoes[100 + p]].descricao);
														clientes[p].contas[100 + p].saldo = clientes[p].contas[100 + p].saldo - 50;
														clientes[100 + p].transacoes[NumTransacoes[100 + p]].tipo = 'D';
														strftime(clientes[100 + p].transacoes[NumTransacoes[100 + p]].data, 10, "%d/%m/%y", timeinfo);
														clientes[100 + p].transacoes[NumTransacoes[100 + p]].valor = 50;
														ArquivoTransacoes = fopen("Transacoes.txt", "a");
														fprintf(ArquivoTransacoes, "Saque\n");
														fprintf(ArquivoTransacoes, "Ag�ncia: %d\n", clientes[p].contas[100 + p].agencia);
														fprintf(ArquivoTransacoes, "N�mero: %d\n", clientes[p].contas[100 + p].NumConta);
														fprintf(ArquivoTransacoes, "Data: %s\n", clientes[100 + p].transacoes[NumTransacoes[p]].data);
														fprintf(ArquivoTransacoes, "Tipo: %c\n", clientes[100 + p].transacoes[NumTransacoes[p]].tipo);													
														fprintf(ArquivoTransacoes, "Valor: %.2f\n", clientes[100 + p].transacoes[NumTransacoes[p]].valor);
														fprintf(ArquivoTransacoes, "Descri��o: %s\n\n", clientes[100 + p].transacoes[NumTransacoes[p]].descricao);
														fclose(ArquivoTransacoes);
														PrintNotas50();
														system("pause");
														system("cls");
														goto MenuContas;
													} else{
														system("cls");
														printf("Saldo insuficiente.\n");
														system("pause");
														system("cls");
														goto MenuContas;
														}
												break;	
											
												case 2:
													if(clientes[p].contas[100 + p].saldo >= 100){												
														ContTransacoes++;
														NumTransacoes[100 + p]++;
														printf("Forne�a uma descri��o para este saque: ");
														fflush(stdin);
														scanf("%[^\n]s", clientes[100 + p].transacoes[NumTransacoes[100 + p]].descricao);
														clientes[p].contas[100 + p].saldo = clientes[p].contas[100 + p].saldo - 100;
														clientes[100 + p].transacoes[NumTransacoes[100 + p]].tipo = 'D';
														strftime(clientes[100 + p].transacoes[NumTransacoes[100 + p]].data, 10, "%d/%m/%y", timeinfo);
														clientes[100 + p].transacoes[NumTransacoes[100 + p]].valor = 100;
														ArquivoTransacoes = fopen("Transacoes.txt", "a");
														fprintf(ArquivoTransacoes, "Saque\n");
														fprintf(ArquivoTransacoes, "Ag�ncia: %d\n", clientes[p].contas[100 + p].agencia);
														fprintf(ArquivoTransacoes, "N�mero: %d\n", clientes[p].contas[100 + p].NumConta);
														fprintf(ArquivoTransacoes, "Data: %s\n", clientes[100 + p].transacoes[NumTransacoes[p]].data);
														fprintf(ArquivoTransacoes, "Tipo: %c\n", clientes[100 + p].transacoes[NumTransacoes[p]].tipo);													
														fprintf(ArquivoTransacoes, "Valor: %.2f\n", clientes[100 + p].transacoes[NumTransacoes[p]].valor);
														fprintf(ArquivoTransacoes, "Descri��o: %s\n\n", clientes[100 + p].transacoes[NumTransacoes[p]].descricao);
														fclose(ArquivoTransacoes);
														PrintNotas100();
														system("pause");
														system("cls");
														goto MenuContas;
													} else{
														system("cls");
														printf("Saldo insuficiente.\n");
														system("pause");
														system("cls");
														goto MenuContas;
														}
												break;
											
												case 3:
													if(clientes[p].contas[100 + p].saldo >= 200){												
														ContTransacoes++;
														NumTransacoes[100 + p]++;
														printf("Forne�a uma descri��o para este saque: ");
														fflush(stdin);
														scanf("%[^\n]s", clientes[100 + p].transacoes[NumTransacoes[100 + p]].descricao);
														clientes[p].contas[100 + p].saldo = clientes[p].contas[100 + p].saldo - 200;
														clientes[100 + p].transacoes[NumTransacoes[100 + p]].tipo = 'D';
														strftime(clientes[100 + p].transacoes[NumTransacoes[100 + p]].data, 10, "%d/%m/%y", timeinfo);
														clientes[100 + p].transacoes[NumTransacoes[100 + p]].valor = 200;
														ArquivoTransacoes = fopen("Transacoes.txt", "a");
														fprintf(ArquivoTransacoes, "Saque\n");
														fprintf(ArquivoTransacoes, "Ag�ncia: %d\n", clientes[p].contas[100 + p].agencia);
														fprintf(ArquivoTransacoes, "N�mero: %d\n", clientes[p].contas[100 + p].NumConta);
														fprintf(ArquivoTransacoes, "Data: %s\n", clientes[100 + p].transacoes[NumTransacoes[p]].data);
														fprintf(ArquivoTransacoes, "Tipo: %c\n", clientes[100 + p].transacoes[NumTransacoes[p]].tipo);													
														fprintf(ArquivoTransacoes, "Valor: %.2f\n", clientes[100 + p].transacoes[NumTransacoes[p]].valor);
														fprintf(ArquivoTransacoes, "Descri��o: %s\n\n", clientes[100 + p].transacoes[NumTransacoes[p]].descricao);
														fclose(ArquivoTransacoes);
														PrintNotas200();
														system("pause");
														system("cls");
														goto MenuContas;
													} else{
														system("cls");
														printf("Saldo insuficiente.\n");
														system("pause");
														system("cls");
														goto MenuContas;
														}
												break;
											
												case 4:
													if(clientes[p].contas[100 + p].saldo >= 500){												
														ContTransacoes++;
														NumTransacoes[100 + p]++;
														printf("Forne�a uma descri��o para este saque: ");
														fflush(stdin);
														scanf("%[^\n]s", clientes[100 + p].transacoes[NumTransacoes[100 + p]].descricao);
														clientes[p].contas[100 + p].saldo = clientes[p].contas[100 + p].saldo - 500;
														clientes[100 + p].transacoes[NumTransacoes[100 + p]].tipo = 'D';
														strftime(clientes[100 + p].transacoes[NumTransacoes[100 + p]].data, 10, "%d/%m/%y", timeinfo);
														clientes[100 + p].transacoes[NumTransacoes[100 + p]].valor = 500;
														ArquivoTransacoes = fopen("Transacoes.txt", "a");
														fprintf(ArquivoTransacoes, "Saque\n");
														fprintf(ArquivoTransacoes, "Ag�ncia: %d\n", clientes[p].contas[100 + p].agencia);
														fprintf(ArquivoTransacoes, "N�mero: %d\n", clientes[p].contas[100 + p].NumConta);
														fprintf(ArquivoTransacoes, "Data: %s\n", clientes[100 + p].transacoes[NumTransacoes[p]].data);
														fprintf(ArquivoTransacoes, "Tipo: %c\n", clientes[100 + p].transacoes[NumTransacoes[p]].tipo);													
														fprintf(ArquivoTransacoes, "Valor: %.2f\n", clientes[100 + p].transacoes[NumTransacoes[p]].valor);
														fprintf(ArquivoTransacoes, "Descri��o: %s\n\n", clientes[100 + p].transacoes[NumTransacoes[p]].descricao);
														fclose(ArquivoTransacoes);
														PrintNotas500();
														system("pause");
														system("cls");
														goto MenuContas;
													} else{
														system("cls");
														printf("Saldo insuficiente.\n");
														system("pause");
														system("cls");
														goto MenuContas;
														}
												break;
											
												default:
													system("cls");
													printf("Por favor, digite um comando v�lido.\n");
													system("pause");														
													system("cls");
													goto ValorSaque2;	
											}	
									   }
									  }
								}
								system("cls");
								printf("Conta n�o encontrada.\n");
								system("pause");
								system("cls");
								goto MenuContas;																		
								break;
			
							//REALIZAR DEP�SITO
							case 'D':
							case 'd':	
								system("cls");
								int NumAgencia2;
								int NummConta2;
								int q = 1;	
								float ValorDeposito;							
								printf("Digite a ag�ncia: ");
								fflush(stdin);
								scanf("%d", &NumAgencia2);
								printf("Digite o n�mero da conta: ");
								fflush(stdin);
								scanf("%d", &NummConta2);
								for(q = 1; q <= ContClientes; q++){
									if(NumAgencia2 == clientes[q].contas[q].agencia
									&& NummConta2 == clientes[q].contas[q].NumConta){
										ContTransacoes++;
										NumTransacoes[q]++;
										printf("Cliente: %s\n", clientes[q].nome);
										printf("C�digo: %d\n", clientes[q].codigo);
										printf("Saldo: %.2f\n\n", clientes[q].contas[q].saldo);
										printf("Informe o valor que deseja depositar: ");
										fflush(stdin);
										scanf("%f", &ValorDeposito);
										printf("Forne�a uma descri��o para este dep�sito: ");
										fflush(stdin);
										scanf("%[^\n]s", clientes[q].transacoes[NumTransacoes[q]].descricao);	
										clientes[q].contas[q].saldo = clientes[q].contas[q].saldo + ValorDeposito;
										clientes[q].transacoes[NumTransacoes[q]].tipo = 'C';
										clientes[q].transacoes[NumTransacoes[q]].valor = ValorDeposito;										
										strftime(clientes[q].transacoes[NumTransacoes[q]].data, 10, "%d/%m/%y", timeinfo);
										ArquivoTransacoes = fopen("Transacoes.txt", "a");
										fprintf(ArquivoTransacoes, "Dep�sito\n");
										fprintf(ArquivoTransacoes, "Ag�ncia: %d\n", clientes[q].contas[q].agencia);
										fprintf(ArquivoTransacoes, "N�mero: %d\n", clientes[q].contas[q].NumConta);
										fprintf(ArquivoTransacoes, "Data: %s\n", clientes[q].transacoes[NumTransacoes[q]].data);
										fprintf(ArquivoTransacoes, "Tipo: %c\n", clientes[q].transacoes[NumTransacoes[q]].tipo);													
										fprintf(ArquivoTransacoes, "Valor: %.2f\n", clientes[q].transacoes[NumTransacoes[q]].valor);
										fprintf(ArquivoTransacoes, "Descri��o: %s\n\n", clientes[q].transacoes[NumTransacoes[q]].descricao);
										fclose(ArquivoTransacoes);
										system("cls");
										printf("Dep�sito efetuado com sucesso.\n");
										system("pause");
										system("cls");
										goto MenuContas;								
									} 
									else{
										if(NumAgencia2 == clientes[q].contas[100 + q].agencia
										&& NummConta2 == clientes[q].contas[100 + q].NumConta){
											ContTransacoes++;
											NumTransacoes[100 + q]++;
											printf("Cliente: %s\n", clientes[q].nome);
											printf("C�digo: %d\n", clientes[q].codigo);
											printf("Saldo: %.2f\n\n", clientes[q].contas[100 + q].saldo);
											printf("Informe o valor que deseja depositar: ");
											fflush(stdin);
											scanf("%f", &ValorDeposito);
											printf("Forne�a uma descri��o para este dep�sito: ");
											fflush(stdin);
											scanf("%[^\n]s", clientes[100 + q].transacoes[NumTransacoes[100 + q]].descricao);	
											clientes[q].contas[100 + q].saldo = clientes[q].contas[100 + q].saldo + ValorDeposito;
											clientes[100 + q].transacoes[NumTransacoes[100 + q]].tipo = 'C';
											clientes[100 + q].transacoes[NumTransacoes[100 + q]].valor = ValorDeposito;										
											strftime(clientes[100 + q].transacoes[NumTransacoes[100 + q]].data, 10, "%d/%m/%y", timeinfo);
											ArquivoTransacoes = fopen("Transacoes.txt", "a");
											fprintf(ArquivoTransacoes, "Dep�sito\n");
											fprintf(ArquivoTransacoes, "Ag�ncia: %d\n", clientes[q].contas[100 + q].agencia);
											fprintf(ArquivoTransacoes, "N�mero: %d\n", clientes[q].contas[100 + q].NumConta);
											fprintf(ArquivoTransacoes, "Data: %s\n", clientes[100 + q].transacoes[NumTransacoes[100 + q]].data);
											fprintf(ArquivoTransacoes, "Tipo: %c\n", clientes[100 + q].transacoes[NumTransacoes[100 + q]].tipo);													
											fprintf(ArquivoTransacoes, "Valor: %.2f\n", clientes[100 + q].transacoes[NumTransacoes[100 + q]].valor);
											fprintf(ArquivoTransacoes, "Descri��o: %s\n\n", clientes[100 + q].transacoes[NumTransacoes[100 + q]].descricao);
											fclose(ArquivoTransacoes);
											system("cls");
											printf("Dep�sito efetuado com sucesso.\n");
											system("pause");
											system("cls");
											goto MenuContas;								
										}
										}																			
								}
								system("cls");
								printf("Conta n�o encontrada.\n");
								system("pause");
								system("cls");
								goto MenuContas;
							break;	
		
							//REALIZAR TRANSFER�NCIA
							case 'T':
							case 't':	
								system("cls");
								float ValorTransferencia;
								int NumAgenciaOrigem, NumAgenciaDestino;
								int NumContaOrigem, NumContaDestino;
								int r = 1;
								int s = 1;	
								char *pch;																														
								printf("Digite a ag�ncia da conta de origem: ");
								fflush(stdin);
								scanf("%d", &NumAgenciaOrigem);
								printf("Digite o n�mero da conta de origem: ");
								fflush(stdin);
								scanf("%d", &NumContaOrigem);																								
								for(r = 1; r <= ContClientes; r++){
									if(NumAgenciaOrigem == clientes[r].contas[r].agencia
									&& NumContaOrigem == clientes[r].contas[r].NumConta){										
										printf("Conta de origem:\n");
										printf("Cliente: %s\n", clientes[r].nome);
										printf("C�digo: %d\n", clientes[r].codigo);
										printf("Saldo: %.2f\n\n", clientes[r].contas[r].saldo);	
										goto ContaDestino;									
									}
									else{
										if(NumAgenciaOrigem == clientes[r].contas[100 + r].agencia
										&& NumContaOrigem == clientes[r].contas[100 + r].NumConta){												
											printf("Conta de origem:\n");
											printf("Cliente: %s\n", clientes[r].nome);
											printf("C�digo: %d\n", clientes[r].codigo);
											printf("Saldo: %.2f\n\n", clientes[r].contas[100 + r].saldo);
											goto ContaDestino;
										}
									}
								}
								system("cls");
								printf("Conta n�o encontrada.\n");
								system("pause");
								system("cls");
								goto MenuContas;																
								ContaDestino:
								printf("Digite a ag�ncia da conta destino: ");
								fflush(stdin);
								scanf("%d", &NumAgenciaDestino);
								printf("Digite o n�mero da conta destino: ");
								fflush(stdin);
								scanf("%d", &NumContaDestino);
								for(s = 1; s <= ContClientes; s++){
									if(NumAgenciaDestino == clientes[s].contas[s].agencia
									&& NumContaDestino == clientes[s].contas[s].NumConta){										
										printf("Conta de destino:\n");
										printf("Cliente: %s\n", clientes[s].nome);
										printf("C�digo: %d\n", clientes[s].codigo);
										printf("Saldo: %.2f\n\n", clientes[s].contas[s].saldo);	
										printf("Qual valor deseja transferir ?\n");
										fflush(stdin);
										scanf("%f", &ValorTransferencia);
										if(ValorTransferencia <= clientes[r].contas[r].saldo
										|| ValorTransferencia <= clientes[r].contas[100 + r].saldo){											
											ContTransacoes++;																						
											NumTransacoes[s]++;		
											clientes[s].contas[s].saldo = clientes[s].contas[s].saldo + ValorTransferencia;																																	
											clientes[s].transacoes[NumTransacoes[s]].tipo = 'C';																						
											clientes[s].transacoes[NumTransacoes[s]].valor = ValorTransferencia;											
											strftime(clientes[s].transacoes[NumTransacoes[s]].data, 10, "%d/%m/%y", timeinfo);
											strcpy(clientes[s].transacoes[NumTransacoes[s]].descricao, "Transfer�ncia de ");											
											if(NumAgenciaOrigem == clientes[r].contas[r].agencia
											&& NumContaOrigem == clientes[r].contas[r].NumConta){
												NumTransacoes[r]++;
												clientes[r].contas[r].saldo = clientes[r].contas[r].saldo - ValorTransferencia;																																														
												clientes[r].transacoes[NumTransacoes[r]].tipo = 'D';												
												clientes[r].transacoes[NumTransacoes[r]].valor = ValorTransferencia;																						
												strftime(clientes[r].transacoes[NumTransacoes[r]].data, 10, "%d/%m/%y", timeinfo);
												strcpy(clientes[r].transacoes[NumTransacoes[r]].descricao, "Transfer�ncia para "); 												
												strcat(clientes[r].transacoes[NumTransacoes[r]].descricao, clientes[s].nome);												 												
												strcat(clientes[s].transacoes[NumTransacoes[s]].descricao, clientes[r].nome);
												ArquivoTransacoes = fopen("Transacoes.txt", "a");
												fprintf(ArquivoTransacoes, "Transfer�ncia\n");
												fprintf(ArquivoTransacoes, "Ag�ncia da conta de origem: %d\n", clientes[r].contas[r].agencia);
												fprintf(ArquivoTransacoes, "N�mero da conta de origem: %d\n", clientes[r].contas[r].NumConta);																								
											}else{
												if(NumAgenciaOrigem == clientes[r].contas[100 + r].agencia
												&& NumContaOrigem == clientes[r].contas[100 + r].NumConta){
													NumTransacoes[100 + r]++;
													clientes[r].contas[100 + r].saldo = clientes[r].contas[100 + r].saldo - ValorTransferencia;																																															
													clientes[100 + r].transacoes[NumTransacoes[100 + r]].tipo = 'D';
													clientes[100 + r].transacoes[NumTransacoes[100 + r]].valor = ValorTransferencia;																																		
													strftime(clientes[100 + r].transacoes[NumTransacoes[100 + r]].data, 10, "%d/%m/%y", timeinfo);
													strcpy(clientes[100 + r].transacoes[NumTransacoes[100 + r]].descricao, "Transfer�ncia para "); 												
													strcat(clientes[100 + r].transacoes[NumTransacoes[100 + r]].descricao, clientes[s].nome);													 												
													strcat(clientes[s].transacoes[NumTransacoes[s]].descricao, clientes[r].nome);
													ArquivoTransacoes = fopen("Transacoes.txt", "a");
													fprintf(ArquivoTransacoes, "Transa��o\n");
													fprintf(ArquivoTransacoes, "Ag�ncia da conta de origem: %d\n", clientes[r].contas[100 + r].agencia);
													fprintf(ArquivoTransacoes, "N�mero da conta de origem: %d\n", clientes[r].contas[100 + r].NumConta);															
												}
											}
											fprintf(ArquivoTransacoes, "Ag�ncia da conta destino: %d\n", clientes[s].contas[s].agencia);
											fprintf(ArquivoTransacoes, "N�mero da conta destino: %d\n", clientes[s].contas[s].NumConta);
											fprintf(ArquivoTransacoes, "Data: %s\n", clientes[s].transacoes[NumTransacoes[s]].data);
											fprintf(ArquivoTransacoes, "Valor: %.2f\n\n", clientes[s].transacoes[NumTransacoes[s]].valor);
											fclose(ArquivoTransacoes);
											system("cls");
											printf("Transfer�ncia efetuada com sucesso.\n");
											system("pause");
											system("cls");
											goto MenuContas;											
										}
										system("cls");
										printf("Saldo insuficiente.\n");
										system("pause");
										system("cls");
										goto MenuContas;																													
									}
									else{
										if(NumAgenciaDestino == clientes[s].contas[100 + s].agencia
										&& NumContaDestino == clientes[s].contas[100 + s].NumConta){												
											printf("Conta destino:\n");
											printf("Cliente: %s\n", clientes[s].nome);
											printf("C�digo: %d\n", clientes[s].codigo);
											printf("Saldo: %.2f\n\n", clientes[s].contas[100 + s].saldo);
											printf("Qual valor deseja transferir ?\n");
											fflush(stdin);
											scanf("%f", &ValorTransferencia);
											if(ValorTransferencia <= clientes[r].contas[r].saldo
											|| ValorTransferencia <= clientes[r].contas[100 + r].saldo){												
												ContTransacoes++;																								
												NumTransacoes[100 + s]++;
												clientes[s].contas[100 + s].saldo = clientes[s].contas[100 + s].saldo + ValorTransferencia;																																				
												clientes[100 + s].transacoes[NumTransacoes[100 + s]].tipo = 'C';																								
												clientes[100 + s].transacoes[NumTransacoes[100 + s]].valor = ValorTransferencia;											
												strftime(clientes[100 + s].transacoes[100 + s].data, 10, "%d/%m/%y", timeinfo);
												strcpy(clientes[100 + s].transacoes[NumTransacoes[100 + s]].descricao, "Transfer�ncia de ");
												if(NumAgenciaOrigem == clientes[r].contas[r].agencia
												&& NumContaOrigem == clientes[r].contas[r].NumConta){												
													NumTransacoes[r]++;		
													clientes[r].contas[r].saldo = clientes[r].contas[r].saldo - ValorTransferencia;																																
													clientes[r].transacoes[NumTransacoes[r]].tipo = 'D';																										
													clientes[r].transacoes[NumTransacoes[r]].valor = ValorTransferencia;																						
													strftime(clientes[r].transacoes[NumTransacoes[r]].data, 10, "%d/%m/%y", timeinfo);
													strcpy(clientes[r].transacoes[NumTransacoes[r]].descricao, "Transfer�ncia para ");
													strcat(clientes[r].transacoes[NumTransacoes[r]].descricao, clientes[s].nome);
													strcat(clientes[100 + s].transacoes[NumTransacoes[100 + s]].descricao, clientes[r].nome);
													ArquivoTransacoes = fopen("Transacoes.txt", "a");
													fprintf(ArquivoTransacoes, "Transfer�ncia\n");
													fprintf(ArquivoTransacoes, "Ag�ncia da conta de origem: %d\n", clientes[r].contas[r].agencia);
													fprintf(ArquivoTransacoes, "N�mero da conta de origem: %d\n", clientes[r].contas[r].NumConta);
												}else{
													if(NumAgenciaOrigem == clientes[r].contas[100 + r].agencia
													&& NumContaOrigem == clientes[r].contas[100 + r].NumConta){															
														NumTransacoes[100 + r]++;
														clientes[r].contas[100 + r].saldo = clientes[r].contas[100 + r].saldo - ValorTransferencia;																																				
														clientes[100 + r].transacoes[NumTransacoes[100 + r]].tipo = 'D';																												
														clientes[100 + r].transacoes[NumTransacoes[100 + r]].valor = ValorTransferencia;																						
														strftime(clientes[100 + r].transacoes[NumTransacoes[100 + r]].data, 10, "%d/%m/%y", timeinfo);
														strcpy(clientes[100 + r].transacoes[NumTransacoes[100 + r]].descricao, "Transfer�ncia para ");
														strcat(clientes[100 + r].transacoes[NumTransacoes[100 + r]].descricao, clientes[s].nome);
														strcat(clientes[100 + s].transacoes[NumTransacoes[100 + s]].descricao, clientes[r].nome);
														ArquivoTransacoes = fopen("Transacoes.txt", "a");
														fprintf(ArquivoTransacoes, "Transa��o\n");
														fprintf(ArquivoTransacoes, "Ag�ncia da conta de origem: %d\n", clientes[r].contas[100 + r].agencia);
														fprintf(ArquivoTransacoes, "N�mero da conta de origem: %d\n", clientes[r].contas[100 + r].NumConta);
													}
												}
												fprintf(ArquivoTransacoes, "Ag�ncia da conta destino: %d\n", clientes[s].contas[100 + s].agencia);
												fprintf(ArquivoTransacoes, "N�mero da conta destino: %d\n", clientes[s].contas[100 + s].NumConta);
												fprintf(ArquivoTransacoes, "Data: %s\n", clientes[100 + s].transacoes[NumTransacoes[100 + s]].data);
												fprintf(ArquivoTransacoes, "Valor: %.2f\n\n", clientes[100 + s].transacoes[NumTransacoes[100 + s]].valor);
												fclose(ArquivoTransacoes);
												system("cls");
												printf("Transfer�ncia efetuada com sucesso.\n");
												system("pause");
												system("cls");
												goto MenuContas;											
											} 
											system("cls");
											printf("Saldo insuficiente.\n");
											system("pause");
											system("cls");
											goto MenuContas;											
									 }
									}	
								}
								system("cls");
								printf("Conta n�o encontrada.\n");
								system("pause");
								system("cls");
								goto MenuContas;																																
							break;
									
							//EXIBIR EXTRATO
							case 'E':
							case 'e':	
								system("cls");
								int t = 1;
								int u;
								int ExtAgencia, ExtNumConta;
								printf("Digite a ag�ncia: ");
								fflush(stdin);
								scanf("%d", &ExtAgencia);
								printf("Digite o n�mero da conta: ");
								fflush(stdin);
								scanf("%d", &ExtNumConta);
								for(t = 1; t <= ContClientes; t++){
									if(ExtAgencia == clientes[t].contas[t].agencia && ExtNumConta == clientes[t].contas[t].NumConta){
										if(ContTransacoes == 0){
											system("cls");
											printf("N�o h� transa��es registradas.\n");
											system("pause");
											system("cls");
											goto MenuContas;
										} else{
											printf("Cliente: %s\n", clientes[t].nome);
											printf("C�digo: %d\n", clientes[t].codigo);											
											printf("Saldo: %.2f\n\n", clientes[t].contas[t].saldo);
											printf("C - Cr�dito\n");
											printf("D - D�bito\n\n");
											if(NumTransacoes[t] == 0){
												system("cls");
												printf("N�o h� transa��es registradas nessa conta.\n");																								
											}else{																						
												for(u = NumTransacoes[t]; u >= 1; u--){
													printf("Data: %s\n", clientes[t].transacoes[u].data);
													printf("Tipo: %c\n", clientes[t].transacoes[u].tipo);
													printf("Valor: %.2f\n", clientes[t].transacoes[u].valor);
													printf("Descri��o: %s\n\n", clientes[t].transacoes[u].descricao);												
												}	
											}
											system("pause");
											system("cls");
											goto MenuContas;											
										}										
									} else{
										if(ExtAgencia == clientes[t].contas[100 + t].agencia && ExtNumConta == clientes[t].contas[100 + t].NumConta){
											if(ContTransacoes == 0){
												system("cls");
												printf("N�o h� transa��es registradas.\n");
												system("pause");
												system("cls");
												goto MenuContas;
											} else{
												printf("Cliente: %s\n", clientes[t].nome);
												printf("C�digo: %d\n", clientes[t].codigo);											
												printf("Saldo: %.2f\n\n", clientes[t].contas[100 + t].saldo);
												printf("C - Cr�dito\n");
												printf("D - D�bito\n\n");
												if(NumTransacoes[100 + t] == 0){
													system("cls");
													printf("N�o h� transa��es registradas nessa conta.\n");																								
												}else{																						
													for(u = NumTransacoes[100 + t]; u >= 1; u--){
														printf("Data: %s\n", clientes[100 + t].transacoes[u].data);
														printf("Tipo: %c\n", clientes[100 + t].transacoes[u].tipo);
														printf("Valor: %.2f\n", clientes[100 + t].transacoes[u].valor);
														printf("Descri��o: %s\n\n", clientes[100 + t].transacoes[u].descricao);												
													}	
												}
												system("pause");
												system("cls");
												goto MenuContas;											
												}										
										}	
									}
								}
								system("cls");
								printf("Conta n�o encontrada.\n");
								system("pause");
								system("cls");
								goto MenuContas;
							break;
						
							//SAIR 
							case 'S':
							case 's':	
								system("cls");	
								goto MenuPrincipal;
							break;
				
							//ERRO
							default:
								system("cls");
								printf("Por favor, digite um comando v�lido.\n");
								system("pause");														
								system("cls");
								goto MenuContas;
						}
		break;
	
		//SAIR	
		case 'S':
		case 's':	
			system("cls");
			system("exit");
		break;
		
		//ERRO
		default:			
			system("cls");
			printf("Por favor, digite um comando v�lido.\n");
			system("pause");
			getchar();
			system("cls");
			goto MenuPrincipal;	
	}
	return 0;
}
