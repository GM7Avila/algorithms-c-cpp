/*SÉRIE DE FIBONACCI

  1,1,2,3,4,8,14,21,34,...

*/
#include <iostream>
using namespace std;

int main() {
    int num1 = 0, num2 = 0, fibonacci;

    cout << "Programa de Fibonacci\n";
    cout << "Série de Fibonacci\n";
    cout << "Insira num1: "; cin >> num1;

    for (int i = 1; i <= 15; i++) {
        fibonacci = num1 + num2;
        num1 = num2;
        num2 = fibonacci;

        cout << "\n" << fibonacci;
    }
}
