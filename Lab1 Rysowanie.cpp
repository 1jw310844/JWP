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

namespace Rysowanie_Lab1
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
        void rysujLinie(int x1, int x2, int y1, int y2, SolidColorBrush pedzel, int gru)
        {
            var myLine = new Line();
            myLine.Stroke = pedzel;
            myLine.X1 = x1;
            myLine.X2 = x2;
            myLine.Y1 = y1;
            myLine.Y2 = y2;

            myLine.StrokeThickness = gru;
            cvPlotno.Children.Add(myLine);
        }
        void czyscRysunek()
        {
            cvPlotno.Children.Clear();
        }
        void rysujKrzyz(int d)
        {
            rysujLinie(0, 100, 150, 150, System.Windows.Media.Brushes.Red, 2);
            rysujLinie(9, 100, 150, 150, System.Windows.Media.Brushes.Red, 2);
            rysujLinie(0, 100, 150, 150, System.Windows.Media.Brushes.Red, 2);
            rysujLinie(0, 100, 150, 150, System.Windows.Media.Brushes.Red, 2);
            rysujLinie(0, 100, 150, 150, System.Windows.Media.Brushes.Red, 2);
            rysujLinie(0, 100, 150, 150, System.Windows.Media.Brushes.Red, 2);
        }
        void rysujElipse(int wpG, int wpP, int wys, int szer, SolidColorBrush pedzel)
        {
            Canvas canv = new Canvas();
            Content = canv;

            Ellipse elips = new Ellipse();
            elips.Stroke = SystemColors.WindowTextBrush;
            elips.Width = szer;
            elips.Height = wys;
            cvPlotno.Children.Add(elips);
            Canvas.SetLeft(elips, wpP);
            Canvas.SetTop(elips, wpG);

            for (int i = 0; i < 72; i++)
            {
                Line line = new Line();
                line.Stroke = SystemColors.WindowTextBrush;
                line.X1 = 150;
                line.Y1 = 150;
                line.X2 = 250;
                line.Y2 = 150;
                line.RenderTransform = new RotateTransform(5 * i, 150, 150);
                cvPlotno.Children.Add(line);
            }
        }

        private void btnRysuj_Click(object sender, RoutedEventArgs e)
        {
            czyscRysunek();
            rysujLinie(0, 299, 150, 150, System.Windows.Media.Brushes.Red, 2);
            rysujLinie(150, 150, 150, 300, System.Windows.Media.Brushes.Green, 5);
        }

        private void btnRysuj2_Click(object sender, RoutedEventArgs e)
        {
            czyscRysunek();
            rysujKrzyz(100);
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            czyscRysunek();
            rysujElipse(100, 100, 100, 100, System.Windows.Media.Brushes.Red);
        }
    }
}
