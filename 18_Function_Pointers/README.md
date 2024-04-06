# Function Pointers
- In C, like normal data pointers (int *, char *, etc), we can have pointers to functions.

- Why do we need an extra bracket around function pointers like fun_ptr in above example? If we remove bracket, then the expression “void (*fun_ptr)(int)” becomes “void *fun_ptr(int)” which is declaration of a function that returns void pointer. 

- Unlike normal pointers, a function pointer points to code, not data. Typically a function pointer stores the start of executable code.

- Unlike normal pointers, we do not allocate de-allocate memory using function pointers.

- A function’s name can also be used to get functions’ address. we have removed address operator ‘&’ in assignment. We have also changed function call by removing *, the program still works

- Like normal pointers, we can have an array of function pointers. Below example in point 5 shows syntax for array of pointers.

- Like normal data pointers, a function pointer can be passed as an argument and can also be returned from a function.

## Intermediate Examples Explain
### Example 1
- Bu C programı, qsort standart kütüphane fonksiyonunu kullanarak bir tam sayı dizisini küçükten büyüğe doğru sıralar. İşleyişini adım adım açıklayalım:

- compare Fonksiyonu
    - compare fonksiyonu, qsort fonksiyonu tarafından kullanılmak üzere tanımlanmış bir karşılaştırma fonksiyonudur. qsort fonksiyonunun düzgün çalışabilmesi için, dizideki elemanları karşılaştıracak bir mantığa ihtiyaç vardır ve bu mantık compare fonksiyonu ile sağlanır.

    - compare fonksiyonu, void pointer (void*) olarak tanımlanmış iki argüman alır. Bu argümanlar, karşılaştırılacak dizinin elemanlarının adresleridir.

    - Fonksiyon içinde, bu void pointer'lar öncelikle int* türüne dönüştürülür (cast edilir), çünkü dizimiz int türünde elemanlar içerir. Ardından bu pointer'ların gösterdiği değerler dereference edilerek alınır ve birbirlerinden çıkarılır.

    - Sonuç pozitif, negatif ya da sıfır olabilir. Bu sonuç, qsort fonksiyonuna elemanların sıralama sırasını belirler.
- intermediate_example Fonksiyonu

    - arr isminde 6 elemanlı bir tam sayı dizisi tanımlanmış ve başlangıç değerleri verilmiştir.

    - n, dizinin eleman sayısını hesaplar. Bu, dizinin toplam boyutunun (sizeof(arr)) bir elemanının boyutuna (sizeof(arr[0])) bölünmesiyle elde edilir.

    - qsort fonksiyonu çağrılır ve sıralama için gerekli parametreler sağlanır: sıralanacak dizi (arr), dizinin eleman sayısı (n), bir elemanın boyutu (sizeof(int)), ve karşılaştırma için kullanılacak fonksiyon (compare).

    - Daha sonra, sıralanmış dizi bir for döngüsü ile ekrana yazdırılır.

-  qsort Fonksiyonu
    - qsort, C standart kütüphanesinde bulunan genel bir sıralama fonksiyonudur. Her türlü veri türündeki dizileri sıralamak için kullanılabilir. Bunun için kullanıcıdan, sıralama kriterini belirleyecek bir karşılaştırma fonksiyonu sağlaması beklenir. qsort, verilen diziyi, sağlanan karşılaştırma fonksiyonuna göre sıralar.

- Programın Çalışması
    - Program çalıştırıldığında, arr dizisi qsort kullanılarak sıralanır ve sonuç olarak [5, 10, 12, 15, 80, 90] şeklinde sıralı bir dizi elde edilir. Bu dizi, for döngüsü ile ekrana yazdırılır.
## When we need to use ?
- Callback Fonksiyonları: En yaygın kullanım alanlarından biri, callback fonksiyonlarının implementasyonudur. Bir işlem tamamlandığında ya da bir olay gerçekleştiğinde hangi fonksiyonun çağrılacağını belirlemek için fonksiyon pointer'ları kullanılır. Bu, özellikle event-driven (olay yönlendirmeli) programlama ve asynchronous (asenkron) işlemler için çok değerlidir.

- Yüksek Seviye Fonksiyonlar: Fonksiyon pointer'ları, fonksiyonları argüman olarak alabilen ya da fonksiyon döndürebilen yüksek seviye fonksiyonların (higher-order functions) yazılabilmesini sağlar. Bu, özellikle sıralama, filtreleme gibi işlemleri gerçekleştiren genel amaçlı kütüphane fonksiyonlarında kullanılır.

- Duruma Bağlı Davranış: Bir programın çalışma zamanında, bazı koşullara bağlı olarak farklı fonksiyonların çalıştırılması gerektiğinde fonksiyon pointer'ları kullanılabilir. Bu, programın esnekliğini ve yeniden kullanılabilirliğini artırır.

- Polimorfizm: Nesne yönelimli programlamada fonksiyon pointer'ları, C dilinde polimorfizm sağlamak için kullanılabilir. C++'da sanal fonksiyonlar ve sanal tablolar (vtable) bu ihtiyacı karşılar, ancak C dilinde fonksiyon pointer'ları ile manuel olarak benzer bir davranış sağlanabilir.

- Plugin Mimarileri: Uygulamaların genişletilebilir olmasını sağlamak için plugin (eklenti) mimarilerinde fonksiyon pointer'ları kullanılır. Bu sayede, ana program çalışırken dinamik olarak yeni özellikler ekleyebilir.

- Fonksiyon pointer'larının tanımlanması ve kullanılması, söz dizimi açısından biraz karmaşık olabilir. Ancak, bu kavramı öğrendikten sonra, C ve C++ programlama dillerinde çok daha güçlü ve esnek programlar yazmanın kapıları açılır.

## Resources
- https://www.geeksforgeeks.org/function-pointer-in-c/