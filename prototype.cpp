#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <iomanip>

using namespace std;

class Data
{
public:

private:

};

//function prototypes
void mainMenu();
void enterFileName();
void loadFile(string filename);
void printFile(ifstream &file);

int main()
{
    mainMenu();

    system("PAUSE");
}

void mainMenu()
{
    int choice;
    do
    {
        if(choice < 1 || choice > 2) cout << "invalid input, please try again." <<endl;
        cout << "1.)Load the file" << endl;
        cout << "2.)Exit" <<  endl;
        cout << "Please enter the number: ";
        cin >> choice;
    }while(choice < 1 || choice > 2);
    switch(choice)
    {
        case 1:
            enterFileName();
            break;
        case 2:
            exit(0);
            break;
        default:
            cout << "ERROR"; exit(0);
    }
}
void enterFileName(){
    string filename;
    cout << "Please enter your file name including extension.\n->";
    cin >> filename;
    loadFile(filename);
}
void loadFile(string filename)
{
    //filename = "data.txt"; //test
    ifstream file; //create ifstream object
    file.open(filename.c_str()); //convert filename

    if(!file.is_open())
    {
        cout << "File is not open, please check your file name again." << endl;
        enterFileName();
    }else
    {
        printFile(file);
    }
}
void printFile(ifstream &file)
{
    int col, count = 0;
    string column, rows, line;

    getline(file, column);
    col = atoi(column.c_str()); //convert string to int
    string row[col];
    string name[col];

    cout << "Column: " << col << endl;

    for(int i = 0; i < col; i++)
    {
        if(i == col - 1)
            getline(file, name[i]);
        else
            getline(file, name[i], ',');
    }
    getline(file, rows);
    cout << "Row: " << rows;
    while(getline(file, line))
    {
        stringstream ss(line);
        count++;
        cout << "(" << count << ") ";
        for(int i = 0; i < col; i++)
        {
            getline(ss, row[i], ',');
            cout << name[i] << ": " <<row[i] << endl;
        }
        cout << endl;
    }
}
