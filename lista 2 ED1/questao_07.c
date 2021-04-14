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
		
		printf("\n ID: %d Nome: %s \n", p->dado.id, p->dado.nome); 
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

int verificarPalavra(tElemento * pInicio, char * palavra){
	
	tElemento * p = pInicio->pProx; 
	
	
	while(p != NULL){
		
		if(!strcmp(p->dado.nome, palavra)){
			return 1;
		}
		
		p = p->pProx;
	}
	
	return 0;
}


int main(){
	
	tElemento * pLista1 = inicializarLista();
	tElemento * pLista2 = inicializarLista();
	tDado entrada, retorno; 
	char palavra[30];
	int quantidade =0;
	
	FILE * pArquivo; 
	
	pArquivo = fopen("arquivo.txt","r");
	
	if(pArquivo == NULL){
		printf("Arquivo nao existe!"); 
		return 1;
	}
	
	while(fscanf(pArquivo,"%s", palavra) != EOF){
		
	strcpy(entrada.nome, palavra);
	inserirInicio(pLista1, entrada );
	quantidade++;
			
	}
	
	fclose(pArquivo);
	
	tElemento * p = pLista1->pProx; 

	int contador =0; 
	int i=1;
	printf("Quantidade: %d \n",quantidade);
	
	while(p != NULL){
		
		while(i <= quantidade){
			
			if(!strcmp(p->dado.nome, buscar(pLista1,i)->dado.nome)){
			  
				 contador++;
			}
		
		   i++;
		}
		
		i = 1;
		
	
		if(verificarPalavra(pLista2, p->dado.nome) == 0){
			strcpy(entrada.nome, p->dado.nome);
	     	inserirInicio(pLista2, entrada );
	        printf("%s: %d \n", entrada.nome, contador);
		}
		
	    contador = 0;
	 
		p = p->pProx;
		
	}
	

	system("pause"); 
	return 0;
}
