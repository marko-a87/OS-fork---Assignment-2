#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int num, status;
    pid_t pid1, pid2;

    // Enter an integer in the range
    printf("Ener an integer in the range:\n");
    scanf("%d", &num);

    // Input error
    if (num < 1 || num >= 10)
    {
        printf("Input error\n");
        exit(0);
    }

    // Create child process
    pid1 = fork();
    if (pid1 == 0)
    {
        // Child[0] process running
        printf("Child[0] process running \n");
        for (int i = 10; i <= 10 + num; i++)
        {
            printf("%d\n", i);
        }
        exit(0);
    }
    else if (pid1 < 0)
    {
        // Fork for Child[0] failed
        perror("Child fork failed");
        exit(1);
    }

    pid2 = fork();
    if (pid2 == 0)
    {
        // Child[1] process running
        printf("Child[1] process running \n");
        for (int i = 20; i <= 20 + num; i++)
        {
            printf("%d\n", i);
        }
        exit(0);
    }
    else if (pid2 < 0)
    {
        // Fork for Child[1] failed
        perror("Child fork failed");
        exit(1);
    }

    waitpid(pid1, &status, 0); // Wait for the child process 1 to finish
    waitpid(pid2, &status, 0); // Wait for the child process 2 to finish

    // Resume Parent process

    printf("Parent process is running\n");
    for (int i = 0; i <= num; i++)
    {
        printf("%d\n", i);
    }

    // Parent process ending");
    return 0;
}
