#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct dados dados;
typedef struct elemento elemento;

struct dados{
    int id;
    char nome[30];
    float valor;
};

struct elemento{
    dados dado;
    elemento * elementoAnterior;
    elemento * elementoProximo;
};

int i = 0;

void inserir_inicio(elemento**, dados);
void inserir_depois(elemento**, dados, int);
void inserir_fim(elemento**, dados);
elemento* criar_elemento(dados);
void percorrer(elemento*);
elemento* encontrar_elemento(elemento*, int);
dados remover(elemento**, int);

int main(void){

    elemento * inicial = NULL;
    dados dado;
    strcpy(dado.nome, "galvao");
    dado.valor = 1.0;
    inserir_fim(&inicial, dado);

    strcpy(dado.nome, "leandro");
    dado.valor = 2.0;
    inserir_fim(&inicial, dado);

    strcpy(dado.nome, "mikeias");
    dado.valor = 3.0;
    inserir_fim(&inicial, dado);
    percorrer(inicial);
    remover(&inicial, 18);
    percorrer(inicial);
    return 0;
}

elemento* criar_elemento(dados dado){
    elemento * novo = (elemento*) calloc(1, sizeof(elemento));
    novo->elementoAnterior = NULL;
    novo->elementoProximo = NULL;
    novo->dado = dado;
    novo->dado.id = time(NULL) / 100000000 + ++i;

    return novo;
}

void inserir_inicio(elemento ** inicial, dados dado){
    elemento * novo = criar_elemento(dado);

    if((*inicial) == NULL){
        *inicial = novo;
    }else{  
    
        novo->elementoProximo = *inicial;

        if((*inicial)->elementoAnterior == NULL){
            (*inicial)->elementoAnterior = novo;
            novo->elementoAnterior = *inicial;

        }else{
            novo->elementoAnterior = (*inicial)->elementoAnterior;
            (*inicial)->elementoAnterior = novo;
        }
        
        *inicial = novo;
    }
}

void inserir_depois(elemento** inicial, dados dado, int id){
    elemento * item = encontrar_elemento(*inicial, id);

    if(item == NULL){
        printf("Posição não encontrada\n");
    }else{
        elemento * novo = criar_elemento(dado);
        novo->elementoAnterior = item;
        if(item->elementoAnterior == NULL){
            
            item->elementoProximo = novo;
            item->elementoAnterior = item;
        }else{  
            novo->elementoProximo = item->elementoProximo;
            item->elementoProximo = novo;
            if(novo->elementoProximo == NULL){
                (*inicial)->elementoAnterior = novo;
            }else{
                elemento* direita = novo->elementoProximo;
                direita->elementoAnterior = novo;
            }
        }

    }
}


void inserir_fim(elemento** inicial, dados dado){
    elemento * novo = criar_elemento(dado);

    if((*inicial) == NULL){
        *inicial = novo;
    }else{
        elemento * temporario = *inicial;

        while(temporario->elementoProximo != NULL){
            temporario = temporario->elementoProximo;
        }

        temporario->elementoProximo = novo;
        novo->elementoAnterior = temporario;
        (*inicial)->elementoAnterior = novo;
    }
}

void percorrer(elemento * inicial){
    if(inicial == NULL){
        printf("Lista vazia\n");
    }else{
        while(inicial != NULL){
            printf("Ponteiro: %d\n", inicial);
            printf("ID: %d\n", inicial->dado.id);
            printf("Nome: %s\n", inicial->dado.nome);
            printf("Valor: %f\n\n\n", inicial->dado.valor);
            inicial = inicial->elementoProximo;
        }

    }
}

elemento* encontrar_elemento(elemento * inicial, int id){
    elemento * temporario = inicial;
    while(temporario != NULL){
        if(temporario->dado.id == id){
            return temporario;
        }

        temporario = temporario->elementoProximo;
    }
    return NULL;
}

dados remover(elemento** inicial, int id){
    dados dado;
    dado.id = 0;
    dado.nome[0] = 0;
    dado.valor = 0;

    elemento* item = encontrar_elemento(*inicial, id);

    if(*inicial == NULL){
        printf("Lista vazia\n");
    }else if(item == NULL){
        printf("Elemento não encontrado\n");
    }else{
        elemento * direita = item->elementoProximo;
        elemento * esquerda = item->elementoAnterior;
        dado = item->dado;
        if(direita == NULL && esquerda == NULL){
            *inicial = NULL;
        }else{
            //Se o elemento for inicial
            
            if(*inicial == item){
                *inicial = direita;
                if(esquerda == *inicial){
                    (*inicial)->elementoAnterior = NULL;
                }else{
                    (*inicial)->elementoAnterior = esquerda;
                }
            }else if((*inicial)->elementoAnterior == item){
                //Se for elemento final
                esquerda->elementoProximo = NULL;
                if(esquerda == (*inicial)){
                    (*inicial)->elementoAnterior = NULL;
                }else{
                    (*inicial)->elementoAnterior = esquerda;
                }

            }else{
                
                esquerda->elementoProximo = direita;
                direita->elementoAnterior = esquerda;
            }
            
        }
        free(item);
    }

    return dado;
}
