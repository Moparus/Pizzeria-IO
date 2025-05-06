using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Pizzeria.Models
{
    public class Produkt
    {
        public Guid Id { get; } = Guid.NewGuid();
        public string Nazwa { get; set; }
        public string Opis { get; set; }
        public string Kategoria { get; set; }

        public Produkt(string nazwa, string opis, string kategoria)
        {
            Nazwa = nazwa;
            Opis = opis;
            Kategoria = kategoria;
        }

        public override string ToString() => $"[{Nazwa}] {Opis} ({Kategoria})";
    }

    public class PozycjaMenu
    {
        public Guid Id { get; } = Guid.NewGuid();
        public Produkt Produkt { get; set; }
        public string Rozmiar { get; set; }
        public double Cena { get; set; }

        public PozycjaMenu(Produkt produkt, string rozmiar, double cena)
        {
            Produkt = produkt;
            Rozmiar = rozmiar;
            Cena = cena;
        }

        public override string ToString() => $"{Produkt.Nazwa} ({Rozmiar}) - {Cena:C}";
    }

    public class Menu
    {
        private readonly List<Produkt> _produkty = new List<Produkt>();
        private readonly List<PozycjaMenu> _pozycje = new List<PozycjaMenu>();

        public void DodajProdukt(string nazwa, string opis, string kategoria)
        {
            var produkt = new Produkt(nazwa, opis, kategoria);
            _produkty.Add(produkt);
        }

        public void EdytujProdukt(Guid produktId, string nazwa, string opis, string kategoria)
        {
            var prod = _produkty.FirstOrDefault(p => p.Id == produktId);
            if (prod == null) return;
            prod.Nazwa = nazwa;
            prod.Opis = opis;
            prod.Kategoria = kategoria;
        }

        public void UsunProdukt(Guid produktId)
        {
            var prod = _produkty.FirstOrDefault(p => p.Id == produktId);
            if (prod != null)
                _produkty.Remove(prod);
        }

        public void DodajPozycjeMenu(Guid produktId, string rozmiar, double cena)
        {
            var prod = _produkty.FirstOrDefault(p => p.Id == produktId);
            if (prod == null) return;
            var pozycja = new PozycjaMenu(prod, rozmiar, cena);
            _pozycje.Add(pozycja);
        }

        public void EdytujPozycjeMenu(Guid pozycjaId, string rozmiar, double cena)
        {
            var p = _pozycje.FirstOrDefault(x => x.Id == pozycjaId);
            if (p == null) return;
            p.Rozmiar = rozmiar;
            p.Cena = cena;
        }

        public void UsunPozycjeMenu(Guid pozycjaId)
        {
            var p = _pozycje.FirstOrDefault(x => x.Id == pozycjaId);
            if (p != null)
                _pozycje.Remove(p);
        }

        public IReadOnlyList<PozycjaMenu> PobierzMenu() => _pozycje.AsReadOnly();
    }

}
