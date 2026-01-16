//===================================================================================||
// Nom du Programme             : Structure de données                               || 
// Auteurs                      : Saran Mady Keita                                   ||
// Date de création             : 01 Decembre 2024                                   ||
// Date de modification         : 04 Decembre 2024                                   ||
// But de programme             : Ce programme a pour but d'implémenter et           ||
//                              : manipuler des arbres binaires de recherche         ||
//                              : avec des classes en C++.                           ||
//===================================================================================||

#include <iostream>
#include "ABR.h"
#include <fstream>
#include <sstream> // Pour utiliser stringstream pour gérer la lecture du fichier

using namespace std;


void afficherIntroduction()
{
    cout << "===================================================" << endl;
    cout << "||  Date de creation:         01/12/2024          ||" << endl;
    cout << "||  Date de Modification:     04/12/2024          ||" << endl;
    cout << "||  Travail realiser par:                         ||" << endl;
    cout << "||  Keita Saran Mady                              ||" << endl;
    cout << "||  Bonnus prise en compte                        ||" << endl;
    cout << "====================================================" << endl;
    cout << endl;
}

int main()
{
    afficherIntroduction();
    ABR arbre;
    string ligne;
    int d;
    // Ouverture du fichier contenant les instructions
    ifstream fichier("Instructions.txt"); 

    if (!fichier.is_open())
    {
        cout << "Erreur lors de l'ouverture du fichier Instructions.txt !" << endl;
        return 1;
    }

    // Lire chaque ligne du fichier
    while (getline(fichier, ligne))
    {
        // Nettoyage des espaces superflus avant et après la ligne
        ligne = ligne.substr(0, ligne.find_last_not_of(" \t\r\n") + 1); // Enlève les espaces et retours à la ligne

        // Si la ligne est vide, on l'ignore
        if (ligne.empty()) continue;

        // Créer un stringstream pour traiter la ligne
        stringstream ss(ligne);
        string commande;
        ss >> commande;

        if (commande == "I")
        {
            if (ss >> d)
            {
                arbre.Inserer(d);
            }
            else
            {
                cout << "Commande incorrecte ou manque de valeur après 'I'." << endl;
            }
        }
        else if (commande == "S")
        {

            if (ss >> d)
            {
                cout << "la valeur " << d << " est supprimer avec succes" << endl;
                arbre.Supprimer(d);
                cout << "*********************************" << endl;
            }
            else
            {
                cout << "Commande incorrecte ou manque de valeur après 'S'." << endl;
            }
        }
        else if (commande == "A")
        {
            cout << " Affichage de l'arbre " << endl;
            arbre.Afficher_Arbre();
            cout << "*********************************" << endl;
        }
        else if (commande == "H")
        {
            cout << "Hauteur de l'arbre: " << arbre.Afficher_hauteur() << endl;
            cout << "*********************************" << endl;
        }
        else if (commande == "D")
        {

            cout << "Nombre de nouds desequilibres: " << arbre.Desequilibre() << endl;
            cout << "*********************************" << endl;
        }
        else if (commande == "G")
        {
            if (ss >> d)
            {
                cout << "Ascendants de " << d << " est de : ";
                arbre.Afficher_Ascendant(d);
                cout << endl;
                cout << "*********************************" << endl;
            }
            else
            {
                cout << "Commande incorrecte ou manque de valeur après 'G'." << endl;
            }
        }
        else if (commande == "T")
        {
            arbre.Archiver("arbre.txt");
            cout << "Arbre archive dans arbre.txt" << endl;
        }

        else
        {
            cout << "Commande inconnue dans le fichier!" << endl;
        }
    }

    fichier.close(); // Fermer le fichier après avoir fini

    return 0;
}
