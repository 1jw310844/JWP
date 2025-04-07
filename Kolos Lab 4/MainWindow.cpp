using System.Security.Cryptography.X509Certificates;
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

namespace Kolokwium_Wesoły_Lab4
{
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
        }

        private void btnUtworz_Click(object sender, RoutedEventArgs e)
        {
            double[] tablica = new double[] { 1.0, 2.0, 3.0, 4.0, 5.5, 6.6, 7.7 };

            Okno okno = new Okno
            {
                Tablica = tablica
            };
            okno.ShowDialog();
        }
    }
}
