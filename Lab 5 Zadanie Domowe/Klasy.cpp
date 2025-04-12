namespace Klasy
{
    public interface IZwiększany
    {
        public void Zmień();
    }

    public interface IZmniejszany
    {
        public void Zmień();
    }
    public interface IPoprawialny<T>
    {
        T PobierzLepsząWersję();
    }
    public class Samochód : IZwiększany, IZmniejszany, IPoprawialny<Samochód>
    {
        private int prędkość;
        public int Prędkość {
            get {return prędkość; }
            set {prędkość = value; } 
        }
  
        public override string ToString()
        {
            return $"{prędkość}";
        }
        void IZwiększany.Zmień()
        {
            prędkość += 10;
        }
        void IZmniejszany.Zmień()
        {
            prędkość -= 5;
        }
        public Samochód PobierzLepsząWersję()
        {
            return new Samochód { Prędkość = this.Prędkość + 20 };
        }
        
    }
    public class Student : IPoprawialny<Student>
    {
        public string Imię { get; set; }
        public int Ocena { get; set; }

        public override string ToString()
        {
            return $"Student: {Imię}, Ocena: {Ocena}";
        }

        public Student PobierzLepsząWersję()
        {
            return new Student { Imię = this.Imię, Ocena = Math.Min(Ocena + 1, 5) }; // poprawiamy ocenę
        }
    }
}
