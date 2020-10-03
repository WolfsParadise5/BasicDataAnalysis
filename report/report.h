#include<iostream>
#include<fstream>
#include<vector>
#include<string>

using namespace std;

void reportTxt(); // Starter function to run the other functions
void addReportTxt(const vector<string> &type, const vector<double> &reportdata); // Starts the report creation
void addReportHtml(const vector<string> &type, const vector<double> &reportdata); // Starts the report creation for html


void reportTxt(){

    const vector<double> reportdata = {2.3,45.2,2.2,24.3,6.4,3.1};

    //Might need to fix the subject passing matter
    const vector<string> reporttype = {"Math","Minimum", "Maximum", "Min", "Median", "Variance", "Standard Deviation"};

    //Difference starts here
    addReportTxt(reporttype, reportdata);
    addReportHtml(reporttype, reportdata);

}

void addReportTxt(const vector<string> &type, const vector<double> &reportdata) {

    ofstream txtreport;
    txtreport.open("report.txt");

    //The way function is passed needs reworking
    if (type[0] == "Math")
        txtreport << "Report for the Subject Math" << endl;

    else if (type[0] == "English")
        txtreport << "Report for the Subject English" << endl;

    else if (type[0] == "Science")
        txtreport << "Report for the Subject Science" << endl;

    else if (type[0] == "Malay")
        txtreport << "Report for the Subject Malay" << endl;


    for(int i = 1; i < 7; ++i) {    //to write first item to txt

        txtreport << type.at(i) <<": " << reportdata.at(i-1) << endl;

    }


    txtreport.close();

}


void addReportHtml(const vector<string> &type, const vector<double> &reportdata) {

    ofstream htmlreport;
    htmlreport.open("report.html");

    htmlreport << "<!DOCTYPE html>\n<html>\n<head>\nTable Report\n</head>\n<body>" << endl;
    //The way function is passed needs reworking
    if (type[0] == "Math")
        htmlreport << "<h1>Report for the Subject Math</h1>";

    else if (type[0] == "English")
        htmlreport << "<h1>Report for the Subject English</h1>";

    else if (type[0] == "Science")
        htmlreport << "<h1>Report for the Subject Science</h1>";

    else if (type[0] == "Malay")
        htmlreport << "<h1>Report for the Subject Malay</h1>";

    htmlreport << "<p></p>" << endl;  //Create gap

    //Content
    htmlreport << "<table>" << endl;
    htmlreport << "   <tr>" << endl;
    htmlreport << "       <th>Stat Name</th>" << endl;
    htmlreport << "       <th>Value</th>" << endl;
    htmlreport << "   </tr>" << endl;

    for(int i = 1; i < 7; ++i) {    //to write first item to txt

            htmlreport << "   <tr>" << endl;
            htmlreport << "       <td>" << type.at(i) << "</td>" << endl;
            htmlreport << "       <td>" << reportdata.at(i-1) << "</td>" << endl;
            htmlreport << "   </tr>" << endl;

    }




    htmlreport.close();

}
