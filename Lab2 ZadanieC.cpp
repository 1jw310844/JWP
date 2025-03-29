using System.Linq.Expressions;
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

namespace Lab_2_Zadanie_C
{
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
        }
        public static double Suma(params double[] liczby)
        {
            int ilość = liczby.Length;
            double suma = 0;
            for (int i = 0; i < liczby.Length; i++)
            {
                suma += liczby[i];
            }
            return suma;
        }
        public static double ObwódProstokąta(params double[] liczby)
        {
            double obwod = obwod = Suma(liczby);
            return obwod;
        }

        private void btnOblicz_Click(object sender, RoutedEventArgs e)
        {
            try
            {
                    double oknoA = Convert.ToDouble(txtA.Text);
                    double oknoB = Convert.ToDouble(txtB.Text);
                    double oknoC = Convert.ToDouble(txtC.Text);
                    double oknoD = Convert.ToDouble(txtD.Text);

                    if (oknoA <= 0)
                    {
                        throw new ArgumentException("Pole A musi zawierać liczbę większą od zera!");
                    }
                    if (oknoB <= 0)
                    {
                        throw new ArgumentException("Pole B musi zawierać liczbę większą od zera!");
                    }
                    if (oknoC <= 0)
                    {
                        throw new ArgumentException("Pole C musi zawierać liczbę większą od zera!");
                    }
                    if (oknoD <= 0)
                    {
                        throw new ArgumentException("Pole D musi zawierać liczbę większą od zera!");
                    }

                    double obwod = ObwódProstokąta(oknoA, oknoB, oknoC, oknoD);
                    MessageBox.Show($"Obwód to: {obwod}", "Wynik polecenia", MessageBoxButton.OK, MessageBoxImage.Information);
                
            }
            catch (ArgumentException ex)
            {
                MessageBox.Show(ex.Message, "Błąd", MessageBoxButton.OK, MessageBoxImage.Warning);
            }
        }
    }
}
