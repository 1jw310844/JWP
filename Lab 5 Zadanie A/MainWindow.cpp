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
using Klasa;

namespace Lab_5_Zadanie_A
{
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
        }
        private void btnUtworz_Click(object sender, RoutedEventArgs e)
        {
            lblBlad.Content = ""; // wyczyść etykietę błędu

            if (!double.TryParse(txtPromien.Text, out double promien))
            {
                MessageBox.Show("Nieprawidłowy format promienia!", "Błąd", MessageBoxButton.OK, MessageBoxImage.Warning);
                return;
            }

            if (!double.TryParse(txtWysokosc.Text, out double wysokosc))
            {
                MessageBox.Show("Nieprawidłowy format wysokości!", "Błąd", MessageBoxButton.OK, MessageBoxImage.Warning);
                return;
            }

            var stozek = new Stozek();

            // Metoda 1: MessageBox
            stozek.BłądDanych += PokazBladMessageBox;

            // Metoda 2: Label
            stozek.BłądDanych += PokazBladWLabelu;

            stozek.Promien = promien;
            stozek.Wysokosc = wysokosc;
        }

        private void PokazBladMessageBox(string opis)
        {
            MessageBox.Show(opis, "Błąd danych", MessageBoxButton.OK, MessageBoxImage.Error);
        }

        private void PokazBladWLabelu(string opis)
        {
            lblBlad.Content = opis;
        }
    }
}
