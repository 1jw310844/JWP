namespace Klasy
{
    public class Armata
    {
        private double kaliber;
        private double masa;
        public double Kaliber
        {
            get { return kaliber; }
            set { kaliber = value; }
        }
        public double Masa
        {
            get { return masa; }
            set { masa = value; }
        }

        public override string ToString()
        {
            return $"Kaliber: {Kaliber}, Masa: {Masa} kg";
        }
        public Armata(double k, double m)
        {
            masa = m;
            kaliber = k;
        }
    }
}
