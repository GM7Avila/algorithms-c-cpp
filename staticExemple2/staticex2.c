#include <stdio.h>

int a; //variável globa não inicializada atribui valor 0

void print_var(void)
{

    int i_local_temp = 0;
    static i_static = 0;

    i_local_temp++;
    i_static++;

    printf("i_local_temp: %i, i_static: %i\n", i_local_temp, i_static);

    int temp=1; //variavel inicializada a cada bloco
}


int main() 
{

    int temp; //variavel inicializada novamente, não recebe 1
    printf("var local n inicializada: %i\n" , temp);
    printf("var global n inicializada: %i\n", a); 

    print_var();
    print_var();
    print_var();

    return 0;

}