//reference : http://www.cplusplus.com/reference/algorithm/min/

#include <iostream>
#include <vector> // for vector
#include <algorithm> // for min_element & max_element
using namespace std;

int main()
{
    vector <int> grades = {93,92,76,87};

    cout << "Minimum = "
         << *min_element(grades.begin(), grades.end());

    cout << endl;

    cout << "Maximum = "
         << *max_element(grades.begin(), grades.end());

return 0;
}
