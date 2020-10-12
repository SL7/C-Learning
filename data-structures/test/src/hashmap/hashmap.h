#ifndef HASHMAP_H
#define HASHMAP_H

typedef struct _node {
    char *key;
    int val;
}node;

typedef struct _table {
    int size;
    int element_count;
    node **list;
}table;

table *HashMap(int size);
/**
 * Check if a hashmap contains a key
 * If succesful returns the position in the list,
 * otherwise -1.
 * @param *t hashmap to check
 * @param key key to check
 * 
 * @return position
 */
int containsKey(table *t, char *key);

/**
 * Put a key value pair in the hashmap
 * @param *t hashmap to put in
 * @param key Key
 * @param val Value of key
 */
int put(table *t, char *key, int val);

/**
 * Get the value of the given key
 * returns -1 if key does not exist
 * @param *t hashmap to get value from
 * @param key key to get value from
 */
int getValue(table *t, char *key);

/**
 * Delete a given key value pair
 * returns -1 if key does not exist
 * @param *t    hashmap to delete the value from
 * @param key   Key to remove
 */
int del(table *t, char *key);

/**
 * Resize the hashmap to a given bigger size
 * returns 1 on success
 * @param *t hashmap to check
 * @param size new size of hashmap
 */
int resize(table *t, int size);


node first(table *t);

/**
 * Checks if the hashmap contains a value
 * returns the position of the first element if found
 * else returns -1
 * @param *t    Hashmap to check
 * @param value Value to search for
 */
int containsValue(table *t, int value);

/**
 * Checks if the hashmap is empty
 * @param *t hashmap to check
 */
int isEmpty(table *t);

/**
 * Clear the hashmap
 * @param *t hashmap to clear
 */
void clear(table *t);
#endif
