#include <pthread.h>
#include <stdlib.h>

#define NUM_THREADS 5

static pthread_mutex_t func_mutex = PTHREAD_MUTEX_INITIALIZER;

void func()
{
    pthread_mutex_lock(&func_mutex);
    // tu coś więcej...
    pthread_mutex_unlock(&func_mutex);
}

void *worker(void *arg)
{
    int value = *((int *)arg);
    // tu więcej logiki...
    return 0;
}

int main(int argc, char **argv)
{
    pthread_t threads[NUM_THREADS];
    int thread_args[NUM_THREADS];
    int result_code;

    for (unsigned int i = 0; i < NUM_THREADS; i++)
    {
        thread_args[i] = i;
        result_code = pthread_create(&threads[i], 0, worker, (void *)&thread_args[i]);
    }
    for (int i = 0; i < NUM_THREADS; i++)
    {
        result_code = pthread_join(threads[i], 0);
    }
    exit(0);
}