class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> edges(numCourses, vector<int>());
        vector<int> indegree(numCourses, 0);
        for (auto prerequisite:prerequisites){
            edges[prerequisite[1]].push_back(prerequisite[0]);
            ++indegree[prerequisite[0]];
        }
        queue<int> q;
        for (int i=0; i<numCourses; i++){
            if (!indegree[i]) {
                q.push(i);
            }
        }
        int visited = 0;
        while (!q.empty()){
            visited++;
            int u = q.front();
            q.pop();
            for (auto v:edges[u]){
                --indegree[v];
                if (!indegree[v]){
                    q.push(v);
                }
            }
        }
        return visited == numCourses;
    }
};