#ifndef INSTANCE_H
#define INSTANCE_H

#pragma once
#include <iostream>
#include<vector>

using namespace std;

class Instance
{
public:
	int nb_parameter;
	vector<int> nb_option_par_parameter;
public:
	Instance(string file_name);
	~Instance();

	//setter methods
	void lire_instance_a_partir_dun_fichier_csv();


	//getter methods
	int get_nb_options_of_parametr(int i);
	int get_note_parameter_option(int i, int j);


};

#endif

