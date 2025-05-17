#include <iostream>
#include <omp.h>
#include <chrono>

int main() {
    int a[10000], b[10000], c[10000];

    for (int i = 0; i < 10000; ++i) {
        a[i] = i;
        b[i] = i + 1;
    }

    std::cout << "Inicializando arrays a e b..." << std::endl;

    auto start = std::chrono::high_resolution_clock::now();

    // Usando OpenMP para paralelizar o loop
    #pragma omp parallel for // para cada i do for, abre uma thread
    for (int i = 1; i < 999; ++i) {
        c[i] = a[i] * b[i] + a[i-1] * b[i+1];

        #pragma omp critical
        {
            std::cout << "Thread " << omp_get_thread_num() << " calculou c[" << i << "] = " << c[i] << std::endl;
        }
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    std::cout << "Tempo de execução (versão paralela): " << duration.count() << " segundos." << std::endl;

    return 0;
}

// Tempo de execução (versão paralela): 0.00610395 segundos.
// Tempo de execução (versão serial): 0.00387464 segundos.
// |--> gasta mais tempo paralelizando e criando threads do que em sequencial