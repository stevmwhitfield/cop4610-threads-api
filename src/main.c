#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void* fib(void*);
void* parent(void*);

int f[1000];

int main(int argc, char** argv) {
    if (argc != 2) {
        fprintf(stderr, "Error! Program accepts 1 argument.\n");
        return -1;
    }

    int n = atoi(argv[1]);
    if (n < 1) {
        fprintf(stderr, "Error! Argument must be a positive integer.\n");
        return -1;
    }

    pthread_t pthread_id;
    pthread_create(&pthread_id, NULL, parent, (void*)argv[1]);
    pthread_join(pthread_id, NULL);

    return 0;
}

void* parent(void* arg) {
    int n = atoi(arg);

    pthread_t cthread_id;
    pthread_create(&cthread_id, NULL, fib, (void*)arg);
    pthread_join(cthread_id, NULL);

    printf("Number: %d\n", f[n - 1]);
    printf("Sequence: ");

    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", f[i]);
    }
    printf("\n");

    return 0;
}

void* fib(void* arg) {
    int n = atoi(arg);

    f[0] = 0;
    f[1] = 1;
    if (n > 1) {
        int i;
        for (i = 2; i < n; i++) {
            f[i] = f[i - 1] + f[i - 2];
        }
    }

    return 0;
}
