// main.cpp
#include <iostream>
#include "palindrome_manacher.hpp"

int main() {
    std::string chaine;
    std::cout << "Entrez une chaine : ";
    std::getline(std::cin, chaine);

    std::vector<std::string> resultats = plusLongPalindromeManacher(chaine);

    std::cout << "Les plus longs palindromes sont : ";
    for (const auto& resultat : resultats) {
        std::cout << resultat << " ";
    }
    std::cout << std::endl;

    return 0;
}
