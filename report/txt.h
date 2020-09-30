#include<iostream>
#include<fstream>

using namespace std;
//NOTE: FUNCTIONS FOLLOWING THE DOCUMENTATION WILL BE ADDED NEXT WEEK
reportTxt(const vector<string> &headers, const vector<vector<int> >&data)
void reportmath();
void reportsci();
void reporteng();
void reportmalay()


//void txtreport() {
//
//   reportmath();
//    reportsci();
//    reporteng();
//    reportmalay();

//}


reportTxt(const vector<string> &headers, const vector<vector<int> >&data)//Creates the file
{

    ofstream txtreport;
    txtreport.open("report.txt");
    txtreport << "Report for the Subject Math: " << endl;
    txtreport << "Minimum: " << data[0] << endl;
    txtreport << "Maximum: " << data[1] << endl;
    txtreport << "Mean: " << data[2] << endl;
    txtreport << "Median: " << data[3] << endl;
    txtreport << "Variance: " << data[4] << endl;
    txtreport << "Standard Deviance: " << data[5] << endl;

    txtreport.close();

}

//void reportsci() //Outputs the report
//{

//    ofstream reportgen;
//    reportgen.open("report.txt");
//    txtreport << "Report for the Subject Science: " << endl;
//    txtreport << "Minimum: " << endl;
//    txtreport << "Maximum: " << endl;
//    txtreport << "Mean: " << endl;
//    txtreport << "Median: " << endl;
//    txtreport << "Variance: " << endl;
//txtreport << "Standard Deviance: " << endl;

//   txtreport.close();

//}



