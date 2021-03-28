#pragma once


#include <stdbool.h>
#include <string.h>


typedef struct mimetype_t {
  const char*  name;
  const char** exts;
} mimetype_t;

extern const mimetype_t mimetype_map[];


static inline const char* mimetype_from_ext_n(const char* needle, size_t len) {
  const mimetype_t* itr = mimetype_map;
  while (itr->name) {
    const char** ext = itr->exts;
    while (*ext) {
      const bool match =
        strncmp(*ext, needle, len) == 0 && (*ext)[len] == 0;
      if (match) {
        return itr->name;
      }
      ++ext;
    }
    ++itr;
  }
  return NULL;
}
static inline const char* mimetype_from_ext(const char* needle) {
  return mimetype_from_ext_n(needle, strlen(needle));
}
