#include "../solution.h"
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        bool ret = false;
        vector<vector<int>> pattern = {{0,-1}, {0, 1}, {1,0}, {-1, 0}};
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
       
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[i].size(); j++) {
                if(board[i][j] == word[0]) {
                    visited[i][j] = true;
                    ret = search(board, word, 1, i, j, pattern, visited);
                    visited[i][j] = false;
                    if(ret) return true;
                }
            }
        }
        return false;
    }
    bool isBetween(int x, int bound) {
        if(x>=0 && x<bound) return true;
        return false;
    }

    bool search(vector<vector<char>>& board, string& word, int wordIndex, int x, int y, 
        vector<vector<int>>& pattern, vector<vector<bool>>& visited) {
        if(wordIndex == word.length()) return true;
        bool ret = false;
        for(int i = 0;i<4;i++) {
            if(isBetween(x+pattern[i][0], board.size())
            && isBetween(y+pattern[i][1], board[0].size())
            && !visited[x+pattern[i][0]][y+pattern[i][1]]
            && board[x+pattern[i][0]][y+pattern[i][1]] == word[wordIndex]) {
                visited[x+pattern[i][0]][y+pattern[i][1]] = true;
                ret = search(board, word, wordIndex + 1, 
                x+pattern[i][0], y + pattern[i][1], 
                pattern, visited);
                visited[x+pattern[i][0]][y+pattern[i][1]] = false;
                if(ret) return true;
            }
        }
        return false;
    }
};

int main() {
	vector<vector<char>> v = {{'A','B','C','E'},{'S','F','C','S'}, {'A','D','E','E'}};
	string word = "ABCB";
	Solution a;
	if(a.exist(v, word)) cout<<"exist!"<<endl;
    else cout<<"not exist!"<<endl;

}