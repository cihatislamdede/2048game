#include<stdio.h>
#define SIZE 5
#include<time.h>

int main (){
	
	int i,j,k,satir,sutun,exit,tmp,v,hamleyap;
	int screen[SIZE][SIZE];
	int puan = 0;
	
	for(i=0;i<SIZE;i++){
		for(j=0;j<SIZE;j++){
			screen[i][j]=0;
		}
	}
		
	printf("\t\t ===== SCREEN ===== \t\t\n");

	for(i=0;i<SIZE;i++){
		printf("\t\t");
		for(j=0;j<SIZE;j++){
			printf("  %d ",screen[i][j]);
		}
		printf("\n");
	}
	printf("\t\t ------------------\t\t\n");
	printf("\t\t\t\t\t SCORE: %d\n",puan);
	
	
	printf("NOT: 2-4-8 sayilari ile oynanacaktir.\n");
	printf("\t8= YUKARI -- 2= ASAGI -- 6= SAGA -- 4= SOLA\n");
	
	exit=0;
	
	int next_x_0, next_x_1, next_x_2;
	int next_y_0, next_y_1, next_y_2;
	srand(time(NULL));
	int next_x, next_y;
	next_x_0 = rand() % 5;
	next_y_0 = rand() % 5;
		
	next_x_1 = rand() % 5;
	next_y_1 = rand() % 5;
		
	next_x_2 = rand() % 5;
	next_y_2 =rand() % 5;
 		
	screen[next_x_0][next_y_0] = 2;
	screen[next_x_1][next_y_1] = 2;
	screen[next_x_2][next_y_2] = 4;
		
	while(exit == 0){

		for(i=0;i<SIZE;i++){
			printf("\t\t");
			for(j=0;j<SIZE;j++){
				printf("  %d ",screen[i][j]);
			}
			printf("\n");
		}
		printf("\t\t ------------------\t\t\n");
		printf("\t\t\t\t\t SCORE: %d\n",puan);
		
		
		printf("Yonu seciniz:\n");
		int yon;
		scanf("%d",&yon);
		
		while(yon!=2 && yon!=4 && yon!=6 && yon!=8){
		
			printf("Gecerli bir yon girmediniz. Lutfen tekrar giriniz!\n");
			scanf("%d",&yon);
		}
		
		
		
		if(yon==6){ // SAGA GOTURME (TAMAM)
					j=3;
					v=3;
					for(i=0;i<5;i++){
						while(j>=0){
							hamleyap=1;
							while(hamleyap>0 && j<4){
								hamleyap=0;
								while(screen[i][j] == screen[i][j+1] && screen[i][j]!=0 && j<4){
									screen[i][j+1]=2*screen[i][j];
									
									screen[i][j]=0;
									j++;
									hamleyap++;
									puan+=screen[i][j];
								}
								while(screen[i][j+1]==0 && screen[i][j]!=0 && j<4){
									screen[i][j+1]=screen[i][j];
									screen[i][j]=0;
									j++;
									hamleyap++;
								}
							}
							v--;
							j=v;
						}
						j=3;
						v=3;
					}				
		}
		if(yon==4){ // SOLA GOTURME (HATA)
					j=1;
					v=1;
					for(i=0;i<5;i++){
						while(j>=0 && j<5){
							hamleyap=1;
							while(hamleyap>0 && j>=0){
								hamleyap=0;
								while(screen[i][j] == screen[i][j-1] && screen[i][j]!=0 && j>0){
									screen[i][j-1]=2*screen[i][j];
									
									screen[i][j]=0;
									j--;
									hamleyap++;
									puan+=screen[i][j];
								}
								while(screen[i][j-1]==0 && screen[i][j]!=0 && j>0){
									screen[i][j-1]=screen[i][j];
									screen[i][j]=0;
									j--;
									hamleyap++;
								}
							}
							v++;
							j=v;
						}
						j=1;
						v=1;
					}				
		}
		
		if(yon==2){ // ASAGI GOTURME (TAMAM)
					i=3;
					v=3;
					for(j=0;j<5;j++){
						while(i>=0 &&  i<5){
							hamleyap=1;
							while(hamleyap>0 && i<4){
								hamleyap=0;
								while(screen[i][j] == screen[i+1][j] && screen[i][j]!=0 && i<4){
									screen[i+1][j]=2*screen[i][j];
									
									screen[i][j]=0;
									i++;
									hamleyap++;
									puan+=screen[i][j];
								}
								while(screen[i+1][j]==0 && screen[i][j]!=0 && i<4){
									screen[i+1][j]=screen[i][j];
									screen[i][j]=0;
									i++;
									hamleyap++;
								}
							}
							v--;
							i=v;
						}
						i=3;
						v=3;
					}				
		}
		
		if(yon==8){ // YUKARI GOTURME (TAMAM)
					i=1;
					v=1;
					for(j=0;j<5;j++){
						while(i>=0 &&  i<5){
							hamleyap=1;
							while(hamleyap>0 && i>=0){
								hamleyap=0;
								while(screen[i][j] == screen[i-1][j] && screen[i][j]!=0 && i<4){
									screen[i-1][j]=2*screen[i][j];
									screen[i][j]=0;
									i--;
									hamleyap++;
									puan+=screen[i][j];
								}
								while(screen[i-1][j]==0 && screen[i][j]!=0 && i>0){
									screen[i-1][j]=screen[i][j];
									screen[i][j]=0;
									i--;
									hamleyap++;
								}
							}
							v++;
							i=v;
						}
						i=1;
						v=1;
					}				
		}
		
		
		next_x = rand() % 5;
		next_y = rand() % 5;
		
		while(screen[next_x][next_y]!=0){
		
		next_x = rand() % 5;
		next_y = rand() % 5;
		}
		
		int choose = rand() % 2;
		
		if(choose == 0){
			screen[next_x][next_y] = 2;
		}
		else if (choose == 1){
			screen[next_x][next_y] = 4;
		}
			
		
		exit=1;
		for(i=0;i<SIZE;i++){
			for(j=0;j<SIZE;j++){
				if(screen[i][j]==0){
					exit = 0;
					j=SIZE;
					i=SIZE;
				}
				
			}
		
		}
		
		
		
	}
	
	
	
	return 0;
}
