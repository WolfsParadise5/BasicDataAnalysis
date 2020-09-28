#include "File.h"
#include "Linear.h"
#include "Correlation.h"
#include "Histogram.h"
#include "Sort.h"

//global
File *dataPtr = nullptr;//point to latest file data

//function prototypes
//menu and get input
void title(string title);
void mainMenu();
int getChoice(int max);
//main menu
void loadFile();
void computeStats();
void report();
//compute stats
void displayMaxMin(const vector<string> &headers, int width, bool maxMin); //true for max, false for min
void displayHistogram();
//selects
void displayHeaders(const vector<string> &headers, int startFrom);
int selectCol(const vector<string> &headers, string subTitle, int startFrom);
void select2Col(const vector<string> &headers);
void selectLinearCorrel(const vector<int> &column1, const vector<int> &column2, string subject1, string subject2);
//report
void preview();
void sorting(const vector<vector<int>> &data, const vector<string>headers, int choice, bool ascDesc);

int main()
{
    cout << fixed << showpoint << setprecision(4); //4 decimal places

    mainMenu();
    delete dataPtr;
    return 0;
}

void title(string title)
{
    int width = 5;
    string seperator = " |";
    string line = seperator + string(title.size() + width*2 - 2, '-') + "|";

    cout << line << endl;
    cout << left << setw(width + 1) << seperator << title << right << setw(width) << seperator << endl;
    cout << line << endl;
}

int getChoice(int max)
{
    int choice;
    int min = 0;

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
        exit(0);
        delete dataPtr;
    }else if(choice == 999)
        mainMenu();

    return choice;
}
void mainMenu()
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

void loadFile()
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

    system("pause");
    mainMenu();
}

void computeStats()
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
        cout << " 7.)Histogram" << endl;
        cout << " 8.)Tables Between Mean" << endl;
        cout << " 9.)Frequency Tables" << endl;
        cout << " 10.)Select 2 Columns\n (Pearson Correlation/ Linear Regression Line)" << endl;

        int choice = getChoice(10);

        switch(choice){
            case 1:
                displayMaxMin(dataPtr->getHeader(), 12, false);
                break;
            case 2:
                displayMaxMin(dataPtr->getHeader(), 12, true);
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                displayHistogram();
                break;
            case 8:
                break;
            case 9:
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
//max, min, mean, median, ...
//string separator from Compute.h
void displayMaxMin(const vector<string> &headers, int width, bool maxMin)
{
    system("cls||clear");
    string result;
    if(maxMin){
        result = "Maximum:";
        title("Maximum");
        cout << " Maximum for ";
    }else{
        result = "Minimum:";
        title("Minimum");
        cout << " Minimum for ";
    }
    cout << headers.size() - 1 << " Columns:" << endl;

    string line = displayColumn(dataPtr->getDataInt(), headers, width);//Compute.h

    cout << separator << result
        << setw(width - result.size());

    for(int i = 1; i < headers.size(); ++i)
    {
        if(i > 1)
            cout << setw(width);
        if(maxMin)
            cout << maximum(dataPtr->get1dData(i));//Compute.h
        else
            cout << minimum(dataPtr->get1dData(i));//compute.h

        cout << separator;
    }
    cout << endl;
    cout << line << endl;

    system("pause");
    computeStats();
}

//histogram, .........
void displayHistogram()
{
    vector<string> headers = dataPtr->getHeader();
    int choice = selectCol(headers, "Histogram", 1);

    system("cls||clear");
    title("Histogram for " + headers[choice]);
    histogram(dataPtr->get1dData(choice), dataPtr->get1dData(0));
    system("pause");

    displayHistogram();
}

void displayHeaders(const vector<string> &headers, int startFrom)
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

int selectCol(const vector<string> &headers, string subTitle, int startFrom)
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
void select2Col(const vector<string> &headers)
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

void selectLinearCorrel(const vector<int> &column1, const vector<int> &column2, string subject1, string subject2)
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

void report()
{
    system("cls||clear");

    if(dataPtr != nullptr)
    {
        title("Report");
        cout << " 1.)Report Settings" << endl;
        cout << " 2.)Preview Table Report" << endl;

        int choice = getChoice(2);

        switch(choice){
            case 1:
                report();//
                break;
            case 2:
                preview();
                //testing
//                system("cls||clear");
//                title("Preview Report");
//                dataPtr->printData();
//                system("pause");
//                report();
                break;
        }
    }else
        cout << " No file is loaded" << endl;

    system("pause");
    mainMenu();
}

void preview()
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
    int col;

    switch(choice)
    {
        case 1:
            order = true;
            col = selectCol(dataPtr->getHeader(), "Sort Ascending W.R.T", 0);
            break;
        case 2:
            order = false;
            col = selectCol(dataPtr->getHeader(), "Sort Descending W.R.T", 0);
            break;
        case 3:
            system("cls||clear");
            title("Table Report");
            cout << " Original Form:" << endl;
            dataPtr->printData();
            system("pause");
            preview();
            break;
        case 4:
            report();
            break;
    }
    sorting(dataPtr->getDataInt(), dataPtr->getHeader(), col - 1, order);
}

void sorting(const vector<vector<int>> &data, const vector<string>headers, int choice, bool ascDesc)
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
    dataPtr->display2dTable(temp, headers, 9);
    system("pause");
    preview();
}
