//
// Created by alexn on 28.05.2024.
//
#include <iostream>
#include <vector>
#include "platacard.h"

using namespace std;

int main() {
    PlatiCard card1(1, "2024-05-20", 100, "1234567891234567");
    PlatiCard card2(2, "2024-05-21", 200, "2345678912345678");
//upcasting
    vector<Plati*> payments;
    payments.push_back(&card1);
    payments.push_back(&card2);
//rtti cu upcasting
    for (Plati* payment : payments) {
        if (PlatiCard* cardPayment = dynamic_cast<PlatiCard*>(payment)) {
            cout<<"plata cu card detectata";
            cardPayment->afisare();
        } else{
            cout<<"plata normala detectata";
            payment->afisare();
        }
    }
    cout<<"nr total de plati:"<<Plati::getTotalPlati()<<endl;
    cout<<"nr total de plati cu cardul:"<<PlatiCard::getTotalPlatiCard()<<endl;

    return 0;
}

