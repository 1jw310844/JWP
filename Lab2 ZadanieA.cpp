using System;
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

namespace Lab_3_Zadanie_A
{
    public enum Figury
    {
        Kwadrat,
        Kolo,
        Trojkat,
        Prostokat
    }
    public partial class MainWindow : Window
    {
        Figury[] tab = new Figury[] { Figury.Kwadrat, Figury.Kolo, Figury.Kwadrat, Figury.Trojkat, Figury.Prostokat, Figury.Kwadrat, Figury.Kolo };
        public MainWindow()
        {
            InitializeComponent();
        }
        Random random = new Random();
        private void btnLosuj_Click(object sender, RoutedEventArgs e)
        {
            Figury wylosowanaFigura = tab[random.Next(tab.Length)];
            MessageBox.Show($"Wylosowano: {wylosowanaFigura}", "Wynik losowania", MessageBoxButton.OK, MessageBoxImage.Information);
        }
    }
}
