#include <stdio.h>
#include <stdlib.h> 
#define MAX 5

typedef struct sDado{
	
	int id;
	char nome[30];
	
}tDado;

void selectSort(tDado * vector, int size);

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
	
	exibir(vector, MAX); 
	printf("\n");
	
	selectSort(vector, MAX);
	
	exibir(vector, MAX); 
	printf("\n");
	
	
	system("pause"); 
	return 0;
}


void selectSort(tDado * vector, int size){
	
int i,j,menor; 
tDado aux; 

for(i=0; i<size;i++){
	
	menor = i;
	
	for(j = i+1; j<size;j++){
		
		if(vector[j].id < vector[menor].id){
			
			menor = j;
		}
		
	}
	
	if(i != menor){
		
		aux = vector[i]; 
		vector[i] = vector[menor]; 
		vector[menor] = aux;
		
	}
	
}
	
}



void exibir(tDado * vector, int size){
	
	int i;
	for(i=0; i<size; i++){
		
		printf("ID %d ", vector[i].id);
		
	}
	
}
