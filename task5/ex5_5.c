#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct trie {
  struct trie *child;
  struct trie *next;
  char c;
} trie_t;

void init_trie(trie_t *ptr)
{
  int i;
  for (i = 0; i < 256; ++i) {
    ptr->array[i] = NULL;
  }
  return;
}

trie_t *new_trie(void)
{
  trie_t *ptr;

  if ((ptr = malloc(sizeof(trie_t))) == NULL) {
    fprintf(stderr, "Out of memory\n");
    exit(1);
  }
  init_trie(ptr);

  return ptr;
}

void add_to_trie(char *str, trie_t *ptr)
{
  if (strlen(str) == 0) {
    if (ptr->c == '\0') {
      ptr->c = '.';
      return;
    } else if (ptr->c == '.') {
      return;
    } else if (ptr->next == NULL) {
      ptr->next = new_trie();
      ptr->next->c = '.';
      return;
    } else {
      add_to_trie(str, ptr->next);
      return;
    }
  }

  if (ptr->c == '\0') {
    /* Implement by yourself */
  } else if (ptr->c == *str) {
    /* Implement by yourself */
  } else if (ptr->next == NULL) {
    /* Implement by yourself */
  } else {
    /* Implement by yourself */
  }
}

  /* Implement by yourself */
trie_t *find_in_trie(char *str, trie_t *ptr)
{
  if (ptr == NULL)
        return NULL;

    if (strlen(str) == 0)
        return ptr->array['.'];

    return find_in_trie(str + 1, ptr->array[*str]);
}

void free_trie(trie_t *ptr)
{
  int i;
  for (i = 0; i < 256; ++i) {
    if (ptr->array[i] != NULL) {
      free_trie(ptr->array[i]);
    }
  }
  free(ptr);
}

int main(int argc, char *argv[])
{
  FILE *f;
  char str[512];
  trie_t *root;

  if (argc != 3) {
    fprintf(stderr, "Missing argument\n");
    exit(1);
  }

  if ((f = fopen(argv[1], "r")) == NULL) {
    fprintf(stderr, "Can't open %s\n", argv[1]);
    exit(1);
  }

  root = new_trie();
  while (fgets(str, 512, f)) {
    if (str[strlen(str) - 1] == '\n') {
      str[strlen(str) - 1] = '\0';
    }
    add_to_trie(str, root);
  }

  fclose(f);

  if (find_in_trie(argv[2], root) != NULL) {
    printf("%s: \"%s\" is found in %s\n", argv[0], argv[2], argv[1]);
  } else {
    printf("%s: \"%s\" is not found in %s\n", argv[0], argv[2], argv[1]);
  }

  free_trie(root);

  return 0;
}