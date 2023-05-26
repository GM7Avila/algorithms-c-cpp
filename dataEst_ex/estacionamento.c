#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 
#include <string.h>

#define MAX_SIZE 5

// vaga de carro - registro + count manobras
typedef struct {
    char registro[9]; // [E/S] AAA1111
    int count;
} Car;

// pilha de Carros - carro + posição do topo (?)
typedef struct {
    Car garage[MAX_SIZE];
    int top;
} Stack;

// inicializa vazio
void stackStarter (Stack *p) {
   
    p->top = 0;

    // inicia todas as vagas por padrão com A AAA1111 (vaga vazia)
    for(int i=0; i<MAX_SIZE; i++){
        
        Car voidCar;

        voidCar.count = 0;

        p->garage[i] = voidCar;

        makeVoid(p, i);
    }

}

// apaga uma vaga (torna ela "vazia" = A AAA1111) - Recebe um ponteiro para a pilha e o index da vaga que deseja "apagar" o elemento
void makeVoid(Stack *p, int i){

    strcpy (p->garage[i].registro, "A AAA1111");
    p->garage[i].count = 0;

}

// printa a pilha
void printStack(Stack *p){
    
    printf("\n");

    for(int i=0; i<MAX_SIZE; i++){

        int resultCmp = strcmp(p->garage[i].registro, "A AAA1111");

        if(resultCmp == 0){
            printf("Vaga: %d: [Vazia]\n", i+1);
        } else {
            printf("Vaga %d: [%s | x%d]\n", i+1, p->garage[i].registro, p->garage[i].count);
        }
    }

    printf("\n");

}

void comandLine(Stack *p, Stack *aux, char *comands[], int n){

    int index_markdown = 0; 
    
    // roda a lista de comandos
    for(int i=0; i < n; i++){
        printf("\n%c", comands[i][0]);

        if(comands[i][0] == 'E'){
            strcpy(p->garage[p->top].registro, comands[i]);
            p->top++;
            // p->garage[100].registro não existe


        } else if (comands[i][0] == 'S'){
            printf("\nOrdem de saida");
            // busca a posição pela placa
            for(int j=0; j < p->top; j++){ 
                // compara a partir do primeiro elemento  
                if(strcmp(&(p->garage[j].registro)[1], &(comands[i])[1]) == 0){
                    printf("Encontrou");
                    //strcpy(aux->garage[aux->top].registro, comands[i]);

                    index_markdown = j; //index da onde vai começar o loop de remoção

                    // transferência de dados para o outro vetor em ordem e depois volta com eles de volta
                    for(int x=index_markdown; x < p->top; x++){
                        printf("entrando nesse lugar");
                        aux->garage[aux->top] = p->garage[x]; //transfere para o auxiliar
                    
                        strcpy (p->garage[x].registro, "A AAA1111");
                        p->garage[x].count = 0; 

                        aux->top++;

                    }

                }
            }

            // como encontrar o elemento que tem que sair?
        } 
    }
}


int main(){

    Stack p; // pilha -> alameda
    Stack aux; // pilha auxiliar -> para manobrar

    int n = 6;

    // Iniciando a pilha vazia  
    stackStarter(&p);
    stackStarter(&aux);

    // Comand Line: Carros entrando
    char *StringList[6]={"E KVN4546", "E BAF3597", "E TCP8080", "E JAV4123", "E SAF7770", "S JAV4123"};
    
    printStack(&p);
    printStack(&aux);

    comandLine(&p, &aux, StringList, n);
    
    printStack(&p);
    printStack(&aux);

    return 1;

}