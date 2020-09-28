#include <iostream>
#include <vector>

using namespace std;

void sortAscending (vector<vector<int>>& vec, int choice)
{
    int minIndex, minValue;

    for(int i = 0; i < vec.size(); ++i) //vec.size() returns the number of elements in vector
    {
      minIndex = i;
      minValue = vec[i][choice];

      for(int j = i+1; j < vec.size(); ++j)
      {
        if(vec[j][choice] < minValue)
        {
          minIndex = j;
          minValue = vec[j][choice];
        }
      }

      swap(vec[minIndex], vec[i]);
    }
}

void sortDescending (vector<vector<int>>& vec, int choice)
{
    int maxIndex, maxValue;

    for(int i = 0; i < vec.size(); ++i) //vec.size() returns the number of elements in vector
    {
      maxIndex = i;
      maxValue = vec[i][choice];

      for(int j = i+1; j < vec.size(); ++j)
      {
        if(vec[j][choice] > maxValue)
        {
          maxIndex = j;
          maxValue = vec[j][choice];
        }
      }

      swap(vec[maxIndex], vec[i]);
    }
}
