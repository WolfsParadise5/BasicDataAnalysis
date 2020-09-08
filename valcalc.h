///Source : https://www.bitdegree.org/learn/c-plus-plus-vector
#include <iostream>
#include <vector>

using namespace std;

int main() {

    int mincalc(vector<int>& number);
    int maxcalc(vector<int>& number);
    float meancalc(vector<int>& number);
    float mediancalc(vector<int>& number);
    double variancecalc(vector<int>& number);
    double standardDeviationCalc(vector<int>& number);
}

int minCalc(vector<int>& number) {

    int min = *min_element(number.begin(),number.end());
    return min;
}

int maxCalc(vector<int>& number) {

    int max = *max_element(number.begin(),number.end());
    return max;

}

float meanCalc(vector<int>& number)  {
    double total = accumulate(number.begin(), number.end(),0);
    double val = total / 100;
    return total, val;
}

float medianCalc(vector<int>& number) {

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

