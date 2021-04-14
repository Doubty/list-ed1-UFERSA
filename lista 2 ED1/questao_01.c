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

typedef struct sPilha{
	 
	 tDado vetor[MAX];
	 int topo;
	 
}tPilha;

int inserir(tPilha * pilha, tDado dado){
	
	if(pilha->topo == MAX-1){
		printf("Pilha estah cheia!");
		return flag_erro;
	}else{
		
		pilha->topo +=1; 
		pilha->vetor[pilha->topo] = dado;	
	}
	
	return flag_ok;
	
}

int remover(tPilha * pilha, tDado * retorno){
	
	if(pilha->topo == -1){
		printf("Pilha estah fazia");
		return flag_erro; 
	}else{
		
		*retorno = pilha->vetor[pilha->topo]; 
		pilha->topo -= 1;
		
	}
	
	return flag_ok;
}

int exibir(tPilha pilha){
	
	printf("\nExibindo a pilha\n");
	
	if(pilha.topo == -1){
		printf("pilha estah vazia");
		return flag_erro;
	}
	
	int i;
	for(i=0; i<= pilha.topo; i++){
		
		printf("%d: %s %.2f \n", i, pilha.vetor[i].nome, pilha.vetor[i].valor);
		
	}
	
	return flag_ok;
	

}


int main(){
	
	tPilha pilha; 
	pilha.topo = -1;
	
	tDado entrada, retorno;
	
	strcpy(entrada.nome, "Galvao");
	entrada.valor = 10;
	
	inserir(&pilha, entrada); 
	
		strcpy(entrada.nome, "Leandro");
	entrada.valor = 20;
		inserir(&pilha, entrada); 
	
	exibir(pilha);
	
	remover(&pilha, &retorno);
	
   printf("\n apos remover \n");
	exibir(pilha);
	
	
	
	system("pause"); 
	return 0;
}
