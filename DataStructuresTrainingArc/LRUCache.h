#pragma once
#include <list>
#include <vector>

class LRUCache {
public:
    explicit LRUCache(int capacity);
    int Get(int key);
    void Put(int key, int value);
private:
    static constexpr int MAX_KEY = static_cast<int>(1e4);
    static constexpr int KEY_NOT_FOUND_VALUE = -1;
    
    void RemoveLeastRecentlyUsedKey();
    void RepositionKey(int key);

    int maxCapacity;
    std::list<int> sortedKeys;
    std::vector<int> values;
    std::vector<std::list<int>::iterator> positions;
};
