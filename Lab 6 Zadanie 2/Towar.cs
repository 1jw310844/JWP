namespace KlasyZadanie2
{
    public enum Kategoria { dostępny, niedostępny };

    public class Towar
    {
        public string nazwa { get; set; }
        public double cena { get; set; }
        public int ilość { get; set; }
        public Kategoria kategoria { get; set; }
        public Towar(string n, double c, int i, Kategoria k)
        {
            this.nazwa = n;
            this.cena = c;
            this.ilość = i;
            this.kategoria = k;
        }

        public override string ToString()
        {
            return $"Nazwa: {nazwa}, Cena: {cena}, \nIlość: {ilość}, Kategoria: {kategoria}";
        }
    }
}
