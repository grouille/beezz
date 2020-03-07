#include "Population.h"

Population::Population(Instance * instance, int nb_individus) :instance(instance), individus(), nb_individus(nb_individus)
{
}

Population::~Population()
{
}

void Population::initialiser_population_aleatoirement(int nombre_individus_a_ajouter)
{
	individus.clear();
	for (int i = 0; i < nombre_individus_a_ajouter; i++)
	{
		Individu individu(instance);
		individu.initialiser_aleatoirement();
		individus.push_back(individu);
	}
	nb_individus = individus.size();
}
