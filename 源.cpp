#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K)
    {
        // creating a weighted graph
        vector<vector<pair<int, int>>> graph(n);

        for (auto i : flights)
        {
            graph[i[0]].push_back({ i[1], i[2] });
        }

        // creating a min heap or a priority queue
        // having distance, src and nodes left(where we can stop)
        // priority queu will be based upon distance, the node with least distance will
        // come on top
        priority_queue < pair<int, pair<int, int> >, vector < pair <int, pair<int, int> > >, greater<pair<int, pair<int, int> > > > pq;

        pq.push({ 0, { src, K} });

        // applying Dijkstra's Algorithm for shortest path from single source         
        while (!pq.empty())
        {
            pair<int, pair<int, int> > node = pq.top();
            pq.pop();

            // if current node is destination, return cost uptill now  
            if (node.second.first == dst)
                return node.first;

            // if nodes that we can visit is finished, skip this node  
            if (node.second.second < 0)
                continue;

            // now iterate over other nodes of the current node - distance will be
            // distance uptill this node + dist from this node to that neighbour node
            // and nodes which we can visit will be on less.
            for (auto i : graph[node.second.first])
            {
                pq.push({ (node.first + i.second),{i.first,(node.second.second - 1)} });
            }
        }

        return -1;
    }
};
int main() {
    Solution sol;
    vector<vector<int>>flights = { {0,12,28},{5,6,39},{8,6,59},{13,15,7},{13,12,38},{10,12,35},{15,3,23},{7,11,26},{9,4,65},{10,2,38},{4,7,7},{14,15,31},{2,12,44},{8,10,34},{13,6,29},{5,14,89},{11,16,13},{7,3,46},{10,15,19},{12,4,58},{13,16,11},{16,4,76},{2,0,12},{15,0,22},{16,12,13},{7,1,29},{7,14,100},{16,1,14},{9,6,74},{11,1,73},{2,11,60},{10,11,85},{2,5,49},{3,4,17},{4,9,77},{16,3,47},{15,6,78},{14,1,90},{10,5,95},{1,11,30},{11,0,37},{10,4,86},{0,8,57},{6,14,68},{16,8,3},{13,0,65},{2,13,6},{5,13,5},{8,11,31},{6,10,20},{6,2,33},{9,1,3},{14,9,58},{12,3,19},{11,2,74},{12,14,48},{16,11,100},{3,12,38},{12,13,77},{10,9,99},{15,13,98},{15,12,71},{1,4,28},{7,0,83},{3,5,100},{8,9,14},{15,11,57},{3,6,65},{1,3,45},{14,7,74},{2,10,39},{4,8,73},{13,5,77},{10,0,43},{12,9,92},{8,2,26},{1,7,7},{9,12,10},{13,11,64},{8,13,80},{6,12,74},{9,7,35},{0,15,48},{3,7,87},{16,9,42},{5,16,64},{4,5,65},{15,14,70},{12,0,13},{16,14,52},{3,10,80},{14,11,85},{15,2,77},{4,11,19},{2,7,49},{10,7,78},{14,6,84},{13,7,50},{11,6,75},{5,10,46},{13,8,43},{9,10,49},{7,12,64},{0,10,76},{5,9,77},{8,3,28},{11,9,28},{12,16,87},{12,6,24},{9,15,94},{5,7,77},{4,10,18},{7,2,11},{9,5,41} };
    
    
    
    
    cout << sol.findCheapestPrice(17,flights, 13, 4, 13);
}