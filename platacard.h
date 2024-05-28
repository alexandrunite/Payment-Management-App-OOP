#ifndef PLATACARD_H
#define PLATACARD_H

#include <string>
#include <iostream>
#include <limits>
#include "business.h"
using namespace std;
class PlatiCard : public Plati {
private:
    string numarCard;
    static int totalPlatiCard;
public:
    void setNumarCard(const string& NumarCard) {
        numarCard = NumarCard;
    }
    string getNumarCard() const {
        return numarCard;
    }
    PlatiCard() {
        ++totalPlatiCard;
    }
    PlatiCard(int id, const std::string& data, int suma, const std::string& numar_card)
        : Plati(id, data, suma, "Card"), numarCard(numar_card) {
        ++totalPlatiCard;
    }
    ~PlatiCard() {
        --totalPlatiCard;
    }
    static int getTotalPlatiCard() {
        return totalPlatiCard;
    }
    void afisare() const override {
        Plati::afisare();
        cout<<"Numar card: "<<numarCard<<endl;
    }

    void citire(istream& in) override {
        try {
            Plati::citire(in);
            cout<<"Introduceti numarul cardului: ";
            in >> numarCard;
            if (in.fail()) throw runtime_error("Numarul cardului invalid");
        } catch (const exception& e) {
            cerr<<"Eroare la citire: "<<e.what()<<endl;
            in.clear();
            in.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    PlatiCard& operator=(const PlatiCard& other) {
        if (this != &other) {
            Plati::operator=(other);
            numarCard = other.numarCard;
        }
        return *this;
    }

    friend istream& operator>>(istream& in, PlatiCard& p) {
        p.citire(in);
        return in;
    }

    friend ostream& operator<<(ostream& out, const PlatiCard& p) {
        p.afisare();
        return out;
    }
};

int PlatiCard::totalPlatiCard = 0;

#endif // PLATACARD_H
