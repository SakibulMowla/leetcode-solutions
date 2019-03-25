class Solution {
public:
    
    int calcMinutes(int a, int b, int c, int d) {
        int hours = (a * 10 + b);
        int minutes = (c * 10 + d);
        if (hours >= 24 || minutes >= 59) 
            return 44 * 60 + 1;
        return hours * 60 + minutes;
    }
    
    string make2digits(int n) {
        return (n < 10 ? "0" : "") + to_string(n);
    }
    
    string minutesToTime(int totalMinutes) {
        int hours = totalMinutes / 60;
        int minutes = totalMinutes % 60;
        return make2digits(hours) + ":" + make2digits(minutes);
    }
    
    string nextClosestTime(string time) {
        vector<int> digits;
        for (int i = 0; i < 5; i++) if (i != 2) {
            digits.push_back(time[i] - '0');
        }
        
        int base = calcMinutes(digits[0], digits[1], digits[2], digits[3]);
        int lim = 4;
        int min = 24 * 60 + 1;
        int closest;

        for (int i = 0; i < lim; i++) {
            for (int j = 0; j < lim; j++) {
                for (int k = 0; k < lim; k++) {
                    for (int l = 0; l < lim; l++) {
                        int now = calcMinutes(digits[i], digits[j], digits[k], digits[l]);
                        int diff = now - base;
                        if (diff <= 0) {
                            diff += 24 * 60;
                        }
                        if (diff < min) {
                            min = diff;
                            closest = now;
                        }
                    }
                }
            }
        }
        
        return minutesToTime(closest);
    }
};
