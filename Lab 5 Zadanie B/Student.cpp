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

    public class Regał<T>
    {
        public T Półka1 { get; set; } = default!;
        public T Półka2 { get; set; } = default!;
        public T Półka3 { get; set; } = default!;
        public void WstawNaWolnąPółkę(T element)
        {
            if (Equals(Półka1, default(T)))
                Półka1 = element;
            else if (Equals(Półka2, default(T)))
                Półka2 = element;
            else if (Equals(Półka3, default(T)))
                Półka3 = element;
        }
        public T WolnaPółka
        {
            set
            {
                WstawNaWolnąPółkę(value);
            }
        }
        public override string ToString()
        {
            return $"Półka1: {Półka1}\nPółka2: {Półka2}\nPółka3: {Półka3}";
        }
    }
}
