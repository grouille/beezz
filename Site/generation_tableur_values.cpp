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

int main() {
    ifstream file_in ("parametres_INRIA.csv");
    ofstream file_out ("values.csv");

    string cell;
    vector<string> ligne;
    getline(file_in, cell);
    getline(file_in, cell);
    ligne = split(cell, ",");

    while(ligne[3]!="") {
        if (ligne[1]!="")
            file_out << "P;" << ligne[1] << endl;
        file_out << "O;" << ligne[3] << ";" << ligne[11] << ";" << ligne[12] << ";" << ligne[13] << ";" << ligne[5] << ";" << ligne[4] << ";" << ligne[6] << ";" << ligne[7] << ";" << ligne[8] << ";" << ligne[9] << endl;

        getline(file_in, cell);
        ligne = split(cell, ",");
    }

    return 0;
}

/*
void lecture_fichier(string file_name) {
    ifstream file (file_name);
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

    for(int i=0; i < (int)tab.size(); i++) {
        for(int j=0; j < (int)tab[i].size(); j++) {
            cout << "Parametre " << i+1 << " option " << j+1 << " : ";
            for(int k=0; k < (int)tab[i][j].size(); k++) {
                cout << tab[i][j][k] << " ";
            }
        cout << endl;
        }
    }
}*/
