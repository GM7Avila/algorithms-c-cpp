#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
    char word[16];
    int contador;
    struct No* esquerda;
    struct No* direita;
} No;


No* criarNo(char* word) {
    No* novoNo = (No*)malloc(sizeof(No));
    strcpy(novoNo->word, word);
    novoNo->contador = 1;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    return novoNo;
}

// Função auxiliar para inserir uma word na árvore
No* inserirNo(No* raiz, char* word) {
    if (raiz == NULL) {
        return criarNo(word);
    }

    int comparacao = strcmp(word, raiz->word);
    if (comparacao == 0) {
        raiz->contador++;
    } else if (comparacao < 0) {
        raiz->esquerda = inserirNo(raiz->esquerda, word);
    } else {
        raiz->direita = inserirNo(raiz->direita, word);
    }

    return raiz;
}

// Função auxiliar para percorrer a árvore em ordem alfabética
void percorrerEmOrdem(No* raiz) {
    if (raiz != NULL) {
        percorrerEmOrdem(raiz->esquerda);
        printf("%s (%d)\n", raiz->word, raiz->contador);
        percorrerEmOrdem(raiz->direita);
    }
}

// Função principal para processar as palavras e construir a árvore
void processaPalavras(char* str[]) {
    No* raiz = NULL;
    int i = 0;

    while (str[i][0] != '\0') {
        raiz = inserirNo(raiz, str[i]);
        i++;
    }

    percorrerEmOrdem(raiz);
}

int main() {
    char* palavras[] = {
        "carro", 
        "navio", 
        "carro", 
        "aviao", 
        "carro",
        "camelo", 
        "carro", 
        "motocicleta", 
        "carro",
        "navio", 
        "aviao", 
        "carro", 
        "navio", 
        "\0"
    };

    processaPalavras(palavras);

    return 0;
}
