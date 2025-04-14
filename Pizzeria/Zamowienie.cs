using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Pizzeria
{
    // Klasa reprezentująca pojedynczy przedmiot zamówienia – opakowanie pozycji menu wraz z ilością
    internal class PrzedmiotZamowienia
    {
        public PozycjaMenu Pozycja { get; set; }
        public int Ilosc { get; set; }

        public PrzedmiotZamowienia(PozycjaMenu pozycja, int ilosc)
        {
            if (pozycja == null)
            {
                throw new ArgumentNullException(nameof(pozycja), "Pozycja menu nie może być null.");
            }
            if (ilosc <= 0)
            {
                throw new ArgumentException("Ilość musi być większa od zera.", nameof(ilosc));
            }
            Pozycja = pozycja;
            Ilosc = ilosc;
        }
    }

    // Klasa reprezentująca zamówienie
    internal class Zamowienie
    {
        // Statyczna lista statusów zamówienia
        private static List<string> statusyZamowienia { get; } = new List<string>
        {
            "Nowe",
            "W realizacji",
            "Wysłane",
            "Zrealizowane",
            "Anulowane"
        };

        // Statyczna lista typów zamówienia
        private static List<string> typyZamowienia { get; } = new List<string>
        {
            "Na miejscu",
            "Dostawa",
            "Odbiór osobisty"
        };

        // Lista przedmiotów zamówienia
        public List<PrzedmiotZamowienia> Przedmioty { get; set; } = new List<PrzedmiotZamowienia>();

        // Nowe właściwości zamówienia
        public Klient Klient { get; set; }
        public string TypZamowienia { get; set; }
        public DateTime DataZamowienia { get; set; }
        public DateTime DataDostawy { get; set; }
        public decimal KwotaCalkowita { get; set; }
        public string Status { get; set; }

        // Konstruktor parametryczny z walidacją typów i statusów
        public Zamowienie(Klient klient, string typZamowienia, DateTime dataZamowienia, DateTime dataDostawy, string status)
        {
            Klient = klient ?? throw new ArgumentNullException(nameof(klient), "Klient nie może być null.");

            if (!typyZamowienia.Contains(typZamowienia))
            {
                throw new ArgumentException("Nieprawidłowy typ zamówienia.", nameof(typZamowienia));
            }
            TypZamowienia = typZamowienia;

            DataZamowienia = dataZamowienia;
            DataDostawy = dataDostawy;

            if (!statusyZamowienia.Contains(status))
            {
                throw new ArgumentException("Nieprawidłowy status zamówienia.", nameof(status));
            }
            Status = status;

            KwotaCalkowita = 0; // Na początku suma wynosi 0 i będzie aktualizowana przy dodawaniu przedmiotów
        }

        // Konstruktor domyślny – przydatny przy inicjalizacji i późniejszym uzupełnianiu danych
        public Zamowienie() { }

        // Metoda dodająca przedmiot do zamówienia – przy aktualizacji kwoty całkowitej
        public void DodajPrzedmiot(PozycjaMenu pozycja, int ilosc)
        {
            var przedmiot = new PrzedmiotZamowienia(pozycja, ilosc);
            Przedmioty.Add(przedmiot);
            KwotaCalkowita += pozycja.Cena * ilosc;
        }

        // Wypisanie szczegółów zamówienia
        public void WypiszZamowienie()
        {
            Console.WriteLine("Zamówienie:");
            Console.WriteLine($"Klient: {Klient.Imie} {Klient.Nazwisko}");
            Console.WriteLine($"Typ zamówienia: {TypZamowienia}");
            Console.WriteLine($"Data zamówienia: {DataZamowienia}");
            Console.WriteLine($"Data dostawy: {DataDostawy}");
            Console.WriteLine($"Status: {Status}");
            Console.WriteLine("Przedmioty zamówienia:");
            foreach (var przedmiot in Przedmioty)
            {
                Console.WriteLine($"{przedmiot.Pozycja.Produkt.Nazwa} ({przedmiot.Pozycja.Rozmiar}) - {przedmiot.Pozycja.Cena:C} x {przedmiot.Ilosc}");
            }
            Console.WriteLine($"Kwota całkowita: {KwotaCalkowita:C}");
        }
    }
}