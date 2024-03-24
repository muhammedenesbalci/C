// main.c
#include <stdio.h>
#include <dlfcn.h>

int main() {
    // Dinamik kütüphane yükleniyor
    void *lib_handle = dlopen("./dynamic_linking.so", RTLD_LAZY);
    
    if (!lib_handle) {
        fprintf(stderr, "Kütüphane yüklenirken hata oluştu: %s\n", dlerror());
        return 1;
    }
    
    // Kütüphaneden hello fonksiyonunu yükle
    void (*hello)() = dlsym(lib_handle, "hello");
    
    if (!hello) {
        fprintf(stderr, "Fonksiyon yüklenirken hata oluştu: %s\n", dlerror());
        dlclose(lib_handle);
        return 1;
    }
    
    // hello fonksiyonunu çağır
    hello();
    
    // Kütüphaneyi kapat
    dlclose(lib_handle);
    
    return 0;
}