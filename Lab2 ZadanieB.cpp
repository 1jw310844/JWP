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

namespace Lab_2_Zadanie_B
{
   
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
        }
        public static void Policz(out double średnia, out int ilość, params int[] liczby)
        {
            ilość = liczby.Length;
            int suma = 0;
            for (int i = 0; i < liczby.Length; i++)
            {
                suma += liczby[i];
            }
            średnia = suma / ilość;
        }
        private void btnPolicz_Click(object sender, RoutedEventArgs e)
        {
            Policz(out double średnia, out int ilość, 1, 2, 3, 4, 5, 6, 7);
            MessageBox.Show($"Średnia to: {średnia}", "Wynik polecenia", MessageBoxButton.OK, MessageBoxImage.Information);
        }

        
    }
}
