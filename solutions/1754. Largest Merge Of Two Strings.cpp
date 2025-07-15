class Solution {
private:
    // checks if substring of word1 starting at start1 is larger than
    // substring of word2 starting at start2
    bool compare(string& word1, string& word2, int start1, int start2) {
        int len1 = word1.size(), len2 = word2.size();
        int i = start1, j = start2;
        
        while (i < len1 && j < len2) {
            if (word1[i] == word2[j])
                i++, j++;
            else
                return word1[i] > word2[j];
        }

        return i < len1;
    }

public:
    string largestMerge(string word1, string word2) {
        int len1 = word1.size(), len2 = word2.size();
        int i = 0, j = 0;
        string ans = "";

        while (i < len1 && j < len2) {
            if (word1[i] > word2[j])
                ans += word1[i++];
            else if (word1[i] < word2[j])
                ans += word2[j++];
            // both chars are same
            // need to compare which substring is larger and take from it
            else if (compare(word1, word2, i, j))
                ans += word1[i++];
            else
                ans += word2[j++];
        }

        while (i < len1)
            ans += word1[i++];

        while (j < len2)
            ans += word2[j++];

        return ans;
    }
};
