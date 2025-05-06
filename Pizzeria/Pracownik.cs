using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Pizzeria
{
    internal class Pracownik
    {
        //public static List<string> role { get; } = new List<string>
        //{
        //    "Szef",
        //    "Kelner",
        //    "Kucharz",
        //    "Dostawca"
        //};

        public string Imie { get; set; }
        public string Nazwisko { get; set; }
        public string Rola { get; set; }
        public string Haslo { get; set; }

        public Pracownik(string imie, string nazwisko, string rola, string haslo)
        {
            Imie = imie;
            Nazwisko = nazwisko;
            Rola = rola;
            Haslo = haslo;
        }

        public bool Autoryzuj(string haslo) => Haslo == haslo;

        public override string ToString() => $"{Imie} {Nazwisko} ({Rola})";
    }

}
