#include <vector>
#include <string>
#include <iostream>
#include <random>

#include <main.hpp>
#include <Individu.hpp>

using std::cout;
using std::vector;
using std::endl;
using std::string;


int main()
{
    //    srand((unsigned)(time(0)));
    srand(0);
    
    // current generation
    int generation = 0;
    
    vector<Individu> population;
    
    // create initial population
    for(int i = 0; i < K_INDIVIDUS_PAR_GENERATION; i++)
    {
        const string chromosome = GetRandomIndividuChromosome();
        //        cout << "chromosome : " << chromosome << endl;
        population.push_back(Individu(chromosome));
    }
    
    while(true)
    {
        // sort the population in increasing order of fitness score
        sort(population.begin(), population.end());
        
        // if the individual having lowest fitness score ie.
        // 0 then we know that we have reached to the target
        // and break the loop
        if(population[0].GetFitness() <= 0)
        {
            cout << population[0].GetChromosome() << endl;
            break;
        }
        
        // Otherwise generate new offsprings for new generation
        vector<Individu> newGeneration;
        
        // On garde les 20 meilleurs
        int stop = K_INDIVIDUS_PAR_GENERATION * K_PERCENT_WINNER_RETAIN; // 100 * .2 = 20
        for(int i = 0; i < stop; i++)
        {
            newGeneration.push_back(population[i]);
        }
        
        for (int i = 0; i < K_INDIVIDUS_PAR_GENERATION - (K_INDIVIDUS_PAR_GENERATION * K_PERCENT_WINNER_RETAIN); i++)
        {
            
        }
        
        stop -= K_INDIVIDUS_PAR_GENERATION - (K_INDIVIDUS_PAR_GENERATION * K_PERCENT_NEW);
        stop *= -1;
        for(int i = 0; i < stop; i++)
        {
            const int indexMother = GetRandomInt(0, K_INDIVIDUS_PAR_GENERATION / 2);
            const int indexFather = GetRandomInt(0, K_INDIVIDUS_PAR_GENERATION / 2);
            
            const Individu mother = population[indexMother];
            Individu father = population[indexFather];
            
            newGeneration.push_back(father.Mate(mother));
        }
        
        stop = K_INDIVIDUS_PAR_GENERATION - stop;
        for (int i = 0; i < stop; i++)
        {
            newGeneration.push_back(Individu(GetRandomIndividuChromosome()));
        }
        
        population = newGeneration;
        if (generation % 10000 == 0)
        {
            cout << "Génération : \033[1;33m" << generation << "\033[0m" << endl;
            cout << "String: " << population[0].GetChromosome() << endl;
            cout << "Fitness: " << population[0].GetFitness() << endl << endl;
        }else if (generation % 1000 == 0)
        {
            cout << "Génération : \033[1;31m" << generation << "\033[0m" << endl;
            cout << "String: " << population[0].GetChromosome() << endl;
            cout << "Fitness: " << population[0].GetFitness() << endl << endl;
        }
        
        generation++;
    }
    cout << endl << endl << "\033[1;32mGénération : " << generation << "\033[0m" << endl;
    cout << "String: " << population[0].GetChromosome() << endl;
    cout << "Fitness: " << population[0].GetFitness() << endl << endl;
    
}

