﻿#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <iomanip>
#include <cstdlib>
#include "Entities.h"
#include "Menu.h"
#include "ListaZamowien.h"
#include <algorithm>

using namespace std;

using std::cout; // Add this line to explicitly specify the namespace for cout
using std::endl; // Add this line to explicitly specify the namespace for endl

// Prototypy funkcji widoków
void widokKelnera(vector<Pracownik*>& pracownicy, Menu& menu, ListaZamowien& listaZamowien);
void widokKuchni(vector<Pracownik*>& pracownicy, ListaZamowien& listaZamowien);
void widokKierowcy(vector<Pracownik*>& pracownicy, ListaZamowien& listaZamowien);
void widokSzefa(vector<Pracownik*>& pracownicy, Menu& menu, ListaZamowien& listaZamowien);

void clearScreen() {
    system("cls"); // Windows
    // #ifdef _WIN32
    //     system("cls");
    // #else
    //     system("clear");
    // #endif
}

// Formatowanie czasu
string czasNaString(time_t t) {
    tm lt;
    if (localtime_s(&lt, &t) != 0) {
        return "blad daty";
    }
    char buf[20];
    strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M", &lt);
    return string(buf);
}

int main() {
    setlocale(LC_ALL, "pl_PL");
    // Inicjalizacja pracowników (role i hasła „na sztywno”)
    vector<Pracownik*> pracownicy;
    pracownicy.push_back(new Pracownik("Jan", "Kowalski", "kelner", "kelner"));
    pracownicy.push_back(new Pracownik("Anna", "Nowak", "kucharz", "kucharz"));
    pracownicy.push_back(new Pracownik("Piotr", "Zielinski", "kierowca", "kierowca"));
    pracownicy.push_back(new Pracownik("Stefan", "Szef", "szef", "szef"));

    // Menu i lista zamówień
    Menu menu;
    ListaZamowien listaZamowien;

    const auto& pozycjeMenu = menu.pobierzPozycje();
    if (pozycjeMenu.size() >= 2) { // Sprawdź czy są pozycje w menu
        // Zamówienie 1
        Klient* k1 = new Klient("Adam", "Nowak", "Warszawa", "ul. Kwiatowa 1");
        listaZamowien.dodajZamowienie("telefoniczne", time(nullptr) - 3600 * 24, time(nullptr) - 3600 * 23, k1, pracownicy[0], "nowe");
        listaZamowien.pobierzWszystkie().back()->dodajElementZamowienia(pozycjeMenu[0], 2);

        // Zamówienie 2
        Klient* k2 = new Klient("Beata", "Kowalczyk", "Kraków", "ul. Słoneczna 5");
        listaZamowien.dodajZamowienie("przykasie", time(nullptr) - 3600 * 20, time(nullptr) - 3600 * 19, k2, pracownicy[0], "gotowe");
        listaZamowien.pobierzWszystkie().back()->dodajElementZamowienia(pozycjeMenu[1], 1);

        // Zamówienie 3
        Klient* k3 = new Klient("Cezary", "Lis", "Poznań", "ul. Polna 7");
        listaZamowien.dodajZamowienie("telefoniczne", time(nullptr) - 3600 * 10, time(nullptr) - 3600 * 9, k3, pracownicy[0], "w trakcie dostawy");
        listaZamowien.pobierzWszystkie().back()->dodajElementZamowienia(pozycjeMenu[0], 1);

        // Zamówienie 4
        Klient* k4 = new Klient("Dorota", "Mazur", "Gdańsk", "ul. Leśna 3");
        listaZamowien.dodajZamowienie("przykasie", time(nullptr) - 3600 * 5, time(nullptr) - 3600 * 4, k4, pracownicy[0], "wydane");
        listaZamowien.pobierzWszystkie().back()->dodajElementZamowienia(pozycjeMenu[1], 3);

        // Zamówienie 5
        Klient* k5 = new Klient("Ewa", "Bąk", "Wrocław", "ul. Długa 10");
        listaZamowien.dodajZamowienie("telefoniczne", time(nullptr) - 3600 * 2, time(nullptr) - 3600 * 1, k5, pracownicy[0], "nowe");
        listaZamowien.pobierzWszystkie().back()->dodajElementZamowienia(pozycjeMenu[0], 1);
        listaZamowien.pobierzWszystkie().back()->dodajElementZamowienia(pozycjeMenu[1], 2);
    }

    while (true) {
        clearScreen();
        cout << "==== Pizzeria Konsola ====" << endl;
        cout << "Wybierz widok:" << endl;
        cout << "1. Kelner" << endl;
        cout << "2. Kuchnia" << endl;
        cout << "3. Kierowca" << endl;
        cout << "4. Szef" << endl;
        cout << "5. Wyjscie" << endl;
        cout << "Twoj wybor: ";

        string wyborStr;
        getline(cin, wyborStr);
        int wybor = 0;
        try { wybor = stoi(wyborStr); }
        catch (...) { wybor = 0; }

        switch (wybor) {
        case 1:
            widokKelnera(pracownicy, menu, listaZamowien);
            break;
        case 2:
            widokKuchni(pracownicy, listaZamowien);
            break;
        case 3:
            widokKierowcy(pracownicy, listaZamowien);
            break;
        case 4:
            widokSzefa(pracownicy, menu, listaZamowien);
            break;
        case 5:
            cout << "Koniec." << endl;
            for (auto p : pracownicy) delete p;
            return 0;
        default:
            cout << "Nieprawidlowy wybor. Nacisnij Enter, aby sprobowac ponownie...";
            getline(cin, wyborStr);
        }
    }
    return 0;
}

// Widok kelnera
void widokKelnera(vector<Pracownik*>& pracownicy, Menu& menu, ListaZamowien& listaZamowien) {
    clearScreen();
    cout << "--- Widok Kelnera ---" << endl;
    cout << "Podaj haslo: ";
    string haslo;
    getline(cin, haslo);

    Pracownik* zalogowany = nullptr;
    for (auto p : pracownicy) {
        if (p->rola == "kelner" && p->autoryzuj(haslo)) {
            zalogowany = p;
            break;
        }
    }
    if (!zalogowany) {
        cout << "Blad logowania. Nacisnij Enter, aby wrocic do menu glownego." << endl;
        getline(cin, haslo);
        return;
    }

    while (true) {
        clearScreen();
        cout << "Zalogowano jako kelner: " << zalogowany->imie << " " << zalogowany->nazwisko << endl;
        cout << "\n--- Menu Kelnera ---" << endl;
        cout << "1. Dodaj nowe zamowienie" << endl;
        cout << "2. Edytuj zamowienie (dodaj/usun elementy)" << endl;
        cout << "3. Zmien status zamowienia" << endl;
        cout << "4. Pokaz wszystkie zamowienia" << endl;
        cout << "5. Wyloguj" << endl;
        cout << "6. Archiwum zamowien" << endl;
        cout << "Wybor: ";

        string wStr;
        getline(cin, wStr);
        int w = 0;
        try { w = stoi(wStr); }
        catch (...) { w = 0; }

        if (w == 5) {
            cout << "Wylogowano. Nacisnij Enter, aby wrocic do glownego menu." << endl;
            getline(cin, wStr);
            break;
        }

        if (w == 1) {
            // Typ zamówienia
            cout << "Typ zamowienia:" << endl;
            cout << "1. telefoniczne" << endl;
            cout << "2. przykasie" << endl;
            cout << "Wybor: ";
            string typStr;
            getline(cin, typStr);
            int typNum = 0;
            try { typNum = stoi(typStr); }
            catch (...) { typNum = 0; }
            string typ = (typNum == 1 ? "telefoniczne" : "przykasie");

            // Dane klienta
            cout << "Dane klienta:" << endl;
            cout << "Imie: ";
            string imie; getline(cin, imie);
            cout << "Nazwisko: ";
            string nazwisko; getline(cin, nazwisko);
            cout << "Miasto: ";
            string miasto; getline(cin, miasto);
            cout << "Ulica: ";
            string ulica; getline(cin, ulica);

            Klient* klient = new Klient(imie, nazwisko, miasto, ulica);
            time_t teraz = time(nullptr);
            time_t dostawa = teraz + 3600;
            string status = "nowe";

            listaZamowien.dodajZamowienie(typ, teraz, dostawa, klient, zalogowany, status);
            auto& wszystkie = const_cast<vector<Zamowienie*>&>(listaZamowien.pobierzWszystkie());
            Zamowienie* zam = wszystkie.back();

            cout << "Zamowienie utworzone (ID = " << wszystkie.size() - 1 << "). Dodaj elementy:" << endl;
            while (true) {
                const auto& pozycjeMenu = menu.pobierzPozycje();
                cout << "\nDostepne pozycje menu:" << endl;
                for (size_t i = 0; i < pozycjeMenu.size(); ++i) {
                    cout << i << ". " << pozycjeMenu[i]->produkt->nazwa
                        << " (" << pozycjeMenu[i]->rozmiar << "), cena: "
                        << fixed << setprecision(2) << pozycjeMenu[i]->cena << endl;
                }
                cout << "Wybierz numer pozycji (-1 konczy): ";
                string idxStr;
                getline(cin, idxStr);
                int idx = -1;
                try { idx = stoi(idxStr); }
                catch (...) { idx = -1; }

                if (idx < 0 || idx >= static_cast<int>(pozycjeMenu.size())) {
                    break;
                }
                cout << "Ilosc: ";
                string iloscStr;
                getline(cin, iloscStr);
                int ilosc = 0;
                try { ilosc = stoi(iloscStr); }
                catch (...) { ilosc = 0; }

                zam->dodajElementZamowienia(pozycjeMenu[idx], ilosc);
                cout << "Dodano element. Obecna kwota: " << fixed << setprecision(2) << zam->kwotaCalkowita << endl;
            }
            cout << "Zakonczenie dodawania elementow. Nacisnij Enter, aby wrocic do menu Kelnera." << endl;
            getline(cin, wStr);
        }
        else if (w == 2) {
            auto& wszystkie = const_cast<vector<Zamowienie*>&>(listaZamowien.pobierzWszystkie());
            if (wszystkie.empty()) {
                cout << "Brak zamowien. Nacisnij Enter, aby wrocic." << endl;
                getline(cin, wStr);
                continue;
            }
            cout << "Wybierz ID zamowienia do edycji:" << endl;
            for (size_t i = 0; i < wszystkie.size(); ++i) {
                if (wszystkie[i]->status != "wydane") {
                    cout << i << ". Status: " << wszystkie[i]->status
                        << ", Kwota: " << fixed << setprecision(2) << wszystkie[i]->kwotaCalkowita << endl;
                }
            }
            string idStr;
            getline(cin, idStr);
            int id = -1;
            try { id = stoi(idStr); }
            catch (...) { id = -1; }

            if (id < 0 || id >= static_cast<int>(wszystkie.size()) || wszystkie[id]->status == "wydane") {
                cout << "Nieprawidlowe ID. Nacisnij Enter, aby wrocic." << endl;
                getline(cin, wStr);
                continue;
            }
            Zamowienie* zam = wszystkie[id];
            cout << "1. Dodaj element\n2. Usun element\nWybor: ";
            string eStr;
            getline(cin, eStr);
            int e = 0;
            try { e = stoi(eStr); }
            catch (...) { e = 0; }

            if (e == 1) {
                const auto& pozycjeMenu = menu.pobierzPozycje();
                cout << "\nDostepne pozycje menu:" << endl;
                for (size_t i = 0; i < pozycjeMenu.size(); ++i) {
                    cout << i << ". " << pozycjeMenu[i]->produkt->nazwa
                        << " (" << pozycjeMenu[i]->rozmiar << "), cena: "
                        << fixed << setprecision(2) << pozycjeMenu[i]->cena << endl;
                }
                cout << "Wybierz numer pozycji: ";
                string idxStr;
                getline(cin, idxStr);
                int idx = -1;
                try { idx = stoi(idxStr); }
                catch (...) { idx = -1; }

                if (idx < 0 || idx >= static_cast<int>(pozycjeMenu.size())) {
                    cout << "Nieprawidlowy indeks. Nacisnij Enter, aby wrocic." << endl;
                    getline(cin, wStr);
                    continue;
                }
                cout << "Ilosc: ";
                string iloscStr;
                getline(cin, iloscStr);
                int ilosc = 0;
                try { ilosc = stoi(iloscStr); }
                catch (...) { ilosc = 0; }

                zam->dodajElementZamowienia(pozycjeMenu[idx], ilosc);
                cout << "Dodano element. Nowa kwota: " << fixed << setprecision(2) << zam->kwotaCalkowita << endl;
                cout << "Nacisnij Enter, aby wrocic." << endl;
                getline(cin, wStr);
            }
            else if (e == 2) {
                const auto& elem = zam->pobierzElementy();
                if (elem.empty()) {
                    cout << "Brak elementow w zamowieniu. Nacisnij Enter, aby wrocic." << endl;
                    getline(cin, wStr);
                    continue;
                }
                cout << "Elementy w zamowieniu:" << endl;
                for (size_t i = 0; i < elem.size(); ++i) {
                    cout << i << ". " << elem[i]->pozycjaMenu->produkt->nazwa
                        << " (" << elem[i]->pozycjaMenu->rozmiar << "), ilosc: "
                        << elem[i]->ilosc << ", cena: "
                        << fixed << setprecision(2) << elem[i]->cena << endl;
                }
                cout << "Wybierz numer elementu do usuniecia: ";
                string idxStr;
                getline(cin, idxStr);
                int idx = -1;
                try { idx = stoi(idxStr); }
                catch (...) { idx = -1; }

                if (idx < 0 || idx >= static_cast<int>(elem.size())) {
                    cout << "Nieprawidlowy indeks. Nacisnij Enter, aby wrocic." << endl;
                    getline(cin, wStr);
                    continue;
                }
                zam->usunElementZamowienia(idx);
                cout << "Element usuniety. Nowa kwota: " << fixed << setprecision(2) << zam->kwotaCalkowita << endl;
                cout << "Nacisnij Enter, aby wrocic." << endl;
                getline(cin, wStr);
            }
            else {
                cout << "Nieprawidlowy wybor. Nacisnij Enter, aby wrocic." << endl;
                getline(cin, wStr);
            }
        }
        else if (w == 3) {
            auto& wszystkie = const_cast<vector<Zamowienie*>&>(listaZamowien.pobierzWszystkie());
            if (wszystkie.empty()) {
                cout << "Brak zamowien. Nacisnij Enter, aby wrocic." << endl;
                string tmp; getline(cin, tmp);
                continue;
            }
            cout << "Wybierz ID zamowienia do zmiany statusu:" << endl;
            for (size_t i = 0; i < wszystkie.size(); ++i) {
                if (wszystkie[i]->status != "wydane") {
                    cout << i << ". Status: " << wszystkie[i]->status
                        << ", Kwota: " << fixed << setprecision(2) << wszystkie[i]->kwotaCalkowita << endl;
                }
            }
            string idStr;
            getline(cin, idStr);
            int id = -1;
            try { id = stoi(idStr); }
            catch (...) { id = -1; }

            if (id < 0 || id >= static_cast<int>(wszystkie.size()) || wszystkie[id]->status == "wydane") {
                cout << "Nieprawidlowe ID. Nacisnij Enter, aby wrocic." << endl;
                getline(cin, idStr);
                continue;
            }
            Zamowienie* zam = wszystkie[id];

            cout << "Nowy status:" << endl;
            cout << "1. nowe" << endl;
            cout << "2. gotowe" << endl;
            cout << "3. w trakcie dostawy" << endl;
            cout << "4. wydane" << endl;
            cout << "Wybor: ";
            string sStr;
            getline(cin, sStr);
            int s = 0;
            try { s = stoi(sStr); }
            catch (...) { s = 0; }

            switch (s) {
            case 1: zam->status = "nowe"; break;
            case 2: zam->status = "gotowe"; break;
            case 3: zam->status = "w trakcie dostawy"; break;
            case 4: zam->status = "wydane"; break;
            default:
                cout << "Nieprawidlowy wybor statusu." << endl;
                break;
            }
            cout << "Status zmieniony. Nacisnij Enter, aby wrocic." << endl;
            getline(cin, sStr);
        }
        else if (w == 4) {
            const auto& wszystkie = listaZamowien.pobierzWszystkie();
            bool jakiekolwiek = false;
            cout << "\n=== Lista Zamowien ===" << endl;
            for (size_t i = 0; i < wszystkie.size(); ++i) {
                Zamowienie* z = wszystkie[i];
                if (z->status != "wydane") {
                    jakiekolwiek = true;
                    cout << "ID " << i
                        << ": Typ: " << z->typZamowienia
                        << ", Status: " << z->status
                        << ", Kwota: " << fixed << setprecision(2) << z->kwotaCalkowita
                        << ", Data zlozenia: " << czasNaString(z->dataZamowienia) << endl;
                }
            }
            if (!jakiekolwiek) {
                cout << "Brak aktywnych zamowien do pokazania." << endl;
            }
            cout << "\nNacisnij Enter, aby wrocic." << endl;
            string tmp; getline(cin, tmp);
        }
        else if (w == 6) {
            const auto& wszystkie = listaZamowien.pobierzWszystkie();
            if (wszystkie.empty()) {
                cout << "Brak zamowien w archiwum. Nacisnij Enter, aby wrocic." << endl;
                string tmp; getline(cin, tmp);
                continue;
            }
            // Tworzymy kopię i sortujemy od najnowszych do najstarszych
            vector<Zamowienie*> kopia = wszystkie;
            sort(kopia.begin(), kopia.end(), [](Zamowienie* a, Zamowienie* b) {
                return a->dataZamowienia > b->dataZamowienia;
                });
            cout << "\n=== Archiwum Zamowien (od najnowszych) ===" << endl;
            for (size_t i = 0; i < kopia.size(); ++i) {
                Zamowienie* z = kopia[i];
                cout << "ID " << i
                    << ": Typ: " << z->typZamowienia
                    << ", Status: " << z->status
                    << ", Kwota: " << fixed << setprecision(2) << z->kwotaCalkowita
                    << ", Data zlozenia: " << czasNaString(z->dataZamowienia) << endl;
            }
            cout << "\nNacisnij Enter, aby wrocic." << endl;
            string tmp; getline(cin, tmp);
        }
        else {
            cout << "Nieprawidlowy wybor. Nacisnij Enter, aby sprobowac ponownie." << endl;
            string tmp; getline(cin, tmp);
        }
    }
}


// Widok kuchni
void widokKuchni(vector<Pracownik*>& pracownicy, ListaZamowien& listaZamowien) {
    clearScreen();
    cout << "--- Widok Kuchni ---" << endl;
    cout << "Podaj haslo: ";
    string haslo;
    getline(cin, haslo);

    Pracownik* zalogowany = nullptr;
    for (auto p : pracownicy) {
        if (p->rola == "kucharz" && p->autoryzuj(haslo)) {
            zalogowany = p;
            break;
        }
    }
    if (!zalogowany) {
        cout << "Blad logowania. Nacisnij Enter, aby wrocic do menu glownego." << endl;
        getline(cin, haslo);
        return;
    }

    while (true) {
        clearScreen();
        cout << "Zalogowano jako kucharz: " << zalogowany->imie << " " << zalogowany->nazwisko << endl;
        cout << "\n--- Menu Kuchni ---" << endl;
        cout << "1. Pokaz zamowienia do obslugi" << endl;
        cout << "2. Oznacz zamowienie jako gotowe" << endl;
        cout << "3. Wyloguj" << endl;
        cout << "Wybor: ";

        string wStr;
        getline(cin, wStr);
        int w = 0;
        try { w = stoi(wStr); }
        catch (...) { w = 0; }

        if (w == 3) {
            cout << "Wylogowano. Nacisnij Enter, aby wrocic do glownego menu." << endl;
            getline(cin, wStr);
            break;
        }

        const auto& wszystkie = listaZamowien.pobierzWszystkie();
        if (wszystkie.empty()) {
            cout << "Brak zamowien. Nacisnij Enter, aby wrocic." << endl;
            string tmp; getline(cin, tmp);
            continue;
        }

        if (w == 1) {
            cout << "\n=== Zamowienia (status != gotowe, != wydane) ===" << endl;
            bool jakiekolwiek = false;
            for (size_t i = 0; i < wszystkie.size(); ++i) {
                if (wszystkie[i]->status != "gotowe" && wszystkie[i]->status != "wydane") {
                    jakiekolwiek = true;
                    cout << "ID " << i
                        << ": Typ: " << wszystkie[i]->typZamowienia
                        << ", Status: " << wszystkie[i]->status
                        << ", Kwota: " << fixed << setprecision(2) << wszystkie[i]->kwotaCalkowita
                        << endl;
                }
            }
            if (!jakiekolwiek) {
                cout << "Brak zamowien do obslugi." << endl;
                cout << "\nNacisnij Enter, aby wrocic." << endl;
                string tmp; getline(cin, tmp);
                continue;
            }
            cout << "\nPodaj ID zamowienia, aby zobaczyc elementy (lub -1 aby wrocic): ";
            string idStr;
            getline(cin, idStr);
            int id = -1;
            try { id = stoi(idStr); }
            catch (...) { id = -1; }
            if (id < 0 || id >= static_cast<int>(wszystkie.size()) ||
                wszystkie[id]->status == "gotowe" || wszystkie[id]->status == "wydane") {
                // powrót
                continue;
            }
            const auto& elem = wszystkie[id]->pobierzElementy();
            if (elem.empty()) {
                cout << "Brak elementow w zamowieniu." << endl;
            }
            else {
                cout << "Elementy zamowienia:" << endl;
                for (size_t i = 0; i < elem.size(); ++i) {
                    cout << "- " << elem[i]->pozycjaMenu->produkt->nazwa
                        << " (" << elem[i]->pozycjaMenu->rozmiar << "), ilosc: "
                        << elem[i]->ilosc << ", cena: "
                        << fixed << setprecision(2) << elem[i]->cena << endl;
                }
            }
            cout << "\nNacisnij Enter, aby wrocic." << endl;
            string tmp; getline(cin, tmp);
        }
        else if (w == 2) {
            cout << "Podaj ID zamowienia do oznaczenia jako gotowe: ";
            string idStr;
            getline(cin, idStr);
            int id = -1;
            try { id = stoi(idStr); }
            catch (...) { id = -1; }

            if (id < 0 || id >= static_cast<int>(wszystkie.size()) || wszystkie[id]->status == "wydane") {
                cout << "Nieprawidlowe ID. Nacisnij Enter, aby wrocic." << endl;
                string tmp; getline(cin, tmp);
                continue;
            }
            if (wszystkie[id]->status == "w trakcie dostawy") {
                cout << "To zamowienie nie jest jeszcze gotowe do oznaczenia." << endl;
                cout << "Nacisnij Enter, aby wrocic." << endl;
                string tmp; getline(cin, tmp);
                continue;
            }
            // Jeśli status był „nowe” nie można od razu na „gotowe”—klient najpierw dodał elementy; 
            // ale w tej wersji pomijamy: każemy przyjąć, że kelner po dodaniu elementów zmieni status.
            wszystkie[id]->status = "gotowe";
            cout << "Zamowienie ID " << id << " oznaczone jako gotowe. Nacisnij Enter, aby wrocic." << endl;
            string tmp; getline(cin, tmp);
        }
        else {
            cout << "Nieprawidlowy wybor. Nacisnij Enter, aby sprobowac ponownie." << endl;
            string tmp; getline(cin, tmp);
        }
    }
}

// Widok kierowcy
void widokKierowcy(vector<Pracownik*>& pracownicy, ListaZamowien& listaZamowien) {
    clearScreen();
    cout << "--- Widok Kierowcy ---" << endl;
    cout << "Podaj haslo: ";
    string haslo;
    getline(cin, haslo);

    Pracownik* zalogowany = nullptr;
    for (auto p : pracownicy) {
        if (p->rola == "kierowca" && p->autoryzuj(haslo)) {
            zalogowany = p;
            break;
        }
    }
    if (!zalogowany) {
        cout << "Blad logowania. Nacisnij Enter, aby wrocic do menu glownego." << endl;
        getline(cin, haslo);
        return;
    }

    while (true) {
        clearScreen();
        cout << "Zalogowano jako kierowca: " << zalogowany->imie << " " << zalogowany->nazwisko << endl;
        cout << "\n--- Menu Kierowcy ---" << endl;
        cout << "1. Pokaz zamowienia do dostarczenia" << endl;
        cout << "2. Rozpocznij dostawę / Zakoncz dostawę" << endl;
        cout << "3. Wyloguj" << endl;
        cout << "Wybor: ";

        string wStr;
        getline(cin, wStr);
        int w = 0;
        try { w = stoi(wStr); }
        catch (...) { w = 0; }

        if (w == 3) {
            cout << "Wylogowano. Nacisnij Enter, aby wrocic do glownego menu." << endl;
            getline(cin, wStr);
            break;
        }

        const auto& wszystkie = listaZamowien.pobierzWszystkie();
        if (wszystkie.empty()) {
            cout << "Brak zamowien. Nacisnij Enter, aby wrocic." << endl;
            string tmp; getline(cin, tmp);
            continue;
        }

        if (w == 1) {
            cout << "\n=== Zamowienia (status: gotowe lub w trakcie dostawy) ===" << endl;
            bool jakiekolwiek = false;
            for (size_t i = 0; i < wszystkie.size(); ++i) {
                if ((wszystkie[i]->status == "gotowe" || wszystkie[i]->status == "w trakcie dostawy")) {
                    jakiekolwiek = true;
                    Klient* k = wszystkie[i]->klient;
                    cout << "ID " << i
                        << ": Adres: " << k->miasto << ", " << k->ulica
                        << ", Status: " << wszystkie[i]->status
                        << ", Kwota: " << fixed << setprecision(2) << wszystkie[i]->kwotaCalkowita
                        << endl;
                }
            }
            if (!jakiekolwiek) {
                cout << "Brak zamowien do dostarczenia." << endl;
            }
            cout << "\nNacisnij Enter, aby wrocic." << endl;
            string tmp; getline(cin, tmp);
        }
        else if (w == 2) {
            cout << "Podaj ID zamowienia: ";
            string idStr;
            getline(cin, idStr);
            int id = -1;
            try { id = stoi(idStr); }
            catch (...) { id = -1; }

            if (id < 0 || id >= static_cast<int>(wszystkie.size())) {
                cout << "Nieprawidlowe ID. Nacisnij Enter, aby wrocic." << endl;
                string tmp; getline(cin, tmp);
                continue;
            }
            Zamowienie* zam = wszystkie[id];
            if (zam->status == "gotowe") {
                zam->status = "w trakcie dostawy";
                cout << "Zamowienie ID " << id << " ustawione na 'w trakcie dostawy'. Nacisnij Enter, aby wrocic." << endl;
            }
            else if (zam->status == "w trakcie dostawy") {
                zam->status = "wydane";
                cout << "Zamowienie ID " << id << " ustawione na 'wydane'. Nacisnij Enter, aby wrocic." << endl;
            }
            else {
                cout << "Ten status (" << zam->status << ") nie mozna zmienic na 'w trakcie dostawy' lub 'wydane'." << endl;
                cout << "Nacisnij Enter, aby wrocic." << endl;
            }
            string tmp; getline(cin, tmp);
        }
        else {
            cout << "Nieprawidlowy wybor. Nacisnij Enter, aby sprobowac ponownie." << endl;
            string tmp; getline(cin, tmp);
        }
    }
}

// Widok szefa
void widokSzefa(vector<Pracownik*>& pracownicy, Menu& menu, ListaZamowien& listaZamowien) {
    clearScreen();
    cout << "--- Widok Szefa ---" << endl;
    cout << "Podaj haslo: ";
    string haslo;
    getline(cin, haslo);

    Pracownik* szef = nullptr;
    for (auto p : pracownicy) {
        if (p->rola == "szef" && p->autoryzuj(haslo)) {
            szef = p;
            break;
        }
    }
    if (!szef) {
        cout << "Blad logowania. Nacisnij Enter, aby wrocic do menu glownego." << endl;
        getline(cin, haslo);
        return;
    }

    while (true) {
        clearScreen();
        cout << "Zalogowano jako szef: " << szef->imie << " " << szef->nazwisko << endl;
        cout << "\n--- Menu Szefa ---" << endl;
        cout << "1. Dodaj pozycje do menu" << endl;
        cout << "2. Usun pozycje z menu" << endl;
        cout << "3. Podsumowanie miesiaca" << endl;
        cout << "4. Wyloguj" << endl;
        cout << "Wybor: ";
        string wStr;
        getline(cin, wStr);
        int w = 0;
        try { w = stoi(wStr); }
        catch (...) { w = 0; }

        if (w == 4) {
            cout << "Wylogowano. Nacisnij Enter, aby wrocic do glownego menu." << endl;
            getline(cin, wStr);
            break;
        }

        if (w == 1) {
            cout << "Podaj nazwe: "; string nazwa; getline(cin, nazwa);
            cout << "Podaj opis: "; string opis; getline(cin, opis);
            cout << "Podaj kategorie: "; string kategoria; getline(cin, kategoria);
            cout << "Podaj rozmiar: "; string rozmiar; getline(cin, rozmiar);
            cout << "Podaj cene: "; string cenaStr; getline(cin, cenaStr);
            double cena = 0.0;
            try { cena = stod(cenaStr); }
            catch (...) { cena = 0.0; }
            menu.dodajPozycje(nazwa, opis, kategoria, rozmiar, cena);
            cout << "Dodano pozycje. Nacisnij Enter, aby kontynuowac." << endl;
            getline(cin, wStr);
        }
        else if (w == 2) {
            const auto& pozycje = menu.pobierzPozycje();
            cout << "Pozycje w menu:" << endl;
            for (size_t i = 0; i < pozycje.size(); ++i) {
                cout << i << ". " << pozycje[i]->produkt->nazwa
                    << " (" << pozycje[i]->rozmiar << "), cena: "
                    << fixed << setprecision(2) << pozycje[i]->cena << endl;
            }
            cout << "Podaj numer pozycji do usuniecia: ";
            string idxStr; getline(cin, idxStr);
            int idx = -1;
            try { idx = stoi(idxStr); }
            catch (...) { idx = -1; }
            menu.usunPozycje(idx);
            cout << "Usunieto pozycje. Nacisnij Enter, aby kontynuowac." << endl;
            getline(cin, wStr);
        }
        else if (w == 3) {
            cout << "Podaj miesiac (1-12): ";
            string mStr; getline(cin, mStr);
            cout << "Podaj rok (np. 2025): ";
            string rStr; getline(cin, rStr);
            int miesiac = 0, rok = 0;
            try { miesiac = stoi(mStr); }
            catch (...) { miesiac = 0; }
            try { rok = stoi(rStr); }
            catch (...) { rok = 0; }
            auto zam = listaZamowien.pobierzWszystkie(miesiac, rok);
            double suma = 0.0;
            for (auto z : zam) suma += z->kwotaCalkowita;
            cout << "Podsumowanie za " << miesiac << "/" << rok << ": " << fixed << setprecision(2) << suma << " zl" << endl;
            cout << "Nacisnij Enter, aby kontynuowac." << endl;
            getline(cin, wStr);
        }
        else {
            cout << "Nieprawidlowy wybor. Nacisnij Enter, aby sprobowac ponownie." << endl;
            getline(cin, wStr);
        }
    }
}
