// reference : lecture 9 notes
#include <iostream>
#include <vector>
using namespace std;
void sortDescending ( vector<int>& vec)
{
    int maxIndex, maxValue;

    for(int i = 0; i < vec.size(); ++i) //vec.size() returns the number of elements in vector
    {
      maxIndex = i;
      maxValue = vec[i];

      for(int j = i+1; j < vec.size(); ++j)
      {
        if(vec[j] > maxValue)
        {
          maxIndex = j;
          maxValue = vec[j];
        }
      }

      swap(vec[maxIndex], vec[i]);
    }
}int main()
{
   vector<int> grades{97,92,88,99,78};

   sortDescending(grades);

   for(int i : grades) //running a loop for every element in the vector
   {
      cout << i << " ";
   }
   cout << endl;

   return 0;
}
