#include<bits/stdc++.h>
using namespace std;

struct TrieNode {
    TrieNode *children[26];
    bool isEndOfWord;
};

TrieNode* getNode() {
    TrieNode *pNode = new TrieNode;
    pNode->isEndOfWord = false;
    for (int i = 0; i < 26; i++)
        pNode->children[i] = NULL;
    return pNode;
}

void insert(TrieNode *root, string key) {
    TrieNode *pCrawl = root;
    for (int i = 0; i < key.length(); i++) {
        int index = key[i] - 'A';
        if (!pCrawl->children[index])
            pCrawl->children[index] = getNode();
        pCrawl = pCrawl->children[index];
    }
    pCrawl->isEndOfWord = true;
}

bool isSafe(int i, int j, bool visited[50][50], int M, int N) {
    return (i >=0 && i < M && j >=0 && j < N && !visited[i][j]);
}

void searchWord(TrieNode *root, vector<vector<char>> &board, int i, int j, bool visited[50][50], string str, set<string> &result) {
    if (root->isEndOfWord)
        result.insert(str);

    if (isSafe(i, j, visited, board.size(), board[0].size())) {
        visited[i][j] = true;
        for (int K =0; K < 26; K++) {
            if (root->children[K] != NULL) {
                char ch = (char)K + 'A' ;
                if (isSafe(i+1, j+1, visited, board.size(), board[0].size()) && board[i+1][j+1] == ch)
                    searchWord(root->children[K], board, i+1, j+1, visited, str+ch, result);
                if (isSafe(i+1, j, visited, board.size(), board[0].size())  && board[i+1][j] == ch)
                    searchWord(root->children[K], board, i+1, j, visited, str+ch, result);
                if (isSafe(i+1, j-1, visited, board.size(), board[0].size()) && board[i+1][j-1] == ch)
                    searchWord(root->children[K], board, i+1, j-1, visited, str+ch, result);
                if (isSafe(i, j+1, visited, board.size(), board[0].size())  && board[i][j+1] == ch)
                    searchWord(root->children[K], board, i, j+1, visited, str+ch, result);
                if (isSafe(i, j-1, visited, board.size(), board[0].size()) && board[i][j-1] == ch)
                    searchWord(root->children[K], board, i, j-1, visited, str+ch, result);
                if (isSafe(i-1, j+1, visited, board.size(), board[0].size()) && board[i-1][j+1] == ch)
                    searchWord(root->children[K], board, i-1, j+1, visited, str+ch, result);
                if (isSafe(i-1, j, visited, board.size(), board[0].size())  && board[i-1][j] == ch)
                    searchWord(root->children[K], board, i-1, j, visited, str+ch, result);
                if (isSafe(i-1, j-1, visited, board.size(), board[0].size()) && board[i-1][j-1] == ch)
                    searchWord(root->children[K], board, i-1, j-1, visited, str+ch, result);
            }
        }
        visited[i][j] = false;
    }
}

vector<string> wordBoggle(vector<string> &dictionary, int n, int r, int c, vector<vector<char>> &board) {
    TrieNode *root = getNode();
    for (int i=0; i<n; i++)
        insert(root, dictionary[i]);

    bool visited[50][50] = {{false}};
    TrieNode *pChild = root ;
    string str = "";
    set<string> result;

    for (int i = 0; i < r; i++)
        for (int j = 0; j < c ; j++)
            if (pChild->children[board[i][j] - 'A'] ) {
                str = str+board[i][j];
                searchWord(pChild->children[board[i][j] - 'A'], board, i, j, visited, str, result);
                str = "";
            }

    vector<string> finalResult(result.begin(), result.end());
    return finalResult;
}

int main() {
    vector<string> dictionary1 = {"CAT"};
    int r1 = 3, c1 = 3;
    vector<vector<char>> board1 = {{'C','A','P'},{'A','N','D'},{'T','I','E'}};
	vector<string> ans1 = wordBoggle(dictionary1, dictionary1.size(), r1, c1, board1);
	cout << "Example 1 output: ";
    for(string s : ans1) {
        cout << s << " ";
    }
    
    cout << endl << endl;

    vector<string> dictionary2 = {"GEEKS","FOR","QUIZ","GO"};
    int r2 = 3, c2 = 3;
    vector<vector<char>> board2 = {{'G','I','Z'},{'U','E','K'},{'Q','S','E'}};
	vector<string> ans2 = wordBoggle(dictionary2, dictionary2.size(), r2, c2, board2);
    cout << "Example 2 output: ";
    for(string s : ans2) {
        cout << s << " ";
    }
    cout << endl;

    return 0;
}
