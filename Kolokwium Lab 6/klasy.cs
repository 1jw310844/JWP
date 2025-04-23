namespace Klasy
{
    public class Kula
    {
        private double promien;
        public double Promien
        {
            get { return promien; }
            private set { promien = value; }
        }
        private string material;
        public string Material 
        {
            get { return material; }
            set { material = value; } 
        }

        public Kula(double pr, string mat)
        {
            Promien = pr;
            Material = mat;
        }

        public void ZmienPromien(Func<double, double> zmiana)
        {
            Promien = zmiana(Promien);
        }

        public double Masa()
        {
            double gestosc = Material.ToLower() switch
            {
                "stal" => 7850,
                "drewno" => 700,
                _ => 1000
            };

            double objetosc = (4.0 / 3.0) * Math.PI * Math.Pow(Promien, 3);
            double wynik = objetosc * gestosc;
            return wynik;
        }

        public override string ToString()
        {
            return $"Kula z materiału: {Material}, promień: {Promien:F2}, masa: {Masa():F2} kg";
        }
    }
}
