#include <stdio.h>									
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

void posiciona(char **nav,int jogador);		
void mostratabuleiro(char **nav1);
void atira(char **nav1,char **nav2,char **tir1,char **tir2);
void posiciona_maquina(char **nav,int jogador);

int main() 														
{
	char **navios1,**navios2,**tiros1,**tiros2;
	int j,k,*sorteio;
    
	
	printf("Inicia Jogo \n\n");
	
	navios1 = (char **)malloc(10*sizeof(char *));
	navios2 = (char **)malloc(10*sizeof(char *));
	tiros1 = (char **)malloc(10*sizeof(char *));
	tiros2 = (char **)malloc(10*sizeof(char *));
    sorteio = (int *) malloc (20 * sizeof(int *));
	
		
	for(j=0;j<10;j++)
	{
		navios1[j] = (char *)malloc(10*sizeof(char));
		navios2[j] = (char *)malloc(10*sizeof(char));
		tiros1[j] = (char *)malloc(10*sizeof(char));
		tiros2[j] = (char *)malloc(10*sizeof(char));
		
		for(k=0;k<10;k++)
		{
			navios1[j][k] = '-';
			navios2[j][k ] = '-';
			tiros1[j][k] = '-';
			tiros2[j][k] = '-';
		}
	}
	
	printf("Posiciona navios Jogador 1\n\n");
	posiciona(navios1,1);
	
	printf("\n");

	printf("Posiciona navios Jogador 2\n\n");
	posiciona_maquina(navios2,2);
	
	printf("\n\n");

	printf("Inicia os tiros\n");	
	atira(navios1,navios2,tiros1,tiros2);
	
	return 0;
}

void posiciona(char **nav,int jogador)
{
	int linha,lin,col,i=0,j,l,c,flag,sinal,sinal1,sinal2;
	char coluna,direcao,tiponav;
	
	printf("Entre com as coordenadas para posicionamento dos navios: Linha->1-10 Coluna->A-J\n");
	printf("Jogador %d\n",jogador);	
	mostratabuleiro(nav);
	
	while(i<5)
	{
		sinal=0;
		while(sinal!=1)
		{
			printf("Entre com a linha= ");
			scanf("%i",&linha);
			if(linha <= 10 && linha >= 1)
				sinal = 1;
			else
				printf("Linha invalida - Entre linha novamente\n");
		}
		
		sinal1=0;

		while(sinal1!=1)
		{
			printf("Entre com a coluna= de A ate J= \n ");
			getchar();
			scanf("%c",&coluna);
            coluna = toupper(coluna);
			if( (coluna =='A')||(coluna=='B')||(coluna=='C')||(coluna=='D')||(coluna=='E')||(coluna=='F')|| (coluna=='G') ||(coluna=='H')|| (coluna=='I')||(coluna=='J'))
				sinal1 = 1;
			else{
				printf("Coluna invalida - Entre coluna novamente\n");
            }
		}
					
		lin=linha-1;
		
		if(coluna=='A')
			col=0;
		else
			if(coluna=='B')
				col=1;
			else
				if(coluna=='C')
					col=2;
				else
					if(coluna=='D')
						col=3;
					else
						if(coluna=='E')
							col=4;
						else
							if(coluna=='F')
								col=5;
							else
								if(coluna=='G')
									col=6;
								else
									if(coluna=='H')
										col=7;
									else
										if(coluna=='I')
											col=8;
										else
											if(coluna=='J')
												col=9;
										
		printf("Entre com a direcao: h-horizontal v-vertical\n");
		getchar();
		scanf("%s",&direcao);
        direcao = toupper(direcao);
		printf("\n");
		
		if(direcao=='H')				
		{
			flag=0;//Posicao horizontal
			
			sinal2=0;
			while(sinal2!=1)
			{
				printf("Entre com o tipo de navio: P-porta aviao G-navio de guerra C-cruzador S-submarino D-destruidor\n");
                getchar();
				scanf("%c",&tiponav);
                tiponav = toupper(tiponav);
				printf("\n");
				if(tiponav == 'P'||tiponav == 'G'||tiponav == 'C'||tiponav == 'S'||tiponav == 'D'){
					sinal2=1;
                }
				else{
					printf("Navio invalido - Entre navio novamente\n");
                }
                printf("%c\n",tiponav);
			}
					
					
			if(tiponav== 'P')
				if(col > 5)
					printf("Porta aviao ficou fora do tabuleiro so pode usar A-F\n");
				else
				{
					for(j=0;j<5;j++)
					{
						if(nav[lin][col+j]!='-')
							flag=1;
					}
						
					if(flag==1)
						printf("posicao ocupada por Navio\n");
					else
					{
						for(j=0;j<5;j++)
							nav[lin][col+j]='P';
								
						i=i+1;
						printf("Jogador %d\n",jogador);								
						mostratabuleiro(nav);
					}
				}
			else
				if(tiponav=='G')
					if(col>6)
						printf("Navio de Guerra ficou fora do tabuleiro so pode usar A-G\n");
					else
					{
						for(j=0;j<4;j++)
						{
							if(nav[lin][col+j]!='-')
								flag=1;
						}
						
						if(flag==1)
							printf("posicao ocupada por Navio\n");
						else
						{
							for(j=0;j<4;j++)
								nav[lin][col+j]='G';
										
							i=i+1;
							printf("Jogador %d\n",jogador);	
							mostratabuleiro(nav);
						}
					}
				else
					if(tiponav=='C')
						if(col>7)
							printf("Cruzador ficou fora do tabuleiro so pode usar A-H\n");
						else
						{
							for(j=0;j<3;j++)
							{
								if(nav[lin][col+j]!='-')
									flag=1;
							}
							
							if(flag==1)
								printf("posicao ocupada por Navio\n");
							else
							{
								for(j=0;j<3;j++)
							  		nav[lin][col+j]='C';
									
								i=i+1;
								printf("Jogador %d\n",jogador);
								mostratabuleiro(nav);
							}
						}
					else
						if(tiponav=='S')
							if(col>7)
								printf("Submarino ficou fora do tabuleiro so pode usar A-H\n");
							else
								{
									for(j=0;j<3;j++)
									{
										if(nav[lin][col+j]!='-')
											flag=1;
									}
									
									if(flag==1)
										printf("posicao ocupada por Navio\n");
									else
									{
										for(j=0;j<3;j++)
											nav[lin][col+j]='S';
										
										i=i+1;
										printf("Jogador %d\n",jogador);
										mostratabuleiro(nav);
									}
								}
						else
							if(tiponav=='D')
								if(col==9)
									printf("Destruidor ficou fora do tabuleiro so pode usar A-I\n");
								else
									{
										for(j=0;j<2;j++)
										{
											if(nav[lin][col+j]!='-')
												flag=1;
										}
										
										if(flag==1)
											printf("posicao ocupada por Navio\n");
										else
										{
											for(j=0;j<2;j++)
												nav[lin][col+j]='D';
											
											i=i+1;
											printf("Jogador %d\n",jogador);
											mostratabuleiro(nav);
										}
									}
		}
		else
			{
				flag=0;//Posicao vertical
				
				sinal2=0;
				while(sinal2!=1)
				{
					printf("Entre com o tipo de navio: P-porta aviao G-navio de guerra C-cruzador S-submarino D-destruidor\n");
					getchar();
					scanf("%s",&tiponav);
                    tiponav = toupper(tiponav);
					printf("\n");
					if(tiponav == 'P'||tiponav == 'G'||tiponav == 'C'||tiponav == 'S'||tiponav == 'D')
						sinal2=1;
                    
					else
						printf("Navio invalido - Entre navio novamente \n");
				}
				
				if(tiponav == 'P')
					if(lin>5)
						printf("Porta aviao ficou fora do tabuleiro so pode usar linha de 1-6\n");
					else
					{
						for(j=0;j<5;j++)
						{
							if(nav[lin+j][col]!='-')
								flag=1;
						}
								
						if(flag==1)
							printf("posicao ocupada por Navio\n");
						else
						{
							for(j=0;j<5;j++)
								nav[lin+j][col]='P';
								
							i=i+1;
							printf("Jogador %d\n",jogador);
							mostratabuleiro(nav);
						}
					}
				else
					if(tiponav=='G')
						if(lin>6)
							printf("Navio de Guerra ficou fora do tabuleiro so pode usar linha 1=7\n");
						else
						{
							for(j=0;j<4;j++)
							{
								if(nav[lin+j][col]!='-')
									flag=1;
							}
								
							if(flag==1)
								printf("posicao ocupada por Navio\n");
							else
							{
								for(j=0;j<4;j++)
									nav[lin+j][col]='G';
									
								i=i+1;
								printf("Jogador %d\n",jogador);
								mostratabuleiro(nav);
							}
						}
					else
						if(tiponav=='C')
							if(lin>7)
								printf("Cruzador ficou fora do tabuleiro so pode usar linha de 1-8\n");
							else
							{
								for(j=0;j<3;j++)
								{
									if(nav[lin+j][col]!='-')
										flag=1;
								}
								
								if(flag==1)
									printf("posicao ocupada por Navio\n");
								else
								{
									for(j=0;j<3;j++)
										nav[lin+j][col]='C';
										
									i=i+1;
									printf("Jogador %d\n",jogador);
									mostratabuleiro(nav);
								}
							}
						else
							if(tiponav=='S')
								if(lin>7)
									printf("Submarino ficou fora do tabuleiro so pode usar linha de 1-8\n");
								else
								{
									for(j=0;j<3;j++)
									{
										if(nav[lin+j][col]!='-')
											flag=1;
									}
								
									if(flag==1)
										printf("posicao ocupada por Navio\n");
									else
									{
										for(j=0;j<3;j++)
											nav[lin+j][col]='S';
											
										i=i+1;
										printf("Jogador %d\n",jogador);
										mostratabuleiro(nav);
									}
								}
							else
								if(tiponav=='D')
									if(lin==9)
										printf("Destruidor ficou fora do tabuleiro so pode usar linha de 1-9\n");
									else
									{
										for(j=0;j<2;j++)
										{
											if(nav[lin+j][col]!='-')
												flag=1;
										}
								
										if(flag==1)
											printf("posicao ocupada por Navio\n");
										else
										{
											for(j=0;j<2;j++)
												nav[lin+j][col]='D';
												
											i=i+1;
											printf("Jogador %d\n",jogador);
											mostratabuleiro(nav);
										}
									}
			}
		
		
	}
}

void posiciona_maquina(char **nav,int jogador)
{
	int linha,lin,col,i=0,j,l,c,flag,sinal,sinal1,sinal2,sorteio;
	char coluna,direcao,tiponav;
    int koluna,sentido,barco,ok = 0;
	
	mostratabuleiro(nav);
	
	while(i<5)
	{
		sinal=0;
		while(sinal!=1)
		{
			srand(time(NULL));
			linha = rand()%10;
			if(linha <= 10 && linha >= 1)
				sinal = 1;
		}
		
		sinal1=0;

		while(sinal1!=1)
		{
			koluna = rand()%9; 
            
			if( (koluna == 0)||(koluna == 1)||(koluna == 2)||(koluna == 3)||(koluna == 4)||(koluna == 5)|| (koluna == 6) ||(koluna == 7)|| (koluna == 8)||(koluna == 9))
				sinal1 = 1;
		}
					
		lin=linha;
		
		if(koluna == 0){
			col=0;
        }
		else
			if(koluna == 1){
				col=1;
            }
			else
				if(koluna == 2){
					col=2;
                }
				else
					if(koluna == 3){
						col=3;
                    }
					else
						if(koluna == 4){
							col=4;
                        }
						else
							if(koluna == 5){
								col=5;
                            }
							else
								if(koluna == 6){
									col=6;
                                }
								else
									if(koluna == 7){
										col=7;
                                    }
									else
										if(koluna == 8){                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      
											col=8;
                                        }
										else
											if(koluna == 9){
												col=9;
                                            }
                                                
										
		sentido = rand()%2;
		if(sentido == 0)				
		{
			flag=0;//Posicao horizontal
			sinal2=0;
			while(sinal2!=1)
			{
                barco = i;
				if(barco == 0||1||2||3||4){
                    sinal2=1;
                }
			}
			if(barco == 0){
				if(col > 5)
					printf("Porta aviao ficou fora do tabuleiro so pode usar A-F\n");
				else
				{
					for(j=0;j<5;j++)
					{
						if(nav[lin][col+j]!='-')
							flag=1;
					}
						
					if(flag==1)
						printf("posicao ocupada por Navio\n");
					else
					{
						for(j=0;j<5;j++)
							nav[lin][col+j]='P';
								
						i=i+1;
						printf("Jogador %d\n",jogador);								
						mostratabuleiro(nav);
					}
				}
            }
                else
				if(barco == 1){
					if(col>6)
						printf("Navio de Guerra ficou fora do tabuleiro so pode usar A-G\n");
					else
					{
						for(j=0;j<4;j++)
						{
							if(nav[lin][col+j]!='-')
								flag=1;
						}
						
						if(flag==1)
							printf("\n");
						else
						{
							for(j=0;j<4;j++)
								nav[lin][col+j]='G';
										
							i=i+1;
							printf("Jogador %d\n",jogador);	
							mostratabuleiro(nav);
						}
					}
                }
                else
					if(barco == 2){
						if(col>7)
							printf("Cruzador ficou fora do tabuleiro so pode usar A-H\n");
						else
						{
							for(j=0;j<3;j++)
							{
								if(nav[lin][col+j]!='-')
									flag=1;
							}
							
							if(flag==1)
								printf("\n");
							else
							{
								for(j=0;j<3;j++)
							  		nav[lin][col+j]='C';
									
								i=i+1;
								printf("Jogador %d\n",jogador);
								mostratabuleiro(nav);
							}
						}
                    }
                    else
						if(barco == 3){
							if(col>7)
								printf("Submarino ficou fora do tabuleiro so pode usar A-H\n");
							else
								{
									for(j=0;j<3;j++)
									{
										if(nav[lin][col+j]!='-')
											flag=1;
									}
									
									if(flag==1)
										printf("\n");
									else
									{
										for(j=0;j<3;j++)
											nav[lin][col+j]='S';
										
										i=i+1;
										printf("Jogador %d\n",jogador);
										mostratabuleiro(nav);
									}
								}
                        }
                        else
							if(barco == 4){
								if(col==9)
									printf("Destruidor ficou fora do tabuleiro so pode usar A-I\n");
								else
									{
										for(j=0;j<2;j++)
										{
											if(nav[lin][col+j]!='-')
												flag=1;
										}
										
										if(flag==1)
											printf("\n");
										else
										{
											for(j=0;j<2;j++)
												nav[lin][col+j]='D';
											
											i=i+1;
											printf("Jogador %d\n",jogador);
											mostratabuleiro(nav);
										}
									}
                            }
		}
		else
        if(sentido == 1){
			{
				flag=0;//Posicao vertical
				
				sinal2=0;
				while(sinal2!=1)
				{
                    barco = i;
				    printf("\n");
				    if(barco == 0||1||2||3||4){
                    sinal2=1;
                    } 
					else
						printf("Navio invalido - Entre navio novamente \n");
				}

				if(barco == 0){
					if(lin>5)
						printf("Porta aviao ficou fora do tabuleiro so pode usar linha de 1-6\n");
					else
					{
						for(j=0;j<5;j++)
						{
							if(nav[lin+j][col]!='-')
								flag=1;
						}
								
						if(flag==1)
							printf("\n");
						else
						{
							for(j=0;j<5;j++)
								nav[lin+j][col]='P';
								
							i=i+1;
							printf("Jogador %d\n",jogador);
							mostratabuleiro(nav);
						}
					}
                }
                else
					if(barco == 1){
                        printf("teste\n");
						if(lin>6)
							printf("Navio de Guerra ficou fora do tabuleiro so pode usar linha 1=7\n");
						else
						{
							for(j=0;j<4;j++)
							{
								if(nav[lin+j][col]!='-')
									flag=1;
							}
								
							if(flag==1)
								printf("\n");
							else
							{
								for(j=0;j<4;j++)
									nav[lin+j][col]='G';
									
								i=i+1;
								printf("Jogador %d\n",jogador);
								mostratabuleiro(nav);
							}
						}
                    }
                        else
						    if(barco == 2){
							    if(lin>7)
								    printf("Cruzador ficou fora do tabuleiro so pode usar linha de 1-8\n");
							else
							{
								for(j=0;j<3;j++)
								{
									if(nav[lin+j][col]!='-')
										flag=1;
								}
								
								if(flag==1)
									printf("\n");
								else
								{
									for(j=0;j<3;j++)
										nav[lin+j][col]='C';
										
									i=i+1;
									printf("Jogador %d\n",jogador);
									mostratabuleiro(nav);
								}
							}
                        }
                        else
							if(barco == 3){
								if(lin>7)
									printf("Submarino ficou fora do tabuleiro so pode usar linha de 1-8\n");
								else
								{
									for(j=0;j<3;j++)
									{
										if(nav[lin+j][col]!='-')
											flag=1;
									}
								
									if(flag==1)
										printf("\n");
									else
									{
										for(j=0;j<3;j++)
											nav[lin+j][col]='S';
											
										i=i+1;
										printf("Jogador %d\n",jogador);
										mostratabuleiro(nav);
									}
								}
                            }
                            else
								if(barco == 4){
									if(lin==9)
										printf("Destruidor ficou fora do tabuleiro so pode usar linha de 1-9\n");
									else
									{
										for(j=0;j<2;j++)
										{
											if(nav[lin+j][col]!='-')
												flag=1;
										}
								
										if(flag==1)
											printf("\n");
										else
										{
											for(j=0;j<2;j++)
												nav[lin+j][col]='D';
												
											i=i+1;
											printf("Jogador %d\n",jogador);
											mostratabuleiro(nav);
										}
									}
			}
            }
        }
		
	}
}


void mostratabuleiro(char **navio)
{
	int l,c;
	printf("    A  B  C  D  E  F  G  H  I  J\n");
	for(l = 0; l < 10; l++)
	{
		printf("%d",l+1);
												
		if((l+1)!=10)
			printf("  ");
		else
			printf(" ");
													
		for(c=0;c<10;c++)
			printf(" %c ",navio[l][c]);
											
		printf("\n");
	}
}


void atira(char **nav1,char **nav2,char **tir1,char **tir2)
{
	int linha11,linha21,linha31,lin11,lin21,lin31,col11,col21,col31,lin,col,cont,teste;
	int linha12,linha22,linha32,lin12,lin22,lin32,col12,col22,col32,sinal,sinal1;
	int afundoutudo=0,navafund1=0,navafund2=0;
	char coluna11,coluna21,coluna31,coluna12,coluna22,coluna32;
    int coluna01,coluna02,coluna03,coluna04,coluna05,coluna06;
	
	while(afundoutudo!=1)
	{
		printf("jogador 1\n");
		mostratabuleiro(nav1);
		printf("\n");
		printf("tabuleiro de tiros do jogador 1\n");
		mostratabuleiro(tir1);
		printf("Navios Afundados = %d\n\n",navafund1);
		
		printf("Marque o tiro da seguinte forma: O-agua X-fogo A-afundou\n");
		
		printf("Entre com as coordenadas dos tres tiros\n\n");
		
		teste=0;
		while(teste==0)
		{
			sinal=0;
			while(sinal==0)
			{
				printf("Entre com a linha e a coluna do primeiro tiro\n");
				printf("linha11=");
				getchar();
				scanf("%d",&linha11);
				if(linha11>=1&&linha11<=10)
					sinal=1;
				else
					printf("linha invalida - Entre linha novamente\n");
			}
				
			sinal1=0;
			while(sinal1==0)	
			{
				printf("coluna11=");
				getchar();
				scanf("%s",&coluna11);
				coluna11 = toupper(coluna11);
				printf("\n");
				if(coluna11=='A'||coluna11=='B'||coluna11=='C'||coluna11=='D'||coluna11=='E'||coluna11=='F'||coluna11=='G'||coluna11=='H'||coluna11=='I'||coluna11=='J')
					sinal1=1;
				else
					printf("Coluna invalida - Entre coluna novamente\n");
			}
			
			lin11 =linha11-1;
			if(coluna11=='A')
				col11=0;
			else
				if(coluna11=='B')
					col11=1;
				else
					if(coluna11=='C')
						col11=2;
					else
						if(coluna11=='D')
							col11=3;
						else
							if(coluna11=='E')
								col11=4;
							else
								if(coluna11=='F')
									col11=5;
								else
									if(coluna11=='G')
										col11=6;
									else
										if(coluna11=='H')
											col11=7;
										else
											if(coluna11=='I')
												col11=8;
											else
												if(coluna11=='J')
													col11=9;
																	
			if((tir1[lin11][col11]=='A')||(tir1[lin11][col11]=='X')||(tir1[lin11][col11]=='O'))											
				printf("Posicao ocupada - tente novamente\n");
			else
			{
				if(nav2[lin11][col11]=='-')
					tir1[lin11][col11]='O';
				else
					tir1[lin11][col11]='X';
				teste=1;
			}
															
		}
		
		teste=0;
		while(teste==0)
		{
			sinal=0;
			while(sinal==0)
			{
				printf("Entre com a linha e a coluna do segundo tiro\n");
				printf("linha21=");
				getchar();
				scanf("%d",&linha21);
				if(linha21>=1&&linha21<=10)
					sinal=1;
				else
					printf("linha invalida - Entre linha novamente\n");
			}
			
			sinal1=0;
			while(sinal1==0)	
			{
				printf("coluna21=");
				getchar();
				scanf("%s",&coluna21);
				coluna21 = toupper(coluna21);
				printf("\n");
				if(coluna21=='A'||coluna21=='B'||coluna21=='C'||coluna21=='D'||coluna21=='E'||coluna21=='F'||coluna21=='G'||coluna21=='H'||coluna21=='I'||coluna21=='J')
					sinal1=1;
				else
					printf("Coluna invalida - Entre coluna novamente\n");
			}
			
			lin21=linha21-1;
			if(coluna21=='A')
				col21=0;
			else
				if(coluna21=='B')
					col21=1;
				else
					if(coluna21=='C')
						col21=2;
					else
						if(coluna21=='D')
							col21=3;
						else
							if(coluna21=='E')
								col21=4;
							else
								if(coluna21=='F')
									col21=5;
								else
									if(coluna21=='G')
										col21=6;
									else
										if(coluna21=='H')
											col21=7;
										else
											if(coluna21=='I')
												col21=8;
											else
												if(coluna21=='J')
													col21=9;
													
			if((tir1[lin21][col21]=='A')||(tir1[lin21][col21]=='X')||(tir1[lin21][col21]=='O'))											
				printf("Posicao ocupada - tente novamente\n");
			else
			{
				if(nav2[lin21][col21]=='-')
					tir1[lin21][col21]='O';
				else
					tir1[lin21][col21]='X';
				teste=1;
			}
		}
		
		teste=0;
		while(teste==0)
		{
			sinal=0;
			while(sinal==0)
			{
				printf("Entre com a linha e a coluna do terceiro tiro\n");
				printf("linha31=");
				getchar();
				scanf("%d",&linha31);
				if(linha31>=1&&linha31<=10)
					sinal=1;
				else
					printf("linha invalida - Entre linha novamente\n");
			}
			
			sinal1=0;
			while(sinal1==0)	
			{
				printf("coluna31=");
				getchar();
				scanf("%s",&coluna31);
				coluna31 = toupper(coluna31);
				printf("\n");
				if(coluna31=='A'||coluna31=='B'||coluna31=='C'||coluna31=='D'||coluna31=='E'||coluna31=='F'||coluna31=='G'||coluna31=='H'||coluna31=='I'||coluna31=='J')
					sinal1=1;
				else
					printf("Coluna invalida - Entre coluna novamente\n");
			}
					
			lin31=linha31-1;
			if(coluna31=='A')
				col31=0;
			else
				if(coluna31=='B')
					col31=1;
				else
					if(coluna31=='C')
						col31=2;
					else
						if(coluna31=='D')
							col31=3;
						else
							if(coluna31=='E')
								col31=4;
							else
								if(coluna31=='F')
									col31=5;
								else
									if(coluna31=='G')
										col31=6;
									else
										if(coluna31=='H')
											col31=7;
										else
											if(coluna31=='I')
												col31=8;
											else
												if(coluna31=='J')
													col31=9;
													
			if((tir1[lin31][col31]=='A')||(tir1[lin31][col31]=='X')||(tir1[lin31][col31]=='O'))											
				printf("Posicao ocupada - tente novamente\n");
			else
			{
				if(nav2[lin31][col31]=='-')
					tir1[lin31][col31]='O';
				else
					tir1[lin31][col31]='X';
				teste=1;
			}
		}
		
		cont=0;
		for(lin=0;lin<10;lin++)		
			for(col=0;col<10;col++)
				if(nav2[lin][col]=='P'&&tir1[lin][col]=='X')
					cont=cont+1;
		if(cont==5)
		{
			for(lin=0;lin<10;lin++)		
				for(col=0;col<10;col++)
					if(nav2[lin][col]=='P')
						tir1[lin][col]='A';
			navafund1=navafund1+1;
		}
		
		cont=0;
		for(lin=0;lin<10;lin++)		
			for(col=0;col<10;col++)
				if(nav2[lin][col]=='G'&&tir1[lin][col]=='X')
					cont=cont+1;
		if(cont==4)
		{
			for(lin=0;lin<10;lin++)		
				for(col=0;col<10;col++)
					if(nav2[lin][col]=='G')
						tir1[lin][col]='A';		
			navafund1=navafund1+1;
		}
		
		cont=0;
		for(lin=0;lin<10;lin++)		
			for(col=0;col<10;col++)
				if(nav2[lin][col]=='C'&&tir1[lin][col]=='X')
					cont=cont+1;
		if(cont==3)
		{
			for(lin=0;lin<10;lin++)		
				for(col=0;col<10;col++)
					if(nav2[lin][col]=='C')
						tir1[lin][col]='A';
			navafund1=navafund1+1;
		}
		
		cont=0;
		for(lin=0;lin<10;lin++)		
			for(col=0;col<10;col++)
				if(nav2[lin][col]=='S'&&tir1[lin][col]=='X')
					cont=cont+1;
		if(cont==3)
		{
			for(lin=0;lin<10;lin++)		
				for(col=0;col<10;col++)
					if(nav2[lin][col]=='S')
						tir1[lin][col]='A';
			navafund1=navafund1+1;
		}
						
		cont=0;
		for(lin=0;lin<10;lin++)		
			for(col=0;col<10;col++)
				if(nav2[lin][col]=='D'&&tir1[lin][col]=='X')
					cont=cont+1;
		if(cont==2)
		{
			for(lin=0;lin<10;lin++)		
				for(col=0;col<10;col++)
					if(nav2[lin][col]=='D')
						tir1[lin][col]='A';
			navafund1=navafund1+1;
		}
		
		printf("jogador 1\n");
		mostratabuleiro(nav1);
		printf("\n");	
		printf("tabuleiro de tiros do jogador 1\n");		
		mostratabuleiro(tir1);
		printf("Navios Afundados = %d\n\n",navafund1);
		
		if(navafund1==5)
		{
			afundoutudo=1;
			printf("O jogador 1 e o vencedor\n");
		}
		
		
		if(afundoutudo!=1)
		{
			printf("jogador 2\n");
			mostratabuleiro(nav2);
			printf("\n");
			printf("tabuleiro de tiros do jogador 2\n");
			mostratabuleiro(tir2);
			printf("Navios Afundados = %d\n\n",navafund2);
			
			printf("Marque o tiro da seguinte forma: O-agua X-fogo A-afundou\n");
			
			printf("Entre com as coordenadas dos tres tiros\n");
			
			teste=0;
			while(teste==0)
			{
				sinal=0;
				while(sinal==0)
				{
					printf("Entre com a linha e a coluna do primeiro tiro\n");
					linha12 = rand()%10;
					if(linha12>=1&&linha12<=10)
						sinal=1;
					else
						printf("linha invalida - Entre linha novamente\n");
				}
				
				sinal1=0;
				while(sinal1==0)	
				{
					printf("coluna12=");
					coluna01 = rand()%9;
					printf("\n");
					if(coluna01== 0||1||2||3||4||5||6||7||8||9){
						sinal1=1;
                    }
					else
						printf("Coluna invalida - Entre coluna novamente\n");
				}
				
				lin12 = linha12-1;
				if(coluna01 == 0)
					col12=0;
				else
					if(coluna01 == 1)
						col12=1;
					else
						if(coluna01 == 2)
							col12=2;
						else
							if(coluna01== 3)
								col12=3;
							else
								if(coluna01 == 4)
									col12=4;
								else
									if(coluna01 == 5)
										col12=5;
									else
										if(coluna01 == 6)
											col12=6;
										else
											if(coluna01 == 7)
												col12=7;
											else
												if(coluna01 == 8)
													col12=8;
												else
													if(coluna01 == 9)
														col12=9;
															
				if((tir2[lin12][col12]=='A')||(tir2[lin12][col12]=='X')||(tir2[lin12][col12]=='O'))											
					printf("Posicao ocupada - tente novamente\n");
				else
				{
					if(nav1[lin12][col12]=='-')
						tir2[lin12][col12]='O';
					else
						tir2[lin12][col12]='X';
					teste=1;
				}
			}
			
			teste=0;
			while(teste==0)
			{
				sinal=0;
				while(sinal==0)
				{
					printf("Entre com a linha e a coluna do segundo tiro\n");
					linha22 = rand()%10;
					if(linha22>=1&&linha22<=10)
						sinal=1;
					else
						printf("linha invalida - Entre linha novamente\n");
				}
				
				sinal1=0;
				while(sinal1==0)	
				{
					printf("coluna22=");
					coluna02 = rand()%10;
					printf("\n");
					if(coluna02 == 0||1||2||3||4||5||6||7||8||9)
						sinal1=1;
					else
						printf("Coluna invalida - Entre coluna novamente\n");
				}
				
				lin22=linha22;
				if(coluna02 == 0)
					col22=0;
				else
					if(coluna02 == 1)
						col22=1;
					else
						if(coluna02== 2)
							col22=2;
						else
							if(coluna02== 3)
								col22=3;
							else
								if(coluna02== 4)
									col22=4;
								else
									if(coluna02== 5)
										col22=5;
									else
										if(coluna02== 6)
											col22=6;
										else
											if(coluna02== 7)
												col22=7;
											else
												if(coluna02== 8)
													col22=8;
												else
													if(coluna02== 9)
														col22=9;
														
				if((tir2[lin22][col22]=='A')||(tir2[lin22][col22]=='X')||(tir2[lin22][col22]=='O'))											
					printf("Posicao ocupada - tente novamente\n");
				else
				{
					if(nav1[lin22][col22]=='-')
						tir2[lin22][col22]='O';
					else
						tir2[lin22][col22]='X';
					teste=1;
				}
			}
			
			teste=0;
			while(teste==0)
			{
				sinal=0;
				while(sinal==0)
				{
					printf("Entre com a linha e a coluna do terceiro tiro\n");
					printf("linha32=");
					linha32 = rand()%10;
					if(linha32>=1&&linha32<=10)
						sinal=1;
					else
						printf("linha invalida - Entre linha novamente\n");
				}
				
				sinal1=0;
				while(sinal1==0)	
				{
					printf("coluna32=");
					coluna03 = rand()%10;
					printf("\n");
					if(coluna03 == 0||1||2||3||4||5||6||7||8||9)
						sinal1=1;
					else
						printf("Coluna invalida - Entre coluna novamente\n");
				}
						
				lin32=linha32-1;
				if(coluna03 == 0)
					col32=0;
				else
					if(coluna03 == 1)
						col32=1;
					else
						if(coluna03 == 2)
							col32=2;
						else
							if(coluna03 == 3)
								col32=3;
							else
								if(coluna03 == 4)
									col32=4;
								else
									if(coluna03 == 5)
										col32=5;
									else
										if(coluna03 == 6)
											col32=6;
										else
											if(coluna03 == 7)
												col32=7;
											else
												if(coluna03 == 8)
													col32=8;
												else
													if(coluna03 == 9)
														col32=9;
														
				if((tir2[lin32][col32]=='A')||(tir2[lin32][col32]=='X')||(tir2[lin32][col32]=='O'))											
					printf("Posicao ocupada - tente novamente\n");
				else
				{
					if(nav1[lin32][col32]=='-')
						tir2[lin32][col32]='O';
					else
						tir2[lin32][col32]='X';
					teste=1;
				}
			}
						
			cont=0;
			for(lin=0;lin<10;lin++)		
				for(col=0;col<10;col++)
					if(nav1[lin][col]=='P'&&tir2[lin][col]=='X')
						cont=cont+1;
			if(cont==5)
			{
				for(lin=0;lin<10;lin++)		
					for(col=0;col<10;col++)
						if(nav1[lin][col]=='P')
							tir2[lin][col]='A';
				navafund2=navafund2+1;
			}
			
			cont=0;
			for(lin=0;lin<10;lin++)		
				for(col=0;col<10;col++)
					if(nav1[lin][col]=='G'&&tir2[lin][col]=='X')
						cont=cont+1;
			if(cont==4)
			{
				for(lin=0;lin<10;lin++)		
					for(col=0;col<10;col++)
						if(nav1[lin][col]=='G')
							tir2[lin][col]='A';		
				navafund2=navafund2+1;
			}
			
			cont=0;
			for(lin=0;lin<10;lin++)		
				for(col=0;col<10;col++)
					if(nav1[lin][col]=='C'&&tir2[lin][col]=='X')
						cont=cont+1;
			if(cont==3)
			{
				for(lin=0;lin<10;lin++)		
					for(col=0;col<10;col++)
						if(nav1[lin][col]=='C')
							tir2[lin][col]='A';
				navafund2=navafund2+1;
			}
			
			cont=0;
			for(lin=0;lin<10;lin++)		
				for(col=0;col<10;col++)
					if(nav1[lin][col]=='S'&&tir2[lin][col]=='X')
						cont=cont+1;
			if(cont==3)
			{
				for(lin=0;lin<10;lin++)		
					for(col=0;col<10;col++)
						if(nav1[lin][col]=='S')
							tir2[lin][col]='A';
				navafund2=navafund2+1;
			}
							
			cont=0;
			for(lin=0;lin<10;lin++)		
				for(col=0;col<10;col++)
					if(nav1[lin][col]=='D'&&tir2[lin][col]=='X')
						cont=cont+1;
			if(cont==2)
			{
				for(lin=0;lin<10;lin++)		
					for(col=0;col<10;col++)
						if(nav1[lin][col]=='D')
							tir2[lin][col]='A';
				navafund2=navafund2+1;
			}
			
			printf("jogador 2\n");
			mostratabuleiro(nav2);
			printf("\n");
			printf("tabuleiro de tiros do jogador 2\n");			
			mostratabuleiro(tir2);
			printf("Navios Afundados = %d\n\n",navafund2);
			
			if(navafund2==5)
			{
				afundoutudo=1;
				printf("O jogador 2 e o vencedor\n");
			}
					
		}
			
		
	}
	
}