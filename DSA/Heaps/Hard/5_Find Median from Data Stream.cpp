Input
["MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"]
[[], [1], [2], [], [3], []]
Output
[null, null, null, 1.5, null, 2.0]

Explanation
MedianFinder medianFinder = new MedianFinder();
medianFinder.addNum(1);    // arr = [1]
medianFinder.addNum(2);    // arr = [1, 2]
medianFinder.findMedian(); // return 1.5 (i.e., (1 + 2) / 2)
medianFinder.addNum(3);    // arr[1, 2, 3]
medianFinder.findMedian(); // return 2.0

class MedianFinder {
public:
    priority_queue <int, vector<int>, greater<int>> maxarr;//minheap
    priority_queue <int> minarr;//maxheap
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        minarr.push(num);
        //the largest element in the minimum array is greater than the smallest element in max array
        if(minarr.size()!=0 and maxarr.size()!=0 and (minarr.top()> maxarr.top())){
            maxarr.push(minarr.top());
            minarr.pop();
        }
        //Size diff > 2
        if(minarr.size() > maxarr.size()+1){
            maxarr.push(minarr.top());
            minarr.pop();
        } 
        //size diff > 2 other way
        if(minarr.size()+1 < maxarr.size()){
            minarr.push(maxarr.top());
            maxarr.pop();
        }
    }
    
    double findMedian() {
        if(minarr.size() > maxarr.size()){
            //odd size
            return minarr.top();
        }
        if(minarr.size() < maxarr.size()){
            //odd size other way
            return maxarr.top();
        }
        //even case
        return (double)(minarr.top()+maxarr.top())/(double)2;
    }
};