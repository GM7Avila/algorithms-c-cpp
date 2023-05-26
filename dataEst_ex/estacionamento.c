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
   
    p->top = MAX_SIZE;

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
    //strcpy (voidCar.registro, "A AAA1111");

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

void comandLine(Stack *p, char *comands[], int n){

    //p->garage[i].registro[0] == 'E'

    for(int i=0; i < p->top; i++){

        printf("\n%c", comands[i][0]);

        if(comands[i][0] == 'E'){
            printf("\nFunc do carro entrando");
        } else if (comands[i][0] == 'S'){
            printf("\nFunc do carro saindo");
        } 
    }
}


int main(){

    Stack p; // pilha -> alameda
    Stack aux; // pilha auxiliar -> para manobrar

    int exit = 0;
    int n = 5;
    stackStarter(&p);

    // Comand Line:
    char *StringList[5]={"AAA1111", "BAA1111", "AAA1111", "CAA1111", "AAA1111"};
    
    printStack(&p);
    comandLine(&p, StringList, n);

    return 1;

}