#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

vector<string> split(string str, string token){
    vector<string>result;
    while(str.size()){
        double index = str.find(token);
        if(index!=string::npos){
            result.push_back(str.substr(0,index));
            str = str.substr(index+token.size());
            if(str.size()==0)result.push_back(str);
        }else{
            result.push_back(str);
            str = "";
        }
    }
    return result;
}

vector<vector<vector<double> > > creation_matrice_donnees() {
    ifstream file ("parametres_INRIA.csv");
    int parametre = 1, option = 3;
    string cell;
    vector<string> ligne;
    vector<vector<vector<double> > > tab;
    getline(file, cell);
    getline(file, cell);
    ligne = split(cell, ",");

    while(ligne[3]!="") {

        if (ligne[1] != "") {
            vector<vector<double> > vect_of_vect;
            tab.push_back(vect_of_vect);
        }
        vector<double> vect_of_double;
        tab.back().push_back(vect_of_double);
        for(int i=1; i<7; i++) {
            double value;
            istringstream iss(ligne[option+i]);
            iss >> value;
            tab.back().back().push_back(value);
        }
        for(int i=8; i<11; i++) {
            double value;
            istringstream iss(ligne[option+i]);
            iss >> value;
            tab.back().back().push_back(value);
        }

        getline(file, cell);
        ligne = split(cell, ",");
    }

    return tab;
}

