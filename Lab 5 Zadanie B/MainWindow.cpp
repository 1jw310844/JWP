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
using Generyki;

namespace Lab_5_Zadanie_B
{
    
    public partial class MainWindow : Window
    {
        Dictionary<double, Student> słownikStudentow = new Dictionary<double, Student>();
        public MainWindow()
        {
            InitializeComponent();
            
            Student s1 = new Student(310844, "Wesoły", 5.0);
            Student s2 = new Student(310811, "Szewczyk", 5.0);
            Student s3 = new Student(320144, "Pawlik", 5.0);
            Student s4 = new Student(311244, "Chorzela", 5.0);
            Student s5 = new Student(000000, "Puk", 2.0);
            Student s6 = new Student(010101, "Albrecht", 2.0);
            słownikStudentow.Add(s1.NumerAlbumu, s1);
            słownikStudentow.Add(s2.NumerAlbumu, s2);
            słownikStudentow.Add(s3.NumerAlbumu, s3);
            słownikStudentow.Add(s4.NumerAlbumu, s4);
            słownikStudentow.Add(s5.NumerAlbumu, s5);
            słownikStudentow.Add(s6.NumerAlbumu, s6);
        }

        private void btnSzukaj_Click(object sender, RoutedEventArgs e)
        {
           double index = Convert.ToDouble(txtNumer.Text); 
            if(słownikStudentow.ContainsKey(index))
            {
                Student znaleziony = słownikStudentow[index];
                MessageBox.Show($"Znaleziono: {znaleziony.Nazwisko}, ocena: {znaleziony.Ocena}");
            }
            else
            {
                MessageBox.Show($"Nie znaleziono");
            }
        }

        private void btnSprawdz_Click(object sender, RoutedEventArgs e)
        {
            string str1 = "Kuba";
            string str2 = "Adi";
            string wiekszyString = Wiekszy.ZnajdzWiekszy(str1, str2);
           
            //MessageBox.Show($"Większy string: {wiekszyString}");

            // Test dla double
            double d1 = 3.5;
            double d2 = 4.2;
            double wiekszyDouble = Wiekszy.ZnajdzWiekszy(d1, d2);
            //MessageBox.Show($"Większa liczba: {wiekszyDouble}");

            // Test dla Student (porównanie według oceny)
            Student student1 = new Student(123456, "Nowak", 4.5);
            Student student2 = new Student(654321, "Kowalski", 5.0);
            Student wiekszyStudent = Wiekszy.ZnajdzWiekszy(student1, student2);
            //MessageBox.Show($"Lepszy student: {wiekszyStudent}");
            lblWieksza.Content = "String: " + wiekszyString + "\nDouble: " + wiekszyDouble + "\nStudent: " + wiekszyStudent;
        }
    }
}
