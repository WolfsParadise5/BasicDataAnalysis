#include<iostream>
#include<vector>
#include<fstream>
#include<string>

using namespace std;

void chooseReport(int option);
void chooseReport2(int input, vector<vector<bool> >&selectData);
void displayInput();
void boolchecker(string option, vector<vector<bool> >&selectData);

void displayInput() {   //Initial output display

    int option
    cout << "1. Txt file" << endl;
    cout << "2. Html file" << endl;

    cout << "Input =>";
    cin >> input;

    do {
        cout << "Invalid input." << endl;

        cout << "Input =>";
        cin >> input;
    }

    while (input != 1 || input != 2)

    chooseReport(input);
}

void chooseReport(int option) {     //Choosing what to put in the report (Minimum -> Standard Deviation)

    vector <bool>selectData;
    int subinput1, subinput2;
    string minimumcheck, maximumcheck, mediancheck, meancheck, variancecheck, standardDeviationcheck;

    cout << "Input only one subject number (1 for math, 2 for science, 3 for malay): ";
    cin >> subinput1;
    cout << endl;

    while (minimumcheck != "Y" || minimumcheck != "N") {
        cout << "Minimum? (Y or N): ";
        cin >> minimumcheck;
        boolchecker(minimumcheck,selectData);
    }

    while (maximumcheck != "Y" || maximumcheck != "N") {
        cout << "Maximum? (Y or N): ";
        cin >> maximumcheck;
        boolchecker(maximumcheck,selectData);
    }

    while (mediancheck != "Y" || mediancheck != "N") {
        cout << "Median? (Y or N): ";
        cin >> mediancheck;
        boolchecker(mediancheck,selectData);
    }

    while (meancheck != "Y" || meancheck != "N") {
        cout << "Mean? (Y or N): ";
        cin >> meancheck;
        boolchecker(meancheck,selectData);
    }

    while (variancecheck != "Y" || variancecheck != "N") {
        cout << "Variance? (Y or N): ";
        cin >> variancecheck;
        boolchecker(variancecheck,selectData);
    }

    while (standardDeviationcheck != "Y" || standardDeviationcheck != "N") {
        cout << "Standard Variance? (Y or N): ";
        cin >> standardDeviationcheck;
        boolchecker(standardDeviationcheck,selectData);
    }

}

void chooseReport2(int input, vector<vector<bool> >&selectData) {

    string pearsoncheck, linearProgressioncheck, filename;
    int sub1, sub2;

    while (pearsoncheck != "Y" || pearsoncheck != "N") {
        cout << "Pearson Correlation? (Y or N): ";
        cin >> pearsoncheck;
        boolchecker(meancheck,selectData);
    }

    while (linearProgressioncheck != "Y" || linearProgressioncheck != "N") {
        cout << "Linear Regression Line? (Y or N): ";
        cin >> linearProgressioncheck;
        boolchecker(linearProgressioncheck,selectData);
    }

    cout << "Input two subject numbers: " << endl;
    cout << "1. math" << endl;
    cout << "2. science" << endl;
    cout << "3. malay" << endl;
    cout << " " << endl;

    while (sub1 != 1 || sub1 != 2 || sub1 != 3) {
        cout << "Input the first subject number? ";
        cin >> sub1;

        if (sub1 != 1 || sub1 != 2 || sub1 != 3)
            cout << "Invalid input";
    }

    while (sub2 != 1 || sub2 != 2 || sub2 != 3) {
        cout << "Input the second subject number? ";
        cin >> sub2;

        if (sub2 != 1 || sub2 != 2 || sub2 != 3)
            cout << "Invalid input";
    }

    while (filename != "") {
    cout << "Input the file you want to save the text file report as? (Without the .txt , leave empty for report.txt)";
    cin >> filename

    if (filename == "")
        filename = "report";

    filename += ".txt";
    }

}

void boolchecker(string option, vector<vector<bool> >&selectData) {

    if (option == "Y")
        selectData.push_back(True);

    else if (option == "N")
        selectData.push_back(False);

    else
        cout << "Invalid Input" << endl;

}
