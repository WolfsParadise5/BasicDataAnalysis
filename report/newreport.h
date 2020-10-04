#include<iostream>
#include<vector>
#include<fstream>
#include<string>

using namespace std;

void chooseReport(int option, vector<string> >&selectData);
void chooseReport2(int input, vector<string> >&selectData);
void displayInput();
void fileSaver(input,vector<string> >&selectData);
vector<double> getCalc(vector<string> >&selectData);
void boolchecker(string option, vector<string> >&selectData);


void displayInput() {   //Initial output display

    int option;
    vector <string>selectData;
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

    chooseReport(input, selectData);
    chooseReport2(input, selectData);

    //Check output
    for (int i=0; i < 8; i++) {

        cout << selectData.at(i)

    }
}

void chooseReport(vector<vector<string> >&selectData) {     //Choosing what to put in the report (Minimum -> Standard Deviation)

    int subinput1;
    string minimumcheck, maximumcheck, mediancheck, meancheck, variancecheck, standardDeviationcheck;

    while (subinput1 != 1 || subinput2 != 2 || subinput != 3 || subinput1 != 4) {
    cout << "Input only one subject number (1 for math, 2 for eng, 3 for science, 4 for malay): ";
    cin >> subinput1;
    errorchecker((string)subinput1, selectData);
    cout << endl;
    }

    while (minimumcheck != "Y" || minimumcheck != "N") {
        cout << "Minimum? (Y or N): ";
        cin >> minimumcheck;
        errorcheckerstr(minimumcheck,selectData);
    }

    while (maximumcheck != "Y" || maximumcheck != "N") {
        cout << "Maximum? (Y or N): ";
        cin >> maximumcheck;
        errorcheckerstr(maximumcheck,selectData);
    }

    while (mediancheck != "Y" || mediancheck != "N") {
        cout << "Median? (Y or N): ";
        cin >> mediancheck;
        errorcheckerstr(mediancheck,selectData);
    }

    while (meancheck != "Y" || meancheck != "N") {
        cout << "Mean? (Y or N): ";
        cin >> meancheck;
        errorcheckerstr(meancheck,selectData);
    }

    while (variancecheck != "Y" || variancecheck != "N") {
        cout << "Variance? (Y or N): ";
        cin >> variancecheck;
        errorcheckerstr(variancecheck,selectData);
    }

    while (standardDeviationcheck != "Y" || standardDeviationcheck != "N") {
        cout << "Standard Variance? (Y or N): ";
        cin >> standardDeviationcheck;
        errorcheckerstr(standardDeviationcheck,selectData);
    }

}

void chooseReport2(vector<vector<string> >&selectData) {

    string pearsoncheck, linearProgressioncheck;
    int sub1, sub2;

    while (pearsoncheck != "Y" || pearsoncheck != "N") {
        cout << "Pearson Correlation? (Y or N): ";
        cin >> pearsoncheck;
        errorcheckerstr(pearsoncheck,selectData);
    }

    while (linearProgressioncheck != "Y" || linearProgressioncheck != "N") {
        cout << "Linear Regression Line? (Y or N): ";
        cin >> linearProgressioncheck;
        errorcheckerstr(linearProgressioncheck,selectData);
    }

    cout << "Input two subject numbers: " << endl;
    cout << "1. math" << endl;
    cout << "2. english" << endl;
    cout << "2. science" << endl;
    cout << "3. malay" << endl;
    cout << " " << endl;

    while (sub1 != 1 || sub1 != 2 || sub1 != 3 || sub != 4) {
        cout << "Input the first subject number? ";
        cin >> sub1;
        errorcheckerint(sub1, selectData);
    }

    while (sub2 != 1 || sub2 != 2 || sub2 != 3 || sub != 4) {
        cout << "Input the second subject number? ";
        cin >> sub2;
        errorcheckerint(sub2, selectData);
    }


}

void fileSaver(input,vector<string> >&selectData)  {

    string filename;

    if (input == 1) {

        while (filename != "") {
            cout << "Input the file you want to save the text file report as? (Without the .txt , leave empty for report.txt)";
            cin >> filename

            if (filename == "")
                filename = "report";

            filename += ".txt";
        }
        selectData.push_back(filename);

    }

    if (input == 2) {

        while (filename != "") {
            cout << "Input the file you want to save the text file report as? (Without the .html , leave empty for report.html)";
            cin >> filename

            if (filename == "")
                filename = "report";

            filename += ".html";
        }
        selectData.push_back(filename);

    }

}

vector<double> getCalc(vector<string> >&selectData) {  //Calculates the data requested

    vector<double> numstats;
    vector<string> passedvalues;
    for(int i=0; i< 8; i++) {

        if (selectData.at(i) == "True") {
            switch(i) {
                case 0:
                    numstats.push_back(minimum());
                    passedvalues.push_back("Minimum");
                    break;

                case 1:
                    numstats.push_back(maximum());
                    passedvalues.push_back("Maximum");
                    break;

                case 2:
                    numstats.push_back(median());
                    passedvalues.push_back("Median");
                    break;

                case 3:
                    numstats.push_back(mean());
                    passedvalues.push_back("Mean");
                    break;

                case 4:
                    numstats.push_back(variance());
                    passedvalues.push_back("Variance");
                    break;

                case 5:
                    numstats.push_back(standardDeviation());
                    passedvalues.push_back("Standard Deviation");
                    break;

                case 6:
                    numstats.push_back(corellation());
                    passedvalues.push_back("Pearson Corellation");
                    break;

                case 7:
                    numstats.push_back(linearRegression());
                    passedvalues.push_back("Linear Regression");
                    break;
            }
        }
    }
}

void errorcheckerstr(string option, vector<vector<string> >&selectData) {   //Checks input errors

    if (option == "Y")
        selectData.push_back("True");

    else if (option == "N")
        selectData.push_back("True");

    else
        cout << "Invalid Input" << endl;

}

void errorcheckerint(int option, vector<vector<string> >&selectData) {


    if (option == 1)
        selectData.push_back("Math");

    else if (option == 2)
        selectData.push_back("English");

    else if (option == 3)
        selectData.push_back("Science");

    else if (option == 4)
        selectData.push_back("Malay");

    else
        cout << "Invalid Input" << endl;


}
