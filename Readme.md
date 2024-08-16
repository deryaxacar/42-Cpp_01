<div align="center">
  <h1>C++ Module 01</h1> <img src="https://cdn-icons-png.flaticon.com/512/6132/6132222.png" alt="C++ Logo" width="65"></br>
</div>
<p align="center">Bu proje, C++ dilinde temel programlama becerilerini geliştirmek için hazırlanmıştır. Veri türleri, kontrol yapıları ve fonksiyonlar üzerine uygulamalı çalışmalar yapılır. Ayrıca, sınıf tanımlamaları ve bellek yönetimi gibi konular da ele alınır.</p>

---

## İçindekiler

- [Bellek Tahsisi Türleri](#bellek-tahsisi-türleri)
    - [Statik Bellek](#statik-bellek)
    - [Dinamik Bellek](#dinamik-bellek)
    - [Stack ve Heap Belleği Arasındaki Fark](#stack-ve-heap-belleği-arasındaki-fark)
    - [Kullanılabilir işlevler](#kullanılabilir-işlevler)
    - [Örnekler](#örnekler)
    - [Sonuç](#sonuç)
- [Pointer ve Referans İşaretçileri](pointer-ve-referans-işaretçileri)
  - [Pointer Nedir?](#pointer-nedir)
  - [Referans Nedir?](#referans-nedir)
  - [Pointer ve Referans Arasındaki Farklar](#pointer-ve-referans-arasındaki-farklar)
  - [Örnek](#örnek)
  - [Özet](#özet)
 
---

<h2 align="center">Bellek Tahsisi Türleri</h2> 

Bellek yönetimi, C++ programlamada verimli yazılım geliştirme için hayati bir konudur. C++'ta bellek yönetimi, iki ana bellek bölgesi olan **stack** ve **heap** üzerinde gerçekleşir.

### Statik Bellek
Statik bellek, programın derleme zamanında tahsis edilen ve programın tüm çalışma süresi boyunca varlığını sürdüren bellek alanıdır. Statik bellek, genellikle global değişkenler, statik değişkenler ve sabit boyutlu veri yapıları için kullanılır. Bu tür bellek, program kapandığında otomatik olarak serbest bırakılır.

---

### Dinamik Bellek

Dinamik bellek, programın çalışma zamanında ihtiyaç duyulduğunda tahsis edilen bellek alanıdır. Bu bellek, new operatörü kullanılarak ayrılır ve delete operatörü ile manuel olarak serbest bırakılır. Dinamik bellek, esnek boyutlarda veri yapıları ve değişkenler için kullanılır, ancak doğru yönetilmezse bellek sızıntılarına yol açabilir.

---

<h2 align="center">Stack ve Heap Belleği Arasındaki Fark</h2>

---

| Özellik                   | Stack Bellek                                       | Heap Bellek                                        |
|---------------------------|-----------------------------------------------------|-----------------------------------------------------|
| **Bellek Tahsisi**        | Statik bellek tahsisi için kullanılır. Derleme zamanında belirlenir. | Dinamik bellek tahsisi için kullanılır. Çalışma zamanında `new` operatörü ile tahsis edilir. |
| **Kullanım Alanları**     | Yerel değişkenler ve geçici veriler.               | Büyük ve değişken boyutlu veri yapıları.           |
| **Bellek Yönetimi**       | Otomatik olarak yönetilir; fonksiyon tamamlandığında serbest bırakılır. | Manuel olarak yönetilmelidir; `delete` operatörü ile serbest bırakılmalıdır. |
| **Performans**            | Hızlı ve verimlidir, sınırlı bir boyuta sahiptir.  | Daha yavaş çalışır ve daha fazla işlem süresi gerektirir. |
| **Tahsis Zamanı**         | Derleme zamanında tahsis edilir.                   | Çalışma zamanında tahsis edilir.                    |
| **Boyut**                 | Sabit boyut; çalışma sırasında değiştirilemez.     | Esnek boyut; çalışma zamanında belirlenebilir ve değiştirilebilir. |

---

### Kullanılabilir işlevler
- **new:** Dinamik bellek tahsisi yapar ve bir nesne oluşturur.
- **delete:** new ile tahsis edilen belleği serbest bırakır.
- **new[]:** Dinamik diziler için bellek tahsisi yapar.
- **delete[]:** new[] ile tahsis edilen dizilerin belleğini serbest bırakır.

---

### Örnekler

```cpp
#include "Zombie.hpp"

int main()
{
    Zombie *zombie1 = newZombie("Foo"); // Dinamik bellek tahsisi: new operatörü ile heap'te bir Zombie nesnesi oluşturulur.
    zombie1->announce(); // Zombie nesnesinin announce() fonksiyonu çağrılır.

    randomChump("Bar"); // Statik bellek tahsisi: randomChump fonksiyonunda stack üzerinde bir geçici Zombie nesnesi oluşturulur.
    delete zombie1; // Dinamik bellek serbest bırakma: heap'te tahsis edilen Zombie nesnesi serbest bırakılır.

    return 0;
}
```

`newZombie("Foo")` fonksiyonu ile heap üzerinde bir Zombie nesnesi oluşturulup, zombie1 işaretçisine atanır. 
```cpp
#include "Zombie.hpp"

Zombie* newZombie(std::string name){
    return new Zombie(name); // Bu nesne dinamik olarak tahsis edilmiştir ve delete operatörü ile serbest bırakılmalıdır.
}
```
 `randomChump("Bar")` fonksiyonu çağrıldığında, stack üzerinde geçici bir Zombie nesnesi oluşturulur. Bu nesne fonksiyon tamamlandığında otomatik olarak serbest bırakılır.

```cpp
#include "Zombie.hpp"

void randomChump(std::string name)
{
    Zombie zombie(name);
    zombie.announce();
}

```
 `delete zombie1` satırı, new operatörü ile tahsis edilen heap bellek alanını serbest bırakır. Bu işlem, bellek sızıntılarını önlemek için gereklidir.
```cpp
  delete zombie1; 
```

### Sonuç
Stack ve heap bellekleri, C++'ta bellek yönetiminin temel yapı taşlarıdır. Stack, hızlı ve otomatik bir bellek yönetimi sunarken, heap, esneklik ve dinamik bellek tahsisi gerektiren durumlar için uygundur. Her iki bellek türünün de doğru bir şekilde kullanılması, programın performansını ve güvenilirliğini artıracaktır.

---

<h2 align="center">Pointer ve Referans İşaretçileri</h2> 

C++ dilinde, **pointer** (işaretçi) bir değişkenin bellek adresini tutar ve bu adrese erişim sağlar. Pointerlar, bellek yönetimi ve dinamik veri yapıları için kullanılırken, **referans** ise bir değişkenin başka bir adıdır ve orijinal değişkeni doğrudan gösterir. Referanslar, işaretçilerden daha güvenli bir kullanım sağlar çünkü referanslar oluşturulduklarında hemen bir değişkene bağlanır ve bu bağlama daha sonradan değiştirilemez.

---

### Pointer Nedir?

Pointer (işaretçi), bir değişkenin bellek adresini tutan bir değişkendir. İşaretçilerin temel özellikleri şunlardır:

- **Tanım:** Bir işaretçi, bir değişkenin bellek adresini saklar ve bu adrese erişim sağlar.
- **Tanımlama:** İşaretçi değişkenleri `*` sembolü ile tanımlanır.
- **Kullanım:** Bir işaretçiye bir adres atanabilir ve bu adres üzerinden veri erişilebilir.

---

### Referans Nedir?
Referans, bir değişkenin başka bir isimle ifade edilmesidir. Referanslar şu özelliklere sahiptir:

- **Tanım:** Referans, bir değişkenin başka bir adıdır. Referanslar, orijinal değişkeni doğrudan gösterir.
- **Tanımlama:** Referanslar & sembolü ile tanımlanır ve bir değişkene atanabilir.
- **Kullanım:** Referanslar, orijinal değişkenle aynı bellek alanını paylaşır ve bu yüzden referansa yapılan değişiklikler orijinal değişkeni de etkiler.

<h2 align="center">Pointer ve Referans Arasındaki Farklar</h2>


| Özellik            | Pointer                             | Referans                           |
|--------------------|-------------------------------------|------------------------------------|
| **Bellek Yönetimi**| Bellek adresini tutar.              | Doğrudan bir değişkenin adıdır.    |
| **Null Değeri**    | `nullptr` ile boş olabilir.         | Boş olamaz; her zaman geçerli bir değişkene bağlanır. |
| **Değer Atama**    | Yeni bir adres atanabilir.          | Bir kez bağlanır ve bağlandığı değişken değiştirilemez. |
| **Kullanım**       | Dinamik bellek yönetimi gibi ileri düzey işlemler için kullanılır. | Genellikle fonksiyon parametreleri ve geri dönüş değerleri için kullanılır. |

---

### Örnek

```cpp
#include <iostream>
#include <string>

int main()
{
    // Bir string değişkeni tanımlanır ve değer atanır.
    std::string string = "HI THIS IS BRAIN";
    
    // 'string' değişkeninin adresini tutan bir işaretçi tanımlanır.
    std::string *stringPTR = &string;
    
    // 'string' değişkenine referans olarak bağlanan bir referans değişkeni tanımlanır.
    std::string &stringREF = string;

    // 'string' değişkeninin bellek adresi yazdırılır.
    std::cout << "string address: " << &string << std::endl;
    
    // 'stringPTR' işaretçisinin tuttuğu bellek adresi yazdırılır.
    std::cout << "stringPTR address: " << stringPTR << std::endl;
    
    // 'stringREF' referansının bellek adresi yazdırılır.
    // Referans değişkenin adresi, bağlı olduğu 'string' değişkenin adresiyle aynı olacaktır.
    std::cout << "stringREF address: " << &stringREF << std::endl;
    
    // 'string' değişkeninin değeri yazdırılır.
    std::cout << "string value: " << string << std::endl;
    
    // 'stringPTR' işaretçisinin işaret ettiği adresin değeri yazdırılır.
    std::cout << "stringPTR value: " << *stringPTR << std::endl;
    
    // 'stringREF' referansının değeri yazdırılır.
    // Referans, 'string' değişkeninin kendisini ifade eder, bu yüzden değer aynı olacaktır.
    std::cout << "stringREF value: " << stringREF << std::endl;
}
```

kodun çıktısı şu şekiilde olucaktır. 
```shell
string address: 0x7fffc8f5a800
stringPTR address: 0x7fffc8f5a800
stringREF address: 0x7fffc8f5a800
string value: HI THIS IS BRAIN
stringPTR value: HI THIS IS BRAIN
stringREF value: HI THIS IS BRAIN
```

---

### Özet

yani kısaca, işaretçi ve referanslar, değişkenin bellekteki adresine erişimi sağlayarak, değişkenin değerini değiştirme veya okuma işlemleri yapabilir. Bu, işaretçiler ve referansların aynı veri üzerinde işlem yapabilme yeteneğini gösterir.

---
