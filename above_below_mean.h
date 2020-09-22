#include <iostream>
#include <vector>

using namespace std;
vector<int> aboveMean(vector<int>& number, const int &MEAN);
vector <int> belowMean(vector<int>& number, const int &MEAN);

vector<int> aboveMean(vector<int>& number, const int &MEAN)
{
    sort(number.begin(), number.end());
    int integer = 0;
    for(int i = 0; i < 100; i++)
    {
        if (number[i] == MEAN)
            integer = i;
            break;
    }
    vector <int> ABOVEMEAN;
    for (int j = integer + 1; j < 100; j++)
    {
        ABOVEMEAN += number[j];
    }
    return ABOVEMEAN;
}

vector <int> belowMean(vector<int>& number, const int &MEAN)
{
    sort(number.begin(), number.end());
    int integer = 0;
    for(int i = 0; i < 100; i++)
    {
        if (number[i] == MEAN)
            integer = i;
            break;
    }
    vector <int> BELOWMEAN;
    for (int j = integer - 1; j <= 0; j--)
    {
        BELOWMEAN += number[j];
    }
    return BELOWMEAN;
}

