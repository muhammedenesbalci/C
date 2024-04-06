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

- Heap ve stack, bilgisayar biliminde bellek yönetimi konseptleri olarak önemli rol oynayan terimlerdir. Bu terimler, bilgisayarın belleğinde veri depolama ve erişme yöntemlerini ifade ederler. İşte heap ve stack'in tanımları ve farkları:

- Stack (Yığın)
    - Stack, bellekteki bir bölgeyi ifade eder ve genellikle LIFO (Last In, First Out - Son giren, ilk çıkan) prensibiyle çalışır. Program yürütülürken, her çağrılan fonksiyon için stack üzerinde bir "çalışma çerçevesi" (activation record veya frame) oluşturulur. Bu çerçeve, fonksiyonun çalışması için gerekli olan yerel değişkenler, fonksiyon argümanları, dönüş adresi ve diğer bilgileri içerir. Bir fonksiyon çağrıldığında, stack üzerine yeni bir çerçeve eklenir (push); fonksiyon tamamlandığında ise çerçeve kaldırılır (pop).

- Özellikleri:

    - Stack boyutu genellikle sınırlıdır ve sabittir. Bu nedenle, stack taşması (stack overflow) durumları olabilir.
    - Yerel değişkenler ve fonksiyon çağrıları stack üzerinde yönetilir.
    - Hızlı erişim sağlar, çünkü bellek üzerinde sıralı olarak yer alır.
    - Derleme zamanında belirlenen sabit bir boyuta sahiptir.
- Heap
    - Heap, dinamik bellek yönetimi için kullanılan bir bellek bölgesidir. Heap, program çalışma zamanında kullanıcı talebine göre büyütülebilir veya küçültülebilir. Programın çalışması sırasında ihtiyaç duyulan dinamik bellek (örneğin, dinamik olarak oluşturulan nesneler, diziler veya veri yapıları) heap üzerinde tahsis edilir ve serbest bırakılır. Bellek tahsisi için genellikle malloc, calloc gibi fonksiyonlar kullanılır ve bellek serbest bırakma için free fonksiyonu kullanılır.

- Özellikleri:

    - Heap boyutu, program çalışma zamanında değişebilir ve genellikle daha büyük ve esnek bir bellek alanı sağlar.
    - Dinamik bellek tahsisini ve serbest bırakmayı sağlar.
    - Veriler heap üzerinde rastgele yerleştirilir ve bellek erişimi stack'e göre daha yavaş olabilir.
    - Bellek yönetimi, programcının sorumluluğundadır ve yanlış kullanım bellek sızıntılarına veya bellek hatalarına yol açabilir.
- Özet
- Stack: Program yürütülürken yerel değişkenler ve fonksiyon çağrıları için kullanılır. Sabit boyutlu ve sıralı bir bellek alanıdır.
- Heap: Dinamik bellek tahsisi için kullanılır. Boyutu program çalışma zamanında değişebilir ve genellikle daha esnek bir bellek alanı sağlar.