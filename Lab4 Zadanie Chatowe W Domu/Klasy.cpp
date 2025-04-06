namespace Pojazdy
{
    //Interfejsy
    public interface IInformacje
    {
        string WyswietlInformacje();
    }

    public interface RekordPredkosci
    {
        string JakiRekord();
    }

    //Klasa PojazdSilnikowy
    public abstract class PojazdSilnikowy : IInformacje, RekordPredkosci
    {
        public abstract string marka { get; }
        public abstract double masa_wlasna { get; }
        public abstract double spalanieNa100km { get; }
        public abstract double cenaZaLitrPaliwa { get; }
        public double pojemnoscBaku { set; get; }
        public double masaPasazerow {  set; get; }

        public double KosztPrzejechania100km => cenaZaLitrPaliwa * spalanieNa100km;
        public double ZasiegNaPelnymBaku => (pojemnoscBaku / spalanieNa100km) * 100;
        public double MasaCalkowita => masa_wlasna + masaPasazerow;

        public PojazdSilnikowy(double p, double mp)
        {
            this.pojemnoscBaku = p;
            this.masaPasazerow = mp;
        }
        public override string ToString()
        {
            return $" Marka: {marka}" + $" Koszt 100 km: {KosztPrzejechania100km:F2}"
                + $" Zasieg na pelnym baku: {ZasiegNaPelnymBaku:F2}"+
                $" Masa Calkowita: {MasaCalkowita:F2}";
        }

        //Metoda funkcyjna z interfejsu
        string IInformacje.WyswietlInformacje()
        {
            return this.ToString();
        }

        string RekordPredkosci.JakiRekord()
        {
            return "Rekord to 555 km/h";         
        }
    }
    
    //Klasa Samochód
    public class Samochod : PojazdSilnikowy
    {
        public int liczbaDrzwi;
        public string model;
        public override string marka => "Samochód";
        public override double masa_wlasna => 1000;
        public override double cenaZaLitrPaliwa => 6.0;
        public override double spalanieNa100km => 6.5;
        public override string ToString()
        {
            return $" Marka: {marka}" + $" Model: {model}" + $" Koszt 100 km: {KosztPrzejechania100km:F2}"
                + $" Zasieg na pelnym baku: {ZasiegNaPelnymBaku:F2}" +
                $" Masa Calkowita: {MasaCalkowita:F2}" + $" Liczba Drzwi: {liczbaDrzwi}";
        }
        public Samochod(double p, double mp, int lD) : base(p, mp)
        {
            this.model = "";
            this.liczbaDrzwi = lD;
        }

    }

    //Klasa Motocykl
    public class Motocykl : PojazdSilnikowy
    {
        public string typMotocykla;
        public string model;
        public override double masa_wlasna => 500;
        public override double cenaZaLitrPaliwa => 6.0;
        public override string marka => "Motocykl";
        public override double spalanieNa100km => 4.5;
        public override string ToString()
        {
            return $" Marka: {marka}"+ $" Model: {model}"  + $" Koszt 100 km: {KosztPrzejechania100km:F2}"
                + $" Zasieg na pelnym baku: {ZasiegNaPelnymBaku:F2}" +
                $" Masa Calkowita: {MasaCalkowita:F2}" + $" Typ motocykla: {typMotocykla:F2}";
        }
        public Motocykl(double p, double mp,string tM) : base(p, mp)
        {
            this.model = "";
            this.typMotocykla = tM;
        }
    }
}
