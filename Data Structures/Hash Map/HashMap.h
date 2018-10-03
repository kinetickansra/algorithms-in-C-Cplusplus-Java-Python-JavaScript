template <typename V>
class MapNode {
    public :
    char *key;
    V value;
    MapNode<V> *next;

    MapNode(char *key, V value) {
        // Shallow copy
        // this -> key = key;
        
        // Deep Copy
        this -> key = new char[strlen(key) + 1];
        strcpy(this -> key, key);
        
        this -> value = value;
        next = NULL;
    }

};

template <typename V>
class HashMap {
    MapNode<V> **table;
    int totalSize;
    int size;

    void rehash() {
        cout << "Rehashing" << endl;
        
        MapNode<V> **temp = table;
        table = new MapNode<V>*[2 * totalSize];
        for(int i = 0; i < 2*totalSize; i++) {
            table[i] = NULL;
        }

        
        int prevSize = totalSize;
        totalSize *= 2;
        size = 0;
        for(int i = 0; i < prevSize; i++) {
            MapNode<V> *head = temp[i];
            while(head != NULL) {
                insert(head -> key, head -> value);
                MapNode<V> *t = head;
                head = head -> next;
                delete t;
            }
        }
        delete [] temp;
    }





    int getIndex(char *key) {
        int len = strlen(key);
        long power = 1;  
        long ans = 0;
        for(int i = len - 1; i >= 0; i--) {
            ans = ans + (key[i] * power);
            power *= 37;
        }
        return (ans % totalSize);
    }


    public :

    HashMap() {
        table = new MapNode<V>*[7];
        totalSize = 7;
        for(int i = 0; i < totalSize; i++) {
            table[i] = NULL;
        }
        size = 0;
    }

    void insert(char *key, V value) {
        int index = getIndex(key);
        
        // Check if key already exists
        MapNode<V> *head = table[index];
        while(head != NULL) {
            if(strcmp(head -> key, key) == 0) {
                head -> value = value;
                return;
            }
            head = head -> next;
        }

        
        MapNode<V> *newNode = new MapNode<V>(key, value);
        newNode -> next = table[index];
        table[index] = newNode;
        size++;
    
        double loadFactor = (size * 1.0) / totalSize;
        if(loadFactor > 0.7) {
            rehash();
        }
    }

    V search(char *key) {
        int index = getIndex(key);
        
        // Check if key already exists
        MapNode<V> *head = table[index];
        while(head != NULL) {
            if(strcmp(head -> key, key) == 0) {
                return head -> value;
            }
            head = head -> next;
        }
        return 0;
    }

    void remove(char *key) {
        int index = getIndex(key);
        
        
        MapNode<V> *head = table[index], *prev = NULL;
        while(head != NULL) {
            if(strcmp(head -> key, key) == 0) {
                if(prev == NULL) {
                    table[index] = head -> next;
                }
                else {
                    prev -> next = head -> next;
                }
                size--;
                delete head;
                return;
            }
            prev = head;
            head = head -> next;
        }
    }

    int getSize() {
        return size;
    }





};
