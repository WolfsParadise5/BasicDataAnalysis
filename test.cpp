//reference : https://www.youtube.com/watch?v=wRj9PZ2wyZI
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream dataFile ("data.txt"); //input/read the file

    if (!dataFile)
    {
        cout << "Unable to open file" << endl;

    } // if there is an invalid file, unable to open

    //variables
    string heading;
    string id;
    string age;
    string maths;
    string science;
    string malay;

    getline(dataFile,heading, '\n');
    cout << heading << endl;
    cout << "                   "<< endl;

   while(dataFile.good()) {

        getline(dataFile, id, ',');
        getline(dataFile, age, ',');
        getline(dataFile, maths, ',');
        getline(dataFile, science, ',');
        getline(dataFile, malay, '\n'); //end line to look for new row

        cout << "Id : " << id << endl;
        cout << "Age : " << age << endl;
        cout << "Maths : " << maths << endl;
        cout << "Science : " << science << endl;
        cout << "Malay : " << malay << endl;
        cout << "                " << endl;
    }

    dataFile.close();
     return 0;
}








