using System;
using System.Runtime.InteropServices;
using Pizzeria.Data;

namespace Pizzeria
{
    internal static class Program
    {
        [DllImport("kernel32.dll")]
        private static extern bool AllocConsole();

        [STAThread]
        static void Main()
        {

            AllocConsole(); // otwiera konsolê
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);

            var menu = DataSeeder.SeedMenu();
            var orders = DataSeeder.SeedOrders(menu);

            Application.Run(new KasaForm(menu.PobierzMenu().ToList()));

            Console.WriteLine("--- MENU ---");
            foreach (var item in menu.PobierzMenu())
                Console.WriteLine(item);

            Console.WriteLine("--- ORDERS ---");
            foreach (var o in orders)
                Console.WriteLine(o);

            Console.ReadKey();

            // Jeœli chcesz równie¿ uruchomiæ Form1
            //Application.Run(new Form());
        }
    }
}