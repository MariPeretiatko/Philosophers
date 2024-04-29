#include <stdio.h>
#include <pthread.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER; // Инициализация мьютекса
int shared_variable = 0;

// Функция, которая будет выполнена в каждом потоке
void *thread_func(void *arg) {
    for (int i = 0; i < 5; ++i) {
        // Захватываем мьютекс перед доступом к общей переменной
        pthread_mutex_lock(&mutex);
        shared_variable++;
        printf("Поток %ld: общая переменная увеличена до %d\n", pthread_self(), shared_variable);
        // Освобождаем мьютекс после доступа к общей переменной
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

int main() {
    pthread_t tid1, tid2;

    // Создаем первый поток
    pthread_create(&tid1, NULL, thread_func, NULL);

    // Создаем второй поток
    pthread_create(&tid2, NULL, thread_func, NULL);

    // Ожидаем завершения выполнения обоих потоков
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    // Уничтожаем мьютекс после его использования
    pthread_mutex_destroy(&mutex);

    printf("Задачи выполнены асинхронно с использованием мьютекса\n");

    return 0;
}
