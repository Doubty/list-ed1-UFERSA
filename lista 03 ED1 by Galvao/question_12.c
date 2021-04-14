#include <stdio.h> 
#include <stdlib.h> 
#include <windows.h>
#include <conio.h>
#include <time.h>
#define MAX 10000


void showVector(int * vector, int size);
void bubbleSort(int * vector, int size);
void fillVector(int * vector, int size);
void insertSort(int * vector, int size);
void selectSort(int * vector, int size);
void quickSort(int * vector, int start, int final);
void shellSort(int * vector, int size);



int main(){
	
	int vector[MAX];
	int vector1[MAX];
	int vector2[MAX];
	int vector3[MAX];
	int vector4[MAX];
	
	int start, final, result;
	
	fillVector(vector, MAX);

	
	printf("\nTestes: ");
	
	printf("\nBubbleSort: \n");
	start = clock();
	bubbleSort(vector,MAX);
	final = clock();
	result = final - start; 
	printf("\nTime: %d \n", result);
    printf("\n\n");
    
	fillVector(vector1, MAX);
	printf("\nInsertSort: \n");
	start = clock();
	insertSort(vector1,MAX);
	final = clock();
	result = final - start; 
	printf("\nTime: %d \n", result);
     printf("\n\n");
     
    fillVector(vector2, MAX);
	printf("\nSelectSort: \n");
	start = clock();
	selectSort(vector2,MAX);
	final = clock();
	result = final - start; 
	printf("\nTime: %d \n", result);
    
    printf("\n\n");
    fillVector(vector3, MAX);
	
	printf("\nQuicktSort: \n");
   	start = clock();
	quickSort(vector3, 0,MAX-1);
	final = clock();
	result = final - start; 
	printf("\nTime: %d \n", result);
     printf("\n\n");
    
   	fillVector(vector4, MAX);
	
	printf("\nShellSort: \n");
	start = clock();
	shellSort(vector4,MAX);
	final = clock();
	result = final - start; 
	printf("\nTime: %d \n", result);
    printf("\n\n");
	system("pause"); 
	return 0;
}

void showVector(int * vector, int size){
	int i; 
	for(i=0; i<size; i++){
		
		printf(" %d ", vector[i]);
		
	}
	
	
}

void fillVector(int * vector, int size){
	int i; 
	for(i=0; i<size; i++){
		
	 vector[i] = rand() % 100;
		
	}
	
	
}


void bubbleSort(int * vector, int size){
	
	int i,j,aux; 
	
	for(i=0; i<size-1; i++){
		for(j=0; j<size-1;j++){
			
			if(vector[j] > vector[j+1]){
				aux = vector[j]; 
				vector[j] = vector[j+1]; 
				vector[j+1] = aux;
			}
			
		}
		
	}
	
}

void insertSort(int * vector, int size){
	
	int i, j,eleito; 
	
	for(i=1; i <size; i++){
		
		eleito = vector[i]; 
		
		j = i-1;
		
		while(j>= 0 && eleito < vector[j]){
			
			vector[j+1] = vector[j]; 
			j--;
			
		}
		
		vector[j+1] = eleito;
		
	}
	
}

void selectSort(int * vector, int size){
	
	int i,j, menor, aux;
	
	for(i =0; i<size; i++){
		
		menor =i; 
		
		for(j=i+1; j<size; j++){
			
			if(vector[j] < vector[menor]){
				
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

void quickSort(int * vector, int start, int final){
	
	int i = start; 
	int j = final; 
	int pivo =0; 
	int aux;
     
     
     pivo = vector[(start+final)/2];
     while(i < j){
     	
     	while(vector[i] < pivo){
     		i++;
     		
		 }
		 
		 while(vector[j] > pivo){
		 	j--;
		 	
		 }
		 
		 if(i <=j){
		 	aux = vector[i]; 
		 	vector[i] = vector[j]; 
		 	vector[j] = aux;
		 	i++; 
		 	j--;
		 	
		 }
     	
     	
	 }
	 
	 if(j >start){
	 	
	 	quickSort(vector, start, j);
	 	
	 }
	 
	 if(i < final){
	 	
	 	quickSort(vector, i, final);
	 }
	 
}

void shellSort(int * vector, int size){
	
	int i, j, h, aux, eleito; 
	
    while(h < size){
    	
    	h = 3 *h+1;
    	
	}
	
	while(h >1){
		
		h = h/3;
		
		for(i=h; i<size; i++){
			
		 eleito = vector[i];	
		 	
		 	j = i-h;
		 	
		 	while(j>=0 && eleito < vector[j]){
		 		
		 		vector[j+h] = vector[j]; 
		 		j = j-h;
		 		
			 }
			 
			 vector[j+h] = eleito;
			
		}
	
		
	}
	
	
}






