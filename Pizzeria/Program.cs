using System;
using Pizzeria.Data;

namespace Pizzeria
{
    internal static class Program
    {
        [STAThread]
        static void Main()
        {
            var menu = DataSeeder.SeedMenu();
            Console.WriteLine("--- MENU ---");
            foreach (var item in menu.PobierzMenu())
                Console.WriteLine(item);

            var orders = DataSeeder.SeedOrders(menu);
            Console.WriteLine("--- ORDERS ---");
            foreach (var o in orders)
                Console.WriteLine(o);
        }
    }
}