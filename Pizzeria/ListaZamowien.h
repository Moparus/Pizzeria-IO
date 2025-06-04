#ifndef LISTAZAMOWIEN_H
#define LISTAZAMOWIEN_H

#include <vector>
#include <string>
#include <ctime>
#include "Zamowienie.h"

/**
 * Klasa ListaZamowien:
 * - trzyma wektor wskaŸników do wszystkich zamówieñ w aplikacji
 * - odpowiedzialna za:
 *     • dodawanie nowego zamówienia
 *     • edytowanie istniej¹cego (zmiana daty, statusu, danych klienta/pracownika)
 *     • usuwanie zamówienia
 *     • pobieranie wszystkich zamówieñ (z mo¿liwoœci¹ filtrowania wed³ug miesi¹ca/roku)
 *     • zmiana statusu konkretnego zamówienia
 */
class ListaZamowien {
public:
    // Wektor wszystkich zamówieñ
    std::vector<Zamowienie*> lista;

    // Konstruktor/destruktor
    ListaZamowien();
    ~ListaZamowien();

    // Dodaj nowe zamówienie (alokujemy je dynamicznie)
    void dodajZamowienie(const std::string& typZamowienia,
        std::time_t dataZam,
        std::time_t dataDost,
        Klient* klient,
        Pracownik* pracownik,
        const std::string& status);

    // Edytuj ju¿ istniej¹ce zamówienie (identyfikujemy je wskaŸnikiem)
    void edytujZamowienie(Zamowienie* zam,
        const std::string& nowyTyp,
        std::time_t nowaDataZam,
        std::time_t nowaDataDost,
        const std::string& nowyStatus,
        Klient* nowyKlient,
        Pracownik* nowyPracownik);

    // Usuñ zamówienie (usuwa wskaŸnik z wektora oraz zwalnia pamiêæ)
    void usunZamowienie(Zamowienie* zam);

    // Zmiana statusu zamówienia
    void zmienStatusZamowienia(Zamowienie* zam, const std::string& nowyStatus);

    // Pobierz wszystkie zamówienia
    const std::vector<Zamowienie*>& pobierzWszystkie() const;

    // Pobierz tylko te zamówienia, które by³y z³o¿one w podanym miesi¹cu i roku
    std::vector<Zamowienie*> pobierzWszystkie(int miesiac, int rok) const;
};

#endif // LISTAZAMOWIEN_H
