# Process and its terms
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
- fork() fonksiyonu, işletim sistemi seviyesinde bir sistem çağrısıdır. Bu çağrı, mevcut sürecin bir kopyasını oluşturarak iki ayrı süreç oluşturur: ebeveyn süreç(parent) ve çocuk süreç(child). Bu iki süreç aynı anda çalışmaya devam ederler, ancak farklı işler yapabilirler.

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

## Extra Information
- The Fork system call is used for creating a new process in Linux, and Unix systems, which is called the child process, which runs concurrently with the process that makes the fork() call (parent process). After a new child process is created, both processes will execute the next instruction following the fork() system call.

- The child process uses the same pc(program counter), same CPU registers, and same open files which use in the parent process. It takes no parameters and returns an integer value.

- Below are different values returned by fork().
    - Negative Value: The creation of a child process was unsuccessful.
    - Zero: Returned to the newly created child process.
    - Positive value: Returned to parent or caller. The value contains the process ID of the newly created child process.

## First Example Explanation
- fork,oluşturulduğu satırdan itibaren çalıştırılmaya başlar.

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

## exec() command
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

## Wait
- A call to wait() blocks the calling process until one of its child processes exits or a signal is received. After child process terminates, parent continues its execution after wait system call instruction. 
Child process may terminate due to any of these: SS
    - It calls exit();
    - It returns (an int) from main.
    - It receives a signal (from the OS or another process) whose default action is to terminate.

- If any process has more than one child processes, then after calling wait(), parent process has to be in wait state if no child terminates. 

- If only one child process is terminated, then return a wait() returns process ID of the terminated child process. 

- If more than one child processes are terminated than wait() reap any arbitrarily child and return a process ID of that child process. 

- When wait() returns they also define exit status (which tells our, a process why terminated) via pointer, If status are not NULL.

- If any process has no child process then wait() returns immediately “-1”.

- Bu mekanizma, özellikle ebeveyn (parent) ve çocuk (child) süreçler arasındaki senkronizasyon için önemlidir. Örneğin, bir ebeveyn süreci, bir çocuk sürecin sonlanmasını bekleyebilir ve böylece çocuk sürecin kaynaklarının düzgün bir şekilde temizlenmesini ve çıkış durumunun alınmasını sağlayabilir. Bu, özellikle çocuk süreçlerin paralel olarak çalıştırıldığı durumlarda ve kaynakların yönetimi, süreçler arası iletişim veya veri bütünlüğünün korunması gibi durumlar için önemlidir.

- C dilinde bu tür bir beklemeyi gerçekleştirmek için kullanılan sistem çağrılarından biri wait() fonksiyonudur. wait() fonksiyonu, ebeveyn sürecin, bir veya daha fazla çocuk sürecin sonlanmasını beklemesini sağlar. Bu fonksiyon, çocuk sürecin çıkış kodunu da alabilir, böylece ebeveyn sürec çocuğun başarıyla mı yoksa bir hata mı nedeniyle sonlandığını belirleyebilir.

- parelel çalışmayı değilde sırayla çalışmayı sağlıyor.

## Child status information
- Status information about the child reported by wait is more than just the exit status of the child, it also includes.
    - normal/abnormal termination
    - termination cause
    - exit status

- For find information about status, we use WIF….macros
    - WIFEXITED(status): child exited normally 
        - WEXITSTATUS(status): return code when child exits
    - WIFSIGNALED(status): child exited because a signal was not caught 
        - WTERMSIG(status): gives the number of the terminating signal
    - WIFSTOPPED(status): child is stopped 
        - WSTOPSIG(status): gives the number of the stop signal

    ```C
    /*if we want to prints information about a signal */
    void psignal(unsigned sig, const char *s);
    ```
## More than one child process
- We know if more than one child processes are terminated, then wait() reaps any arbitrarily child process but if we want to reap any specific child process, we use waitpid() function.
- belli bir process i beklemek istiyorsan bunu kulanırız.
- ```C
    pid_t waitpid (child_pid, &status, options);
    ```
- Options Parameter 
    - If 0 means no option parent has to wait for terminates child.
    - If WNOHANG means parent does not wait if child does not terminate just check and return waitpid().(not block parent process).
    - If child_pid is -1 then means any arbitrarily child, here waitpid() work same as wait() work.
- Return value of waitpid()
    - pid of child, if child has exited.
    - 0, if using WNOHANG and child hasn’t exited.

## Signals
- A signal is a software generated interrupt that is sent to a process by the OS because of when user press ctrl-c or another process tell something to this process.
There are fix set of signals that can be sent to a process. signal are identified by integers.
Signal number have symbolic names. For example SIGCHLD is number of the signal sent to the parent process when child terminates.
-   ```C
    #define SIGHUP  1   /* Hangup the process */ 
    #define SIGINT  2   /* Interrupt the process */ 
    #define SIGQUIT 3   /* Quit the process */ 
    #define SIGILL  4   /* Illegal instruction. */ 
    #define SIGTRAP 5   /* Trace trap. */ 
    #define SIGABRT 6   /* Abort. */
    ```
## OS Structures for Signals
- For each process, the operating system maintains 2 integers with the bits corresponding to a signal numbers.
- The two integers keep track of: pending signals and blocked signals
- With 32 bit integers, up to 32 different signals can be represented.

## Default Signal Handlers
- There are several default signal handler routines. Each signal is associated with one of these default handler routine. The different default handler routines typically have one of the following actions:
- Ign: Ignore the signal; i.e., do nothing, just return
- Term: terminate the process
- Cont: unblock a stopped process
- Stop: block the process

## User Defined Signal Handlers
- A process can replace the default signal handler for almost all signals (but not SIGKILL) by its user’s own handler function.
A signal handler function can have any name, but must have return type void and have one int parameter.
- Example: you might choose the name sigchld_handler for a signal handler for the SIGCHLD signal (termination of a child process). Then the declaration would be:
    -   ```C
        void sigchld_handler(int sig);
        ```
    - When a signal handler executes, the parameter passed to it is the number of the signal. A programmer can use the same signal handler function to handle several signals. In this case the handler would need to check the parameter to see which signal was sent. On the other hand, if a signal handler function only handles one signal, it isn’t necessary to bother examining the parameter since it will always be that signal number.

    - ```C    
        // CPP program to illustrate 
        // User-defined Signal Handler 
        #include<stdio.h> 
        #include<signal.h> 
        
        // Handler for SIGINT, caused by 
        // Ctrl-C at keyboard 
        void handle_sigint(int sig) 
        { 
            printf("Caught signal %d\n", sig); 
        } 
        
        int main() 
        { 
            signal(SIGINT, handle_sigint); 
            while (1) ; 
            return 0; 
        } 
      ```

## Sending signals via kill()
-   int kill(pid_t pid, int signal);
    pid: id of destination process
    signal: the type of signal to send
    Return value: 0 if signal was sent successfully
```C
    pid_t iPid = getpid(); /* Process gets its id.*/
    kill(iPid, SIGINT);  /* Process sends itself a  SIGINT signal   
    (commits suicide?)(because of SIGINT 
    signal default handler is terminate the process) */
```

## Communication between process
- İşletim sistemlerinde süreçler (processler) arasında veri aktarımı ve haberleşme, süreçlerin birbirlerinin adres alanlarına doğrudan erişememeleri gerçeğinden dolayı özel mekanizmalar aracılığıyla gerçekleşir. Bu mekanizmalar genellikle İşletim Sistemi (İS) tarafından sağlanır. Süreçler arası haberleşme (Interprocess Communication - IPC) mekanizmaları arasında aşağıdakiler bulunur:
    - Dosya Paylaşımı (File Sharing): En basit IPC yöntemlerinden biridir. İki veya daha fazla süreç, veri alışverişi yapmak için dosya sistemi üzerindeki dosyaları kullanır. Bu yöntemin dezavantajı, süreçlerin dosya üzerindeki değişiklikleri manuel olarak senkronize etmeleri gerektiğidir.

    - Sinyaller (Signals): Bir süreçten diğerine veya işletim sisteminden bir sürece bir olayın gerçekleştiğini bildiren asenkron bir haberleşme şeklidir. Sinyaller, sınırlı bir bilgi taşır ve genellikle yalnızca bir durumun veya olayın gerçekleştiğini bildirmek için kullanılır.

    - Boru Hatları (Pipes): Standart giriş ve çıkışı kullanarak iki süreç arasında bir veri akışı sağlar. Anonim boru hatları (anonymous pipes) yalnızca ilişkilendirilmiş süreçler arasında kullanılabilirken, adlandırılmış boru hatları (named pipes) veya FIFO'lar farklı süreçler arasında iletişim kurmak için kullanılabilir.

    - Mesaj Kuyrukları (Message Queues): Süreçler arası mesajları bir kuyrukta saklar. Her mesaj, bir tür ve belirli bir boyuta sahiptir. Mesaj kuyrukları, karmaşık veri yapılarını aktarmak için uygun bir yol sağlar.

    - Paylaşımlı Bellek (Shared Memory): İki veya daha fazla süreçin aynı bellek segmentini paylaşmasına olanak tanır. Bu yöntem, süreçler arasında büyük miktarda verinin hızlı bir şekilde aktarılması gerektiğinde etkilidir. Ancak, süreçlerin bu ortak kaynağa erişimlerini senkronize etmeleri gerekir, bu genellikle semaforlar veya kilitler kullanılarak yapılır.

    - Semaforlar (Semaphores): Semaforlar doğrudan veri aktarımı için kullanılmasa da, paylaşılan kaynaklara erişimde süreçler arasındaki senkronizasyonu sağlar. Semaforlar, bir kaynağın aynı anda yalnızca belirli sayıda süreç tarafından kullanılmasını garantiler.

    - Soketler (Sockets): Ağ üzerinden çalışan süreçler arasında çift yönlü iletişim kurulmasını sağlar. Soketler, farklı bilgisayarlardaki süreçlerin birbiriyle haberleşmesine olanak tanır ve genellikle ağ tabanlı uygulamalarda kullanılır.

## Inter Process Communication (IPC)
## Türkçe
- communication_example.c dosyasını incele

- İşletim sistemlerinde süreçler (processler) arasında veri aktarımı ve haberleşme, süreçlerin birbirlerinin adres alanlarına doğrudan erişememeleri gerçeğinden dolayı özel mekanizmalar aracılığıyla gerçekleşir. Bu mekanizmalar genellikle İşletim Sistemi (İS) tarafından sağlanır. Süreçler arası haberleşme (Interprocess Communication - IPC) mekanizmaları arasında aşağıdakiler bulunur:

    - Dosya Paylaşımı (File Sharing): En basit IPC yöntemlerinden biridir. İki veya daha fazla süreç, veri alışverişi yapmak için dosya sistemi üzerindeki dosyaları kullanır. Bu yöntemin dezavantajı, süreçlerin dosya üzerindeki değişiklikleri manuel olarak senkronize etmeleri gerektiğidir.

    - Sinyaller (Signals): Bir süreçten diğerine veya işletim sisteminden bir sürece bir olayın gerçekleştiğini bildiren asenkron bir haberleşme şeklidir. Sinyaller, sınırlı bir bilgi taşır ve genellikle yalnızca bir durumun veya olayın gerçekleştiğini bildirmek için kullanılır.

    - Boru Hatları (Pipes): Standart giriş ve çıkışı kullanarak iki süreç arasında bir veri akışı sağlar. Anonim boru hatları (anonymous pipes) yalnızca ilişkilendirilmiş süreçler arasında kullanılabilirken, adlandırılmış boru hatları (named pipes) veya FIFO'lar farklı süreçler arasında iletişim kurmak için kullanılabilir.

    - Mesaj Kuyrukları (Message Queues): Süreçler arası mesajları bir kuyrukta saklar. Her mesaj, bir tür ve belirli bir boyuta sahiptir. Mesaj kuyrukları, karmaşık veri yapılarını aktarmak için uygun bir yol sağlar.

    - Paylaşımlı Bellek (Shared Memory): İki veya daha fazla süreçin aynı bellek segmentini paylaşmasına olanak tanır. Bu yöntem, süreçler arasında büyük miktarda verinin hızlı bir şekilde aktarılması gerektiğinde etkilidir. Ancak, süreçlerin bu ortak kaynağa erişimlerini senkronize etmeleri gerekir, bu genellikle semaforlar veya kilitler kullanılarak yapılır.

    - Semaforlar (Semaphores): Semaforlar doğrudan veri aktarımı için kullanılmasa da, paylaşılan kaynaklara erişimde süreçler arasındaki senkronizasyonu sağlar. Semaforlar, bir kaynağın aynı anda yalnızca belirli sayıda süreç tarafından kullanılmasını garantiler.

    - Soketler (Sockets): Ağ üzerinden çalışan süreçler arasında çift yönlü iletişim kurulmasını sağlar. Soketler, farklı bilgisayarlardaki süreçlerin birbiriyle haberleşmesine olanak tanır ve genellikle ağ tabanlı uygulamalarda kullanılır.

    - Bu mekanizmaların her biri, farklı senaryolar için avantajlar ve dezavantajlar sunar. Seçim, uygulamanın gereksinimlerine, performans beklentilerine ve güvenlik ihtiyaçlarına bağlıdır.

## Communication_shared_memory_1 example Explanation
- #include direktifleri: Gerekli kütüphaneleri dahil eder.
```C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <unistd.h>
```
- #define ile bir sembolik isim tanımlanır. Bu sembolik isim, paylaşılan bellek boyutunu belirtir.
```C
#define SHM_SIZE 1024
```
- ftok() fonksiyonuyla paylaşılan bellek için bir anahtar oluşturulur.
```C
key_t key = ftok("/tmp", 'A');
```
- shmget() fonksiyonuyla paylaşılan bellek segmenti oluşturulur. Bu fonksiyon, paylaşılan belleğin boyutunu ve erişim izinlerini belirler.
```C
int shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666);
```
- shmat() fonksiyonuyla paylaşılan bellek segmenti sürecin adres alanına bağlanır.
```C
char *shmaddr = shmat(shmid, NULL, 0);
```
- fork() fonksiyonuyla yeni bir süreç oluşturulur. Bu süreç, asıl süreçten bir kopya oluşturur.
```C
pid_t pid = fork();
```
- Çocuk süreç, paylaşılan belleğe kendi mesajını yazar ve ekrana basar. strcpy() fonksiyonu, çocuk süreçten paylaşılan belleğe veriyi kopyalar.
```C
if (pid == 0) {
    // Çocuk süreç
    const char* message_child = "Bu veri çocuk süreçten geliyor!";
    strcpy(shmaddr, message_child);
    printf("Çocuk süreçten paylaşılan belleğe yazılan veri: %s\n", shmaddr);
}
```
- Ebeveyn süreç, paylaşılan belleğe kendi mesajını yazar ve ekrana basar.
```C
else {
    // Ebeveyn süreç
    const char* message_parent = "Bu veri ebeveyn süreçten geliyor!";
    strcpy(shmaddr, message_parent);
    printf("Ebeveyn süreçten paylaşılan belleğe yazılan veri: %s\n", shmaddr);
}
```
- Paylaşılan belleği serbest bırakmak için shmdt() fonksiyonu kullanılır. Bu fonksiyon, paylaşılan belleği sürecin adres alanından çıkarır.
```C
shmdt(shmaddr);
```

## Communication_shared_memory_2 example Explanation
- #include direktifleri: Gerekli kütüphaneleri dahil eder.
```C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <unistd.h>
```
- #define ile bir sembolik isim tanımlanır. Bu sembolik isim, paylaşılan bellek boyutunu belirtir.
```C
#define SHM_SIZE 1024
```
- ftok() fonksiyonuyla paylaşılan bellek için bir anahtar oluşturulur.
```C
key_t key = ftok("/tmp", 'A');
```
- shmget() fonksiyonuyla paylaşılan bellek segmenti oluşturulur. Bu fonksiyon, paylaşılan belleğin boyutunu ve erişim izinlerini belirler.
```C
int shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666);
```
- shmat() fonksiyonuyla paylaşılan bellek segmenti sürecin adres alanına bağlanır.
```C
char *shmaddr = shmat(shmid, NULL, 0);
```
- fork() fonksiyonuyla yeni bir süreç oluşturulur. Bu süreç, asıl süreçten bir kopya oluşturur.
```C
pid_t pid = fork();
```
- Çocuk süreç, paylaşılan belleğe kendi mesajını yazar ve ekrana basar. strcpy() fonksiyonu, çocuk süreçten paylaşılan belleğe veriyi kopyalar.
```C
if (pid == 0) {
    // Çocuk süreç
    const char* message_child = "Bu veri çocuk süreçten geliyor!";
    strcpy(shmaddr, message_child);
    printf("Çocuk süreçten paylaşılan belleğe yazılan veri: %s\n", shmaddr);
}
```
- Ebeveyn süreç, paylaşılan belleğe kendi mesajını yazar ve ekrana basar.
```C
else {
    // Ebeveyn süreç
    const char* message_parent = "Bu veri ebeveyn süreçten geliyor!";
    strcpy(shmaddr, message_parent);
    printf("Ebeveyn süreçten paylaşılan belleğe yazılan veri: %s\n", shmaddr);
}
```
- Ebeveyn süreçten gelen veriyi çocuk süreçte yazdırmak için wait() fonksiyonu kullanılır. Yani ana process bekletilir.
```C
wait(NULL); // Çocuk sürecin tamamlanmasını bekle
```
- Çocuk süreçten gelen veriyi ekrana yazdırmak için shmaddr değişkeni kullanılır.
```C
printf("Çocuk süreçten gelen veri: %s\n", shmaddr);
```
- Paylaşılan belleği serbest bırakmak için shmdt() fonksiyonu kullanılır. Bu fonksiyon, paylaşılan belleği sürecin adres alanından çıkarır.
```C
shmdt(shmaddr);
```

## communication_message_queue example explanation
- #include direktifleri: Gerekli kütüphaneleri dahil eder.
```c
Copy code
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <unistd.h>
#define ile bir sembolik isim tanımlanır.
```
- Bu sembolik isim, mesajın maksimum boyutunu belirtir.
```c
#define MAX_SIZE 1024
```

- struct msg_buffer yapısı tanımlanır. Bu yapı, mesajın içeriğini ve türünü tutar.
```c
struct msg_buffer {
    long msg_type;
    char msg_text[MAX_SIZE];
};
```

- ftok() fonksiyonuyla key oluşturulur.
```c
key_t key = ftok("/tmp", 'A');
```
- Message Queue oluşturulur. Bu fonksiyon, yeni bir Message Queue oluşturur veya mevcut bir Message Queue'nun kimlik numarasını alır.
```c
int msg_id = msgget(key, 0666 | IPC_CREAT);
```

- fork() fonksiyonuyla yeni bir süreç oluşturulur. Bu süreç, asıl süreçten bir kopya oluşturur.
```c
pid_t pid = fork();
```

- Çocuk süreç, kullanıcıdan bir mesaj alır ve Message Queue'ya gönderir.

```c
if (pid == 0) {
    // Çocuk süreç
    struct msg_buffer message;
    message.msg_type = 1;

    printf("Çocuk süreç: Lütfen bir mesaj girin: ");
    fgets(message.msg_text, MAX_SIZE, stdin);

    // Mesajı Message Queue'ya gönderme
    msgsnd(msg_id, &message, sizeof(message), 0);
}
```
- Ebeveyn süreç, Message Queue'dan mesajı alır ve ekrana yazdırır.

```c
else {
    // Ebeveyn süreç
    struct msg_buffer message;

    // Mesajı Message Queue'dan alma
    msgrcv(msg_id, &message, sizeof(message), 1, 0);

    printf("Ebeveyn süreç: Alınan mesaj: %s", message.msg_text);
}
```

- Message Queue silinir. Bu fonksiyon, Message Queue'yu siler ve belleği serbest bırakır.
```c
if (msgctl(msg_id, IPC_RMID, NULL) == -1) {
    perror("msgctl");
    exit(EXIT_FAILURE);
}
```
- Bu örnekte, ebeveyn ve çocuk süreçler birbirini beklemiyorlar çünkü asenkron bir şekilde iletişim kuruyorlar. İki süreç arasındaki haberleşme Message Queue kullanılarak gerçekleştiriliyor. İşleyiş şu şekilde gerçekleşiyor:

- Ana süreç, fork() fonksiyonu çağrısı ile iki süreç oluşturur: ebeveyn ve çocuk süreçleri.

- Ebeveyn süreç, msgget() fonksiyonu ile bir Message Queue oluşturur veya var olan bir Message Queue'yu alır.

- Ebeveyn süreç, çocuk sürecin oluşturulmasından sonra, çocuk sürece bir mesaj göndermek için msgsnd() fonksiyonunu kullanır. Bu işlem, ebeveyn sürecin engellenmeden devam etmesini sağlar.

- Çocuk süreç, msgrcv() fonksiyonu ile Message Queue'dan bir mesaj alır. Bu işlem, çocuk sürecin engellenmeden devam etmesini sağlar.

- Çocuk süreç, alınan mesajı ekrana yazdırır.

- Ebeveyn süreç, mesajı gönderdikten sonra Message Queue'yu siler.

- Bu şekilde, ebeveyn ve çocuk süreçler birbirini beklemeden çalışır. Message Queue, asenkron iletişimi sağlar ve süreçler arasında veri alışverişi yapılabilir. Bu nedenle, herhangi bir süreç diğerini beklemek zorunda kalmaz ve her iki süreç de bağımsız bir şekilde çalışabilir.

## Socket Programing
- Socket programming is a way of connecting two nodes on a network to communicate with each other. One socket(node) listens on a particular port at an IP, while the other socket reaches out to the other to form a connection. The server forms the listener socket while the client reaches out to the server.

## Example Explanation
### Client Code
- int sock = 0;: Soket dosya tanımlayıcısı için değişken tanımı.
- struct sockaddr_in serv_addr;: Sunucu adresi bilgilerini tutacak sockaddr_in yapısı tanımı.
- char *message;: Kullanıcıdan alınacak mesajı tutacak karakter dizisi için işaretçi tanımı.
- char buffer[1024] = {0};: Sunucudan alınacak cevabı tutacak karakter dizisi tanımı.
- Soket oluşturma ve sunucu adresi yapılandırma:
    - socket(AF_INET, SOCK_STREAM, 0): TCP iletişiminde kullanılan bir soket oluşturuluyor.
    - inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr): Sunucu IP adresi 127.0.0.1 (localhost) olarak ayarlanıyor.
- Sunucuya bağlanma:
    - connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)): Belirtilen sunucuya soket üzerinden bağlantı kuruluyor.

- Kullanıcıdan mesaj alma:
    - scanf("%s", message): Kullanıcıdan bir dize alınıyor. Bu noktada message değişkeni işaretçi olduğu için bellek sızıntısı olabilir; çünkü message için hafıza ayrılmamış.

- Sunucuya mesaj gönderme:
    - send(sock, message, strlen(message), 0): Sunucuya kullanıcının girdiği mesaj gönderiliyor.

- Sunucudan cevap alma:
    - read(sock, buffer, 1024): Sunucudan gelen cevap buffer dizisine okunuyor.

### Server Code
- Değişken Tanımlamaları:

    - server_fd: Sunucu soketi için dosya tanımlayıcısı.
    - new_socket: Yeni bağlantı için dosya tanımlayıcısı.
    - address: sockaddr_in türünden sunucu adresi bilgileri yapısı.
    - addrlen: Adres yapısının boyutunu tutan değişken.
    - buffer: İstemciden alınacak verileri tutacak karakter dizisi.
    - message: İstemciye gönderilecek karşılama mesajı için dinamik bellek alanı.

- Sunucu Soketi Oluşturma:
    - socket(AF_INET, SOCK_STREAM, 0): TCP protokolü için bir soket oluşturulur. Oluşturulan soket dosya tanımlayıcısı server_fd değişkenine atanır.

- Sunucu Adresini Yapılandırma:
    - address.sin_family = AF_INET;: IPv4 adres ailesini belirtir.
    - address.sin_addr.s_addr = INADDR_ANY;: Tüm ağ arabirimlerini dinlemek için IP adresini belirtir.
    - address.sin_port = htons(PORT);: Bağlantı noktasını belirtir.

- Soketi Belirtilen Port ile Bağlama:
    - bind(server_fd, (struct sockaddr *)&address, sizeof(address)): Oluşturulan sunucu soketini belirtilen port ile bağlar.

- Bağlantıları Dinlemeye Başlama:
    - listen(server_fd, 3): Bağlantıları dinlemeye başlar. 3 burada eşzamanlı bağlantı kuyruğunun boyutunu belirtir.

- Bağlantıyı Kabul Etme:
    - new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen)

- İstemciden Veri Alma:
    - read(new_socket, buffer, 1024): İstemciden gelen verileri buffer dizisine okur. 1024 maksimum okunacak bayt sayısını belirtir.

- İstemciye Karşılama Mesajı Gönderme:    
    - `send(new_socket, message, strlen(message), 0)`: İstemciye `message` dizisindeki mesajı gönderir. `strlen(message)` ile mesaj uzunluğu belirtilir.

## TCP/IP UDP
### TCP/IP (Transmission Control Protocol/Internet Protocol)
- TCP/IP, internet üzerinde veri iletimini sağlayan temel iletişim protokollerinin bir kombinasyonudur. Bu protokoller, veri paketlerinin yönlendirilmesi, iletimi ve alınmasını sağlayarak güvenilir iletişim sağlar.

- **Transmission Control Protocol (TCP)**:
    - Bağlantı tabanlı bir protokol.
    - Veri iletimi için güvenilir bir yöntem sağlar.
    - Hedefe ulaşmamış veya bozulmuş paketleri algılar ve yeniden iletim yapar.
    - Veri akışını kontrol etmek için akış kontrolü ve hatırlama (acknowledgment) mekanizmalarını kullanır.
    - Veri akışı için güvenilir, sıralı ve hata düzeltmeli iletişim sağlar.
    - Örneğin, dosya indirme, web sayfalarının yüklenmesi gibi uygulamalar için tercih edilir.
- **Internet Protocol (IP)**
    - Ağdaki bilgisayarların birbirleriyle iletişim kurmasını sağlayan protokol.
    - Veri paketlerinin yönlendirilmesi ve teslimatını sağlar.
    - IP adresleri kullanarak kaynak ve hedef bilgisayarları tanımlar.
    - Ağ üzerindeki veri iletimi için adresleme ve yönlendirme sağlar.
- TCP/IP, internetin temelini oluşturan bu protokollerin birbirleriyle entegrasyonunu sağlar ve ağ iletişimini düzenler.

### UDP (User Datagram Protocol)
- UDP, TCP/IP protokol ailesinin bir parçasıdır ve veri iletimi için alternatif bir protokoldür. UDP, TCP'ye göre daha basit ve daha az güvenilir bir iletişim sağlar.

- **User Datagram Protocol (UDP)**
    - Bağlantısız (connectionless) bir protokol.
    - Veri iletimi için daha az güvenilir bir yöntem sağlar.
    - Hedefe ulaşmamış veya bozulmuş paketleri yeniden iletmek veya düzeltmekle sorumlu değildir.
    - Veri akışını kontrol etmez ve sıralı iletimi garanti etmez.
    - Daha az karmaşık ve daha hızlı iletişim sağlar.
    - Yüksek performans gerektiren uygulamalarda tercih edilebilir, ancak veri kaybı tolere edilebilir.

- UDP, video yayıncılığı, sesli iletişim (VoIP), online oyunlar gibi gerçek zamanlı uygulamalarda tercih edilir. Bu tür uygulamalar, hızlı iletişim ve gecikme (latency) süresinin az olması için UDP'yi tercih edebilirler, ancak veri kaybı olabileceği unutulmamalıdır.

### Farklar ve Kullanım Alanları
- Güvenilirlik: TCP, güvenilir veri iletimi sağlar (hata düzeltmesi, yeniden iletim), UDP ise daha az güvenilir bir iletişim sağlar (veri kaybına izin verir).
- Bağlantı Tabanlı vs. Bağlantısız: TCP bağlantı tabanlıdır (bağlantı kurma ve sonlandırma), UDP ise bağlantısızdır (doğrudan veri iletimi).
- Kullanım Alanları: TCP, dosya transferi, web sayfalarının yüklenmesi gibi uygulamalarda tercih edilirken, UDP gerçek zamanlı uygulamalarda (video yayıncılığı, sesli iletişim, oyunlar) kullanılabilir.

### Bağlantılı (connection-oriented) ve bağlantısız (connectionless) 
- Bağlantılı (connection-oriented) ve bağlantısız (connectionless) terimleri, ağ iletişim protokollerinin temel çalışma modlarına göre tanımlanır. Bu terimler arasındaki fark, iletişimde kullanılan protokolün nasıl çalıştığına ve iletişim kurma yöntemine dayanır. İşte bu terimlerin anlamları ve farkları:

### Bağlantılı (Connection-Oriented) İletişim
- Tanım: Bağlantılı iletişim, iki iletişim noktası (uygulama veya cihazlar arası) arasında önceden bir bağlantı kurulmasını gerektiren iletişim yöntemidir. Bağlantılı iletişimde, veri iletimi için bir başlangıç aşamasında bir bağlantı kurulur ve iletişim sırasında bu bağlantı sürekli olarak izlenir ve yönetilir.
- Özellikler:
    - Bağlantı kurma, bağlantı sürdürme ve bağlantı sonlandırma aşamaları vardır.
    - Veri iletimi için akış kontrolü, hata düzeltme ve akış yönetimi gibi mekanizmalar kullanılır.
    - Güvenilir ve sıralı iletişim sağlar.
    - Örnek olarak TCP (Transmission Control Protocol) bağlantılı bir iletişim protokolüdür.
- Bağlantısız (Connectionless) İletişim
- Tanım: Bağlantısız iletişim, iletişim noktaları arasında önceden bir bağlantı kurulmasını gerektirmeyen iletişim yöntemidir. Her iletim için ayrı ayrı paketler gönderilir ve herhangi bir bağlantı izleme veya yönetme işlemi yapılmaz.
- Özellikler:

    - Bağlantı kurma aşaması yoktur, her iletişim için ayrı paketler gönderilir.
    - Veri paketleri bağımsız olarak iletilir ve işlenir.
    - Veri iletimi için güvenilirlik ve sıralı iletim garantisi yoktur.
    - Örnek olarak UDP (User Datagram Protocol) bağlantısız bir iletişim protokolüdür.

### Farklar
- Bağlantı Kurma:

    - Bağlantılı iletişimde (TCP gibi), iletişim başlamadan önce bir bağlantı kurulması gerekir. Bu bağlantı süreci, karşılıklı olarak iletişim noktaları arasında bir güvenlik ve bağlantı oluşturur.
    - Bağlantısız iletişimde (UDP gibi), her iletim için ayrı paketler gönderilir ve bağlantı önceden kurulmaz.

- Bağlantı İzleme ve Yönetim:

    - Bağlantılı iletişimde, iletişim sırasında bağlantı sürekli olarak izlenir ve yönetilir. Bağlantı kurma, sürdürme ve sonlandırma işlemleri mevcuttur.
    - Bağlantısız iletişimde, her iletim bağımsızdır ve iletişim noktaları arasında sürekli bir bağlantı izleme veya yönetme işlemi yapılmaz.

- Güvenilirlik ve Sıralı İletim:

    - Bağlantılı iletişimde, iletim güvenilir ve sıralıdır. Veri paketleri hedefe ulaşmazsa veya bozuk gelirse, yeniden iletim yapılır.
    - Bağlantısız iletişimde, iletim güvenilir değildir ve veri paketleri hedefe ulaşma garantisi yoktur. Veri paketleri sıralı bir şekilde alınmayabilir.

- Kullanım Alanları:

    - Bağlantılı iletişim, genellikle dosya transferi, web sayfalarının yüklenmesi, e-posta iletimi gibi güvenilir ve sıralı iletişim gerektiren uygulamalarda tercih edilir.
    - Bağlantısız iletişim, gerçek zamanlı uygulamalar (sesli iletişim, video yayıncılığı, online oyunlar) gibi hızlı iletişim ve düşük gecikme gerektiren uygulamalarda tercih edilir.