#include "ListaZamowien.h"
#include <algorithm>
#include <iostream>
#include <ctime>

ListaZamowien::ListaZamowien() {
    // Na start pusty wektor
}

ListaZamowien::~ListaZamowien() {
    // Zwolnij pami?? wszystkich Zamowienie*
    for (Zamowienie* zam : lista) {
        delete zam;
    }
    lista.clear();
}

void ListaZamowien::dodajZamowienie(const std::string& typZamowienia,
    std::time_t dataZam,
    std::time_t dataDost,
    Klient* klient,
    Pracownik* pracownik,
    const std::string& status)
{
    Zamowienie* nowe = new Zamowienie(typZamowienia, dataZam, dataDost, klient, pracownik, status);
    lista.push_back(nowe);
}

void ListaZamowien::edytujZamowienie(Zamowienie* zam,
    const std::string& nowyTyp,
    std::time_t nowaDataZam,
    std::time_t nowaDataDost,
    const std::string& nowyStatus,
    Klient* nowyKlient,
    Pracownik* nowyPracownik)
{
    if (!zam) return;
    zam->typZamowienia = nowyTyp;
    zam->dataZamowienia = nowaDataZam;
    zam->dataDostawy = nowaDataDost;
    zam->status = nowyStatus;
    zam->klient = nowyKlient;
    zam->pracownik = nowyPracownik;
    // NIE modyfikujemy tu kwoty ani elementów – robi? to metody w Zamowienie
}

void ListaZamowien::usunZamowienie(Zamowienie* zam) {
    if (!zam) return;
    auto it = std::find(lista.begin(), lista.end(), zam);
    if (it != lista.end()) {
        delete* it;
        lista.erase(it);
    }
}

void ListaZamowien::zmienStatusZamowienia(Zamowienie* zam, const std::string& nowyStatus) {
    if (!zam) return;
    zam->status = nowyStatus;
}

const std::vector<Zamowienie*>& ListaZamowien::pobierzWszystkie() const {
    return lista;
}

std::vector<Zamowienie*> ListaZamowien::pobierzWszystkie(int miesiac, int rok) const {
    std::vector<Zamowienie*> wynik;
    for (Zamowienie* zam : lista) {
        std::tm tmData;
        // localtime_s zwraca 0 przy sukcesie
        if (localtime_s(&tmData, &zam->dataZamowienia) != 0) {
            continue; // pomi?, je?li b??d konwersji
        }
        int m = tmData.tm_mon + 1;  // tm_mon: [0..11]
        int y = tmData.tm_year + 1900;
        if (m == miesiac && y == rok) {
            wynik.push_back(zam);
        }
    }
    return wynik;
}
