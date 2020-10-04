#include <iostream>
#include <vector> // for vector
#include <algorithm> // for min_element & max_element
#include <iomanip>

using namespace std;

//global
string separator = " |";

//tables
string displayColumn(const vector<vector<int> > &data, const vector<string> &headers, int width);//return line
void displayMax(const vector<vector<int> > &data, const vector<string> &headers);
//minimum
int minimum(const vector<int> &column);
//maximum
int maximum(const vector<int> &column);
//mean
double mean(const vector<int> column);
//median
double median(const vector<int> column);

int minimum(const vector<int> &column)
{
    return *min_element(column.begin(), column.end());
}

int maximum(const vector<int> &column)
{
    return *max_element(column.begin(), column.end());
}

double mean(const vector<int> column)
{
    double sum = accumulate(column.begin(), column.end(), 0);
    double mean = sum / column.size();
    return mean;
}

double median(const vector<int> column)
{
double median(const vector<int> column)
{
    int size = column.size();
    sort(number.begin(), number.end());
    if (column % 2 == 0)
    {
        return (double)(column[column.size / 2 - 1] + scores[column.size / 2]) / 2;
    }
    else
    {
        return (double)column[column.size / 2]
    }
}
}

double variance(const vector<int> column)
{
    double m = mean(column)

    double variance = 0;
    for (int i = 0; i < column.size() ;i++)
    {
        variance += ((column[i] - m) * (column[i] - m));
    }
    double total = variance / (column.size() - 1);
    return total;
}

double standardDeviation(const vector<int> column)
{
    double v = variance(column);
    return sqrt(v);
}

vector<vector<int>> aboveBelow (const vector<vector<int>>& vec, int choice)
{
    double m = mean(get1dData(vec, choice));
    vector<vector<int>> v = vec;
    sortAscending (v, choice);
    vector<vector<int>> result;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i][choice] < m)
        {
            result.push_back(v[i]);
        }
    }
    return result;

}

string displayColumn(const vector<vector<int> > &data, const vector<string> &headers, int width)
{
    int numFields = headers.size() - 1;
    int totalWidth = (width * numFields) + (separator.size() * numFields);
    string line = separator + string(totalWidth - 1, '-') + "|";

    //print table headers
    cout << line << endl;
    cout << separator;
    for(int i = 1; i < headers.size(); ++i)
        cout << setw(width) << headers[i] << separator;
    cout << endl << line << endl;

    //print table body
    for(int i = 0; i < data.size(); ++i)
    {
        cout << separator;
        for(int j = 1; j < headers.size(); ++j)
            cout << setw(width) << data[i][j] << separator;
        cout << endl;
    }
    cout << line << endl;

    return line;
}
