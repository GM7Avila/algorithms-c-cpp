#include <iostream>
using namespace std;
    /*
    # InsertionSort

    ## DESCRICAO
        Ordenação de cartas de baralho com as mãos: pega uma carta e a coloca em seu lugar, sempre deixando em ordem;

    ## PERFORMANCE
        Pior caso: O(N^2)
        Eficiente para conjuntos pequenos de dados
        Estável: não altera a ordem de dados iguais
        Capaz de ordenar os dados em demanda (tempo real)
    */

int main() {

    const int n = 4;
    int vect[n] = {1,14,31,2};

    for(int i=0; i<n ; i++){
        cout << vect[i] << "\n";
    }

    cout << "\nInsertion Sort:\n";

    for(int i=0; i<n ; i++){

        int key = vect[i];
        int j = i-1;

        // Compara a variavel key com cada elemento na esquerda até encontrar um elemnto menor que o atual.
        while(key < vect[n] && j >= 0){
            vect[j+1] = vect[j];
            j--;
        }

        vect[j+1] = key;

    }

    for(int i=0; i<n ; i++){
        cout << vect[i] << "\n";
    }


    return 0;

}
