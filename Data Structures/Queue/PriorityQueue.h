#include <vector>
#include <climits>

class PriorityQueue {
    vector<int> pq;

    public :

    PriorityQueue() {
        pq.push_back(INT_MIN);
    }

    void insert(int element) {
        pq.push_back(element);

        int childIndex = pq.size() - 1;
        while(childIndex > 1) {
            int parentIndex = childIndex / 2;

            if(pq[parentIndex] < pq[childIndex]) {
                break;
            }
            else {
                int temp = pq[parentIndex];
                pq[parentIndex] = pq[childIndex];
                pq[childIndex] = temp;
                childIndex = parentIndex;
            }
        }
    }

    int min() {
        if(pq.size() == 1) {
            return INT_MAX;
        }
        return pq[1];
    }

    int removeMin() {
        int ans = pq[1];
        pq[1] = pq[pq.size()-1];
        pq.pop_back();

        int parentIndex = 1;
        while(parentIndex < pq.size()) {
            int leftChildIndex = 2 * parentIndex;
            int rightChildIndex = leftChildIndex + 1;

            int minIndex = parentIndex;
            if(leftChildIndex < pq.size()) {
                if(pq[leftChildIndex] < pq[minIndex]) {
                    minIndex = leftChildIndex;
                }
            }

            if(rightChildIndex < pq.size()) {
                if(pq[rightChildIndex] < pq[minIndex]) {
                    minIndex = rightChildIndex;
                }
            }

            if(minIndex == parentIndex) {
                break;
            }
            else {
                int temp = pq[parentIndex];
                pq[parentIndex] = pq[minIndex];
                pq[minIndex] = temp;

                parentIndex = minIndex;
            }
        }

        return ans;

    }
    


};
