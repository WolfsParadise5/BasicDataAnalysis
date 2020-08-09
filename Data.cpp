#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int main(){
    ifstream myFile("main.txt");
    if (!myFile.is_open()){
        cout << "File failed to open, try again" << endl;
        return 0;
    }

    string id, age, maths, science, malay;
    string myString;
    string line;

    while(getline(myFile, line)){
        stringstream ss(line);
        getline(ss, id, ',');
        getline(ss, age, ',');
        getline(ss, maths, ',');
        getline(ss, science, ',');
        getline(ss, malay, ',');

        cout << "Id : " << id << endl;
        cout << "Age : " << age << endl;
        cout << "Maths : " << maths << endl;
        cout << "Science : " << science << endl;
        cout << "Malay : " << malay << endl;
    }
     myFile.close();

    }

