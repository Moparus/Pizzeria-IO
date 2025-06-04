#include <iostream>
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

}

// Widok kuchni
void widokKuchni(vector<Pracownik*>& pracownicy, ListaZamowien& listaZamowien) {

}

// Widok kierowcy
void widokKierowcy(vector<Pracownik*>& pracownicy, ListaZamowien& listaZamowien) {

}

// Widok szefa
void widokSzefa(vector<Pracownik*>& pracownicy, Menu& menu, ListaZamowien& listaZamowien) {

}
