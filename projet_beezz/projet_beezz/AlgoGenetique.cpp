#include "AlgoGenetique.h"

AlgoGenetique::AlgoGenetique(Instance* instance, int nb_iteration_max, double max_running_time, int nombre_individus):
	instance(instance), nb_iteration_max(nb_iteration_max), max_running_time(max_running_time),population(instance, nb_iteration_max)
{
}

AlgoGenetique::~AlgoGenetique()
{
}

void AlgoGenetique::run()
{
}

Individu AlgoGenetique::crossover(Individu parent1, Individu parent2)
{
	return Individu(instance);
}

Individu AlgoGenetique::mutation(Individu indivudu_a_muter)
{
	return Individu();
}

void AlgoGenetique::selection()
{
}

vector<Individu> AlgoGenetique::individus_non_domines()
{
	return vector<Individu>();
}
