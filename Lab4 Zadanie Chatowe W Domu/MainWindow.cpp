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
using Pojazdy;

namespace Zadanie_z_chata_Lab_4
{
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            lstLista.Items.Clear();
            Samochod s1 = new Samochod(50.0, 120.0, 3);
            Samochod s2 = new Samochod(53.0, 110.0, 5);
            Motocykl m1 = new Motocykl(62.0, 140.0, "Trzykołowy");
            Motocykl m2 = new Motocykl(30.0, 77.0, "Dwukołowy");

            s1.model = txtModel.Text;
            s2.model = txtModel.Text;
            m1.model = txtModel2.Text;
            m2.model = txtModel2.Text;

            lstLista.Items.Add(s1);
            lstLista.Items.Add(s2);
            lstLista.Items.Add(m1);
            lstLista.Items.Add(m2);

            //Wyswietlenie informacji za pomocą funkcji w interfejsie
            IInformacje samochod = s1;
            IInformacje motocykl = m1;
            RekordPredkosci rekord = s1;
            lblDane.Content = samochod.WyswietlInformacje()+ "\n" + motocykl.WyswietlInformacje() + "\n" + rekord.JakiRekord();
        }
    }
}
