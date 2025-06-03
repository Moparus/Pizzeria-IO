#ifndef MENU_H
#define MENU_H

#include <vector>
#include <string>
#include "Entities.h"   // Produkt, PozycjaMenu

/**
 * Klasa Menu:
 * - przechowuje wszystkie dostêpne PozycjaMenu (np. ró¿ne rodzaje pizzy, napojów, deserów)
 * - za ka¿dym uruchomieniem aplikacji generujemy „na sztywno” listê pozycji w konstruktorze
 * - metody pozwalaj¹ tylko na pobranie listy albo (opcjonalnie) dodanie / usuniêcie pozycji
 */
class Menu {
public:
    // Wektor wskaŸników do wszystkich pozycji w menu
    std::vector<PozycjaMenu*> pozycje;

    // Konstruktor: tutaj WGRYWAMY „na sztywno” wszystkie pozycje
    Menu();

    // Destruktor: zwalniamy pamiêæ zaalokowanych Produkt i PozycjaMenu
    ~Menu();

    // Pobierz wskaŸnik do wszystkich pozycji (tylko do odczytu)
    const std::vector<PozycjaMenu*>& pobierzPozycje() const;

    // (Opcjonalnie) Dodaj now¹ pozycjê do menu
    void dodajPozycje(const std::string& nazwa,
        const std::string& opis,
        const std::string& kategoria,
        const std::string& rozmiar,
        double cena);

    // (Opcjonalnie) Usuñ pozycjê po indeksie w wektorze
    void usunPozycje(int index);
};

#endif // MENU_H
