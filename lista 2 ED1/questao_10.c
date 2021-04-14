#include <stdio.h>
#include <stdlib.h>
#define MAX 20
#define FLAG_OK 1
#define FLAG_FAIL 0

typedef struct {
    char vetor[MAX];
    int topo;
} tPilha;

tPilha inicializar();
int empilhar(tPilha*, char);
int desempilhar(tPilha* , char*);

int main(void){

    char expressao[MAX] = "81+2-";
    char operando = 0;
    int resultado = 0;
    
    tPilha pilha = inicializar();

    printf("Expressao: %s\n\n", expressao);
    int i;
    for(i = 0; expressao[i]; i++){
    
        if((expressao[i]-'0') >= 0 && (expressao[i]-'0') <= 9){
        	
            empilhar(&pilha,expressao[i]);
            
        }else if(expressao[i] == '+'){
        	
            resultado = 0;
            
            desempilhar(&pilha, &operando);
            resultado += operando - '0';
            desempilhar(&pilha, &operando);
            resultado += operando - '0';

            empilhar(&pilha, (char) '0' + resultado);
            
        }else if(expressao[i] == '-'){
            resultado = 0;
            
            desempilhar(&pilha, &operando);
            resultado -= operando - '0';
            desempilhar(&pilha, &operando);
            resultado += operando - '0';

            empilhar(&pilha, (char) '0' + resultado);
            
        }else if(expressao[i] == '*'){
        	
            resultado = 1;
            
            desempilhar(&pilha, &operando);
            resultado *= operando - '0';
            desempilhar(&pilha, &operando);
            resultado *= operando - '0';

            empilhar(&pilha, (char) '0' + resultado);
            
        }else if(expressao[i] == '/'){
            resultado = 0;
            
            char operandoUm = 0, operandoDois = 0;
            desempilhar(&pilha, &operandoDois);
            desempilhar(&pilha, &operandoUm);
            
            resultado *= (operandoUm - '0')/(operandoDois - '0');

            empilhar(&pilha, (char) '0' + resultado);
        }
    }

    desempilhar(&pilha, &operando);
    printf("Resultado: %c", operando);

    return 0;
}

tPilha inicializar()
{
	tPilha pilha;
	pilha.topo = -1;
	
	return pilha;
}

int empilhar(tPilha* pilha, char simbolo){

    if(pilha->topo == MAX-1) {
        printf("Pilha cheia\n");
        return FLAG_FAIL;
    }else{
        pilha->topo = pilha->topo + 1;
        pilha->vetor[ pilha->topo ] = simbolo;
        return FLAG_OK;
    }

}

int desempilhar(tPilha* pilha, char * retorno){

    if(pilha->topo == -1) {
        printf("Pilha vazia \n");
		*retorno = ' ';
        return FLAG_FAIL;
    }else{
        *retorno = pilha->vetor[ pilha->topo ];
        pilha->topo -= 1;
        return FLAG_OK;
    }
}
