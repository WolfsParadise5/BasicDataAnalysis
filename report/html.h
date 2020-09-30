#import<iostream>
#import<fstream>
#import<string>

using namespace std;

void reporthtml(const vector<string> &headers, const vector<vector<int> >&data);
void reportmath(const vector<vector<int> >&data);
void reporteng(const vector<vector<int> >&data);
void reportsci(const vector<vector<int> >&data);
void reportmalay(const vector<vector<int> >&data);


void reporthtml(const vector<string> &headers, const vector<vector<int> >&data) {

    ofstream htmlreport;
    htmlreport.open("report.html");
    htmlreport << "<!DOCTYPE html>\n<html>\n<head>\nTable Report\n</head>\n<body>" << endl;
    htmlreport.close();
    reportmath();
    reporteng();
    reportsci();
    reportmalay();

}

void reportmath(const vector<vector<int> >&data) {

    ofstream htmledit;
    htmledit.open("report.html");
    htmledit << "<h1>Math table report</h1>";
    htmledit << "<p></p>";

    //Table header
    htmledit << "<table>";
    htmledit << "   <tr>";
    htmledit << "       <th>Stat Name</th>";
    htmledit << "       <th>Value</th>";
    htmledit << "   </tr>";

    //Table Contents
    htmlreport.close();
    contentTable(const vector<vector<int> data);

}

void reporteng(const vector<vector<int> data) {          //Add report for English

    ofstream htmledit;
    htmledit.open("report.html");
    htmledit << "<h1>English table report</h1>";
    htmledit << "<p></p>"  //Spacing

    //Table header
    htmledit << "<table>";
    htmledit << "   <tr>";
    htmledit << "       <th>Stat Name</th>";
    htmledit << "       <th>Value</th>";
    htmledit << "   </tr>";

    //Table Contents
    htmlreport.close();
    contentTable(const vector<vector<int> data);


}

void reportsci(const vector<vector<int> >&data) {         //Add report for Science

    ofstream htmledit;
    htmledit.open("report.html");
    htmledit << "<h1>Science table report</h1>";
    htmledit << "<p></p>"  //Spacing

    //Table header
    htmledit << "<table>";
    htmledit << "   <tr>";
    htmledit << "       <th>Stat Name</th>";
    htmledit << "       <th>Value</th>";
    htmledit << "   </tr>";

    //Table Contents
    htmlreport.close();
    contentTable(const vector<vector<int> data);

}

void reportmalay(const vector<vector<int> >&data) {   //Add report for Malay

    ofstream htmledit;
    htmledit.open("report.html");
    htmledit << "<h1>Malay table report</h1>";
    htmledit << "<p></p>"  //Spacing

    //Table header
    htmledit << "<table>";
    htmledit << "   <tr>";
    htmledit << "       <th>Stat Name</th>";
    htmledit << "       <th>Value</th>";
    htmledit << "   </tr>";

    //Table Contents
    htmlreport.close();
    contentTable(const vector<vector<int> data); //string subject to change

}

void contentTable(const vector<vector<int> >&data) {   //Add the content
    //STRING FUNCTION SUBJECT TO CHANGE
    ofstream htmledit;
    htmledit.open("report.html");

    htmledit << "   <tr>";
    htmledit << "       <td>Mininum</td>";
    htmledit << "       <td>" << data[0] << "</td>";
    htmledit << "   </tr>";


    htmledit << "   <tr>";
    htmledit << "       <td>Maximum</td>";
    htmledit << "       <td>" << data[1] << "</td>";
    htmledit << "   </tr>";


    htmledit << "   <tr>";
    htmledit << "       <td>Min</td>";
    htmledit << "       <td>" << data[2] << "</td>";
    htmledit << "   </tr>";


    htmledit << "   <tr>";
    htmledit << "       <td>Median</td>";
    htmledit << "       <td>" << data[3] << "</td>";
    htmledit << "   </tr>";


    htmledit << "   <tr>";
    htmledit << "       <td>Variance</td>";
    htmledit << "       <td>" << data[4] << "</td>";
    htmledit << "   </tr>";


    htmledit << "   <tr>";
    htmledit << "       <td>Standard Deviation</td>";
    htmledit << "       <td>" << data[5] << "</td>";
    htmledit << "   </tr>";

    htmledit.close();


}
