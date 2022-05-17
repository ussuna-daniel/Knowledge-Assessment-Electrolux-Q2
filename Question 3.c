#include <stdio.h>
#include <stdlib.h>
 
int vetor[] = {2,3,5,7,10,15,18,50,100,103};

int tamanho_vetorOriginal, tamanho_vetorNovo, max, min;
float somatorio, media;
int i;

// Deve retornar valor MÉDIO, MÁXIMO e MÍNIMO além de um Vetor com Valores PARES e o TAMANHO do novo Vetor
int* Analise_Vetor(int array[], int tam_v) 
{
int tam_Nv, n = 0;
int array_Par[tam_v];
int array_resultado[(tam_v+4)];
		
for(i = 0; i < tam_v; i++)
	{
	if(array[i]%2 == 0) 
		{
		array_Par[n] = array[i];	 
		printf("ARRAY Par[%d]: %d \n", n, array_Par[n]);
		n++;
		}
	}

tam_Nv = n;
somatorio = 0;
max = array[0];
min = max;
 	
for(i = 0; i < tam_v; i++)
	{
	somatorio = somatorio + array[i];
	if(array[i] >= max) max = array[i];
	if(array[i] <= min) min = array[i];
	}
	media = somatorio/tam_v;

	printf("Func Media: %.2f \n", media);
	printf("Func Maximo: %d \n", max);
	printf("Func Minimo: %d \n", min);
	printf("Func Tamanho do Vetor Par: %d \n", tam_Nv);
	
	
	array_resultado[0] = media;
	array_resultado[1] = max;
	array_resultado[2] = min;
	array_resultado[3] = tam_Nv;
	
for(i = 4; i < (tam_Nv+4); i++)
	{
		array_resultado[i] = array_Par[i-4];
	}
	
	return array_resultado; // {media, max, min, tam_Nv, array_Par}
}

int main() {
	int* ptr;  
	int tam_ptr;
	printf("Vetor de Entrada\n");
	tamanho_vetorOriginal = sizeof(vetor)/sizeof(vetor[0]);
	for(i = 0; i < tamanho_vetorOriginal; i++)
	{
		printf("VETOR[%d]: %d \n", i, vetor[i]);
		
	}	
	
	printf("\n------------------------\nResultados\n");
	
	ptr = Analise_Vetor(vetor, tamanho_vetorOriginal );
	
	tam_ptr = sizeof(ptr)/sizeof(ptr[0]);
	
	printf("\n\n\nMain Media: %d \n", ptr[0]);
	printf("Main Maximo: %d \n", ptr[1]);
	printf("Main Minimo: %d \n", ptr[2]);
	printf("Main Tamanho do Vetor Par: %d \n", ptr[3]);


	for(i = 4; i < tam_ptr; i++)
	{
		printf("Main Vetor Par[%d]: %d \n", i, ptr[i]);
		
	}
	
	
	system("pause");
	
	return 0;
}


