#include <iostream>
#include <algorithm> //to use remove
#include <limits> //to numeric_limits function
#include <sstream> //use string stream to separate comma
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

//class functions
class File
{
    public:
        File();
        ~File();
        void loadFileCsv(const string &filename);//open file
        void loadData(ifstream &filename);//assign each data to variable
        bool checkFormat(ifstream &file);//check header of the csv file
        bool isNumber(string line);//check if the string contains only number
        int checkColumn(string line);//check num of columns
        void printData();
        void display2dTable(const vector<vector<int>> &data, const vector<string> &headers, const int &width);
        void convertData(vector<vector<string> > &data, int column);
        //return types
        bool isFileOpen(){return file.is_open();}
        string getFilename(){return filename;}
        vector<string> getHeader(){return name;}
        vector<vector<string> > getData(){return data;}
        vector<vector<int> > getDataInt(){return dataInt;}
        bool getFormat(){return format;}
        int getColumn(){return column;}
        int getRow(){return row;}
        vector<int> get1dData(const vector<vector<int> > &data, const int &choice);
    private:
        string filename;//point to filename variable
        bool format; //store the result of format checking
        ifstream file; //to load the csv file
        int column, row; //read the value of column and row from the csv file
        vector<string> name; // store header names
        vector<vector<string> > data;//2d array to store all the data
        vector<vector<int> > dataInt;//convert data to int for calculation
};

//code
File::File()
{
    format = true;//assume format is correct first
}
File::~File()
{
    file.close();
}
void File::loadFileCsv(const string &filename)
{
    file.open(filename.c_str()); //convert filename
    if(!file.is_open())
    {
        cout << "File is not open, please check your file name again." << endl;
    }else
    {
        File::filename = filename;//store file name
        if(checkFormat(file))
        {
            loadData(file);
            convertData(data, column);
            //printData();
        }else
            cout << "Format Error, please check your file" << endl;
    }
}
bool File::checkFormat(ifstream &file)
{
    string line;//to store the a line of string from file temporally
    getline(file, line);//get first line
    if(!isNumber(line))//check if the string contain only integer
    {
        format = false;
        cout << "ERROR: Undefined column value" << endl;
    }
    else
    {
        column = atoi(line.c_str());//convert string to int, store into int column
        getline(file, line);//get second line

        if(checkColumn(line) != column)//check if the number of titles is not match to column
        {
            format = false;
            cout << "ERROR: Column does not match to the number of titles" << endl;
        }
        else
        {
            getline(file, line);//get the third line
            if(!isNumber(line))
            {
                format = false;
                cout << "ERROR: Undefined row value" << endl;
            }
            else
            {
                row = atoi(line.c_str());//convert string to int, store into int row
                int countRow = 1;//to get the current row
                while(getline(file, line))//check the rest of the row
                {
                    if(checkColumn(line)!= (column))//perform check column for each row
                    {
                        format = false;
                        cout << "ERROR: Data Column does not match to the number of titles at line " << countRow + 3 << endl;//add 3 rows because of headers
                    }
                    countRow++;
                }
                if(countRow - 1 != row)//check number of rows match to header setting
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
    string line; //to store the string from file temporally
    file.ignore(numeric_limits<streamsize>::max(), '\n');//skip a line

    getline(file, line); //read line 3, header names
    stringstream ss(line);//use to separate comma
    for(int i = 0; i < column; ++i)
    {
        getline(ss, line, ',');
        line.erase(remove(line.begin(), line.end(), ' '), line.end());
        name.push_back(line);
    }
    file.ignore(numeric_limits<streamsize>::max(), '\n');//skip a line
    while(getline(file, line))
    {
        stringstream ss(line);
        vector<string> temp;//to store one row of data temporally
        for(int i = 0; i < name.size(); ++i)
        {
            getline(ss, line, ',');
            line.erase(remove(line.begin(), line.end(), ' '), line.end());
            temp.push_back(line);
        }
        data.push_back(temp);//put it back to 2d vector
    }
    system("cls||clear");
    cout << "File loaded." << endl;
}

int File::checkColumn(string line)
{
    int count = 0;
    for(int i = 0; i < line.length(); ++i)//count how many comma on line 3
    {
        if(line[i] == ',')
            count++;
    }
    return count + 1; //add 1, eg Id,Age,Math,Science,Malay have 4 comma which means it have 5 columns
}

bool File::isNumber(string line)
{
    bool number = true;
    line.erase(remove(line.begin(), line.end(), ' '), line.end());//remove spaces
    for(int i = 0; i < line.length(); ++i)
    {
        if(isdigit(line[i]) == false)//detect each character
            number = false;
    }
    return number;
}

void File::convertData(vector<vector<string> >&data, int column)
{
    vector<vector<string> > tempData = data;
    for(int i = 0; i < data.size(); ++i)
    {
        vector<int>temp;//store a row of vector temporally
        for(int j = 0; j < column; ++j)
        {
            temp.push_back(atoi(tempData[i][j].c_str()));//convert string to int and add to temp vector
        }
        dataInt.push_back(temp);
    }
}
void File::printData()
{
    cout << "File name: " << filename << endl;
    cout << "Column: " << column << endl;
    cout << "Row: " << row<< endl;
//
//    for(int dataRow = 0; dataRow < dataInt.size(); ++dataRow)
//    {
//        cout << dataRow + 1 << ".)";
//
//        for(int dataColumn = 0; dataColumn < name.size(); ++dataColumn)
//            cout << name[dataColumn] << ": " << dataInt[dataRow][dataColumn]<< " ";
//
//        cout << endl;
//    }
    display2dTable(dataInt, name, 9);
}
vector<int> File::get1dData(const vector<vector<int> > &data, const int &choice)
{
    vector<int> vec;

    for(int i = 0; i < data.size(); ++i)
    {
        vec.push_back(data[i][choice]);
    }

    return vec;
}
void File::display2dTable(const vector<vector<int> > &data, const vector<string> &headers, const int &width)
{
    int numFields = headers.size();
    string seperator = " |";
    int totalWidth = (width * numFields) + seperator.size() * (numFields + 1) + 5;
    string line = seperator + string(totalWidth - 1, '-') + "|";

    //print table headers
    cout << line << endl;
    cout << seperator;
    cout << setw(5) << "No." << seperator;
    for(int i = 0; i < headers.size(); ++i)
        cout << setw(width) << headers[i] << seperator;
    cout << endl << line << endl;

    //print table body
    for(int i = 0; i < data.size(); ++i)
    {
        cout << seperator;
        cout << setw(5) << i + 1 << seperator;
        for(int j = 0; j < headers.size(); ++j)
            cout << setw(width) << data[i][j] << seperator;
        cout << endl;
    }

    cout << line << endl;
}
