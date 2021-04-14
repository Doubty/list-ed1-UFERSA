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
   struct sElemento * pAnte; 
	
}tElemento; 


tElemento * criarNovo(tElemento * pInicio, tDado dado){
	
	tElemento * pNovo = (tElemento*) calloc(1, sizeof(tElemento));
	pNovo->dado = dado; 
	pNovo->dado.id = pInicio->dado.id;
	pNovo->pProx = NULL;
	pNovo->pAnte = NULL; 
	
	pInicio->dado.id +=1;
	
	return pNovo;
	
}

tElemento * inicializarLista(){
	
	tElemento * pNovo = (tElemento*) calloc(1, sizeof(tElemento));
	pNovo->dado.id = 1;
	pNovo->pProx = NULL;
	pNovo->pAnte = NULL; 
	
	return pNovo;
   
}

void inserirInicio(tElemento * pInicio, tDado dado){
	
	tElemento * pNovo = criarNovo(pInicio, dado);
	
	pNovo->pAnte = pInicio; 
	pNovo->pProx = pInicio->pProx; 
	
	tElemento * pDireita = pInicio->pProx; 
	pInicio->pProx = pNovo;
	
	if(pDireita == NULL){
		pInicio->pAnte = pNovo; 

	}else{
		pDireita->pAnte = pNovo;
	}
	
}

void inserirFim(tElemento * pInicio, tDado dado){
	
	tElemento * pNovo = criarNovo(pInicio, dado);

	tElemento * pUltimo = pInicio->pAnte;
	
	if(pUltimo == NULL){
		 
		 pInicio->pProx = pNovo; 
		 pNovo->pAnte = pInicio;
		 
		 
	}else{
		
		pNovo->pAnte = pUltimo; 
		pUltimo->pProx = pNovo;  
		
	}
	
	  pInicio->pAnte = pNovo;
		
}

tElemento * buscar(tElemento * pInicio, int id ){
	
	tElemento * p = pInicio->pProx; 
	
	if(p == NULL){
		printf("ID invalido."); 
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

tDado remover(tElemento * pInicio, int id){
	
	tElemento * p = buscar(pInicio, id);
	tDado retorno; 
	retorno.id = -1;
	
	
	if(p == NULL){
		printf("ID não encontrado"); 
		return retorno;
		
	}
	
	tElemento * pDireito = p->pProx; 
	tElemento * pEsquerdo = p->pAnte; 
	
	pEsquerdo->pProx = pDireito;
	
	if(pDireito == NULL){
		
		if(pInicio->pProx == pInicio->pAnte){
			   pInicio->pAnte = NULL;
		}else{
			pInicio->pAnte = pEsquerdo; 
		}
		
	}else{
		  
		pDireito->pProx = pEsquerdo;
	}
	
	retorno = p->dado; 
	
	free(p);
	
	return retorno;
	
	
}

int percorrer(tElemento * pInicio){
	
	tElemento * p = pInicio->pProx; 
	
	if(p == NULL){
		printf("Lista vazia"); 
		return 0;
	}
	
	while(p != NULL){
		
		printf("\n ID: %d Nome: %s Valor: %.2f \n", p->dado.id, p->dado.nome, p->dado.valor);
		p = p->pProx; 
	}
	
	return 1;
}


int main(){
	
	tDado entrada, retorno; 
	int id;
	tElemento * pInicio = inicializarLista();
	
	strcpy(entrada.nome, "Galvao"); 
	entrada.valor = 10;
	
	inserirInicio(pInicio, entrada);
	
		strcpy(entrada.nome, "leandro"); 
	entrada.valor = 20;
	
	inserirInicio(pInicio, entrada);
	
	percorrer(pInicio);
	
	printf("\nInserindo no fim\n");
	strcpy(entrada.nome, "gustavo"); 
	entrada.valor = 30;
	
	inserirFim(pInicio, entrada);
	
	percorrer(pInicio);
	
	
	
	system("pause"); 
	return 0;
}
