using System.ComponentModel.Design;

namespace Generyki
{
    public class Student : IComparable<Student>
    {
        public double NumerAlbumu { get; set; }
        public string Nazwisko { get; set; }
        public double Ocena { get; set; }

        public Student(double na, string name, double oc)
        {
            this.NumerAlbumu = na;
            this.Ocena = oc;
            this.Nazwisko = name;
        }

        // Porównujemy studentów wg oceny
        public int CompareTo(Student? other)
        {
            if (other == null) return 1;
            return this.Ocena.CompareTo(other.Ocena);
        }

        public override string ToString()
        {
            return $"{Nazwisko} ({NumerAlbumu}), Ocena: {Ocena}";
        }
    }

    public static class Wiekszy
    {
        public static T ZnajdzWiekszy<T>(T a, T b) where T : IComparable<T>
        {
            if (a.CompareTo(b) >= 0)
                return a;
            else
                return b;
        }
    }
}
