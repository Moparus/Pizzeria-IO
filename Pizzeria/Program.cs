namespace Pizzeria
{
    internal static class Program
    {
        [STAThread]
        static void Main()
        {
            Menu menu = new Menu();

            // Kategorie
            // 0: Opakowanie
            // 1: Dostawa
            // 2: Pizza
            // 3: Makaron
            // 4: Napój
            // 5: Przystawka

            Produkt margaritka = new Produkt("Pizza Margherita", "Dobra z sosem pomidorowym i serem", "Pica");
            Produkt carbonaura = new Produkt("Carbonara", "Dobra z sosem", "Makaron");

            menu.pozycje.Add(new PozycjaMenu(margaritka, "ma³a", 20.00));
            menu.pozycje.Add(new PozycjaMenu(carbonaura, "prawie ca³a miska", 25.02));
            menu.pozycje.Add(new PozycjaMenu(margaritka, "du¿a", 23.99));

            KasaForm kasa = new KasaForm(menu.pozycje);
            kasa.Show();
            KuchniaForm kuchnia = new KuchniaForm();
            kuchnia.Show();
            DostawaForm dostawa = new DostawaForm();
            dostawa.Show();
            DostawcaForm dostawca = new DostawcaForm();
            dostawca.Show();

            Application.Run();
        }
    }
}