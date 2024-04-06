#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include<signal.h>

int first_example() {
    pid_t pid;

    // Yeni bir process oluştur
    pid = fork();

    if (pid < 0) { // fork() çağrısı başarısız oldu
        fprintf(stderr, "Fork failed.\n");
        return 1;
    } else if (pid == 0) { // Çocuk süreç
        printf("Bu çocuk süreçtir. PID: %d\n", getpid());
        printf("pid: %d\n", pid);
    } else { // Ebeveyn süreç
        printf("Bu ebeveyn süreçtir. PID: %d, Çocuk PID: %d\n", getpid(), pid);
    }

}

int second_example() {
    pid_t pid;

    pid = fork();

    if (pid < 0) { // fork() çağrısı başarısız oldu
        fprintf(stderr, "Fork failed.\n");
        return 1;
    } else if (pid == 0) { // Çocuk süreç
        printf("Child process deyiz getpid dersen mantıken child process in PID ni alırsın\n");
        printf("Bu child process. PID: %d\n", getpid());

        printf("child process pid değerini 0 olarak görür\n");
        printf("pid: %d\n", pid);
    } else { // Ebeveyn süreç
        printf("Parent Process\n");
        printf("Bu ebeveyn süreçtir. PID: %d, Çocuk PID: %d\n", getpid(), pid);
    }
}

int third_example() {
    fork();
    fork();
    fork();
    printf("hello\n");
}

void fourth_example() {
    int x = 1;
    pid_t p = fork();
      if(p<0){
      perror("fork fail");
    }
    else if (p == 0){
        printf("In Child\n");
        printf("Child has x = %d\n", ++x);
    } 
    else {
        printf("In Parent\n");
        printf("Parent has x = %d\n", --x);
    }
}

void exec_example() {
    pid_t pid;
    pid = fork();

    if (pid < 0) { // fork() çağrısı başarısız oldu
        fprintf(stderr, "Fork failed.\n");
    } else if (pid == 0) { // Çocuk süreç
        printf("Bu child process. PID: %d\n", getpid());
        execl("./exec_example_prog", "exec_example_prog", NULL);

        // Eğer execl çağrısı başarısız olursa, bu kod çalışır
        perror("exec failed");
        printf("pid: %d\n", pid);

    } else { // Ebeveyn süreç
        printf("Bu parent process. PID: %d, Çocuk PID: %d\n", getpid(), pid);
    }
}

void wait_example() {
    pid_t pid;
    pid_t pid_terminated;
    pid = fork();
    if (pid == 0){
        printf("Child Process: %d\n", pid);
        exit(0);           /* terminate child */
    } else {
        pid_terminated = wait(NULL); /* reaping parent */
        printf("Parent pid = %d\n", getpid());
        printf("Child pid = %d\n", pid);
        printf("termianted pid = %d\n", pid_terminated);
    }
}
void wait_example_2() {
    if (fork()== 0){
        printf("HC: hello from child\n");
        exit(0);
    }
    else {
        printf("HP: hello from parent\n");
        wait(NULL);
        printf("CT: child has terminated\n");
    }
 
    printf("Bye\n");
}

void wait_example_2_1() {
    if (fork()== 0){
        printf("HC: hello from child\n");
    }
    else {
        printf("HP: hello from parent\n");
        wait(NULL);
        printf("CT: child has terminated\n");
    }
 
    printf("Bye\n");
}

void wait_example_3() {
    int stat;
 
    // This status 1 is reported by WEXITSTATUS
    if (fork() == 0)
        exit(1);
    else {
        wait(&stat);
        printf("stat: %d", stat);
        printf("stat: %p", &stat);
    }
    if (WIFEXITED(stat)) {
        printf("Exit status: %d\n", WEXITSTATUS(stat));
        printf("stat: %d", stat);
        printf("stat: %p", &stat);
    }
    else if (WIFSIGNALED(stat)) {
        psignal(WTERMSIG(stat), "Exit signal");
    }
}

void wait_example_4() {
    int i, stat;
    pid_t pid[5];
    for (i=0; i<5; i++)
    {
        if ((pid[i] = fork()) == 0)
        {
            sleep(10);
            exit(100 + i);
        }
    }
 
    // Using waitpid() and printing exit status
    // of children.
    for (i=0; i<5; i++)
    {
        pid_t cpid = waitpid(pid[i], &stat, 0);
        if (WIFEXITED(stat))
            printf("Child %d terminated with status: %d\n",
                   cpid, WEXITSTATUS(stat));
    }
}

//ctrl c
void handle_sigint(int sig) 
{ 
    printf("Caught signal %d\n", sig); 
}

void signals_example() {
    signal(SIGINT, handle_sigint); 
    while (1) 
    { 
        //printf("hello world\n"); 
        sleep(1); 
    } 
}

int main() {
    //Sadece bir fonskyionu ve printi açık bırakarak yaz yoksa karışır
    //printf("\n First Example #################################\n");
    //first_example();

    //printf("\n Second Example #################################\n");
    //first_example();

    //printf("\n Third Example #################################\n");
    //third_example();

    //printf("\n Fourth Example #################################\n");
    //fourth_example();

    /*
    printf("\n exec example #################################\n");
    //exec example ###################################################
    exec_example();
    printf("Mevcut program devam ediyor. PID: %d\n", getpid());
    printf("deger giriniz: ");
    int a = 0;
    scanf("%d", &a);
    */

    //wait_example();
    //wait_example_2();
    //wait_example_2_1();
    //wait_example_3();
    wait_example_4();
    //signals_example();

    return 0;
}
