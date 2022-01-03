#include "../solution.h"
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    	int max = 0;
    	for(int i = 0; i < s.length(); i++) {
    		for(int j = i + 1; j < s.length(); j++) {
	    		if(checkDup(s, i, j)) {
	    			if ((j - i) > max) {
	    				max = j -i;
	    			}
	    			break;
	    		}
	    	}
    	}
    	return max;
    }

    bool checkDup(string s, int start, int end) {
    	for(int i = start; i < end; i++) {
    		if(s[end] == s[i]) {
    			return true;
    		}
    	}
    	return false;
    }
};

int main() {
	Solution sol;
	cout << sol.lengthOfLongestSubstring("abcabcbb") << endl;
	cout << sol.lengthOfLongestSubstring("pwwkew") << endl;
	cout << sol.lengthOfLongestSubstring("bbbbbb") << endl;

	return 0;
}