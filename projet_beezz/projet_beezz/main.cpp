#include "AlgoGenetique.h"

int main()
{
	Instance instance("../../parametres_INRIA.csv", "../../data.txt");

	int nb_iterations = 500;
	double temps_max = 100;
	int nb_individus = 150;
	AlgoGenetique algo_genetique(&instance, nb_iterations, temps_max, nb_individus);
	algo_genetique.run();

	string file_name = "../../solutions.txt";
	ofstream solutions;
	for (int i = 0; i < algo_genetique.best_individus.size(); i++)
	{
		algo_genetique.best_individus[i].afficher_individu();
		cout << endl;
		algo_genetique.best_individus[i].into_texte_file(file_name);
	}
	solutions.close();
	system("pause");
	return 0;
}