#include "Individu.h"
#include <random>

Individu::Individu(Instance* instance):instance(instance), satisfaction(0), empreinte_carbone(0), prix(0), duree_de_vie(0), chromosome()
{
}

Individu::~Individu()
{
}

void Individu::initialiser_aleatoirement()
{
	int option_choisie_a_un;

	for (int i = 0; i < instance->nombre_parametres; i++)
	{
		for (int j = 0; j < instance->get_nb_options_of_parametr(i); j++)
			instance->set_option_of_parameter(i, j, 0);

		option_choisie_a_un = random_int_between(0, instance->get_nb_options_of_parametr(i) - 1);
		instance->set_option_of_parameter(i, option_choisie_a_un, 1);
	}
	update_caracteristics();
}


void Individu::update_caracteristics()
{
	calculer_satisfaction();
	calculer_empreinte_carbone();
	calculer_prix();
	calculer_duree_de_vie();
}

void Individu::calculer_satisfaction()
{
	//somme des evaluations sur chaque critere
}

void Individu::calculer_empreinte_carbone()
{
	//sommer sur l'empreinte carbone dependemment des options a 1
}

void Individu::calculer_prix()
{
	//sommer sur les prix dependemment des options a 1
}

void Individu::calculer_duree_de_vie()
{
	//minimum des durees de vie sur les options a 1
}

double Individu::get_satisfaction()
{
	return satisfaction;
}

double Individu::get_empreinte_carbone()
{
	return empreinte_carbone;
}

double Individu::get_prix()
{
	return prix;
}

double Individu::get_duree_de_vie()
{
	return duree_de_vie;
}
