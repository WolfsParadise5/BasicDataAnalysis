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


int minCalc(int valarr[100]) {

    int lownum = valarr[0];

    for (i = 0; i < 100; i++)
    {
        if (valarr[i] < lownum)
        {
            lownum = valarr[i];
        }
    return lownum;
    }

}


int maxCalc(int valarr[100]) {

    int highnum = valarr[0];

    for (i = 0; i < 100; i++)
    {
        if (valarr[i] > highnum)
        {
            highnum = valarr[i];
        }
    return highnum;
    }


}


int medianCalc(int valarr[100]) {

    result = valarr[49];  //Between 0-99
    return result;

}


int meanCalc(int valarr[100]) {

    int total,result;

    for(i = 0; i < 100; i++)
    {
        total += valarr[i];
    }

    total = num / 100;
    return num, result;

}


int varianceCalc(int total,int mean) {

    int result = ((num - mean) ** 2 ) / 100;
    return result;


}


int standardDeviationCalc(int variance) {

    int result = variance ** 0.5;
    return result;

}

