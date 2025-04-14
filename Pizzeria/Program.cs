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
            // Tworzymy przyk³adowych klientów
            Klient klient1 = new Klient("Jan", "Kowalski", "Warszawa", "Marsza³kowska 10");

            // Tworzymy produkty
            Produkt pizzaMargarita = new Produkt("Pizza Margarita", "Klasyczna pizza z sosem pomidorowym i serem", "Pizza");
            Produkt cola = new Produkt("Cola", "Napój gazowany", "Napój");
            Produkt makaronCarbonara = new Produkt("Makaron Carbonara", "Makaron z sosem œmietanowym i boczkiem", "Makaron");

            // Tworzymy pozycje menu
            PozycjaMenu pozycjaPizza = new PozycjaMenu(pizzaMargarita, "Du¿a", 25.00m);
            PozycjaMenu pozycjaCola = new PozycjaMenu(cola, "Standard", 5.00m);
            PozycjaMenu pozycjaMakaron = new PozycjaMenu(makaronCarbonara, "Standard", 18.00m);

            // Tworzymy menu i dodajemy pozycje
            Menu menu = new Menu();
            menu.DodajPozycje(pozycjaPizza);
            menu.DodajPozycje(pozycjaCola);
            menu.DodajPozycje(pozycjaMakaron);

            menu.WypiszMenu();

            // Tworzymy zamówienie dla klienta
            Zamowienie zamowienie = new Zamowienie(
                klient1,
                "Dostawa",
                DateTime.Now,                            // Data zamówienia: teraz
                DateTime.Now.AddHours(1),                // Przewidywana data dostawy: za godzinê
                "Nowe"                                   // Pocz¹tkowy status zamówienia
            );

            // Dodajemy przedmioty do zamówienia
            zamowienie.DodajPrzedmiot(pozycjaPizza, 1);
            zamowienie.DodajPrzedmiot(pozycjaCola, 2);
            zamowienie.DodajPrzedmiot(pozycjaMakaron, 1);

            // Wypisanie szczegó³ów zamówienia
            Console.WriteLine("\nSzczegó³y zamówienia:");
            zamowienie.WypiszZamowienie();

            Console.WriteLine("\nNaciœnij dowolny klawisz aby zakoñczyæ.");
            Console.ReadKey();
        }
    }
}