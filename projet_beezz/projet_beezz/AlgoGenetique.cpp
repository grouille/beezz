#include "AlgoGenetique.h"

AlgoGenetique::AlgoGenetique(Instance* instance, int nb_iteration_max, double max_running_time, int nombre_individus):
	instance(instance), nb_iteration_max(nb_iteration_max), max_running_time(max_running_time), nombre_individus(nombre_individus), population(instance, nombre_individus)
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
	double pourcentage_enfant_de_plus_souhaite = 0.3;
	double pourcentage_mutants_de_plus_souhaite = 0.01;
	population.initialiser_population_aleatoirement(nombre_individus);
	while (iteration < nb_iteration_max)
	{
		cout << "*";
		for (int i = 0; i < (int)nb_iteration_max * pourcentage_enfant_de_plus_souhaite; i++)
		{
			do {
				index_parent_1 = Individu::random_int_between(0, population.nb_individus - 1);
				index_parent_2 = Individu::random_int_between(0, population.nb_individus - 1);
			} while (index_parent_1 == index_parent_2);

			enfant = crossover(population.individus[index_parent_1], population.individus[index_parent_2]);
			population.individus.push_back(enfant);
			population.nb_individus++;
		}

		for (int i = 0; i < (int)nb_iteration_max * pourcentage_mutants_de_plus_souhaite; i++)
		{
			index_individu_a_muter = Individu::random_int_between(0, population.nb_individus - 1);
			mutee = mutation(population.individus[index_individu_a_muter]);
			population.individus.push_back(mutee);
			population.nb_individus++;
		}


		if(iteration < nb_iteration_max)
		{
			selection();
			iteration++;
		}
		best_solutions(4);

	}

	vector<pair<Individu, double>> tous_les_meilleurs_individus;
	pair<Individu, double> couple(Individu(instance), 0);
	for (int i = 0; i < best_individus.size(); i++)
	{
		couple.first = best_individus[i];
		couple.second = best_individus[i].get_satisfaction();
		tous_les_meilleurs_individus.push_back(couple);
	}

	tous_les_meilleurs_individus = sort(tous_les_meilleurs_individus);

	best_individus.clear();

	for (int i = 0; i < 4; i++)
		best_individus.push_back(tous_les_meilleurs_individus[i].first);
}

void AlgoGenetique::best_solutions(int nb_best_ones)
{
	if (population.individus.empty())
		throw exception("List of individuals empty !!!");
	else
	{
		vector<bool> individus_deja_dans_best(population.nb_individus, false);
		double max;
			
		int index;
		int nb_solutions_souhaite = min(population.nb_individus, nb_best_ones);
		for (int b = 0; b < nb_solutions_souhaite; b++)
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
			
			vector<Individu>::iterator it;
			if (!best_individus.empty())
			{
				it = find(best_individus.begin(), best_individus.end(), population.individus[index]);
				if (it != best_individus.end())
					best_individus.push_back(population.individus[index]);
			}
			else
				best_individus.push_back(population.individus[index]);
		}
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

	/*Individu enfant(instance);

	vector<int> parent_choisi_a_chaque_fois(instance->get_nb_parametres());
	for(int i=0; i < instance->get_nb_parametres(); i++)
		parent_choisi_a_chaque_fois [i] = Individu::random_int_between(0,1);

	for (int i = 0; i < instance->get_nb_parametres(); i++)
		if (parent_choisi_a_chaque_fois[i] == 0)
			enfant.chromosome.push_back(parent1.chromosome[i]);
		else
			enfant.chromosome.push_back(parent2.chromosome[i]);*/

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
	{
		population.initialiser_population_aleatoirement(nombre_individus);
	}

	/*elaguer_individus_mauvaise_duree_de_vie(instance->get_duree_de_vie_minimale());
	if (population.individus.size() == 0)
	{
		population.initialiser_population_aleatoirement(nombre_individus);
	}*/

	elaguer_individus_pas_ecolo(instance->seuil_ecolo);
	if (population.individus.size() == 0)
	{
		population.initialiser_population_aleatoirement(nombre_individus);
	}
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
