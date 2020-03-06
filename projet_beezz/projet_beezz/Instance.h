#ifndef INSTANCE_H
#define INSTANCE_H

#pragma once
#include <iostream>

using namespace std;

class Instance
{
public:
	Instance(string file_name);
	~Instance();

	void lire_instance_a_partir_dun_fichier_csv();


};

#endif

