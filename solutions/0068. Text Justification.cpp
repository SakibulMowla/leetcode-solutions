class Solution {
private:
    // Helper to format and justify a line from words[start] to words[end]
    void addLineToAnswer(vector<string>& words, int start, int end, vector<string>& ans, int left) {
        int avgSpaces, extraSpaces, endSpaces;

        // If it's the last line or a single-word line, left-justify
        if (start == end || end == (int)words.size() - 1) {
            avgSpaces = 0;
            extraSpaces = 0;
            endSpaces = left;  // Remaining space goes to the end
        } else {
            int slots = end - start; // Spaces between words
            avgSpaces = left / slots;
            extraSpaces = left % slots;
            endSpaces = 0;
        }

        string line = words[start];

        for (int i = start + 1; i <= end; i++) {
            // Add the one mandatory space between words (already accounted for in `left`)
            line += " ";

            // Add avg spaces per slot (for justified lines)
            line += string(avgSpaces, ' ');

            // Distribute extra spaces from the left
            if (extraSpaces > 0) {
                line += " ";
                extraSpaces--;
            }

            line += words[i];
        }

        // If it's the last line or single-word line, pad the end to match maxWidth
        if (endSpaces > 0) {
            line += string(endSpaces, ' ');
        }

        ans.push_back(line);
    }

public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int n = words.size();
        vector<string> ans;

        for (int i = 0; i < n; i++) {
            int left = maxWidth - words[i].size();  // Remaining space after first word
            int j = i;

            // Try to fit as many words as possible into the line
            while (j + 1 < n && left >= (int)words[j + 1].size() + 1) {
                left -= words[j + 1].size() + 1;  // Account for one space between words
                j++;
            }

            // Format and add the line
            addLineToAnswer(words, i, j, ans, left);
            i = j;  // Move to the next unprocessed word
        }

        return ans;
    }
};
