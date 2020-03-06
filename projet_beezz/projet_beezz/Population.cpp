#include "Population.h"

Population::Population(Instance * instance, int nb_individus) :instance(instance), individus(), nb_individus()
{
}

Population::~Population()
{
}

void Population::initialiser_population_aleatoirement()
{
	individus.clear();
	for (int i; i < nb_individus; i++)
	{
		Individu individu(instance);
		individu.initialiser_aleatoirement();
		individus.push_back(individu);
	}
}
