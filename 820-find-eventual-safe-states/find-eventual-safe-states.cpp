class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
         int V = graph.size();

        //create adj
        vector<vector<int>> adj(V);
        vector<int> inorder(V, 0);

        for(int u = 0 ; u < V ; u++){

            for(int v : graph[u]){
                adj[v].push_back(u);
                inorder[u]++;

            }
        }

        // start 
        queue<int> q;
        for(int i = 0 ; i < V ; i++){
            if(inorder[i] == 0){
                q.push(i);
            }
        }
        vector<int> ans;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);

            // travel adj
            for(int n : adj[node]){
                inorder[n]--;
                if(inorder[n] == 0){
                    q.push(n);
                }
            }

        }

            sort(ans.begin() , ans.end());
            return ans; 
    }
};