#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define MAXWORD 100

struct tnode {
  char *word;
  int count;
  struct tnode *left;
  struct tnode *right;
};

struct tnode *addtree(struct tnode *, char *);
void treeprint(struct tnode *);
int getword(char *, int);

int main(void) {
  struct tnode *root;
  char word[MAXWORD];

  root = NULL;
  while (getword(word, MAXWORD) != EOF)
    if (isalpha(word[0]))
      root = addtree(root, word);
  treeprint(root);
  return 0;
}

struct tnode *talloc(void);

struct tnode *addtree(struct tnode *p, char *w) {
  int cond;

  if (p == NULL) {
    p = talloc();
    p->word = strdup(w);
    p->count = 1;
    p->left = p->right = NULL;
  } else if ((cond = strcmp(w, p->word)) == 0)
    p->count++;
  else if (cond < 0)
    p->left = addtree(p->left, w);
  else
    p->right = addtree(p->right, w);

  return p;
}

int mystrcmp(char *, char *, int);

void mytreeprint(struct tnode *p, int n) {
  static int printprevious = 1;
  static struct tnode *previous;
  if (p != NULL) {
    mytreeprint(p->left, n);
    if (n == 0)
      printf("%4d %s\n", p->count, p->word);
    else {
      if (previous != NULL) {
        if (mystrcmp(previous->word, p->word, n)) {
          if (printprevious) {
            printf("%4d %s\n", previous->count, previous->word);
            printprevious = 0;
          }
          printf("%4d %s\n", p->count, p->word);

        } else
          printprevious = 1;
      }
      previous = p;
    }
    mytreeprint(p->right, n);
  }
}

int mystrcmp(char *s1, char *s2, int n) {
  int i;
  if (n == 0)
    return 1;
  for (i = 0; *s1 == *s2 && *s1 != '\0' && i < n; i++, *s1++, *s2++)
    ;
  if (i == n)
    return 1;
  return 0;
}
