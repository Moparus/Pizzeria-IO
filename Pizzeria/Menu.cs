using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Pizzeria
{
    internal class Menu
    {
        public List<PozycjaMenu> Pozycje { get; set; } = new List<PozycjaMenu>();
    }

    internal class PozycjaMenu
    {
        public Produkt Produkt { get; set; }
        public string Rozmiar { get; set; }
        public decimal Cena { get; set; }
    }

    internal class Produkt
    {
        private static List<string> kategorie { get; set; } = new List<string>
        {
            "Opakowanie",
            "Dostawa",
            "Pizza",
            "Makaron",
            "Napój",
            "Przystawka"
        };

        public string Nazwa;
        public string Opis;
        public string Kategoria_id;

        public Produkt(string nazwa, string opis, string kategoria_id)
        {
            this.Nazwa = nazwa;
            this.Opis = opis;
            this.Kategoria_id = kategoria_id;
        }
    }
    
}
