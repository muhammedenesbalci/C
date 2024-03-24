# Thread, Process and Concurrency
## Thread
- A "thread" is the smallest unit of execution that can be independently scheduled by an operating system's scheduler. Threads exist within processes and share the same memory space, allowing them to easily communicate and share data with one another. Threads are managed by the operating system's thread scheduler, which decides when each thread gets CPU time.

- Threads offer several advantages:

    - Parallelism: Multiple threads can execute different tasks simultaneously, allowing for better utilization of CPU resources.

    - Responsiveness: Threads can allow a program to remain responsive even when some threads are waiting for input/output operations to complete, as other threads can continue to execute.

    - Sharing and Communication: Threads within the same process can easily share data and communicate with each other, making programming more convenient.

- However, threads also have some drawbacks:

    - Synchronization Issues: Accessing shared data concurrently can lead to synchronization issues if not properly managed. This requires the use of synchronization techniques to prevent race conditions and ensure data consistency.

    - Race Conditions: Race conditions occur when the behavior of a program depends on the relative timing of multiple threads accessing shared resources. These conditions can lead to unexpected and erroneous behavior.

    - Memory Overhead: Each thread consumes memory for its stack and other data structures, which can add up when using a large number of threads.

- Bir "thread" (iş parçacığı), bir işlem içinde bağımsız olarak yürütülebilen en küçük iş yükü birimidir. Bir işlem, genellikle bir veya daha fazla thread içerir ve her bir thread işlem belleğini paylaşır. İş parçacıkları, işlemci tarafından yürütülür ve iş parçacığı yöneticisi (thread scheduler) tarafından işlemci kaynaklarına erişim için planlanır.

- İş parçacıklarının kullanılmasının birkaç avantajı vardır:

    - Paralelizasyon: Birden fazla iş parçacığı, aynı anda farklı işler üzerinde çalışabilir, bu da işlemci kaynaklarının daha verimli kullanılmasını sağlar.

    - Duyarlılık: Birden fazla iş parçacığı, bir iş parçacığının girdi veya çıktı beklerken diğer iş parçacıklarının çalışmasını sağlayarak, programın daha duyarlı ve etkileşimli olmasını sağlar.

    - Paylaşım ve İletişim: İş parçacıkları, aynı işlem içindeki diğer iş parçacıklarıyla veri paylaşabilir ve iletişim kurabilir, bu da programlama kolaylığı sağlar.

- İş parçacıklarının dezavantajları da vardır:

    - Senkronizasyon Sorunları: Paylaşılan verilere eşzamanlı erişim, senkronizasyon sorunlarına yol açabilir. Bu sorunlar, doğru senkronizasyon tekniklerinin kullanılması gerektiğini gerektirir.

    - Yarış Koşulları (Race Conditions): Birden çok iş parçacığının aynı anda bir kaynağa erişmesi durumunda, beklenmeyen sonuçlar oluşabilir. Bu durumlar, uygun senkronizasyon olmadığında ortaya çıkabilir.

    - Bellek Tüketimi: Her iş parçacığı, işlem belleğinde bir yığın (stack) ve diğer veri yapıları için bellek tüketir. Çok sayıda iş parçacığı kullanmak, bellek tüketimini artırabilir.

# Parallelism example (Multi Thread)
-   Code 
    ```C
        #include <stdio.h> 
        #include <stdlib.h> 
        #include <unistd.h>  //Header file for sleep(). man 3 sleep for details. 
        #include <pthread.h> 
        
        // A normal C function that is executed as a thread  
        // when its name is specified in pthread_create() 
        void *myThreadFun(void *vargp) 
        { 
            sleep(1); 
            printf("Printing from Thread \n"); 
            return NULL; 
        } 
        
        int main() 
        { 
            pthread_t thread_id; 
            printf("Before Thread\n"); 
            pthread_create(&thread_id, NULL, myThreadFun, NULL); 
            pthread_join(thread_id, NULL); 
            printf("After Thread\n"); 
            exit(0); 
        }
        ```    
- void *thread_function(void *arg) thread fonksiyonu yapısı
- In main(), we declare a variable called thread_id, which is of type pthread_t, which is an integer used to identify the thread in the system. After declaring thread_id, we call pthread_create() function to create a thread. 
- The first argument is a pointer to thread_id which is set by this function. 
- The third argument is name of function to be executed for the thread to be created. 
- The fourth argument is used to pass arguments to the function, myThreadFun. 
- The pthread_join() function for threads is the equivalent of wait() for processes. A call to pthread_join blocks the calling thread until the thread with identifier equal to the first argument terminates. 
- pthread_join fonksiyonu, bir iş parçacığının tamamlanmasını beklemek için kullanılır. Bu fonksiyon, belirtilen iş parçacığının bitmesini bekler ve iş parçacığının sonucunu veya dönüş değerini alır. İş parçacığı tamamlanana kadar çağıran iş parçacığı (genellikle ana program), pthread_join fonksiyonunun çağrısını bekler.
-   ```C
    int pthread_join(pthread_t thread, void **retval);
    ```
- thread: Beklenen iş parçacığının kimliğini temsil eden bir pthread_t türünde değerdir.
- retval: İş parçacığı işlevinin dönüş değerini almak için kullanılan bir işaretçidir. İş parçacığının işlevi void * türünde bir değer döndürür ve bu değer pthread_join fonksiyonuna retval parametresi aracılığıyla aktarılır. Eğer bu değeri kullanmak istemiyorsanız, NULL geçebilirsiniz.


- Derlerken **-lpthread** flagı thread kütüphanesini dahil eder
    ```bash
    - gcc -c main.c -o main.o -lpthread
    - gcc main.o -o my_prog -lpthread
    ```

# Thread memory sharing

- İş parçacıkları (threadler), aynı süreç içinde çalıştıkları için genellikle bazı bellek alanlarını paylaşırlar. Paylaşılan bellek alanları şunları içerebilir:

- Global Değişkenler ve Statik Değişkenler: Programınızın herhangi bir yerinde tanımlanan global değişkenler ve statik değişkenler, tüm iş parçacıkları arasında paylaşılır. Bu değişkenlere herhangi bir iş parçacığından erişilebilir ve değiştirilebilir.

- Heap Belleği (Dinamik Bellek): malloc, calloc gibi fonksiyonlarla oluşturulan bellek blokları, tüm iş parçacıkları arasında paylaşılır. Bu nedenle, dinamik bellek tahsisi işlemleri ile oluşturulan bellek alanları, herhangi bir iş parçacığı tarafından erişilebilir ve değiştirilebilir.

- Dosya İşaretçileri: Açılan dosyalar ve dosyalarla ilgili işaretçiler (File pointers), iş parçacıkları arasında paylaşılır. Bir iş parçacığı tarafından açılan bir dosya, diğer iş parçacıkları tarafından okunabilir veya yazılabilir.

- Paylaşılan Bellek Alanları: İş parçacıkları arasında özellikle paylaşılan bellek alanları oluşturulabilir. Bu alanlar genellikle pthread kütüphanesindeki senkronizasyon araçları ile birlikte kullanılır ve iş parçacıkları arasında güvenli bir şekilde veri paylaşımı sağlar.

- Ancak, iş parçacıkları arasında paylaşılan bellek alanlarının kullanımı dikkatle ele alınmalıdır çünkü aynı bellek alanına aynı anda birden fazla iş parçacığı erişebilir ve bu durum yarış koşullarına ve diğer senkronizasyon sorunlarına neden olabilir. Bu nedenle, paylaşılan bellek alanlarını kullanırken uygun senkronizasyon mekanizmaları (örneğin, kilitleme mekanizmaları) kullanılmalıdır.

# Methods
- Shared memory: İş parçacıkları arasında paylaşılan bir bellek alanı oluşturulabilir. Bu bellek alanı, iş parçacıkları tarafından okunabilir ve yazılabilir. İş parçacıkları bu bellek alanı üzerinden veri paylaşabilir ve iletişim kurabilir. Ancak, paylaşılan bellek kullanırken senkronizasyon mekanizmaları (örneğin, kilitleme mekanizmaları) kullanmak önemlidir. Senkronizasyon mekanizmaları, aynı anda aynı bellek alanına erişmeye çalışan iş parçacıklarının uygun bir şekilde kontrol edilmesini sağlar.
- Async Communication: İş parçacıkları arasındaki haberleşme için mesaj geçişi kullanılabilir. İş parçacıkları birbirlerine mesaj gönderebilirler ve bu mesajlar aracılığıyla veri veya komut alışverişi yapabilirler. Mesaj geçişi genellikle asenkron bir iletişim yöntemidir ve iş parçacıkları arasında iş parçacığı sınırı aşırı iletişim sağlar. Bu şekilde, iş parçacıkları birbirlerine doğrudan müdahale etmeden iletişim kurabilirler.

# Informations
- mutex, çoklu iş parçacıklı programlarda senkronizasyonu sağlamak için kullanılan bir kilit mekanizmasıdır. "Mutex" terimi, "mutual exclusion"ın kısaltmasıdır. Shared memory de kullanılır.
- Mutexler, belirli bir kritik bölgeye yalnızca bir iş parçacığının erişmesine izin vererek yarış koşullarını ve senkronizasyon sorunlarını önlerler. Özellikle paylaşılan kaynaklara erişimde kullanılırlar.
- Bir mutex, genellikle iki ana işleve sahiptir:
    - lock(): Bu işlev, bir iş parçacığının kilitlenmiş bir mutex'i kilitlemesini sağlar. Eğer mutex zaten kilitlenmişse, iş parçacığı kilit serbest bırakılana kadar bekler.
    - unlock(): Bu işlev, bir iş parçacığının kilitlenmiş bir mutex'i serbest bırakmasını sağlar. Eğer bir iş parçacığı kilitlenmiş mutex'i serbest bırakmazsa, diğer iş parçacıkları bu mutex'e erişemeyebilir.

