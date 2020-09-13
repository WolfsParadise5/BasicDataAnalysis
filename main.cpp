#include "File.h"
#include "Linear.h"

//global
File *dataPtr = nullptr;//to store latest file data

//function prototypes
//menu and get input
void title(const string &title);
void mainMenu();
int getChoice(const int &max);
//main menu
void loadFile();
void calculation();
void report();
//compute stats
void select2Col(const vector<string> &headers);

int main()
{
    mainMenu();
    delete dataPtr;
    return 0;
}

void title(const string &title)
{
    int width = 5;
    string line = "|" + string(title.size() + width*2 - 2, '-') + "|";

    cout << line << endl;
    cout << setw(width) << left << "| " << title << right << setw(width) << " |" << endl;
    cout << line << endl;
}

int getChoice(const int &max)
{
    int choice;
    int min = 0;

    cout << "0.)Exit" << endl;
    cout << "999.)Main Menu" << endl;

    do
    {
        cout << "From the list above, enter the number(" << min << " - " << max << " and 999): ";
        cin >> choice;
    }while(choice != 999 && (choice < min || choice > max) && printf("ERROR Message: You have entered an invalid number. Please try again.\n"));

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
    cout << "1.)Open file" << endl;
    cout << "2.)Report" << endl;
    cout << "3.)Compute Stats" << endl;

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
            calculation();
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
        cout << "Please enter your file name including extension\n(Enter 999 return to main menu).\n->";

        getline(cin, filename);

        if(filename == "999")
            mainMenu();
        else
            data.loadFileCsv(filename);

    }while(data.isFileOpen() == false);
    if(data.getFormat()) dataPtr = &data;//if format is correct, point to the latest data

    system("pause");
    mainMenu();
}

void calculation()
{
    system("cls||clear");

    if(dataPtr != nullptr)
    {
        title("Compute Stats");
        cout << "File Name: " << dataPtr->getFilename() << endl;
        cout << "1.)Minimum" << endl;
        cout << "2.)Maximum" << endl;
        cout << "3.)Median" << endl;
        cout << "4.)Mean" << endl;
        cout << "5.)Variance" << endl;
        cout << "6.)Standard Deviation" << endl;
        cout << "7.)Histogram" << endl;
        cout << "8.)Tables Between Mean" << endl;
        cout << "9.)Frequency Tables" << endl;
        cout << "10.)Select 2 Columns" << endl;

        int choice = getChoice(10);

        switch(choice){
            case 1:
                break;
            case 2:
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
        cout << "No file is loaded" << endl;

    system("pause");
    mainMenu();
}

void select2Col(const vector<string> &headers)
{
    system("cls||clear");
    title("Select 2 Columns");

    for(int i = 1; i < headers.size(); ++i)
        cout << i << ".)" << headers[i] << endl;

    int choice1 = getChoice(headers.size() - 1);
    int choice2 = getChoice(headers.size() - 1);
    vector<int> column1 = dataPtr->get1dData(dataPtr->getDataInt(), choice1);
    vector<int> column2 = dataPtr->get1dData(dataPtr->getDataInt(), choice2);

    linearRegression(column1, column2, headers[choice1], headers[choice2]);

    system("pause");
    select2Col(headers);
}

void report()
{
    system("cls||clear");

    if(dataPtr != nullptr)
        dataPtr->printData();//testing
    else
        cout << "No file is loaded" << endl;

    system("pause");
    mainMenu();
}
