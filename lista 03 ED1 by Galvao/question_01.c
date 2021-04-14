#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#define MAX 5

typedef struct sDado{
	int id; 
	char nome[30]; 
	
}tDado;

int linearSearch(tDado * vector, int size, int valor);


int main(){
	
	tDado aux; 
	tDado vector [MAX];
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
	
	
	
   int result= 	linearSearch(vector, MAX, 5);
   printf("Valor: %d Nome: %s Position: %d \n",vector[result].id, vector[result].nome, result);
	
	system("pause"); 
	return 0;
}

// A função retorna a posição de um determinado valor recebido
int linearSearch(tDado * vector, int size, int valor){
	
	int i;
	
	for(i =0; i<size; i++){
		
		if(vector[i].id == valor){
			return i;
		}
		
	}
	
	return -1;
}
