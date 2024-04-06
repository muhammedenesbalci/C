#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define PORT 8080

int main() {
    int server_fd, new_socket;  // Sunucu soketi ve yeni bağlantı soketi için dosya tanımlayıcıları
    struct sockaddr_in address;  // Sunucu adres bilgilerini tutacak yapı
    int addrlen = sizeof(address);  // Adres yapısının boyutu
    char buffer[1024] = {0};  // İstemciden alınacak verileri tutacak tampon
    char *message = (char*)malloc(50);  // İstemciye gönderilecek karşılama mesajı için bellekten alan ayırma

    // Sunucu soketi oluşturma
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket oluşturulamadı");
        exit(EXIT_FAILURE);
    }

    // Sunucu adresini yapılandırma
    address.sin_family = AF_INET;  // IPv4 adres ailesini belirtme
    address.sin_addr.s_addr = INADDR_ANY;  // Tüm ağ arabirimlerini dinleme
    address.sin_port = htons(PORT);  // Port numarasını ayarlama

    // Sunucu soketini belirtilen port ile bağlama
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bağlama başarısız");
        exit(EXIT_FAILURE);
    }

    // Bağlantıları dinlemeye başlama
    if (listen(server_fd, 3) < 0) {
        perror("Dinleme başarısız");
        exit(EXIT_FAILURE);
    }

    // Bağlantıyı kabul etme
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0) {
        perror("Bağlantı kabul edilemedi");
        exit(EXIT_FAILURE);
    }

    // İstemciden veri alma
    read(new_socket, buffer, 1024);
    printf("İstemciden gelen mesaj: %s\n", buffer);

    // İstemciye karşılama mesajı gönderme
    printf("Mesajı giriniz: ");
    scanf("%s", message);
    send(new_socket, message, strlen(message), 0);
    printf("Karşılama mesajı istemciye gönderildi\n");

    free(message);  // Bellekten ayrılan alanı serbest bırakma

    return 0;
}
