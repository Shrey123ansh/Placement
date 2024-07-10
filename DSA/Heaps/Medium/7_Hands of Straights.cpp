Example 1:

Input: hand = [1,2,3,6,2,3,4,7,8], groupSize = 3
Output: true
Explanation: Alice's hand can be rearranged as [1,2,3],[2,3,4],[6,7,8]
Example 2:

Input: hand = [1,2,3,4,5], groupSize = 4
Output: false
Explanation: Alice's hand can not be rearranged into groups of 4.

  bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if (n % groupSize)
            return false;

        unordered_map<int, int> freq;
        priority_queue<int, vector<int>, greater<int>> pq;

        for (int i : hand) {
            freq[i]++;
            pq.push(i);
        }

        int lim = n / groupSize;
        for (int i = 0; i < lim; i++) {
            while (!pq.empty() && freq[pq.top()] <= 0)
                pq.pop();
            if (pq.empty())
                return false;
            
            int small = pq.top();
            freq[small]--;

            for (int j = 1; j < groupSize; j++) {
                small++;
                if (freq[small] <= 0)
                    return false;
                freq[small]--;
            }
        }

        return true;
    }
