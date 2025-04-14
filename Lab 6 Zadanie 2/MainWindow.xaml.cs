using KlasyZadanie2;
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

namespace Lab_6_Zadanie_2
{
    public partial class MainWindow : Window
    {
        List<Towar> towary = new List<Towar>();

        public MainWindow()
        {
            InitializeComponent();

            // Tworzenie danych
            towary = new List<Towar>
            {
                new Towar("Mleko", 3.50, 10, Kategoria.dostępny),
                new Towar("Chleb", 2.00, 15, Kategoria.dostępny),
                new Towar("Masło", 7.50, 3, Kategoria.dostępny),
                new Towar("Ser", 10.00, 6, Kategoria.dostępny),
                new Towar("Czekolada", 5.00, 2, Kategoria.niedostępny),
                new Towar("Herbata", 6.00, 9, Kategoria.dostępny),
                new Towar("Kawa", 18.00, 4, Kategoria.niedostępny),
                new Towar("Cukier", 4.00, 7, Kategoria.dostępny),
                new Towar("Mąka", 3.00, 12, Kategoria.dostępny),
                new Towar("Sok", 6.50, 5, Kategoria.niedostępny)
            };
        }

        // 1. Towary z ilością > 5, posortowane malejąco wg ilości
        private void Btn1_Click(object sender, RoutedEventArgs e)
        {
            var wynik = towary
                .Where(t => t.ilość > 5)
                .OrderByDescending(t => t.ilość);

            outputBox.ItemsSource = wynik.Select(t => t.ToString());
        }

        // 2. Liczba towarów w wybranej kategorii (tu: dostępny)
        private void Btn2_Click(object sender, RoutedEventArgs e)
        {
            var liczba = towary.Count(t => t.kategoria == Kategoria.dostępny);
            outputBox.ItemsSource = new List<string> { $"Liczba towarów dostępnych: {liczba}" };
        }

        // 3. Nazwy i ceny towarów droższych niż średnia
        private void Btn3_Click(object sender, RoutedEventArgs e)
        {
            double srednia = towary.Average(t => t.cena);
            var wynik = towary
                .Where(t => t.cena > srednia)
                .Select(t => $"{t.nazwa} - {t.cena} zł");

            outputBox.ItemsSource = wynik.ToList();
        }

        // 4. Średnia cena i ilość w każdej kategorii
        private void Btn4_Click(object sender, RoutedEventArgs e)
        {
            var grupy = towary
                .GroupBy(t => t.kategoria)
                .Select(g => $"{g.Key}: Ilość = {g.Sum(t => t.ilość)}, Średnia cena = {g.Average(t => t.cena):0.00} zł");

            outputBox.ItemsSource = grupy.ToList();
        }

        // 5. Najdroższy towar
        private void Btn5_Click(object sender, RoutedEventArgs e)
        {
            var max = towary.OrderByDescending(t => t.cena).FirstOrDefault();
            if (max != null)
                outputBox.ItemsSource = new List<string> { $"Najdroższy: {max.nazwa}, Cena: {max.cena} zł" };
        }
    }
}