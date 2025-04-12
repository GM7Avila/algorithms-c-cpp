# Racing Condition

> _Race condition_ é um problema comum que acontece em programação concorrente, onde duas threads modificam o mesmo recurso simultaneamente, podendo gerar resultados inesperados.

No exemplo em questão, o código `ex1` tem duas threads que competem por um recurso compartilhado, que é a variável `contador`, sem proteção adequada.

```cpp
const int N = 100000;
int contador = 0;

void incrementar() {
    for (int i = 0; i < N; ++i)
        contador++; // região crítica sem proteção
}

int main() {
    thread t1(incrementar);
    thread t2(incrementar);

    t1.join();
    t2.join();

    cout << "Contador final (sem semáforo): " << contador << endl;

    return 0;
}
```

Como saída o valor contado acaba sendo um valor diferente de `100000`, ou seja, a soma fica com valor errado devido a esse conflito no acesso a variável contador.

## O que causa esse conflito?

Esse erro ocorre porque a operação de incremento `contador++` **não é atômica** . No caso do incremento, ele é composto por três etapas:

> Uma operação **atômica** é uma operação que é executada como uma unidade indivisível, ou seja, sem possibilidade de ser interrompida ou interferida por outra thread durante sua execução. Isso garante que a variável seja modificada de maneira consistente e sem risco de sobrescrição por outras threads.

1. **Leitura** do valor atual da variável `contador`.
2. **Incremento** desse valor;
3. **Escrita** do novo valor de volta na memória.

<img src="https://arshsharma.com/posts/2021-05-24-race-conditions-in-golang/2021-05-24-1.jpeg">

Sem proteção, essas três etapas podem ser interrompidas em qualquer ponto, o que pode causar o **problema da condição de corrida** .

### Região Crítica

Uma **região crítica** é uma parte do código onde o acesso a um recurso compartilhado (como uma variável ou estrutura de dados) precisa ser protegido para garantir que apenas uma thread possa acessá-lo de cada vez. No nosso exemplo, a linha `contador++` é uma região crítica, pois várias threads estão tentando modificar a variável `contador` ao mesmo tempo.

Quando uma thread está dentro da região crítica, ela deve garantir **exclusão mútua** , ou seja, impedir que outra thread acesse a mesma região ao mesmo tempo.

> **Exclusão mútua** significa que, quando uma thread está executando uma operação crítica, nenhuma outra thread pode interferir ou acessar esse recurso compartilhado até que a thread original tenha terminado. Isso garante que as operações sejam feitas de forma consistente e sem interferência, evitando resultados incorretos.

## Estratégia de Solução: Semáforo

Para resolver esse problema, podemos usar **semáforos**. Semáforos são mecanismos de sincronização que controlam o acesso a recursos compartilhados em ambientes de programação concorrente. Com um semáforo, conseguimos garantir que apenas uma thread possa acessar a região crítica de cada vez, evitando a condição de corrida.

```cpp
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
    sem_init(&sem, 0, 1); // semáforo inicializado com 1 (exclusão mútua)

    thread t1(incrementar);
    thread t2(incrementar);

    t1.join();
    t2.join();

    sem_destroy(&sem);

    cout << "Contador final (com semáforo): " << contador << endl;

    return 0;
}
```

- **sem_init(&sem, 0, 1);** — Inicializa o semáforo `sem` com um valor inicial de `1`, o que garante que apenas uma thread pode entrar na seção crítica por vez.
- **sem_wait(&sem);** — A função `sem_wait()` é chamada antes de acessar a região crítica. Ela diminui o valor do semáforo, bloqueando a entrada de outras threads caso o semáforo já tenha o valor `0`.
- **sem_post(&sem);** — A função `sem_post()` é chamada após a execução da região crítica, aumentando o valor do semáforo e permitindo que outras threads possam entrar na região crítica.

Usar semáforos para controlar o acesso a uma região crítica garante que as operações dentro dessa região sejam atômicas, ou seja, executadas de maneira indivisível, sem interrupções. Isso resolve o problema de race condition e assegura que a variável `contador` seja corretamente incrementada pelas duas threads, sem sobrescrita de dados.
