#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    pid_t pid;
    pid = fork();

    if(pid == 0)
    {
        int i = 0;
        while(1)
        {
            printf("this is child process i = %d\n", i++);
            printf("this is child process, my pid = %d\n", getpid());
            printf("this is child process, my ppid = %d\n", getppid());
            sleep(1);
            if(i == 10)
            {
                return 0;
            }
        }
    }
    else if(pid > 0)
    {
        int i = 0;
        while(1)
        {
            printf("this is parent process i = %d\n", i++);
            printf("this is parent process, my pid = %d\n", getpid());
            sleep(1);
            if(i == 15)
            {
                return 0;
            }
        }
    }
    else
    {
        perror("fork");
        exit(1);
    }
    return 0;
}
