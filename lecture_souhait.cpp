#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int main()
{
        ifstream fichier("data.txt", ios::in);  // on ouvre le fichier en lecture
        if(fichier)  // si l'ouverture a réussi
        {
            // instructions
            string chaine;
            vector<int> result;
            int number;
            while(getline(fichier, chaine))
            {
                istringstream iss(chaine);
                iss >> number;
                result.push_back(number);
            }
            fichier.close();  // on ferme le fichier
        }
        else  // sinon
            cerr << "Impossible d'ouvrir le fichier !" << endl;
        return 0;
}
