#include<iostream>
#include<fstream>
#include<vector>
#include<string>

using namespace std;

void reportTxt(const vector<string> &headers, const vector<vector<int> >&data); // Starter function to run the other functions
vector<double> convData(const vector<vector<int> >&data); //Convert data for report usage
void addReportTxt(const vector<string> &type, const vector<vector<int> >&reportdata); // Starts the report creation
void addReportHtml(const vector<string> &type, const vector<vector<int> >&reportdata); // Starts the report creationn for html


void reportTxt(const vector<string> &headers, const vector<vector<int> >&data){

    vector<double> reportdata = convData(data);

    //Might need to fix the subject passing matter
    vector<string> reporttype = {"Math","Minimum", "Maximum", "Min", "Median", "Variance", "Standard Deviation"};

    //Difference starts here
    addReportTxt(reporttype, reportdata);
    addReportHtml(reporttype, reportdata);

}


vector<double> convData(const vector<vector<int> >&data) {

    vector<double> reportdata;

    //Might require typecasting
    reportdata.push_back(minimum(data));
    reportdata.push_back(maximum(data));
    reportdata.push_back(mean(data));
    reportdata.push_back(median(data));
    reportdata.push_back(variance(data));
    reportdata.push_back(standardDeviation(data));

    return reportdata;

}


void addReportTxt(const vector<string> &type, const vector<vector<int> >&reportdata) {

    ofstream txtreport;
    txtreport.open("report.txt");

    //The way function is passed needs reworking
    if (type[0] == "Math")
        txtreport << "Report for the Subject Math";

    else if (type[0] == "English")
        txtreport << "Report for the Subject English";

    else if (type[0] == "Science")
        txtreport << "Report for the Subject Science";

    else if (type[0] == "Malay")
        txtreport << "Report for the Subject Malay";


    for(int i = 1; i < 7; ++i) {    //to write first item to txt

        for (int j=0; j < 6; ++j) {

            txtreport << type.at(i) <<": " << reportdata.at(j) << endl;

    }


    txtreport.close();

}


void addReportHtml(const vector<string> &type, const vector<vector<int> >&reportdata) {

    ofstream htmlreport;
    htmlreport.open("report.html");

    htmlreport << "<!DOCTYPE html>\n<html>\n<head>\nTable Report\n</head>\n<body>" << endl;
    //The way function is passed needs reworking
    if (type[0] == "Math")
        txtreport << "<h1>Report for the Subject Math</h1>";

    else if (type[0] == "English")
        txtreport << "<h1>Report for the Subject English</h1>";

    else if (type[0] == "Science")
        txtreport << "<h1>Report for the Subject Science</h1>";

    else if (type[0] == "Malay")
        txtreport << "<h1>Report for the Subject Malay</h1>";

    htmlreport << "<p></p>" << endl;  //Create gap

    //Content
    htmlreport << "<table>" << endl;
    htmlreport << "   <tr>" << endl;
    htmlreport << "       <th>Stat Name</th>" << endl;
    htmlreport << "       <th>Value</th>" << endl;
    htmlreport << "   </tr>" << endl;

    for(int i = 1; i < 7; ++i) {    //to write first item to txt

        for (int j=0; j < 6; ++j) {

            htmlreport << "   <tr>" << endl;
            htmlreport << "       <td>" << type.at(i) << "</td>" << endl;
            htmlreport << "       <td>" << reportdata.at(j) << "</td>" << endl;
            htmlreport << "   </tr>" << endl;

    }


    htmlreport.close();



}
