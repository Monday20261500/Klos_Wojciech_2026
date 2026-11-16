#include <iostream>
using namespace std;

// zadania 1 - 6

class Pojazd{
    protected:
        string marka;
        string model;
    public:
        virtual void przyspiesz() {}
        virtual void zatrzymaj() {}
};

class Samochod : private Pojazd {
    public:
        Samochod(string Marka, string Model) { this->marka = Marka; this->model = Model;  }
        void przyspiesz() { cout<<"Samochod marki "<<marka<<" przyspiesza.\n"; }
        void zatrzymaj() { cout<<"Samochod modelu "<<model<<" się zatrzymuje.\n"; }
};

class Rower : private Pojazd {
    public:
        Rower(string Marka, string Model) { this->marka = Marka; this->model = Model;  }
        void przyspiesz() { cout<<"Rower marki "<<marka<<" przyspiesza.\n"; }
        void zatrzymaj() { cout<<"Rower modelu "<<model<<" się zatrzymuje.\n"; }
};

// dziedziczenie prywatne powoduje, że zmienne dziedziczone z Pojazdu stają się prywatne.


// zadanie 8 i 10

class Silnikowy : Samochod{    
    public:
        Silnikowy(string Marka, string Model) : Samochod(Marka,Model) {};
        void przyspiesz() {};
};

class Elektryczny : Samochod {
    public:
        Elektryczny(string Marka, string Model) : Samochod(Marka,Model) {};
        void ladowanie() {};
};

class Hybryda : public Silnikowy, public Elektryczny{
    public:
        Hybryda(string Marka, string Model) : Elektryczny(Marka,Model), Silnikowy(Marka,Model) {};
        void przyspiesz() {cout<<"Hybryda przyspiesza.\n";}
};

// zadanie 9

class ElektrycznySamochod : Samochod{
    public:
        ElektrycznySamochod(string Marka, string Model) : Samochod(Marka,Model) {};
        void przyspiesz() { cout<<"Samochod elektryczny przyspiesza.\n"; }
};

int main()
{
    Samochod samochodTestowy("Toyota", "Corolla");
    samochodTestowy.przyspiesz();
    samochodTestowy.zatrzymaj();

    Rower rowerTestowy("Shimano", "Indiana");
    rowerTestowy.przyspiesz();
    rowerTestowy.zatrzymaj();

    ElektrycznySamochod es("tesla","cybertruck");
    es.przyspiesz();

    Hybryda hybryda("Kia", "Torrento");

    hybryda.przyspiesz();

    return 0;
}