#include <stdio.h>
#include <stdlib.h>
#include <time.h>//preciso função para gerar aleatorios

#define numAposta 5
#define vetMax 10000

void lerDados(int *tammax, int *maior){
	/*Ler o tamanho do vetor, e o maior numero que sera possivel gerar aleatoriamente*/
	printf("Digite o tamanho do vetor (min 1, max %d):\n",vetMax);
	scanf("%d",tammax);
	while((*tammax<1)||(*tammax>vetMax-1)){
		printf("Digite o tamanho do vetor (min 1, max %d):\n",vetMax);
		scanf("%d",tammax);
	}

	printf("Digite o valor maximo que podera ser sorteado (minimo 1):\n");
	scanf("%d",maior);
	while(*maior<1){
		printf("Digite o valor maximo que podera ser sorteado (minimo 1):\n");
		scanf("%d",maior);
	}
}


void gerarAleatorios(int tammax, int maior,int vetor[]){
	for (int i = 1; i <= tammax; ++i)
	{
		vetor[i] = (rand()% maior)+1;
		printf("vet[%d]: %d\n",i,vetor[i] );
	}
}

void lerAposta(int maior,int aposta[]){
	/* Ler os numeros que serão apostados*/
	for (int i =0; i < numAposta; ++i)
	{
		printf("Digite o %d° numero que deseja apostar (de 1 até %d)\n",i,maior );
		scanf("%d",&aposta[i]);
		while((aposta[i]<1)||(aposta[i]>maior)){
			printf("Digite o %d° numero que deseja apostar (de 1 até %d)\n",i,maior );
			scanf("%d",&aposta[i]);
		}
	}
	for (int i = 0; i < numAposta; ++i)
	{
		printf("numero apostado: %d\n",aposta[i] );
	}
}

void procurarElementos(int tammax, int aposta[], int vetor[]){
	int j=1, encontrado=0;
	int compSeq[numAposta],achadoSeq[numAposta];
	
	/*PESQUISA SEQUENCIAL*/
	for (int i = 0; i < numAposta; ++i)
	{
		compSeq[i]=0;
		achadoSeq[i]=0;
		while ((j<= tammax)&&(achadoSeq[i]!=1))
		{
			if (aposta[i]==vetor[j])
			{
				achadoSeq[i]=1;
			} 
			compSeq[i]++;
			j++;
		}
		j=1;
	}

	for (int i = 0; i < numAposta; ++i)
	{
		printf("elemento: %d. comparações: %d. Encontrado: %d.\n",aposta[i],compSeq[i],achadoSeq[i] );
	}
}

int main()
{
	int tammax; // tamanho maximo do vetor
	int maior; // maior numero que podera ser sorteado 
	int vetor[vetMax]; // vetor que guarda os numeros aleatorios gerados
	int aposta[numAposta]; // vetor que guarda os numeros apostados pelo usuario

	srand(time(NULL));
	lerDados(&tammax,&maior);
	gerarAleatorios(tammax,maior,vetor);
	lerAposta(maior,aposta);
	procurarElementos(tammax,aposta,vetor);
	return 0;
}