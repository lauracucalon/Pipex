#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int pipefd[2];
    int pipe_status;
    char buf[31]; //recuerda que '31' es el tamaño del buffer pero la posición va de la 0 a la 30 entonces.

    pipe_status = pipe(pipefd);

    // Error occurred while pipe()
    if (pipe_status == -1)
    {
        perror("pipe");
        return 1;
    }

    pid_t pid = fork();

    if (pid == -1)
    {
        // Error occurred while forking
        perror("fork");
        return 1;
    }
    else if (pid == 0)
    {
        // Child process
        close(pipefd[0]);
        buf[30] = '\0';
        write(pipefd[1], "Hello from the child process!\n", 30);
        close(pipefd[1]);
    }
    else
    {
        // Parent process
        waitpid(pid, NULL, 0);
        // Waits for the child to finish
        close(pipefd[1]);
        read(pipefd[0], buf, 30);
        //printf("%s", buf);
        //printf("Hello from the parent process! %d\n", pid);
        close(pipefd[0]);
        // Add parent process code here
    }

    return 0;
}
