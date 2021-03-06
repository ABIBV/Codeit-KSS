
/* 2020_10_09_01 - Notepad Operations 
https://www.geeksforgeeks.org/implement-undo-and-redo-features-of-a-text-editor/ */

#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

auto write(char character, string board, string history) {
  board.push_back(character); 
  history += 'w';
  struct retVals {
    string board, history;
  };
  return retVals {board, history};
}

auto remove(string board, string history, vector<char> bin){
  bin.push_back(*(board.end() -1));
  board.pop_back();
  history += "r";

  struct retVals {
    string board, history;
    vector<char> bin;
  };
  return retVals {board, history, bin};
}

int main() {
  string s = "";
  string board = "";
  string history = "";
  string undoHistory = "";
  vector<char> bin;
  while (s != "exit"){
    getline(cin, s);
    if(s[0] == 'W' || s[0] == 'w') {
      auto [val1, val2] = write(*(s.end() -1), board, history);
      board = val1;
      history = val2;
    }else if((s[0] == 'r' || s[0] == 'R') && (*(s.end() -1)=='d' || *(s.end() -1) == 'D')){
      cout<<board<<endl;
    }else if(s[0] == 'U' || s[0] == 'u') {
      char lastOperation = *(history.end() - 1);
      if(lastOperation == 'w') {
        auto [val1, val2, val3] = remove(board, history, bin);
        board = val1;
        history = val2;
        bin = val3;
        undoHistory += "r";
      } else if (lastOperation == 'r') {
        auto [val1, val2] = write(*(bin.end() -1), board, history);
        board = val1;
        history = val2;
        bin.pop_back();
        undoHistory += "w";
      }
    }else if((s[0] == 'r' || s[0] == 'R') && (*(s.end() -1)=='o' || *(s.end() -1) == 'O')){
      char lastOperation = *(undoHistory.end() -1);
      undoHistory.pop_back();
      if(lastOperation == 'w') {
        auto [val1, val2, val3] = remove(board, undoHistory, bin);
        board = val1;
        history = val2;
        bin = val3;
      } else if (lastOperation == 'r') {
        auto [val1, val2] = write(*(bin.end() -1), board, undoHistory);
        board = val1;
        history = val2;
        bin.pop_back();
      }
      undoHistory.pop_back();
    } else {
      cout<<s<<" is not a valid operation"<<endl;
    }
  }
  return 0;
}