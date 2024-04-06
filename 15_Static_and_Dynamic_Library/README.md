# Static and Dynmaic Library(Shared Objects)
- **Static libraries (statik kütüphaneler)** ve **shared objects (paylaşılan nesneler)** C ve C++ gibi dillerde sıkça kullanılan iki tür kütüphane türüdür.

- Static Libraries:

    Statik kütüphaneler, derlenmiş kaynak kodlarının bir araya getirilip, bir dosya içine sıkıştırılmış halidir.
    Programcılar bu kütüphaneleri programlarında kullanarak, belirli işlevleri veya kod parçalarını tekrar tekrar yazmak zorunda kalmazlar.
    Kütüphane, programın derlenme anında programın kendisine bağlanır (linklenir). Bu nedenle, program çalıştırılmadan önce tüm kütüphane kodu programa dahil edilir.
    .a (archive) uzantısı genellikle statik kütüphaneleri gösterir. .a in linux .lib in windows

- Dynmaic Library(Shared Objects): 

    Paylaşılan nesneler, çalışma zamanında dinamik olarak yüklenen ve paylaşılan bir kütüphane dosyasıdır.
    Bu kütüphaneler, programların çalışma sürecinde dinamik olarak yüklenebilir, yani program çalıştırıldığında bellekte yüklenir.
    Paylaşılan nesneler, birden fazla program tarafından paylaşılabilir ve aynı fiziksel bellek bölgesine yüklenirler, bu nedenle sistemde kaynakların daha etkin kullanılmasını sağlarlar.
    .so (shared object) uzantısı genellikle paylaşılan nesneleri gösterir windows da dll.

- Kullanım durumlarına gelince, statik kütüphaneler, programlarınızın 
    bağımlılıklarını derleme zamanında belirtmek için kullanılır. Programın bağımlılıkları, derleme sırasında tam olarak belirtilir ve derleme sonucunda program, tüm bağımlılıkları içeren tek bir dosya olarak oluşturulur. Paylaşılan nesneler ise programlarınızın çalışma zamanında bağımlılıklarını yüklemek için kullanılır. Bu, daha esnek ve daha hafif bir yaklaşımdır, çünkü bağımlılıklar programın çalışma zamanında yüklenir ve aynı bağımlılıklar birden çok program tarafından paylaşılabilir.

## Static Linking Commands
```bash
- gcc -c static_linking.c -o static_linking.o  # 'static_linking.c' dosyasını bir nesne dosyasına derler
- ar rcs static_linking.a static_linking.o # 'static_linking.o' nesne dosyasını 'static_linking.a' adında bir statik kütüphane dosyasına dönüştürür.
- gcc -c main.c -o main.o  # 'main.c' dosyasını bir nesne dosyasına derler
- gcc main.o -o example_static -L. static_linking.a -static # 'main.o' nesne dosyasını ve 'static_linking.a' statik kütüphanesini kullanarak programı oluşturur
```

- example_static dosyasını bu klasörün dışında da çalıştırabilirsin
- c: Bu bayrak, derleme işlemini gerçekleştirir ve bağlama aşamasını atlar. Yani, sadece kaynak kod dosyalarını derler ve nesne dosyalarını üretir.

- o [dosyaadı]: Bu bayrak, çıktı dosyasının adını belirtir. Derleme işlemi sonunda oluşturulacak dosyanın ismini belirlemek için kullanılır.

- L[dizin]: Bu bayrak, kütüphane dosyalarının bulunduğu dizini belirtir. Programın kütüphaneleri ararken bu dizini kullanır.
- static: Bu bayrak, statik bağlama yapılmasını sağlar. Yani, programın tüm bağımlılıkları derleme aşamasında bağlanır ve sonuç olarak tek bir çalıştırılabilir 

- ar: GNU ar aracı, dosya arşivlerini oluşturmak ve yönetmek için kullanılır. Arşivler genellikle birden fazla nesne dosyasını (*.o uzantılı dosyalar) birleştirmek için kullanılır.

- rcs: Bu, ar komutunun bayraklarıdır:

- r: Arşive dosya ekler veya varolan dosyaları günceller. Eğer dosya arşivde yoksa ekler, varsa üzerine yazar.
c: Yeni bir arşiv dosyası oluşturur. Eğer dosya zaten varsa, içeriğini siler.
s: Arşiv dosyasının semboller tablosunu günceller. Bu, genellikle programların başlatıcı sembollerini içeren bir tablodur.
static_linking.a: Oluşturulacak arşiv dosyasının adıdır. Burada static_linking.a adında bir arşiv dosyası oluşturulacak.

- static_linking.o: Arşive eklenmek istenen nesne dosyasının adıdır. Burada static_linking.o adında bir nesne dosyası kullanılacak.

- Bu komut, static_linking.o adındaki bir nesne dosyasını static_linking.a adında bir arşiv dosyasına ekler. -r bayrağı, eğer arşiv dosyası zaten varsa, varolan nesnelerin üzerine yazar. -c bayrağı, eğer arşiv dosyası yoksa, yeni bir arşiv dosyası oluşturur. -s bayrağı, arşiv dosyasının semboller tablosunu günceller. Bu komut, genellikle statik bir kütüphane oluşturmak için kullanılır.
## Dynamic Linking
```bash
- gcc -c dynamic_linking.c -o dynamic_linking.o  # dynamic_linking.c dosyasını derleyerek dynamic_linking.o nesne dosyasını oluştur
- gcc dynamic_linking.o -o dynamic_linking.so -shared  # dynamic_linking.o nesne dosyasını dynamic_linking.so adında bir dinamik kütüphane dosyasına dönüştür.
- gcc -c main.c -o main.o
- gcc main.o -o example_dynamic -ldl
```
- -ldl, "dynamic linking" (dinamik bağlama) kütüphanesini (libdl) bağlamak için kullanılır.
- -ldl bayrağı, libdl kütüphanesini bağlayarak programın dinamik bağlama işlemleri için gerekli olan işlevleri kullanmasını sağlar. Bu nedenle, dinamik bağlama ile çalışırken -ldl bayrağını eklemek önemlidir.
- <dlfcn.h> başlık dosyası, dinamik bağlama (dynamic linking) ile ilgili işlevleri içeren C programlarında kullanılan bir başlık dosyasıdır. dlfcn.h, UNIX benzeri sistemlerde dinamik bağlama ile çalışırken kullanılan işlevleri tanımlar.
- void *dlopen(const char *filename, int flag): Belirtilen dinamik bağlama dosyasını yükler ve bir tanıtıcı döndürür.

- void *dlsym(void *handle, const char *symbol): Belirtilen sembol adını içeren bir işlev veya veri nesnesini belirtilen dinamik bağlama dosyasından bulur ve işaretçi olarak döndürür.

- int dlclose(void *handle): Belirtilen dinamik bağlama dosyasını kapatır.

- char *dlerror(void): En son oluşan dinamik bağlama hatasının bir açıklamasını döndürür.
- Bu kütüphane bu so dosyasının olmadığı yerdede çalışmaz

## Important Informations
- normal herhangi bir flag kullanmadan yaptığımız buildler dynmaic builddir. Include ettiğimiz so dosyaları sistemde bulunmaktadır. Bu sistem dosyaları için dlmopen gibi komutlar kullanmaya gerek yoktur.

- kendi kütüphanelerimiz so veya .a değil çünkü zaten olduğumuz directory de header ve source file ları var. Her zaman .a veya .so üretmek zounda değliz bunları kaynak kodunu paylaşmka istemediğimiz zaman oluşturuyoruz

- çalıştırılabilir dosyayı elde ettiğinde ldd my_prog yaaprak linkenecek so dosyalarını görebilrsin.

## Resources
- https://www.geeksforgeeks.org/static-and-dynamic-linking-in-operating-systems/
- https://www.geeksforgeeks.org/static-vs-dynamic-libraries/