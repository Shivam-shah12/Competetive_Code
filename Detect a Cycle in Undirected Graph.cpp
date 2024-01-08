class Solution
{
public:
bool checkForcycle(int src,vector<int>adj[],int vis[])
    {
        // we are storing pair of {node,parent}
        vis[src]=1;
        queue<pair<int,int>>q;
        q.push({src,-1});
        while(!q.empty())
        {
            int node=q.front().first;
            int parent=q.front().second;
            q.pop();
            for(auto adjacent:adj[node])
            {
                if(!vis[adjacent])
                {
                    vis[adjacent]=1;
                    q.push({adjacent,node});
                }
                else if(parent != adjacent)
                return true;
            }
        }
        return false;
    }
    
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        int vis[V]={0};
    
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                if(checkForcycle(i,adj,vis))
                {
                    return true;
                }
            }
          
        }
        return false;
    }
};
