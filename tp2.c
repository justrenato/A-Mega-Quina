#include <stdio.h>
#include <stdlib.h>
#include <time.h>//preciso função para gerar aleatorios

#define numAposta 5

void gerarAleatorios(int tammax){
	int vetor[tammax+1],maior,aposta[numAposta+1];

	printf("Digite o valor maximo que sera sorteado (minimo 1):\n");
	scanf("%d",&maior);
	while(maior<1){
		printf("Digite o valor maximo que sera sorteado (minimo 1):\n");
		scanf("%d",&maior);
	}

	for (int i = 1; i < tammax +1; ++i)
	{
		vetor[i] = rand()% maior;
		printf("vet[%d]: %d\n",i,vetor[i] );
	}

	for (int i = 1; i < numAposta+1; ++i)
	{
		printf("Digite o %d numero que deseja apostar (de 0 até %d)\n",i,maior );
		scanf("%d",&aposta[i]);
		while((aposta[i]<0)||(aposta[i]>maior)){
			printf("Digite o %d numero que deseja apostar (de 0 até %d)\n",i,maior );
			scanf("%d",&aposta[i]);
		}
	}

	for (int i = 1; i < numAposta+1; ++i)
	{
		printf("numero apostado: %d\n",aposta[i] );
	}


}



int main(int argc, char const *argv[])
{
	int tammax;
	
	printf("Digite o tamanho do vetor (minimo 1):\n");
	scanf("%d",&tammax);
	while(tammax<1){
		printf("Digite o tamanho do vetor (minimo 1):\n");
		scanf("%d",&tammax);
	}

	srand(time(NULL));
	gerarAleatorios(tammax);
	return 0;
}