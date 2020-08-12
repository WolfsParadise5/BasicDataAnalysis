#include <iostream>
#include <algorithm> //to user remove function
#include <fstream> //to open the csv file
#include <sstream>
#include <cstdlib> //use system function
#include <string> //use string functions
#include <limits> //to use numeric_limit function
#include <vector>

using namespace std;

class Data
{
public:
    //functions
    void loadFile(string filename);//open file
    void loadData(string filename);//assign each data to variable
    bool checkFormat(ifstream &file);//check header of the csv file
    bool isNumber(string line);
    void printData();
    ~Data()
    {
        file.close();
        delete filename;
    }
private:
    string *filename;//point to filename variable
    ifstream file; //to load the csv file
    int column, row; //read the value of column and row from the csv file
    vector<string> name; // store header names
    vector<vector<string> > data;//2d array to store all the data
};

//function prototypes
void mainMenu();
void enterFileName();

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
        cout << "1.)Load the file" << endl;
        cout << "2.)Exit" <<  endl;
        cout << "Please enter the number: ";
        cin >> choice;
        if(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); //prevent infinite loop when user entered character/string
        }
    }while((choice < 1 || choice > 2) && printf("Invalid input, please try again.\n"));
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
    Data data;
    cout << "Please enter your file name including extension\n(Enter 999 return to main menu).\n->";
    cin >> filename;
    if(filename == "999")
        mainMenu();
    else
        data.loadFile(filename);
}
void Data::loadFile(string filename)
{
    Data::filename = &filename;
    file.open(filename.c_str()); //convert filename

    if(!file.is_open())
    {
        cout << "File is not open, please check your file name again." << endl;
        enterFileName();
    }else
    {
        if(checkFormat(file))
        {
            loadData(filename);
            printData();
        }else
        {
            cout << "Format Error, please check your file" << endl;
        }
        mainMenu();
    }
}
bool Data::isNumber(string line)
{
    bool number = true;
    for(int i = 0; i < line.length(); i++)
    {
        if(isdigit(line[i]) == false)
            number = false;
    }
    return number;
}
bool Data::checkFormat(ifstream &file)
{
    string line;//to store the string from csv temporally
    bool format = true;
    getline(file, line);//get first line
    line.erase(remove(line.begin(), line.end(), ' '), line.end());//remove spaces
    if(!isNumber(line))
    {
        format = false;
        cout << "ERROR: Undefined column value" << endl;
    }
    column = atoi(line.c_str());//convert string to int, store into int column
    getline(file, line);
    int count = 0;
    for(int i = 0; i < line.length(); i++)//count how many comma on line 3
    {
        if(line[i] == ',')
            count++;
    }
    if(count != (column - 1))//check if the number of titles is not match to column
    {
        format = false;
        cout << "ERROR: Column does not match to the number of titles" << endl;
    }
    getline(file, line);//get the thid line
    line.erase(remove(line.begin(), line.end(), ' '), line.end());//remove spaces
    if(!isNumber(line))
    {
        format = false;
        cout << "ERROR: Undefined row value" << endl;
    }
    row = atoi(line.c_str());//convert string to int, store into int row
    file.close();
    return format;
}
void Data::loadData(string filename)
{
    file.open(filename.c_str());
    string line; //to store the string from csv temporally
    getline(file, line);//skip the first line string
    for(int i = 0; i < column; i++)
    {
        if(i == column - 1){//to detect the last word of the line to prevent get next line of the string
            getline(file, line);
            line.erase(remove(line.begin(), line.end(), ' '), line.end()); //remove spaces after last characters
            name.push_back(line);
        }else{
            getline(file, line, ',');
            name.push_back(line);
        }
    }
    getline(file, line);//skip the third line
    while(getline(file, line))
    {
        stringstream ss(line);
        vector<string> temp;//to store one row of data temporally
        for(int i = 0; i < name.size(); i++)
        {
            getline(ss, line, ',');
            line.erase(remove(line.begin(), line.end(), ' '), line.end());//remove spaces
            temp.push_back(line);
        }
        data.push_back(temp);//put it back to 2d vector
    }
    cout << "File loaded." << endl;
}
void Data::printData(){
    cout << "File name: " << *filename << endl;//get pointer value
    cout << "Column: " << column << endl;
    cout << "Row: " << row<< endl;
    for(int i = 0; i < data.size(); i++){
        cout << i + 1 << ".)";
        for(int j = 0; j < name.size(); j++)
            cout << name[j] << ": " << data[i][j] << " ";
        cout << endl;
    }
}
