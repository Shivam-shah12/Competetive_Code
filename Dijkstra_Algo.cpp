
vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
      priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
      // we assume 0 as starting node
      pq.push({0,S});
      vector<int>dist(V);
      for(int i=0;i<V;i++)
      {
          dist[i]=INT_MAX;
      }
      dist[S]=0;
      while(!pq.empty())
      {
          pair<int,int>curr_node=pq.top();
          pq.pop();
          int d=curr_node.first;
          int node=curr_node.second;
          for(auto val:adj[node])
          {
              int c_node=val[0];
              int c_dist=val[1]+d;
            //   cout<<c_node<<" "<<c_dist<<endl;
              if(dist[c_node]>c_dist)
              {
                  dist[c_node]=c_dist;
                  pq.push({c_dist,c_node});
              }
          }
      }
     
      return dist;
    }
