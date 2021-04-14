#include <stdio.h>
#include <stdlib.h>
#define MAX 3
#define OK 1
#define FAIL 0


int empilhar(int * pilha, int * topo, int valor){
	 
	 int flag = OK; 
	 
	 if(*topo == MAX-1){
	 	printf("Erro. A pilha estar cheia"); 
	 	flag = FAIL; 
	 	
	 }else{
	 	
	 	*topo = *topo+1; 
	 	pilha[*topo]= valor; 
	 }
	 
	 return OK;
	 
}


int desempilhar(int * pilha, int * topo, int * retorno){
	 
	 int flag = OK; 
	 
	 if(*topo == -1){
	 	printf("Erro. A pilha estar vazia"); 
	 	flag = FAIL; 
	 	
	 }else{
	 	
	 	
	 	*retorno = pilha[*topo];
	 	*topo = *topo-1; 
	
	 }
	 
	 return OK;
	 
}

void exibir(int * pilha, int * topo){
	 
	 int i;
	 for(i=0; i<=*topo; i++){
	 	
	 	printf(" %d ", pilha[i]);
	 }
	 
}

int main(){
	
	int pilha[MAX];
	int topo = -1; 
	int retorno =0;
	
	empilhar(pilha, &topo, 10);
	empilhar(pilha, &topo, 5);
	empilhar(pilha, &topo, 3);
			
	exibir(pilha, &topo);
			
	desempilhar(pilha, &topo, &retorno);
	
	printf("\n");
	exibir(pilha, &topo);
	printf("\n");
	
	
	system("pause"); 
	return 0;
}


