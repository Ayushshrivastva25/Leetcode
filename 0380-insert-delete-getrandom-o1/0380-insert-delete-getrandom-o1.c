#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define HASH_SIZE 200003  

typedef enum {
    EMPTY,      // never used
    FILLED,     // key present
    DELETED     // previously used but deleted
} SlotState;

typedef struct {
    int key;
    int index;
    SlotState state;
} HashNode;

typedef struct {
    int *nums;           
    int size;            
    int capacity;        
    HashNode *map;     
} RandomizedSet;

// Hash function
int hash(int key) {
    long long val = key;
    if (val < 0) val = -val;
    return (int)(val % HASH_SIZE);
}

RandomizedSet* randomizedSetCreate() {
    RandomizedSet* obj = (RandomizedSet*)malloc(sizeof(RandomizedSet));
    obj->capacity = 4;
    obj->size = 0;
    obj->nums = (int*)malloc(sizeof(int) * obj->capacity);
    obj->map = (HashNode*)malloc(sizeof(HashNode) * HASH_SIZE);
    
    for (int i = 0; i < HASH_SIZE; i++) {
        obj->map[i].state = EMPTY;
    }

    srand(time(NULL)); 
    return obj;
}

// Find key index in the hash map
int findKey(RandomizedSet* obj, int key) {
    int idx = hash(key);
    while (obj->map[idx].state != EMPTY) {
        if (obj->map[idx].state == FILLED && obj->map[idx].key == key)
            return idx;
        idx = (idx + 1) % HASH_SIZE;
    }
    return -1;
}

// Insert key into hash map
bool insertKey(RandomizedSet* obj, int key, int index) {
    int idx = hash(key);
    while (obj->map[idx].state == FILLED) {
        if (obj->map[idx].key == key) return false; // already exists
        idx = (idx + 1) % HASH_SIZE;
    }
    obj->map[idx].key = key;
    obj->map[idx].index = index;
    obj->map[idx].state = FILLED;
    return true;
}

// Mark a key as deleted
bool removeKey(RandomizedSet* obj, int key) {
    int idx = findKey(obj, key);
    if (idx == -1) return false;
    obj->map[idx].state = DELETED;
    return true;
}

bool randomizedSetInsert(RandomizedSet* obj, int val) {
    if (findKey(obj, val) != -1) return false;

    if (obj->size == obj->capacity) {
        obj->capacity *= 2;
        obj->nums = (int*)realloc(obj->nums, sizeof(int) * obj->capacity);
    }

    obj->nums[obj->size] = val;
    insertKey(obj, val, obj->size);
    obj->size++;
    return true;
}

bool randomizedSetRemove(RandomizedSet* obj, int val) {
    int idx = findKey(obj, val);
    if (idx == -1) return false;

    int removeIndex = obj->map[idx].index;

    // Swap last element into position of removed element
    int lastElement = obj->nums[obj->size - 1];
    obj->nums[removeIndex] = lastElement;

    // Update map for last element
    int lastIdx = findKey(obj, lastElement);
    obj->map[lastIdx].index = removeIndex;

    obj->size--;
    removeKey(obj, val);
    return true;
}

int randomizedSetGetRandom(RandomizedSet* obj) {
    int randomIndex = rand() % obj->size;
    return obj->nums[randomIndex];
}

void randomizedSetFree(RandomizedSet* obj) {
    free(obj->nums);
    free(obj->map);
    free(obj);
}
