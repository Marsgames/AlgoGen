//
//  Individu.hpp
//  FindPhrase
//
//  Created by Raphaël Daumas on 15/12/2018.
//  Copyright © 2018 Headcrab Entertainment. All rights reserved.
//

#pragma once

#include <string>
#include <main.hpp>

using std::string;

class Individu
{
private:
    string m_Chromosome;
    int m_Fitness;
    
    
public:
    Individu(const string& chromosome) : m_Chromosome(chromosome)
    {
        m_Fitness = CalculateFitness();
    }
    
    int CalculateFitness()
    {
        unsigned long tempFitness = 2 * K_STRING_TO_FIND.size();
        
        for (int i = 0; i < K_STRING_TO_FIND.size(); i++)
        {
            if (K_STRING_TO_FIND.find(m_Chromosome[i]) == string::npos)
            {
                continue;
            }
            tempFitness--;
            
            if (K_STRING_TO_FIND[i] != m_Chromosome[i])
            {
                continue;
            }
            tempFitness--;
        }
        
        return (int)tempFitness;
    }
    
    Individu Mate(Individu partner)
    {
        string childChromosome = "";
        
        for (int i = 0; i < m_Chromosome.size(); i++)
        {
            const double K_PROB = GetRandomInt(0, 100) / 100;
            
            if (K_PROB < (1 - K_MUTATE_PROB) / 2)
            {
                childChromosome += m_Chromosome[i];
            }
            else if (K_PROB < 1 - K_MUTATE_PROB)
            {
                childChromosome += partner.m_Chromosome[i];
            }
            else
            {
                childChromosome += GetRandomChar();
            }
        }
        
        return Individu(childChromosome);
    }
    
    int GetFitness() const
    {
        return m_Fitness;
    };
    
    string GetChromosome() const
    {
        return m_Chromosome;
    };
    
    bool operator<(const Individu& ind2) const
    {
        return m_Fitness < ind2.GetFitness();
    };
};
