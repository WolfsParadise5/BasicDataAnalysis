#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int sum(const vector<int> &column);
int sumMultiplication(const vector<int> &column1, const vector<int> &column2);
double slope(const vector<int> &column1, const vector<int> &column2);
double intercept(const vector<int> &column1, const vector<int> &column2, double slope);
void displayLinearTable(const vector<int> &column1, const vector<int> &column2, string subject1, string subject2, int width);
void linearRegression(const vector<int> &column1, const vector<int> &column2, string subject1, string subject2);

void linearRegression(const vector<int> &column1, const vector<int> &column2, string subject1, string subject2)
{
    cout << " Column 1: " << subject1 << endl;
    cout << " Column 2: " << subject2 << endl;

    displayLinearTable(column1, column2, subject1, subject2, 12);

    double slopeNum = slope(column1, column2);
    double interceptNum = intercept(column1, column2, slopeNum);

    cout << " Line Equation: y = mx + c" <<endl;
    if(interceptNum < 0)
        cout << " Line Equation: y = " << slopeNum << "x - " << -interceptNum << endl;//make intercept +ive
    else
        cout << " Line Equation: y = " << slopeNum << "x + " << interceptNum << endl;
}

void displayLinearTable(const vector<int> &column1, const vector<int> &column2, string subject1, string subject2, int width)
{
    int numFields = 4;
    string separator = " |";
    string result = "Sum: ";
    int totalWidth = (width * numFields) + separator.size() * numFields;
    string line = separator + string(totalWidth - 1, '-') + "|";
    //display headers
    cout << line << endl;
    cout << separator << setw(width) << subject1 + "/x" << separator
        << setw(width) << subject2 + "/y" << separator
        << setw(width) << "x * x" << separator
        << setw(width) << "x * y" << separator << endl;
    cout << line << endl;
    //display values
    for(int i = 0; i < column1.size(); ++i)
        cout << separator << setw(width) << column1[i] << separator
            << setw(width) << column2[i] << separator
            << setw(width) << column1[i]*column1[i] << separator
            << setw(width) << column1[i]*column2[i] << separator << endl;
    //display result
    cout << line << endl;
    cout << separator << result
        << setw(width - result.size()) <<sum(column1) << separator
        << setw(width) << sum(column2) << separator
        << setw(width) << sumMultiplication(column1, column1) << separator
        << setw(width) << sumMultiplication(column1, column2) << separator << endl;
    cout << line << endl;
}

double slope(const vector<int> &column1, const vector<int> &column2)
{
    int n = column1.size();

    cout << " Slope, m = (n * sum(x*y) - sum(x) * sum(y)) / (n * sum(x*x) - sum(x) * sum(x))" << endl; //formula
    //steps
    cout << " Slope, m = (" << n << " * " << sumMultiplication(column1, column2)
        << " - " << sum(column1) << " * " << sum(column2) << ") / "
        << "(" << n << " * " << sumMultiplication(column1, column1)
        << " - " << sum(column1) << " * " << sum(column1) << "))" << endl;

    double slope = static_cast<double>(n * sumMultiplication(column1, column2) - sum(column1) * sum(column2)) /
                    (n * sumMultiplication(column1, column1) - sum(column1) * sum(column1));

    cout << " Slope, m = " << slope << endl;

    return slope;
}

double intercept(const vector<int> &column1, const vector<int> &column2, double slope)
{
    int n = column1.size();

    cout << " Intercept, c = sum(y) - m * sum(x) / n" << endl; //formula
    //steps
    cout << " Intercept, c = " << sum(column2) << " - " << slope << " * " << sum(column1) << " / " << n << endl;

    double intercept = static_cast<double>((sum(column2) - slope * sum(column1)) / n);

    cout << " Intercept, c = " << intercept << endl;

    return intercept;
}

int sum(const vector<int> &column)
{
    int sum = 0;

    for(int i = 0; i < column.size(); ++i)
        sum += column[i];

    return sum;
}

int sumMultiplication(const vector<int> &column1, const vector<int> &column2)
{
    int sum = 0;

    for(int i = 0; i < column1.size(); ++i)
        sum += column1[i]*column2[i];

    return sum;
}

