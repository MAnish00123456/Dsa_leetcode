// The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value, and the median is the mean of the two middle values.

// For example, for arr = [2,3,4], the median is 3.
// For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.
// Implement the MedianFinder class:

// MedianFinder() initializes the MedianFinder object.
// void addNum(int num) adds the integer num from the data stream to the data structure.
// double findMedian() returns the median of all elements so far. Answers within 10-5 of the actual answer will be accepted.

// Input
// ["MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"]
// [[], [1], [2], [], [3], []]
// Output
// [null, null, null, 1.5, null, 2.0]

// Explanation
// MedianFinder medianFinder = new MedianFinder();
// medianFinder.addNum(1);    // arr = [1]
// medianFinder.addNum(2);    // arr = [1, 2]
// medianFinder.findMedian(); // return 1.5 (i.e., (1 + 2) / 2)
// medianFinder.addNum(3);    // arr[1, 2, 3]
// medianFinder.findMedian(); // return 2.0

// class MedianFinder {
//     // Max-heap: stores the smaller half of the numbers.
//     // top() gives the largest element in the smaller half.
//     priority_queue<int> LeftContainer;

//     // Min-heap: stores the larger half of the numbers.
//     // top() gives the smallest element in the larger half.
//     priority_queue<int, vector<int>, greater<int>> RightContainer;

// public:
//     MedianFinder() {

//     }

//     void addNum(int num) {
//         // Insert the new number into the left max-heap first.
//         LeftContainer.push(num);

//         // Maintain the ordering invariant:
//         // every element in LeftContainer should be <=
//         // every element in RightContainer.
//         //
//         // If the largest element on the left is greater than
//         // the smallest element on the right, move that left
//         // element to the right heap.
//         if (!RightContainer.empty() &&
//             LeftContainer.top() > RightContainer.top()) {

//             RightContainer.push(LeftContainer.top());
//             LeftContainer.pop();
//         }

//         // Maintain the size invariant:
//         // LeftContainer can contain at most one extra element.
//         //
//         // If the left heap has more than one extra element,
//         // move its largest element to the right heap.
//         if (((int)LeftContainer.size() -
//              (int)RightContainer.size()) > 1) {

//             RightContainer.push(LeftContainer.top());
//             LeftContainer.pop();

//         }
//         // If the right heap has more elements than the left,
//         // move its smallest element to the left heap.
//         else if (RightContainer.size() > LeftContainer.size()) {

//             LeftContainer.push(RightContainer.top());
//             RightContainer.pop();
//         }
//     }

//     double findMedian() {
//         // Odd number of elements:
//         // the left heap contains one extra element,
//         // so its top is the median.
//         if (LeftContainer.size() > RightContainer.size()) {
//             return LeftContainer.top();
//         }

//         // Even number of elements:
//         // the median is the average of the two middle values.
//         return (double)(LeftContainer.top() +
//                         RightContainer.top()) / 2.0;
//     }
// };

/**
 * MedianFinder object is instantiated and called as:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
