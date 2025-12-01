#include "strmem.h"
#include <string.h>

char *strmem(char *buffer, char const *string, size_t buffer_len) {
  size_t string_len = strlen(string);
  size_t i = 0, j = 0;
  while (i < buffer_len && j < string_len) {
    if (buffer[i] == string[j]) {
      ++i, ++j;
    } else {
      i = i - j + 1;
      j = 0;
    }
  }
  if (j == string_len) {
    // string found
    return buffer + i - j;
  }
  return 0;
}

