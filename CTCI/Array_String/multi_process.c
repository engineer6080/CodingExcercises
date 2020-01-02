#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h> //wait
#include <unistd.h> //fork
//#include <sys/sysinfo.h> //processor information

void forkexample()
{
        /* needs <sys/sysinfo.h>
           printf("This system has %d processors configured and "
               "%d processors available.\n",
               get_nprocs_conf(), get_nprocs());
         */

        long number_of_processors = sysconf(_SC_NPROCESSORS_ONLN); //only needs unistd.h
        printf("System has %ld processors\n", number_of_processors);

        pid_t pid = fork();
        int status;

        // child process because return value zero
        if (pid == 0)

                printf("Hello from Child!\n");

        // parent process because return value non-zero.
        else{
                wait(&status); //wait for child to die so child WILL run first
                printf("Hello from Parent!\n");
        }

}
int main()
{
        forkexample();
        return 0;
}
