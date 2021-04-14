
#include<stdio.h>
#include<stdlib.h>
// size = tamanho da tabela
#define SIZE 7 
                

int ht_insert(int *hashtable, int *empty,  int key);
                
int main(){
	
  int hashtable[SIZE]; // criando a tabela hash
  int empty[SIZE] = {0}; // inicializando todos os elementos do array para zero
  
  int i;
  for(i=0; i<SIZE; i++){
    ht_insert(hashtable, empty, i);
  }
  
  for(i=0; i<SIZE; i++){
    printf("%d ", hashtable[i]);
  }
  
  
  
  return 0;
}
  
       
int ht_insert(int *hashtable, int *empty,  int key){
  
  int i, index;// index é o valor da função da tabela hash
  
  for( i=0; i<SIZE; i++){
    index = (key + i * i)% SIZE;
    if(empty[index] == 0){
      
      //insere a chave naquele index
      hashtable[index] = key;
      
      //marca a posição que tem sido pegada usando o vetor empty
      empty[index] = -1;
      return index;
    }
    
  }
  
  return -1;
}      



