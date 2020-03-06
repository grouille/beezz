#ifndef INDIVIDU_H
#define INDIVIDU_H
#pragma once

#include <iostream>
#include <vector>
#include "Instance.h"
#include <random>

using namespace std;

class Individu
{
public:
	Instance* instance;
	double satisfaction;
	double empreinte_carbone;
	double prix;
	double duree_de_vie;

	vector<vector<int>> chromosome;

public:
	Individu(Instance*);
	~Individu();

	void initialiser_aleatoirement();

	void update_caracteristics();
	void calculer_satisfaction();
	void calculer_empreinte_carbone();
	void calculer_prix();
	void calculer_duree_de_vie();

	double get_satisfaction();
	double get_empreinte_carbone();
	double get_prix();
	double get_duree_de_vie();

	int option_a_un_dun_parametre(int i);

	void into_texte_file(string file_name);

	void afficher_individu();

	static int random_int_between(int _min, int _max)
	{
		int minimum = min(_min, _max);
		int maximum = max(_min, _max);
		random_device                  rand_dev;
		mt19937                        generator(rand_dev());
		uniform_int_distribution<int>  distr(minimum, maximum);

		return distr(generator);
	}

};

#endif // !INDIVIDU_H
