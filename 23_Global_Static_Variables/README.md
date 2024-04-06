# Global and Static variables
- Global değişkenler ve static (statik) değişkenler, programlama dillerinde farklı kapsam ve yaşam sürelerine sahip olan değişken türleridir. İkilisi arasındaki farkları ayrıntılı olarak açıklayalım:
## **Global Değişkenler** 
- Global değişkenler, programın herhangi bir yerinden erişilebilen ve programın çalışma süresi boyunca varlığını sürdüren değişkenlerdir. Bu değişkenler genellikle programın başında tanımlanır ve global kapsamda (scope) bulunurlar. Yani, bir dosyanın tüm fonksiyonları tarafından erişilebilirler.
    - Özellikleri:
    - Programın herhangi bir yerinden erişilebilirler.
    - Program başladığında oluşturulur ve program sona erene kadar bellekte kalır.
    - Diğer dosyalardan da erişilebilirler (eğer extern anahtar kelimesiyle uygun şekilde tanımlanmışlarsa).
    - Genellikle programın boyunca değişmeyen sabit veriler için kullanılırlar.
    - Global değişkenler, programın karmaşıklığını artırabilir ve hatalara neden olabilir (örneğin, yanlışlıkla değiştirme).
        ```c
        #include <stdio.h>

        int globalVariable = 10;  // Global bir integer değişken

        void func() {
            printf("Global değişken: %d\n", globalVariable);
        }

        int main() {
            func();  // Global değişkene erişim
            return 0;
        }
        ```
## **Static (Statik) Değişkenler** 
- Static değişkenler, tanımlandıkları kapsam içinde ömürlerini sürdüren ancak sadece tanımlandıkları dosya veya fonksiyon içinde erişilebilir olan değişkenlerdir. Bir static değişken tanımlandığında, bellekte ayrılan alan programın başında oluşturulur ve program sona erene kadar bellekte kalır.
    - Özellikleri:
    - Sadece tanımlandıkları kapsam içinde erişilebilirler.
    - Program başladığında oluşturulur, ancak sadece tanımlandıkları dosya veya fonksiyon içinde görünürler.
    - Her çağrıldıklarında değeri korur ve son çağrıldığı değeri hatırlarlar.
    - Fonksiyon içindeki static değişkenler, fonksiyon çağrıldığında bellekte oluşturulur ve fonksiyon çağrısı sona erdiğinde yok olmazlar.
        ```c
        #include <stdio.h>

        void func() {
            static int count = 0;  // Fonksiyon içinde static bir integer değişken
            count++;
            printf("Çağrı sayısı: %d\n", count);
        }

        int main() {
            func();  // Çağrı sayısı: 1
            func();  // Çağrı sayısı: 2
            func();  // Çağrı sayısı: 3
            return 0;
        }

        ```
    - Bu örnekte count adlı static bir değişken, func fonksiyonunun çağrıldığında bellekte oluşturulur ve her çağrıldığında değeri artar. Bu değişken, func fonksiyonunun dışındaki kodlar tarafından erişilemez ve ömrü programın sonuna kadar sürer.

# Global Static Variables
- Bir değişkenin hem global hem de static olarak tanımlanması, bu değişkenin tüm program boyunca yaşamını sürdüreceği ancak yalnızca tanımlandığı dosya içinde erişilebilir olduğu anlamına gelir. Bu, özellikle C gibi dillerde görülen bir durumdur ve genellikle büyük projelerde, modüller arası etkileşimi sınırlamak ve isim çakışmalarını önlemek için kullanılır.

- Global static değişkenler, global değişkenlerin aksine, tanımlandıkları dosya dışından erişilemezler. Bu özellik, farklı dosyalarda aynı isimde global değişkenlerin kullanımını kolaylaştırır ve programın farklı bölümleri arasında veri gizliliğini sağlar. Programın başlangıcında bellekte yer ayrılır ve program sona erene kadar bu bellek bölgesi ayrılmış olarak kalır. Ancak, bu değişkenlere yalnızca tanımlandıkları dosya içerisinden erişilebilir.
    ```c
    static int globalStaticVariable = 0; // Yalnızca bu dosya içinden erişilebilir

    void increment() {
        globalStaticVariable++;
    }

    void print() {
        printf("%d\n", globalStaticVariable);
    }
    ```
- Bu örnekte, globalStaticVariable adlı değişken static olarak tanımlandığı için, yalnızca tanımlandığı dosya içerisindeki fonksiyonlar tarafından erişilebilir ve manipüle edilebilir. Diğer dosyalardaki kodlar bu değişkene doğrudan erişemez veya onun değerini değiştiremez. Bu durum, büyük ve modüler programlarda yanlışlıkla yapılabilecek değişikliklerin önüne geçerek kodun güvenilirliğini artırır.

- Bir değişken hem global hem de static olarak tanımlandığında, bu değişken programın başlangıcından sonuna kadar yaşar, ancak yalnızca tanımlandığı dosya içinde görünür ve erişilebilir olur. Bu, değişkenler arası çakışmayı önlemek ve modüllerin birbirinden bağımsızlığını korumak için kullanışlı bir yöntemdir.