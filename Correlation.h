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
    string separator = " |";
    string result = "Sum: ";
    int totalWidth = (width * numFields) + separator.size() * numFields;
    string line = separator + string(totalWidth - 1, '-') + "|";
    double mean1 = mean(column1);
    double mean2 = mean(column2);
    //display headers
    cout << line << endl;
    cout << separator << setw(width) << subject1 + "/x" << separator
        << setw(width) << subject2 + "/y" << separator
        << setw(width) << "a=x-mean_x" << separator
        << setw(width) << "b=y-mean_y" << separator
        << setw(width) << "a * b" << separator
        << setw(width) << "a * a" << separator
        << setw(width) << "b * b" << separator << endl;
    cout << line << endl;
    //values
//    double totalA, totalB, n;
//    totalA = totalB = n = 0;
    for(int i = 0; i < column1.size(); ++i)
    {
        double a = column1[i] - mean1;
        double b = column2[i] - mean2;
        cout << separator << setw(width) << column1[i] << separator
            << setw(width) << column2[i] << separator
            << setw(width) << a << separator
            << setw(width) << b << separator
            << setw(width) << a * b << separator
            << setw(width) << a * a << separator
            << setw(width) << b * b << separator << endl;
//        totalA += a * a;
//        totalB += b * b;
//        n += a * b;
    }
    cout << line << endl;
    cout << separator << setw(width*4 + separator.size()*4) << result//jump to column 4
        << setw(width) << sumCorrel(column1, column2) << separator
        << setw(width) << sumCorrel(column1, column1) << separator
        << setw(width) << sumCorrel(column2, column2) << separator << endl;
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
