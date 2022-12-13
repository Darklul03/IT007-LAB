#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>

int wait = 5;
sem_t semS, semP;
int sells = 0, products = 0;

void msleep(int * pmilliseconds)  
{
    struct timespec ts_sleep = 
    {
        *pmilliseconds / 1000,
        (*pmilliseconds % 1000) * 1000000L
    };

    nanosleep(&ts_sleep, NULL);
}

void *processA() { // making product
    while (1) {
        sem_wait(&semP);
        products++;
        sem_post(&semS);
        printf("Products = %d\n", products);
        // msleep(&wait);
    }
}

void *processB() { // selling product
    while (1) {
        sem_wait(&semS);
        sells++;
        sem_post(&semP);
        printf("Sells = %d\n", sells);
        // msleep(&wait);
    }
}

int main() {
    sem_init(&semS, 0, 0); // products > sells
    sem_init(&semP, 0, 60); // sells+60 >= products
    
    pthread_t p1, p2;
    pthread_create(&p1, NULL, processA, NULL);
    pthread_create(&p2, NULL, processB, NULL);

    pthread_join(p1, NULL);
    pthread_join(p2, NULL);

    return 0;
}