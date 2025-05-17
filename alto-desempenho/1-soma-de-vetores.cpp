#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <chrono>

using namespace std;
using namespace std::chrono;

/**
 * @brief Função que soma um peda o de um vetor de forma paralela,
 *        em uma região do vetor especificada por 'start' e 'end'.
 *
 * @param v Vetor cujos elementos devem ser somados
 * @param start Índice de in cio do peda o a ser somado
 * @param end   Índice de fim do peda o a ser somado
 * @param resultado Refer ncia para a soma total do vetor, que ser  atualizada
 * @param mtx Mutex usado para garantir exclus o m tual na atualiza o da soma
 *
 * A fun o soma_parcial  dividida em dois passos:
 *   1. Primeiramente, s o somados os elementos do vetor na regi o
 *      especificada por 'start' e 'end', e armazenada na vari vel
 *      'soma_local'.
 *   2. Em seguida, o valor de 'soma_local'  adicionado  soma total do
 *      vetor, que est  armazenada na vari vel 'resultado'. Para garantir
 *      exclus o m tual nessa atualiza o, usamos um mutex ( mtx ).
 */
void soma_parcial(const vector<int>& v, int start, int end, long long& resultado, mutex& mtx) {
    long long soma_local = 0;
    for (int i = start; i < end; ++i)
        soma_local += v[i];

    lock_guard<mutex> lock(mtx); // garante exclusão mútua
    resultado += soma_local;
}

/**
 * @brief Soma os elementos de um vetor de forma sequencial.
 *
 * @param v Vetor cujos elementos serão somados.
 *
 * @return Soma de todos os elementos de 'v'.
 *
 * A função percorre todos os elementos do vetor 'v', acumulando sua soma
 * na variável 'total', que é retornada no final.
 */
long long soma_sequencial(const vector<int>& v) {
    long long total = 0;
    for (int val : v)
        total += val;
    return total;
}

/**
 * @brief Soma os elementos de um vetor em paralelo, usando threads.
 *
 * @param v Vetor cujos elementos serão somados
 * @param num_threads Número de threads a serem criadas
 *
 * @return Soma de todos os elementos de 'v'
 *
 * A função soma os elementos do vetor 'v' em paralelo, dividindo o vetor em
 * 'num_threads' pedaços e criando uma thread para somar cada pedaço. O resultado
 * é guardado na variável 'resultado', que é compartilhada entre as threads. A
 * função aguarda todas as threads terminarem sua execução antes de retornar.
 *
 * @note A função assume que o vetor tem pelo menos 'num_threads' elementos.
 */
long long soma_paralela(const vector<int>& v, int num_threads) {
    vector<thread> threads;          // Vetor que guardará todas as threads criadas
    mutex mtx;                       // Mutex para proteger o acesso à variável 'resultado'
    long long resultado = 0;         // Acumulador global da soma (compartilhado entre threads)

    int chunk = v.size() / num_threads;  // Tamanho do pedaço do vetor que cada thread vai processar

    for (int i = 0; i < num_threads; ++i) {
        // índice de início do pedaço que esta thread vai processar
        int start = i * chunk;

        // A última thread pega o restante para garantir que todo o vetor seja processado
        int end = (i == num_threads - 1) ? v.size() : (i + 1) * chunk;

        // Cria e inicia uma nova thread, que executa a função 'soma_parcial'
        threads.emplace_back(
            soma_parcial,           // Função que a thread vai executar
            cref(v),                // Passa o vetor como referência constante
            start, end,             // Índices do pedaço do vetor que essa thread vai somar
            ref(resultado),         // Passa a referência para a variável compartilhada
            ref(mtx)                // Passa a referência para o mutex
        );
    }

    // Aguarda todas as threads terminarem sua execução
    for (auto& t : threads)
        t.join();

    return resultado;  // Retorna a soma total feita pelas threads
}

int main() {
    int n = 1e8;
    vector<int> v(n, 1); // vetor com 100 milhões de elementos valendo 1

    // SEQUENCIAL
    auto inicio_seq = high_resolution_clock::now();
    long long resultado_seq = soma_sequencial(v);
    auto fim_seq = high_resolution_clock::now();

    // PARALELO
    int p = thread::hardware_concurrency(); // número de threads do sistema
    auto inicio_par = high_resolution_clock::now();
    long long resultado_par = soma_paralela(v, p);
    auto fim_par = high_resolution_clock::now();

    // TEMPOS
    auto tempo_seq = duration_cast<milliseconds>(fim_seq - inicio_seq).count();
    auto tempo_par = duration_cast<milliseconds>(fim_par - inicio_par).count();

    // MÉTRICAS
    double speedup = double(tempo_seq) / tempo_par;
    double eficiencia = speedup / p;

    // RESULTADOS
    cout << "Resultado esperado: " << resultado_seq << "\n";
    cout << "Resultado paralelo: " << resultado_par << "\n";
    cout << "Tempo sequencial: " << tempo_seq << " ms\n";
    cout << "Tempo paralelo (" << p << " threads): " << tempo_par << " ms\n";
    cout << "Speedup: " << speedup << "\n";
    cout << "Eficiência: " << eficiencia * 100 << " %\n";

    return 0;
}