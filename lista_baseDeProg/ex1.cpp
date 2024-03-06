#include <iostream>
using namespace std;

int main(){

    int b, e, result = 1;

    cout << "Insira b: "; cin >> b;
    cout << "Insira e: "; cin >> e;

    for (int i=0; i<e; i++){

        result = result * b;

    }

    cout << "\nResult: " << result;

}
