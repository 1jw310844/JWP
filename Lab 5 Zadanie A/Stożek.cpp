namespace Klasa
{
    public class Stozek
    {
        public delegate void ObsługaBłędu(string opisBłędu);

        // Zdarzenie
        public event ObsługaBłędu BłądDanych;

        private double promien;
        private double wysokosc;

        public double Promien
        {
            get => promien;
            set
            {
                if (value < 0)
                {
                    BłądDanych?.Invoke("Promień nie może być ujemny!");
                }
                else
                {
                    promien = value;
                }
            }
        }

        public double Wysokosc
        {
            get => wysokosc;
            set
            {
                if (value < 0)
                {
                    BłądDanych?.Invoke("Wysokość nie może być ujemna!");
                }
                else
                {
                    wysokosc = value;
                }
            }
        }
        public Stozek() { }
    }
}
