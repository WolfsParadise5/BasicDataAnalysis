#import<iostream>
#import<fstream>

using namespace std;

void fileopener();
void htmltable();

int main() {
//NOTE : CHANGES REPRESENTING THE DOCUMENTATION WILL BE ADDED NEXT WEEK
fileopener();



}

void fileopener() {

    ofstream htmlreport;
    htmlreport.open("report.html");
    htmlreport << "<!DOCTYPE html>\n<html>\n<head>\nTable Report\n</head>\n<body>" << endl;
    htmlreport.close();
    reportgen();

}

void reportgen() {

    ofstream htmledit;
    htmledit.open("report.html");
    htmledit << "<p>Trying this function out</p>";

}
