#ifndef LISTAZAMOWIEN_H
#define LISTAZAMOWIEN_H

#include <vector>
#include <string>
#include <ctime>
#include "Zamowienie.h"

/**
 * Klasa ListaZamowien:
 * - trzyma wektor wska�nik�w do wszystkich zam�wie� w aplikacji
 * - odpowiedzialna za:
 *     � dodawanie nowego zam�wienia
 *     � edytowanie istniej�cego (zmiana daty, statusu, danych klienta/pracownika)
 *     � usuwanie zam�wienia
 *     � pobieranie wszystkich zam�wie� (z mo�liwo�ci� filtrowania wed�ug miesi�ca/roku)
 *     � zmiana statusu konkretnego zam�wienia
 */
class ListaZamowien {
public:
    // Wektor wszystkich zam�wie�
    std::vector<Zamowienie*> lista;

    // Konstruktor/destruktor
    ListaZamowien();
    ~ListaZamowien();

    // Dodaj nowe zam�wienie (alokujemy je dynamicznie)
    void dodajZamowienie(const std::string& typZamowienia,
        std::time_t dataZam,
        std::time_t dataDost,
        Klient* klient,
        Pracownik* pracownik,
        const std::string& status);

    // Edytuj ju� istniej�ce zam�wienie (identyfikujemy je wska�nikiem)
    void edytujZamowienie(Zamowienie* zam,
        const std::string& nowyTyp,
        std::time_t nowaDataZam,
        std::time_t nowaDataDost,
        const std::string& nowyStatus,
        Klient* nowyKlient,
        Pracownik* nowyPracownik);

    // Usu� zam�wienie (usuwa wska�nik z wektora oraz zwalnia pami��)
    void usunZamowienie(Zamowienie* zam);

    // Zmiana statusu zam�wienia
    void zmienStatusZamowienia(Zamowienie* zam, const std::string& nowyStatus);

    // Pobierz wszystkie zam�wienia
    const std::vector<Zamowienie*>& pobierzWszystkie() const;

    // Pobierz tylko te zam�wienia, kt�re by�y z�o�one w podanym miesi�cu i roku
    std::vector<Zamowienie*> pobierzWszystkie(int miesiac, int rok) const;
};

#endif // LISTAZAMOWIEN_H
