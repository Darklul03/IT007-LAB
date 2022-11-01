#include <pthread.h>
#include <stdio.h>

int main() {
    pthread_attr_t tattr;
    int ret;

    /* initialize an attribute to the default value */
    ret = pthread_attr_init(&tattr);
    
    int dState; pthread_attr_getdetachstate(&tattr, &dState);
    size_t gSize; pthread_attr_getguardsize(&tattr, &gSize);
    int inheSched; pthread_attr_getinheritsched(&tattr, &inheSched);
    struct sched_param param; pthread()

}