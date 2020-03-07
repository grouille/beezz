#ifndef POPULATION_H
#define POPULATION_H
#pragma once

#include <iostream>
#include "Individu.h"

class Population
{
public:
	Instance* instance;
	vector<Individu> individus;
	int nb_individus;
public:
	Population(Instance* instance, int nb_individus);
	~Population();

	void initialiser_population_aleatoirement(int nombre_individus_a_ajouter);
};

#endif