#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

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
    //exec example ###################################################
    exec_example();
    printf("Mevcut program devam ediyor. PID: %d\n", getpid());
    int a = 0;
    scanf("%d", &a);
    */
    return 0;
}
