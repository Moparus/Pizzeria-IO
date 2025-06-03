#ifndef MENU_H
#define MENU_H

#include <vector>
#include <string>
#include "Entities.h"   // Produkt, PozycjaMenu

/**
 * Klasa Menu:
 * - przechowuje wszystkie dost�pne PozycjaMenu (np. r�ne rodzaje pizzy, napoj�w, deser�w)
 * - za ka�dym uruchomieniem aplikacji generujemy �na sztywno� list� pozycji w konstruktorze
 * - metody pozwalaj� tylko na pobranie listy albo (opcjonalnie) dodanie / usuni�cie pozycji
 */
class Menu {
public:
    // Wektor wska�nik�w do wszystkich pozycji w menu
    std::vector<PozycjaMenu*> pozycje;

    // Konstruktor: tutaj WGRYWAMY �na sztywno� wszystkie pozycje
    Menu();

    // Destruktor: zwalniamy pami�� zaalokowanych Produkt i PozycjaMenu
    ~Menu();

    // Pobierz wska�nik do wszystkich pozycji (tylko do odczytu)
    const std::vector<PozycjaMenu*>& pobierzPozycje() const;

    // (Opcjonalnie) Dodaj now� pozycj� do menu
    void dodajPozycje(const std::string& nazwa,
        const std::string& opis,
        const std::string& kategoria,
        const std::string& rozmiar,
        double cena);

    // (Opcjonalnie) Usu� pozycj� po indeksie w wektorze
    void usunPozycje(int index);
};

#endif // MENU_H
