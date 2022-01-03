#include "../solution.h"
using namespace std;
class Solution {
public:
     template<typename T> vector<T> twoSum(std::vector<T>& nums, T target) {
    	std::unordered_map<T, int> reversedMap;
        for(int i = 0; i < nums.size(); ++i) {
        	auto iter = reversedMap.find(target - nums[i]);
        	if(iter != reversedMap.end()) {
        		cout << iter->second << ","  << i << endl;
                //std::initializer_list<T>
                return {iter->second, i};
        	} else {
        		reversedMap.emplace(pair<T, int>(nums[i], i));
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