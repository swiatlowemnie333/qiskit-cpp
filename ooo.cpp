#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>

struct Bubble {
    int id;
    double r;     // Promień od oka
    double theta; // Kąt sferyczny
};

int main() {
    std::cout << "==================================================\n";
    std::cout << "🧬 DYNAMICZNY ROJ BĄBELKOWY INTERFERENCJI V2 🧬\n";
    std::cout << "==================================================\n\n";

    // Tworzymy naszą sieć 156 bąbelków
    std::vector<Bubble> foam;
    foam.push_back({0, 1.0, 0.0}); // Środek
    for (int i = 1; i <= 155; ++i) {
        foam.push_back({i, 1.2, (i * 2.3) * (M_PI / 180.0)});
    }

    std::vector<std::string> observables = {"XYZ", "XIY", "OZO", "ZZZ"};
    double base_pos = 0.50;
    double step = 0.10;

    std::cout << std::left << std::setw(8) << "Obs" 
              << std::setw(15) << "Kolor/Cecha" 
              << "Wyliczona Interferencja Kwantowa\n";
    std::cout << "---------------------------------------------------------\n";

    for (const auto& obs : observables) {
        // dynamiczne nadawanie cech (kolorów) na podstawie liter w stringu
        double weight = 1.0;
        for (char c : obs) {
            if (c == 'X') weight *= 1.5; // Faza X wzmacnia przesunięcie
            if (c == 'Y') weight *= -1.2; // Faza Y odwraca wektor
            if (c == 'Z') weight *= 2.0;  // Faza Z podwaja energię środka
        }

        double snap_f = base_pos + (step * weight);
        double snap_b = base_pos - (step * weight);
        
        double central_shift = snap_f - snap_b;
        double external_shift = (step * 2) * std::cos(foam[5].theta);

        // Nakładanie się fal (Interferencja Dodatnia)
        double total_interference = std::sin(central_shift) + std::sin(external_shift * weight);

        std::cout << std::left << std::setw(8) << obs 
                  << std::setw(15) << (weight > 0 ? "RÓŻOWY/DODATNI" : "NIEBIESKI/UJEMNY") 
                  << std::fixed << std::setprecision(6) << total_interference << "\n";
    }

    std::cout << "\n✅ Różnice cech zmapowane. System gotowy do wdrożenia do rdzenia!\n";
    return 0;
}
