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
        - [Stack Bellek](#stack-bellek)
        - [Heap Bellek](#heap-bellek)
    - [Kullanılabilir işlevler](#kullanılabilir-işlevler)
    - [Örnekler](#örnekler)
    - [Sonuç](#sonuç)
 
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

### Stack Bellek
- **Statik Bellek Tahsisi:** Stack, statik bellek tahsisi için kullanılır. Bellek, programın derleme zamanında belirlenir.
- **Yerel Değişkenler:** Fonksiyon çağrıları sırasında yerel değişkenler ve geçici veriler stack bellekte saklanır.
- **Otomatik Bellek Yönetimi:** Stack bellekteki bellek, fonksiyon tamamlandığında otomatik olarak serbest bırakılır.
- **Performans:** Stack bellek hızlıdır ve sınırlı bir boyuta sahiptir.
- **Derleme Zamanında Tahsis:** Bellek alanları program derlenirken tahsis edilir.
- **Sabit Boyut:** Stack belleğin boyutu sabittir ve çalışma sırasında değiştirilemez.

---

### Heap Bellek
- **Dinamik Bellek Tahsisi:** Heap, dinamik bellek tahsisi için kullanılır. Bellek, programın çalışma zamanında `new` operatörü ile ayrılır.
- **Esneklik:** Heap, büyük ve değişken boyutlu veri yapıları için uygundur.
- **Manuel Bellek Yönetimi:** Heap belleği yönetmek için `delete` operatörü ile manuel olarak serbest bırakılmalıdır.
- **Performans:** Heap bellek, stack belleğe göre daha yavaş çalışır ve daha fazla işlem süresi gerektirir.
- **Çalışma Zamanında Tahsis:** Bellek alanları program çalışırken tahsis edilir.
- **Esnek Boyut:** Heap belleğin boyutu çalışma zamanında belirlenebilir ve değiştirilebilir.

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

