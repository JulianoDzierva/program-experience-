#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<ctype.h>
#include<windows.h>
#include<string.h>
#define STRTAM 77
void LinhaSuperior(){

	int i;

	printf("%c",201);
	for(i=0;i<STRTAM;i++){
		printf("%c",205);
	}
	printf("%c\n",187);
}
void LinhaRodape(int tamX){

	int i;

	printf("%c",200);
	for(i=0;i<STRTAM;i++){
		printf("%c",205);
	}
	printf("%c\n",188);

}
void CriaLinha(int tamX, char str[]){


	int i,contaLetras=0;

	for(i=0;i<tamX;i++){
		if(str[i]=='\0'){
			break;
		}else{
			contaLetras++;
		}
	}

	printf("%c",186);
	printf("%s",str);
	while(contaLetras<tamX){
		printf("%c",32);
		contaLetras++;
	}
	printf("%c\n",186);

}
void AbreBorda(int tamX, char str[]){
	printf("%c",186);
	printf("%s",str);
}
void FechaBorda(int tamX){

	if(tamX=='\0'){
		printf("%c",186);
	}
}

struct cadastroAdm {

	char nome[20];
	char nomeUser[20];
	int senha[7];

};
struct cadastroPort {

	char nome[20];
	char turno[11];
	char nomeUser[20];
	int senha[7];

};
struct cadastroCliente {

	char nome[20];
	char sobreNOme[20];
	char funcao[20];
	char carro[30];
	char cor[30];
	char placa[8];
	char cpf[12];
	char celular[10];

};
struct PesqUsuario {

	char placa[7];
	char nome[10];

};
struct login {

	char User[20];
	char senhaPort[7];
	char UserAdm[20];
	int senhaAdm[7];

};
int main(){

	int cont=0,op,i,j,ctrl=0;



	struct cadastroAdm adm;
	struct cadastroPort porteiro[2];
	struct cadastroCliente user[100];
	struct PesqUsuario pesquisa;
	struct login login;

	for(;;){
		destino:
		LinhaSuperior();

		CriaLinha(STRTAM,"PEDRO MACEDO EFMP           SEJA BEM VINDO             CONTROLSEG");
		CriaLinha(STRTAM,"");
		CriaLinha(STRTAM,"[1] LOGIN");
		CriaLinha(STRTAM,"[2] AREA ADRIMINISTRADOR");
		LinhaRodape(STRTAM);
		scanf("%d",&op);

		if(op==1){
			FILE *f;
				f= fopen("cadastroAdm.txt","r");
			fclose(f);
			FILE *file;
				file= fopen("cadastroPorteiro.txt","r");
			fclose(file);
			if((f==NULL)&&(file==NULL)){
				printf("\t\t\tNENHUM CADASTRO");
				Sleep(800);
				system("cls");
			}else{
				for(;;){
					while(ctrl==0){

						system("cls");
						LinhaSuperior();
						CriaLinha(STRTAM,"PEDRO MACEDO EFMP           LOGIN PORTERIO             CONTROLSEG");
						CriaLinha(STRTAM,"");
						CriaLinha(STRTAM,"[1] CONTINUAR");
						CriaLinha(STRTAM,"[0] VOLTAR");
						LinhaRodape(STRTAM);
						scanf("%d",&op);
						if(op==1){
							LinhaSuperior();
							AbreBorda(STRTAM,"NOME DE USUARIO: ");
							scanf("%s",login.User);
							FechaBorda(STRTAM);
							LinhaRodape(STRTAM);
							LinhaSuperior();
							AbreBorda(STRTAM,"SENHA: ");
							for(i=0;i<6;i++){
								login.senhaPort[i]=getch();
								printf("*");
							}
							char tamX;
							if(tamX=='\0'){
								printf("\n");
								LinhaRodape(STRTAM);
							}
							for(i=0;i<2;i++){
								if(strcmp(login.User,porteiro[i].nomeUser)==0){
									if(strcmp(login.senhaPort,porteiro[i].senha)==0){
										ctrl=1;
										printf("BEM VINDO!!\n");
										Sleep(800);
										system("cls");
										break;
									}
								}
							}
							if(strcmp(login.User,adm.nomeUser)==0){
								if(strcmp(login.senhaPort,adm.senha)==0){
									ctrl=1;
									printf("BEM VINDO!!\n");
									Sleep(800);
									system("cls");
								}
							}else{
								printf("NOME DE USUARIO OU SENHA INCORRETA!! \a\n");
								ctrl=0;
								break;
							}
						}else{
							system("cls");
							Sleep(100);
							goto destino;
						}
					}
					for(;;){
						system("cls");
						LinhaSuperior();
						CriaLinha(STRTAM,"PEDRO MACEDO   EFMP CENTRAL   CONTROLSEG");
						CriaLinha(STRTAM,"");
						CriaLinha(STRTAM,"");
						CriaLinha(STRTAM,"[1] CONSULTAR");
						CriaLinha(STRTAM,"[2] CADASTRAR VISITANTES");
						CriaLinha(STRTAM,"[0] LOGOFF");
						LinhaRodape(STRTAM);
						scanf("%d",&op);
						if(op==1){
							for(;;){
								system("cls");
								printf("PEDRO MACEDO EFMP");
								printf("\t\tCONSULTA");
								printf("\t\tCONTROLSEG  ");

								printf("\n[1] CONSULTA POR PLACA\n");
								printf("[2] CONSULTA POR NOME\n");
								printf("[0] VOLTAR\n\n");
								scanf("%d",&op);
								if(op==1){
									printf("PLACA: ");
									scanf("%s",pesquisa.placa);
									for(i=0;i<10;i++){
										if(strcmp(pesquisa.placa,user[i].placa)==0){
											printf("nome: %s\n",user[i].nome);
											printf("funcao: %s\n",user[i].funcao);
											printf("carro: %s\n",user[i].carro);
											printf("cor: %s\n",user[i].cor);
											printf("placa: %s\n",user[i].placa);
											system("pause");
											i=1;
											break;
										}
									}
									if(i!=1){
										printf("placa nao encontrada...\a\n");
										Sleep(800);
										system("cls");
									}
								}else if(op==2){
									printf("NOME: ")	;
									scanf("%s",pesquisa.nome);
									for(i=0;i<10;i++){
										if(strcmp(pesquisa.nome,user[i].nome)==0){
											printf("nome: %s\n",user[i].nome);
											printf("funcao: %s\n",user[i].funcao);
											printf("carro: %s\n",user[i].carro);
											printf("cor: %s\n",user[i].cor);
											printf("placa: %s\n",user[i].placa);
											system("pause");
											i=1;
											break;
										}
									}
									if(i!=1){
										printf("nome nao encontrado...\a\n");
										Sleep(800);
										system("cls");
									}
								}else{
									break;
								}
							}
						}else if(op==2){
							for(;;){
								system("cls");
								printf("PEDRO MACEDO EFMP");
								printf("\t\tCADASTRO VISITANTES");
								printf("\tCONTROLSEG  \n");

								printf("\n[1] CONTINUAR\n");
								printf("[0] VOLTAR\n ");
								scanf("%d",&op);

								printf("%d\n",cont);
								i=cont;
								printf("%d\n",i);
								if(op==1){
									printf("NOME: ");
									scanf("%s",user[i].nome);
									printf("\nSOBRENOME: ");
									scanf("%s",user[i].sobreNOme);
									printf("\nCPF: ");
									scanf("%s",user[i].cpf);
									printf("\nCELULAR: ");
									scanf("%s",user[i].celular);
									printf("\nVEICULO: ");
									scanf("%s",user[i].carro);
									printf("\nCOR: ",user[i].cor);
									scanf("%s",user[i].cor);
									printf("\nPLACA: ");
									scanf("%s",user[i].placa);

									printf("\n[1]CONFIRMAR\n");
									printf("[0]CANCELAR ");
									scanf("%d",&op);

									if(op==1){
										FILE *file;
											file=fopen("cadastroUsuarios.txt","a");
											if(file==NULL){
												printf("ERRO NA ABERTURA DO ARQUIVO!\a");
												Sleep(800);
												system("cls");
												return 0;
											}
											fprintf(file,"NOME: %s\n",user[i].nome);
											fprintf(file,"SOBRENOME: %s\n",user[i].sobreNOme);
											fprintf(file,"CPF: %s\n",user[i].cpf);
											fprintf(file,"CELULAR: %s\n",user[i].celular);
											fprintf(file,"VEICULO: %s\n",user[i].carro);
											fprintf(file,"PLACA: %s\n",user[i].placa);
										fclose(file);
										printf("CADASTRO REALIZADO COM SUCESSO");
										Sleep(800);
									}
								}else{
									break;
								}
							}
						}else{
							system("cls");
							printf("\n\n\n\t\t\tATE LOGO...");
							Sleep(800);
							break;
						}
					}
				}
			}
		}else if(op==2){
			for(;;){
				FILE *file;
					file= fopen("cadastroAdm.txt","r");
				fclose(file);
				if(file==NULL){

						system("cls");
						LinhaSuperior();
						CriaLinha(STRTAM,"PEDRO MACEDO EFMP           CADASTRO ADM             CONTROLSEG");
					LinhaRodape(STRTAM);
					printf("NOME: ");
					scanf("%s",&adm.nome);
					printf("\nNOME DE USUARIO: ");
					scanf("%s",adm.nomeUser);
					printf("SENHA:");
					scanf("%s",adm.senha);

					for(;;){
						printf("\n[1]CONFIRMAR\n");
						printf("[0]CANCELAR ");
						scanf("%d",&op);

						if(op==1){
							FILE *file;
								file= fopen("cadastroAdm.txt","w");
								if(file==NULL){
									system("cls");
									printf("ERRO NA ABERTURA DO ARQUIVO\n");
									Sleep(1000);
									return 0;
								}
								fprintf(file,"			CADASTRO ADM \n");
								fprintf(file,"\nNOME: %s",adm.nome);
								fprintf(file,"\nNOME DE USUARIO: %s", adm.nomeUser);
								fprintf(file,"\nSENHA: %s",adm.senha);
							fclose(file);
							printf("\t\t\tCADASTRO REALIZADO  COM SUSCESSO\n");
							Sleep(800);
							system("cls");

							destino2:
							for(;;){
								printf("PEDRO MACEDO EFMP");
								printf("\tBEM VINDO     %s  ",adm.nome);
								printf("\t\tCONTROLSEG\n\n");
								printf("\t\t\tAREA ADIMINISTRADOR\n\n");

								printf("\t\t\t[1]CADASTRAR PORTEIRO\n");
								printf("\t\t\t[2]CADASTRAR USUARIOS\n");
								printf("\t\t\t[0]SAIR\n");
								scanf("%d",&op);

								if(op==1){
									FILE *file;
										file= fopen("cadastroPorteiro.txt","w");
										if(file==NULL){
											system("cls");
											printf("ERRO NA ABERTURA DO ARQUIVO\n");
											Sleep(800);
											return 0;
										}
										fprintf(file," \t\t\tCADASTRO PORTEIROS\n");
									fclose(file);

									for(;;){
										system("cls");
										printf("PEDRO MACEDO EFMP");
										printf("\tCADASTRO PORTEIRO");
										printf("\tCONTROLSEG  %s \n\n",adm.nome);

										printf("\n\n[0]VOLTAR \n");
										printf("[1]CONTINUAR\n");
										scanf("%d",&op);

										if(op==0){
											system("cls");
											break;
										}else if(op==1){
											for(i=0;i<2;i++){
												printf("\n\nNOME: ");
												scanf("%s",porteiro[i].nome);
												printf("\nTURNO: ");
												scanf("%s",porteiro[i].turno);
												printf("\nNOME DE USUARIO: ");
												scanf("%s",porteiro[i].nomeUser);
												printf("\nSENHA: ");
												for(j=0;j<6;j++){
													porteiro[i].senha[j]=getch();
													printf("%c",porteiro[i].senha[j]);
												}
													printf("\n[1]CONFIRMAR\n");
													printf("[0]CANCELAR ");
													scanf("%d",&op);
													if(op==1){
														FILE *file;
															file= fopen("cadastroPorteiro.txt","a");
															if(file==NULL){
																printf("ERRO NA ABERTURA DO CADASTRO");
																Sleep(1000);
																return 0;
															}
															fprintf(file,"NOME: %s\n",porteiro[i].nome);
															fprintf(file,"TURNO: %s\n",porteiro[i].turno);
															fprintf(file,"NOME DE USUARIO: %s\n",porteiro[i].nomeUser);
															fprintf(file,"SENHA: ");
															for(j=0;j<6;j++){
																fprintf(file,"%c",porteiro[i].senha[j]);
															}
															fprintf(file,"\n_____________________________________\n");
														fclose(file);
									 					printf("\t\t\tCADASTRO REALIZADO COM SUCESSO\n\n");
														Sleep(1000);
                                                        system("cls");
														break;
													}else if(op==0){
														printf("\t\t\tCADASTRO CANCELADO!\n");
														Sleep(800);
														system("cls");
														break;
													}else{
														printf("\t\t\tOPCAO INVALIDA!\n");
														Sleep(800);
													}
												}
										}else{
											printf("\t\t\tOPCAO INVALIDA!\n");
											Sleep(800);
											system("cls");
										}
									}
								}else if(op==2){
									FILE *file;
										file= fopen("cadastroUsuarios.txt","w");
										if(file==NULL){
											printf("ERRO NA ABERTURA DO CADASTRO");
											Sleep(800);
											return 0;
										}
										fprintf(file,"\t\t\tCADASTRO USUARIOS\n\n");
									fclose(file);
									for(i=0;i<10;i++){
										system("cls");
										printf("PEDRO MACEDO EFMP");
										printf("\t\tCADASTRO USUARIO");
										printf("\tCONTROLSEG %s\n\n",adm.nome);

										printf("\n\n[0]VOLTAR \n");
										printf("[1]CONTINUAR\n");
										scanf("%d",&op);
										if(op==0){
											system("cls");
											break;
										}else if(op==1){

												printf("\n\nNOME: ");
												scanf("%s",user[i].nome);
												printf("\nFUNCAO: ");
												scanf("%s",user[i].funcao);
												printf("\nCARRO: ");
												scanf("%s",user[i].carro);
												printf("\nCOR: ");
												scanf("%s",user[i].cor);
												printf("\nPLACA:");
												scanf("%s",user[i].placa);
												cont++;
												printf("\n[1]CONFIRMAR\n");
												printf("[0]CANCELAR ");
												scanf("%d",&op);
												if(op==1){
													FILE *file;
													file= fopen("cadastroUsuarios.txt","a");
														if(file==NULL){
															printf("ERRO NA ABERTURA DO CADASTRO");
															Sleep(800);
															return 0;
														}
														fprintf(file,"NOME: %s\n",user[i].nome);
														fprintf(file,"FUNCAO: %s\n",user[i].funcao);
														fprintf(file,"CARRO: %s\n",user[i].carro);
														fprintf(file,"COR: %s\n",user[i].cor);
														fprintf(file,"PLACA: %s\n",user[i].placa);
														fprintf(file,"_____________________________________\n");
													fclose(file);
													printf("\t\t\tCADASTRO REALIZADO COM SUCESSO\n\n");
													Sleep(800);
													system("cls");
												}else if(op==0){
													printf("\t\t\tCADASTRO CANCELADO!\a");
													Sleep(800);
													break;
												}else{
													printf("\t\t\tOPCAO INVALIDA!\n");
													Sleep(800);
													system("cls");
												}

										}else{
											printf("\t\t\tOPCAO INVALIDA!\n");
											Sleep(800);
											system("pause");
										}
									}
								}else if(op==0){
									system("cls");
	 								goto destino;
								}else{
									printf("\t\t\tOPCAO INVALIDA!\n");
									Sleep(800);
									system("cls");
								}
							}
						}else if(op==0)	{
							printf("cadastro cancelado!\a");
							Sleep(800);
							system("cls");
							break;
						}else{
							printf("opcao invalida\a");
							Sleep(800);
						}
					}
				}else{
					do{
						system("cls");
						printf("PEDRO MACEDO EFMP");
						printf("\t\t\tLOGIN ADM");
						printf("\t\tCONTROLSEG\n\n");
						printf("\n[1] CONTINUAR\n");
						printf("[0] VOLTAR\n ");
						scanf("%d",&op);
						if(op==1){
							printf("NOME DE USUARIO: ");
							scanf("%s",login.UserAdm);
							printf("\nSENHA: ");
							for(i=0;i<6;i++){
								login.senhaAdm[i]=getch();
								printf("*");
							}
							if(strcmp(login.UserAdm,adm.nomeUser)==0){
								if(strcmp(login.senhaAdm,adm.senha)==0){
									ctrl=1;
									printf("BEM VINDO!!\n");
									Sleep(800);
									system("cls");
									goto destino2;
								}
							}else{
								printf("NOME DE USUARIO OU SENHA INCORRETA!! \a\n");
								ctrl=0;
								Sleep(800);
							}
						}else{
							system("cls");
							goto destino;
						}
					}while(ctrl==0);
				}
			}
		}else{
			system("cls");
		}
	}
	return 0;
}
