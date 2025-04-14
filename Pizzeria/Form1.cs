namespace Pizzeria
{
    public partial class Logowanie : Form
    {
        Dictionary<string, string> uzytkownicy = new Dictionary<string, string>();
        public Logowanie()
        {
            InitializeComponent();

            // Dodajemy dane
            uzytkownicy["1"] = "haslo123";
            uzytkownicy["2"] = "tajnehaslo";
            uzytkownicy["3"] = "admin123";
            uzytkownicy["4"] = "admin123";
        }
    }
}
