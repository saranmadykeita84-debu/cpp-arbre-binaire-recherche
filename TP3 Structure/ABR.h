 //===================================================================================||
 // Nom du Programme             : Structure de données                               || 
 // Auteurs                      : Saran Mady Keita et Kadiatou Lamarana Bah          ||
 // Date de création             : 6 Novembre 2024                                    ||
 // Date de modification         : 14 Novembre 2024                                   ||
 // But de programme             : Ce programme a pour but d'implémenter et           ||
 //                              : manipuler des arbres binaires de recherche         ||
 //                              : avec des classes en C++.                           ||
 //===================================================================================||

#ifndef ABR_H
#define ABR_H

#include <iostream>
#include "Noeud.h"

using namespace std;
 

class ABR
{
private:
    Noeud* racine;

public:
    ABR(); // Constructeur sans argument (initialise racine à nullptr)
    ~ABR(); // Destructeur

    void Inserer(int d); // Insère un élément dans l'arbre
    void Supprimer(int d); // Supprime un élément de l'arbre
    void Afficher_Arbre(); // Affiche l'arbre niveau par niveau
    int Afficher_hauteur(); // Affiche la hauteur de l'arbre
    int Desequilibre(); // Calcule le nombre de nœuds déséquilibrés
    bool Afficher_Ascendant(int d); // Affiche les ascendants d'un élément
    void Archiver(const string& filename); // Archive l'arbre dans un fichier texte


    // Méthodes  pour les opérations récursives
    Noeud* InsererRecursif(Noeud* racine, int d);
    Noeud* SupprimerRecursif(Noeud* racine, int d);
    Noeud* minimum(Noeud* racine);
    void Afficher_ArbreRecursif(Noeud* racine);
    int hauteur(Noeud* racine);
    int DesequilibreRecursif(Noeud* racine);
    bool AfficherAscendants(Noeud* racine, int d);
    void ArchiverRecursif(Noeud* racine, ofstream& file);
   
};

#endif
