*Bu proje 42 müfredatının bir parçası olarak geliştirilmiş ve oluşturulmuştur.*

# FDF - Wireframe Model

## Açıklama (Description)
FDF, 3 boyutlu bir manzarayı tel kafes (wireframe) modeli olarak basitçe temsil etmeyi amaçlayan bir grafik projesidir. Proje kapsamında, argüman olarak verilen bir .fdf dosyasındaki koordinat noktaları (x, y, z) okunarak çizgi segmentleri (kenarlar) ile birbirine bağlanır ve model ekrana yansıtılır.

Bu projenin temel amaçları; grafik programlama mantığını kavramak, çizgi çizme algoritmalarını (Bresenham vb.) uygulamak ve pencere/olay yönetimini (MiniLibX kullanarak) öğrenmektir.

---

## Özellikler ve Kurallar
* **İzometrik Projeksiyon:** Program, oluşturulan modeli zorunlu olarak izometrik projeksiyon ile ekrana çizmektedir.
* **MiniLibX Kullanımı:** Görüntü oluşturma ve ekrana basma süreçlerinde MiniLibX kütüphanesinin imaj (image) özelliklerinin kullanımı zorunludur.
* **Pencere Yönetimi:** Pencere yönetimi akıcıdır (başka bir pencereye geçildiğinde donma yaşanmaz).
* **Çıkış İşlemleri:** ESC tuşuna basıldığında veya pencerenin çerçevesindeki çarpı (X) ikonuna tıklandığında pencere kapanır ve program tüm ayrılan bellekleri temizleyerek sorunsuz bir şekilde sonlanır.

---

## Kurulum ve Kullanım (Instructions)

### Derleme
Projeyi derlemek için terminalde aşağıdaki komutu çalıştırmanız yeterlidir:
make

Bu işlem, kaynak dosyalarınızı -Wall, -Wextra ve -Werror bayraklarıyla derleyerek fdf isimli çalıştırılabilir dosyayı oluşturacaktır. Gerektiğinde temizlik yapmak için clean, fclean ve re kuralları kullanılabilir.

### Çalıştırma
Program, parametre olarak geçerli bir harita dosyası almalıdır:
./fdf test_maps/42.fdf

Haritadaki her sayı uzayda bir noktayı belirtir:
* Yatay konum apsisi (X ekseni) temsil eder.
* Dikey konum ordinatı (Y ekseni) temsil eder.
* Sayının değeri ise yüksekliği (Z ekseni) temsil eder.

---

## Kaynaklar ve Yapay Zeka Kullanımı (Resources)
* **Temel Referanslar:** Bresenham Çizgi Çizme Algoritması, İzometrik İzdüşüm Formülleri ve MiniLibX Kütüphane Dokümantasyonu.
* **Yapay Zeka (AI) Kullanımı:** Bu projede yapay zeka araçları, .fdf dosyalarındaki verilerin okunması ve parse edilmesi sürecinde kod tekrarlarını azaltmak, ayrıca doğru ve verimli algoritmik yaklaşımlar (örneğin çizgi çizme mantığı) üzerine fikir alışverişi yapmak amacıyla kullanılmıştır. Üretilen içerik veya mantıklar projeye doğrudan kopyalanmamış; sistemli olarak test edilmiş, sorgulanmış ve akran değerlendirmelerinden geçirilerek koda entegre edilmiştir.
