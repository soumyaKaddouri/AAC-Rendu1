// tests.cpp
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "palindrome_manacher.hpp"

TEST_CASE("AjouterCaracteresSpeciaux - Cas de base", "[ajouterCaracteresSpeciaux]") {
    std::string input = "babad";
    std::string expected = "#b#a#b#a#d#";

    REQUIRE(ajouterCaracteresSpeciaux(input) == expected);
}

TEST_CASE("PlusLongPalindromeManacher - Cas de base", "[plusLongPalindromeManacher]") {
    std::string input = "babad";
    std::vector<std::string> expected = {"bab", "aba"};

    REQUIRE(plusLongPalindromeManacher(input) == expected);
}

TEST_CASE("AjouterCaracteresSpeciaux - Cas de chaîne vide", "[ajouterCaracteresSpeciaux]") {
    std::string input = "";
    std::string expected = "#";

    REQUIRE(ajouterCaracteresSpeciaux(input) == expected);
}

TEST_CASE("PlusLongPalindromeManacher - Cas de chaîne vide", "[plusLongPalindromeManacher]") {
    std::string input = "";
    std::vector<std::string> expected = {""};

    REQUIRE(plusLongPalindromeManacher(input) == expected);
}

TEST_CASE("AjouterCaracteresSpeciaux - Cas de palindrome impair", "[ajouterCaracteresSpeciaux]") {
    std::string input = "racecar";
    std::string expected = "#r#a#c#e#c#a#r#";

    REQUIRE(ajouterCaracteresSpeciaux(input) == expected);
}

TEST_CASE("PlusLongPalindromeManacher - Cas de palindrome impair", "[plusLongPalindromeManacher]") {
    std::string input = "racecar";
    std::vector<std::string> expected = {"racecar"};

    REQUIRE(plusLongPalindromeManacher(input) == expected);
}

TEST_CASE("AjouterCaracteresSpeciaux - Cas de palindrome pair", "[ajouterCaracteresSpeciaux]") {
    std::string input = "noon";
    std::string expected = "#n#o#o#n#";

    REQUIRE(ajouterCaracteresSpeciaux(input) == expected);
}

TEST_CASE("PlusLongPalindromeManacher - Cas de palindrome pair", "[plusLongPalindromeManacher]") {
    std::string input = "noon";
    std::vector<std::string> expected = {"noon"};

    REQUIRE(plusLongPalindromeManacher(input) == expected);
}
