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

namespace Lab_5_Zadanie_Domowe
{

    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
        }

        private void btnWyswietl_Click(object sender, RoutedEventArgs e)
        {
            Samochód ferrari = new Samochód { Prędkość = 340 };
            lstLista.Items.Add("Prędkość po inicjalizacji: " + ferrari);
            ((IZwiększany)ferrari).Zmień();
            lstLista.Items.Add("Prędkość po zwiększeniu: " + ferrari);
            ((IZmniejszany)ferrari).Zmień();
            lstLista.Items.Add("Prędkość po zmniejszeniu: " + ferrari);
            ((IZwiększany)ferrari).Zmień();
            ((IZwiększany)ferrari).Zmień();
            ((IZwiększany)ferrari).Zmień();
            lstLista.Items.Add("Prędkość po zwiększeniu: " + ferrari);

            Samochód oryginalnySamochód = new Samochód{ Prędkość = 100 };
            Samochód lepszySamochód = oryginalnySamochód.PobierzLepsząWersję();

            lstLista2.Items.Add("Samochód:");
            lstLista2.Items.Add("Oryginalny: " + oryginalnySamochód);
            lstLista2.Items.Add("Poprawiony: " + lepszySamochód);

            // Student
            Student oryginalnyStudent = new Student { Imię = "Ania", Ocena = 4 };
            Student lepszyStudent = oryginalnyStudent.PobierzLepsząWersję();

            lstLista2.Items.Add("");
            lstLista2.Items.Add("Student:");
            lstLista2.Items.Add("Oryginalny: " + oryginalnyStudent);
            lstLista2.Items.Add("Poprawiony: " + lepszyStudent);
        }
    }
}
