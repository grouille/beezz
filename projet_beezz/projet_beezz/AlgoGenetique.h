#ifndef ALGOGENETIQUE_H
#define ALGOGENETIQUE_H
#pragma once

#include "Population.h"

class AlgoGenetique
{
public:
	Instance* instance;
	Population population;
	int nb_iteration_max;
	int nombre_individus;
	double max_running_time;

	vector<Individu> best_individus;

public:
	AlgoGenetique(Instance* instance, int nb_iteration_max, double max_running_time, int nombre_individus);
	~AlgoGenetique();

	void run();

	void best_solutions(int nb_best_ones);

	Individu crossover(Individu parent1, Individu parent2);
	Individu mutation(Individu indivudu_a_muter);

	void selection();

	void elaguer_individus_trop_chers(double prix_max);

	void elaguer_individus_pas_ecolo(double seuil);

	void elaguer_individus_mauvaise_duree_de_vie(double duree_vie_minimale_client);

	vector<Individu> individus_non_domines();

	vector<pair<Individu, double>> sort(vector<pair<Individu, double>> list)
	{
		pair<Individu, double> temporary(Individu(instance), 0);
		vector<pair<Individu, double>> result = list;

		for (int i = 0; i < result.size(); i++)
		{
			for (int j = 0; j < result.size() - 1; j++)
				if (result[j].second < result[j + 1].second)
				{
					temporary = result[j];
					result[j] = result[j + 1];
					result[j + 1] = temporary;
				}
		}

		return result;
	}
};

#endif // !ALGOGENETIQUE_H


