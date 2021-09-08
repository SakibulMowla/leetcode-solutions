class Solution {
private:
    double hourToDegree(double hour) {
        return hour * (360 / 12);
    }
    
    double minutesToDegree(int minutes) {
        return minutes * (360.0 / 60);
    }

public:
    double angleClock(int hour, int minutes) {
        if (hour == 12) {
            hour = 0;
        }
        
        double hourInDegree = hourToDegree(hour + minutes / 60.0);
        double minutesInDegree = minutesToDegree(minutes);
        
        double diff = abs(hourInDegree - minutesInDegree);
        double angle = min(diff, 360 - diff);
        
        return angle;
    }
};
