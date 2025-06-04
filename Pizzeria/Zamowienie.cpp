#include "Zamowienie.h"
#include <iostream>

Zamowienie::Zamowienie(const std::string& typ,
    std::time_t dataZam,
    std::time_t dataDost,
    Klient* klient,
    Pracownik* pracownik,
    const std::string& status)
    : typZamowienia(typ),
    dataZamowienia(dataZam),
    dataDostawy(dataDost),
    kwotaCalkowita(0.0),
    status(status),
    klient(klient),
    pracownik(pracownik)
{
    // Na pocz¹tku elementy s¹ puste, kwota = 0
}

Zamowienie::~Zamowienie() {
    // Zwolnij wszystkie ElementZamowienia*
    for (ElementZamowienia* el : elementy) {
        delete el;
    }
    elementy.clear();
}

void Zamowienie::dodajElementZamowienia(PozycjaMenu* pozycja, int ilosc) {
    if (ilosc <= 0) return;
    ElementZamowienia* nowy = new ElementZamowienia(pozycja, ilosc);
    kwotaCalkowita += nowy->cena;
    elementy.push_back(nowy);
}

void Zamowienie::usunElementZamowienia(int index) {
    if (index < 0 || index >= static_cast<int>(elementy.size())) return;
    ElementZamowienia* doUsuniecia = elementy[index];
    kwotaCalkowita -= doUsuniecia->cena;
    delete doUsuniecia;
    elementy.erase(elementy.begin() + index);
}

const std::vector<ElementZamowienia*>& Zamowienie::pobierzElementy() const {
    return elementy;
}
