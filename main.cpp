/*
Programme : Chifoumi
But : Jouer au jeu du chifoumi contre un ordinateur
Date de dernière modif : 28/09/2021
Auteurs : A. Garcia et A. Fakhfakh
Remarques : Code conforme aux spécification internes données en cours
*/

#include "game-tools.h"
#include <string>
#include <iostream>

using namespace std;

int main(void)
{
    //VARIABLES
    char coupJoueur; //Coup que le joueur saisis au clavier
    string coupMachineLettre; //coup de la machine ecrite en toute lettre
    string coupJoueurLettre; //coup du joueur ecrit en toute lettre
    unsigned short int coupJoueurTransformer; //Coup du joueur transformé en 1, 2 ou 3 selon ce qu'il a saisis
    int coupMachine; //Coup aleatoire de la machine entre 1 et 3
    unsigned short int scoreJoueur; //Score du joueur
    unsigned short int scoreMachine; //Score de la machine

    
    //TRAITEMENTS

    //Initialiser la partie >> scoreJoueur, scoreMachine

    //Initialiser les variables de comptage >> scoreJoueur, scoreMachine
    scoreJoueur = 0; //Initialisation du compteur score du joueur
    scoreMachine = 0; //Initialisation du compteur score de la machine

    //ecran >> afficherRegles
    cout << "CHIFOUMI" << endl;
    cout << "-------------------" << endl;
    cout << "Vous (joueur1) jouerez contre la machine (joueur2)." << endl;
    cout << "Le jeu est compose de manches." << endl;
    cout << "Vous pourrez arreter quand vous le souhaitez. La question sera posee dans chaque manche." << endl;  
    cout << "Pas de point en cas d'egalite." << endl;
    cout << endl;

    //scoreMachine, scoreJoueur >> Jouer la partie
    while(true)
    {   
       //Saisie Et Verif et Condition d'arret >> coupJoueur

       //Saisie et Verif >> coupJoueur € ["F", "f", "P", "p", "C", "c", "Q", "q"]
       do
       {
            cout << "Nouvelle manche :"  << endl;
            cout << "      Choisissez une figure ou Quittez : (C)iseau (F)euille (P)ierre ou (Q)uitter : ";
            cin >> coupJoueur;
       } while (coupJoueur != 'f' && coupJoueur != 'F' && coupJoueur != 'p' && coupJoueur != 'P' && coupJoueur != 'c' && coupJoueur != 'C' && coupJoueur != 'q' && coupJoueur != 'Q');
       
       //Condition d'arret 
       if(coupJoueur == 'Q' || coupJoueur == 'q')
       {    
           break;
       }
        //Transformer coupJoueur et Generer coupMachine

        //coupJoueur >> Transformer coupJoueur >> coupJoueurTransformer
        switch(coupJoueur)
        {
            case 'C' : coupJoueurTransformer = 1; break;
            case 'c' : coupJoueurTransformer = 1; break;
            case 'F' : coupJoueurTransformer = 2; break;
            case 'f' : coupJoueurTransformer = 2; break;
            case 'P' : coupJoueurTransformer = 3; break;
            case 'p' : coupJoueurTransformer = 3; break;
        }

        // Generer coupMachine>> coupMachine
        coupMachine = random(1,3);

        //coupJoueur, coupMachine >> Transformer les coups en toute lettre >> coupMachineLettre, coupJoueurLettre

        //coupMachine >> Transformer coupMachine en lettre >> coupMachineLettre
        switch(coupMachine)
        {
            case 1 : coupMachineLettre = "ciseau" ; break;
            case 2 : coupMachineLettre = "feuille" ; break;
            case 3 : coupMachineLettre = "pierre" ; break;
        }

        //coupJoueur >> transformer coupJoueur en lettre >> coupJoueurLettre
        switch(coupJoueurTransformer)
        {
            case 1 : coupJoueurLettre = "ciseau" ; break;
            case 2 : coupJoueurLettre = "feuille" ; break;
            case 3 : coupJoueurLettre = "pierre" ; break;
        }

        //coupJoueurTransformer, coupJoueurLettre, coupMachine, coupMachineLettre, scoreJoueur, scoreMachine >> Compter les scores et afficher la manche

        // coupJoueurTransformer, coupMachine >> compterPoints >> scoreJoueur, scoreMachine
        switch(coupJoueurTransformer)
        {
            case 1 :
                if (coupMachine == 2)
                {
                    scoreJoueur ++;
                } 
                else if (coupMachine == 3) 
                {
                    scoreMachine ++;
                }
                break;
            case 2 : 
                if (coupMachine == 1)
                {
                    scoreMachine ++;
                }
                else if (coupMachine == 3) 
                {
                    scoreJoueur ++;
                }
                break;
            case 3 : 
                if (coupMachine == 1)
                {
                    scoreJoueur ++;
                }
                else if (coupMachine == 2) 
                {
                    scoreMachine ++;
                }
                break;
        }
        //scoreJoueur, scoreMachine, coupJoueurLettre, coupMachineLettre >> afficherCoupEtScore >> ecran
        cout << "      joueur 1 (vous) : " << coupJoueurLettre << " , " << scoreJoueur << endl;
        cout << "      joueur 2        : " << coupMachineLettre << " , " << scoreMachine << endl;
        
        
    }

    //Finaliser la partie

    //Afficher message de fin 
    cout << "Merci d'avoir jouer" << endl;

    return 0;
}