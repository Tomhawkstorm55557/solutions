class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int i = 0;

        while (i < words.size()) {
            vector<string> currentLine = getWords(i, words, maxWidth);
            i += currentLine.size();
            ans.push_back(createLine(currentLine, i, words, maxWidth));
        }

        return ans;
    }

private:
    vector<string> getWords(int i, vector<string>& words, int maxWidth) {
        vector<string> currentLine;
        int currLength = 0;

        while (i < words.size() && currLength + words[i].length() <= maxWidth) {
            currentLine.push_back(words[i]);
            currLength += words[i].length() + 1;
            i++;
        }

        return currentLine;
    }

    string createLine(vector<string>& currentLine, int i, vector<string>& words, int maxWidth) {
        string line;
        int totalWordsWidth = 0;

        for (const string& word : currentLine) {
            totalWordsWidth += word.length();
        }

        int extraSpaces = maxWidth - totalWordsWidth;
        int numWords = currentLine.size();

        if (numWords == 1 || i == words.size()) {
            line = currentLine[0];

            for (int j = 1; j < numWords; j++) {
                line += " " + currentLine[j];
            }

            line += string(maxWidth - line.length(), ' ');
        } else {
            int spacesBetweenWords = extraSpaces / (numWords - 1);
            int extraSpaceCount = extraSpaces % (numWords - 1);

            line = currentLine[0];

            for (int j = 1; j < numWords; j++) {
                int spacesCount = spacesBetweenWords + (j <= extraSpaceCount ? 1 : 0);
                line += string(spacesCount, ' ') + currentLine[j];
            }
        }

        return line;
    }
};
