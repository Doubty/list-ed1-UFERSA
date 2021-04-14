#include <stdlib.h>
#include <stdio.h>
#define MAX 4
#define FLAG_FAIL 0
#define FLAG_OK 1

// Prof: Bruno Monteiro
// Objetivo: fila simples.

//--------------------------------------------
// inserir
//--------------------------------------------

int inserir(int* fila, int* inicio, int* fim, int valor)
{
    int fimTemp = (*fim + 1) % MAX;

    if (fimTemp == *inicio) {
       printf("ERRO: Fila cheia!!! \n");
       return FLAG_FAIL;
    }

    *fim = fimTemp;
    fila[*fim] = valor;

	// Bloco executado apenas quando 1o elemento eh inserido
    if (*inicio == -1) { 
        *inicio = 0;
    }
    
    
    return FLAG_OK;
}

//--------------------------------------------
// remover
//--------------------------------------------
int remover(int* fila, int* inicio, int* fim, int* retorno)
{
    if (*inicio == -1) {
    	printf("ERRO: Fila vazia!!! \n");
        return FLAG_FAIL;
    }

    *retorno = fila[*inicio];
    
    if (*inicio == *fim) {
        // Bloco executado apenas quando a função estiver removendo o ultimo elemento da fila
        *inicio = -1;
        *fim = -1;
    }
    else {
      *inicio = (*inicio + 1) % MAX;
    }
    


   return FLAG_OK;
}

//--------------------------------------------
// exibir
//--------------------------------------------
void exibir(int *fila, int inicio, int fim)
{
    printf("Exibir... \n");
    
    int cont = inicio;

    while(cont != fim)
    {
        printf(" posicao %d = %d \n", cont, fila[cont] );
        cont++;

        if (cont == MAX) {
            cont = 0;
        }
    }
    
    printf(" posicao %d = %d \n", cont, fila[cont]);
	printf(" inicio = %d    fim = %d \n\n", inicio, fim);
}

//--------------------------------------------
// MAIN
//--------------------------------------------
int main()
{
	// Inicializo Fila
    int fila1[MAX];
    int inicio = -1; // variavel de controle deslocado quando há "remoção" de elemento.
    int fim = -1;	 // variavel de controle deslocado quando há "inserção" de elemento.

    inserir(fila1, &inicio, &fim, 3);
    inserir(fila1, &inicio, &fim, 5);
    inserir(fila1, &inicio, &fim, 7);
    inserir(fila1, &inicio, &fim, 9);  
   
    
    

    exibir(fila1, inicio, fim);


	system("pause");
    return 0;
}
