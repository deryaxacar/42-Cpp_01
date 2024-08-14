## C++ Memory Allocation 

C++ dilinde bellek tahsisi konusunu kapsamlı bir şekilde açıklar. İki ana bellek tahsisi türünü ele alacağız: **statik bellek tahsisi** ve **dinamik bellek tahsisi**.

## İçindekiler

1. [Giriş](#giriş)
2. [Statik Bellek Tahsisi](#statik-bellek-tahsisi)
3. [Dinamik Bellek Tahsisi](#dinamik-bellek-tahsisi)
4. [Örnekler](#örnekler)
5. [En İyi Uygulamalar](#en-iyi-uygulamalar)
6. [Kaynaklar](#kaynaklar)

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
