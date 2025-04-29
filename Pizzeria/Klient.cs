using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Pizzeria
{
    internal class Klient
    {
        public string imie { get; set; }
        public string nazwisko { get; set; }
        public string miasto { get; set; }
        public string ulica { get; set; }

        public Klient(string imie, string nazwisko, string miasto, string ulica)
        {
            this.imie = imie;
            this.nazwisko = nazwisko;
            this.miasto = miasto;
            this.ulica = ulica;
        }
    }
}
