#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    int fd[2];
    char str[1024] = "Hello Wenjia\n";
    char buf[1024];
    pid_t pid;
    
    if (pipe(fd) < 0) {
        perror("pipe");
        exit(1);
    }
    
    pid = fork();
    
    if(pid > 0) {
        close(fd[0]);
        sleep(2);
        write(fd[1], str, strlen(str));
        wait(NULL);
    }
    else if (pid == 0) {
        int len;
        close(fd[1]);
        len = read(fd[0], buf, sizeof(buf));
        write(STDOUT_FILENO, buf, len);
    }
    else {
        perror("fork");
        exit(1);
    }
    return 0;
}