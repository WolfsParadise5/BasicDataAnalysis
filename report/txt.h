#include<iostream>
#include<fstream>

using namespace std;
//NOTE: FUNCTIONS FOLLOWING THE DOCUMENTATION WILL BE ADDED NEXT WEEK
void reportTxt();
void reportmath();
void reportsci();
void reporteng();
void reportmalay()


void txtreport() {

    reportmath();
    reportsci();
    reporteng();
    reportmalay();

}


void reportTxt() //Creates the file
{

    ofstream txtreport;
    txtreport.open("report.txt");
    txtreport << "Report for the Subject Math: " << endl;
    txtreport << "Minimum: " << endl;
    txtreport << "Maximum: " << endl;
    txtreport << "Mean: " << endl;
    txtreport << "Median: " << endl;
    txtreport << "Variance: " << endl;
    txtreport << "Standard Deviance: " << endl;

    txtreport.close();

}

void reportsci() //Outputs the report
{

    ofstream reportgen;
    reportgen.open("report.txt");
    txtreport << "Report for the Subject Science: " << endl;
    txtreport << "Minimum: " << endl;
    txtreport << "Maximum: " << endl;
    txtreport << "Mean: " << endl;
    txtreport << "Median: " << endl;
    txtreport << "Variance: " << endl;
    txtreport << "Standard Deviance: " << endl;

    txtreport.close();

}

void reporteng() //Outputs the report
{

    ofstream reportgen;
    reportgen.open("report.txt");
    txtreport << "Report for the Subject English: " << endl;
    txtreport << "Minimum: " << endl;
    txtreport << "Maximum: " << endl;
    txtreport << "Mean: " << endl;
    txtreport << "Median: " << endl;
    txtreport << "Variance: " << endl;
    txtreport << "Standard Deviance: " << endl;

    txtreport.close();

}

void reportmalay() //Outputs the report
{

    ofstream reportgen;
    reportgen.open("report.txt");
    txtreport << "Report for the Subject Malay: " << endl;
    txtreport << "Minimum: " << endl;
    txtreport << "Maximum: " << endl;
    txtreport << "Mean: " << endl;
    txtreport << "Median: " << endl;
    txtreport << "Variance: " << endl;
    txtreport << "Standard Deviance: " << endl;

    txtreport.close();

}


