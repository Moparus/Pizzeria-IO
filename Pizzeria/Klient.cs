using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Pizzeria
{
    internal class Klient
    {
        public string Imie { get; set; }
        public decimal Nazwisko { get; set; }
        public string Miasto { get; set; }
        public decimal Ulica { get; set; }

        public Klient(string imie, decimal nazwisko, string miasto, decimal ulica)
        {
            Imie = imie;
            Nazwisko = nazwisko;
            Miasto = miasto;
            Ulica = ulica;
        }
    }
}
