# Process, Fork, Wait, Signals
## Process
- İşletim sistemi, bilgisayar donanımı üzerinde çalışan yazılımı yöneten bir programdır. Bu yazılımlar, uygulama programları, sürücüler ve diğer sistem yazılımları gibi çeşitli türlerde olabilir. İşletim sistemi, bu yazılımları yönetirken aynı anda birden çok görevin (veya işlem) yürütülmesini sağlar. İşte bu görevler, işletim sistemi tarafından "process" (süreç) olarak adlandırılır.

- Bir işletim sistemi içindeki her process, kendi bellek alanına, kaynaklarına ve çalışma bağlamına sahip bir programın veya işlemin yürütülmesini temsil eder. Bu, bir process'in diğer process'lerden bağımsız olarak yürütülmesini sağlar. Her process, bir programın bir kopyası olarak düşünülebilir ancak aynı programdan oluşturulan process'ler farklı bellek alanlarında çalışır.

- İşletim sistemi, process'leri yönetirken aşağıdaki işlevleri sağlar:

    - Zaman Paylaşımı: İşlemci zamanını process'ler arasında adil bir şekilde paylaştırır, böylece birden çok process aynı anda çalışıyormuş gibi görünür.

    - Hafıza Yönetimi: Her process, kendi adres alanına sahiptir ve işletim sistemi, process'ler arasında bellek kullanımını yönetir. Bu, her process'in kendi verilerini saklamasını ve diğer process'lerin belleğine erişimini sınırlar.

    - Eşzamanlılık Yönetimi: İşletim sistemi, process'ler arasında iletişimi ve senkronizasyonu sağlar. Bu, process'ler arasında veri paylaşımını, haberleşmeyi ve senkronizasyonu kolaylaştırır.

    - Güvenlik ve İzolasyon: Her process, kendi kullanıcı izinlerine ve erişim haklarına sahiptir. İşletim sistemi, process'lerin birbirlerine veya sistemin diğer bölümlerine zarar vermesini önlemek için güvenlik önlemleri alır.

    - İşletim sistemi, process'leri oluşturur, sonlandırır, duraklatır, devam ettirir ve yönetir. Ayrıca, birden çok process'in aynı anda çalışmasını sağlayarak çoklu görev işlevselliğini sağlar. Bu sayede, kullanıcılar aynı anda birden fazla programı veya görevi yürütebilir ve işletim sistemi bunları etkin bir şekilde yönetir.
## Differences with Thread
- Bellek ve Kaynak Kullanımı:
    - Processler: Her process, kendi ayrı bellek alanına sahiptir. Bu, her process'in kendi kodu, verileri, yığını ve diğer kaynakları için ayrı bir alanı olduğu anlamına gelir. Process'ler arasında veri paylaşımı ve iletişim, işletim sistemi tarafından sağlanan özel mekanizmalar kullanılarak yapılır.
    - Threadler: Threadler, bir process içinde paylaşılan bellek alanını kullanır. Bir process'in her bir thread'i, aynı kod ve veri alanını paylaşır. Bu nedenle, thread'ler arasında veri paylaşımı doğrudan mümkündür ve daha hızlı iletişim sağlanır.

- İşlem ve Thread Oluşturma Maliyeti:

    - Processler: Yeni bir process oluşturmak oldukça maliyetlidir. Yeni bir process oluşturmak için işletim sistemi, yeni bir adres alanı oluşturmalı, program kodunu yüklemeli ve gerekli kaynakları ayırmalıdır.
    - Threadler: Yeni bir thread oluşturmak daha az maliyetlidir. Çünkü yeni bir thread, ana process'in mevcut adres alanını paylaşır ve genellikle birkaç küçük veri yapısı oluşturulmasıyla sınırlıdır.

- Paralelizasyon Yeteneği:

    - Processler: Process'ler, birbirlerinden bağımsız olarak çalışabilirler. Bu nedenle, işletim sistemi, farklı işlemcilerde (çoklu işlemci sistemleri) veya farklı çekirdeklerde (çoklu çekirdekli işlemciler) aynı anda çalışan process'leri dağıtabilir. Ancak process'ler arasındaki iletişim ve senkronizasyon maliyetli olabilir.
    - Threadler: Thread'ler, aynı process'in içinde çalıştıkları için, process'in kaynaklarına ve verilerine doğrudan erişebilirler. Bu nedenle, thread'ler arasındaki iletişim ve senkronizasyon daha hızlı ve verimlidir. Ancak, birçok işletim sistemi, aynı process içindeki thread'leri aynı anda birden çok işlemci veya çekirdekte çalıştırma yeteneğine sahip olmayabilir.

- Hata Yönetimi ve İzolasyon:

    - Processler: Her process, kendi hata alanına (error domain) sahiptir. Bir process bir hata oluştuğunda diğer process'leri etkilemez.
    - Threadler: Bir thread'in bir hata yapması durumunda, bu hata diğer thread'leri de etkileyebilir. Çünkü thread'ler aynı adres alanını paylaşırlar, bu nedenle bir thread'in yaptığı bir hata, diğer thread'leri de etkileyebilir.

- Özetle, process'ler genellikle daha yalıtılmış, güvenilir ve bağımsızdır, ancak daha yüksek maliyetli ve iletişim maliyeti daha fazladır. Thread'ler ise daha hızlı ve verimli bir iletişim sağlar, ancak daha dikkatli yönetilmesi gereken ve izolasyon sorunlarına daha açık olabilirler.


## Fork
- fork() fonksiyonu, işletim sistemi seviyesinde bir sistem çağrısıdır. Bu çağrı, mevcut sürecin bir kopyasını oluşturarak iki ayrı süreç oluşturur: ebeveyn süreç ve çocuk süreç. Bu iki süreç aynı anda çalışmaya devam ederler, ancak farklı işler yapabilirler.

- İşte fork() fonksiyonunun temel özellikleri:

    - Bellek Alanı:

        - Ebeveyn süreç ve çocuk süreç, fork() çağrısından sonra aynı bellek alanını paylaşırlar. Ancak, işletim sistemi, kopyalama işlemi sırasında bu bellek alanını korur ve her süreç kendi değişkenlerine, yığınlarına ve kodlarına sahip olur. Dolayısıyla, ebeveyn ve çocuk süreçler birbirinden bağımsız çalışabilirler.
    - Dönüş Değeri:

        - fork() fonksiyonu, ebeveyn süreçte 0'dan farklı bir değer (genellikle çocuk sürecin PID'si) döndürürken, çocuk süreçte 0 döndürür. Bu, ebeveyn süreç ve çocuk süreç arasında ayrım yapılmasını sağlar.
    - Çocuk Süreçin Özellikleri:

        - Çocuk süreç, ebeveyn sürecin bir kopyasıdır. Dolayısıyla, çocuk süreçin çevresi (environment) ve özellikleri, ebeveyn sürecinkilere benzerdir. Ancak, bazı sistem kaynakları (örneğin dosya tanımlayıcıları) kopyalanır ve bu kaynaklar iki süreç arasında paylaşılmaz.
    - Hızlı ve Maliyetli:

        - fork() çağrısı, oldukça hızlı ve hafif bir işlemdir, ancak işletim sistemi tarafından bazı maliyetlerle gerçekleştirilir. Özellikle, bellek alanının kopyalanması ve işletim sistemi kaynaklarının paylaşımı gibi işlemler bazı zaman ve kaynaklar gerektirir.
    - Birden Fazla Çocuk Süreç:

        - Bir ebeveyn süreç, birden fazla fork() çağrısı yaparak birden fazla çocuk süreç oluşturabilir. Her fork() çağrısı sonrasında ebeveyn süreç, bir çocuk sürecin PID'sini alır ve işlemine devam eder.
- fork() fonksiyonu, Unix benzeri işletim sistemlerinde çok önemli bir araçtır ve çoklu görev (multitasking) ve paralel programlama gibi birçok senaryoda kullanılır.
- Bir fork() çağrısı yapıldığında, ebeveyn ve çocuk süreçler aynı bellek alanını paylaşırlar, ancak bu paylaşım tam olarak "aynı alanı kullanma" anlamına gelmez. Bunun yerine, her süreç, kendi kopyası olan aynı bellek alanını farklı amaçlar için kullanır. Yani, ebeveyn ve çocuk süreçler aynı bellek alanına sahiptir, ancak bu alanın içeriği süreçler arasında bağımsızdır.

- Örneğin, ebeveyn süreç ve çocuk süreç aynı değişkenlere sahip olabilir, ancak her süreç bu değişkenlerin kendi kopyasını saklar. Bir süreç bir değişiklik yaparsa, bu değişiklik sadece o süreçin bellek alanını etkiler, diğer süreçin bellek alanı bundan etkilenmez.
- Ebeveyn süreç ve çocuk süreç arasında bellek alanı paylaşılır; ancak, her süreç kendi bağımsız adres alanına sahip olduğu için, değişkenlerin etki alanı genellikle sadece tanımlı oldukları süreçle sınırlıdır. Yani, ebeveyn süreçte tanımlanan değişkenler doğrudan çocuk süreçte erişilebilir değildir ve aynı şekilde, çocuk süreçte tanımlanan değişkenler de ebeveyn süreçte erişilebilir değildir.

- Ancak, bazı durumlarda, ebeveyn ve çocuk süreçler arasında belirli bir derecede veri paylaşımı sağlanabilir. Örneğin, paylaşımlı bellek bölgeleri veya haberleşme araçları (örneğin, Unix sinyalleri, işaretçiler veya dosyalar) kullanılarak veri paylaşımı sağlanabilir. Ancak, bu tür paylaşım mekanizmaları dikkatlice yönetilmelidir ve çeşitli senaryolarda doğru şekilde senkronize edilmelidir.

- Genel olarak, ebeveyn ve çocuk süreçler arasında değişkenlerin doğrudan paylaşılması yerine, veri paylaşımı ve iletişim için daha güvenli ve yapılandırılmış yöntemler kullanılması tavsiye edilir. Bu, programın daha tutarlı ve daha güvenilir bir şekilde çalışmasını sağlar.

# Extra
- The Fork system call is used for creating a new process in Linux, and Unix systems, which is called the child process, which runs concurrently with the process that makes the fork() call (parent process). After a new child process is created, both processes will execute the next instruction following the fork() system call.

- The child process uses the same pc(program counter), same CPU registers, and same open files which use in the parent process. It takes no parameters and returns an integer value.

- Below are different values returned by fork().
    - Negative Value: The creation of a child process was unsuccessful.
    - Zero: Returned to the newly created child process.
    - Positive value: Returned to parent or caller. The value contains the process ID of the newly created child process.

## First Example Explanation
- fork oluşturulduğu satırdan itibaren çalıştırılmaya başlar.
- yazılan kodun fork oluşturulduktan sonra herk iki process de çalıştırıyor. ayrı ayrı. 
- İlk olarak, main() fonksiyonu çalıştırılır ve ebeveyn süreç başlatılır.
- Ebeveyn süreç, fork() çağrısını yapar ve yeni bir süreç (çocuk süreç) oluşturulur.
- fork() çağrısı, ebeveyn süreçte çocuk sürecin PID'sini ve çocuk süreçte 0 değerini döndürür.
- Ebeveyn süreç, çocuk süreçin PID'sini ve kendi PID'sini yazdıran printf() işlevini çalıştırır.
- Çocuk süreç ise sadece kendi PID'sini yazdıran printf() işlevini çalıştırır.
- Sonuç olarak, ebeveyn ve çocuk süreçler, fork() çağrısı sonucunda oluşturulduğu için, her ikisi de aynı kodu çalıştırır, ancak fork() çağrısı sonucunda farklı davranışlar sergilerler. Ebeveyn süreç çocuk süreç oluştururken, çocuk süreç sadece kendisini yazdırır.
## Third Example Explanation
- The number of times ‘hello’ is printed is equal to the number of processes created. Total Number of Processes = 2n, where n is the number of fork system calls. So here n = 3, 23 = 8 Let us put some label names for the three lines:
```C
fork ();   // Line 1
fork ();   // Line 2
fork ();   // Line 3
       L1       // There will be 1 child process 
    /     \     // created by line 1.
  L2      L2    // There will be 2 child processes
 /  \    /  \   //  created by line 2
L3  L3  L3  L3  // There will be 4 child processes 
                // created by line 3
 ```

- So there is a total of eight processes (new child processes and one original process). If we want to represent the relationship between the processes as a tree hierarchy it would be the following: The main process: P0 Processes created by the 1st fork: P1 Processes created by the 2nd fork: P2, P3 Processes created by the 3rd fork: P4, P5, P6, P7.
```C
             P0
         /   |   \
       P1    P4   P2
      /  \          \
    P3    P6         P5
   /
 P7
  ```

## Fourth Example Explanation
- global variable change in one process does not affect two other processes because the data/state of the two processes is different. And also parent and child run simultaneously so two outputs are possible.

# exec() command
- exec ailesi, Unix ve Unix benzeri işletim sistemlerinde kullanılan bir dizi sistem çağrısını ifade eder. Bu çağrılar, bir işlemi yürütmek için yeni bir programı yüklemek ve çalıştırmak için kullanılır.

- Bu ailenin bazı üyeleri şunlardır:

    - execve: Yeni bir program yüklemek ve çalıştırmak için kullanılır. Yeni bir program dosyası adı ve argüman listesi alır.
    - execl, execle: Argüman listesiyle birlikte yeni bir program yüklemek için kullanılır. Her bir argüman, fonksiyona ayrı bir parametre olarak geçirilir.
    - execv, execvp: Argüman listesiyle birlikte yeni bir program yüklemek için kullanılır. Argümanlar, bir dizi olarak fonksiyona geçirilir.
    - execle: Yeni bir program yüklemek için kullanılır ve ortam değişkenlerini de belirleyebilir.
- Bu çağrılar, mevcut işlemi değiştirerek yeni bir programın yüklenmesine ve çalıştırılmasına olanak tanır. Örneğin, bir shell programında kullanıcı bir komut girdiğinde, shell bu exec çağrılarından birini kullanarak belirtilen programı çalıştırır.

- exec çağrıları genellikle fork() çağrısı ile birlikte kullanılır. fork() ile yeni bir süreç oluşturulur ve ardından bu yeni süreç exec çağrısı ile farklı bir programı çalıştırır. Bu şekilde, bir süreç içinde çalışan programın yerini değiştirmek mümkün olur.

- yeni program çağırıldıktan sonra çalışan program durdurulur ve yeni program başlatılır.
- exec_example_program adında klasik sıradan bi program olyuşturdum.
- iki program da çalışmaya devam ediyor dikkat et sadece child process yeni program çalıştıktan sonra diğerine geçiyor.

- https://www.geeksforgeeks.org/fork-system-call/
- https://www.geeksforgeeks.org/signals-c-language/
- https://www.geeksforgeeks.org/wait-system-call-c/