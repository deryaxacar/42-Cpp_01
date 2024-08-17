<div align="center">
  <h1>C++ Module 01</h1> <img src="https://cdn-icons-png.flaticon.com/512/6132/6132222.png" alt="C++ Logo" width="65"></br></br>
</div>
<p align="center">Bu proje, C++ dilinde temel programlama becerilerini geliştirmek için hazırlanmıştır. Veri türleri, kontrol yapıları ve fonksiyonlar üzerine uygulamalı çalışmalar yapılır. Ayrıca, sınıf tanımlamaları ve bellek yönetimi gibi konular da ele alınır.</p>

---

## İçindekiler

- [Bellek Tahsisi Türleri](#bellek-tahsisi-türleri)
    - [Statik Bellek](#statik-bellek)
    - [Dinamik Bellek](#dinamik-bellek)
    - [Stack Ve Heap Belleği Arasındaki Fark](#stack-ve-heap-belleği-arasındaki-fark)
    - [Kullanılabilir işlevler](#kullanılabilir-işlevler)
    - [Örnekler](#örnekler)
    - [Sonuç](#sonuç)
- [Pointer Ve Referans](pointer-ve-referans)
  - [Pointer Nedir?](#pointer-nedir)
  - [Referans Nedir?](#referans-nedir)
  - [Pointer Ve Referans Arasındaki Farklar](#pointer-ve-referans-arasındaki-farklar)
  - [Örnek](#örnek)
  - [Özet](#özet)
- [Switch Nedir Ve Nasıl Kullanılır?](#switch-nedir-ve-nasıl-kullanılır)
  - [Switch Nasıl Kullanılır?](#switch-nasıl-kullanılır)
  - [Temel Yapısı](#temel-yapısı)
  - [Örnek Kullanım](#örnek-kullanım)
- [ifstream Ve Ofstream Nedir?](#ifstream-ve-ofstream-nedir)
  - [ifstream (Input File Stream)](#ifstream-input-file-stream)
  - [ofstream (Output File Stream)](#ofstream-output-file-stream)
  - [ifstream ve ofstream ortak kullanım örneği](#ifstream-ve-ofstream-ortak-kullanım-örneği)

 
---

<h2 align="center">Bellek Tahsisi Türleri</h2> 

Bellek yönetimi, C++ programlamada verimli yazılım geliştirme için hayati bir konudur. C++'ta bellek yönetimi, iki ana bellek bölgesi olan **stack** ve **heap** üzerinde gerçekleşir.

### Statik Bellek
Statik bellek, programın derleme zamanında tahsis edilen ve programın tüm çalışma süresi boyunca varlığını sürdüren bellek alanıdır. Statik bellek, genellikle global değişkenler, statik değişkenler ve sabit boyutlu veri yapıları için kullanılır. Bu tür bellek, program kapandığında otomatik olarak serbest bırakılır.

---

### Dinamik Bellek

Dinamik bellek, programın çalışma zamanında ihtiyaç duyulduğunda tahsis edilen bellek alanıdır. Bu bellek, new operatörü kullanılarak ayrılır ve delete operatörü ile manuel olarak serbest bırakılır. Dinamik bellek, esnek boyutlarda veri yapıları ve değişkenler için kullanılır, ancak doğru yönetilmezse bellek sızıntılarına yol açabilir.

---

<h2 align="center">Stack Ve Heap Belleği Arasındaki Fark</h2>

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

<h2 align="center">Pointer Ve Referans</h2> 

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

<h2 align="center">Switch Nedir Ve Nasıl Kullanılır?</h2>

switch ifadesi, bir değişkenin değerine göre programın belirli bir yol izlemesini sağlayan bir kontrol yapısıdır. switch, birden fazla durumu kontrol etmek ve her durum için farklı kod blokları çalıştırmak için kullanılır. Bu yapı, birden fazla `if-else` ifadesi yazmaktan daha temiz ve anlaşılır bir alternatif sunar.

### Switch Nasıl Kullanılır?

`switch ifadesi`, bir anahtar kelime (değişken veya ifade) alır ve bu anahtar kelimenin değerine göre farklı case bloklarını çalıştırır. Her case, anahtar kelimenin belirli bir değeri ile eşleşir. Eğer hiçbir case ile eşleşmezse, isteğe bağlı olarak bir default bloğu çalıştırılır.

### Temel Yapısı

```cpp
switch (değişken) {
    case değer1:
        // Değişken değer1 ile eşleşirse bu kod bloğu çalışır
        break;
    case değer2:
        // Değişken değer2 ile eşleşirse bu kod bloğu çalışır
        break;
    // İstenilen kadar case eklenebilir
    default:
        // Hiçbir case ile eşleşmezse bu kod bloğu çalışır
}
```

---

### Örnek Kullanım

```cpp

void Harl::complain(std::string level)
{
    std::string data[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    int i = 0;
    while(!data[i].empty() && data[i] != level)
        i++;
    switch(i)
    {
        case 0:
            this->Harl::debug();
        case 1:
            this->Harl::info();
        case 2:
            this->Harl::warning();
        case 3:
            this->Harl::error();  
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
            break;
    }
}

```

**Açıklama:** 
Bu `switch` yapısı, `i` değişkenine bağlı olarak belirli fonksiyonları çağırır. `i` değeri `0` ile `3` arasında olduğunda sırasıyla `debug()`, `info()`, `warning()`, veya `error()` fonksiyonları çağrılır. `break` komutunun eksik olduğu durumlarda, belirtilen durumdan sonraki tüm fonksiyonlar da çalıştırılır. `i` `0-3` aralığında değilse, varsayılan bir mesaj gösterilir.

Bu yapı, özellikle belirli bir değişkenin birçok farklı değerine göre farklı işlemler yapmak gerektiğinde oldukça kullanışlıdır.

---

<h2 align="center">Ifstream Ve Ofstream Nedir?</h2>

`ifstream` ve `ofstream`, C++ dilinde dosya işlemleri için kullanılan temel akış sınıflarıdır. ifstream dosyalardan veri okumak için, ofstream ise dosyalara veri yazmak için kullanılır. Her iki sınıf da `<fstream>` başlık dosyasında tanımlanmıştır ve dosya akışı sırasında hata kontrolü ve veri işleme işlevlerini yerine getirir. Bu sınıflar, dosya tabanlı veri işleme uygulamalarında yaygın olarak kullanılır ve programcılara esnek bir dosya yönetim mekanizması sunar.

### ifstream (Input File Stream)

**Amaç:** Dosyadan veri okumak için kullanılır.

**Kullanım:** Bir dosya açılır ve bu dosya üzerinden veri okuma işlemi yapılır.

**Örnek:**
```cpp
#include <fstream>
#include <string>

int main() {
    std::ifstream file("example.txt");
    std::string line;

    if (file.is_open()) {
        while (getline(file, line)) {
            std::cout << line << std::endl;
        }
        file.close();
    } else {
        std::cout << "Dosya açılamadı." << std::endl;
    }

    return 0;
}
```
**Açıklama:** Bu program, `example.txt` adındaki bir dosyayı açar ve dosyadaki her satırı okuyup ekrana yazdırır. Eğer dosya başarıyla açılırsa, her satır `getline` fonksiyonu ile okunur ve `std::cout` ile ekrana yazdırılır. Dosya okuma işlemi tamamlandıktan sonra dosya kapatılır. Eğer dosya açılamazsa, hata mesajı ekrana yazdırılır.

---

### ofstream (Output File Stream)

**Amaç:** Dosyaya veri yazmak için kullanılır.

**Kullanım:** Bir dosya açılır veya oluşturulur ve bu dosyaya veri yazma işlemi yapılır.

**Örnek:**
```cpp
#include <fstream>

int main() {
    std::ofstream file("example.txt");

    if (file.is_open()) {
        file << "Hello, World!" << std::endl;
        file.close();
    } else {
        std::cout << "Dosya açılamadı." << std::endl;
    }

    return 0;
}
```

**Açıklama:** Bu program, `example.txt` adında bir dosya oluşturur veya var olan dosyayı açar ve içine `"Hello, World!"` yazdırır. Eğer dosya başarıyla açılırsa, yazma işlemi yapıldıktan sonra dosya kapatılır. Dosya açılamazsa, hata mesajı ekrana yazdırılır.

---

### ifstream ve ofstream ortak kullanım örneği

```cpp
#include <iostream>
#include <fstream>
#include <string>

int main(int ac, char **av)
{
    // Argüman sayısını kontrol et
    if(ac != 4)
    {
        std::cout << "*** You must enter 4 arguments." << std::endl ;
        return 0;
    }

    // Girdi dosyasını aç
    std::ifstream inputFile(av[1]);
    // Dosyanın açılıp açılmadığını kontrol et
    if(!inputFile)
    {
        std::cout << "*** Entered file cannot open." << std::endl;
        return 0;
    }

    // Aranacak ve değiştirilecek kelimeleri al
    std::string s1 = av[2];
    std::string s2 = av[3];

    // Aranacak kelime ve değiştirilmiş kelimenin aynı olup olmadığını kontrol et
    if(s1 == s2)
    {
        std::cout << "*** Are u kidding me? Please enter different word or letter." << std::endl;
        return 0;
    }

    // Dosya açıldıysa işlemlere başla
    if(inputFile.is_open())
    {
        std::string line;
        // Çıktı dosyasının adını belirle
        std::string r_file = av[1];
        r_file += ".replace";
        // Çıktı dosyasını aç
        std::ofstream replace_file(r_file);

        // Girdi dosyasını satır satır oku
        while(std::getline(inputFile, line))
        {
            // Aranacak kelimeyi bul
            size_t found = line.find(s1);
            // Aranacak kelime bulunana kadar işlemi tekrarla
            while(found != std::string::npos)
            {
                // Aranacak kelimeyi sil
                line.erase(found, s1.length());
                // Değiştirilen kelimeyi ekle
                line.insert(found, s2);
                // Bir sonraki arama için pozisyonu güncelle
                found = line.find(s1);
            }
            // Değiştirilen satırı çıktı dosyasına yaz
            replace_file << line << std::endl;
        }
        // Dosyaları kapat
        replace_file.close();
        inputFile.close();
    }
    return 0;
}
```

**Açıklama:** Bu program, komut satırından üç argüman alarak bir dosya üzerinde metin değiştirme işlemi yapar.

- **Argüman Sayısını Kontrol Etme:**
Program, dört argüman (program adı ve üç ek argüman) bekler. Argüman sayısı doğru değilse hata mesajı verir ve sonlanır.

- **Dosya Açma:**
Girdi dosyası `(av[1])` ifstream kullanılarak açılır. Dosya açılamazsa hata mesajı verilir ve program sonlanır.

- **Aranacak ve Değiştirilecek Kelimeler:**
s1 ve s2 isimli iki string değişken, ikinci `(av[2])` ve üçüncü `(av[3])` argümanlardan alınır. Bu iki kelime arasında eşitlik kontrolü yapılır; eğer aynı ise kullanıcıya hata mesajı verilir.

- **Dosya Okuma ve Değişiklik Yapma:**
Girdi dosyası açıldıysa, satır satır okunur. Her satırda `s1` kelimesi aranır. Bulunan tüm s1 kelimeleri, `s2` ile değiştirilir.

- **Sonuçların Yazılması:**
Değiştirilen her satır yeni bir dosyaya `(<original_filename>.replace)` yazılır. Bu dosya, ofstream kullanılarak oluşturulur ve yazma işlemi tamamlandığında kapatılır.

- **Dosya Kapatma:**
Girdi ve çıktı dosyaları kapatılır.

---

Bu README dosyası Derya ACAR tarafından hazırlanmıştır.
