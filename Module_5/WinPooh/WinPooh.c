#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int honey = 0; // бочка с медом
int bee_honey_production; // количество производимого пчелой меда
pthread_mutex_t mutex; // мьютекс для бочки с медом
void *beeWork(void *param); // функция работы пчелы

int main(int argc, char *argv[]) {
    
    // параметры
    int bee_num, pooh_time, pooh_honey_need;
    printf("Введите количество пчел: ");
    scanf("%d", &bee_num);
    printf("Введите количество меда, добываемое одной пчелой за раз: ");
    scanf("%d", &bee_honey_production);
    printf("Ввдите потребность (порцию) Винни-Пуха в меде за один раз: ");
    scanf("%d", &pooh_honey_need);
    printf("Введите время (сек) потребления меда/простаивания Винни-Пуха: ");
    scanf("%d", &pooh_time);
    int no_food_time = 0; // флаг того, что Пух жил без питания
    
    // создаем потоки
    pthread_mutex_init(&mutex, NULL);
    pthread_t *tid = (pthread_t*)malloc(bee_num*sizeof(pthread_t));
    int *bee_id = (int*)malloc(bee_num*sizeof(int));
    for (int i = 0; i < bee_num; i++) {
        bee_id[i] = i + 1;
        pthread_create(tid + i, NULL, beeWork, bee_id + i);
    }
    
    // потребление Винни-Пухом меда
    while (1) {
        pthread_mutex_lock(&mutex);
        // проверяем пустоту бочки
        if (honey <= pooh_honey_need) {
            if (no_food_time) {
                printf("Недостаточно меда, Винни-Пух больше не может ждать\n");
                for (int i = 0; i < bee_num; i++) {
                    pthread_cancel(tid[i]);
                }
                break;
            }
            else {
                printf("Недостаточно меда, Винни-Пух ждет, ");
                no_food_time++;
            }
        }
        else {
            // Пух съедает порцию
            printf("Винни-Пух поел мед, ");
            no_food_time = 0;
            honey -= pooh_honey_need;
        }
        printf("меда в бочке: %d\n", honey);
        pthread_mutex_unlock(&mutex);
        sleep(pooh_time); // время поедания меда или простоя
    }
    free(tid);
    return 0;
}

// работа пчелы (парметр - id пчелы для вывода)
void *beeWork(void *param) {
    while (1) {
        pthread_mutex_lock(&mutex);
        honey += bee_honey_production; // пчела добывает мед
        printf("Пчела %d добыла мед, в бочке теперь: %d\n", *((int*)param), honey);
        pthread_mutex_unlock(&mutex);
        sleep(rand()%5 + 1); // пчела задерживается на случайное время (от 1 до 5 сек)
        pthread_testcancel();
    }
}
