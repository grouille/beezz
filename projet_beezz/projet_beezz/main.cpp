#include "AlgoGenetique.h"

int main()
{
	Instance instance("../../parametres_INRIA.csv", "../../data.txt");

	int nb_iterations = 1;
	double temps_max = 100;
	int nb_individus = 100;
	AlgoGenetique algo_genetique(&instance, nb_iterations, temps_max, nb_individus);
	algo_genetique.run();

	for (int i = 0; i < algo_genetique.best_individus.size(); i++)
	{
		algo_genetique.best_individus[i].afficher_individu();
		cout << endl;
	}

	system("pause");
	return 0;
}