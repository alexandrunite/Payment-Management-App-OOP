#include "business.h"
#include "platacard.h"
#include "gestiune.h"
using namespace std;
int main() {
    try {
        Gestiune<Plati> gestiunePlati;
        Gestiune<PlatiCard> gestiunePlatiCard;
        //2 plati normale
        Plati p1(1, "20.05.2024", 100, "Cash");
        Plati p2(2, "21.05.2024", 200, "Cec");
        gestiunePlati+=p1;
        gestiunePlati+=p2;
        //adaugam 2 plati cu cardul
        PlatiCard pc1(3, "22.05.2022", 300, "1234567891234567");
        PlatiCard pc2(4, "23.05.2021", 400, "2345678912345678");
        gestiunePlatiCard+=pc1;
        gestiunePlatiCard+=pc2;
        cout<<"gestionare plati normale:\n"<<gestiunePlati;
        cout<<"gestionare plati cu cardul:\n"<<gestiunePlatiCard;
        Plati p3;
        cin>>p3;
        gestiunePlati+=p3;
        PlatiCard pc3;
        cin>>pc3;
        gestiunePlatiCard+=pc3;
        cout<<"Gestiune plati normale dupa adaugare:\n"<<gestiunePlati;
        cout<<"Gestiune plati cu cardul dupa adaugare:\n"<<gestiunePlatiCard;
        cout<<"RTTI pentru plati normale:\n";
        gestiunePlati.demoRTTI();
        cout<<" RTTI pentru plati cu cardul:\n";
        gestiunePlatiCard.demonstratiedyncast();
    } catch (const exception& e) {
        cerr<<"A aparut o eroare: "<<e.what()<<endl;
    }
    return 0;
}
