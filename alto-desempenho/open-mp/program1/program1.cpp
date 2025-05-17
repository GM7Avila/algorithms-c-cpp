#include <iostream>
#include <omp.h>

// executa N threads, onde N é o número de processadores fisicos do computador (nucleos)
int main()
{
  // 1. Por variavel de ambiente: OMP_NUM_THREADS=5
  // 2. Pela função da Biblioteca: omp_set_num_threads(5);  (executa 5 threads)
  // 3. Setando diretamente no pragma: #pragma omp parallel num_threads(5) // executa 5 threads
  #pragma omp parallel // TODO: documentar
    {
        std::cout << "Hello World!\n";
    }
}