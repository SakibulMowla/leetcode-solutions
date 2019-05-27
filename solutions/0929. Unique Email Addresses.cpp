class Solution {
public:
    
    void separate(string& local, string& domain, string& email) {
        int len = email.size();
        for (int i = 0; i < len; i++) {
            if (email[i] == '@') {
                local = email.substr(0, i);
                domain = email.substr(i + 1);
                break;
            }
        }
        return;
    }
    
    string shorten(string& local) {
        string ans;
        for (auto& ch: local) {
            if (ch == '+') {
                break;
            } else if (ch != '.') {
                ans += ch;
            }
        }
        return ans;
    }
    
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> hash;

        for (auto& email: emails) {
            string local, domain;
            separate(local, domain, email);
            local = shorten(local);
            hash.insert(local + '@' + domain);
        }
        
        return hash.size();
    }
};
