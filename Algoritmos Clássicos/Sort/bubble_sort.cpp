#include <iostream>
using namespace std;

/*

# Bubble Sort
- Ordenação para pequenos conjuntos de dados
- De dois em dois
*/ 


int main() {

    cout << "Bubble Sort: \n";
    const int n = 5;
    int vect[n] = {5,3,1,7,2};
    // compara de dois em dois, e faz inversão caso um seja menor

    for(int i=0;i<n;i++){
 
        for(int j=0;j<n-1;j++){
            if(vect[j] > vect[j+1]){
                int aux = vect[j];
                vect[j] = vect[j+1];
                vect[j+1] = aux;
            }
        }
 
    }

    cout << "| ";
    for(int i=0;i<n;i++){
        cout << vect[i] << " | " ;
    }

    return 0;
    
}