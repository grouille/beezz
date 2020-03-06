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
};

#endif // !ALGOGENETIQUE_H


