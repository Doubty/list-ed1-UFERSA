#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 3
#define flag_ok 1 
#define flag_erro 0

typedef struct sDado{
   char nome[30]; 
   float valor; 
	
}tDado;

typedef struct sFila{
	 
	 tDado vetor[MAX];
	 int inicio; 
	 int fim;
	 
}tFila;


int inserir(tFila * fila, tDado dado){
	
	int fimTemp = (fila->fim+1) % MAX; 
	
	if(fila->inicio == fimTemp){
		printf("Fila estah cheia"); 
		return flag_erro; 
		
	}else{
		
		fila->vetor[fimTemp] = dado; 
		fila->fim = fimTemp; 
		
		if(fila->inicio == -1){
		     
		     fila->inicio =0;
			
		}
	}
	
	return flag_ok;
	
}

int remover(tFila * fila, tDado * retorno){
	
	if(fila->inicio == -1){
		printf("Fila estah vazia"); 
		return flag_erro;
		
	}else{
		
		*retorno = fila->vetor[fila->inicio]; 
		
		if(fila->inicio == fila->fim){
			fila->inicio = -1; 
			fila->fim = -1;
		}else{
			
			fila->inicio = (fila->inicio+1) % MAX;
		}
		
	}
	
	return flag_ok;
}

void exibir(tFila fila){
	
	 printf("\nExibir... \n");
    int i = fila.inicio;

    while(i != fila.fim)
    {
        printf("Pos: %d nome: %s valor: %.2f \n", i, fila.vetor[i].nome, fila.vetor[i].valor );
        i++;
        
        i = i % MAX;
    }
      printf("Pos: %d nome: %s valor: %.2f \n", i, fila.vetor[i].nome, fila.vetor[i].valor );
	
}






int main(){
	
    tFila fila; 
    fila.inicio = -1; 
    fila.fim = -1; 
    
    
    	tDado dado;
	dado.valor = 10.0;
    inserir(&fila, dado);
    
	dado.valor = 20.0;
    inserir(&fila, dado);
    
    exibir(fila);
    
    remover(&fila, &dado);
    exibir(fila);
    
	
	
	
	system("pause"); 
	return 0;
}
