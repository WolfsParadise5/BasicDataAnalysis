#include <iostream>
using namespace std;

int minCalc(int);
int maxCalc(int);
int medianCalc(int);
int meanCalc(double);
int varianceCalc(double);
int standardDeviationCalc(double);

int main() {


}


///Source : https://www.bitdegree.org/learn/c-plus-plus-vector
///Source : 

#include<iostream>
#include<vector>

using namespace std;

int main() {

    int mincalc(vector<int>& number);
    int maxcalc(vector<int>& number);
    int meancalc(vector<int>& number);
    int mediancalc(vector<int>& number);
    int variancecalc(vector<int>& number);
    int standardDeviationCalc(vector<int>& number);
}

int minCalc(vector<int>& number) {

    int min = *min_element(number.begin(),number.end());
    return min;
}

int maxCalc(vector<int>& number) {

    int max = *max_element(number.begin(),number.end());
    return max;

}

int meanCalc(vector<int>& number)  {
    double total = accumulate(number.begin(), number.end(),0);
    double val = total / 100;
    return total, val; 
}

double medianCalc(vector<int>& number) {

    sort(number.begin(), number.end());
    return (number[100 / 2 - 1] + number[100 / 2]) / 2;

}

double varianceCalc(vector<int>& number) {

    double total = accumulate(number.begin(), number.end(),0);
    double mean = total / 100;
    double variance = (total - mean) ** 2 / 100;
    return variance;

}

double standardDeviationCalc(vector<int>& number) {

    double total = accumulate(number.begin(), number.end(),0);
    double mean = total / 100;
    double variance = (total - mean) ** 2 / 100;
    double standardDeviation = variance ** 0.5;
    return standardDeviation;

}

