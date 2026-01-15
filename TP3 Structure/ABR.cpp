
//===================================================================================||
// Nom du Programme             : Structure de données                               || 
// Auteurs                      : Saran Mady Keita et Kadiatou Lamarana Bah          ||
// Date de création             : 01 Decembre 2024                                   ||
// Date de modification         : 04 Decembre 2024                                   ||
// But de programme             : Ce programme a pour but d'implémenter et           ||
//                              : manipuler des arbres binaires de recherche         ||
//                              : avec des classes en C++.                           ||
//===================================================================================||

#include "ABR.h"
#include <queue>
#include <fstream>

using namespace std;

// Constructeur
ABR::ABR() : racine(nullptr) 
{
    // Initialisation de la racine à nullptr dans le constructeur.

}  


// Destructeur
ABR::~ABR()
{
    // Destruction récursive de l'arbre
    delete racine;  // Appelle le destructeur de Noeud qui supprimera récursivement les nœuds.
}

// Fonction pour insérer un élément dans l'arbre
void ABR::Inserer(int d)
{
    // Appel à la méthode récursive pour insérer l'élément dans l'arbre.
    racine = InsererRecursif(racine, d);  
}

// Méthode récursive pour insérer un élément dans l'arbre
Noeud* ABR::InsererRecursif(Noeud* racine, int d)
{
    // Si la racine est null, on insère le nouvel élément ici.
    if (!racine)  
    {
        // Crée un nouveau nœud et le retourne.
        return new Noeud(d); 
    }
    // Si la valeur est inférieure à celle du nœud actuel, insère à gauche.
    if (d < racine->valeur)  
    {
        racine->gauche = InsererRecursif(racine->gauche, d);
    }
    // Ou si la valeur est supérieure à celle du nœud actuel, insère à droite.
    else if (d > racine->valeur)  
    {
        racine->droit = InsererRecursif(racine->droit, d);
    }
    // Retourne la racine actuelle après insertion.
    return racine;  
}

// Fonction pour supprimer un élément de l'arbre
void ABR::Supprimer(int d)
{
    // Appel à la méthode récursive pour supprimer l'élément.
    racine = SupprimerRecursif(racine, d);  
}

// Méthode récursive pour supprimer un élément de l'arbre
Noeud* ABR::SupprimerRecursif(Noeud* racine, int d)
{
    // Si la racine est null, l'élément n'existe pas dans l'arbre.
    if (!racine)  
    {
        return nullptr;
    }
    // Si l'élément à supprimer est plus petit, il est à gauche.
    if (d < racine->valeur) 
    {
        racine->gauche = SupprimerRecursif(racine->gauche, d);
    }
    // Ou si l'élément à supprimer est plus grand, il est à droite.
    else if (d > racine->valeur)  
    {
        racine->droit = SupprimerRecursif(racine->droit, d);
    }
    // L'élément est trouvé.
    else  // L'élément est trouvé.
    {
        // Cas 1 : Pas de fils gauche
        if (!racine->gauche)
        {
            Noeud* temp = racine->droit;
            delete racine;
            return temp;
        }
        // Cas 2 : Pas de fils droit
        else if (!racine->droit)
        {
            Noeud* temp = racine->gauche;
            delete racine;
            return temp;
        }

        // Cas 3 : Les deux fils sont présents, on remplace la valeur du nœud par le minimum du sous-arbre droit
        Noeud* temp = minimum(racine->droit);
        racine->valeur = temp->valeur;
        // Supprime le nœud ayant la valeur du minimum.
        racine->droit = SupprimerRecursif(racine->droit, temp->valeur);  
    }
    // Retourne la racine modifiée après suppression.
    return racine;  
}

// Fonction pour obtenir le minimum d'un sous-arbre
Noeud* ABR::minimum(Noeud* racine)
{
    // On descend à gauche jusqu'à trouver le minimum.
    while (racine->gauche)  
    {
        racine = racine->gauche;
    }
    // Retourne le minimum trouvé.
    return racine;  
}

// Fonction pour afficher l'arbre niveau par niveau
void ABR::Afficher_Arbre()
{
    cout << "*********************************" << endl;
    // Si l'arbre est vide, on ne fait rien.
    if (!racine) return;  
    // Appel à la méthode récursive pour afficher l'arbre.
    Afficher_ArbreRecursif(racine); 
}

// Méthode récursive pour afficher l'arbre niveau par niveau
void ABR::Afficher_ArbreRecursif(Noeud* racine)
{
    // Si la racine est null, on arrête.
    if (!racine) return;  

    // Utilisation d'une queue pour afficher l'arbre niveau par niveau
    queue<Noeud*> q;
    q.push(racine);
    // Tant qu'il y a des nœuds dans la queue.
    while (!q.empty())  
    {
        // Nombre de nœuds à afficher à ce niveau.
        size_t n = q.size();  
        // Afficher tous les nœuds à ce niveau.
        while (n--)  
        {
            Noeud* current = q.front();
            q.pop();
            // Afficher la valeur du nœud.
            cout << current->valeur << " ";  
            // Ajouter le fils gauche à la queue.
            if (current->gauche) q.push(current->gauche); 
            // Ajouter le fils droit à la queue.
            if (current->droit) q.push(current->droit); 
        }
        // Passer à la ligne suivante après avoir affiché un niveau.
        cout << endl; 
    }
}

// Fonction pour afficher la hauteur de l'arbre
int ABR::Afficher_hauteur()
{
    // Appel à la méthode récursive pour calculer la hauteur de l'arbre.
    return hauteur(racine);  
}

// Méthode récursive pour calculer la hauteur de l'arbre
int ABR::hauteur(Noeud* racine)
{
    // Si la racine est null, la hauteur est -1 (arbre vide).
    if (!racine) return -1;  
    // Hauteur du sous-arbre gauche.
    int hauteurGauche = hauteur(racine->gauche); 
    // Hauteur du sous-arbre droit.
    int hauteurDroite = hauteur(racine->droit);  
    // La hauteur est le maximum des hauteurs des sous-arbres + 1.
    return max(hauteurGauche, hauteurDroite) + 1;
}

// Fonction pour afficher les ascendants d'un nœud
bool ABR::Afficher_Ascendant(int d)
{
    if (racine == nullptr)
    {
        // Si l'arbre est vide, on affiche un message et on retourne.
        cout << "l'arbre est vide " << endl;  
        return d;
    }
    if (racine->valeur == d)
    {
        cout << "l'element " << d << " est la racine, il n'a pas d'ascendants " << endl;
        return d;
    }
    if (!AfficherAscendants(racine, d))
    {
        // Si l'élément n'existe pas.
        cout << "l'element " << d << " n'existe pas dans l'arbre " << endl;  
    }
    return d;
}

// Méthode récursive pour afficher les ascendants d'un nœud
bool ABR::AfficherAscendants(Noeud* racine, int d)
{
    // Si le nœud est null, il n'y a pas d'ascendants.
    if (!racine) return false;  

    if (racine->valeur == d || AfficherAscendants(racine->gauche, d) || AfficherAscendants(racine->droit, d))
    {
        // Affiche l'ascendant.
        cout << racine->valeur << " "; 
        return true;
    }
    // Si l'élément n'a pas été trouvé parmi les ascendants.
    return false;  
}

// Fonction pour archiver l'arbre dans un fichier texte
void ABR::Archiver(const string& filename)
{
    //On ouvre le fichier pour l'écriture.
    ofstream file(filename);  
    // Appel à la méthode récursive pour écrire l'arbre dans le fichier.
    ArchiverRecursif(racine, file);
    // Ferme le fichier après l'écriture.
    file.close();  
}

// Méthode récursive pour archiver l'arbre dans un fichier texte
void ABR::ArchiverRecursif(Noeud* racine, ofstream& file)
{
    if (!racine)
    {
        // Si le nœud est null, écrire un marqueur de fin de branche.
        file << "/ ";
        return;
    }
    // Écrire la valeur du nœud dans le fichier.
    file << racine->valeur << " "; 
    // Archiver le sous-arbre gauche.
    ArchiverRecursif(racine->gauche, file);  
    // Archiver le sous - arbre droit.
    ArchiverRecursif(racine->droit, file);  
}

// Fonction pour calculer le nombre de nœuds déséquilibrés
int ABR::Desequilibre()
{
    // Appel à la méthode récursive pour calculer le nombre de nœuds déséquilibrés.
    return DesequilibreRecursif(racine);  
}

// Méthode récursive pour calculer le nombre de nœuds déséquilibrés
int ABR::DesequilibreRecursif(Noeud* racine)
{
    // Si le nœud est null, il n'est pas déséquilibré.
    if (!racine) return 0;  
    // Hauteur du sous-arbre gauche.
    int hauteurGauche = hauteur(racine->gauche); 
    // Hauteur du sous-arbre droit.
    int hauteurDroite = hauteur(racine->droit);  

    int count = 0;
    if (abs(hauteurGauche - hauteurDroite) > 1)
    {
        // Le nœud est déséquilibré.
        count = 1; 
    }

    return count + DesequilibreRecursif(racine->gauche) + DesequilibreRecursif(racine->droit);  // Retourne le nombre total de nœuds déséquilibrés.
}
