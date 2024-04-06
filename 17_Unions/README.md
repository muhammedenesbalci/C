# Unions
- The Union is a user-defined data type in C language that can contain elements of the different data types just like structure. But unlike structures, all the members in the C union are stored in the same memory location. Due to this, only one member can store data at the given instance.

- Her veri tipinden sadece bir eleman olabilir yani sadece bir int değişkeni olabilir. bütün elemanlar aynı memory adresinde depolanıyor

- The size of the union will always be equal to the size of the largest member of the array. All the less-sized elements can store the data in the same space without any overflow.

## Differences with struct
### Struct
- struct, farklı veri türlerini gruplamak için kullanılır.

- Her bir üye (alan), bellekte kendi benzersiz yerini alır.

- Bu nedenle, bir struct'ın boyutu, içindeki tüm üyelerin boyutlarının toplamıdır (bazı hizalama kuralları nedeniyle bu miktar biraz daha büyük olabilir).
- struct'lar genellikle farklı veri parçalarını bir arada tutmak için kullanılır, örneğin bir öğrencinin adı, yaş ve notları.

### Union
- union, aynı bellek alanını paylaşan farklı veri türlerini saklamak için kullanılır.

- Bir union içinde tanımlanan tüm üyeler aynı bellek alanını paylaşır.
Bu nedenle, bir union'ın boyutu, içindeki en büyük üyenin boyutuna eşittir.

- union'lar genellikle bir veri parçasının birden fazla yorumunu saklamak için kullanılır, örneğin bir veri parçasının hem int hem de float olarak kullanılması.

## Resources
- https://www.geeksforgeeks.org/c-unions/