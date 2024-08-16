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
    - [Sonuç](#sonuç)
 
---

<h2 align="center">Bellek Tahsisi Türleri</h2> 

Bellek yönetimi, C++ programlamada verimli yazılım geliştirme için hayati bir konudur. C++'ta bellek yönetimi, iki ana bellek bölgesi olan **stack** ve **heap** üzerinde gerçekleşir.

### Statik Bellek
Statik bellek, programın derleme zamanında tahsis edilen ve programın tüm çalışma süresi boyunca varlığını sürdüren bellek alanıdır. Statik bellek, genellikle global değişkenler, statik değişkenler ve sabit boyutlu veri yapıları için kullanılır. Bu tür bellek, program kapandığında otomatik olarak serbest bırakılır.

**Örnek:**
```cpp
#include <iostream>

int main() {
    int staticVar = 10; // Statik olarak tahsis edilmiş bir değişken
    std::cout << "Statik değişken: " << staticVar << std::endl;
    return 0;
}
```

---

### Dinamik Bellek

Dinamik bellek, programın çalışma zamanında ihtiyaç duyulduğunda tahsis edilen bellek alanıdır. Bu bellek, new operatörü kullanılarak ayrılır ve delete operatörü ile manuel olarak serbest bırakılır. Dinamik bellek, esnek boyutlarda veri yapıları ve değişkenler için kullanılır, ancak doğru yönetilmezse bellek sızıntılarına yol açabilir.

**Örnek:**
```cpp
#include <iostream>

int main() {
    // Dinamik bellek tahsisi
    int* dynamicVar = new int; // Bellek tahsisi yapılır ve işaretçi `dynamicVar` bu belleği işaret eder
    *dynamicVar = 20; // Tahsis edilen bellek alanına değer atanır

    std::cout << "Dinamik değişken: " << *dynamicVar << std::endl;

    // Dinamik belleğin serbest bırakılması
    delete dynamicVar; // `new` ile tahsis edilen bellek serbest bırakılır

    return 0;
}
```

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

### Sonuç
Stack ve heap bellekleri, C++'ta bellek yönetiminin temel yapı taşlarıdır. Stack, hızlı ve otomatik bir bellek yönetimi sunarken, heap, esneklik ve dinamik bellek tahsisi gerektiren durumlar için uygundur. Her iki bellek türünün de doğru bir şekilde kullanılması, programın performansını ve güvenilirliğini artıracaktır.

---

