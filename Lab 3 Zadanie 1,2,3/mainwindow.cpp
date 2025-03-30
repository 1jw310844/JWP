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
using Motoryzacja;

namespace Lab_3_Zadanie1
{
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
        }
        public void wyświetlPojazdy(pojazdy[] lp)
        {
            foreach(pojazdy p in lp)
            {
                lstLista.Items.Add(p);
            }
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            lstLista.Items.Clear();
            try
            {            
                pojazdy[] tablica = new pojazdy[] { new Samochód("Ferrari", "F8", 4, 320, 710, 2), new Samochód("Lamborgini", "Aventador", 4, 320, 710, 2) };
                wyświetlPojazdy(tablica);
            }
            catch(ArgumentException) 
            {
                MessageBox.Show($"Błąd!!!", "Komunikat Błędu", MessageBoxButton.OK, MessageBoxImage.Information);
            }   
        }
    }
}
