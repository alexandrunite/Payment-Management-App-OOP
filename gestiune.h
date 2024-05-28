#ifndef GESTIUNE_H
#define GESTIUNE_H

#include <unordered_map>
#include <unordered_set>
#include "platacard.h"
#include "business.h"

template <typename T>
class Gestiune {
private:
    int nr_plati;
    std::unordered_map<int, T> plati;
public:
    Gestiune() : nr_plati(0) {}

    void adauga_plata(const T& plata) {
        plati[plata.getID()] = plata;
        nr_plati++;
    }

    int get_nr_plati() const {
        return nr_plati;
    }

    friend std::ostream& operator<<(std::ostream& out, const Gestiune& g) {
        out << "Numar total plati: " << g.nr_plati << std::endl;
        for (const auto& [id, plata] : g.plati) {
            out << plata;
        }
        return out;
    }

    Gestiune& operator+=(const T& plata) {
        this->adauga_plata(plata);
        return *this;
    }
};

template <>
class Gestiune<PlatiCard> {
private:
    int nr_plati;
    int nr_clienti;
    std::unordered_map<int, PlatiCard> plati;
    std::unordered_set<std::string> clienti;

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

    friend std::ostream& operator<<(std::ostream& out, const Gestiune& g) {
        out << "Numar total plati: " << g.nr_plati << std::endl;
        out << "Numar total clienti: " << g.nr_clienti << std::endl;
        for (const auto& [id, plata] : g.plati) {
            out << plata;
        }
        return out;
    }

    Gestiune& operator+=(const PlatiCard& plata) {
        this->adauga_plata(plata);
        return *this;
    }
};

#endif // G
