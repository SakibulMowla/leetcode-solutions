class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target) {
            return 0;
        }

        unordered_map<int, vector<int>> stopToRoute;
        for (int i = 0; i < routes.size(); i++) {
            for (int stop: routes[i]) {
                stopToRoute[stop].push_back(i);
            }
        }

        // impossible case
        if (stopToRoute.find(source) == stopToRoute.end() ||
            stopToRoute.find(target) == stopToRoute.end()) {
                return -1;
            }

        unordered_set<int> visited;
        queue<int> routeQueue;
        unordered_map<int, int> dist;

        for (int route: stopToRoute[source]) {
            routeQueue.push(route);
            visited.insert(route);
            dist[route] = 1;
        }

        while (!routeQueue.empty()) {
            int route = routeQueue.front();
            routeQueue.pop();

            for (int stop: routes[route]) {
                // found the target stop
                if (stop == target) {
                    return dist[route];
                }

                for (int nextRoute: stopToRoute[stop]) {
                    if (visited.find(nextRoute) == visited.end()) {
                        routeQueue.push(nextRoute);
                        visited.insert(nextRoute);
                        dist[nextRoute] = 1 + dist[route];
                    }
                }
            }
        }

        return -1;
    }
};
