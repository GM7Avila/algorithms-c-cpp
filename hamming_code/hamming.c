#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#define WORD_SIZE 4

typedef struct Node {
    int binary_value;
    int index;

    /*
    
    Se é um nó de paridade, verifica se ele ja foi checado. Se não verifica os nós no range. Por fim, altera o valor.

    */
    bool isParity; /* nó de paridade ou normal */
    bool parityChecked; /* se a paridade ja foi verificada, procura a próxima */
    struct Node* next;
} Node;

Node* createStream(int size){
    if(size <=0){
        return NULL;
    }

    Node* head = (Node*)malloc(sizeof(Node));
    if(head == NULL){
        return NULL; /* Caso não seja possível alocar memória */
    }

    head->binary_value = 0;
}

int calculateParity(int m) {
    int p = 0;
    while (pow(2, p) < (m + p) + 1) {
        p++;
    }
    return p;
}

int main() {

    int p = calculateParity(WORD_SIZE);
    int new_word_size = WORD_SIZE + p;
    printf("Para uma informação de %d bits, precisaremos de %d paridades\n=> A informação encapsulada com os bits de paridade terá tamanho: %d", WORD_SIZE, p, new_word_size);

    malloc();

    return 0;
}
