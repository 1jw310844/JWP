namespace Geometria
{
    public abstract class Bryła : IWyswietl
    {
        public abstract string Nazwa { get; }
        public double Gęstość { get; set; }
        public double CenaZaKg { get; set; }
        public double Masa => Gęstość * ObliczObjętość;
        public double ObliczCenę => CenaZaKg * Masa;
        public abstract double ObliczObjętość { get; }

        public Bryła(double g, double c)
        {
            Gęstość = g;
            CenaZaKg = c;
        }

        public override string ToString()
        {
            return $"Nazwa: {Nazwa}, Gęstość: {Gęstość:F2}, Cena za KG: {CenaZaKg:F2}, Objętość: {ObliczObjętość:F2}, Masa: {Masa:F2}, Cena: {ObliczCenę:F2}";
        }

        // Zmodyfikowana metoda CompareTo z obsługą różnych typów
        public int CompareTo(object obj)
        {
            if (obj == null) return 1;

            if (obj is Bryła otherBryła)
            {
                // Porównanie po objętości (malejąco)
                return otherBryła.ObliczObjętość.CompareTo(ObliczObjętość);
            }
            else if (obj is Student otherStudent)
            {
                // Jeśli obiekt jest typu Student, porównaj po nazwisku (rosnąco)
                return string.Compare(otherStudent.Nazwisko, "", StringComparison.Ordinal);
            }

            throw new ArgumentException("Obiekt nie jest typu Bryła ani Student.");
        }

        public string PobierzIdentyfikator()
        {
            return $"{Nazwa}-{Guid.NewGuid()}";
        }
    }

    public class Kula : Bryła
    {
        public double Promień { get; set; }
        public override string Nazwa => "Kula";
        public override double ObliczObjętość => 4.0 / 3.0 * Math.PI * Math.Pow(Promień, 3);

        public Kula(double g, double c, double pr) : base(g, c)
        {
            Promień = pr;
        }

        // Operator +, zwracający kulę, której objętość to suma objętości obu kul
        public static Kula operator +(Kula k1, Kula k2)
        {
            double nowaObjętość = k1.ObliczObjętość + k2.ObliczObjętość;
            double nowyPromień = Math.Pow((3 * nowaObjętość) / (4 * Math.PI), 1.0 / 3.0); // Obliczanie nowego promienia na podstawie objętości
            return new Kula(k1.Gęstość, k1.CenaZaKg, nowyPromień);
        }

        // Operator -, zwracający kulę, której objętość to różnica objętości obu kul
        public static Kula operator -(Kula k1, Kula k2)
        {
            double nowaObjętość = Math.Max(0, k1.ObliczObjętość - k2.ObliczObjętość);
            double nowyPromień = Math.Pow((3 * nowaObjętość) / (4 * Math.PI), 1.0 / 3.0); // Obliczanie nowego promienia na podstawie objętości
            return new Kula(k1.Gęstość, k1.CenaZaKg, nowyPromień);
        }

        // Operator ++, zwiększający objętość kuli o jedną jednostkę
        public static Kula operator ++(Kula k)
        {
            double nowaObjętość = k.ObliczObjętość + 1; // Zwiększamy objętość o 1
            double nowyPromień = Math.Pow((3 * nowaObjętość) / (4 * Math.PI), 1.0 / 3.0); // Obliczanie nowego promienia na podstawie objętości
            return new Kula(k.Gęstość, k.CenaZaKg, nowyPromień);
        }
    }

    public class Stożek : Bryła
    {
        public double Promień { get; set; }
        public double Wysokość { get; set; }
        public override string Nazwa => "Stożek";
        public override double ObliczObjętość => 1.0 / 3.0 * Wysokość * Math.PI * Math.Pow(Promień, 2);

        public Stożek(double g, double c, double pr, double h) : base(g, c)
        {
            Promień = pr;
            Wysokość = h;
        }
    }

    public interface IWyswietl : IComparable
    {
        string PobierzIdentyfikator();
    }

    public class Student : IWyswietl
    {
        public string Imię { get; set; }
        public string Nazwisko { get; set; }

        public Student(string imię, string nazwisko)
        {
            Imię = imię;
            Nazwisko = nazwisko;
        }

        // Implementacja metody PobierzIdentyfikator
        public string PobierzIdentyfikator()
        {
            return $"{Imię} {Nazwisko}-{Guid.NewGuid()}";
        }

        // Zmodyfikowana metoda CompareTo z obsługą różnych typów
        public int CompareTo(object obj)
        {
            if (obj == null) return 1;

            if (obj is Student otherStudent)
            {
                return string.Compare(Nazwisko, otherStudent.Nazwisko);
            }
            else if (obj is Bryła otherBryła)
            {
                // Jeśli obiekt jest typu Bryła, porównaj po objętości (malejąco)
                return otherBryła.ObliczObjętość.CompareTo(0); // Porównanie z zerem, bo bryły porównujemy po objętości
            }

            throw new ArgumentException("Obiekt nie jest typu Student ani Bryła.");
        }
    }
}
