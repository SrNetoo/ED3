
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
	char vetorTeste1[345] = "16541313AUTOR1yyyyyyyyyyyyyyyyyyyyyyyyMUSICA1yyyyyyyyyyyyy00/02/0513\n16541313AUTOR7yyyyyyyyyyyyyyyyyyyyyyyyMUSICA7yyyyyyyyyyyyy00/02/0513\n06746202AUTOR2yyyyyyyyyyyyyyyyyyyyyyyyMUSICA2yyyyyyyyyyyyy14/00/1606\n86096202AUTOR72yyyyyyyyyyyyyyyyyyyyyyyMUSICA59yyyyyyyyyyyy14/08/1606\n17096202AUTOR92yyyyyyyyyyyyyyyyyyyyyyyMUSICA19yyyyyyyyyyyy24/12/1783\n";
	char vetorTeste2[276] = "16541313AUTOR1yyyyyyyyyyyyyyyyyyyyyyyyMUSICA2yyyyyyyyyyyyy00/02/0513\n16541313AUTOR7yyyyyyyyyyyyyyyyyyyyyyyyMUSICA7yyyyyyyyyyyyy00/02/0513\n86096202AUTOR4yyyyyyyyyyyyyyyyyyyyyyyyMUSICA2yyyyyyyyyyyyy14/00/1606\n86096202AUTOR72yyyyyyyyyyyyyyyyyyyyyyyMUSICA59yyyyyyyyyyyy14/08/1606\n";
	
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
	
  
//campo 2
	while((buffer1 != EOF) || (buffer2 != EOF)){
		printf("%c\n%c\n", buffer1 , buffer2);

		if(buffer1==buffer2){

			printf("buffer iguais\n");
			aux[posatual]=buffer1;
			printf("guardado no buffer%d %c\n",posatual, aux[posatual] );

			if(posatual== 68){
				printf("fechou um registro\n");
				fwrite (&aux[0], sizeof(char), 69,arq3 );
				printf("\n");
				posatual = -1;
				

			}
			buffer1 = fgetc(arq1);
			buffer2 = fgetc(arq2);
			posatual ++;
			
		}
		else{
			printf("buffers diferentes\n");
			//buffer1 = fseek(arq1,sizeof(1-posatual), SEEK_CUR);
			//buffer2 = fseek(arq2,sizeof(1-posatual), SEEK_CUR);
			//buffer1 = (3-posatual)*fgetc(arq1);
			//buffer2 = (3-posatual)*fgetc(arq2);
			for (int x=0;x<(69-posatual); x++)
			{
				buffer1 = fgetc(arq1);
				buffer2 = fgetc(arq2);
			}
			posatual=0;

		}
	}
	



	fclose(arq1);
	fclose(arq2);
	fclose(arq3);



	return 0;
}
