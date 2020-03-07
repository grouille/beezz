#include "Individu.h"
#include <random>
#include <fstream>
Individu::Individu():instance(NULL), satisfaction(0), empreinte_carbone(0), prix(0), duree_de_vie(0), chromosome()
{
}
Individu::Individu(Instance* instance):instance(instance), satisfaction(0), empreinte_carbone(0), prix(0), duree_de_vie(0), chromosome()
{

}

Individu::~Individu()
{
}

void Individu::initialiser_aleatoirement()
{
	int option_choisie_a_un;
	
	for (int i = 0; i < instance->get_nb_parametres(); i++)
		chromosome.push_back(vector<int>());

	for (int i = 0; i < instance->get_nb_parametres(); i++)
	{
		for (int j = 0; j < instance->get_nb_options_of_parametre(i); j++)
			chromosome[i].push_back(0);

		option_choisie_a_un = random_int_between(0, instance->get_nb_options_of_parametre(i) - 1);
		chromosome[i][option_choisie_a_un] = 1;

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
	int option;
	double somme_note_options_a_un = 0;
	double note_max_par_critere = 0, note_max_par_parametere;
	double somme_satisfaction = 0;
	for (int c = 0; c < instance->get_nb_criteres(); c++)
	{
		for (int i = 0; i < chromosome.size(); i++)
		{
			//ajouter note de l'option a 1 du parametre i
			option = option_a_un_dun_parametre(i);
			somme_note_options_a_un += instance->get_note_parametre_option_critere(i, option, c);

			//calcul note max sur toutes les options du parametre i
			note_max_par_parametere = instance->get_note_parametre_option_critere(i, 0, c);
			for (int j = 1; j < chromosome[i].size(); j++)
			{
				if (instance->get_note_parametre_option_critere(i, j, c) > note_max_par_parametere)
					note_max_par_parametere = instance->get_note_parametre_option_critere(i, 0, c);
			}
			//ajouter cette note max
			note_max_par_critere += note_max_par_parametere;
		}
		//ajout du pourcentage de la satisfaction par rapport au critere c
		somme_satisfaction += somme_note_options_a_un / note_max_par_critere * 100;
	}
	this->satisfaction = somme_satisfaction;
}

void Individu::calculer_empreinte_carbone()
{
	int option;
	double somme_note_options_a_un_sur_ecologie = 0;
	double note_max_pour_ecologie = 0, note_max_par_parametere;
	//comme calcul de la satisfaction mais que sur le critere écologie
	for (int i = 0; i < chromosome.size(); i++)
	{
		//ajouter note de l'option a 1 du parametre i sur le critere écologie
		option = option_a_un_dun_parametre(i);
		somme_note_options_a_un_sur_ecologie += instance->get_note_parametre_option_critere(i, option, 1);

		//calcul note max sur toutes les options du parametre i sur écologie
		note_max_par_parametere = instance->get_note_parametre_option_critere(i, 0, 1);
		for (int j = 1; j < chromosome[i].size(); j++)
		{
			if (instance->get_note_parametre_option_critere(i, j, 1) > note_max_par_parametere)
				note_max_par_parametere = instance->get_note_parametre_option_critere(i, j, 1);
		}
		//ajouter cette note max
		note_max_pour_ecologie += note_max_par_parametere;
	}
	//ajout du pourcentage de la satisfaction par rapport au critere c
	this->empreinte_carbone = somme_note_options_a_un_sur_ecologie / note_max_pour_ecologie * 100;
}

void Individu::calculer_prix()
{
	//sommer sur les prix dependemment des options a 1
	int option;
	double facteur;
	vector<double> facteurs;
	double somme_prix = 0.0;
	for (int i = 0; i < chromosome.size(); i++)
	{
		option = option_a_un_dun_parametre(i);
		facteur = instance->get_facteur_parametre_option(i, option);
		if (facteur == 1)
			somme_prix += instance->get_prix_parametre_option(i, option);
		else
			facteurs.push_back(facteur);
	}
	for (int i = 0; i < facteurs.size(); i++)
		somme_prix *= facteurs[i];

	this->prix = somme_prix;
}

void Individu::calculer_duree_de_vie()
{
	int option;
	option = option_a_un_dun_parametre(0);

	double min_duree_vie = instance->get_duree_de_vie_parametre_option(0, option);
	//minimum des durees de vie sur les options a 1
	for (int i = 1; i < chromosome.size(); i++)
	{
		option = option_a_un_dun_parametre(i);
		if (instance->get_duree_de_vie_parametre_option(i, option) < min_duree_vie)
			min_duree_vie = instance->get_duree_de_vie_parametre_option(i, option);
	}

	this->duree_de_vie = min_duree_vie;
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

int Individu::option_a_un_dun_parametre(int i)
{
	if (i < 0 || i >= chromosome.size())
		throw invalid_argument("Attention!!!");

	for (int j = 0; j < chromosome[i].size(); j++)
		if (chromosome[i][j] == 1)
			return j;
	throw exception("Aucune option n'est a 1!!!!!!");
}

void Individu::into_texte_file(string file_name)
{
	ofstream file;
	file.open(file_name, ios::app);
	if (!file.is_open())
	{
		throw exception("Unable to open file ");
		cerr << "Unable to open file " << file_name << endl;
	}

	for (int i = 0; i < chromosome.size() -1; i++)
		file << option_a_un_dun_parametre(i) << ";";

	file << option_a_un_dun_parametre(chromosome.size() - 1);

	file << endl;
	file.close();
}

void Individu::afficher_individu()
{
	for (int i = 0; i < chromosome.size(); i++)
		cout << option_a_un_dun_parametre(i) + 1 << ";";

	string traduction_duree_vie;
	if (duree_de_vie == 0)
		traduction_duree_vie = "2 semaines";
	else
		if (duree_de_vie == 1)
			traduction_duree_vie = "2 ans";
		else
			traduction_duree_vie = "10 ans";
	cout <<endl<< "Satisfaction : " << satisfaction << "; " << "Prix : " << prix << "; " << "Duree de vie : " << traduction_duree_vie << "; " << "Empreinte Carbone : " << empreinte_carbone;
}

bool Individu::operator==(Individu autre_individu)
{
	for (int i = 0; i < chromosome.size(); i++)
		for (int j = 0; j < chromosome[i].size(); j++)
			if (chromosome[i][j] != autre_individu.chromosome[i][j])
				return false;
	return true;
}
