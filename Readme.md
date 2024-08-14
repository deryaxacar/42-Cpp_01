## C++ Memory Allocation 

C++ dilinde bellek tahsisi konusunu kapsamlı bir şekilde açıklar. İki ana bellek tahsisi türünü ele alacağız: **statik bellek tahsisi** ve **dinamik bellek tahsisi**.

## İçindekiler

1. [Giriş](#giriş)
2. [Statik Bellek Tahsisi](#statik-bellek-tahsisi)
3. [Özellikler](#özellikler)
4. [Dinamik Bellek Tahsisi](#dinamik-bellek-tahsisi)
5. [Özellikler](#özellikler)


## Giriş

Bellek tahsisi, bir programın çalışması sırasında bellek alanlarını yönetme sürecidir. C++ dilinde, bellek tahsisi iki ana türde yapılır: statik ve dinamik.

## Statik Bellek Tahsisi

Statik bellek tahsisi, derleme zamanında belirlenen ve programın çalışma süresi boyunca değişmeyen bellek alanlarının tahsisidir. Bu tür bellek tahsisi genellikle sabit boyutlu veri yapıları ve değişkenler için kullanılır.

### Özellikler

- **Derleme Zamanında Tahsis**: Bellek alanları program derlenirken tahsis edilir.
- **Sabit Boyut**: Bellek boyutu sabittir ve çalışma sırasında değiştirilemez.
- **Otomatik Yönetim**: Bellek otomatik olarak yönetilir ve serbest bırakılır.

### Örnek

```cpp
#include <iostream>

int main() {
    int staticVar = 10; // Statik olarak tahsis edilmiş bir değişken
    std::cout << "Statik değişken: " << staticVar << std::endl;
    return 0;
}
```

## Dinamik Bellek Tahsisi

Dinamik bellek tahsisi, programın çalışma zamanında bellek alanlarını tahsis etme yöntemidir. Bu yöntem, belleği daha esnek ve verimli bir şekilde yönetmeyi sağlar.

### Özellikler

- **Çalışma Zamanında Tahsis**: Bellek alanları program çalışırken tahsis edilir.
- **Esnek Boyut**: Bellek boyutu çalışma zamanında belirlenebilir ve değiştirilebilir.
- **Manuel Yönetim**: Bellek otomatik olarak yönetilir ve serbest bırakılır.


### İşlevler 

- **new:** Dinamik bellek tahsisi yapar ve bir nesne oluşturur.
- **delete:** new ile tahsis edilen belleği serbest bırakır.
- **new[]:** Dinamik diziler için bellek tahsisi yapar.
- **delete[]:** new[] ile tahsis edilen dizilerin belleğini serbest bırakır.

---

Bu README dosyası, C++ dilinde bellek tahsisi ve yönetimi hakkında temel bilgileri sağlar ve hem statik hem de dinamik bellek tahsisi ile ilgili kod örnekleri sunar. Herhangi bir sorunuz varsa, lütfen bana bildirin!
