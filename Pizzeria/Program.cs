namespace Pizzeria
{
    internal static class Program
    {
        [STAThread]
        static void Main()
        {
            List<PozycjaMenu> Menu = new List<PozycjaMenu>();

            // Kategorie
            // 0: Opakowanie
            // 1: Dostawa
            // 2: Pizza
            // 3: Makaron
            // 4: Napój
            // 5: Przystawka

            Produkt margaritka = new Produkt("Pizza Margherita", "Dobra z sosem pomidorowym i serem", 2);
            Produkt carbonaura = new Produkt("Carbonara", "Dobra z sosem", 3);

            Menu.Add(new PozycjaMenu(margaritka, "ma³a", 20.00m));
            Menu.Add(new PozycjaMenu(carbonaura, "prawie ca³a miska", 25.02m));
            Menu.Add(new PozycjaMenu(margaritka, "du¿a", 23.99m));

            KasaForm kasa = new KasaForm(Menu);
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