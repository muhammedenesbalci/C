#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define PORT 8080

int main() {
    int sock = 0;
    struct sockaddr_in serv_addr;
    //const char *hello = "Merhaba, sunucu! Ben istemci.";
    char *message = (char*)malloc(50);
    char buffer[1024] = {0};

    // İstemci soketi oluşturma
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket oluşturulamadı \n");
        return -1;
    }

    // Sunucu adresini yapılandırma
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // IP adresini "127.0.0.1" (localhost) olarak ayarlama
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0) {
        printf("\n Geçersiz adres/ Adres desteklenmiyor \n");
        return -1;
    }

    // Sunucuya bağlanma
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("\n Bağlantı başarısız \n");
        return -1;
    }

    // Sunucuya mesaj gönderme
    printf("Mesajı giriniz: ");
    scanf("%s", message);
    send(sock, message, strlen(message), 0);
    printf("Mesaj sunucuya gönderildi\n");
    free(message);

    // Sunucudan cevap alma
    read(sock, buffer, 1024);
    printf("Sunucudan gelen mesaj: %s\n", buffer);

    return 0;
}
