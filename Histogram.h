#include "Compute.h"

void histogram (const vector <int>&value, const vector <int>&ID);

void histogram(const vector <int>&value, const vector <int>&ID){

    int width = 10;
    int dataWidth = maximum(value);//get maximum width
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
