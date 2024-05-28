#ifndef PROIECT3_BUSINESS
#define PROIECT3_BUSINESS

#include <iostream>
#include <string>
#include <limits>
using namespace std;
class Plati {
private:
    int id;
    string data;
    int suma;
    string tip_plata;
    static int totalPlati;
public:
    Plati() : id(0), suma(0) {
        ++totalPlati;
    }
    Plati(int id, const string &data, int suma, const string &tip_plata)
        : id(id), data(data), suma(suma), tip_plata(tip_plata) {
        ++totalPlati;
    }
    virtual ~Plati() {
        --totalPlati;
    }
    void setID(int ID) {
        id = ID;
    }
    void setData(const string& Data) {
        data = Data;
    }
    void setSuma(int Suma) {
        suma = Suma;
    }
    void setTipPlata(const string& TipPlata) {
        tip_plata = TipPlata;
    }
    int getID() const {
        return id;
    }
    string getData() const {
        return data;
    }
    int getSuma() const {
        return suma;
    }
    string getTipPlata() const {
        return tip_plata;
    }
    static int getTotalPlati() {
        return totalPlati;
    }
    virtual void afisare() const {
        cout<<"PLata numarul: "<<id<<", Data: "<<data<<", Suma: "<<suma<<", Modul de plata: "<< tip_plata<<endl;
    }
    virtual void citire(istream& in) {
        try {
            cout<<"numarul platii:";
            in>>id;
            if (in.fail()) throw runtime_error("nr invalid, rescrie");
            cout<<"data efectuarii platii:";
            in>>data;
            if (in.fail()) throw runtime_error("data invalida");
            cout<<"introduce suma";
            in>>suma;
            if (in.fail()) throw runtime_error("suma gresita");
            cout << "introduce tipul de plata:";
            in>>tip_plata;
            if (in.fail()) throw runtime_error("tip de plata invalid");
        } catch (const exception& e) {
            cerr<<"eroare la citire: "<<e.what()<<endl;
            in.clear();
            in.ignore(numeric_limits<streamsize>::max(),'\n');
        }
    }
    friend istream& operator>>(istream& in, Plati& p) {
        p.citire(in);
        return in;
    }
    friend ostream& operator<<(ostream& out, const Plati& p) {
        p.afisare();
        return out;
    }
    Plati& operator=(const Plati& other){
        if (this != &other){
            id=other.id;
            data=other.data;
            suma=other.suma;
            tip_plata=other.tip_plata;
        }
        return *this;
    }
};
int Plati::totalPlati = 0;
#endif // PROIECT3_BUSINESS