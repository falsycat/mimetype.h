#undef NDEBUG

#include <assert.h>
#include <stdlib.h>

#include "mimetype.h"


int main(void) {
  assert(strcmp(mimetype_from_ext("mp3"), "audio/mpeg") == 0);
  assert(strcmp(mimetype_from_ext("mp4"), "video/mp4") == 0);

  assert(mimetype_from_ext("unchi") == NULL);
  assert(mimetype_from_ext("kusai") == NULL);

  return EXIT_SUCCESS;
}
