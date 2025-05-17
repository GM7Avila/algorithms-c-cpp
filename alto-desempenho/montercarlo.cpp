#include <iostream>
#include <random>
#include <pthread.h>

void* worker(void* arg) {
  auto* pIter = static_cast<unsigned long long*>(arg);                          // iterações recebidas
  unsigned long long iterations = *pIter;

  // gerador pseudo-aleatório
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_real_distribution<> dis(0.0, 1.0);

  // contagem dos pontos
  unsigned long long inside = 0;
  for (unsigned long long i = 0; i < iterations; ++i){
    double x = dis(gen);
    double y = dis(gen);
    if(x * x + y * y <= 1.0){
      ++inside;
    }
  }

  *pIter = inside;                                                              // devolve o resultado usando o mesmo ponteiro
  return nullptr;
}

int main(){
  const unsigned long long totalIter = 1'000'000ULL;                            // num. de iterações
  const unsigned numThreads = 8;                                                // num. de threads

  unsigned long long itrPerThreads = totalIter / numThreads;                    // qtd. de iterações por thread
  unsigned long long resto = totalIter % numThreads;                            // restante caso a divisão não seja exata

  pthread_t threads[numThreads];                                                // vetor de ID das threads
  unsigned long long work[numThreads];                                          // armazena quantas iterações realizar (inicialmente) + resultado das iterações (final)

  /* criando as threads */
  for(unsigned t=0; t < numThreads; ++t) {
    work[t] = itrPerThreads + (t < resto ? 1 : 0);                              // distribui uma sobra por thread (se houver)
    if (pthread_create(&threads[t], nullptr, worker, &work[t]) != 0){
      std::perror("pthread_create");
      return 1;
    }
  }

  /* espera todas terminarem */
  for (unsigned t = 0; t < numThreads; ++t)
        pthread_join(threads[t], nullptr);

  /* soma total de pontos dentro do círculo */
  unsigned long long totalInside = 0;
  for (unsigned t = 0; t < numThreads; ++t)
    totalInside += work[t];

  double pi = 4.0 * static_cast<double>(totalInside) / static_cast<double>(totalIter);

  std::cout << "Iterações : " << totalIter   << '\n'
            << "Threads   : " << numThreads    << '\n'
            << "Dentro    : " << totalInside << '\n'
            << "π ≈ "        << pi           << '\n';

  return 0;
}