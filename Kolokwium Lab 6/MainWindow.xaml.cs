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
/// Grupa A


namespace Kolokwium_6_Wesoły
{
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            Kula kula1 = new Kula(1, "stal");
            Kula kula2 = new Kula(1, "drewno");

            kula1.ZmienPromien(p => p + 2);
            kula2.ZmienPromien(p => p * 3);

            lstLista.Items.Clear();
            lstLista.Items.Add(kula1.ToString());
            lstLista.Items.Add(kula2.ToString());
        }
    }
    
}