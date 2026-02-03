#include <vector>
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        int i = 0, n = words.size();

        while (i < n) {
            int lineLen = words[i].size();
            int j = i + 1;

            // Determine how many words fit in the current line
            while (j < n && lineLen + 1 + words[j].size() <= maxWidth) {
                lineLen += 1 + words[j].size();
                j++;
            }

            vector<string> lineWords(words.begin() + i, words.begin() + j);
            int wordCount = j - i;
            string line;

            // Left-justified: last line or single word
            if (j == n || wordCount == 1) {
                for (int k = 0; k < wordCount; k++) {
                    if (k > 0) line += " ";
                    line += lineWords[k];
                }
                line += string(maxWidth - line.size(), ' ');
            } 
            // Fully justified
            else {
                int totalLetters = 0;
                for (const string& w : lineWords) {
                    totalLetters += w.size();
                }

                int totalSpaces = maxWidth - totalLetters;
                int gaps = wordCount - 1;
                int spacePerGap = totalSpaces / gaps;
                int extraSpaces = totalSpaces % gaps;

                for (int k = 0; k < gaps; k++) {
                    line += lineWords[k];
                    int spaces = spacePerGap + (k < extraSpaces ? 1 : 0);
                    line += string(spaces, ' ');
                }
                line += lineWords.back();
            }

            res.push_back(line);
            i = j;
        }

        return res;
    }
};

int main(){
  vector<string> words;
  words = {"This","is","an","example","of","practice","makes","perfect"};
  Solution s1;
  s1.fullJustify(words,16);
  cout << re << endl;

  return 0;
}
