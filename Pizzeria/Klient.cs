using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Pizzeria.Models
{
    public class Klient
    {
        public string Imie { get; set; }
        public string Nazwisko { get; set; }
        public string Miasto { get; set; }
        public string Ulica { get; set; }

        public Klient(string imie, string nazwisko, string miasto, string ulica)
        {
            Imie = imie;
            Nazwisko = nazwisko;
            Miasto = miasto;
            Ulica = ulica;
        }

        public override string ToString() => $"{Imie} {Nazwisko}, {Ulica}, {Miasto}";
    }
}
