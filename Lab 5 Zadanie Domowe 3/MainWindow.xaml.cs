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
using System.Collections.Generic;

using Klasy1;

namespace Lab_5_Zadanie_Domowe_3
{
    
    public partial class MainWindow : Window
    {
        private Queue<Zadanie> kolejka = new Queue<Zadanie>();
        public MainWindow()
        {
            InitializeComponent();
        }
        private void DodajZadanie_Click(object sender, RoutedEventArgs e)
        {
            var oknoDodaj = new DodajZadanieWindow();
            if (oknoDodaj.ShowDialog() == true)
            {
                var noweZadanie = new Zadanie(oknoDodaj.OpisZadania);
                kolejka.Enqueue(noweZadanie);
                MessageBox.Show("Zadanie dodane!");
            }
        }

        private void PobierzZadanie_Click(object sender, RoutedEventArgs e)
        {
            if (kolejka.Count == 0)
            {
                MessageBox.Show("Brak zadań w kolejce!");
                return;
            }

            var zadanie = kolejka.Dequeue();
            var oknoPobierz = new PobierzZadanieWindow(zadanie);
            oknoPobierz.ShowDialog();
        }
    }
}
