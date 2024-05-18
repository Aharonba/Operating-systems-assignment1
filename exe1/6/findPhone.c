#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define READ_END 0
#define WRITE_END 1

// Helper function to execute a command using execvp
void execute_command(char *cmd, char *argv[])
{
    if (execvp(cmd, argv) == -1)
    {
        perror("execvp failed");
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char *argv[])
{
    // Check if the number of arguments is correct
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s \"Full Name\"\n", argv[0]);
        return 1;
    }

    // Create two pipes for inter-process communication
    int pipe1[2], pipe2[2];

    if (pipe(pipe1) == -1 || pipe(pipe2) == -1)
    {
        perror("pipe failed");
        return 1;
    }

    pid_t id1, id2, id3;

    // First child process: executes the grep command
    if ((id1 = fork()) == 0)
    {
        // Redirect stdout to pipe1 write end
        dup2(pipe1[WRITE_END], STDOUT_FILENO);

        close(pipe1[READ_END]);
        close(pipe1[WRITE_END]);

        // Prepare and execute the sed command

        char *grep_args[] = {"grep", argv[1], "phonebook.txt", NULL};
        execute_command("grep", grep_args);
    }

    // Second child process: executes sed 's/ /#/g'
    if ((id2 = fork()) == 0)
    {
        // Redirect stdin to pipe1 read end
        dup2(pipe1[READ_END], STDIN_FILENO);

        close(pipe1[WRITE_END]);
        // Redirect stdout to pipe2 write end
        dup2(pipe2[WRITE_END], STDOUT_FILENO);
        close(pipe2[READ_END]);
        close(pipe2[WRITE_END]);

        // Prepare and execute the sed command
        char *sed_args[] = {"sed", "s/ /#/g", NULL};
        execute_command("sed", sed_args);
    }

    close(pipe1[READ_END]);
    close(pipe1[WRITE_END]);
    close(pipe2[WRITE_END]);

    // Third child process: executes sed 's/,/ /'
    if ((id3 = fork()) == 0)
    {
        // Redirect stdin to pipe2 read end
        dup2(pipe2[READ_END], STDIN_FILENO);

        close(pipe2[READ_END]);

        // Prepare and execute the sed command
        char *sed_args[] = {"sed", "s/,/ /", NULL};
        execute_command("sed", sed_args);
    }

    close(pipe2[READ_END]);

    // Parent process waits for all child processes to finish
    waitpid(id1, NULL, 0);
    waitpid(id2, NULL, 0);
    waitpid(id3, NULL, 0);

    return 0;
}
