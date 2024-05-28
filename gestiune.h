#ifndef GESTIUNE_H
#define GESTIUNE_H

#include <unordered_map>
#include <unordered_set>
#include "platacard.h"
#include "business.h"
using namespace std;

template <typename T>
class Gestiune {
private:
    int nr_plati;
    unordered_map<int, T> plati;
public:
    Gestiune() : nr_plati(0) {}
    void adauga_plata(const T& plata) {
        plati[plata.getID()] = plata;
        nr_plati++;
    }
    int get_nr_plati() const {
        return nr_plati;
    }
    friend ostream& operator<<(ostream& out, const Gestiune& g) {
        out<<"Numar total plati: "<<g.nr_plati<<endl;
        for (const auto& [id, plata] : g.plati) {
            out << plata;
        }
        return out;
    }
    Gestiune& operator+=(const T& plata) {
        this->adauga_plata(plata);
        return *this;
    }
    // Demonstratie RTTI si dynamic_cast
    void demoRTTI() const{
        for (const auto& [id, plata] : plati) {
            const PlatiCard* card = dynamic_cast<const PlatiCard*>(&plata);
            if (card) {
                cout<<"Plata cu cardul: "<<*card<<endl;
            } else {
                cout<<"Plata normala: "<<plata<<endl;
            }
        }
    }
};

template <>
class Gestiune<PlatiCard> {
private:
    int nr_plati;
    int nr_clienti;
    unordered_map<int, PlatiCard> plati;
    unordered_set<string> clienti;

public:
    Gestiune() : nr_plati(0), nr_clienti(0) {}

    void adauga_plata(const PlatiCard& plata) {
        plati[plata.getID()] = plata;
        nr_plati++;
        if (clienti.find(plata.getNumarCard()) == clienti.end()) {
            clienti.insert(plata.getNumarCard());
            nr_clienti++;
        }
    }
    int get_nr_plati() const {
        return nr_plati;
    }
    int get_nr_clienti() const {
        return nr_clienti;
    }
    friend ostream& operator<<(ostream& out, const Gestiune& g) {
        out<<"Numar total plati: "<<g.nr_plati<<endl;
        out<<"Numar total clienti: "<<g.nr_clienti<<endl;
        for (const auto& [id, plata] : g.plati) {
            out << plata;
        }
        return out;
    }
    Gestiune& operator+=(const PlatiCard& plata) {
        this->adauga_plata(plata);
        return *this;
    }
    //demonstratie RTTI si dynamic+cast
    void demonstratiedyncast() const{
        for (const auto& [id, plata] : plati) {
            cout<<"Plata cu cardul: "<<plata<<endl;
        }
    }
};

#endif // GESTIUNE_H
