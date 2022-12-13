#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

int x[] = {0, 1, 2, 3, 4, 5, 6};
int w, v, y, z, ans;
sem_t semC, semD, semE, semF, semG;

void *processA() {
    w = x[1] * x[2];
    sem_post(&semE);
    sem_post(&semF);
}

void *processB() {
    v = x[3] * x[4];
    sem_post(&semC);
    sem_post(&semD);
}

void *processC() {
    sem_wait(&semC);
    y = v * x[5];
    sem_post(&semE);
}

void *processD() {
    sem_wait(&semD);
    z = v * x[6];
    sem_post(&semF);
}

void *processE() {
    sem_wait(&semE);
    sem_wait(&semE);
    y = w * y;
    sem_post(&semG);
}

void *processF() {
    sem_wait(&semF);
    sem_wait(&semF);
    z = w * z;
    sem_post(&semG);
}

void *processG() {
    sem_wait(&semG);
    sem_wait(&semG);
    ans = y+z;
    printf("Ans: %d\n", ans);
}

int main() {
    pthread_t p1, p2, p3, p4, p5, p6, p7;
    pthread_create(&p1, NULL, processA, NULL);
    pthread_create(&p2, NULL, processB, NULL);
    pthread_create(&p3, NULL, processC, NULL);
    pthread_create(&p4, NULL, processD, NULL);
    pthread_create(&p5, NULL, processE, NULL);
    pthread_create(&p6, NULL, processF, NULL);
    pthread_create(&p7, NULL, processG, NULL);

    pthread_join(p1, NULL);
    pthread_join(p2, NULL);
    pthread_join(p3, NULL);
    pthread_join(p4, NULL);
    pthread_join(p5, NULL);
    pthread_join(p6, NULL);
    pthread_join(p7, NULL);

    return 0;
}