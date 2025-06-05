#include "Menu.h"
#include <iostream>

Menu::Menu() {
    // Przyk�adowe pozycje �na sztywno�.
    // W realnej aplikacji mo�na by to czyta� z pliku, ale tutaj tworzymy r�cznie.
    // Ka�dy Produkt i PozycjaMenu alokujemy dynamicznie.

    // Pizza Margherita (ma�a, �rednia, du�a)
    Produkt* p1 = new Produkt("Margherita", "Sos pomidorowy, ser mozzarella", "Pizza");
    pozycje.push_back(new PozycjaMenu(p1, "ma�a", 20.0));
    pozycje.push_back(new PozycjaMenu(p1, "�rednia", 25.0));
    pozycje.push_back(new PozycjaMenu(p1, "du�a", 30.0));

    // Pizza Pepperoni
    Produkt* p2 = new Produkt("Pepperoni", "Sos pomidorowy, ser mozzarella, salami", "Pizza");
    pozycje.push_back(new PozycjaMenu(p2, "ma�a", 22.0));
    pozycje.push_back(new PozycjaMenu(p2, "�rednia", 27.5));
    pozycje.push_back(new PozycjaMenu(p2, "du�a", 33.0));

    // Napoje
    Produkt* p3 = new Produkt("Cola", "Nap�j gazowany", "Nap�j");
    pozycje.push_back(new PozycjaMenu(p3, "0.5l", 5.0));
    pozycje.push_back(new PozycjaMenu(p3, "1.0l", 9.0));

    Produkt* p4 = new Produkt("Woda", "Woda mineralna", "Nap�j");
    pozycje.push_back(new PozycjaMenu(p4, "0.5l", 4.0));
    pozycje.push_back(new PozycjaMenu(p4, "1.0l", 7.0));

    // Deser
    Produkt* p5 = new Produkt("Lody", "Lody waniliowe", "Deser");
    pozycje.push_back(new PozycjaMenu(p5, "porcja", 8.0));

    // Mo�esz doda� tu inne pozycje �na sztywno�, je�li potrzebujesz
}

Menu::~Menu() {
    // Zwolnij pami�� wszystkich PozycjaMenu i odpowiadaj�cych im Produkt�w
    for (PozycjaMenu* poz : pozycje) {
        delete poz->produkt;
        delete poz;
    }
    pozycje.clear();
}

const std::vector<PozycjaMenu*>& Menu::pobierzPozycje() const {
    return pozycje;
}

void Menu::dodajPozycje(const std::string& nazwa,
    const std::string& opis,
    const std::string& kategoria,
    const std::string& rozmiar,
    double cena)
{
    Produkt* nowyProdukt = new Produkt(nazwa, opis, kategoria);
    PozycjaMenu* nowaPozycja = new PozycjaMenu(nowyProdukt, rozmiar, cena);
    pozycje.push_back(nowaPozycja);
}

void Menu::usunPozycje(int index) {
    if (index < 0 || index >= static_cast<int>(pozycje.size())) return;
    PozycjaMenu* doUsuniecia = pozycje[index];
    delete doUsuniecia->produkt;
    delete doUsuniecia;
    pozycje.erase(pozycje.begin() + index);
}
