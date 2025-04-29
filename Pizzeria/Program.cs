namespace Pizzeria
{
    internal static class Program
    {
        [STAThread]
        static void Main()
        {
            Kasa kasa = new Kasa();
            kasa.Show();
            Kuchnia kuchnia = new Kuchnia();
            kuchnia.Show();
            Dostawa dostawa = new Dostawa();
            dostawa.Show();
            Dostawca dostawca = new Dostawca();
            dostawca.Show();

            Application.Run();
        }
    }
}