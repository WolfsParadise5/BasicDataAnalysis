#include <iostream>
using namespace std;

int minCalc(int);
int maxCalc(int);
int medianCalc(int);
int meanCalc(int);
int varianceCalc(int);
int standardDeviationCalc(int);

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
    int total = accumulate(number.begin(), number.end(),0);
    int val = total / 100;
    return total, val; 
}

int medianCalc(vector<int>& number) {

    size_t vecsize = number.size();
    sort(number.begin(), number.end());
    return (number[vecsize / 2 - 1] + number[size / 2]) / 2;

}

int varianceCalc(vector<int>& number) {

    int total = accumulate(number.begin(), number.end(),0);
    int mean = total / 100;
    int variance = (total - mean) ** 2 / 100;
    return variance;

}

int standardDeviationCalc(vector<int>& number) {

    int total = accumulate(number.begin(), number.end(),0);
    int mean = total / 100;
    int variance = (total - mean) ** 2 / 100;
    int standardDeviation = variance ** 0.5;
    return standardDeviation;

}

