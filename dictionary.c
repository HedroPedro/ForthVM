#include "dictionary.h"
#include <string.h>

void dict_init(dictionary_t *dict, size_t size) {
    memset((void *) dict, 0, sizeof(dictionary_t) * size);
}

address dict_get_address(dictionary_t *dict, word id) {
    return dict[id].start;
}
