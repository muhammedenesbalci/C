#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/msg.h>

#define SHM_SIZE 1024

void communication_shared_memory_1() {
    key_t key = ftok("/tmp", 'A'); // Ortak bir key oluştur

    int shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666); // Paylaşılan bellek segmenti oluştur
    if (shmid == -1) {
        perror("shmget");
        exit(EXIT_FAILURE);
    }

    char *shmaddr = shmat(shmid, NULL, 0); // Paylaşılan belleği bağla
    if (shmaddr == (char *) -1) {
        perror("shmat");
        exit(EXIT_FAILURE);
    }

    // fork() ile yeni bir süreç oluştur
    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        // Çocuk süreç
        const char* message_child = "Bu veri çocuk süreçten geliyor!";
        strcpy(shmaddr, message_child);
        printf("Çocuk süreçten paylaşılan belleğe yazılan veri: %s\n", shmaddr);
    } else {
        // Ebeveyn süreç
        const char* message_parent = "Bu veri ebeveyn süreçten geliyor!";
        strcpy(shmaddr, message_parent);
        printf("Ebeveyn süreçten paylaşılan belleğe yazılan veri: %s\n", shmaddr);
    }

    // Paylaşılan belleği serbest bırak
    shmdt(shmaddr);
}

void communication_shared_memory_2() {
     key_t key = ftok("/tmp", 'A'); // Ortak bir key oluştur

    int shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666); // Paylaşılan bellek segmenti oluştur
    if (shmid == -1) {
        perror("shmget");
        exit(EXIT_FAILURE);
    }

    char *shmaddr = shmat(shmid, NULL, 0); // Paylaşılan belleği bağla
    if (shmaddr == (char *) -1) {
        perror("shmat");
        exit(EXIT_FAILURE);
    }

    // fork() ile yeni bir süreç oluştur
    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        // Çocuk süreç
        const char* message_child = "Bu veri çocuk süreçten geliyor!";
        strcpy(shmaddr, message_child);
        printf("Çocuk süreçten paylaşılan belleğe yazılan veri: %s\n", shmaddr);
        exit(EXIT_SUCCESS); // Çocuk süreci başarılı bir şekilde sonlandırılır
    } else {
        // Ebeveyn süreç
        const char* message_parent = "Bu veri ebeveyn süreçten geliyor!";
        strcpy(shmaddr, message_parent);
        printf("Ebeveyn süreçten paylaşılan belleğe yazılan veri: %s\n", shmaddr);
        
        // Ebeveyn süreçten gelen veriyi çocuk süreçte yazdır
        wait(NULL); // Çocuk sürecin tamamlanmasını bekle
        printf("Çocuk süreçten gelen veri: %s\n", shmaddr);
    }

    // Paylaşılan belleği serbest bırak
    shmdt(shmaddr);
}

#define MAX_SIZE 1024

// Mesaj yapısı
struct msg_buffer {
    long msg_type;
    char msg_text[MAX_SIZE];
};

void communication_message_queue() {
    key_t key;
    int msg_id;

    // Key oluşturma
    key = ftok("/tmp", 'A');
    if (key == -1) {
        perror("ftok");
        exit(EXIT_FAILURE);
    }

    // Message Queue oluşturma
    msg_id = msgget(key, 0666 | IPC_CREAT);
    if (msg_id == -1) {
        perror("msgget");
        exit(EXIT_FAILURE);
    }

    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        // Çocuk süreç
        struct msg_buffer message;
        message.msg_type = 1;

        printf("Çocuk süreç: Lütfen bir mesaj girin: ");
        fgets(message.msg_text, MAX_SIZE, stdin);

        // Mesajı Message Queue'ya gönderme
        if (msgsnd(msg_id, &message, sizeof(message), 0) == -1) {
            perror("msgsnd");
            exit(EXIT_FAILURE);
        }

        printf("Çocuk süreç: Mesaj başarıyla gönderildi.\n");
    } else {
        // Ebeveyn süreç
        struct msg_buffer message;

        // Mesajı Message Queue'dan alma
        if (msgrcv(msg_id, &message, sizeof(message), 1, 0) == -1) {
            perror("msgrcv");
            exit(EXIT_FAILURE);
        }

        printf("Ebeveyn süreç: Alınan mesaj: %s", message.msg_text);

        // Message Queue silme
        if (msgctl(msg_id, IPC_RMID, NULL) == -1) {
            perror("msgctl");
            exit(EXIT_FAILURE);
        }
    }
}
int main() {
    //communication_shared_memory_1();
    //communication_shared_memory_2();
    communication_message_queue();
    return 0;
}
