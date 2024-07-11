Example 1:

Input
["KthLargest", "add", "add", "add", "add", "add"]
[[3, [4, 5, 8, 2]], [3], [5], [10], [9], [4]]
Output
[null, 4, 5, 5, 8, 8]

Explanation
KthLargest kthLargest = new KthLargest(3, [4, 5, 8, 2]);
kthLargest.add(3);   // return 4
kthLargest.add(5);   // return 5
kthLargest.add(10);  // return 5
kthLargest.add(9);   // return 8
kthLargest.add(4);   // return 8


class KthLargest {
    int k;
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
    
public:
    KthLargest(int k, std::vector<int>& nums) {
        this->k = k;
        
        for (int num : nums) {
            add(num);
        }
    }
    
    int add(int val) {
        if (minHeap.size() < k) {
            minHeap.push(val);
        } else if (val > minHeap.top()) {
            minHeap.pop();
            minHeap.push(val);
        }
        
        return minHeap.top();
    }
};