#include <stdlib.h>
#include <stdio.h>
#define flag_fail 0 
#define flag_ok 1 
#define MAX 4 


typedef struct sFila{
	 int fila[MAX];
	 int inicio;
	 int fim;
	
} tFila;

int inserir(tFila * fila, int valor){
	  
	  int fimTemp = (1+ fila->fim) % MAX; 
	  
	  if(fimTemp == fila->inicio){
	  	printf("Erro: Pilha cheia \n"); 
	  	return flag_fail; 
	  }
	  
	  fila->fim = fimTemp; 
	  fila->fila[fila->fim] = valor; 
	  
	  if(fila->inicio == -1){
	  	 fila->inicio = 0;
	  }
	  
	  return flag_ok;

}




int remover(tFila * fila, int * retorno ){
	  
     if(fila->inicio == -1){
     	printf("Erro: fila vazia \n");
     	return flag_fail;
	 }
	 
	*retorno =  fila->fila[fila->inicio];
	
	if(fila->inicio == fila->fim){
		fila->inicio = -1;
		fila->fim = -1;
	}else{
		
		fila->inicio = (1+fila->inicio) % MAX;
	}
	 
	 return flag_ok;
	  
}

void exibir(tFila * fila){
	 
	 int count = fila->inicio; 
	 
	 while(count != fila->fim){
	 	
	 	
	 	printf("%d \n", fila->fila[count]);
	 	count++; 
	 	
	 	if(count == MAX){
	 		count =0;
		 }
	 }
	 
	printf("%d", fila->fila[count]);
	 

}

tFila inicializarFila(){
	
	
     tFila fila; 
     fila.fim = -1; 
     fila.inicio = -1; 
     
     return fila;
}

int main(){
	

    tFila fila1 = inicializarFila();
	
    inserir(&fila1, 3);
    inserir(&fila1, 5);
    inserir(&fila1, 7);
    inserir(&fila1, 9);  
    
    exibir(&fila1);
    
    inserir(&fila1, 12);  // vai dar erro!!!

    
	
	system("pause"); 
	return 0;
}
