#ifndef ENTITIES_H
#define ENTITIES_H

#include <string>

/**
 * Klasa Produkt:
 * - nazwa    : nazwa produktu (np. "Margherita")
 * - opis     : kr�tki opis (np. "Sos pomidorowy, ser mozzarella")
 * - kategoria: np. "Pizza", "Nap�j", "Deser"
 */
class Produkt {
public:
    std::string nazwa;
    std::string opis;
    std::string kategoria;

    Produkt(const std::string& nazwa,
        const std::string& opis,
        const std::string& kategoria)
        : nazwa(nazwa), opis(opis), kategoria(kategoria) {
    }
};

/**
 * Klasa PozycjaMenu:
 * - wskazuje na konkretny obiekt Produktu
 * - rozmiar  : np. "ma�a", "�rednia", "du�a", "0.5l", "1.0l", "porcja"
 * - cena     : cena za jedn� sztuk� (dla danej pozycji i rozmiaru)
 */
class PozycjaMenu {
public:
    Produkt* produkt;
    std::string rozmiar;
    double cena;

    PozycjaMenu(Produkt* produkt,
        const std::string& rozmiar,
        double cena)
        : produkt(produkt), rozmiar(rozmiar), cena(cena) {
    }
};

/**
 * Klasa ElementZamowienia:
 * - pozycjaMenu: wskazuje na wybran� PozycjaMenu
 * - ilosc       : ile sztuk tej pozycji w zam�wieniu
 * - cena        : koszt = pozycjaMenu->cena * ilosc
 */
class ElementZamowienia {
public:
    PozycjaMenu* pozycjaMenu;
    int ilosc;
    double cena;

    ElementZamowienia(PozycjaMenu* pozycjaMenu, int ilosc)
        : pozycjaMenu(pozycjaMenu),
        ilosc(ilosc),
        cena(pozycjaMenu->cena* ilosc) {
    }
};

/**
 * Klasa Klient:
 * - imie     : imi� klienta
 * - nazwisko : nazwisko klienta
 * - miasto   : miasto dostawy
 * - ulica    : ulica i numer dostawy
 */
class Klient {
public:
    std::string imie;
    std::string nazwisko;
    std::string miasto;
    std::string ulica;

    Klient(const std::string& imie,
        const std::string& nazwisko,
        const std::string& miasto,
        const std::string& ulica)
        : imie(imie),
        nazwisko(nazwisko),
        miasto(miasto),
        ulica(ulica) {
    }
};

/**
 * Klasa Pracownik:
 * - imie     : imi� pracownika (np. kelner, kucharz, kierowca)
 * - nazwisko : nazwisko pracownika
 * - rola     : "kelner", "kucharz" lub "kierowca"
 * - haslo    : prosta autoryzacja w konsoli
 *
 * Metoda autoryzuj(...) por�wnuje podane has�o z tym przechowywanym.
 */
class Pracownik {
public:
    std::string imie;
    std::string nazwisko;
    std::string rola;
    std::string haslo;

    Pracownik(const std::string& imie,
        const std::string& nazwisko,
        const std::string& rola,
        const std::string& haslo)
        : imie(imie),
        nazwisko(nazwisko),
        rola(rola),
        haslo(haslo) {
    }

    bool autoryzuj(const std::string& hasloUzytkownika) {
        return haslo == hasloUzytkownika;
    }
};

#endif // ENTITIES_H
