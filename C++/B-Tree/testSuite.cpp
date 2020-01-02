#include "btree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {

  char select[2]; // 3 byte selection input

  char input[2]; // user input

  // For measurement
  // clock_t start, end;

  // double cpu_time_used;
  BTree t(3); // A B-Tree with minium degree 3
  t.insert(10);
  t.insert(20);
  t.insert(5);
  t.insert(6);
  t.insert(12);
  t.insert(30);
  t.insert(7);
  t.insert(17);

  while (strcmp(select, "q") != 0) {

    printf("1. Traverse\n");
    printf("Choose an option or type q to exit: ");

    fgets(select, 3, stdin);

    select[strcspn(select, "\n")] =
        '\0'; // strcspn Returns index of that character

    switch (atoi(select)) {

    case 1:
      t.traverse();

      break;
    case 2:

      break;
    case 3:

      break;
    case 4:
      // levelorder(root);
      break;

    case 5:
      break;
    }
  }

  return 0;
}
