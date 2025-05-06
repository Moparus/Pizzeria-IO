using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using static System.Windows.Forms.VisualStyles.VisualStyleElement;
using Pizzeria.Models;

namespace Pizzeria
{
    public partial class DodajZamowienieForm : Form
    {
        private List<PozycjaMenu> menu;
        public DodajZamowienieForm(List<PozycjaMenu> menu)
        {
            InitializeComponent();
            this.menu = menu;
        }

        private void DodajZamowienieForm_Load(object sender, EventArgs e)
        {
            menuListView.Items.Clear();

            foreach (var pozycja in menu)
            {
                var item = new ListViewItem(pozycja.produkt.nazwa);
                item.SubItems.Add(pozycja.produkt.opis);
                item.SubItems.Add(pozycja.rozmiar);
                item.SubItems.Add($"{pozycja.cena} PLN");

                menuListView.Items.Add(item);
            }
        }
    }
}
