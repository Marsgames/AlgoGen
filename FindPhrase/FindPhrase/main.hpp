//
//  main.hpp
//  FindPhrase
//
//  Created by Raphaël Daumas on 09/12/2018.
//  Copyright © 2018 Headcrab Entertainment. All rights reserved.
//

#pragma once

#include <random>
#include <string>

using std::mt19937;
using std::uniform_int_distribution;
using std::string;

mt19937 rng(0); // Seed
uniform_int_distribution<int> genesValide(32, 255); // uniform, unbiased
//const string K_STRING_TO_FIND = "Fuck fucking fucked fucker fucking fuckups fuck fucking fucked fucking fuckup fucking fucker's fucking fuckup.";
const string K_STRING_TO_FIND = "Ceci est une phrase totallement lambda qui à pour but de voir comment se comporte le K_PERCENT_NEW avec une autre phrase que l'exemple en anglais.";
//const string K_STRING_TO_FIND = "Mais au lieu de la simplicité, c'est le faste que je mettais au plus haut rang, si, après que j'avais forcé Françoise, qui n'en pouvait plus et disait que les jambes \" lui rentraient \", à faire les cent pas pendant une heure, je voyais enfin, débouchant de l'allée qui vient de la Porte Dauphine - image pour moi d'un prestige royal, d'une arrivée souveraine telle qu'aucune reine véritable n'a pu m'en donner l'impression dans la suite";
const int K_INDIVIDUS_PAR_GENERATION = 100;
const double K_MUTATE_PROB = .1;
const double K_PERCENT_WINNER_RETAIN = .2; // Les 20% les meilleurs sont gardés
const double K_PERCENT_NEW = .05;


// Retourne un entier aléatoire de manière uniforme et non biaisé
int GetRandomInt(int start, int end)
{
    uniform_int_distribution<int> range(start, end);
    return range(rng);
}

// Retourne un char valide (ascii 32 --> ascii 255) aléatoire qui servira de nouveau gene
char GetRandomChar()
{
    return (char)genesValide(rng);
}

// Retourne un individu
string GetRandomIndividuChromosome()
{
    string randomIndividu = "";
    while (randomIndividu.size() < K_STRING_TO_FIND.size()) {
        randomIndividu += GetRandomChar();
    }
    
    return randomIndividu;
}
