#include "AlgoGenetique.h"
#include <chrono>
int main()
{
	Instance instance("../../parametres_INRIA.csv", "../../data.txt");

	int nb_iterations = 500;
	double temps_max = 100;
	int nb_individus = 150;
	AlgoGenetique algo_genetique(&instance, nb_iterations, temps_max, nb_individus);
	chrono::milliseconds _chronoStart = chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch());
	algo_genetique.run();
	chrono::milliseconds _chronoEnd = chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch());
	chrono::milliseconds _chrono = _chronoEnd - _chronoStart;
	cout << "L'algorithme a pris\t | " << float(_chrono.count()) / 1000 << " sec |" << endl << endl;
	string file_name = "../../solutions.txt";
	ofstream solutions;
	for (int i = 0; i < algo_genetique.best_individus.size(); i++)
	{
		algo_genetique.best_individus[i].afficher_individu();
		cout << endl;
		algo_genetique.best_individus[i].into_texte_file(file_name);
	}
	solutions.close();
	return 0;
}