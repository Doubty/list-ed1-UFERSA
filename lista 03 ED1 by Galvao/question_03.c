#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#define MAX 10


typedef struct sDado{
	
	int id;
	char nome[30];
	
}tDado;

int binarySearch(tDado * vector, int size, int valor);


int main(){
	
	tDado aux;
	tDado vector[MAX];
	
	aux.id = 3; 
	strcpy(aux.nome, "galvao");
	vector[0] = aux;
	
	aux.id = 1; 
	strcpy(aux.nome, "Joao"); 
	vector[1] = aux;
	
	aux.id = 5; 
	strcpy(aux.nome, "Leandro");
	vector[2] = aux;
	
	aux.id = 8; 
		strcpy(aux.nome, "Carlos");
	vector[3] = aux;
	
	aux.id = 25; 
	strcpy(aux.nome, "Joana");
	vector[4] = aux;
	
	
	
	int result = binarySearch(vector, MAX, 25);
	
	 printf("Valor: %d Nome: %s Position: %d \n",vector[result].id, vector[result].nome, result);
	
	
	system("pause"); 
	return 0;
}


int binarySearch(tDado * vector, int size, int valor){
	
  int middle = 0; 
  int start =0; 
  int final= size-1; 
  int result = -1; 
  
  
  
  while(start<=final){
  	
  	middle = (start+final)/2;
  	
  	if(valor < vector[middle].id){
  		
  		final = middle-1; 
  		
	  }else if(valor > vector[middle].id){
	  	
	  	start = middle+1;
	  	
	  }else{
	  	
	  	start = size;
	  	result = middle;
	  	
	  }
  	
  	
  }
  
  return result;
	
	
}

