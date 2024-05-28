#ifndef PLATACARD_H
#define PLATACARD_H

#include <string>
#include <iostream>
#include "business.h"

class PlatiCard : public Plati {
private:
    std::string numarCard;
public:
    void setNumarCard(std::string NumarCard) {
        numarCard = NumarCard;
    }
    std::string getNumarCard() const {
        return numarCard;
    }
    PlatiCard() = default;
    PlatiCard(int id, const std::string& data, int suma, const std::string& numar_card)
        : Plati(id, data, suma, "Card"), numarCard(numar_card) {}
    ~PlatiCard() = default;

    void afisare() const override {
        Plati::afisare();
        std::cout << "Numar card: " << numarCard << std::endl;
    }

    void citire(std::istream& in) override {
        try {
            Plati::citire(in);
            std::cout << "Introduceti numarul cardului: ";
            in >> numarCard;
            if (in.fail()) throw std::runtime_error("Numar de card invalid");
        } catch (const std::exception& e) {
            std::cerr << "Eroare la citire: " << e.what() << std::endl;
            in.clear(); // Reset the stream state
            in.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the rest of the line
        }
    }

    PlatiCard& operator=(const PlatiCard& other) {
        if (this != &other) {
            Plati::operator=(other);
            numarCard = other.numarCard;
        }
        return *this;
    }

    friend std::istream& operator>>(std::istream& in, PlatiCard& p) {
        p.citire(in);
        return in;
    }

    friend std::ostream& operator<<(std::ostream& out, const PlatiCard& p) {
        p.afisare();
        return out;
    }
};

#endif // PLATACARD_H
