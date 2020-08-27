/*
    NOTE:
    HOW TO USE File CLASS
    - INCLUDE File.h first, #include "File.h"
    - USE loadFileCsv() to load file into array e.g. loadFileCsv("data.csv")
    - USE isFileOpen() to check if the file is open successfully

    e.g USING LOOP TO ENTER FILENAME IF FILE IS NOT OPEN
    //////////////////////////////////////
    File data; //create object
    string filename;
    cin.ignore();
    do
    {
        cout << "Please enter your file name.\n->";

        getline(cin, filename);
        data.loadFileCsv(filename);

    }while(data.isFileOpen() == false);
    //////////////////////////////////////
    - USE getHeader() to get header names
    - USE getData() for string type of data, getDataInt() for int type of data
    - USE printData() simply print all data
    - check return types function for more////
*/
#include <iostream>
#include <algorithm> //to use remove function
#include <sstream> //use string stream to separate comma
#include <string>
#include <fstream>
#include <vector>

using namespace std;

//class functions
class File
{
    public:
        File();
        ~File();
        void loadFileCsv(string filename);//open file
        void loadData(ifstream &filename);//assign each data to variable
        bool checkFormat(ifstream &file);//check header of the csv file
        bool isNumber(string line);
        void printData();
        void convertData(vector<vector<string> > &data, int column);
        int checkColumn(string line);
        //return types
        bool isFileOpen(){return open;}
        bool isFileLoad(){return load;}
        string getFilename(){return filename;}
        vector<string> getHeader(){return name;}
        vector<vector<string> > getData(){return data;}
        vector<vector<int> > getDataInt(){return dataInt;}
        int getColumn(){return column;}
        int getRow(){return row;}
    private:
        string filename;//point to filename variable
        ifstream file; //to load the csv file
        int column, row; //read the value of column and row from the csv file
        vector<string> name; // store header names
        vector<vector<string> > data;//2d array to store all the data
        vector<vector<int> > dataInt;//convert data to int for calculation
        bool open, load;
};

//code
File::File()
{
    open = load = false;
}
File::~File()
{
    file.close();
}
void File::loadFileCsv(string filename)
{

    file.open(filename.c_str()); //convert filename
    if(!file.is_open())
    {
        cout << "File is not open, please check your file name again." << endl;
        open = false;
    }else
    {
        File::filename = filename;//store file name
        if(checkFormat(file))
        {
            loadData(file);
            convertData(data, column);
            //printData();
            open = true;
        }else
            cout << "Format Error, please check your file" << endl;
    }
}
bool File::checkFormat(ifstream &file)
{
    string line;//to store the a line of string from file temporally
    bool format = true;//assume format is correct first
    getline(file, line);//get first line
    line.erase(remove(line.begin(), line.end(), ' '), line.end());//remove spaces
    if(!isNumber(line))//check if the string contain only integer
    {
        format = false;
        cout << "ERROR: Undefined column value" << endl;
    }
    else
    {
        column = atoi(line.c_str());//convert string to int, store into int column
        getline(file, line);//get second line
        int countColumn;//use to store number of columns for checking

        countColumn = checkColumn(line);//get number of columns store into countColumn
        if(countColumn != column)//check if the number of titles is not match to column
        {
            format = false;
            cout << "ERROR: Column does not match to the number of titles" << endl;
        }
        else
        {
            getline(file, line);//get the third line
            line.erase(remove(line.begin(), line.end(), ' '), line.end());//remove spaces
            if(!isNumber(line))
            {
                format = false;
                cout << "ERROR: Undefined row value" << endl;
            }
            else
            {
                row = atoi(line.c_str());//convert string to int, store into int row
                int countRow = 0;//to get the current row
                while(getline(file, line))//check the rest of the row
                {
                    countColumn = checkColumn(line);
                    if(countColumn != (column))//perform check column for each row
                    {
                        format = false;
                        cout << "ERROR: Data Column does not match to the number of titles at line: " << countRow + 4 /*Skip 3 rows + 1*/ << endl;
                    }
                    countRow++;
                }
                if(countRow != row)//check number of rows match to header setting
                {
                    format = false;
                    cout << "ERROR: Row does not match to the total number of data" << endl;
                }
            }
        }
    }
    return format;
}

void File::loadData(ifstream &file)
{
    file.clear();//remove error flag
    file.seekg(0, file.beg);//point back to first line
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
    getline(file, line);//skip line 3
    while(getline(file, line))
    {
        stringstream ss(line);//use to separate each string till comma
        vector<string> temp;//to store one row of data temporally
        for(int i = 0; i < name.size(); i++)
        {
            getline(ss, line, ',');
            line.erase(remove(line.begin(), line.end(), ' '), line.end());//remove spaces
            temp.push_back(line);
        }
        data.push_back(temp);//put it back to 2d vector
    }
    system("CLS");
    cout << "File loaded." << endl;
    load = true;//file loaded successfully
}

int File::checkColumn(string line)
{
    int count = 0;
    for(int i = 0; i < line.length(); i++)//count how many comma on line 3
    {
        if(line[i] == ',')
            count++;
    }
    return count + 1; //add 1, eg Id,Age,Math,Science,Malay have 4 comma which means it have 5 columns
}

bool File::isNumber(string line)
{
    bool number = true;
    for(int i = 0; i < line.length(); i++)
    {
        if(isdigit(line[i]) == false)//detect each character
            number = false;
    }
    return number;
}

void File::convertData(vector<vector<string> > &data, int column)
{
    for(int i = 0; i < data.size(); i++)
    {
        vector<int>temp;//store a row of vector temporally
        for(int j = 0; j < column; j++)
        {
            temp.push_back(atoi(data[i][j].c_str()));//convert string to int and add to temp vector
        }
        dataInt.push_back(temp);
    }
}

void File::printData()
{
    cout << "File name: " << filename << endl;
    cout << "Column: " << column << endl;
    cout << "Row: " << row<< endl;

    for(int dataRow = 0; dataRow < dataInt.size(); dataRow++)
    {
        cout << dataRow + 1 << ".)";

        for(int dataColumn = 0; dataColumn < name.size(); dataColumn++)
            cout << name[dataColumn] << ": " << dataInt[dataRow][dataColumn]<< " ";

        cout << endl;
    }
}
