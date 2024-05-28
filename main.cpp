#include "business.h"
#include "platacard.h"
#include "gestiune.h"

int main() {
    try {
        Gestiune<Plati> gestiunePlati;
        Gestiune<PlatiCard> gestiunePlatiCard;

        // Adaugam plati normale
        Plati p1(1, "2024-05-20", 100, "Cash");
        Plati p2(2, "2024-05-21", 200, "Cec");

        gestiunePlati += p1;
        gestiunePlati += p2;

        // Adaugam plati cu cardul
        PlatiCard pc1(3, "2024-05-22", 300, "1234-5678-9123-4567");
        PlatiCard pc2(4, "2024-05-23", 400, "2345-6789-1234-5678");

        gestiunePlatiCard += pc1;
        gestiunePlatiCard += pc2;

        std::cout << "Gestiune plati normale:\n" << gestiunePlati;
        std::cout << "Gestiune plati cu cardul:\n" << gestiunePlatiCard;

        // Citim plati normale de la utilizator
        Plati p3;
        std::cin >> p3;
        gestiunePlati += p3;

        // Citim plati cu cardul de la utilizator
        PlatiCard pc3;
        std::cin >> pc3;
        gestiunePlatiCard += pc3;

        std::cout << "Gestiune plati normale dupa adaugare:\n" << gestiunePlati;
        std::cout << "Gestiune plati cu cardul dupa adaugare:\n" << gestiunePlatiCard;
    } catch (const std::exception& e) {
        std::cerr << "A aparut o eroare: " << e.what() << std::endl;
    }

    return 0;
}
