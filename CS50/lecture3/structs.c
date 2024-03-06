#include <stdio.h>
#include <string.h>

typedef struct {
    char name[30];
    char number[15];
} person;

int main(){

    const int n = 2;
    person people[n];

    strcpy(people[0].name, "Carter"); // variavel = recebe
    strcpy(people[0].number, "+1-429-677-0021"); // variavel = recebe

    strcpy(people[1].name, "David"); // variavel = recebe
    strcpy(people[1].number, "+1-671-123-5066"); // variavel = recebe

    char nome[30];
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = 0; //remove o \n adicionado pelo fgets

    for (int i=0;i<n;i++){

        if(strcmp(people[i].name, nome) == 0){ // compara, se for igual: retorna 0

            printf("Found: %s\n", people[i].number);
            return 0;

        }
    }

    printf("Not found\n");
    return 1;

}