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
	population.initialiser_population_aleatoirement();
	int iteration = 0;
	int index_parent_1, index_parent_2, index_individu_a_muter;
	Individu enfant(instance), mutee(instance);
	while (iteration < nb_iteration_max)
	{
		do {
			index_parent_1 = Individu::random_int_between(0, population.nb_individus - 1);
			index_parent_2 = Individu::random_int_between(0, population.nb_individus - 1);
		} while (index_parent_1 == index_parent_2);

		enfant = crossover(population.individus[index_parent_1], population.individus[index_parent_2]);
		population.individus.push_back(enfant);

		index_individu_a_muter = Individu::random_int_between(0, population.nb_individus - 1);
		mutee = mutation(population.individus[index_individu_a_muter]);
		population.individus.push_back(mutee);

		selection();
	}
}

Individu AlgoGenetique::crossover(Individu parent1, Individu parent2)
{
	int point_de_coupure = Individu::random_int_between(1, instance->get_nb_parametres()-2);
	Individu enfant(instance);

	for (int i = 0; i <= point_de_coupure; i++)
		enfant.chromosome.push_back(parent1.chromosome[i]);


	for (int i = point_de_coupure+1; i < instance->get_nb_parametres(); i++)
		enfant.chromosome.push_back(parent2.chromosome[i]);

	enfant.update_caracteristics();
	return enfant;
}

Individu AlgoGenetique::mutation(Individu indivudu_a_muter)
{
	int parametre_a_mutter = Individu::random_int_between(0, instance->get_nb_parametres()-1);
	int option_a_muter		= Individu::random_int_between(0, instance->get_nb_options_of_parametre(parametre_a_mutter) - 1);

	for (int j = 0; j < instance->get_nb_options_of_parametr(i); j++)
		instance->set_option_of_parameter(i, j, 0);

	indivudu_a_muter[parametre_a_mutter][option_a_muter] = 1;
	return indivudu_a_muter;
}

void AlgoGenetique::selection()
{
	elaguer_individus_pas_ecolo(instance->seuil_ecologie);
	elaguer_individus_trop_chers(instance->prix_max);
}

void AlgoGenetique::elaguer_individus_trop_chers(double prix_max)
{
	int i = 0;
	while (i < population.nb_individus)
		if (population.individus[i].get_prix() > prix_max)
		{
			population.individus.erase(population.individus.begin() + i);
			population.nb_individus--;
		}
		else
			i++;
}

void AlgoGenetique::elaguer_individus_pas_ecolo(double seuil)
{
	int i = 0;
	while (i < population.nb_individus)
		if (population.individus[i].get_empreinte_carbone() > seuil)
		{
			population.individus.erase(population.individus.begin() + i);
			population.nb_individus--;
		}
		else
			i++;
}

vector<Individu> AlgoGenetique::individus_non_domines()
{
	return vector<Individu>();
}
