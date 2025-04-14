using System.Text;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using Klasy;

namespace Kolokwium_Wesoły
{
    public partial class MainWindow : Window
    {
        private static Random random = new Random();
        public static T JedenZTrzech<T>(T a, T b, T c)
        {
            int wylosowana = random.Next(3);
            return wylosowana switch
            {
                0 => a,
                1 => b,
                _ => c
            };
        }
        public MainWindow()
        {
            InitializeComponent();
        }

        private void ButtonString_Click(object sender, RoutedEventArgs e)
        {
            string pierwszy = "Języki";
            string drugi = "Wysokiego";
            string trzeci = "Poziomu";
            string wynik = JedenZTrzech(pierwszy, drugi, trzeci);
            MessageBox.Show($"Wylosowany string: {wynik}");
        }

        private void ButtonArmata_Click(object sender, RoutedEventArgs e)
        {
            Armata a1 = new Armata(100, 3000);
            Armata a2 = new Armata(120, 4000);
            Armata a3 = new Armata(150, 5000);

            Armata losowa = JedenZTrzech(a1, a2, a3);
            
            MessageBox.Show($"Wylosowana armata:\n{losowa}");
        }
    }
    
}