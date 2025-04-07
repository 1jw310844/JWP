namespace Generyki
{
    public class Student
    {
        private double numerAlbumu;
        public double NumerAlbumu {
            get {return numerAlbumu; }
            set {numerAlbumu=value; } 
        }
        private string nazwisko;
        public string Nazwisko {
            get {return nazwisko; }
            set {nazwisko = value; } 
        }
        private double ocena;
        public double Ocena {
            get {return ocena; }
            set {ocena = value; } 
        }

        public Student(double na, string name, double oc)
        {
            this.numerAlbumu = na;
            this.ocena = oc;
            this.nazwisko = name;
        }
    }
}
