/* 
The only thing you need to remember for this problem
----------------------------------------------------
    Max Heap → Smaller half
    Min Heap → Larger half
Balance Rule
------------
    maxHeap.size() == minHeap.size()
    OR
    maxHeap.size() == minHeap.size() + 1
Median
------
    Equal sizes → Average of both heap tops.
    Otherwise → maxHeap.top().
 */


class MedianFinder {
public:

    // Max Heap -> stores the smaller half
    priority_queue<int> maxHeap;

    // Min Heap -> stores the larger half
    priority_queue<int, vector<int>, greater<int>> minHeap;

    MedianFinder() {

    }

    void addNum(int num) {

        // Insert into the appropriate heap
        if (maxHeap.empty() || num <= maxHeap.top()) {
            maxHeap.push(num);
        }
        else {
            minHeap.push(num);
        }

        int sizeDiff = maxHeap.size() - minHeap.size();

        // Right heap became larger
        if (sizeDiff < 0) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }

        // Left heap became larger by more than one
        else if (sizeDiff > 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
    }

    double findMedian() {

        // Even number of elements
        if (minHeap.size() == maxHeap.size())
            return (maxHeap.top() + minHeap.top()) / 2.0;

        // Odd number of elements
        return maxHeap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */