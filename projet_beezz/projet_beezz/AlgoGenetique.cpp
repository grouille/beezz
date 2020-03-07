#include "AlgoGenetique.h"

AlgoGenetique::AlgoGenetique(Instance* instance, int nb_iteration_max, double max_running_time, int nombre_individus):
	instance(instance), nb_iteration_max(nb_iteration_max), max_running_time(max_running_time), population(instance, nombre_individus)
{
}

AlgoGenetique::~AlgoGenetique()
{
}

void AlgoGenetique::run()
{
	int iteration = 0;
	int index_parent_1, index_parent_2, index_individu_a_muter;
	Individu enfant(instance), mutee(instance);

	population.initialiser_population_aleatoirement();
	while (iteration < nb_iteration_max)
	{
		do {
			index_parent_1 = Individu::random_int_between(0, population.nb_individus - 1);
			index_parent_2 = Individu::random_int_between(0, population.nb_individus - 1);
		} while (index_parent_1 == index_parent_2);

		enfant = crossover(population.individus[index_parent_1], population.individus[index_parent_2]);
		population.individus.push_back(enfant);
		population.nb_individus++;

		index_individu_a_muter = Individu::random_int_between(0, population.nb_individus - 1);
		mutee = mutation(population.individus[index_individu_a_muter]);
		population.individus.push_back(mutee);
		population.nb_individus++;

		selection();
		iteration++;
	}

	best_solutions(4);
}

void AlgoGenetique::best_solutions(int nb_best_ones)
{
	if (population.individus.empty())
		throw exception("List of individuals empty !!!");
	best_individus.clear();
	vector<bool> individus_deja_dans_best(population.nb_individus, false);
	double max;

	int index;
	for (int b = 0; b < nb_best_ones; b++)
	{
		max = 0;
		index = 0;
		for (int i = 1; i < population.individus.size(); i++)
			if (population.individus[i].get_satisfaction() > max && !individus_deja_dans_best[i])
			{
				max = population.individus[i].get_satisfaction();
				index = i;
			}
		individus_deja_dans_best[index] = true;
		best_individus.push_back(population.individus[index]);
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
	int deuxieme_option_a_mutter_au_cas_ou;
	if (indivudu_a_muter.chromosome[parametre_a_mutter][option_a_muter] == 0)
	{
		for (int j = 0; j < instance->get_nb_options_of_parametre(parametre_a_mutter); j++)
			indivudu_a_muter.chromosome[parametre_a_mutter][j] = 0;

		indivudu_a_muter.chromosome[parametre_a_mutter][option_a_muter] = 1;
	}
	else
	{
		for (int j = 0; j < instance->get_nb_options_of_parametre(parametre_a_mutter); j++)
			indivudu_a_muter.chromosome[parametre_a_mutter][option_a_muter] = 0;

		do
		{
			deuxieme_option_a_mutter_au_cas_ou = Individu::random_int_between(0, instance->get_nb_options_of_parametre(parametre_a_mutter) - 1);
		} while (deuxieme_option_a_mutter_au_cas_ou == option_a_muter);

		indivudu_a_muter.chromosome[parametre_a_mutter][deuxieme_option_a_mutter_au_cas_ou] = 1;
	}

	indivudu_a_muter.update_caracteristics();
	return indivudu_a_muter;
}

void AlgoGenetique::selection()
{
	
	elaguer_individus_trop_chers(instance->prix_max);
	if (population.individus.size() == 0)
		population.initialiser_population_aleatoirement();

	elaguer_individus_mauvaise_duree_de_vie(instance->get_duree_de_vie_minimale());
	if (population.individus.size() == 0)
		population.initialiser_population_aleatoirement();

	elaguer_individus_pas_ecolo(instance->seuil_ecolo);
	if (population.individus.size() == 0)
		population.initialiser_population_aleatoirement();
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
	population.nb_individus = population.individus.size();
}

void AlgoGenetique::elaguer_individus_pas_ecolo(double seuil)
{
	int i = 0;
	while (i < population.nb_individus)
		if (population.individus[i].get_empreinte_carbone() < seuil)
		{
			population.individus.erase(population.individus.begin() + i);
			population.nb_individus--;
		}
		else
			i++;
	population.nb_individus = population.individus.size();
}

void AlgoGenetique::elaguer_individus_mauvaise_duree_de_vie(double duree_vie_minimale_client)
{
	int i = 0;
	while (i < population.nb_individus)
	{
		if (population.individus[i].get_duree_de_vie() < duree_vie_minimale_client)
		{
			population.individus.erase(population.individus.begin() + i);
			population.nb_individus--;
		}
		else
			i++;
	}
	population.nb_individus = population.individus.size();
}

vector<Individu> AlgoGenetique::individus_non_domines()
{
	return vector<Individu>();
}
