using namespace std;

#include <iostream>
#include <vector>

class Solution
{
public:
    int findLength(const vector<int> &arr, int k)
    {
      if(k == arr.size()) {
        return arr.size();
      }
      int maxLength = 0;
      // TODO: Write your code here
      int start = 0;
      unordered_map<int, int> map;
      for(int end = 0; end < arr.size(); end++) {
        map[arr[end]]++;
        while(end-start+1-map[1] > k) {
          cout<<"in while"<<endl;
          map[arr[start]]--;
          start++;
        }
        maxLength = max(maxLength, end-start+1);
      }
      return maxLength;
    }
};

