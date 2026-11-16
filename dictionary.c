#include "dictionary.h"

void dict_init(dictionary_t *dict, size_t size) {
	memset((void *) dict, 0, sizeof(dictionary_t) * size);
}

address dict_get_address(dictionary_t *dict, word id) {
	if (dict[id].is_set == false) {
		fprintf(stderr, "No dictionary entry with id: %d\n", id);
		exit(2);
	}
	return dict[id].start;
}

void dict_write_address(dictionary_t *dict, word id, address start) {
	dict[id].start = start;
	dict[id].is_set = true;
}
