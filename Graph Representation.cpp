int main()
{
 
          // Adjacency Matrix Code
          int n,m;
          cin>>n>>m;
           int adj[n+1][n+1]={0};
          for(int i=0;i<m;i++)
          {
            int u,v;
            cin>>u>>v;
            adj[u][v]=1;
            adj[v][u]=1;
          }
          for(int i=0;i<n;i++)
          {
            for(int j=0;j<n;j++)
            {
              cout<<adj[i][j]<<" ";
            }
            cout<<endl;
          }

          //  Adjacency List Code
          // adjacency list for undirected graph
          // time complexity: O(2E)
          vector<int> adj[n+1];
          for(int i = 0; i < m; i++)
          {
              int u, v;
              cin >> u >> v;
              adj[u].push_back(v);
              adj[v].push_back(u);
          }
          return 0;
}
 
