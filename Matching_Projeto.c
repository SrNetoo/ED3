

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

/*
le arq1
le arq 2

se nome 1 do arq 1 < nome 1 do arq 2
le nome 2 do arq 1
senao se
	se nome1 do arq1 > nome1 arq2
	le nome2 do arq2
	senao se
		escreve nome 1 na saida


ele coloca o novo arquivo somente os dados iguais dos 2 arqs
*/



int main(){

	FILE *arq1;
	FILE *arq2;
	FILE *arq3;
	char vetorTeste1[345] = "00000000AUTOR1yyyyyyyyyyyyyyyyyyyyyyyyMUSICA1yyyyyyyyyyyyy00/00/0000\n11111111AUTOR2yyyyyyyyyyyyyyyyyyyyyyyyMUSICA3yyyyyyyyyyyyy00/00/0000\n33333333AUTOR3yyyyyyyyyyyyyyyyyyyyyyyyMUSICA5yyyyyyyyyyyyy00/00/0000\n44444444AUTOR4yyyyyyyyyyyyyyyyyyyyyyyyMUSICA12yyyyyyyyyyyy00/00/0000\n55555555AUTOR92yyyyyyyyyyyyyyyyyyyyyyyMUSICA19yyyyyyyyyyyy00/00/0000\n";
	char vetorTeste2[276] = "00000000AUTOR1yyyyyyyyyyyyyyyyyyyyyyyyMUSICA2yyyyyyyyyyyyy00/00/0000\n11111111AUTOR3yyyyyyyyyyyyyyyyyyyyyyyyMUSICA3yyyyyyyyyyyyy00/00/0000\n33333333AUTOR3yyyyyyyyyyyyyyyyyyyyyyyyMUSICA5yyyyyyyyyyyyy00/00/0000\n44444444AUTOR4yyyyyyyyyyyyyyyyyyyyyyyyMUSICA12yyyyyyyyyyyy00/00/1000\n";
	
	int result1;
	int result2;
	

	arq1 = fopen("arqteste1.txt", "wb");
	arq2 = fopen("arqteste2.txt", "wb");

	fwrite (&vetorTeste1[0], sizeof(char), 345,arq1 );

	fwrite (&vetorTeste2[0], sizeof(char), 276,arq2 );

	fclose(arq1);
	fclose(arq2);



	arq1 = fopen("arqteste1.txt", "rb");
	arq2 = fopen("arqteste2.txt", "rb");
	arq3 = fopen("arqteste3.txt", "wb");
	char buffer1;
	char buffer2;
	
	if(arq1 == NULL){
		printf("Arquivo vazio\n");
	}
	if(arq2 == NULL){
		printf("Arquivo vazio\n");
	}
	if(arq3 == NULL){
		printf("Arquivo vazio\n");
	}

	//fwrite (&vetorTeste1[0], sizeof(char), 6,arq3 );

	buffer1 = fgetc(arq1);
	buffer2 = fgetc(arq2);
	char aux[69];

	int posatual = 0;
	int origem = 0;
	int seek;
	seek = posatual + origem;
	//(buffer1 != EOF) || (buffer2 != EOF)
	//origem<70
	
  
//campo 2
	while(!feof(arq1) && !feof(arq2)){
		printf("buffer1 %c\n",buffer1 );
		printf("buffer2 %c\n",buffer2 );
		origem++;

		if(buffer1==buffer2){

			printf("buffers iguais\n");
			aux[posatual]=buffer1;
		
			if(posatual== 68){

				//memcpy(arq3[0],&aux[0],69);
				fwrite (&aux[0], sizeof(char), 69,arq3 );
				posatual = -1;
				}

			buffer1 = fgetc(arq1);
			buffer2 = fgetc(arq2);
			posatual ++;
			//origem ++;

			
		}
		else{
			if(buffer1<buffer2){
				printf("buffer1 < buffer2\n");
				for (int x=0;x<(69-posatual); x++)
			{
				buffer1 = fgetc(arq1);
		
			}
			//for (int i = 0;i<posatual;i++)
			//{
			//	buffer2 = - fgetc(arq2);
			//}
			fseek(arq2,(-posatual-1),SEEK_CUR) ;
			printf("buffer2 pos seek %c\n",buffer2 );
			buffer2 = fgetc(arq2);
			printf("buffer2 pos igualar %c\n",buffer2 );
			
		
		}
			else{
				if(buffer1>buffer2){
					printf("buffer2 < buffer1\n");
					for (int k=0;k<(69-posatual); k++)
					{
						buffer2 = fgetc(arq2);
	
					}

					//for (int i = 0;i<posatual;i++)
					//{
					//	buffer1= - fgetc(arq1);
					//}
					
					fseek(arq1,(-posatual-1),SEEK_CUR);
					printf("buffer1 pos seek %c\n",buffer1 );
					//rewind(arq1);
					buffer1 = fgetc(arq1);
					printf("buffer1 pos igualar %c\n",buffer1 );
			
					printf("%d\n",seek );
				}
				
			}
			
			
			posatual=0;

		}
	}
	





	fclose(arq1);
	fclose(arq2);
	fclose(arq3);



	return 0;
}
