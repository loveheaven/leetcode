#include "../solution.h"
class Solution {
public:
    bool isDigit(char s) {
        return (s-'0')>=0 && (s-'0') <= 9;
    }
    string processSquareBracket(string& s, int index, int& end) {
        stringstream ss;
        int found = 1;
        end = index + 1;
        for(int i = index + 1; i< s.length(); i++) {
            if(s[i] == '[') found++;
            else if(s[i] == ']') {
                found--;
                if(found == 0) {
                    end = i;
                    return ss.str();
                }
            }
            ss << s[i];
        }
        return "";
    }
    string decodeString(string& s) {
        stringstream ret;
        
        int num = 1;
        for(int i = 0;i<s.length(); i++) {
            if(isDigit(s[i])) {
                stringstream ss;
                while(isDigit(s[i])) {
                    ss << s[i];
                    i++;
                }
                ss >> num;
                i--;
            } else if(s[i] =='[') {
                string b;
                string t = processSquareBracket(s, i, i);
                for(int j = 0; j < num; j++) {
                    b.append(t);                    
                }
                cout << b<<";"<<endl;
                ret<<decodeString(b);
            } else {
                ret<<s[i];
            }
        }
        return ret.str();
        

    }
};

int main() {
	
	string word = "3[a2[c]]";
	Solution a;
	cout << a.decodeString(word) << endl;

}