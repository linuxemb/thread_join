#include <pthread.h>
#include <stdio.h>

void *func(void *arg)    // take hi char string's address.
{
    printf("child thread says %s\n", (char *)arg);
    sleep(3);
    pthread_exit((void *)99);
}

int main()
{
    pthread_t handle;
    int exitcode;

    pthread_create(&handle, NULL, func, "hi!"); // Hi is passed as arg, 
    printf("primary thread says hello\n");
    pthread_join(handle, (void **)&exitcode);
    printf("exit code %d\n", exitcode);
}
