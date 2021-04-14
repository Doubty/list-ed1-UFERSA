#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define FLAG_OK 1
#define FLAG_ERRO 0
#define MAX 50

typedef struct {
    char vetor[MAX];
    float vetResultado[MAX];
    int topo;
} tPilha;

tPilha inicializar();
int empilhar(tPilha*, char);
int empilhar_real(tPilha*, float);
int desempilhar(tPilha*, char*);
int desempilhar_real(tPilha*, float*);
int precedencia(char);

int main(void){

    char expressao[MAX] = "( 1.0 + 2.0 ) * 3.0";
    char resultado[MAX];
  
    char retorno = NULL;

    tPilha pilha = inicializar();

    printf("Expressao na forma infixa: %s\n", expressao);

    char* fatias = strtok(expressao, " ");

    int i = 0;
    while( fatias != NULL){
     
        if(fatias[0] == '+' || fatias[0] == '-' || fatias[0] == '*' || fatias[0] == '/'){
            
          
            while((pilha.topo != -1) && (precedencia(pilha.vetor[pilha.topo]) >= precedencia(fatias[0]))){
                desempilhar(&pilha, &retorno);
           
                resultado[i++] = retorno;
                resultado[i++] = ' ';
            }

            if(empilhar(&pilha, fatias[0]) == FLAG_ERRO){
                printf("Pilha cheia\n");
                return 1;
            }
            

        }else if(fatias[0] == '('){
        
            if(empilhar(&pilha, fatias[0]) == FLAG_ERRO){
                printf("Pilha cheia\n");
                return 1;
            }

        }else if(fatias[0] == ')'){
       
            if(desempilhar(&pilha, &retorno) == FLAG_ERRO){
                printf("Pilha vazia\n");
            }
            while(retorno != '('){
            
                resultado[i++] = retorno;
                resultado[i++] = ' ';
                if(desempilhar(&pilha, &retorno) == FLAG_ERRO){
                printf("Pilha vazia\n");
                }
            }

        }else{
        
            int j;
            for(j = 0; fatias[j]; j++){
                resultado[i++] = fatias[j];
            }
            resultado[i++] = ' ';

        }
        
        fatias = strtok(NULL, " ");
    }
  
    while(desempilhar(&pilha, &retorno)){
  
        resultado[i++] = retorno;
        resultado[i++] = ' ';
    }

    printf("Expressao na forma posfixa: %s\n", resultado);


    float numeroUm, numeroDois;

    fatias = strtok(resultado, " ");

    while(fatias != NULL){
        float numero;        
     
        if(ispunct(fatias[0])){
            switch (fatias[0])
            {
            case '+':
                desempilhar_real(&pilha, &numeroDois);
                desempilhar_real(&pilha, &numeroUm);
                empilhar_real(&pilha, numeroUm+numeroDois);
                break;
            case '-':
                desempilhar_real(&pilha, &numeroDois);
                desempilhar_real(&pilha, &numeroUm);
                empilhar_real(&pilha, numeroUm-numeroDois);
                break;
            case '*':
                desempilhar_real(&pilha, &numeroDois);
                desempilhar_real(&pilha, &numeroUm);
                empilhar_real(&pilha, numeroUm*numeroDois);
                break;
            case '/':
                desempilhar_real(&pilha, &numeroDois);
                desempilhar_real(&pilha, &numeroUm);
                empilhar_real(&pilha, numeroUm/numeroDois);
                break;
            default:
                break;
            }
        }else{
            sscanf(fatias, "%f", &numero); 
            empilhar_real(&pilha, numero);
        }
        fatias = strtok(NULL, " "); 
    }

    desempilhar_real(&pilha, &numeroUm);
    printf("Resultado: %f", numeroUm);
    
    system("pause");
    return 0;
}

tPilha inicializar(){
    tPilha pilha;
    pilha.topo = -1;

    return pilha;
}

int empilhar(tPilha * pilha, char simbolo){

    if(pilha->topo == MAX-1){
        return FLAG_ERRO;
    }else{

        pilha->topo += 1;
        pilha->vetor[pilha->topo] = simbolo;
        return FLAG_OK;
    }
}

int desempilhar(tPilha * pilha, char * retorno){

    if(pilha->topo == -1){
        return FLAG_ERRO;
        *retorno = ' ';
    }else{
        *retorno = pilha->vetor[pilha->topo];
        pilha->topo -= 1;
        return FLAG_OK;
        
    }

}

int precedencia(char operando){
    if(operando == '(' || operando == ')'){
        return 1;
    }else if(operando == '+' || operando == '-'){
        return 2;
    }else if(operando == '*' || operando == '/'){
        return 3;
    }else{
        return 0;
    }
}

int empilhar_real(tPilha* pilha, float numero){
    if(pilha->topo == MAX-1) {
        printf("Pilha cheia\n");
        return FLAG_ERRO;
    }else{   
        pilha->topo = pilha->topo + 1;
        pilha->vetor[ pilha->topo ] = numero;
        return FLAG_OK;
    }

}

int desempilhar_real(tPilha* pilha, float * retorno){

    if(pilha->topo == -1) {
        printf("ERRO: pilha vazia!!! \n");
		*retorno = 0;
        return FLAG_ERRO;
    }else{
        *retorno = pilha->vetor[ pilha->topo ];
        pilha->topo = pilha->topo - 1;
        return FLAG_OK;
    }
}
