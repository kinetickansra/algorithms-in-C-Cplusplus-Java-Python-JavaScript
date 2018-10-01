template <typename T>
class Queue {
    T *data;
    int nextIndex;
    int frontIndex;
    int size;
    int totalSize;

    public :

    Queue() {
        data = new T[5];
        nextIndex = 0;
        frontIndex = -1;
        this -> size = 0;
        totalSize = 5;
    }

    int getSize() {
        return size;
    }

    bool isEmpty() {
        return size == 0;
    }

    T front() {
        if(isEmpty()) {
            cout << "Queue empty ! " << endl;
            return 0;
        }
        return data[frontIndex];
    }

    void enqueue(T element) {
        if(frontIndex == nextIndex) {
            T *temp = new T[2 * totalSize];
            int j = 0;
            for(int i = frontIndex; i < totalSize; i++) {
                temp[j++] = data[i];
            }
            for(int i = 0; i < frontIndex; i++) {
                temp[j++] = data[i];
            }
            nextIndex = totalSize;
            totalSize *= 2;
            delete [] data;
            data = temp;
            frontIndex = 0;
            
        }
        data[nextIndex] = element;
        nextIndex = (nextIndex + 1) % totalSize;
        size++;
        if(frontIndex == -1) {
            frontIndex = 0;
        }
    }

    T dequeue() {
        if(isEmpty()) {
            cout << "Queue empty ! " << endl;
            return 0;
        }
        T ans = data[frontIndex];
        frontIndex = (frontIndex + 1) % totalSize;
        size--;
        if(size == 0) {
            frontIndex = -1;
            nextIndex = 0;
        }
        return ans;
    }


};
