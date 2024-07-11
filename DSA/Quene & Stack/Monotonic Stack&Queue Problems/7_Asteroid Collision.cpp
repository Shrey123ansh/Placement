Example 1:

Input: asteroids = [5,10,-5]
Output: [5,10]
Explanation: The 10 and -5 collide resulting in 10. The 5 and 10 never collide.
Example 2:

Input: asteroids = [8,-8]
Output: []
Explanation: The 8 and -8 collide exploding each other.
Example 3:

Input: asteroids = [10,2,-5]
Output: [10]
Explanation: The 2 and -5 collide resulting in -5. The 10 and -5 collide resulting in 10.
 
 class Solution
{
public:
    vector<int> asteroidCollision(vector<int> &astro)
    {
        stack<int> s;
        for (auto i : astro)
        {
            if (s.empty())
            {
                s.push(i);
            }
            else if (i > 0)
            {
                s.push(i);
            }
            else if (i < 0)
            {
                // while(!s.empty()){
                //     if(s.top()<=abs(i)){
                //         s.pop();
                //     }
                //     else{
                //         // s.push(i);
                //         break;
                //     }
                // }
                while (!s.empty() && s.top() > 0 && s.top() < abs(i))
                {
                    s.pop();
                }
                if (!s.empty() && s.top() > 0)
                {
                    if (s.top() == abs(i))
                    {
                        s.pop();
                    }
                }
                else
                {
                    s.push(i);
                }
            }
        }
        vector<int> ans;
        for (; !s.empty();)
        {
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};