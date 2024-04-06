#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

/*
C dilinde genellikle POSIX Threads (pthreads) kütüphanesi kullanılarak iş parçacığı oluşturulur ve yönetilir.
*/

//Parellel thread example 1###################################################################################################################################
struct ThreadData {
    int limit;
    pthread_t thread_id;
};

void* printNumbers(void* data) {
    struct ThreadData *thread_data = (struct ThreadData *)data; //casting

    int i;
    int limit = (*thread_data).limit;
    pthread_t thread_id = thread_data->thread_id;

    for (i = 0; i < limit; i++) {
        printf("thread id: %ld ||i: %d\n", thread_id, i);
    }
   pthread_exit(NULL); // Thread'in sonlandığını belirtir. 
}

void parellel_thread_example_1() {
    pthread_t thread1, thread2;
    struct ThreadData thread_data_1, thread_data_2;

    // İki thread oluşturulur.
    thread_data_1.limit = 10;
    pthread_create(&thread1, NULL, printNumbers, (void*)&thread_data_1);

    thread_data_2.limit = 10;
    pthread_create(&thread2, NULL, printNumbers, (void*)&thread_data_2);

    thread_data_1.thread_id = thread1; //Create edip id leri alabilmek için tanımladıktan sonra set ediyoruz
    thread_data_2.thread_id = thread2;

    // Main thread, diğer iki thread'in bitmesini bekler.
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

}

//Parellel thread example 2################################################################################################################################
// Verilere erişme
// Let us create a global variable to change it in threads 
int global_int = 0; 
  
// The function to be executed by all threads 
void *myThreadFun(void *vargp) 
{ 
    // Store the value argument passed to this thread 
    int *myid = (int *)vargp; 
  
    // Let us create a static variable to observe its changes 
    int local_int = 0; 
    static int static_int = 0;
  
    // Change static and global variables 
    ++static_int;
    ++global_int;
    ++local_int;
    
    // Print the argument, static and global variables 
    printf("Thread ID: %d, Static: %d, Global: %d, Local: %d\n", *myid, static_int, global_int, local_int); 
    
    pthread_exit(NULL);
} 

void parellel_thread_example_2() {
    pthread_t thread1, thread2, thread3;
    
    pthread_create(&thread1, NULL, myThreadFun, (void*)&thread1);
    pthread_create(&thread2, NULL, myThreadFun, (void*)&thread2);
    pthread_create(&thread3, NULL, myThreadFun, (void*)&thread3);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);
}
//Thread Communication#################################################################################################################################
//Shared Memory----------------------------------------------------------------------------

#define BUFFER_SIZE 10

int buffer[BUFFER_SIZE]; // Paylaşılan bellek alanı
int index_i = 0; // Buffer indeksi
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER; // Mutex

// Üretici iş parçacığı
void *producer(void *arg) {
    for (int i = 0; i < BUFFER_SIZE; i++) {
        pthread_mutex_lock(&mutex);
        buffer[index_i] = i; // Veri üret
        printf("Producer produced: %d\n", i);
        index_i++;
        pthread_mutex_unlock(&mutex);
    }
    printf("producer end----------------------------------\n");
    pthread_exit(NULL);
}

// Tüketici iş parçacığı
void *consumer(void *arg) {
    int data;
    for (int i = 0; i < BUFFER_SIZE; i++) {
        pthread_mutex_lock(&mutex);
        data = buffer[index_i - 1]; // Veriyi tüket
        printf("Consumer consumed: %d\n", data);
        index_i--;
        pthread_mutex_unlock(&mutex);
    }
    printf("consumer end----------------------------------\n");
    pthread_exit(NULL);
}

void shared_memory_example() {
    pthread_t producer_thread, consumer_thread;

    // Üretici ve tüketici iş parçacıklarını oluştur
    pthread_create(&producer_thread, NULL, producer, NULL);
    pthread_create(&consumer_thread, NULL, consumer, NULL);

    // İş parçacıklarının tamamlanmasını bekle
    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);
}
//Async communicaiton ----------------------------------------------------------------------------
#define BUFFER_SIZE_2 10

int buffer[BUFFER_SIZE_2]; // Paylaşılan bellek alanı
int index_2 = 0; // Buffer indeksi

// Mesaj yapıları
struct Message {
    int data;
};

// Üretici iş parçacığı
void *producer_2(void *arg) {
    for (int i = 0; i < BUFFER_SIZE_2; i++) {
        struct Message message;
        message.data = i; // Mesaj oluştur
        buffer[index_2] = message.data; // Mesajı buffer'a kopyala
        printf("Producer produced: %d\n", message.data);
        index_2++;
    }
    printf("producer end----------------------------------\n");
    pthread_exit(NULL);
}

// Tüketici iş parçacığı
void *consumer_2(void *arg) {
    struct Message message;
    for (int i = 0; i < BUFFER_SIZE_2; i++) {
        message.data = buffer[index_2 - 1]; // Mesajı al
        printf("Consumer consumed: %d\n", message.data);
        index_2--;
    }
    printf("consumer end----------------------------------\n");
    pthread_exit(NULL);
}

void async_com_ex() {
    pthread_t producer_thread, consumer_thread;

    // Üretici ve tüketici iş parçacıklarını oluştur
    pthread_create(&producer_thread, NULL, producer_2, NULL);
    pthread_create(&consumer_thread, NULL, consumer_2, NULL);

    // İş parçacıklarının tamamlanmasını bekle
    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);
}
//Sıralı thread #####################################################################
void responsiveness_thread() {
    pthread_t producer_thread, consumer_thread;

    // Üretici ve tüketici iş parçacıklarını oluştur
    pthread_create(&producer_thread, NULL, producer, NULL);
    pthread_join(producer_thread, NULL);

    pthread_create(&consumer_thread, NULL, consumer, NULL);
    pthread_join(consumer_thread, NULL);
}

//diğer threadın tamamlanması için diğer threadi bekleyen thread örneği########################################################################
pthread_mutex_t mutex_2 = PTHREAD_MUTEX_INITIALIZER;
int thread1_finished = 0;
int count = 0;

void* thread_function1(void* arg) {
    printf("thread 1 started----\n");
    pthread_mutex_lock(&mutex_2);
    for(int i=0; i<10;i++) {
        printf("threadd_function_1: %d\n", count);
        count++;
    }
    thread1_finished = 1;
    pthread_mutex_unlock(&mutex_2);

    printf("thread 1 ended----\n");
    pthread_exit(NULL);
}

void* thread_function2(void* arg) {
    pthread_mutex_lock(&mutex_2);
    printf("thread 2 started----\n");
    while (!thread1_finished) {
        printf("Waiting to thread 1\n");
        pthread_mutex_unlock(&mutex_2);
    }

    for(int i=10; i>0;i--) {
        printf("threadd_function_2: %d\n", count);
        count--;
    }
    pthread_mutex_unlock(&mutex_2);
    printf("thread 2 ended----\n");
    pthread_exit(NULL);
}

void sirali_thread_1() {
    pthread_t thread1, thread2;

    pthread_create(&thread1, NULL, thread_function1, NULL);
    pthread_create(&thread2, NULL, thread_function2, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
}

//diğer threadın tamamlanması için diğer threadi bekleyen thread örneği 2#########################################################################################################################################
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
int count_2 = 0;
pthread_mutex_t mutex_3 = PTHREAD_MUTEX_INITIALIZER;


void* thread_function1_1(void* arg) {
    printf("thread 1 started----\n");
    pthread_mutex_lock(&mutex_3);
    for(int i=0; i<10;i++) {
        printf("thread_function_1: %d\n", count_2);
        count_2++;
    }
    pthread_cond_signal(&cond); // Thread 2'nin beklemesini sonlandır
    pthread_mutex_unlock(&mutex_3);

    printf("thread 1 ended----\n");
    pthread_exit(NULL);
}

void* thread_function1_2(void* arg) {
    printf("thread 2 started----\n");
    pthread_mutex_lock(&mutex_3);
    printf("Waiting for thread 1\n");
    pthread_cond_wait(&cond, &mutex_3); // Thread 1'in bitmesini bekle ve mutex kilidini serbest bırak
    pthread_mutex_unlock(&mutex_3);

    pthread_mutex_lock(&mutex_3); // Mutex kilidini tekrar al
    for(int i=10; i>0;i--) {
        printf("thread_function_2: %d\n", count_2);
        count_2--;
    }
    pthread_mutex_unlock(&mutex_3); // Mutex kilidini serbest bırak

    printf("thread 2 ended----\n");
    pthread_exit(NULL);
}

void sirali_thread_2() {
    pthread_t thread1, thread2;

    pthread_create(&thread1, NULL, thread_function1_1, NULL);
    pthread_create(&thread2, NULL, thread_function1_2, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
}

//Aynı fonksiyonu kullanan threadd örneği#########################################################################################################################################
int count_ex = 0;
pthread_mutex_t mutex_ex = PTHREAD_MUTEX_INITIALIZER;

void* same_thread_ex_func(void *args) {
    pthread_t *thread_id_p = (pthread_t*)args;
    pthread_t thread_id = *thread_id_p;

    printf("thread: %ld ||thread started----\n", thread_id);

    pthread_mutex_lock(&mutex_ex);
    
    for(int i=0; i<10;i++) {
        printf("thread_function_1: %d\n", count_ex);
        count_ex++;
    }
    
    pthread_mutex_unlock(&mutex_ex);

    printf("thread: %ld ||thread ended----\n", thread_id);
    
    pthread_exit(NULL);
}

void same_thred_ex() {
    pthread_t thread1, thread2;

    pthread_create(&thread1, NULL, same_thread_ex_func, (void*)&thread1);
    pthread_create(&thread2, NULL, same_thread_ex_func, (void*)&thread2);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
}

//Resturn değeri olan thread fonksiyonu #########################################################################################################################################
#define NUM_THREADS 2

// İş parçacığı işlevi
void *thread_sum_fun(void *arg) {
    int start = *((int *)arg);

    int end = start + 5; // Toplama aralığı: 5
    
    int *thread_sum = malloc(sizeof(int));
    *thread_sum = 0;

    // Belirlenen aralıkta toplama yap
    for (int i = start; i < end; i++) {
        printf("i: %d\n", i);
        *thread_sum += i;
    }

    // Ana iş parçacığına toplam değeri gönder
    pthread_exit((void *)thread_sum);
}

void sum_ex() {
    int sum = 0;
    pthread_t threads[NUM_THREADS];
    int rc;
    int indexes[NUM_THREADS] = {0, 5}; // Her bir iş parçacığının başlangıç indeksi

    for (int t = 0; t < NUM_THREADS; t++) {
        printf("Ana program: yeni iş parçacığı %d oluşturuluyor...\n", t);
        printf("zzz: %d\n", indexes[t]);
        printf("zzz: %p\n", &indexes[t]);
        rc = pthread_create(&threads[t], NULL, thread_sum_fun, (void *)&indexes[t]);
        if (rc) {
            printf("Hata: pthread_create() başarısız oldu; hata kodu: %d\n", rc);
            exit(-1);
        }
    }

    // Tüm iş parçacıklarının tamamlanması ve toplam sonucunun hesaplanması
    int thread_result;
    int *thread_result_p=NULL;
    for (int t = 0; t < NUM_THREADS; t++) {
        rc = pthread_join(threads[t], (void *)&thread_result_p); //NULL vermek yerine direkt almak istediğimiz değeri veriypruz
        if (rc) {
            printf("Hata: pthread_join() başarısız oldu; hata kodu: %d\n", rc);
            exit(-1);
        }
        thread_result = *((int*) thread_result_p);
        free(thread_result_p);
        printf("xxxxx: %d\n", thread_result);
        sum += thread_result; // Her iş parçacığının toplamını ana toplama ekleyin
    }

    printf("Toplam: %d\n", sum);

    pthread_exit(NULL);

}
int main() {
    
    printf("\nBasic parellel_thread_example_1  #######################\n");
    parellel_thread_example_1();

    printf("\nBasic parellel_thread_example_2  #######################\n");
    parellel_thread_example_2();

    printf("\nshared_memory_example  #######################\n");
    shared_memory_example();

    printf("\nasync_com_ex  #######################\n");
    async_com_ex();

    printf("\nresponsiveness_thread  #######################\n");
    responsiveness_thread();
    
    printf("\nsirali_thread_1  #######################\n");
    sirali_thread_1();
    
    //printf("\nsirali_thread_2  #######################\n");
    //sirali_thread_2();

    printf("\nsame_thred_ex  #######################\n");
    same_thred_ex();

    printf("\nreturing thread examlple  #######################\n");
    sum_ex();

    return 0;
}
