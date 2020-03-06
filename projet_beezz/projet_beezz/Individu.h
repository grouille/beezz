#ifndef INDIVIDU_H
#define INDIVIDU_H
#pragma once

#include <iostream>
#include <vector>

using namespace std;

class Instance;

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

	void calculer_satisfaction();
	void empreinte_carbone();
	void prix();
	void duree_de_vie();

	double get_calculer_satisfaction();
	double get_empreinte_carbone();
	double get_prix();
	double get_duree_de_vie();
};

#endif // !INDIVIDU_H
