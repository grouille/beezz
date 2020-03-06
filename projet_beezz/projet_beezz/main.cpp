#include "AlgoGenetique.h"

int main()
{

	Instance instance("./parametres_INRIA.csv", "./data.txt");

	int nb_iterations = 50;
	double temps_max = 100;
	int nb_individus = 30;
	AlgoGenetique algo_genetique(&instance, nb_iterations, temps_max, nb_individus);
	system("pause");
	return 0;
}