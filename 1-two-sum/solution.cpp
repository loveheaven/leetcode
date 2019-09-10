#include <iostream>
#include <vector>
#include <map>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    	map<int, int> reversedMap;
        for(int i = 0; i < nums.size(); ++i) {
        	map<int, int>::iterator iter = reversedMap.find(target - nums[i]);
        	if(iter != reversedMap.end()) {
        		cout << iter->second << ","  << i << endl;
                //std::initializer_list<T>
                return {iter->second, i};
        	} else {
        		reversedMap.emplace(pair<int, int>(nums[i], i));
        	}
    	}
        return {};
    }
};

int main() {
	std::vector<int> v;
	for (int i = 0; i < 10; i++)
		v.emplace_back(i);

	Solution a;
	a.twoSum(v, 13);

}