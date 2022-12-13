#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

sem_t sem1, sem2;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
int n, size;
int *a;

void *pop() {
    while (1) {
        sem_wait(&sem1);
        pthread_mutex_lock(&mutex);
        size--;
        printf("POP %5d|\t Size:%3d\n", a[size],size);
        sem_post(&sem2);
        pthread_mutex_unlock(&mutex);
    }
}

void *push() {
    while (1) {
        sem_wait(&sem2);
        pthread_mutex_lock(&mutex);
        
        a[size]= size+1;
        size++;
        printf("PUSH %4d|\t Size: %3d\n", a[size-1],size);
        sem_post(&sem1);
        pthread_mutex_unlock(&mutex);
    }
}

int main() {
    pthread_mutex_init(&mutex,NULL);

    printf("Array size: ");
    scanf("%d", &n);
    a = (int*) malloc(n*sizeof(int));
    sem_init(&sem1, 0, 0);
    sem_init(&sem2, 0, n);

    pthread_t p1, p2;

    pthread_create(&p1, NULL, push, NULL);
    pthread_create(&p2, NULL, pop, NULL);

    pthread_join(p1, NULL);
    pthread_join(p2, NULL);
    
    return 0;
}