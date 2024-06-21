#include "LRUCache.h"

LRUCache::LRUCache(const int capacity): maxCapacity(capacity) {
    values.resize(MAX_KEY, KEY_NOT_FOUND_VALUE);
    positions.resize(MAX_KEY, sortedKeys.end());
}

int LRUCache::Get(const int key) {
    RepositionKey(key);
    return values[key];
}

void LRUCache::Put(const int key, const int value) {
    values[key] = value;
    RepositionKey(key);
    if (positions[key] == sortedKeys.end()) {
        RemoveLeastRecentlyUsedKey();
        positions[key] = sortedKeys.insert(sortedKeys.end(), key);
    }
}

void LRUCache::RemoveLeastRecentlyUsedKey() {
    if (sortedKeys.size() < maxCapacity) {
        return;
    }
    const int leastRecentlyUsedKey = *sortedKeys.begin();
    positions[leastRecentlyUsedKey] = sortedKeys.end();
    values[leastRecentlyUsedKey] = -1;
    sortedKeys.pop_front();
}

void LRUCache::RepositionKey(const int key) {
    if (positions[key] != sortedKeys.end()) {
        sortedKeys.erase(positions[key]);
        positions[key] = sortedKeys.insert(sortedKeys.end(), key);
    }
}
