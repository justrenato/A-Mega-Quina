#include <stdio.h>
#include <stdlib.h>
#include <time.h>//preciso função para gerar aleatorios

#define numAposta 5
#define vetMax 10000

#define infoVetor
#define infoPesqSeq
#define infoPesqBin

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
	}

	#ifdef infoVetor
		printf("\nVetor gerado: %d,",vetor[1] );
		for (int i = 2; i < tammax; ++i)
		{
			printf(" %d,",vetor[i] );
		}
		printf(" %d.\n\n",vetor[tammax] );
	#endif
}

void lerAposta(int maior,int aposta[]){
	/* Ler os numeros que serão apostados*/
	for (int i =0; i < numAposta; ++i)
	{
		printf("Digite o %d° numero que deseja apostar na faixa de 1 até %d\n",i+1,maior );
		scanf("%d",&aposta[i]);
		while((aposta[i]<1)||(aposta[i]>maior)){
			printf("Digite o %d° numero que deseja apostar na faixa de 1 até %d\n",i+1,maior );
			scanf("%d",&aposta[i]);
		}
	}

	/*esse bloco imprime os numeros apostados no formato: Numero apostado: 1, 2, 3, 4, 5. */
	printf("\nNumeros apostados: %d,",aposta[0]);
	for (int i = 1; i < numAposta-1; ++i)
	{
		printf(" %d,",aposta[i]);
	}
	printf(" %d.\n",aposta[numAposta-1] );
}

void pesqSeq(int tammax, int aposta[], int vetor[]){
	int j=1, encontrado=0;
	int comps[numAposta],achado[numAposta];
	
	for (int i = 0; i < numAposta; ++i)
	{
		comps[i]=0;
		achado[i]=0;
		while ((j<= tammax)&&(achado[i]!=1))
		{
			if (aposta[i]==vetor[j])
			{
				achado[i]=1;
			} 
			comps[i]++;
			j++;
		}
		j=1;
	}

	#ifdef infoPesqSeq	
		printf("\nPESQUISA SEQUENCIAL RESULTADOS: \n\n");
		for (int i = 0; i < numAposta; ++i)
		{
			printf("\tElemento: %d. comparações: %d. Encontrado: %d.\n",aposta[i],comps[i],achado[i] );
		}
	#endif
}

void selectSort(int tammax, int vetor[], int vetorOrden[]){
	int min,aux,comps=0,movs=0;
	for (int i = 1; i <= tammax; ++i)
	{
		vetorOrden[i]=vetor[i];
	}

	for (int i = 1; i < tammax; ++i)
	{
		min = i;

		for (int j = i+1; j <= tammax; ++j){
			if (vetorOrden[j]<vetorOrden[min]) min = j;
			comps++;
		}

		aux=vetorOrden[min];
		vetorOrden[min] = vetorOrden[i];
		vetorOrden[i] = aux;
		movs++;
	}

	#ifdef infoPesqBin
		printf("\tSELECTSORT:\n");
		printf("\t\tVetorOrdenado: %d,",vetorOrden[1] );
		for (int i = 2; i < tammax; ++i)
		{
			printf(" %d,",vetorOrden[i]);
		}
		printf(" %d.\n",vetorOrden[tammax] );
		printf("\t\tNumero de comparações: %d.\n",comps);
		printf("\t\tNumero de movimentações: %d.\n",movs);
	#endif
}

void bubbleSort(int tammax, int vetor[], int vetorOrden[]){
	int aux,comps=0,movs=0;
	for (int i = 1; i <= tammax; ++i)
	{
		vetorOrden[i]=vetor[i];
	}

	for (int i = 2; i <= tammax; ++i)
	{
		for (int j = tammax; j >= i; --j)
		{
			if (vetorOrden[j]<vetorOrden[j-1])
			{
				aux = vetorOrden[j];
				vetorOrden[j] = vetorOrden[j-1];
				vetorOrden[j-1] = aux;
				movs++;
			}
			comps++;
		}
	}

	#ifdef infoPesqBin
		printf("\n\tBUBBLESORT:\n");
		printf("\t\tVetorOrdenado: %d,",vetorOrden[1] );
		for (int i = 2; i < tammax; ++i)
		{
			printf(" %d,",vetorOrden[i]);
		}
		printf(" %d.\n",vetorOrden[tammax] );
		printf("\t\tNumero de comparações: %d.\n",comps);
		printf("\t\tNumero de movimentações: %d.\n",movs);
	#endif
}


void mergeSort(int tammax, int vetor[], int vetorOrden[], int esq, int dir){
	// int comps=0,movs=0;
	// int meio,vetAux[tammax];
	
	// for (int i = 1; i <= tammax; ++i)
	// {
	// 	vetorOrden[i]=vetor[i];
	// }

	// #ifdef infoPesqBin
	// 	printf("\n\tMERGESORT:\n");
	// 	printf("\t\tVetorOrdenado: %d,",vetorOrden[1] );
	// 	for (int i = 2; i < tammax; ++i)
	// 	{
	// 		printf(" %d,",vetorOrden[i]);
	// 	}
	// 	printf(" %d.\n",vetorOrden[tammax] );
	// 	printf("\t\tNumero de comparações: %d.\n",comps);
	// 	printf("\t\tNumero de movimentações: %d.\n",movs);
	// #endif
}


int binsearch (int vetorOrden[], int elemento, int tammax, int *comps)
{
     int esq = 1;    
     int dir = tammax;
     int meio;
     while (esq <= dir)
     {
          meio = (esq + dir)/2;
          *comps=*comps+1;
          if (elemento == vetorOrden[meio])
               return 1;
          if (elemento < vetorOrden[meio])
               dir = meio-1;
          else
               esq = meio+1;
     }
     return 0;   // não encontrado
}

void pesqBin(int tammax, int aposta[], int vetor[]){
	int vetorOrden[tammax]; //vetor ordenado criado dentro da função pois só sera usado aqui.
	int comps[numAposta],achado[numAposta];
	for (int i = 0; i < numAposta; ++i)
	{
		comps[i]=0;
	}
	#ifdef infoPesqBin
		printf("\nPESQUISA BINARIA RESULTADOS: \n\n");
	#endif
	
	selectSort(tammax,vetor,vetorOrden);
	bubbleSort(tammax,vetor,vetorOrden);
	mergeSort(tammax,vetor,vetorOrden,1,tammax);

	for (int i = 0; i < numAposta; ++i)
	{
		achado[i]=binsearch(vetorOrden,aposta[i],tammax,&comps[i]);
	}

	#ifdef infoPesqBin
		printf("\n");
		for (int i = 0; i < numAposta; ++i)
		{
			printf("\tElemento: %d. comparações: %d. Encontrado: %d.\n",aposta[i],comps[i],achado[i] );
		}
	#endif
}

int main()
{
	int tammax; // tamanho maximo do vetor
	int maior; // maior numero que podera ser sorteado 
	int vetor[vetMax]; // vetor que guarda os numeros aleatorios gerados
	int aposta[numAposta]; // vetor que guarda os numeros apostados pelo usuario

	int continuar=1;

	srand(time(NULL));
	
	while(continuar){
		lerDados(&tammax,&maior);
		gerarAleatorios(tammax,maior,vetor);
		lerAposta(maior,aposta);
		pesqSeq(tammax,aposta,vetor);
		pesqBin(tammax,aposta,vetor);
		printf("\nDESEJA JOGAR NOVAMENTE? (1- sim. 0- não.)\n");
		scanf("%d",&continuar);
		while((continuar!=0)&&(continuar!=1)){
			printf("\nDESEJA JOGAR NOVAMENTE? (1- sim. 0- não.)\n");
			scanf("%d",&continuar);			
		}
	}
	return 0;
}