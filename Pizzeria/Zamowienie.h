#ifndef ZAMOWIENIE_H
#define ZAMOWIENIE_H

#include <vector>
#include <string>
#include <ctime>
#include "Entities.h"   // Produkt, PozycjaMenu, ElementZamowienia, Klient, Pracownik

class Zamowienie {
public:
    // Typ zamówienia: np. "telefoniczne" lub "przykasie"
    std::string typZamowienia;
    // Data i godzina z³o¿enia zamówienia
    std::time_t dataZamowienia;
    // Planowana data i godzina dostawy (lub odbioru)
    std::time_t dataDostawy;
    // Kwota ca³kowita (sumowana dynamicznie)
    double kwotaCalkowita;
    // Status zamówienia: np. "nowe", "w trakcie", "gotowe", "dostarczone", "op³acone"
    std::string status;

    // Wskazanie na klienta (dla zamówieñ telefonicznych/dowozowych)
    Klient* klient;
    // Wskazanie na pracownika, który przyj¹³/obs³uguje to zamówienie
    Pracownik* pracownik;

    // Lista elementów (pozycji) w zamówieniu
    std::vector<ElementZamowienia*> elementy;

    // Konstruktor: wszystkie pola poza kwotaCalkowita ustawiamy na wejœciu
    Zamowienie(const std::string& typ,
        std::time_t dataZam,
        std::time_t dataDost,
        Klient* klient,
        Pracownik* pracownik,
        const std::string& status);

    // Destruktor: zwalniamy pamiêæ zaalokowanych ElementZamowienia*
    ~Zamowienie();

    // Dodaje pojedynczy element do zamówienia (iloœæ x danej pozycji)
    void dodajElementZamowienia(PozycjaMenu* pozycja, int ilosc);

    // Usuwa element (po indeksie w wektorze). Obliczamy ponownie kwotê.
    void usunElementZamowienia(int index);

    // Zwraca wszystkie elementy zamówienia (tylko do odczytu)
    const std::vector<ElementZamowienia*>& pobierzElementy() const;
};

#endif // ZAMOWIENIE_H
