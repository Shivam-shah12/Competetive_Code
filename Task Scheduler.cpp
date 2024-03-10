class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // priority_queue store the (no. of task,time)
        priority_queue<pair<int,int>>pq;
        // queue store all the element who can't execute right now
        queue<pair<int,int>>q;
        map<char,int>cnt;
        for(auto val:tasks)
        cnt[val]++;

        for(auto val:cnt)
        {
            pq.push({val.second,0}); 
        }
        int time=0;
        while(!pq.empty() || !q.empty())
        {
            // we check --> Can any queue element those who ready to execute
            // push inside the priority queue
            if(!q.empty() && abs(q.front().second-time)>n)
            {
                pq.push(q.front());
                q.pop();
            }
            // if pq is not empty , it means some one ready to execute
            if(!pq.empty())
            {auto a =pq.top();
            pq.pop();

            if(a.first-1>0)
            q.push({a.first-1,time});
            }
            time++;

        }
        return time;
        
        
    }
};
