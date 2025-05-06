using System;
using System.Collections.Generic;
using System.Linq;
using Pizzeria;

namespace Pizzeria
{
    internal class Zamowienie
    {
        public Guid Id { get; } = Guid.NewGuid();
        public string TypZamowienia { get; set; }
        public DateTime DataZamowienia { get; set; }
        public DateTime DataDostawy { get; set; }
        public string Status { get; private set; }

        public Klient Klient { get; set; }
        public Pracownik Pracownik { get; set; }

        private readonly List<ElementZamowienia> _elementy = new List<ElementZamowienia>();
        private static readonly List<Zamowienie> WszystkieZamowienia = new List<Zamowienie>();

        public double KwotaCalkowita => _elementy.Sum(e => e.Cena);

        private Zamowienie(string typZamowienia, DateTime dataZamowienia, DateTime dataDostawy, Klient klient)
        {
            TypZamowienia = typZamowienia;
            DataZamowienia = dataZamowienia;
            DataDostawy = dataDostawy;
            Klient = klient;
            Status = "Nowe";
        }

        public static Zamowienie DodajZamowienie(string typZamowienia, DateTime dataDostawy, Klient klient)
        {
            var zam = new Zamowienie(typZamowienia, DateTime.Now, dataDostawy, klient);
            WszystkieZamowienia.Add(zam);
            return zam;
        }

        public static void EdytujZamowienie(Guid id, string typZamowienia, DateTime dataDostawy)
        {
            var zam = WszystkieZamowienia.FirstOrDefault(z => z.Id == id);
            if (zam == null) return;
            zam.TypZamowienia = typZamowienia;
            zam.DataDostawy = dataDostawy;
        }

        public static void UsunZamowienie(Guid id)
        {
            var zam = WszystkieZamowienia.FirstOrDefault(z => z.Id == id);
            if (zam != null)
                WszystkieZamowienia.Remove(zam);
        }

        public static IReadOnlyList<Zamowienie> PobierzWszystkie() => WszystkieZamowienia.AsReadOnly();

        public void DodajElement(PozycjaMenu pozycja, int ilosc)
        {
            if (ilosc <= 0) throw new ArgumentException("Ilość musi być większa niż 0");
            _elementy.Add(new ElementZamowienia(pozycja, ilosc));
        }

        public void UsunElement(Guid pozycjaId)
        {
            var el = _elementy.FirstOrDefault(e => e.Pozycja.Id == pozycjaId);
            if (el != null)
                _elementy.Remove(el);
        }

        public void ZmienStatus(string status) => Status = status;

        public override string ToString()
        {
            var items = string.Join("; ", _elementy.Select(e => e.ToString()));
            return $"Zamówienie {Id}: {TypZamowienia}, klient: {Klient}, status: {Status}, suma: {KwotaCalkowita:C}, elementy: [{items}]";
        }
    }
}