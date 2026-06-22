class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        auto mavorqeli = edges;

        vector<vector<pair<int, int>>> adj(n);

        for (auto& it : edges) {
            int u = it[0];
            int v = it[1];
            int w = it[2];

            adj[u].push_back({v, w});
        }

        long long inf = 1e18;

        vector<vector<long long>> dis(n, vector<long long>(k + 1, inf));

        priority_queue<tuple<long long, int, int>,
                       vector<tuple<long long, int, int>>,
                       greater<tuple<long long, int, int>>>
            pq;

        dis[0][1] = 0;
        pq.push({0, 0, 1});

        while (!pq.empty()) {

            auto [currCost, currNode, cnt] = pq.top();
            pq.pop();

            if (currCost != dis[currNode][cnt]) {
                continue;
            }

            for (auto& nbr : adj[currNode]) {

                int nextNode = nbr.first;
                int wt = nbr.second;

                int nextCnt;

                if (labels[currNode] == labels[nextNode]) {
                    nextCnt = cnt + 1;
                } else {
                    nextCnt = 1;
                }

                if (nextCnt > k) {
                    continue;
                }

                long long totalCost = currCost + wt;

                if (totalCost < dis[nextNode][nextCnt]) {

                    dis[nextNode][nextCnt] = totalCost;

                    pq.push({totalCost, nextNode, nextCnt});
                }
            }
        }

        long long ans = inf;

        for (int i = 1; i <= k; i++) {
            ans = min(ans, dis[n - 1][i]);
        }

        if (ans == inf) {
            return -1;
        }

        return ans;
    }
};
