#include <iostream>
#include <vector>
#include <string>

// Kitap sınıfı
class Kitap {
public:
    Kitap(std::string ad, std::string yazar) : ad(ad), yazar(yazar) {}

    std::string getAd() const {
        return ad;
    }

    std::string getYazar() const {
        return yazar;
    }

private:
    std::string ad;
    std::string yazar;
};

// Kütüphane sınıfı
class Kutuphane {
public:
    // Kitap eklemek
    void kitapEkle(const Kitap& kitap) {
        kitaplar.push_back(kitap);
        std::cout << "Kitap eklendi: " << kitap.getAd() << std::endl;
    }

    // Tüm kitapları listelemek
    void kitapListele() const {
        std::cout << "Kütüphanedeki Kitaplar:" << std::endl;
        for (const auto& kitap : kitaplar) {
            std::cout << "Ad: " << kitap.getAd() << ", Yazar: " << kitap.getYazar() << std::endl;
        }
    }

    // Bir yazarın kitaplarını sorgulamak
    void yazarKitaplariniListele(const std::string& yazar) const {
        std::cout << "Yazarın Kitapları:" << std::endl;
        for (const auto& kitap : kitaplar) {
            if (kitap.getYazar() == yazar) {
                std::cout << "Ad: " << kitap.getAd() << ", Yazar: " << kitap.getYazar() << std::endl;
            }
        }
    }

private:
    std::vector<Kitap> kitaplar;
};

int main() {
    Kutuphane kutuphane;

    // Kitapları ekleyelim
    Kitap kitap1("1984", "George Orwell");
    Kitap kitap2("Suç ve Ceza", "Fyodor Dostoyevsky");
    Kitap kitap3("Beyaz Zambaklar Ülkesinde", "Grigory Petrov");

    kutuphane.kitapEkle(kitap1);
    kutuphane.kitapEkle(kitap2);
    kutuphane.kitapEkle(kitap3);

    // Tüm kitapları listele
    kutuphane.kitapListele();

    // Belirli bir yazarın kitaplarını listele
    std::cout << "\nFyodor Dostoyevsky'nin Kitapları:" << std::endl;
    kutuphane.yazarKitaplariniListele("Fyodor Dostoyevsky");

    return 0;
}