#include <pthread.h>
#include <stdio.h>

int fib(int);

int f[1000];

int main(int argc, char** argv) { return 0; }

int fib(int n) {
    f[0] = 0;
    f[1] = 1;
    if (n > 1) {
        int i;
        for (i = 2; i < n; i++) {
            f[i] = f[i - 1] + f[i - 2];
        }
    }
    return f[n - 1];
}
