# Dynamic Memory Allocation
## Content
- Basics
- heap and stack
- malloc
- free
- calloc
- realloc

## Informations
Heap ve stack, bilgisayar belleğinde verilerin depolandığı iki temel alanı temsil eder. İşte heap ve stack'in temel özellikleri ve farkları:

- **Stack**
    - Stack, veri yapısında bir tür depolama alanıdır ve genellikle yerel değişkenlerin ve fonksiyon çağrılarının yönetilmesi için kullanılır.
    - Yerel değişkenler ve fonksiyon çağrıları gibi geçici veriler burada saklanır.
    - Stack, sıralı bir yapıya sahiptir ve verilerin eklenip çıkarılması, son giren ilk çıkar (Last In, First Out - LIFO) prensibine göre gerçekleşir.
    - Bellekteki bu alan, programın çalışma zamanında otomatik olarak oluşturulur ve serbest bırakılır.
- **Heap**
    - Heap, dinamik bellek tahsisi için kullanılan bir alandır. Programcılar tarafından ihtiyaç duyulduğunda elle kontrol edilir.
    - Genellikle dinamik veri yapıları ve nesneler (örneğin, dinamik olarak oluşturulan diziler) için kullanılır.
    - Bellek tahsisi ve serbest bırakma, programcının sorumluluğundadır. Yani, bir nesne oluşturulduğunda bellekten tahsis edilir ve işlevini tamamladığında programcı tarafından serbest bırakılmalıdır.
    - Bellekteki bu alan, programın çalışma zamanında dinamik olarak yönetilir.


- **Farklar**
    - Stack'te bellek otomatik olarak yönetilirken, heap'te programcının kontrolü vardır.
    - Stack, yerel değişkenler gibi geçici veriler için kullanılırken, heap genellikle dinamik veri yapıları için kullanılır.
    - Stack'te veri eklenip çıkarılma işlemleri hızlıdır çünkü sıralıdır. Heap'te ise bellek tahsisi ve serbest bırakma işlemleri daha maliyetlidir.
    - Stack bellek yönetimi genellikle derleyici tarafından otomatik olarak yapılırken, heap bellek yönetimi programcı tarafından kontrol edilir.

        ```c
        #include <stdio.h>
        #include <stdlib.h>

        int main() {
            // Stack'te bellek tahsisi
            int stackVariable = 5;

            // Heap'te bellek tahsisi
            int *heapVariable = (int *)malloc(sizeof(int));
            *heapVariable = 10;

            // Bellekten serbest bırakma
            free(heapVariable);

            return 0;
        }
        ```