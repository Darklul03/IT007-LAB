#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

int x = 0;

void *processA() {
    while (1) {
        x++;
        if (x == 20)
            x = 0;
        printf("A: %d\n", x);
    }
}

void *processB() {
    while (1) {
        x++;
        if (x == 20)
            x = 0;
        printf("B: %d\n", x);
    }
}

int main() {
    pthread_t p1, p2;
    pthread_create(&p1, NULL, processA, NULL);
    pthread_create(&p2, NULL, processB, NULL);

    pthread_join(p1, NULL);
    pthread_join(p2, NULL);

    return 0;
}