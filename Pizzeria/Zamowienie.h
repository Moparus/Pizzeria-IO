#ifndef ZAMOWIENIE_H
#define ZAMOWIENIE_H

#include <vector>
#include <string>
#include <ctime>
#include "Entities.h"   // Produkt, PozycjaMenu, ElementZamowienia, Klient, Pracownik

class Zamowienie {
public:
    // Typ zam�wienia: np. "telefoniczne" lub "przykasie"
    std::string typZamowienia;
    // Data i godzina z�o�enia zam�wienia
    std::time_t dataZamowienia;
    // Planowana data i godzina dostawy (lub odbioru)
    std::time_t dataDostawy;
    // Kwota ca�kowita (sumowana dynamicznie)
    double kwotaCalkowita;
    // Status zam�wienia: np. "nowe", "w trakcie", "gotowe", "dostarczone", "op�acone"
    std::string status;

    // Wskazanie na klienta (dla zam�wie� telefonicznych/dowozowych)
    Klient* klient;
    // Wskazanie na pracownika, kt�ry przyj��/obs�uguje to zam�wienie
    Pracownik* pracownik;

    // Lista element�w (pozycji) w zam�wieniu
    std::vector<ElementZamowienia*> elementy;

    // Konstruktor: wszystkie pola poza kwotaCalkowita ustawiamy na wej�ciu
    Zamowienie(const std::string& typ,
        std::time_t dataZam,
        std::time_t dataDost,
        Klient* klient,
        Pracownik* pracownik,
        const std::string& status);

    // Destruktor: zwalniamy pami�� zaalokowanych ElementZamowienia*
    ~Zamowienie();

    // Dodaje pojedynczy element do zam�wienia (ilo�� x danej pozycji)
    void dodajElementZamowienia(PozycjaMenu* pozycja, int ilosc);

    // Usuwa element (po indeksie w wektorze). Obliczamy ponownie kwot�.
    void usunElementZamowienia(int index);

    // Zwraca wszystkie elementy zam�wienia (tylko do odczytu)
    const std::vector<ElementZamowienia*>& pobierzElementy() const;
};

#endif // ZAMOWIENIE_H
