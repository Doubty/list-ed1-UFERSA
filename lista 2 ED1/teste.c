#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20
#define flag_ok 1 
#define flag_fail 0

typedef struct{
	char vetor[MAX]; 
	int topo;
	
}tPilha;


int empilhar(tPilha * pilha, char valor){
	
	if(pilha->topo == MAX-1){
		printf("Pilha cheia!");
		return flag_fail; 
	}else{
		
	    pilha->topo +=1;
		pilha->vetor[pilha->topo] = valor;
	}
	
	return flag_ok;
	
}


int desempilhar(tPilha * pilha, char * retorno){
	
	if(pilha->topo == -1){
		printf("Pilha vazia!"); 
		*retorno = ' ';
		return flag_fail; 
	}else{
		
		*retorno = pilha->vetor[pilha->topo]; 
		pilha->topo -=1; 
	
	}
	
	return flag_ok;
	
}
tPilha inicializarPilha(){
	
	tPilha pilha; 
	pilha.topo = -1; 
	
	return pilha;
	
}

int main(){
	
	char expressao[MAX] = "81+2-";
	tPilha pilha = inicializarPilha();
	
	char operando = 0;
	int resultado = 0;
	
	printf("Expressao: %s \n", expressao);
	
	int i; 
	for(i =0; expressao[i]; i++){
		
		if((expressao[i] - '0') >= 0 && expressao[i] - '0' <=9){
			
			empilhar(&pilha,expressao[i]);
			
		}else if(expressao[i] == '+'){
			
			resultado = 0;
			
			desempilhar(&pilha, &operando);
			resultado += operando - '0'; 
			desempilhar(&pilha, &operando); 
			resultado += operando - '0'; 
		    
		    empilhar(&pilha, (char) '0'+resultado);
		}else if(expressao[i] == '-'){
			
			resultado = 0;
			
			desempilhar(&pilha, &operando);
			resultado -= operando - '0'; 
			desempilhar(&pilha, &operando); 
			resultado += operando - '0'; 
		    
		    empilhar(&pilha, (char) '0'+resultado);
		    
		}else if(expressao[i] == '*'){
			
			resultado = 1;
			
			desempilhar(&pilha, &operando);
			resultado *= operando - '0'; 
			desempilhar(&pilha, &operando); 
			resultado *= operando - '0'; 
		    
		    empilhar(&pilha, (char) '0'+resultado);
		    
		    
		}else if(expressao[i] == '/'){
			
		   resultado = 0; 
		   
		   char operandoUm = 0, operandoDois = 0; 
		   
		   desempilhar(&pilha, &operandoDois); 
		    desempilhar(&pilha, &operandoUm); 
		    
		    resultado *= (operandoUm - '0')/(operandoDois - '0'); 
		    
		    empilhar(&pilha, (char) '0'+resultado); 
		   
		   		}
		
	}
	
    desempilhar(&pilha, &operando);
    printf("Resultado: %c \n", operando);
	
	system("pause"); 
	return 0;
}


