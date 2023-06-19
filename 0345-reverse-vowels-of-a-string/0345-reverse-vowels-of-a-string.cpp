class Solution {
public:

    bool is_vowel(char ch)
    {
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U');
    }

    string reverseVowels(string str) {

        int n = str.size();

        // use two pointer

        int i = 0;

        int j = n - 1;

        // find position of vowels from the left and position of vowels from the right, 

        // as we found vowels at ith and jth, swap both the characters

        while(i < j)
        {
            if(is_vowel(str[i]) && is_vowel(str[j]))
            {
                swap(str[i], str[j]);

                i++;

                j--;
            }
            else if(is_vowel(str[i]) == false)
            {
                i++;
            }
            else if(is_vowel(str[j]) == false)
            {
                j--;
            }
        }

        return str;
    }
};