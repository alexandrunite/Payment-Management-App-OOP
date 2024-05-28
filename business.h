#ifndef PROIECT3_BUSINESS
#define PROIECT3_BUSINESS

#include <iostream>
#include <string>

using std::string;

class Plati{
    private:
        int id;
        string data;
        int suma;
        string tip_plata;
    public:
        Plati()=default;
        Plati(int id, const string &data, int suma, const string &tip_plata)
            : id(id),
              data(data),
              suma(suma),
              tip_plata(tip_plata) {
        }
        virtual ~Plati() = default;
        void setID(int ID) {
            id=ID;
        }
        void setData(string Data) {
            data=Data;
        }
        void setSuma(int Suma) {
            suma=Suma;
        }
        void setTipPlata(string TipPlata) {
            tip_plata=TipPlata;
        }
        int getID() const {
            return id;
        }
        string getData() const {
            return data;
        }
        virtual void afisare() const {
                std::cout << "ID: " << id << ", Data: " << data << ", Suma: " << suma << ", Tip plata: " << tip_plata << std::endl;
            }
        virtual void citire(std::istream& in, Plati& p) const {
            std::cout<<"Introduceti ID-ul platii: ";
            in >> p.id;
            std::cout << "Introduceti data platii: ";
            in >> p.data;
            std::cout << "Introduceti suma: ";
            in >> p.suma;
            std::cout << "Introduceti tipul platii: ";
            in >> p.tip_plata;
        }
        friend std::istream& operator>>(std::istream& in, Plati& p) {
            std::cout << "Introduceti ID-ul platii: ";
            in >> p.id;
            std::cout << "Introduceti data platii (YYYY-MM-DD): ";
            in >> p.data;
            std::cout << "Introduceti suma: ";
            in >> p.suma;
            std::cout << "Introduceti tipul platii: ";
            in >> p.tip_plata;
            return in;
        }
        friend std::ostream& operator<<(std::ostream& out, const Plati& p) {
                p.afisare();
                return out;
            }
        Plati& operator=(const Plati& other) {
            if (this != &other) {
                id = other.id;
                data = other.data;
                suma = other.suma;
                tip_plata = other.tip_plata;
            }
            return *this;
        }

};

#endif