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
	

void inserirInicio(tElemento ** ppInicio, tDado dado){
	
	tElemento * pNovo = (tElemento*) calloc(1,sizeof(tElemento)); 
	pNovo->dado = dado; 
	pNovo->dado.id = time(NULL);
	pNovo->pProx = NULL;
	
	if(*ppInicio == NULL){
		
		*ppInicio = pNovo;
		
	}else{
		pNovo->pProx = *ppInicio;
		*ppInicio = pNovo;
	}
		
}

void inserirFim(tElemento ** ppInicio, tDado dado){
	
	tElemento * pNovo = (tElemento*) calloc(1,sizeof(tElemento)); 
	pNovo->dado = dado; 
	pNovo->dado.id = time(NULL);
	pNovo->pProx = NULL;
	
	tElemento * p = *ppInicio;
	
	if(*ppInicio == NULL){
		
		*ppInicio = pNovo; 
		
	}else{
		
		while(p->pProx != NULL){
			p = p->pProx;
		}
		
		p->pProx = pNovo;
	}
	
}

tElemento* buscar(tElemento* pInicio, int id)
{
    tElemento* p = pInicio;	

    while( p != NULL )
    {
        if( p->dado.id == id ) {
            return p;
        }
        p = p->pProx;
    }
    
    return NULL;
}

tElemento* buscarAnterior(tElemento* pInicio, int id)
{
    tElemento* p = pInicio; 	  
	tElemento* anterior = NULL;	   

    while (p != NULL)
    {
    	anterior = p;
        p = p->pProx;
        
        if (p != NULL && p->dado.id == id) {
           return anterior;
        }
    }
    
    return NULL;
}

int percorrer(tElemento* pInicio)
{
    tElemento *p = pInicio; 	

	if(p == NULL) {
		printf("LISTA VAZIA \n");
		return 0;
	}

        while( p != NULL )
        {
         
            printf("ID: %d \n", p->dado.id);
            printf("Nome: %s \n", p->dado.nome);
            printf("Valor: %.2f \n", p->dado.valor);
            printf("\n");
            p = p->pProx;
        }
    
    return 1;
}

void inserirDepoisDe(tElemento * pInicio, tDado dado, int id){
	
	tElemento * p = buscar(pInicio, id); 
	
	if(p == NULL){
		printf("Critério inválido");
		
	}else{
		
		tElemento * pNovo = (tElemento*) calloc(1, sizeof(tElemento)); 
		pNovo->dado = dado; 
		pNovo->dado.id = time(NULL); 
		pNovo->pProx = NULL; 
		
		pNovo->pProx = p->pProx; 
		p->pProx = pNovo; 
		
	}
	
}

tDado remover(tElemento** ppInicio, int id)
{	
	tElemento* anterior = NULL;
	tElemento* atual = NULL;
	tDado dadoRetorno;
	dadoRetorno.id = -1;

	if( *ppInicio == NULL ) {
        printf("Lista Vazia!!! \n");
        return dadoRetorno;
    }


	anterior = buscarAnterior(*ppInicio, id); 

	if( anterior == NULL ) {
		if( (*ppInicio)->dado.id == id ) {    
			atual = *ppInicio;

			if( atual->pProx == NULL ) {
				printf("Remove o primeiro e unico elemento \n");
				*ppInicio = NULL;
			}
			else {
        		printf("Remove o primeiro elemento \n");
    			*ppInicio = atual->pProx;
            	atual->pProx = NULL;
			}
		}
	}
	else
	{
		atual = anterior->pProx;

		printf("Remove elemento meio ou ultimo \n");
		anterior->pProx = atual->pProx; 
        atual->pProx = NULL;
	}

	dadoRetorno = atual->dado;
	free(atual);
	
	return dadoRetorno;
}



	


int main(){
	
	tElemento * pInicio = NULL; 
	tDado entrada, retorno; 
	
	strcpy(entrada.nome, "Galvao"); 
	entrada.valor = 10; 
	inserirInicio(&pInicio, entrada);
	
		
	strcpy(entrada.nome, "Gustavo"); 
	entrada.valor = 20; 
	inserirInicio(&pInicio, entrada);
	
	percorrer(pInicio);

	
	
	
	
	system("pause"); 
	return 0;
}
