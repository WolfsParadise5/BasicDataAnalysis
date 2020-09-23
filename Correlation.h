#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

using namespace std;

void correlation(const vector<int> &column1, const vector<int> &column2, string subject1, string subject2);
void displayCorrelTable(const vector<int> &column1, const vector<int> &column2, string subject1, string subject2, int width);
double sumCorrel(const vector<int> &column1, const vector<int> &column2);

double mean(const vector<int> column)
{
    double total = 0;
    for(int i = 0; i < column.size(); ++i)
        total += column[i];

    return total / column.size();
}

void correlation(const vector<int> &column1, const vector<int> &column2, string subject1, string subject2)
{
    cout << " Column 1: " << subject1 << endl;
    cout << " Column 2: " << subject2 << endl;

    displayCorrelTable(column1, column2, subject1, subject2, 11);

    cout << " mean_x = " << mean(column1) << ", mean_y = " << mean(column2) << endl;
    cout << " Correlation Computation = sum(a * b) / sqrt(sum(a * a) * sum(b * b))" << endl;
    cout << " Correlation Computation = " << sumCorrel(column1, column2) << " / sqrt("
        << sumCorrel(column1, column1) << " * " << sumCorrel(column2, column2) << ")" << endl;

    double correl = sumCorrel(column1, column2) / sqrt(sumCorrel(column1, column1) * sumCorrel(column2, column2));

    cout << "Correlation Computation = " << correl << endl;
}

void displayCorrelTable(const vector<int> &column1, const vector<int> &column2, string subject1, string subject2, int width)
{
    int numFields = 7;
    string seperator = " |";
    string result = "Sum: ";
    int totalWidth = (width * numFields) + seperator.size() * numFields;
    string line = seperator + string(totalWidth - 1, '-') + "|";
    double mean1 = mean(column1);
    double mean2 = mean(column2);
    //display headers
    cout << line << endl;
    cout << seperator << setw(width) << subject1 + "/x" << seperator
        << setw(width) << subject2 + "/y" << seperator
        << setw(width) << "a=x-mean_x" << seperator
        << setw(width) << "b=y-mean_y" << seperator
        << setw(width) << "a * b" << seperator
        << setw(width) << "a * a" << seperator
        << setw(width) << "b * b" << seperator << endl;
    cout << line << endl;
    //values
//    double totalA, totalB, n;
//    totalA = totalB = n = 0;
    for(int i = 0; i < column1.size(); ++i)
    {
        double a = column1[i] - mean1;
        double b = column2[i] - mean2;
        cout << seperator << setw(width) << column1[i] << seperator
            << setw(width) << column2[i] << seperator
            << setw(width) << a << seperator
            << setw(width) << b << seperator
            << setw(width) << a * b << seperator
            << setw(width) << a * a << seperator
            << setw(width) << b * b << seperator << endl;
//        totalA += a * a;
//        totalB += b * b;
//        n += a * b;
    }
    cout << line << endl;
    cout << seperator << setw(width*4 + seperator.size()*4) << result//jump to column 4
        << setw(width) << sumCorrel(column1, column2) << seperator
        << setw(width) << sumCorrel(column1, column1) << seperator
        << setw(width) << sumCorrel(column2, column2) << seperator << endl;
    cout << line << endl;
}
double sumCorrel(const vector<int> &column1, const vector<int> &column2)
{
    double total = 0;
    double meanNum1 = mean(column1);
    double meanNum2 = mean(column2);

    for(int i = 0; i < column1.size(); ++i)
    {
        double a = column1[i] - meanNum1;
        double b = column2[i] - meanNum2;

        total += a * b;
    }

    return total;
}
