class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
         int V = numCourses;
        //create adj
        vector<vector<int>> adj(V);
        vector<int> inorder(V, 0);

        for(int i = 0 ; i < prerequisites.size() ; i++){
            int u = prerequisites[i][1];
            int v  = prerequisites[i][0];
            adj[u].push_back(v);
            inorder[v]++;
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

            return ans.size() == V ? ans : vector<int>{}; 

    }
        
    
};