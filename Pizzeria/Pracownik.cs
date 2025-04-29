using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Pizzeria
{
    internal class Pracownik
    {
        public static List<string> role { get; } = new List<string>
        {
            "Szef",
            "Kelner",
            "Kucharz",
            "Dostawca"
        };

        public string imie { get; set; }
        public string nazwisko { get; set; }
        public string rola { get; set; }
        public string haslo { get; set; }

        public Pracownik(string imie, string nazwisko, string rola, string haslo)
        {
            this.imie = imie;
            this.nazwisko = nazwisko;

            if (!role.Contains(rola))
            {
                throw new ArgumentException("Nieprawidłowa rola pracownika.");
            }
            this.rola = rola;
            this.haslo = haslo;
        }
    }

}
