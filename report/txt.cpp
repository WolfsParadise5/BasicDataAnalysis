#include<iostream>
#include<fstream>

using namespace std;
//NOTE: FUNCTIONS FOLLOWING THE DOCUMENTATION WILL BE ADDED NEXT WEEK
void fileOpener();
void reportGenerator();

int main()
{

    fileOpener();
    reportGenerator();

}

void fileOpener() //Creates the file
{

    ofstream txtreport;
    txtreport.open("report.txt");
    txtreport << "Data Analysis Report" << endl;
    txtreport.close();

}

void reportGenerator() //Outputs the report
{

    ofstream reportgen;
    reportgen.open("report.txt");

    //Data to input starts here



}


