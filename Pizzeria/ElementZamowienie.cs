using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Pizzeria
{
    public class ElementZamowienia
    {
        public PozycjaMenu Pozycja { get; set; }
        public int Ilosc { get; set; }
        public double Cena => Pozycja.Cena * Ilosc;

        public ElementZamowienia(PozycjaMenu pozycja, int ilosc)
        {
            Pozycja = pozycja;
            Ilosc = ilosc;
        }

        public override string ToString() => $"{Pozycja.Produkt.Nazwa} x{Ilosc} = {Cena:C}";
    }
}
