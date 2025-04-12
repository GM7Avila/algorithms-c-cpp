#include <iostream>
#include <thread>

using namespace std;

const int N = 100000;
int contador = 0;

void incrementar() {
    for (int i = 0; i < N; ++i)
        contador++;
}

int main() {
    thread t1(incrementar);
    thread t2(incrementar);

    t1.join();
    t2.join();

    cout << "Contador final (sem semáforo): " << contador << endl;

    return 0;
}
