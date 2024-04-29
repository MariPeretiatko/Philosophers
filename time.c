# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>

int main() {
    struct timeval start_time, end_time;
    double elapsed_time;

    // Записываем время перед выполнением программы
    if (gettimeofday(&start_time, NULL) != 0) {
        perror("gettimeofday");
        return 1;
    }

    // Ваш код программы здесь
    // milliseconds
    usleep(1000000);

    // Записываем время после выполнения программы
    if (gettimeofday(&end_time, NULL) != 0) {
        perror("gettimeofday");
        return 1;
    }

    // Вычисляем разницу между временами в миллисекундах
    elapsed_time = (end_time.tv_sec - start_time.tv_sec) * 1000.0; // Секунды в миллисекунды
    elapsed_time += (end_time.tv_usec - start_time.tv_usec) / 1000.0; // Микросекунды в миллисекунды

    // Выводим результат
    printf("Время выполнения программы: %.2f миллисекунд\n", elapsed_time);

    return 0;
}
