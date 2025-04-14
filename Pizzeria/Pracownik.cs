using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Pizzeria
{
    internal class Pracownik
    {
        public static List<string> Role { get; } = new List<string>
        {
            "Szef",
            "Kelner",
            "Kucharz",
            "Dostawca"
        };

        public string Imie { get; set; }
        public string Nazwisko { get; set; }
        public string Rola { get; set; }
        public string Haslo { get; set; }

        public Pracownik(string imie, string nazwisko, string rola, string haslo)
        {
            Imie = imie;
            Nazwisko = nazwisko;

            if (!Role.Contains(rola))
            {
                throw new ArgumentException("Nieprawidłowa rola pracownika.");
            }
            Rola = rola;
            Haslo = haslo;
        }
    }

}
