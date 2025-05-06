using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Pizzeria
{
    public class Menu
    {
        public List<PozycjaMenu> pozycje { get; set; } = new List<PozycjaMenu>();
        public List<Produkt> produkty { get; set; } = new List<Produkt>();
    }

    public class PozycjaMenu
    {
        public Produkt produkt { get; set; }
        public string rozmiar { get; set; }
        public double cena { get; set; }
    
        public PozycjaMenu(Produkt produkt, string rozmiar, double cena)
        {
            this.produkt = produkt;
            this.rozmiar = rozmiar;
            this.cena = cena;
        }
    }

    public class Produkt
    {
        //private static List<string> kategorie { get; set; } = new List<string>
        //{
        //    "Opakowanie",
        //    "Dostawa",
        //    "Pizza",
        //    "Makaron",
        //    "Napój",
        //    "Przystawka"
        //};

        public string nazwa;
        public string opis;
        public string kategoria;

        public Produkt(string nazwa, string opis, string kategoria)
        {
            this.nazwa = nazwa;
            this.opis = opis;
            this.kategoria = kategoria;
        }
    }
    
}
