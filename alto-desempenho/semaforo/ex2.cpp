#include <iostream>
#include <thread>
#include <semaphore.h>

using namespace std;

const int N = 100000;
int contador = 0;
sem_t sem;

void incrementar() {
    for (int i = 0; i < N; ++i) {
        sem_wait(&sem);   // entra na seção crítica
        contador++;
        sem_post(&sem);   // sai da seção crítica
    }
}

int main() {
    sem_init(&sem, 0, 1); // exclusão mútua

    thread t1(incrementar);
    thread t2(incrementar);

    t1.join();
    t2.join();

    sem_destroy(&sem);

    cout << "Contador final (com semáforo): " << contador << endl;

    return 0;
}