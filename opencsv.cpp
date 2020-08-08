//source:https://www.youtube.com/watch?v=da8prmVYul8
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int columns, columnIterate = 0;
    ifstream dataFile;
    dataFile.open("file.txt");

    while(dataFile.good()) {
        string line;
        getline(dataFile, line, ' ');
        cout << line << endl;
    }
}
