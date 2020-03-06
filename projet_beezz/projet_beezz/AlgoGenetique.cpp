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
	int parametre_a_mutter = Individu::random_int_between(0, instance->get_nb_parametres());
	int option_a_muter		= Individu::random_int_between(0, instance->get_nb_options_of_parametre(parametre_a_mutter));

	for (int j = 0; j < instance->get_nb_options_of_parametr(i); j++)
		instance->set_option_of_parameter(i, j, 0);

	indivudu_a_muter[parametre_a_mutter][option_a_muter] = 1;
	return Individu(instance);
}

void AlgoGenetique::selection()
{
}

vector<Individu> AlgoGenetique::individus_non_domines()
{
	return vector<Individu>();
}
