// palindrome_manacher.cpp
#include "palindrome_manacher.hpp"

using namespace std;

string ajouterCaracteresSpeciaux(const string& s) {
    string nouvelleChaine = "#";
    for (char c : s) {
        nouvelleChaine += c;
        nouvelleChaine += '#';
    }
    return nouvelleChaine;
}

vector<string> plusLongPalindromeManacher(const string& s) {
    string chaineModifiee = ajouterCaracteresSpeciaux(s);
    int n = chaineModifiee.length();
    vector<int> rayon(n, 0);

    int centre = 0;
    int droite = 0;

    int maxRayon = 0;
    vector<string> resultats;

    for (int i = 0; i < n; i++) {
        if (i < droite) {
            int miroir = 2 * centre - i;
            rayon[i] = min(droite - i, rayon[miroir]);
        }

        // Extension du palindrome centré à i
        int gaucheExtension = i - (rayon[i] + 1);
        int droiteExtension = i + (rayon[i] + 1);

        while (gaucheExtension >= 0 && droiteExtension < n &&
               chaineModifiee[gaucheExtension] == chaineModifiee[droiteExtension]) {
            rayon[i]++;
            gaucheExtension--;
            droiteExtension++;
        }

        // Mise à jour du centre et du droit si nécessaire
        if (i + rayon[i] > droite) {
            centre = i;
            droite = i + rayon[i];
        }

        // Mise à jour du plus long rayon
        if (rayon[i] > maxRayon) {
            maxRayon = rayon[i];
            resultats.clear();  // Supprime les résultats précédents
        }

        // Ajouter le palindrome trouvé à la liste des résultats
        if (rayon[i] == maxRayon) {
            resultats.push_back(s.substr((i - maxRayon) / 2, maxRayon));
        }
    }

    return resultats;
}
