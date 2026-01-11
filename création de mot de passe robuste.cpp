#include <iostream>
#include <string>
#include <vector>
#include <random> // Pour une génération aléatoire moderne
#include <algorithm> // Pour std::shuffle

// Fonction pour générer le mot de passe
std::string generatePassword(int length, bool useSpecialChars) {
    // 1. Définition des jeux de caractères
    const std::string lowercase = "abcdefghijklmnopqrstuvwxyz";
    const std::string uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const std::string numbers = "0123456789";
    const std::string special = "!@#$%^&*()-_=+[]{}|;:,.<>?";

    std::string allChars = lowercase + uppercase + numbers;
    if (useSpecialChars) {
        allChars += special;
    }

    std::string password;
    
    // 2. Initialisation du générateur aléatoire (Mersenne Twister)
    std::random_device rd;  // Source d'entropie matérielle
    std::mt19937 generator(rd()); // Générateur standard
    std::uniform_int_distribution<> distribution(0, allChars.size() - 1);

    // 3. Génération
    for (int i = 0; i < length; ++i) {
        password += allChars[distribution(generator)];
    }

    return password;
}

int main() {
    int length;
    char includeSpecialInput;
    bool useSpecial = false;

    std::cout << "========================================\n";
    std::cout << "   GENERATEUR DE MOT DE PASSE C++   \n";
    std::cout << "========================================\n";

    // Entrée utilisateur : Longueur
    std::cout << "Longueur du mot de passe souhaitee (ex: 12) : ";
    while (!(std::cin >> length) || length < 4) {
        std::cout << "Erreur : Veuillez entrer un nombre entier >= 4 : ";
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }

    // Entrée utilisateur : Caractères spéciaux
    std::cout << "Inclure des caracteres speciaux (!@#$...) ? (o/n) : ";
    std::cin >> includeSpecialInput;

    if (includeSpecialInput == 'o' || includeSpecialInput == 'O') {
        useSpecial = true;
    }

    // Génération et affichage
    std::string myPassword = generatePassword(length, useSpecial);
    
    std::cout << "\n----------------------------------------\n";
    std::cout << "Votre mot de passe genere : \n";
    std::cout << ">>  " << myPassword << "  <<";
    std::cout << "\n----------------------------------------\n";

    // Pause pour lire le résultat avant de fermer (utile sur Windows)
    std::cout << "\nAppuyez sur Entree pour quitter...";
    std::cin.ignore();
    std::cin.get();

    return 0;
}