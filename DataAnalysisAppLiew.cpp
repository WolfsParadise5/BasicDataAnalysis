//
// TCP1101 Assignment
// Trimester 1, 2020/2021
// by <<Liew Jiann Shen>>
// Team Leader: Liew Jiann Shen, 017-4922881, 1191100556@student.mmu.edu.my
// Team members:
// Fong Zheng Wei, 012-322 9588, 1191100350@student.mmu.edu.my
// Nagaindran, 011-2356 9102, 1191100776@student.mmu.edu.my
// Wong Chun Gee, +673 8358615, 1201301759@student.mmu.edu.my
//

#include <iostream>
#include <algorithm> //to use remove, min and max
#include <limits> //numeric_limits function
#include <sstream> //use string stream to separate comma
#include <fstream>
#include <vector>
#include <cctype>
#include <cstdlib>
#include <iomanip>
#include <cmath>    //sqrt
#include <numeric> //sorting function

using namespace std;

//Classes
class File
{
    public:
        File();
        ~File();
        void loadFileCsv(string filename);//open file
        void loadData(ifstream &filename);//assign each data to variable
        bool checkFormat(ifstream &file);//check header of the csv file
        bool isNumber(string line);//check if the string contains only number
        int checkColumn(string line);//check num of columns
        void printData();
        void display2dTable(const vector<vector<int>> &data, const vector<string> &headers, int width);
        void convertData(const vector<vector<string> > &data, int column);
        //return types
        bool isFileOpen(){return file.is_open();}
        string getFilename(){return filename;}
        vector<string> getHeader(){return name;}
        vector<vector<string> > getData(){return data;}
        vector<vector<int> > getDataInt(){return dataInt;}
        bool getFormat(){return format;}
        int getColumn(){return column;}
        int getRow(){return row;}
        vector<int> get1dData(int choice);
    private:
        string filename;//point to filename variable
        bool format; //store the result of format checking
        ifstream file; //to load the csv file
        int column, row; //read the value of column and row from the csv file
        vector<string> name; // store header names
        vector<vector<string> > data;//2d array to store all the data
        vector<vector<int> > dataInt;//convert data to int for calculation
};
class Menu
{
    public:
        Menu();
        ~Menu();
        //menu and get input
        void title(string title);
        void mainMenu();
        int getChoice(int max);
        bool getDisplay(int max);
        //main menu
        void loadFile();
        void computeStats();
        void report();
        //compute stats
        void displayMaxMin(int width, bool maxMin); //true for max, false for min
        void displayMedian(int width);
        void displayMean(int width);
        void displayVar(int width);
        void displayStdDev();
        void displayFrequency();
        void displayHistogram();
        void displayTablesMean();
        //selects
        void displayHeaders(const vector<string> &headers, int startFrom);
        int selectCol(const vector<string> &headers, string subTitle, int startFrom);
        void select2Col(const vector<string> &headers);
        void selectLinearCorrel(const vector<int> &column1, const vector<int> &column2, string subject1, string subject2);
        //report
        void preview();
        void generateReport();//select txt or html
        //select data
        void selectReport(bool isTxt);//select everything
        void computeReport(const vector<bool> &display, vector<string> &getStats, vector<double> &getResult, int sub1, const vector<int> &sub2);
        vector<bool> selectDisplay();
        int getSub();//select 1 sub
        vector<int> get2Sub();//select 2 subs
        void selectSort(bool ascDesc);
        void sorting(const vector<vector<int>> &data, const vector<string>headers, int choice, bool ascDesc);
    private:
        File *dataPtr;//point to latest file and share to all function
};

//function prototypes
//tables
void displayColumn(const vector<vector<int> > &data, const vector<string> &headers, string &line, int width);//for min, max, ....
//minimum
int minimum(const vector<int> &column);
//maximum
int maximum(const vector<int> &column);
//median
double median(const vector<int> &column);
//mean
double mean(const vector<int> &column);
int getSum(const vector<int> &column);
//variance
double variance(const vector<int> &column);
double varianceSum(const vector<int> &column);//calculate sum for variance
//std deviation
double standardDeviation(const vector<int> &column);
//Frequency Table
void frequency(const vector <int>&value);
//Histogram
vector<int> getHistoVal(const vector <int>&value);//count marks
void histogram (const vector <int>&value);
//tables above and below mean
vector<vector<int>> aboveBelow(const vector<vector<int>> &data, double mean, int choice, bool isBelow); //true = below, false = above
//Linear
int sum(const vector<int> &column);//sum all values
int sumMultiplication(const vector<int> &column1, const vector<int> &column2);//sum of multiplication
double slope(const vector<int> &column1, const vector<int> &column2);
double intercept(const vector<int> &column1, const vector<int> &column2, double slope);
void displayLinearTable(const vector<int> &column1, const vector<int> &column2, string subject1, string subject2, int width);
void slopeStep(const vector<int> &column1, const vector<int> &column2);//show steps of slope calculation
void interceptStep(const vector<int> &column1, const vector<int> &column2, double slope);//show steps of intercept calculation
void linearRegression(const vector<int> &column1, const vector<int> &column2, string subject1, string subject2);//combine everything

//Correlation
void correlation(const vector<int> &column1, const vector<int> &column2, string subject1, string subject2);//combine everything
double getCorrel(const vector<int> &column1, const vector<int> &column2);//calculate correlation
void displayCorrelTable(const vector<int> &column1, const vector<int> &column2, string subject1, string subject2, int width);
double sumCorrel(const vector<int> &column1, const vector<int> &column2);//sum of value - mean
void correlStep(const vector<int> &column1, const vector<int> &column2, string subject1, string subject2);//display correlation steps

//Sorting
void sortAscending(vector<vector<int>>& vec, int choice);
void sortDescending(vector<vector<int>>& vec, int choice);

//Reports
void reportTxt(string filename, const vector<vector<string>> &data);
void reportHtml(string filename, const vector<vector<string>> &data);
//report table
void display2dTableReport(ofstream &fileout, const vector<vector<string> > &data, const vector<string> &headers, int width);
void display2dTableReportHtml(ofstream &fileout, const vector<vector<string> > &data, const vector<string> &headers);

int main()
{
    cout << fixed << showpoint << setprecision(4); //4 decimal places
    Menu menu;

    return 0;
}

//Menu
Menu::Menu()//constructor
{
    dataPtr = nullptr;
    mainMenu();
}
Menu::~Menu()//destructor
{
    delete dataPtr;
    dataPtr = nullptr;
}
void Menu::title(string title)
{
    int width = 5;
    string seperator = " |";
    string line = seperator + string(title.size() + width*2 - 2, '-') + "|";

    cout << line << endl;
    cout << left << setw(width + 1) << seperator << title << right << setw(width) << seperator << endl;
    cout << line << endl;
}

int Menu::getChoice(int max)
{
    int choice;
    int min = 0;//0 = exit

    cout << " 0.)Exit" << endl;
    cout << " 999.)Main Menu" << endl;

    do
    {
        cout << " From the list above, enter the number(" << min << " - " << max << " and 999): ";
        cin >> choice;
        if(!cin){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');//prevent infinite loop
            choice = max + 1;//give choice a false value to trigger error message
        }
    }while(!cin || choice != 999 && (choice < min || choice > max) && printf("\n ERROR Message: You have entered an invalid number. Please try again.\n"));
    if(choice == 0){
        if(dataPtr != nullptr){
            delete dataPtr;
            dataPtr = nullptr;
        }
        exit(0);
    }else if(choice == 999)
        mainMenu();

    return choice;
}
void Menu::mainMenu()
{
    system("cls||clear");
    title("Main Menu");
    cout << " 1.)Open file" << endl;
    cout << " 2.)Report" << endl;
    cout << " 3.)Compute Stats" << endl;

    int choice = getChoice(3);

    switch(choice)
    {
        case 1:
            loadFile();
            break;
        case 2:
            report();
            break;
        case 3:
            computeStats();
            break;
    }
}

void Menu::loadFile()
{
    File data;

    system("cls||clear");
    title("Open File");
    string filename;
    cin.ignore();
    do
    {
        cout << " Please enter your file name including extension\n (Enter 999 return to main menu).\n ->";

        getline(cin, filename);

        if(filename == "999")
            mainMenu();
        else
            data.loadFileCsv(filename);

    }while(data.isFileOpen() == false);

    if(data.getFormat())
    {
        if(dataPtr != nullptr){ //if theres data inside pointer
            delete dataPtr; //delete pointer to prevent memory leak
            dataPtr = nullptr;
        }
        dataPtr = &data;//if format is correct, point to the latest data
    }

    cin.get();
    mainMenu();
}

void Menu::computeStats()
{
    system("cls||clear");

    if(dataPtr != nullptr)
    {
        title("Compute Stats");
        cout << " File Name: " << dataPtr->getFilename() << endl;
        cout << " 1.)Minimum" << endl;
        cout << " 2.)Maximum" << endl;
        cout << " 3.)Median" << endl;
        cout << " 4.)Mean" << endl;
        cout << " 5.)Variance" << endl;
        cout << " 6.)Standard Deviation" << endl;
        cout << " 7.)Frequency Table" << endl;
        cout << " 8.)Histogram" << endl;
        cout << " 9.)Tables Between Mean" << endl;
        cout << " 10.)Select 2 Columns\n (Pearson Correlation/ Linear Regression Line)" << endl;

        int choice = getChoice(10);

        switch(choice){
            case 1:
                displayMaxMin(16, false);
                break;
            case 2:
                displayMaxMin(16, true);
                break;
            case 3:
                displayMedian(16);
                break;
            case 4:
                displayMean(16);
                break;
            case 5:
                displayVar(22);
                break;
            case 6:
                displayStdDev();
                break;
            case 7:
                displayFrequency();
                break;
            case 8:
                displayHistogram();
                break;
            case 9:
                displayTablesMean();
                break;
            case 10:
                select2Col(dataPtr->getHeader());
                break;
        }
    }else
        cout << " No file is loaded" << endl;

    system("pause");
    mainMenu();
}
//Compute Stats
void Menu::displayMaxMin(int width, bool maxMin)
{
    string separator = " |";
    system("cls||clear");
    string result;
    if(maxMin){
        result = "Maximum:";
        title("Maximum");
    }else{
        result = "Minimum:";
        title("Minimum");
    }
    string line;
    displayColumn(dataPtr->getDataInt(), dataPtr->getHeader(), line, width);

    cout << separator << result
        << setw(width - result.size());

    for(int i = 1; i < dataPtr->getColumn(); ++i)
    {
        if(i > 1)
            cout << setw(width);
        if(maxMin)
            cout << maximum(dataPtr->get1dData(i));
        else
            cout << minimum(dataPtr->get1dData(i));

        cout << separator;
    }
    cout << endl;
    cout << line << endl;

    system("pause");
    computeStats();
}
//display median
void Menu::displayMedian(int width)
{
    string separator = " |";
    string line;
    string result = "Median: ";
    system("cls||clear");
    title("Median");
    displayColumn(dataPtr->getDataInt(), dataPtr->getHeader(), line, width);
    cout << separator << result
        << setw(width - result.size());
    for(int i = 1; i < dataPtr->getColumn(); ++i){
        if(i > 1)
            cout << setw(width);
        cout << median(dataPtr->get1dData(i)) << separator;
    }

    cout << endl << line << endl;
    system("pause");
    computeStats();
}
//display mean
void Menu::displayMean(int width)
{
    string separator = " |";
    string line;
    string result = "Sum: ";
    string result2 = "Mean: ";
    system("cls||clear");
    title("Mean");
    displayColumn(dataPtr->getDataInt(), dataPtr->getHeader(), line, width);
    cout << separator << result
        << setw(width - result.size());
    for(int i = 1; i < dataPtr->getColumn(); ++i){
        if(i > 1)
            cout << setw(width);
        cout << getSum(dataPtr->get1dData(i)) << separator;
    }

    cout << endl << line << endl;
    cout << separator << result2
        << setw(width - result2.size());
    for(int i = 1; i < dataPtr->getColumn(); ++i){
        if(i > 1)
            cout << setw(width);
        cout << mean(dataPtr->get1dData(i)) << separator;
    }

    cout << endl << line << endl;
    system("pause");
    computeStats();
}
//display variance
void Menu::displayVar(int width)
{
    vector<string> headers = dataPtr->getHeader();
    int choice = selectCol(headers, "Variance", 1);

    int numFields = 3;
    string separator = " |";
    string result = "Sum: ";
    int totalWidth = (numFields*width) + (separator.size()*numFields);
    string line = separator + string(totalWidth - 1, '-') + "|";;
    system("cls||clear");
    title("Variance");
    cout << " Variance for " << headers[choice] << endl;

    vector<int> column = dataPtr->get1dData(choice);
    double m = mean(column);
    double sum = 0;
    //display headers
    cout << line << endl;
    cout << separator << setw(width) << headers[choice] + "/ x" << separator
            << setw(width) << "x-mean_x" << separator
            << setw(width)<< "(x-mean_x)*(x-mean_x)" << separator << endl;
    cout << line << endl;
    //display data
    for(int j = 0; j < dataPtr->getRow(); ++j)
    {
        sum += pow(column[j] - m, 2);
        cout << separator << setw(width) << column[j] << separator
                << setw(width) << column[j] - m << separator
                << setw(width) << (column[j] - m)*(column[j] - m) << separator << endl;
    }
    cout << line << endl;
    //display sum
    cout << separator << setw(width*2 + separator.size()* 2) << result << setw(width) << sum << separator << endl;
    cout << line << endl;
    cout << " Variance = sum((x - mean_x)*(x - mean_x)) / (n - 1)" << endl;
    cout << " Variance = " << varianceSum(column) << " / " << column.size() - 1 << endl;
    cout << " Variance = " << variance(column) << endl;
    system("pause");
    displayVar(width);
}
//display std deviation
void Menu::displayStdDev()
{
    system("cls||clear");
    title("Standard Deviation");
    vector<string> headers = dataPtr->getHeader();
    cout << " Standard Deviation for " << headers.size() - 1 << " Subjects:" << endl << endl;
    for(int i = 1; i < dataPtr->getColumn(); ++i)
    {
        cout << " Subject: " << headers[i] << endl;
        cout << " Variance = " << variance(dataPtr->get1dData(i)) << endl;
        cout << " Standard Deviation = sqrt(" << variance(dataPtr->get1dData(i)) << ")" << endl;
        cout << " Standard Deviation = " << standardDeviation(dataPtr->get1dData(i)) << endl;
        cout << endl;
    }
    system("pause");
    computeStats();
}
//display frequency table
void Menu::displayFrequency()
{
    vector<string> headers = dataPtr->getHeader();
    int choice = selectCol(headers, "Frequency Table", 1);

    system("cls||clear");
    title("Frequency Table for " + headers[choice]);
    frequency(dataPtr->get1dData(choice));
    system("pause");

    displayFrequency();
}
//display histogram
void Menu::displayHistogram()
{
    vector<string> headers = dataPtr->getHeader();
    int choice = selectCol(headers, "Histogram", 1);

    system("cls||clear");
    title("Histogram for " + headers[choice]);
    histogram(dataPtr->get1dData(choice));
    system("pause");

    displayHistogram();
}
//display tables between the mean
void Menu::displayTablesMean()
{
    vector<string> headers = dataPtr->getHeader();
    int choice = selectCol(headers, "Tables between the mean", 1);

    system("cls||clear");
    title("Table between the mean");

    double m = mean(dataPtr->get1dData(choice));

    cout << " Column: " << headers[choice] << endl;
    cout << " Mean: " << m << endl << endl;
    cout << " Table below " << headers[choice] << " mean" << endl;
    dataPtr->display2dTable(aboveBelow(dataPtr->getDataInt(), m, choice, true), headers, 10);
    cout << "\n Table above " << headers[choice] << " mean" << endl;
    dataPtr->display2dTable(aboveBelow(dataPtr->getDataInt(), m, choice, false), headers, 10);
    system("pause");
    displayTablesMean();
}
//display headers for select column
void Menu::displayHeaders(const vector<string> &headers, int startFrom)
{
    int add = 0;
    if(startFrom == 0)
        ++add;
    for(int i = startFrom; i < headers.size(); ++i)
        cout << " " << i + add << ".)" << headers[i] << endl;

    if(startFrom != 0)
        cout << " " << headers.size() << ".)Back to Compute Stats" << endl;//last choice
    else
        cout << " " << headers.size() + add << ".)Back to Preview Table Report" << endl;
}
//select a column
int Menu::selectCol(const vector<string> &headers, string subTitle, int startFrom)
{
    system("cls||clear");
    title("Select A Column(" + subTitle + ")");

    displayHeaders(headers, startFrom);

    cout << " Enter a column" << endl;
    int add = 0;
    if(startFrom == 0) ++add;

    int choice = getChoice(headers.size() + add);

    if(choice != headers.size() + add)
        return choice;
    else{
        if(startFrom == 0)
            preview();
        else
            computeStats();
    }
}
//select 2 column, linear, correlation
void Menu::select2Col(const vector<string> &headers)
{
    system("cls||clear");
    title("Select 2 Columns");

    displayHeaders(headers, 1);

    cout << " Enter First Column: " << endl;
    int choice1 = getChoice(headers.size());
    if(choice1 != headers.size())
    {
        cout << " Enter Second Column: " << endl;
        int choice2 = getChoice(headers.size());
        if(choice2 != headers.size())
        {
            vector<int> column1 = dataPtr->get1dData(choice1);
            vector<int> column2 = dataPtr->get1dData(choice2);

            selectLinearCorrel(column1, column2, headers[choice1], headers[choice2]);
        }
    }
    computeStats();
}
//select linear or correlation
void Menu::selectLinearCorrel(const vector<int> &column1, const vector<int> &column2, string subject1, string subject2)
{
    system("cls||clear");
    title("Choose Linear Regression Line or Pearson Correlation");
    cout << " Columns you chose: " << endl;
    cout << " Column 1: " << subject1 << endl;
    cout << " Column 2: " << subject2 << endl;
    cout << " 1.)Linear Regression Line" << endl;
    cout << " 2.)Pearson Correlation" << endl;
    cout << " 3.)Back to Select 2 Columns" << endl;

    int choice = getChoice(3);
    system("cls||clear");

    switch(choice)
    {
        case 1:
            title("Linear Regression");
            linearRegression(column1, column2, subject1, subject2);//Linear.h
            break;
        case 2:
            title("Pearson's Correlation");
            correlation(column1, column2, subject1, subject2);//Correlation.h
            break;
        case 3:
            select2Col(dataPtr->getHeader());
            break;
    }
    system("pause");
    selectLinearCorrel(column1, column2, subject1, subject2);
}
//report menu
void Menu::report()
{
    system("cls||clear");

    if(dataPtr != nullptr)
    {
        title("Report");
        cout << " 1.)Generate a Report" << endl;
        cout << " 2.)Preview Table Report" << endl;

        int choice = getChoice(2);

        switch(choice){
            case 1:
                generateReport();//generate report
                break;
            case 2:
                preview();
                break;
        }
    }else
        cout << " No file is loaded" << endl;

    system("pause");//window
    //linus
    mainMenu();
}
//select report
void Menu::generateReport()
{
    system("cls||clear");
    title("Generate Report");
    cout << " 1.)Txt" << endl;
    cout << " 2.)HTML" << endl;
    cout << " 3.)Back to Report" << endl;

    int choice = getChoice(3);
    bool isTxt;
    switch(choice)
    {
        case 1:
            isTxt = true;
            break;
        case 2:
            isTxt = false;
            break;
        case 3:
            report();
    }
    selectReport(isTxt);
    report();
}
void Menu::selectReport(bool isTxt)
{
    int sub1 = getSub();
    vector<bool> display = selectDisplay();
    vector<int> sub2 = get2Sub();

    vector<string> stats;
    vector<double> result;
    vector<string> headers = dataPtr->getHeader();

    computeReport(display, stats, result, sub1, sub2);

    vector<vector<string>> data;
    //convert result into 2d vec
    for(int i = 0; i < result.size(); ++i)
    {
        vector<string>temp;
        temp.push_back(stats[i]);
        if(i > 5)
            temp.push_back(headers[sub2[0]] + ", " + headers[sub2[1]]);
        else
            temp.push_back(headers[sub1]);

        char num[20];
        sprintf(num, "%.4f", result[i]);
        temp.push_back(num);

        data.push_back(temp);
    }

    string filename;
    cout << "Filename? ";
    cin >> filename;

    if(isTxt)
    {
        filename += ".txt";
        reportTxt(filename, data);
    }else{
        filename += ".html";
        reportHtml(filename, data);
    }

    system("pause");
    report();
}
void Menu::computeReport(const vector<bool> &display, vector<string> &getStats, vector<double> &getResult, int sub1, const vector<int> &sub2)
{
    vector<string> stats = {"Minimum", "Maximum", "Median", "Mean", "Variance", "Standard Deviation", "Pearson's Correlation", "Linear Regression Line Slope, m", "Linear Regression Line Intercept, c"};
    double result;

    for(int i = 0; i < stats.size(); ++i)
    {
        if(display[i]){
            getStats.push_back(stats[i]);
            switch(i + 1)
            {
                case 1:
                    result = minimum(dataPtr->get1dData(sub1));
                    break;
                case 2:
                    result = maximum(dataPtr->get1dData(sub1));
                    break;
                case 3:
                    result = median(dataPtr->get1dData(sub1));
                    break;
                case 4:
                    result = mean(dataPtr->get1dData(sub1));
                    break;
                case 5:
                    result = variance(dataPtr->get1dData(sub1));
                    break;
                case 6:
                    result = standardDeviation(dataPtr->get1dData(sub1));
                    break;
                case 7:
                    result = getCorrel(dataPtr->get1dData(sub2[0]), dataPtr->get1dData(sub2[1]));
                    break;
                case 8:
                    result = slope(dataPtr->get1dData(sub2[0]), dataPtr->get1dData(sub2[1]));
                    break;
                case 9:
                    result = intercept(dataPtr->get1dData(sub2[0]), dataPtr->get1dData(sub2[1]), slope(dataPtr->get1dData(sub2[0]), dataPtr->get1dData(sub2[1])));
                    break;
            }

            //result = roundf(result * 10000) / 10000;
            getResult.push_back(result);
        }
    }
}
vector<bool> Menu::selectDisplay()
{
    vector<bool> display(9, true);
    vector<string> stats = {"Minimum", "Maximum", "Median", "Mean", "Variance", "Standard Deviation", "Pearson's Correlation", "Linear Regression Line"};
    char choice;
    for(int i = 0; i < stats.size(); ++i)
    {
        cout << stats[i] << "? (Y or N): ";
        do
        {
            cin >> choice;
            cin.clear();
            cin.ignore(1000, '\n');
            choice = toupper(choice);
        }while(choice != 'Y' && choice != 'N' && printf("\n ERROR Message: You have entered an invalid number. Please try again.\n"));//to check if choice is not Y and not N then loop
        if(choice == 'N'){
            if(i == stats.size() - 1)
            {
                display[i] = false;
                display[i + 1] = false;
            }else
                display[i] = false;
        }
    }
    return display;
}
//get 1 sub
int Menu::getSub()
{
    vector<string> headers = dataPtr->getHeader();
    cout << "Input only one subject number(";
    for(int i = 1; i < dataPtr->getColumn(); ++i)
    {
        cout << i << " for " << headers[i];
        if(i != dataPtr->getColumn() - 1)
            cout << ", ";
    }
    cout << ")" << endl;
    int choice = getChoice(headers.size());

    return choice;
}
//get 2 subs
vector<int> Menu::get2Sub()
{
    cout << "Input two subject numbers" << endl;
    vector<string> headers = dataPtr->getHeader();
    vector<int> result;
    for(int i = 1; i < headers.size(); ++i)
        cout << i << ". " << headers[i] << endl;
    cout << "Input the first subject number? ";
    int choice;
    choice = getChoice(headers.size());
    result.push_back(choice);
    choice = getChoice(headers.size());
    result.push_back(choice);

    return result;
}
//view report table menu
void Menu::preview()
{
    system("cls||clear");
    title("Preview Table Report");
    cout << " View the Table Report in: " << endl;
    cout << " 1.)Ascending Order" << endl;
    cout << " 2.)Descending Order" << endl;
    cout << " 3.)Original Form" << endl;
    cout << " 4.)Back to Report" << endl;

    int choice = getChoice(4);
    bool order;
    switch(choice)
    {
        case 1:
            order = true;
            break;
        case 2:
            order = false;
            break;
        case 3:
            system("cls||clear");
            title("Table Report");
            cout << " Original Form:" << endl;
            dataPtr->printData();
            system("pause");
            preview();
        case 4:
            report();
    }
    selectSort(order);
}
//select columns for ascending / descending
void Menu::selectSort(bool ascDesc)
{
    int choice = selectCol(dataPtr->getHeader(), "Sort Descending W.R.T", 0);
    sorting(dataPtr->getDataInt(), dataPtr->getHeader(), choice - 1, ascDesc);
}
//display sorting
void Menu::sorting(const vector<vector<int>> &data, const vector<string>headers, int choice, bool ascDesc)
{
    vector<vector<int>> temp = dataPtr->getDataInt();
    system("cls||clear");
    if(ascDesc){
        title("Table Report(Ascending)");
        sortAscending(temp, choice);
    }else{
        title("Table Report(Descending)");
        sortDescending(temp, choice);
    }
    cout << " Data sorted with respect to: " << headers[choice] << endl;
    cout << " File name: " << dataPtr->getFilename() << endl;
    //print table
    dataPtr->display2dTable(temp, headers, 10);
    system("pause");
    selectSort(ascDesc);
}

//Compute
//minimum
int minimum(const vector<int> &column)
{
    return *min_element(column.begin(), column.end());
}
//maximum
int maximum(const vector<int> &column)
{
    return *max_element(column.begin(), column.end());
}
//median
double median(const vector<int> &column)
{
    vector<int> vec = column;
    sort(vec.begin(), vec.end());
    int size = vec.size();
    double median;
    if (size % 2 == 0)
    {
        median = (double)(vec[size / 2 - 1] + vec[size / 2]) / 2;
    }
    else
    {
        median = (double)vec[size / 2];
    }
    return median;
}
//mean
double mean(const vector<int> &column)
{
    int sum = getSum(column);
    double mean = (double)sum / column.size();
    return mean;
}
int getSum(const vector<int> &column)
{
    return accumulate(column.begin(), column.end(), 0);
}
//variance
double variance(const vector<int> &column)
{
    double sum = varianceSum(column);

    double result = sum / (column.size() - 1);
    return result;
}
double varianceSum(const vector<int> &column)
{
    double sum = 0;
    double m = mean(column);
    for(int i = 0; i < column.size(); ++i)
        sum += ((column[i] - m) * (column[i] - m));
    return sum;
}
//std deviation
double standardDeviation(const vector<int> &column)
{
    double v = variance(column);
    return sqrt(v);
}
//display table for minimum, maximum, ...
void displayColumn(const vector<vector<int> > &data, const vector<string> &headers, string &line, int width)
{
    string separator = " |";
    int numFields = headers.size() - 1;
    int totalWidth = (width * numFields) + (separator.size() * numFields);
    line = separator + string(totalWidth - 1, '-') + "|";

    //print table headers
    cout << line << endl;
    cout << separator;
    for(int i = 1; i < headers.size(); ++i)
        cout << setw(width) << headers[i] << separator;
    cout << endl << line << endl;

    //print table body
    for(int i = 0; i < data.size(); ++i)
    {
        cout << separator;
        for(int j = 1; j < headers.size(); ++j)
            cout << setw(width) << data[i][j] << separator;
        cout << endl;
    }
    cout << line << endl;
}

//Frequency Table
void frequency(const vector<int> &values)
{
    int width = 10;
    int numFields = 2;
    string separator = " |";
    int totalWidth = (width * numFields) + (separator.size() * numFields);
    string line = separator + string(totalWidth - 1, '-') + "|";

    //headers
    cout << line << endl;
    cout << separator << setw(width) << "Values" << separator << setw(width) << "Frequency" << separator << endl;
    cout << line << endl;
    for(int i = 0; i <= 100; ++i) //100marks
    {
        int count = 0;
        cout << separator << setw(width) << i << separator;
        for(int j = 0; j < values.size(); ++j)
        {
            if(values[j] == i)
                ++count;
        }
        cout << setw(width) << count << separator << endl;
    }
    cout << line << endl;
}

//Histogram
vector<int> getHistoVal(const vector <int>&value)
{
    //0-10, 11-20, 21-30, 31-40, 41-50, 51-60, 61-70, 71-80, 81-90, 91-100
    vector<int> result(10, 0);//total 9
    for(int i = 0; i < value.size(); ++i)
    {
        if(value[i] > 0 && value[i] <= 10)
            ++result[0];
        else if(value[i] > 10 && value[i] <= 20)
            ++result[1];
        else if(value[i] > 20 && value[i] <= 30)
            ++result[2];
        else if(value[i] > 30 && value[i] <= 40)
            ++result[3];
        else if(value[i] > 40 && value[i] <= 50)
            ++result[4];
        else if(value[i] > 50 && value[i] <= 60)
            ++result[5];
        else if(value[i] > 60 && value[i] <= 70)
            ++result[6];
        else if(value[i] > 70 && value[i] <= 80)
            ++result[7];
        else if(value[i] > 80 && value[i] <= 90)
            ++result[8];
        else if(value[i] > 90 && value[i] <= 100)
            ++result[9];
    }
    return result;
}
void histogram(const vector <int>&value)
{
    int width = 15;
    vector<string> name = {"0-10", "11-20", "21-30", "31-40", "41-50", "51-60", "61-70", "71-80", "81-90", "91-100"};
    vector<int> result = getHistoVal(value);
    int dataWidth;//get maximum width
    if(maximum(result) < 7)
        dataWidth = 7;
    else
        dataWidth = maximum(result);
    string seperator = " |";
    string line = seperator + string(width + dataWidth + (seperator.size()*2) - 1, '-') + "|";
    //header
    cout << " * = 1" << endl;
    cout << line << endl;
    cout << seperator << setw(width)<< "Class Interval" << seperator << left << setw(dataWidth) << " Values" << seperator << endl;
    cout << line << endl;

        for (int i = name.size() - 1; i >= 0; i--)
        {
            cout << right << seperator << setw(width) << name[i] << left << seperator;//id
                for (int j = 0; j < dataWidth; j++)
                {
                    if(result[i] > j)
                        cout << "*";
                    else
                        cout << " ";
                }
            cout << seperator << endl;
        }
    cout << line << endl;
}
//Tables between the mean
vector<vector<int>> aboveBelow (const vector<vector<int>> &data, double mean, int choice, bool isBelow)
{
    vector<vector<int>> v = data;
    sortAscending (v, choice);
    vector<vector<int>> result;
    if(isBelow)
    {
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i][choice] < mean)
                result.push_back(v[i]);
        }
    }else
    {
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i][choice] > mean)
                result.push_back(v[i]);
        }
    }
    return result;
}

//Correlation

void correlation(const vector<int> &column1, const vector<int> &column2, string subject1, string subject2)
{
    cout << " Column 1: " << subject1 << endl;
    cout << " Column 2: " << subject2 << endl;

    displayCorrelTable(column1, column2, subject1, subject2, 11);

    cout << " mean_x = " << mean(column1) << ", mean_y = " << mean(column2) << endl;
    cout << " Correlation Computation = sum(a * b) / sqrt(sum(a * a) * sum(b * b))" << endl;
    cout << " Correlation Computation = " << sumCorrel(column1, column2) << " / sqrt("
        << sumCorrel(column1, column1) << " * " << sumCorrel(column2, column2) << ")" << endl;

    double correl = getCorrel(column1, column2);

    cout << " Correlation Computation = " << correl << endl;
}
double getCorrel(const vector<int> &column1, const vector<int> &column2)
{
    return sumCorrel(column1, column2) / sqrt(sumCorrel(column1, column1) * sumCorrel(column2, column2));
}
void displayCorrelTable(const vector<int> &column1, const vector<int> &column2, string subject1, string subject2, int width)
{
    int numFields = 7;
    string separator = " |";
    string result = "Sum: ";
    int totalWidth = (width * numFields) + separator.size() * numFields;
    string line = separator + string(totalWidth - 1, '-') + "|";
    double mean1 = mean(column1);
    double mean2 = mean(column2);
    //display headers
    cout << line << endl;
    cout << separator << setw(width) << subject1 + "/x" << separator
        << setw(width) << subject2 + "/y" << separator
        << setw(width) << "a=x-mean_x" << separator
        << setw(width) << "b=y-mean_y" << separator
        << setw(width) << "a * b" << separator
        << setw(width) << "a * a" << separator
        << setw(width) << "b * b" << separator << endl;
    cout << line << endl;

    for(int i = 0; i < column1.size(); ++i)
    {
        double a = column1[i] - mean1;
        double b = column2[i] - mean2;
        cout << separator << setw(width) << column1[i] << separator
            << setw(width) << column2[i] << separator
            << setw(width) << a << separator
            << setw(width) << b << separator
            << setw(width) << a * b << separator
            << setw(width) << a * a << separator
            << setw(width) << b * b << separator << endl;
    }
    cout << line << endl;
    cout << separator << setw(width*4 + separator.size()*4) << result//jump to column 4
        << setw(width) << sumCorrel(column1, column2) << separator
        << setw(width) << sumCorrel(column1, column1) << separator
        << setw(width) << sumCorrel(column2, column2) << separator << endl;
    cout << line << endl;
}
double sumCorrel(const vector<int> &column1, const vector<int> &column2)
{
    double total = 0;
    double meanNum1 = mean(column1);
    double meanNum2 = mean(column2);

    for(int i = 0; i < column1.size(); ++i)
    {
        double a = column1[i] - meanNum1;
        double b = column2[i] - meanNum2;

        total += a * b;
    }

    return total;
}

//Linear
void linearRegression(const vector<int> &column1, const vector<int> &column2, string subject1, string subject2)
{
    cout << " Column 1: " << subject1 << endl;
    cout << " Column 2: " << subject2 << endl;

    displayLinearTable(column1, column2, subject1, subject2, 12);//display table

    double slopeNum = slope(column1, column2);
    double interceptNum = intercept(column1, column2, slopeNum);
    //show steps
    slopeStep(column1, column2);
    cout << " Slope, m = " << slopeNum << endl;
    interceptStep(column1, column2, slopeNum);
    cout << " Intercept, c = " << interceptNum << endl;

    cout << " Line Equation: y = mx + c" <<endl;
    if(interceptNum < 0)
        cout << " Line Equation: y = " << slopeNum << "x - " << -interceptNum << endl;//make intercept +ive
    else
        cout << " Line Equation: y = " << slopeNum << "x + " << interceptNum << endl;
}
void displayLinearTable(const vector<int> &column1, const vector<int> &column2, string subject1, string subject2, int width)
{
    int numFields = 4;
    string separator = " |";
    string result = "Sum: ";
    int totalWidth = (width * numFields) + separator.size() * numFields;
    string line = separator + string(totalWidth - 1, '-') + "|";
    //display headers
    cout << line << endl;
    cout << separator << setw(width) << subject1 + "/x" << separator
        << setw(width) << subject2 + "/y" << separator
        << setw(width) << "x * x" << separator
        << setw(width) << "x * y" << separator << endl;
    cout << line << endl;
    //display values
    for(int i = 0; i < column1.size(); ++i)
        cout << separator << setw(width) << column1[i] << separator
            << setw(width) << column2[i] << separator
            << setw(width) << column1[i]*column1[i] << separator
            << setw(width) << column1[i]*column2[i] << separator << endl;
    //display result
    cout << line << endl;
    cout << separator << result
        << setw(width - result.size()) <<sum(column1) << separator
        << setw(width) << sum(column2) << separator
        << setw(width) << sumMultiplication(column1, column1) << separator
        << setw(width) << sumMultiplication(column1, column2) << separator << endl;
    cout << line << endl;
}

double slope(const vector<int> &column1, const vector<int> &column2)
{
    int n = column1.size();
    double slope = static_cast<double>(n * sumMultiplication(column1, column2) - sum(column1) * sum(column2)) /
                    (n * sumMultiplication(column1, column1) - sum(column1) * sum(column1));

    return slope;
}

double intercept(const vector<int> &column1, const vector<int> &column2, double slope)
{
    int n = column1.size();
    double intercept = static_cast<double>((sum(column2) - slope * sum(column1)) / n);

    return intercept;
}
void slopeStep(const vector<int> &column1, const vector<int> &column2)
{
    int n = column1.size();

    cout << " Slope, m = (n * sum(x*y) - sum(x) * sum(y)) / (n * sum(x*x) - sum(x) * sum(x))" << endl; //formula
    //steps
    cout << " Slope, m = (" << n << " * " << sumMultiplication(column1, column2)
        << " - " << sum(column1) << " * " << sum(column2) << ") / "
        << "(" << n << " * " << sumMultiplication(column1, column1)
        << " - " << sum(column1) << " * " << sum(column1) << "))" << endl;
}
void interceptStep(const vector<int> &column1, const vector<int> &column2, double slope)
{
    int n = column1.size();

    cout << " Intercept, c = sum(y) - m * sum(x) / n" << endl; //formula
    //steps
    cout << " Intercept, c = " << sum(column2) << " - " << slope << " * " << sum(column1) << " / " << n << endl;
}
int sum(const vector<int> &column)
{
    int sum = 0;

    for(int i = 0; i < column.size(); ++i)
        sum += column[i];

    return sum;
}

int sumMultiplication(const vector<int> &column1, const vector<int> &column2)
{
    int sum = 0;

    for(int i = 0; i < column1.size(); ++i)
        sum += column1[i]*column2[i];

    return sum;
}

//Reports
//Sorting
void sortAscending (vector<vector<int>>& vec, int choice)
{
    int minIndex, minValue;

    for(int i = 0; i < vec.size(); ++i) //vec.size() returns the number of elements in vector
    {
      minIndex = i;
      minValue = vec[i][choice];

      for(int j = i+1; j < vec.size(); ++j)
      {
        if(vec[j][choice] < minValue)
        {
          minIndex = j;
          minValue = vec[j][choice];
        }
      }

      swap(vec[minIndex], vec[i]);
    }
}

void sortDescending (vector<vector<int>>& vec, int choice)
{
    int maxIndex, maxValue;

    for(int i = 0; i < vec.size(); ++i) //vec.size() returns the number of elements in vector
    {
      maxIndex = i;
      maxValue = vec[i][choice];

      for(int j = i+1; j < vec.size(); ++j)
      {
        if(vec[j][choice] > maxValue)
        {
          maxIndex = j;
          maxValue = vec[j][choice];
        }
      }

      swap(vec[maxIndex], vec[i]);
    }
}

//generate report
void reportTxt(string filename, const vector<vector<string>> &data)
{

    ofstream txtreport;
    txtreport.open(filename.c_str());

    vector<string> headers = {"Stat", "Subject(s)", "Value"};

    txtreport << " Report" << endl;
    display2dTableReport(txtreport, data, headers, 40);

    txtreport.close();
    cout << "Text Report Generated!" << endl;
}
void reportHtml(string filename, const vector<vector<string>> &data)
{
    ofstream txtreport;
    txtreport.open(filename.c_str());

    vector<string> headers = {"Stat", "Subject(s)", "Value"};
    display2dTableReportHtml(txtreport, data, headers);

    txtreport.close();
    cout << "Text Report Generated!" << endl;
}

//Load File
File::File()
{
    format = true;//assume format is correct first
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
        cout << " File is not open, please check your file name again." << endl;
    }else
    {
        File::filename = filename;//store file name
        if(checkFormat(file))
        {
            loadData(file);
            convertData(data, column);
            //printData();
        }else
            cout << " Format Error, please check your file" << endl;
    }
}
bool File::checkFormat(ifstream &file)
{
    string line;//to store the a line of string from file temporally
    getline(file, line);//get first line
    if(!isNumber(line))//check if the string contain only integer
    {
        format = false;
        cout << " ERROR: Undefined column value" << endl;
    }
    else
    {
        column = stoi(line);//convert string to int, store into int column
        getline(file, line);//get second line

        if(checkColumn(line) != column)//check if the number of titles is not match to column
        {
            format = false;
            cout << " ERROR: Column does not match to the number of titles" << endl;
        }
        else
        {
            getline(file, line);//get the third line
            if(!isNumber(line))
            {
                format = false;
                cout << " ERROR: Undefined row value" << endl;
            }
            else
            {
                row = stoi(line);//convert string to int, store into int row
                int countRow = 1;//to get the current row
                while(getline(file, line))//check the rest of the row
                {
                    if(checkColumn(line)!= (column))//perform check column for each row
                    {
                        format = false;
                        cout << " ERROR: Data Column does not match to the number of titles at line " << countRow + 3 << endl;//add 3 rows because of headers
                    }
                    countRow++;
                }
                if(countRow - 1 != row)//check number of rows match to header setting
                {
                    format = false;
                    cout << " ERROR: Row does not match to the total number of data" << endl;
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
    cout << " File loaded." << endl;
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
        {
            number = false;
            break;
        }
    }
    return number;
}

void File::convertData(const vector<vector<string> >&data, int column)
{
    vector<vector<string> > tempData = data;
    for(int i = 0; i < data.size(); ++i)
    {
        vector<int>temp;//store a row of vector temporally
        for(int j = 0; j < column; ++j)
        {
            temp.push_back(stoi(tempData[i][j]));//convert string to int and add to temp vector
        }
        dataInt.push_back(temp);
    }
}
void File::printData()
{
    cout << " File name: " << filename << endl;

    display2dTable(dataInt, name, 10);
}
vector<int> File::get1dData(int choice)
{
    vector<int> vec;

    for(int i = 0; i < dataInt.size(); ++i)
        vec.push_back(dataInt[i][choice]);

    return vec;
}

void File::display2dTable(const vector<vector<int> > &data, const vector<string> &headers, int width)
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
void display2dTableReport(ofstream &fileout, const vector<vector<string> > &data, const vector<string> &headers, int width)
{
    int numFields = headers.size();
    string seperator = " |";
    int totalWidth = (width * numFields) + seperator.size() * (numFields + 1) + 5;
    string line = seperator + string(totalWidth - 1, '-') + "|";

    //print table headers
    fileout << line << endl;
    fileout << seperator;
    fileout << setw(5) << "No." << seperator;
    for(int i = 0; i < headers.size(); ++i)
        fileout << setw(width) << headers[i] << seperator;
    fileout << endl << line << endl;

    //print table body
    for(int i = 0; i < data.size(); ++i)
    {
        fileout << seperator;
        fileout << setw(5) << i + 1 << seperator;
        for(int j = 0; j < headers.size(); ++j)
            fileout << setw(width) << data[i][j] << seperator;
        fileout << endl;
    }

    fileout << line << endl;
}
void display2dTableReportHtml(ofstream &fileout, const vector<vector<string> > &data, const vector<string> &headers)
{
    //print table headers
    fileout << "<!DOCTYPE html>\n<html>\n<head>"<< endl;
    fileout << "<style>table, th, td { border: 1px solid black; border-collapse: collapse;" <<endl;
    fileout << "</style>\nReport\n</head>\n<body>" << endl;
    fileout << "<table><tr>" << endl;
    fileout << "<tr><th>" << "No." << "</th>";
    for(int i = 0; i < headers.size(); ++i)
        fileout << "<th>" << headers[i] << "</th>";
    fileout << "</tr>";

    //print table body
    for(int i = 0; i < data.size(); ++i)
    {
        fileout << "<tr>";
        fileout << "<td>" << i + 1 << "</td>";
        for(int j = 0; j < headers.size(); ++j)
            fileout << "<td>" << data[i][j] << "</td>";

        fileout << "</tr>";
    }

    fileout << "</table></body></html>";

}
