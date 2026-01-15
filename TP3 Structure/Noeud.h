
//===================================================================================||
// Nom du Programme             : Structure de données                               || 
// Auteurs                      : Saran Mady Keita et Kadiatou Lamarana Bah          ||
// Date de création             : 01 Decembre 2024                                   ||
// Date de modification         : 04 Decembre 2024                                   ||
// But de programme             : Ce programme a pour but d'implémenter et           ||
//                              : manipuler des arbres binaires de recherche         ||
//                              : avec des classes en C++.                           ||
//===================================================================================||

#ifndef NOEUD_H
#define NOEUD_H

struct Noeud
{
    int valeur;
    Noeud* gauche;
    Noeud* droit;

    // Constructeur pour initialiser un noeud avec une valeur
    Noeud(int v) : valeur(v), gauche(nullptr), droit(nullptr) {}
};

#endif
