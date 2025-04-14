namespace Pizzeria
{
    internal static class Program
    {
        /// <summary>
        ///  The main entry point for the application.
        /// </summary>
        [STAThread]
        static void Main()
        {
            // Tworzymy przyk�adowych klient�w
            Klient klient1 = new Klient("Jan", "Kowalski", "Warszawa", "Marsza�kowska 10");

            // Tworzymy produkty
            Produkt pizzaMargarita = new Produkt("Pizza Margarita", "Klasyczna pizza z sosem pomidorowym i serem", "Pizza");
            Produkt cola = new Produkt("Cola", "Nap�j gazowany", "Nap�j");
            Produkt makaronCarbonara = new Produkt("Makaron Carbonara", "Makaron z sosem �mietanowym i boczkiem", "Makaron");

            // Tworzymy pozycje menu
            PozycjaMenu pozycjaPizza = new PozycjaMenu(pizzaMargarita, "Du�a", 25.00m);
            PozycjaMenu pozycjaCola = new PozycjaMenu(cola, "Standard", 5.00m);
            PozycjaMenu pozycjaMakaron = new PozycjaMenu(makaronCarbonara, "Standard", 18.00m);

            // Tworzymy menu i dodajemy pozycje
            Menu menu = new Menu();
            menu.DodajPozycje(pozycjaPizza);
            menu.DodajPozycje(pozycjaCola);
            menu.DodajPozycje(pozycjaMakaron);

            menu.WypiszMenu();

            // Tworzymy zam�wienie dla klienta
            Zamowienie zamowienie = new Zamowienie(
                klient1,
                "Dostawa",
                DateTime.Now,                            // Data zam�wienia: teraz
                DateTime.Now.AddHours(1),                // Przewidywana data dostawy: za godzin�
                "Nowe"                                   // Pocz�tkowy status zam�wienia
            );

            // Dodajemy przedmioty do zam�wienia
            zamowienie.DodajPrzedmiot(pozycjaPizza, 1);
            zamowienie.DodajPrzedmiot(pozycjaCola, 2);
            zamowienie.DodajPrzedmiot(pozycjaMakaron, 1);

            // Wypisanie szczeg��w zam�wienia
            Console.WriteLine("\nSzczeg�y zam�wienia:");
            zamowienie.WypiszZamowienie();

            Console.WriteLine("\nNaci�nij dowolny klawisz aby zako�czy�.");
            Console.ReadKey();
        }
    }
}