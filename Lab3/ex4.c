#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

pid_t pid = -1;

void on_sigint() {
    kill(pid, SIGKILL);
    printf("\nYou are pressed CTRL+C! Goodbye!\n");
    exit(0);
}

int main() {
    printf("Welcome to IT007, I am 21521050\n");
    pid = fork();
    if (pid == 0) {
        execlp("vi", "abcd.txt", NULL);
        return 255;
    }

    signal(SIGINT, on_sigint);
    while(1) {
        sleep(1);
    }
}
