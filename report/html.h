#import<iostream>
#import<fstream>
#import<string>

using namespace std;

void reporthtml(//const vector<string> &headers, const vector<vector<int> >&data);
void reportmath();
void reporteng();
void reportsci();
void reportmalay();


void reporthtml(//const vector<string> &headers, const vector<vector<int> >&data) {

    ofstream htmlreport;
    htmlreport.open("report.html");
    htmlreport << "<!DOCTYPE html>\n<html>\n<head>\nTable Report\n</head>\n<body>" << endl;
    htmlreport.close();
    reportmath();
    reporteng();
    reportsci();
    reportmalay();

}

void reportmath() {

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
    contentTable("Math");

}

void reporteng() {          //Add report for English

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
    contentTable("English");


}

void reportsci() {         //Add report for Science

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
    contentTable("Science");

}

void reportmalay() {   //Add report for Malay

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
    contentTable("Malay"); //string subject to change

}

void contentTable(string type) {   //Add the content
    //STRING FUNCTION SUBJECT TO CHANGE
    ofstream htmledit;
    htmledit.open("report.html");

    htmledit << "   <tr>";
    htmledit << "       <td>Mininum</td>";
    htmledit << "       <td>Value</td>";
    htmledit << "   </tr>";


    htmledit << "   <tr>";
    htmledit << "       <td>Maximum</td>";
    htmledit << "       <td>Value</td>";
    htmledit << "   </tr>";


    htmledit << "   <tr>";
    htmledit << "       <td>Mininum</td>";
    htmledit << "       <td>Value</td>";
    htmledit << "   </tr>";


    htmledit << "   <tr>";
    htmledit << "       <td>Mininum</td>";
    htmledit << "       <td>Value</td>";
    htmledit << "   </tr>";


    htmledit << "   <tr>";
    htmledit << "       <td>Mininum</td>";
    htmledit << "       <td>Value</td>";
    htmledit << "   </tr>";


    htmledit << "   <tr>";
    htmledit << "       <td>Mininum</td>";
    htmledit << "       <td>Value</td>";
    htmledit << "   </tr>";


}
