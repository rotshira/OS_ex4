#include <assert.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
//we took it from https://danluu.com/malloc-tutorial/
pthread_mutex_t lock_new = PTHREAD_MUTEX_INITIALIZER;

void *malloc(size_t size) {
  if (pthread_mutex_init(&lock_new, NULL) != 0) { //init lock
        printf("\n mutex init has failed\n");
        // return 1;
  }
  pthread_mutex_lock(&lock_new);
  void *p = sbrk(0);
  void *request = sbrk(size);
  if (request == (void*) -1) {
    return NULL; // sbrk failed.
  } else {
    assert(p == request); // Not thread safe.
    return p;
  }
  pthread_mutex_unlock(&lock_new);
}

void *calloc(size_t nelem, size_t elsize) {
  size_t size = nelem * elsize; // TODO: check for overflow.
  void *ptr = malloc(size);
  memset(ptr, 0, size);
  return ptr;
}

void free(void *ptr) {
  if (!ptr) {
      free(ptr);
    return;
}
}