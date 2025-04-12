using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Shapes;

namespace Lab_5_Zadanie_Domowe_3
{
    /// <summary>
    /// Logika interakcji dla klasy DodajZadanieWindow.xaml
    /// </summary>
    public partial class DodajZadanieWindow : Window
    {
        public string OpisZadania { get; private set; }
        public DodajZadanieWindow()
        {
            InitializeComponent();
        }
        private void Ok_Click(object sender, RoutedEventArgs e)
        {
            if (string.IsNullOrWhiteSpace(OpisTextBox.Text))
            {
                MessageBox.Show("Wpisz opis zadania.");
                return;
            }

            OpisZadania = OpisTextBox.Text;
            DialogResult = true;
            Close();
        }
    }
}
