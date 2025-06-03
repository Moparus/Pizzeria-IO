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
