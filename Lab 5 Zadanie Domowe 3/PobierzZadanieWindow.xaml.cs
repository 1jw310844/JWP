using Klasy1;
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
using Klasy1;

namespace Lab_5_Zadanie_Domowe_3
{
    /// <summary>
    /// Logika interakcji dla klasy PobierzZadanieWindow.xaml
    /// </summary>
    public partial class PobierzZadanieWindow : Window
    {
        public PobierzZadanieWindow(Zadanie zadanie)
        {
            InitializeComponent();
            OpisTextBlock.Text = $"Opis: {zadanie.Opis}";
            DataTextBlock.Text = $"Dodano: {zadanie.DataWprowadzenia}";
        }
        private void Ok_Click(object sender, RoutedEventArgs e)
        {
            Close();
        }
    }
}
