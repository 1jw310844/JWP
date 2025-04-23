using System.IO;
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

/*
 * Na oknie głównym umieścić przycisk Melduj, którego naciśnięcie będzie powodować dopisanie do
pliku tekstowego rejestr.txt w kolejnej linii daty i naciśnięcia przycisku. Zadbać o to, żeby w czasie
pracy programu do pliku był dostęp z innych programów.

*/

namespace Laboratorium_7_Zadanie_A
{
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
            btnMelduj.Click += BtnMelduj_Click;
        }

        private void BtnMelduj_Click(object sender, RoutedEventArgs e)
        {
            string filePath = @"C:\Users\Student\Desktop\Jakub Wesoły\rejestr.txt";
            string logEntry = DateTime.Now.ToShortDateString();

            using (FileStream fs = new FileStream(filePath, FileMode.Append, FileAccess.Write, FileShare.ReadWrite))
            using (StreamWriter writer = new StreamWriter(fs))
            {
                writer.WriteLine(logEntry);
            }
        }
    }
}