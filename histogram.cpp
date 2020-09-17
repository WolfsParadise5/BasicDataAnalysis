#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

void histogram (const vector <int>&value, const vector <int>&ID);

int main (){
    vector <int> value = {10, 25, 15};
    vector <int> ID    = {1191100001, 1191101212, 1191100350};
    histogram (value, ID);
    return 0;
}

void histogram (const vector <int>&value, const vector <int>&ID){
    cout << "ID" << setw(20) << "value" << endl;
    cout << string (30, '-') << endl;
        for (int i = 0; i < value.size(); i++)
        {
            cout << ID[i];
                for (int j = 0; j < value[i]; j++)
                    cout << setw(8) << "*";
         cout << endl;
        }
}
