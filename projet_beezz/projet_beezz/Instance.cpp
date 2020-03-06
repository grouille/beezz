#include "Instance.h"
#include "Instance.h"

Instance::Instance(string file_name)
{
}

Instance::~Instance()
{
}

void Instance::lire_instance_a_partir_dun_fichier_csv()
{
}

int Instance::get_nb_options_of_parametre(int i)
{
	if (i < 0 || i >= nb_parametres)
		throw invalid_argument("Attention!!!");
	return nb_options_par_parametre[i];
}

double Instance::get_note_parametre_option_critere(int i, int j, int c)
{
	if (i < 0 || i >= nb_parametres ||
		j < 0 || j >= get_nb_options_of_parametre(i) ||
		c < 0 || c >= nb_criteres)
		throw invalid_argument("Attention!!!");
	return valeur_parametre_option_critere[i][j][c];
}

double Instance::get_prix_parametre_option(int i, int j)
{
	if (i < 0 || i >= nb_parametres ||
		j < 0 || j >= get_nb_options_of_parametre(i))
		throw invalid_argument("Attention!!!");
	return valeur_parametre_option_critere[i][j][6];
}

double Instance::get_facteur_parametre_option(int i, int j)
{
	if (i < 0 || i >= nb_parametres ||
		j < 0 || j >= get_nb_options_of_parametre(i))
		throw invalid_argument("Attention!!!");
	return valeur_parametre_option_critere[i][j][7];
}

double Instance::get_duree_de_vie_parametre_option(int i, int j)
{
	if (i < 0 || i >= nb_parametres ||
		j < 0 || j >= get_nb_options_of_parametre(i))
		throw invalid_argument("Attention!!!");
	return valeur_parametre_option_critere[i][j][8];
}

int Instance::get_souhait_client_pour_critere(int c)
{

	if (c < 0 || c >= nb_criteres)
		throw invalid_argument("Attention!!!");
	return souhait_critere[c];
}

int Instance::get_nb_parametres()
{
	return nb_parametres;
}

int Instance::get_nb_criteres()
{
	return nb_criteres;
}

int Instance::get_nb_prix_max()
{
	return prix_max;
}

int Instance::get_duree_de_vie_minimale()
{
	return duree_de_vie_minimale;
}
