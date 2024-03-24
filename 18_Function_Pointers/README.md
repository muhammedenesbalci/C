# Function Pointers
- In C, like normal data pointers (int *, char *, etc), we can have pointers to functions.
- Why do we need an extra bracket around function pointers like fun_ptr in above example? If we remove bracket, then the expression “void (*fun_ptr)(int)” becomes “void *fun_ptr(int)” which is declaration of a function that returns void pointer. 
- Unlike normal pointers, a function pointer points to code, not data. Typically a function pointer stores the start of executable code.
- Unlike normal pointers, we do not allocate de-allocate memory using function pointers.
- A function’s name can also be used to get functions’ address. we have removed address operator ‘&’ in assignment. We have also changed function call by removing *, the program still works(example-2).
- Like normal pointers, we can have an array of function pointers. Below example in point 5 shows syntax for array of pointers.
- Like normal data pointers, a function pointer can be passed as an argument and can also be returned from a function.

# Intermediate example explain
Bu C programı, qsort standart kütüphane fonksiyonunu kullanarak bir tam sayı dizisini küçükten büyüğe doğru sıralar. İşleyişini adım adım açıklayalım:

1. compare Fonksiyonu
- compare fonksiyonu, qsort fonksiyonu tarafından kullanılmak üzere tanımlanmış bir karşılaştırma fonksiyonudur. qsort fonksiyonunun düzgün çalışabilmesi için, dizideki elemanları karşılaştıracak bir mantığa ihtiyaç vardır ve bu mantık compare fonksiyonu ile sağlanır.

- compare fonksiyonu, void pointer (void*) olarak tanımlanmış iki argüman alır. Bu argümanlar, karşılaştırılacak dizinin elemanlarının adresleridir.
- Fonksiyon içinde, bu void pointer'lar öncelikle int* türüne dönüştürülür (cast edilir), çünkü dizimiz int türünde elemanlar içerir. Ardından bu pointer'ların gösterdiği değerler dereference edilerek alınır ve birbirlerinden çıkarılır.
- Sonuç pozitif, negatif ya da sıfır olabilir. Bu sonuç, qsort fonksiyonuna elemanların sıralama sırasını belirler.
2. intermediate_example Fonksiyonu

- arr isminde 6 elemanlı bir tam sayı dizisi tanımlanmış ve başlangıç değerleri verilmiştir.
- n, dizinin eleman sayısını hesaplar. Bu, dizinin toplam boyutunun (sizeof(arr)) bir elemanının boyutuna (sizeof(arr[0])) bölünmesiyle elde edilir.
- qsort fonksiyonu çağrılır ve sıralama için gerekli parametreler sağlanır: sıralanacak dizi (arr), dizinin eleman sayısı (n), bir elemanın boyutu (sizeof(int)), ve karşılaştırma için kullanılacak fonksiyon (compare).
- Daha sonra, sıralanmış dizi bir for döngüsü ile ekrana yazdırılır.
3. qsort Fonksiyonu
- qsort, C standart kütüphanesinde bulunan genel bir sıralama fonksiyonudur. Her türlü veri türündeki dizileri sıralamak için kullanılabilir. Bunun için kullanıcıdan, sıralama kriterini belirleyecek bir karşılaştırma fonksiyonu sağlaması beklenir. qsort, verilen diziyi, sağlanan karşılaştırma fonksiyonuna göre sıralar.

4. Programın Çalışması
- Program çalıştırıldığında, arr dizisi qsort kullanılarak sıralanır ve sonuç olarak [5, 10, 12, 15, 80, 90] şeklinde sıralı bir dizi elde edilir. Bu dizi, for döngüsü ile ekrana yazdırılır.

- https://www.geeksforgeeks.org/function-pointer-in-c/