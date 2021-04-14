#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct sDado{
	int id; 
	char nome[30]; 
	float valor; 
}tDado; 

typedef struct sElemento{
	tDado dado; 
	struct sElemento * pProx; 
}tElemento;

tElemento * inicializarLista(){
	
	 tElemento * pNovo = (tElemento*) calloc(1, sizeof(tElemento)); 
	 pNovo->dado.id = 1; 
	 pNovo->pProx = NULL; 
	 
	 return pNovo; 
}

void inserirInicio(tElemento * pInicio, tDado dado){
	
     tElemento * pNovo = (tElemento*) calloc(1, sizeof(tElemento)); 
     pNovo->dado = dado; 
     pNovo->dado.id = pInicio->dado.id; 
     pNovo->pProx = NULL;
     
     pInicio->dado.id +=1; 
     
     pNovo->pProx = pInicio->pProx; 
     pInicio->pProx = pNovo; 
	
}

void inserirFim(tElemento * pInicio, tDado dado){
	
		
     tElemento * pNovo = (tElemento*) calloc(1, sizeof(tElemento)); 
     pNovo->dado = dado; 
     pNovo->dado.id = pInicio->dado.id; 
     pNovo->pProx = NULL;
     
      pInicio->dado.id +=1; 
      
      
      tElemento * p = pInicio; 
	
	while(p->pProx != NULL){
		
		p = p->pProx;
		
	}
	
	p->pProx = pNovo; 
		
}

int percorrer(tElemento * pInicio){
	
   tElemento * p = pInicio->pProx; 
   
    if(p == NULL){
    	printf("A fila estah vazia!"); 
    	return 0; 
	}
	
	while(p != NULL){
		
		printf("\n ID: %d Nome: %s Valor: %.2f\n", p->dado.id, p->dado.nome, p->dado.valor); 
		p = p->pProx;
		
	}
	
	return 1;
	
}

tElemento * buscar(tElemento * pInicio, int id){
	
	tElemento * p = pInicio->pProx; 
	
	if(p == NULL){
		printf("ID invalido!"); 
		return NULL; 
	}
	
	while(p != NULL){
		
		if(p->dado.id == id){
			return p;
		}
		
		p = p->pProx;
		
	}
	
	return NULL;
	
}

tElemento * buscarAnterior(tElemento * pInicio, int id){
	
	tElemento * p = pInicio; 
	tElemento * result = NULL;
	
	if(p == NULL){
		printf("Erro: não tem anterior"); 
		return NULL;
	}
	
	while(p != NULL){
		result = p; 
		p = p->pProx; 
		if(p != NULL && p->dado.id == id){
			return result;
		}
	}
	
	return NULL;
	
}

tDado remover(tElemento * pInicio, int id){
	
	tElemento * pAnterior = buscarAnterior(pInicio, id);
	tElemento * p = buscar(pInicio, id);
	tDado dado; 
	dado.id = 0;
	
	if(pAnterior == NULL){
		printf("Não existe elemento com esse ID"); 
		return dado;
	}
	
	dado = p->dado;
	
	pAnterior->pProx = p->pProx; 
    p = NULL;
    	
}


int main(){
	
	tElemento * pInicio = inicializarLista();
	tDado entrada, retorno; 
	
	strcpy(entrada.nome, "galvao");
	entrada.valor = 10;
	inserirInicio(pInicio, entrada );
	
		
	strcpy(entrada.nome, "aaaa");
	entrada.valor = 20;
	inserirInicio(pInicio, entrada );
	
		strcpy(entrada.nome, "bbb");
	entrada.valor = 30;
	inserirFim(pInicio, entrada );
	

	
	percorrer(pInicio);
	
	remover(pInicio, 3);
	printf("\n------Remover o 3 ---------\n");
		
	percorrer(pInicio);
	
	
	
	system("pause"); 
	return 0;
}
