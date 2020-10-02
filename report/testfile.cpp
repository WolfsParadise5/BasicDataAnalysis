#include<iostream>
#include<vector>
#include"html.h"
#include"txt.h"

using namespace std;

int main() {

    vector <int>data = {4,5,6,3,4,5};
    vector <string>header = {"Minimum", "Maximum", "Min", "Median", "Variance", "Standard Deviation"}
    vector <string>header1 = {"Math","Minimum", "Maximum", "Min", "Median", "Variance", "Standard Deviation"}
    vector <string>header2 = {"English", "Minimum", "Maximum", "Min", "Median", "Variance", "Standard Deviation"}
    vector <string>header3 = {"Science","Minimum", "Maximum", "Min", "Median", "Variance", "Standard Deviation"}
    vector <string>header4 = {"Malay","Minimum", "Maximum", "Min", "Median", "Variance", "Standard Deviation"}

    reportTxt(data,header);
    reporthtml(data,header);




}
