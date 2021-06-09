class Solution {
private:
	const double RAD_TO_DEGREES = 180.0 / M_PI;

	double calcDegree(vector<int>& point, vector<int>& location) {
		return atan2(location[1] - point[1], location[0] - point[0]) * RAD_TO_DEGREES;
	}

public:
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
		int ans = 0;
        vector<double> degrees;
        
		for (int i = 0; i < points.size(); i++) {
			if (points[i][0] == location[0] && points[i][1] == location[1]) {
				ans++;
			} else {
				degrees.push_back(calcDegree(points[i], location));
			}
		}

		sort(degrees.begin(), degrees.end());
		int n = degrees.size();
		degrees.resize(2 * n);

		for (int i = 0; i < n; i++) {
			degrees[i + n] = degrees[i] + 360;
		}

		int maxPoints = 0;

		for (int start = 0, end = 0; end < 2 * n; end++) {
			while (end - start >= n) {
				start++;
			}

			while (degrees[end] - degrees[start] > angle) {
				start++;
			}

			maxPoints = max(maxPoints, end - start + 1);
		}

		return ans + maxPoints;
    }
};
