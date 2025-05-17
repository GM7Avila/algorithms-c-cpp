#include <iostream>
#include <chrono>  // Para medição de tempo

int main() {
    int a[10000], b[10000], c[10000];

    // Inicializando os arrays a e b
    for (int i = 0; i < 10000; ++i) {
        a[i] = i;
        b[i] = i + 1;
    }

    std::cout << "Inicializando arrays a e b..." << std::endl;

    // Medição de tempo para a versão serial
    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 1; i < 999; ++i) {
        c[i] = a[i] * b[i] + a[i-1] * b[i+1];

        // Log do cálculo (para monitorar)
        std::cout << "Cálculo de c[" << i << "] = " << c[i] << std::endl;
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    std::cout << "Tempo de execução (versão serial): " << duration.count() << " segundos." << std::endl;

    return 0;
}
