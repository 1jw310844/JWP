using System;
using System.Windows;
using System.Windows.Controls;
using System.Text;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Shapes;
using Geometria;

namespace Lab_3_Zadanie
{
    public static class ListBoxExtensions
    {
        public static void Dodaj(this ListBox listBox, IWyswietl element)
        {
            listBox.Items.Add(element.PobierzIdentyfikator());
        }
    }
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
        }

        private void btnPokaż_Click(object sender, RoutedEventArgs e)
        {
            List<IWyswietl> obiekty = new List<IWyswietl>();
          
            Stożek s1 = new Stożek(2, 3, 2, 2);
            Stożek s2 = new Stożek(5, 7, 1, 1);

            Kula k1 = new Kula(2, 3, 2);
            Kula k2 = new Kula(2, 2, 3);
            lbNapis.Content = $"Kula 1: {k1.ToString()}";
            lbNapis2.Content = $"Kula 2: {k2.ToString()}";

            // Operator + (suma objętości kul)
            Kula k3 = k1 + k2;
            lbNapis3.Content = $"Kula po dodaniu: {k3.ToString()}";

            // Operator - (różnica objętości kul)
            Kula k4 = k1 - k2;
            lbNapis4.Content = $"Kula po odjęciu: {k4.ToString()}";

            // Operator ++ (zwiększanie objętości kuli)
            Kula k5 = ++k1;
            lbNapis5.Content = $"Kula po zwiększeniu objętości: {k5.ToString()}";

            Student student1 = new Student("Jakub", "Wesoły");
            Student student2 = new Student("Adrian", "Szewczyk");
            Student student3 = new Student("Bartłomiej", "Pawlik");
            Student student4 = new Student("Oskar", "Chorzela");
            Student student5 = new Student("Artur", "Albrecht");

            obiekty.Add(k1);
            obiekty.Add(s1);
            obiekty.Add(k2);
            obiekty.Add(s2);
            obiekty.Add(student1);
            obiekty.Add(student2);
            obiekty.Add(student3);
            obiekty.Add(student4);
            obiekty.Add(student5);

            obiekty.Sort();
            lbLista.Items.Clear(); 

            foreach (var obiekt in obiekty)
            {
                lbLista.Dodaj(obiekt);
            }
        }
    }
}
