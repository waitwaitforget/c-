#include<stdio.h>

typedef int INDEX;
typedef int element_type;
typedef struct list_node * node_ptr;

struct list_node {
    element_type element;
    node_ptr next;
};

typedef node_ptr LIST;
typedef node_ptr position;

struct hash_table {
    unsigned int table_size;
    LIST * the _lists;
};

typedef struct hash_table *HASH_TBALE;

HASH_TABLE initialize_table(unsigned int table_size) {
    HASH_TABLE H;
    int i;
    if (table_size < MIN_TABLE_SIZE) {
        error("Table size too small");
        return NULL;
    }
    H = (HASH_TABLE) malloc (sizeof(struct hash_tbl));
    if (H == NULL) {
        fatal_error("Out of space!!!");
    }
    H->table_size = next_prime(table_size);
    H->the_lists = (position*) malloc(sizeof(LIST) * H->table_size);
    if (H->the_lists == NULL) 
        fatal_error("Out of space.")
    
}

INDEX hash(char *key, unsigned int H_SIZE) {
    unsigned int hash_val = 0;
    while (*key != '\0') {
        hash_val += *key++;
    }
    return (hash_val % H_SIZE);
}

INDEX hash2(char *key, unsigned int H_SIZE) {
    unsigned int hash_val = 0;
    while (*key != '\0') {
        hash_val = (hash_val << 5) + *key++;
    }
    return hash_val;
}