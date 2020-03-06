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

    for(int i=0; i < (int)tab.size(); i++) {
        for(int j=0; j < (int)tab[i].size(); j++) {
            cout << "Parametre " << i+1 << " option " << j+1 << " : ";
            for(int k=0; k < (int)tab[i][j].size(); k++) {
                cout << tab[i][j][k] << " ";
            }
        cout << endl;
        }
    }
}

/*
    Book* book = xlCreateXMLBook();

    if(book->load("parametres_INRIA.xlsx")) {
        Sheet* sheet = book->getSheet(1);

        if(sheet) {
            int row=1, column=1;
            int parametre = 1, option = 3;
            vector<vector<vector<int> > > tab;

            while(sheet->readStr(row, option) != NULL) {
                if (sheet->readStr(row, parametre) != NULL) {
                    vector<vector<int> > vect_of_vect;
                    tab.push_back(vect_of_vect);
                }
                vector<int> vect_of_int;
                tab.back().push_back(vect_of_int);
                for(int i=1; i<7; i++) {
                    if (sheet->readNum(row, option+i))
                        tab.back().back().push_back((int)(sheet->readNum(row, option+i)));
                }
                //tab.back().back().push_back((int)(sheet->readNum(row, 11)));
                row ++;
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

         for(int row = sheet->firstRow(); row < sheet->lastRow(); ++row)
         {
            for(int col = sheet->firstCol(); col < sheet->lastCol(); ++col)
            {
               CellType cellType = sheet->cellType(row, col);
               std::wcout << "(" << row << ", " << col << ") = ";
               if(sheet->isFormula(row, col))
               {
                  const wchar_t* s = sheet->readFormula(row, col);
                  std::wcout << (s ? s : L"null") << " [formula]";
               }
               else
               {
                  switch(cellType)
                  {
                     case CELLTYPE_EMPTY: std::wcout << "[empty]"; break;
                     case CELLTYPE_NUMBER:
                     {
                        double d = sheet->readNum(row, col);
                        std::wcout << d << " [number]";
                        break;
                     }
                     case CELLTYPE_STRING:
                     {
                        const wchar_t* s = sheet->readStr(row, col);
                        std::wcout << (s ? s : L"null") << " [string]";
                        break;
                     }
                     case CELLTYPE_BOOLEAN:
                     {
                        bool b = sheet->readBool(row, col);
                        std::wcout << (b ? "true" : "false") << " [boolean]";
                        break;
                     }
                     case CELLTYPE_BLANK: std::wcout << "[blank]"; break;
                     case CELLTYPE_ERROR: std::wcout << "[error]"; break;
                  }
               }
               std::wcout << std::endl;
            }
         }
        }
    }
    else {
        cout << "erreur ouverture fichier" << endl;
    }
    book->release();
    return 0;
}
*/
