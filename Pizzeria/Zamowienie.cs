using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Pizzeria
{
    // Klasa reprezentująca pojedynczy przedmiot zamówienia – opakowanie pozycji menu wraz z ilością
    internal class ElementZamowienia
    {
        public PozycjaMenu pozycja { get; set; }
        public int ilosc { get; set; }
        public double cena { get; set; }

        public ElementZamowienia(PozycjaMenu pozycja, int ilosc)
        {
            if (pozycja == null)
            {
                throw new ArgumentNullException(nameof(pozycja), "Pozycja menu nie może być null.");
            }
            if (ilosc <= 0)
            {
                throw new ArgumentException("Ilość musi być większa od zera.", nameof(ilosc));
            }
            this.pozycja = pozycja;
            this.ilosc = ilosc;
            this.cena = ilosc * pozycja.cena;
        }
    }

    // Klasa reprezentująca zamówienie
    internal class Zamowienie
    {
        // Statyczna lista statusów zamówienia
        //private static List<string> statusyZamowienia { get; } = new List<string>
        //{
        //    "Nowe",
        //    "W realizacji",
        //    "Wysłane",
        //    "Zrealizowane",
        //    "Anulowane"
        //};

        // Statyczna lista typów zamówienia
        //private static List<string> typyZamowienia { get; } = new List<string>
        //{
        //    "Na miejscu",
        //    "Dostawa",
        //    "Odbiór osobisty"
        //};

        // Lista przedmiotów zamówienia
        public List<ElementZamowienia> przedmioty { get; set; } = new List<ElementZamowienia>();

        // Nowe właściwości zamówienia
        public Klient klient { get; set; }
        public string typZamowienia { get; set; }
        public DateTime dataZamowienia { get; set; }
        public DateTime dataDostawy { get; set; }
        public double kwotaCalkowita { get; set; }
        public string status { get; set; }
        public Pracownik pracownik { get; set; }

        // Konstruktor parametryczny z walidacją typów i statusów
        public Zamowienie(Klient klient, string typZamowienia, DateTime dataZamowienia, DateTime dataDostawy, string status)
        {
            this.klient = klient ?? throw new ArgumentNullException(nameof(klient), "Klient nie może być null.");

            //if (!typyZamowienia.Contains(typZamowienia))
            //{
            //    throw new ArgumentException("Nieprawidłowy typ zamówienia.", nameof(typZamowienia));
            //}
            this.typZamowienia = typZamowienia;

            this.dataZamowienia = dataZamowienia;
            this.dataDostawy = dataDostawy;

            //if (!statusyZamowienia.Contains(status))
            //{
            //    throw new ArgumentException("Nieprawidłowy status zamówienia.", nameof(status));
            //}
            this.status = status;

            this.kwotaCalkowita = 0; // Na początku suma wynosi 0 i będzie aktualizowana przy dodawaniu przedmiotów
            this.pracownik = null;
        }

        // Konstruktor domyślny – przydatny przy inicjalizacji i późniejszym uzupełnianiu danych
        public Zamowienie() { }

        // Metoda dodająca przedmiot do zamówienia – przy aktualizacji kwoty całkowitej
        public void DodajPrzedmiot(PozycjaMenu pozycja, int ilosc)
        {
            var przedmiot = new ElementZamowienia(pozycja, ilosc);
            this.przedmioty.Add(przedmiot);
            this.kwotaCalkowita += przedmiot.cena;
        }

        // Wypisanie szczegółów zamówienia
        public void WypiszZamowienie()
        {
            Console.WriteLine("Zamówienie:");
            Console.WriteLine($"Klient: {klient.imie} {klient.nazwisko}");
            Console.WriteLine($"Typ zamówienia: {typZamowienia}");
            Console.WriteLine($"Data zamówienia: {dataZamowienia}");
            Console.WriteLine($"Data dostawy: {dataDostawy}");
            Console.WriteLine($"Status: {status}");
            Console.WriteLine("Przedmioty zamówienia:");
            foreach (var przedmiot in przedmioty)
            {
                Console.WriteLine($"{przedmiot.pozycja.produkt.nazwa} ({przedmiot.pozycja.rozmiar}) - {przedmiot.pozycja.cena:C} x {przedmiot.ilosc}");
            }
            Console.WriteLine($"Kwota całkowita: {kwotaCalkowita:C}");
        }
    }
}