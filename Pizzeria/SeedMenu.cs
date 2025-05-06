using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Collections.Generic;
using Pizzeria.Models;

namespace Pizzeria.Data
{
    public static class DataSeeder
    {
        public static Menu SeedMenu()
        {
            var menu = new Menu();
            // przykładowe produkty
            menu.DodajProdukt("Pizza Margherita", "Klasyczna pizza z mozzarellą", "Pizza");
            menu.DodajProdukt("Spaghetti Carbonara", "Makaron z boczkiem i parmezanem", "Makaron");
            menu.DodajProdukt("Sałatka Cezar", "Sałata rzymska z kurczakiem", "Sałatki");

            // przykładowe pozycje menu
            foreach (var p in menu.PobierzMenu()) ; // dummy to ensure list exists
            var pozycje = menu.PobierzMenu(); // before adding positions, retrieve produkty via reflection
            // since produkty są wewnętrzne, dodaj pozycje po dodaniu produktów
            // aktualnie nie mamy metody pobierania produktów, więc zakładamy kolejność
            var produkty = new List<Produkt>
            {
                new Produkt("Pizza Margherita", "Klasyczna pizza z mozzarellą", "Pizza"),
                new Produkt("Spaghetti Carbonara", "Makaron z boczkiem i parmezanem", "Makaron"),
                new Produkt("Sałatka Cezar", "Sałata rzymska z kurczakiem", "Sałatki")
            };

            menu = new Menu();
            foreach (var prod in produkty)
            {
                menu.DodajProdukt(prod.Nazwa, prod.Opis, prod.Kategoria);
            }
            var all = menu.PobierzMenu();
            // utworzymy pozycje dla każdego produktu
            foreach (var prod in produkty)
            {
                menu.DodajPozycjeMenu(prod.Id, "Standard", 25.0);
            }

            return menu;
        }

        public static List<Zamowienie> SeedOrders(Menu menu)
        {
            var klient1 = new Klient("Jan", "Kowalski", "Warszawa", "ul. Marszałkowska 1");
            var klient2 = new Klient("Anna", "Nowak", "Kraków", "ul. Floriańska 10");

            var zam1 = Zamowienie.DodajZamowienie("Dowóz", DateTime.Now.AddHours(1), klient1);
            var zam2 = Zamowienie.DodajZamowienie("Na miejscu", DateTime.Now.AddMinutes(30), klient2);

            var pozycje = menu.PobierzMenu();
            if (pozycje.Count >= 2)
            {
                zam1.DodajElement(pozycje[0], 2);
                zam1.DodajElement(pozycje[1], 1);
                zam2.DodajElement(pozycje[1], 3);
            }

            return new List<Zamowienie>(Zamowienie.PobierzWszystkie());
        }
    }
}
