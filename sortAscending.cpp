// reference : lecture 9 notes
#include <iostream>
#include <vector>
using namespace std;
void sortAscending ( vector<int>& vec)
{
    int minIndex, minValue;

    for(int i = 0; i < vec.size(); ++i) //vec.size() returns the number of elements in vector
    {
      minIndex = i;
      minValue = vec[i];

      for(int j = i+1; j < vec.size(); ++j)
      {
        if(vec[j] < minValue)
        {
          minIndex = j;
          minValue = vec[j];
        }
      }

      swap(vec[minIndex], vec[i]);
    }
}int main()
{
   vector<int> grades{97,92,88,99,78};

   sortAscending (grades);

   for(int i : grades) //running a loop for every element in the vector
   {
      cout << i << " ";
   }
   cout << endl;

   return 0;
}
