#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct sDado{
	int id; 
	char nome[30]; 
	
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
		
		printf("\n ID: %d Nome: %s ", p->dado.id, p->dado.nome); 
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

tElemento * buscaLinear(tElemento * pInicio, int id){
	
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
	
	// reaproveitando o código da lista anterior.
	tElemento * pInicio = inicializarLista();
	tDado entrada, retorno; 
	
	strcpy(entrada.nome, "objeto 1");
	inserirInicio(pInicio, entrada );
	
		
	strcpy(entrada.nome, "objeto 2");
	inserirInicio(pInicio, entrada );
	
	strcpy(entrada.nome, "objeto 3");
	inserirInicio(pInicio, entrada );
	
	tElemento * pResultado = buscaLinear(pInicio, 2);
	
	printf("Resultado da busca: \nID: %d Nome: %s \n", pResultado->dado.id, pResultado->dado.nome);
	

	
	percorrer(pInicio);
	

	
	
	system("pause"); 
	return 0;
}


