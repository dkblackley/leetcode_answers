#include<unordered_map>
#include<vector>
#include <bits/stdc++.h>
#include <string>
#include <iostream>

using namespace std;

struct key_value {
    int key;
    int value;

    key_value(int x, int y): key(x), value(y) {}
};

class LRUCache {
public:
    unordered_map<int, list<key_value>::iterator> key_index;
    list<key_value> stack;
    int max_size;
    LRUCache(int capacity) {
        max_size = capacity;
    }

    int get(int key) {
        if (key_index.find(key) == key_index.end()) {
            return -1;
        } else {
            auto iter =  key_index[key];
            key_value KV = key_value(iter->key, iter->value); // move value to the front
            stack.erase(iter);
            stack.push_front(KV);
            key_index[key] = stack.begin();
            return KV.value;
        }
    }

    void put(int key, int value) {
        auto entry = key_index.find(key);

        if (entry == key_index.end()) { // if it doesn't exist
            if (stack.size() >= max_size) { // if it's too big, delete the back
                key_value KV = stack.back();
                key_index.erase(KV.key);
                stack.pop_back();
            }
            stack.emplace_front(key, value);
        } else { // else push it to the top of the queue
            key_value KV = key_value(entry->second->key, entry->second->value);
            if (KV.value != value) { // replace the old value and move this one to the front
                stack.erase(entry->second);
                KV.value = value;
                stack.push_front(KV);
            } else {
                stack.erase(entry->second);
                stack.push_front(KV);
            }
        }
        key_index[key] = stack.begin();
    }
};

int main() {

//    LRUCache lRUCache = *new LRUCache(2);
//    lRUCache.put(1, 1); // cache is {1=1}
//    lRUCache.put(2, 2); // cache is {1=1, 2=2}
//    lRUCache.get(1);    // return 1
//    lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
//    lRUCache.get(2);    // returns -1 (not found)
//    lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
//    lRUCache.get(1);    // return -1 (not found)
//    lRUCache.get(3);    // return 3
//    lRUCache.get(4);    // return 4



    LRUCache LR = *new LRUCache(10);

    vector<string> commands = {"put", "put", "put", "get", "put", "put", "get", "put", "put", "get", "put", "get",
                      "get", "get", "put", "put", "get", "put", "get"};

    vector<vector<int>> values{{7,28},  {7,1},  {8,15},  {6},
                             {10,27},  {8,10},  {8},  {6,29},
                             {1,9},  {6},  {10,7},  {1},
                             {2},  {13},  {8,30},  {1,5},
                             {1},  {13,2}, {12}};

    for (int i = 0; i < commands.size(); ++i) {
        if (commands[i] ==  "put") {
            LR.put(values[i][0], values[i][1]);
        } else {
            cout << LR.get(values[i][0]) << endl;
        }
    }


}




/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */