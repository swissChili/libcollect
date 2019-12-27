#ifndef LIBCOLLECT_VECTOR_H
#define LIBCOLLECT_VECTOR_H

#include <stdint.h>

#define VEC_ALLOC_SIZE 256

/**
 * @brief An auto-allocating container of numbered pointers
 * Use new_vector() or new_vector_sized() to allocate a vector on the heap. Use
 * free_vector() to free such a vector. Use vector_at(), vector_set(), and
 * vector_push() to get, assign, and add items to a vector.
 */
typedef struct
{
    uint64_t length;
    uint64_t size;
    void **items;
} vector;

/**
 * @brief Allocate a new vector on the heap.
 * @param size The number of elements the vector should be allocated to hold
 * @return A pointer to the vector
 */
vector *new_vector_sized(uint64_t size);

/**
 * @brief Allocate a new vector on the heap.
 * @return A pointer to the vector
 */
vector *new_vector();

/**
 * @brief Free a vector allocated on the heap.
 * @param vec A pointer to the vector to free
 */
void free_vector(vector *vec);

/**
 * @brief Get an item at a certain position in a vector.
 * @param vec A pointer to the vector
 * @param i The index at which to get the item
 * @return A pointer to the item if it exists, NULL otherwise
 */
void *vector_at(vector *vec, uint64_t i);

/**
 * @brief Set the item at some position in the vector
 * @param vec A pointer to the vector
 * @param i The index whose value to set
 * @param val The value
 * @return 1 on success, 0 if cannot allocate more memory
 */
int vector_set(vector *vec, uint64_t i, void *val);

/**
 * @brief Push another item onto the end of a vector
 * @param vec A pointer to the vector
 * @param val The value to push
 */
void vector_push(vector *vec, void *val);


#endif //LIBCOLLECT_VECTOR_H