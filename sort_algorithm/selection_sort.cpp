#include <iostream>
using namespace std;

int main() {
    // ordenação do Array - Select Sort
    // utilização - vetores menores
    // comparacoes = (n^2)/2 - onde n, é o numero de elementos

    cout << "Selection Sort: \n";
    
    const int n = 5;
    int vect[n] = {5,3,1,7,2};

    //print inicial
    for (int i=0; i<n; i++){
        cout << vect[i];
    }
    cout << "\n\nOrdenando...\n\n";
    
    for (int j=0; j<=n; j++){
        for(int i=j+1 ; i<=n ; i++){ //começa na próxima posição referente ao i
            if(vect[j]>vect[i]){
                // i é menor que j
                int aux = vect[i];
                vect[i] = vect[j];
                vect[j] = aux;
            }
        }
    }

    //print ordenado
    for (int i=0; i<n; i++){
        cout << vect[i];
    }

    return 0;
    
}