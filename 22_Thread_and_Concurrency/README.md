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

## Parallelism example (Multi Thread)
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

- Paylaşılan Bellek Alanları: İş parçacıkları arasında özellikle paylaşılan bellek alanları oluşturulabilir. Bu alanlar genellikle pthread kütüphanesindeki senkronizasyon araçları ile birlikte kullanılır ve iş parçacıkları arasında güvenli bir şekilde veri paylaşımı sağlar.(mutex)

- Ancak, iş parçacıkları arasında paylaşılan bellek alanlarının kullanımı dikkatle ele alınmalıdır çünkü aynı bellek alanına aynı anda birden fazla iş parçacığı erişebilir ve bu durum yarış koşullarına ve diğer senkronizasyon sorunlarına neden olabilir. Bu nedenle, paylaşılan bellek alanlarını kullanırken uygun senkronizasyon mekanizmaları (örneğin, kilitleme mekanizmaları) kullanılmalıdır.

# Methods
- Shared memory: İş parçacıkları arasında paylaşılan bir bellek alanı oluşturulabilir. Bu bellek alanı, iş parçacıkları tarafından okunabilir ve yazılabilir. İş parçacıkları bu bellek alanı üzerinden veri paylaşabilir ve iletişim kurabilir. Ancak, paylaşılan bellek kullanırken senkronizasyon mekanizmaları (örneğin, kilitleme mekanizmaları) kullanmak önemlidir. Senkronizasyon mekanizmaları, aynı anda aynı bellek alanına erişmeye çalışan iş parçacıklarının uygun bir şekilde kontrol edilmesini sağlar.

- Async Communication: İş parçacıkları arasındaki haberleşme için mesaj geçişi kullanılabilir. İş parçacıkları birbirlerine mesaj gönderebilirler ve bu mesajlar aracılığıyla veri veya komut alışverişi yapabilirler. Mesaj geçişi genellikle asenkron bir iletişim yöntemidir ve iş parçacıkları arasında iş parçacığı sınırı aşırı iletişim sağlar. Bu şekilde, iş parçacıkları birbirlerine doğrudan müdahale etmeden iletişim kurabilirler(struct).

# Informations
- mutex, çoklu iş parçacıklı programlarda senkronizasyonu sağlamak için kullanılan bir kilit mekanizmasıdır. "Mutex" terimi, "mutual exclusion"ın kısaltmasıdır. Shared memory de kullanılır.

- Mutexler, belirli bir kritik bölgeye yalnızca bir iş parçacığının erişmesine izin vererek yarış koşullarını ve senkronizasyon sorunlarını önlerler. Özellikle paylaşılan kaynaklara erişimde kullanılırlar. yani bütün threadlerin erişebilleceği bölgeye mutex kullandığımızda sadece o thread erişebilir diğerleri erişemez

- Bir mutex, genellikle iki ana işleve sahiptir:
    - lock(): Bu işlev, bir iş parçacığının kilitlenmiş bir mutex'i kilitlemesini sağlar. Eğer mutex zaten kilitlenmişse, iş parçacığı kilit serbest bırakılana kadar bekler.
    - unlock(): Bu işlev, bir iş parçacığının kilitlenmiş bir mutex'i serbest bırakmasını sağlar. Eğer bir iş parçacığı kilitlenmiş mutex'i serbest bırakmazsa, diğer iş parçacıkları bu mutex'e erişemeyebilir.

- Evet, mutex (Mutex kısaltması) bir tür senkronizasyon mekanizmasıdır ve genellikle paylaşılan bellek gibi birden fazla iş parçacığı tarafından erişilen ortamlarda kullanılır. Mutex, paylaşılan belleğe erişimi korumak için kullanılır ve aynı anda yalnızca bir iş parçacığının o bölgeye erişmesine izin verir. Bu şekilde, veri yarışı durumlarını (race conditions) önler ve veri bütünlüğünü sağlar.

- Bir mutex kullanarak, bir iş parçacığı belirli bir kritik bölgeye (veya kritik kaynağa) erişmeden önce mutex kilidini alır. Eğer bir başka iş parçacığı o bölgeye erişmeye çalışırsa, bu iş parçacığı o noktada bir müddet beklemek zorunda kalır. İlk iş parçacığı işini bitirip mutex kilidini serbest bıraktığında, diğer iş parçacığı mutex kilidini alır ve işini yapmaya devam eder.

- Bu sayede, mutex kullanarak paylaşılan belleğe erişimi senkronize ederiz ve veri yarışı durumlarından kaynaklanan hataları önleriz. Ancak, mutex kullanmak beraberinde bazı maliyetler getirir; özellikle, iş parçacıklarının birbirlerini beklemek zorunda kalması durumunda performans düşebilir. Bu yüzden, mutex kullanırken dikkatli olunmalı ve mutex kilidi olabildiğince kısa sürelerle tutulmalıdır.

- mutex tanımladığımız zaman bütün thradlerin ulaşabileceği bölgeye sadece o anda lock lanan mutex ulaşabilir diğer threadler bekler ve o alana ulaşamaz.

## Concurrency
- Genel olarak, bir sistemde birden fazla işlem veya görevin aynı anda yürütülmesi yeteneğini ifade eder. Bu işlemler aynı anda başlatılabilir, çalışabilir veya tamamlanabilir, ancak gerçek zamanlı eşzamanlılık olması gerekmez.

- Concurrency, özellikle çoklu işlemci sistemlerinde veya modern işletim sistemlerinde önemlidir. Çünkü birden fazla işlemci varsa, her bir işlemci ayrı görevleri aynı anda işleyebilir, bu da daha yüksek performans ve sistem verimliliği sağlar.

- Concurrency'i gerçekleştirmenin farklı yolları vardır, bunlar arasında paralel işleme, çoklu iş parçacığı (threading), asenkron programlama ve olay tabanlı programlama gibi teknikler bulunmaktadır. Bu teknikler, farklı senaryolara ve gereksinimlere göre kullanılabilir ve programcılara sistemlerinde aynı anda birden fazla görevi etkin bir şekilde yönetme esnekliği sağlar.
- aslında multithreading den bahsediyor

## Paralel Çalışma (Parallelism)
- Paralel çalışma, aynı anda birden fazla işlemcinin veya iş parçacığının (thread) eş zamanlı olarak çalıştırılması anlamına gelir. Bu, genellikle çoklu işlemci veya çoklu çekirdekli sistemlerde gerçekleşir ve bir görevin parçalara bölünerek aynı anda işlenmesini sağlar. Her bir işlemci veya çekirdek, farklı görevleri eş zamanlı olarak yürütür.
    - Farklı görevlerin veya iş parçacıklarının aynı anda çalışmasıdır.
    - Gerçek zamanlı eş zamanlı işlemleri mümkün kılar.
    - Kaynak kullanımını ve işlemci kapasitesini etkin bir şekilde kullanır.
    - Paralel programlama modelleri (örneğin, thread'ler veya işlem havuzları) kullanılarak uygulanabilir.
    - Örnek olarak, çoklu işlemci veya çoklu çekirdekli bilgisayarlarda performansı artırmak için kullanılır.  
    
## Asenkron Çalışma (Asynchronous Programming)
- Asenkron çalışma, bir işlemin tamamlanmasını beklemeksizin devam eden işlemleri ifade eder. Bu genellikle giriş/çıkış (I/O) işlemleri için kullanılır; örneğin, dosya okuma/yazma, ağ iletişimi veya zaman alıcı işlemler gibi. Asenkron programlama, işlemi bloke etmeden diğer işlemlerin devam etmesine izin verir.

    - işlem tamamlanana kadar diğer işlemlerin devam etmesine olanak tanır.
    - Genellikle olay odaklı programlama veya callback fonksiyonlarıyla uygulanır.
    - Giriş/çıkış (I/O) işlemleri için etkili bir yaklaşımdır, çünkü uzun sürecek işlemler arka planda gerçekleştirilir.
    - İşlem sonucu elde edildiğinde callback veya promise/future gibi mekanizmalarla sonuç alınabilir.
    - Örnek olarak, bir web tarayıcısının asenkron çalışması, aynı anda birden fazla kaynağı (resimler, CSS dosyaları, JavaScript dosyaları vb.) indirerek ve yükleyerek sayfanın daha hızlı yüklenmesini sağlar.

## Farklar
- **Eş zamanlılık**: Paralel çalışma eş zamanlı olarak farklı işlemcilerde veya iş parçacıklarında gerçekleşirken, asenkron çalışma tek bir işlemci veya iş parçacığı üzerinde gerçekleşebilir.

- **İşlem Modeli**: Paralel çalışma genellikle çoklu görevlerin eş zamanlı olarak yürütülmesini ifade ederken, asenkron çalışma işlemlerin tamamlanmasını beklemeksizin devam eden işlemleri ifade eder.

- **Kullanım Alanları**: Paralel çalışma performansı artırmak için kullanılırken, asenkron çalışma genellikle giriş/çıkış (I/O) işlemleri için etkilidir ve işlemi bloke etmeden programların daha verimli çalışmasını sağlar.

## Paralel Çalışma (Parallelism)
- Tanım: Paralel çalışma, birden fazla işlemcinin veya iş parçacığının (thread) aynı anda ve eş zamanlı olarak çalıştırılmasıdır. Bu işlemciler veya iş parçacıkları, genellikle farklı görevleri veya aynı görevin farklı parçalarını işleyerek paralel olarak çalışırlar.

- İşlev: Paralel çalışma, performansı artırmak ve işlem hızını iyileştirmek için kullanılır. Özellikle çoklu çekirdekli işlemciler veya çoklu işlemci sistemlerinde yaygın olarak kullanılır. Her bir işlemci veya iş parçacığı, farklı veri parçaları üzerinde eş zamanlı olarak çalışarak işlemlerin hızlı bir şekilde tamamlanmasını sağlar.

- Örnek: Bir resim işleme uygulaması, bir resmi parçalara böler ve farklı işlemcilerde veya iş parçacıklarında paralel olarak bu parçaları işler. Bu şekilde, resmin işlenmesi daha hızlı tamamlanabilir.

## Asenkron Çalışma (Asynchronous Programming)
- Tanım: Asenkron çalışma, bir işlemin tamamlanmasını beklemeksizin devam eden işlemleri ifade eder. Yani, bir işlemin sonucunu beklemek yerine, işlem başlatıldıktan sonra program diğer işlemlere devam eder ve işlem tamamlandığında sonucu elde eder.

- İşlev: Asenkron çalışma, özellikle giriş/çıkış (I/O) işlemleri için etkilidir. Uzun sürecek I/O işlemleri (dosya okuma/yazma, ağ iletişimi vb.) asenkron olarak gerçekleştirilir ve ana iş parçacığını bloke etmez. Bu sayede, programın daha verimli çalışması ve daha iyi yanıt vermesi sağlanır.

- Örnek: Bir web tarayıcısının asenkron çalışması, sayfanın yüklenmesi sırasında aynı anda birden fazla kaynağı (resimler, stil dosyaları, JavaScript dosyaları vb.) indirerek ve yükleyerek sayfanın daha hızlı yüklenmesini sağlar.

## Farklar
- Çalışma Zamanı: Paralel çalışma işlemleri eş zamanlı olarak yürütürken, asenkron çalışma işlemleri sırayla ve beklemeksizin yürütülür.

- Kullanım Alanı: Paralel çalışma genellikle performansı artırmak için kullanılırken, asenkron çalışma genellikle giriş/çıkış (I/O) işlemleri veya kullanıcı arayüzü etkileşimleri için kullanılır.

- Senkronizasyon ve Veri Paylaşımı: Paralel çalışmada farklı işlemciler arasında senkronizasyon ve veri paylaşımı gerekebilirken, asenkron çalışmada genellikle tek bir işlemci üzerindeki işlemler için daha basit ve sıralı bir model kullanılır.

- Özetle, paralel çalışma birden fazla işlemcinin veya iş parçacığının aynı anda çalışmasıyla performansı artırırken, asenkron çalışma işlemlerin sırayla ve beklemeksizin yürütülmesiyle programların daha etkin ve hızlı çalışmasını sağlar. İkisi de farklı senaryolarda kullanılarak programların daha verimli ve kullanıcı dostu olmasını sağlar.

## Asenkron Çalışma
- Tanım: Asenkron çalışma, bir işlemin başlatılması ve tamamlanması arasında beklenmeksizin diğer işlemlerin devam edebilmesine olanak sağlayan bir programlama modelidir. Yani, bir işlem başlatıldığında, program diğer işlemlere devam eder ve işlem tamamlandığında sonuçla ilgili işlemler gerçekleştirilir.

- Örnek: Web tarayıcınızın bir sayfayı yüklerken, tarayıcı asenkron olarak farklı kaynakları (resimler, stil dosyaları, JavaScript dosyaları vb.) indirir. Bu kaynaklar indirilirken, tarayıcı sayfanın geri kalanını görüntülemeye devam eder. Kaynaklar indirildiğinde, tarayıcı bunları kullanarak sayfayı tamamlar.

- Farklılık: Asenkron çalışma, işlemlerin sırayla ve bloke etmeden yürütülmesine izin verir. İşlemler arasında zaman açısından örtüşmeler olabilir, ancak aynı anda birden fazla işlem eş zamanlı olarak çalışmaz.

## Paralel Çalışma
- Tanım: Paralel çalışma, birden fazla işlemcinin veya iş parçacığının (thread) aynı anda ve gerçekten eş zamanlı olarak çalıştırılmasıdır. Bu işlemciler veya iş parçacıkları, genellikle farklı görevleri veya veri parçalarını işleyerek eş zamanlı olarak çalışırlar.

- Örnek: Bir bilgisayarın çoklu çekirdekli bir işlemcisi varsa, bir program farklı iş parçacıklarını farklı çekirdeklerde paralel olarak çalıştırarak performansı artırabilir. Her çekirdek aynı anda bir iş parçacığı üzerinde çalışabilir.

- Farklılık: Paralel çalışma, işlemlerin gerçekten aynı anda ve eş zamanlı olarak yürütülmesine izin verir. Farklı işlemciler veya iş parçacıkları, birbirini bloke etmeden eş zamanlı olarak çalışabilir.

## Ana Farklar
- Eş Zamanlılık: Asenkron çalışma sırasında işlemler sırayla ve bloke etmeden yürütülürken, paralel çalışma işlemlerin gerçekten aynı anda ve eş zamanlı olarak çalışmasını sağlar.

- İşlem Kapasitesi: Asenkron çalışma genellikle tek bir işlemci veya iş parçacığı üzerinde gerçekleşirken, paralel çalışma genellikle çoklu işlemciler veya çoklu çekirdekler üzerinde gerçekleşir.

- Kullanım Alanları: Asenkron çalışma genellikle giriş/çıkış (I/O) işlemleri veya kullanıcı arayüzü etkileşimleri için kullanılırken, paralel çalışma genellikle işlem yoğun ve performans gerektiren uygulamalarda kullanılır.

## Resources
- https://www.geeksforgeeks.org/operating-systems/?ref=lbp
- https://www.geeksforgeeks.org/thread-in-operating-system/
- https://www.geeksforgeeks.org/threads-and-its-types-in-operating-system/?ref=lbp
- https://www.geeksforgeeks.org/multithreading-in-c/
- https://www.geeksforgeeks.org/multithreading-in-operating-system/?ref=lbp