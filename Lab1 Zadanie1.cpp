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

namespace Lab1_Wesoły
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
        }

        private void TextBox_TextChanged(object sender, TextChangedEventArgs e)
        {

        }

        private void btnOblicz_Click(object sender, RoutedEventArgs e)
        {
            double r, h, v, p;
            try
            {
                r = Convert.ToDouble(txtPromien.Text);
                h = Convert.ToDouble(txtWysokosc.Text);
                if (r < 0 || h < 0)
                {
                    MessageBox.Show("Bledne dane");
                }
                switch (cbxTypBryly.SelectedIndex)
                {
                    case 0: v = Math.PI * Math.Pow(r, 2) * h;
                        p = 2 * Math.PI * r * h + 2 * Math.PI * Math.Pow(r, 2);
                        break;
                    case 1: v = 1.0/3.0*Math.PI * Math.Pow(r, 2) * h;
                        p = Math.PI * Math.Pow(r, 2) + Math.PI * r * h;
                        break;
                    case 2: v = 4.0/3.0*Math.PI * Math.Pow(r, 2);
                        p = 4 * Math.PI * Math.Pow(r, 2);
                        break;
                    default: throw new NotImplementedException();
                }    
                if(chkObliczObjetosc.IsChecked == true)
                {
                    lblObjetosc.Content = $"Objetość wynosi: {v:F2}";
                }
                if (chkObliczPole.IsChecked == true)
                {
                    lblPole.Content = $"Pole wynosi: {p:F2}";
                }
            }
            catch
            {
                MessageBox.Show("Zły format danych");
            }            
        }

        private void cbxTypBryly_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            if(cbxTypBryly.SelectedIndex == 2)
            txtWysokosc.Visibility = Visibility.Hidden;
            else
            {
                txtWysokosc.Visibility = Visibility.Visible;
            }
        }

        private void btnZamknij_Click_1(object sender, RoutedEventArgs e)
        {
            if(MessageBox.Show("Czy jesteś pewien?", "Pytanie", MessageBoxButton.YesNo) == MessageBoxResult.Yes)
            {
                this.Close();
            }
        }

    }
}
