#include <stdio.h>
#include <stdlib.h> 
#define MAX 5

typedef struct sDado{
	
	int id; 
	char nome[30];
	
}tDado;



void shellSort(tDado * vector, int size);

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
	
	shellSort(vector, MAX);
	
	exibir(vector, MAX); 
	
	
	system("pause"); 
	return 0;
}


void shellSort(tDado * vector, int size){
	
	int i, j, h =0; 
	tDado eleito; 
	
	while(h < size){
		h = 3 * h+1; 
	}
	
	while(h >1){
		
		h = h/3; 
		
		for(i =h; i<size;i++){
			
			eleito = vector[i]; 
			j = i-h; 
			
			while(j >=0 && eleito.id < vector[j].id){
				vector[j+h] = vector[j]; 
				j = j-h; 
				
			}
			
			vector[j+h] = eleito;
			
		}
		
	}
}

void exibir(tDado * vector, int size){
	
	
	int i;
	for(i=0; i<size; i++){
		
		printf("ID %d ", vector[i].id);
		
	}
	
}





