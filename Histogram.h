#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

void histogram (const vector <int>&value, const vector <int>&ID);

//int main (){
//    vector <int> value = {10, 25, 15};
//    vector <int> ID    = {1191100001, 1191101212, 1191100350};
//    histogram (value, ID);
//    return 0;
//}

void histogram(const vector <int>&value, const vector <int>&ID){

    int width = 10;
    int dataWidth = 100;//test
    string seperator = " |";
    string line = seperator + string(width + dataWidth + (seperator.size()*2) - 1, '-') + "|";
    //header
    cout << " * = 1" << endl;
    cout << line << endl;
    cout << seperator << setw(width)<< "ID" << seperator << left << setw(dataWidth) << " Values" << seperator << endl;
    cout << line << endl;

        for (int i = 0; i < value.size(); i++)
        {
            cout << right << seperator << setw(width) << ID[i] << left << seperator;//id
                for (int j = 0; j < dataWidth; j++){
                    if(value[i] > j)
                        cout << "*";
                    else
                        cout << " ";
                }
            cout << seperator << endl;
        }
    cout << line << endl;
}
