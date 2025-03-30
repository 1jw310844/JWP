namespace Motoryzacja
{
    public class pojazdy
    {
        public int lp { get; }
        private static int liczbaPojazdów; 
        static pojazdy()
        {
            liczbaPojazdów = 0;
        }

        public string nazwa { get; set; }
        private int liczbaKół;
        public int LiczbaKół
        {
            get { return this.liczbaKół; }
            set { 
                if(value>0)
                {
                    this.liczbaKół = value;
                }
                else { throw new ArgumentException("NLiczba kół musi być większa od 0!!!"); }                
            }
        }
        private int prędkość;
        public int Prędkość {
            get { return this.prędkość; }
            set {
                if(value>0)
                {
                    this.prędkość = value;
                }
                else { throw new ArgumentException("Prędkość musi być większa od 0!!!"); }
            }
        }
        public pojazdy(string nazwa, int lk, int pr)
        {
            this.nazwa = nazwa;
            this.LiczbaKół = lk;
            this.Prędkość = pr;
            this.lp = ++liczbaPojazdów;
        }
        public pojazdy(string nazwa, int pr)
        {
            this.nazwa = nazwa;
            this.LiczbaKół = 4;
            this.Prędkość = pr;
            this.lp = ++liczbaPojazdów;
        }
        public override string ToString()
        {
            return $"{lp}/{liczbaPojazdów} - Nazwa: {nazwa}, Liczba Kół: {LiczbaKół}, Prędkość: {Prędkość} km/h";
        }
    }
    public class PojazdMechaniczny : pojazdy
    {
        private int mocSilnika;
        public int MocSilnika
        {
            get { return mocSilnika; }
            set
            {
                if (value > 0)
                    mocSilnika = value;
                else
                    throw new ArgumentException("Moc silnika musi być większa od 0!!!");
            }
        }

        public PojazdMechaniczny(string nazwa, int lk, int pr, int moc) : base(nazwa, lk, pr)
        {
            this.MocSilnika = moc;
        }

        public override string ToString()
        {
            return base.ToString() + $", Moc Silnika: {MocSilnika} KM";
        }
    }
    public class Samochód : PojazdMechaniczny
    {
        private int liczbaPasażerów;
        public int LiczbaPasażerów
        {
            get { return liczbaPasażerów; }
            set
            {
                if (value > 0)
                    liczbaPasażerów = value;
                else
                    throw new ArgumentException("Liczba pasażerów musi być większa od 0!!!");
            }
        }

        public string Marka { get; set; }

        public Samochód(string nazwa, string marka, int lk, int pr, int moc, int pasazerowie)
            : base(nazwa, lk, pr, moc)
        {
            this.Marka = marka;
            this.LiczbaPasażerów = pasazerowie;
        }

        public override string ToString()
        {
            return base.ToString() + $", Marka: {Marka}, Pasażerowie: {LiczbaPasażerów}";
        }
    }
}
