Example 1:
Input: tasks = ["A","A","A","B","B","B"], n = 2
Output: 8

Explanation: A possible sequence is: A -> B -> idle -> A -> B -> idle -> A -> B.
After completing task A, you must wait two cycles before doing A again. The same applies to task B. In the 3rd interval, neither A nor B can be done, so you idle. By the 4th cycle, you can do A again as 2 intervals have passed.

Example 2:
Input: tasks = ["A","C","A","B","D","B"], n = 1
Output: 6

Explanation: A possible sequence is: A -> B -> C -> D -> A -> B.
With a cooling interval of 1, you can repeat a task after just one other task.

Example 3:
Input: tasks = ["A","A","A", "B","B","B"], n = 3
Output: 10

Explanation: A possible sequence is: A -> B -> idle -> idle -> A -> B -> idle -> idle -> A -> B.
There are only two types of tasks, A and B, which need to be separated by 3 intervals. This leads to idling twice between repetitions of these tasks.

  class cmp{
    public:
    bool operator()(pair<char, pair<int, int>>& p1, pair<char, pair<int, int>>& p2){
        return p1.second.first < p2.second.first;
    }
};

int leastInterval(vector<char>& tasks, int n) {
         if(n==0){return tasks.size();}
         priority_queue<pair<char, pair<int, int>>, vector<pair<char, pair<int, int>>>, cmp> pq;
         unordered_map<char, int> cnt;
         for(char ch: tasks){
             cnt[ch]++;
         }
         for(auto p: cnt){
             pq.push({p.first, {p.second, -1}});
         }
         int time = 0;
         stack<pair<char, pair<int, int>>> s;
         while(!pq.empty()){
             time++;
             while(!pq.empty() && pq.top().second.second >= time){ // on an off right now
                 s.push(pq.top());
                 pq.pop();
             }
             if(!pq.empty()){
                 auto p = pq.top();
                 pq.pop();
                 if(p.second.first>1){
                     pq.push({p.first, {p.second.first-1, time+n}});
                 }
             }
             while(!s.empty() && s.top){
                 pq.push(s.top());
                 s.pop();
             }
         }
         return time;
     }

////////////////or/////////////////

  int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int>mp;
        int count = 0;
        for(auto e : tasks)
        {
            mp[e]++;
            count = max(count, mp[e]);
        }
        
        int ans = (count-1)*(n+1);
        for(auto e : mp){
            if(e.second == count){ans++;}
        }
        return max(tasks.size(), ans);
    }
