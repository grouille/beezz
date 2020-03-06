#ifndef INSTANCE_H
#define INSTANCE_H

#pragma once
#include <iostream>
#include<vector>

using namespace std;

class Instance
{
public:
	int nb_parametres;
	int nb_criteres;
	vector<int> nb_options_par_parametre;
	vector<vector<vector<double>>> valeur_parametre_option_critere;
	vector<int> souhait_critere;
	int prix_max;
	int duree_de_vie_minimale;
	double seuil_ecolo;

public:
	Instance(string file_name);
	~Instance();

	//setter methods
	void lire_instance_a_partir_dun_fichier_csv(string file_name);


	//getter methods
<<<<<<< HEAD
	int get_nb_options_of_parametr(int i);
=======
	int get_nb_options_of_parametre(int i);
	double get_note_parametre_option_critere(int i, int j, int c);
	double get_prix_parametre_option(int i, int j);
	double get_facteur_parametre_option(int i, int j);
	double get_duree_de_vie_parametre_option(int i, int j);
>>>>>>> branch 'master' of https://github.com/grouille/beezz.git

	int get_souhait_client_pour_critere(int c);

	int get_nb_parametres();
	int get_nb_criteres();
	int get_nb_prix_max();
	int get_duree_de_vie_minimale();

};

#endif

