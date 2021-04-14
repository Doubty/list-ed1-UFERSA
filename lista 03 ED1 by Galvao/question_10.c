#include <stdlib.h>
#include <stdio.h> 
#include <windows.h>
#define MAX 5


typedef struct sDado{
	
	int id; 
	char nome[30];
	
}tDado;

void quickSort(tDado * vector, int start, int final);

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
	
	quickSort(vector, 0, MAX-1);
	
	exibir(vector, MAX); 
	
	
	system("pause"); 
	return 0;
}


void quickSort(tDado * vector, int start, int final){
	
 int i =0;
 int j = final;
 int pivo; 
 tDado aux; 
  
  pivo = vector[(start+final)/2].id;
  
  while(i < j){
  	
  	while(vector[i].id < pivo){
  		 
  		 i++;
	  }
	  
	  while(vector[j].id > pivo){
	  	j--;
	  	
	  }
	  
	  if(i <= j){
	  	
	  	aux = vector[i]; 
	  	vector[i] = vector[j]; 
	  	vector[j] = aux;
	  	i++;
	  	j--;
	  	
	  }
  	
  }
  
  if(j > start){
  	
  	quickSort(vector, start,j);
  	 
  }
  
  if(i < final){
  	
  	quickSort(vector, i, final);
  }
	
}


void exibir(tDado * vector, int size){
	
	
	int i;
	for(i=0; i<size; i++){
		
		printf("ID %d ", vector[i].id);
		
	}
	
}
