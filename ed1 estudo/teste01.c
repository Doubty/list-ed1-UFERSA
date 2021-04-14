#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct sDado{
	  
	  int id; 
	  char nome[30]; 
	  float valor; 
} tDado;

typedef struct sElemento{
	tDado dado; 
	
  struct sElemento * pProx; 
  struct sElemento * pAnte;
	
} tElemento;

tElemento* criarNovo(tElemento * pInicio, tDado dado);
tElemento* inicializarLista();
void inserirInicio(tElemento * pInicio, tDado dado);
int percorrer(tElemento * pInicio);
void inserirFim(tElemento * pInicio, tDado dado);
tElemento * buscar(tElemento * pInicio, int id);
tDado remover(tElemento * pInicio, int key);

int main(){
	
	tElemento * pInicio = inicializarLista(); 
	int id;
	tDado entrada, retorno;
	
	strcpy(entrada.nome, "Galvao"); 
	entrada.valor = 20;	
	
	inserirInicio(pInicio, entrada);
	
	strcpy(entrada.nome, "leandro"); 
	entrada.valor = 35;	
	inserirInicio(pInicio, entrada);
		strcpy(entrada.nome, "Carlos"); 
	entrada.valor = 35;	
	inserirFim(pInicio, entrada);
	percorrer(pInicio); 
	printf("---------------"); 
	
	remover(pInicio, 1);
		percorrer(pInicio); 
	
	
	
	
	system("pause"); 
	return 0;
}

tElemento* inicializarLista(){
	
	tElemento * pNovo = (tElemento*) calloc(1, sizeof(tElemento));
    pNovo->dado.id = 1; 
    pNovo->pProx = NULL; 
    pNovo->pAnte = NULL; 
    
    return pNovo;
}

tElemento* criarNovo(tElemento * pInicio, tDado dado){
	
	tElemento * pNovo = (tElemento*) calloc(1, sizeof(tElemento)); 
	pNovo->dado = dado; 
	pNovo->dado.id = pInicio->dado.id; 
	pNovo->pProx = NULL; 
	pNovo->pAnte = NULL; 
	
	// Atualizando o elemento cabeça
	pInicio->dado.id +=1;
	
	return pNovo;
}

void inserirInicio(tElemento * pInicio, tDado dado){
	
	tElemento * pNovo = criarNovo(pInicio, dado); 
	
	pNovo->pProx = pInicio->pProx; 
	pNovo->pAnte = pInicio; 
	
	tElemento * pDireita = pInicio->pProx; 
	pInicio->pProx = pNovo; 
	
	if(pDireita == NULL){
		pInicio->pAnte = pNovo; 
	}else{
		pDireita->pAnte = pNovo;
	}
	
}

int percorrer(tElemento * pInicio){
	
	tElemento * p = pInicio->pProx; 
	
	if(p == NULL){
		printf("Lista vazia!"); 
		 return 0;
	}
	
	while(p != NULL){
		printf("ID: %d Nome: %s Valor: %.2f \n", p->dado.id, p->dado.nome, p->dado.valor );
		p = p->pProx;
	}
	
	return 1;
}

void inserirFim(tElemento * pInicio, tDado dado){
	
	tElemento * pNovo = criarNovo(pInicio, dado); 
	
	tElemento * pUltimo = pInicio->pAnte; 
	
	if(pUltimo == NULL){
		pNovo->pAnte = pInicio; 
		pInicio->pProx = pNovo; 
	}else{
		pNovo->pAnte = pUltimo;
		pUltimo->pProx = pNovo; 
	}
	
	pInicio->pAnte = pNovo;
}

tElemento * buscar(tElemento * pInicio, int id){
	
	tElemento * p = pInicio->pProx; 
	
	while(p != NULL){
		
		if(p->dado.id == id){
			return p;
		}
		
		p = p->pProx;
	}
	
	return NULL;
}

tDado remover(tElemento * pInicio, int key){
	
	tDado dado; 
	dado.id = -1; 
	
	tElemento * p = buscar(pInicio, key);
	
	if(p == NULL){
		printf("Id não encontrado"); 
		return dado;
	}
	
	tElemento * pEsquerdo = p->pAnte; 
	tElemento * pDireito = p->pProx; 
	
	pEsquerdo->pProx = pDireito; 
	
	if(pDireito == NULL){
		if(pInicio->pAnte == pInicio->pAnte){
			pInicio->pAnte = NULL; 
		}else{
			pInicio->pAnte = pEsquerdo; 
		}
		
	}else{
		pDireito->pAnte = pEsquerdo; 
	}
	
	dado = p->dado; 
	
	free(p);
	return dado; 
	
	
}
	





