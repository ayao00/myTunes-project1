#include <stdio.h>
#include <stdlib.h>

#include "linkedlist.h"
#include "library.h"

int main(){
  printf("LINKED LIST TESTS\n");
  printf("===========================\n");

  struct song_node * tester = (struct song_node*)malloc(sizeof(struct song_node));
  char * ac = "ac/dc";
  char * pearl = "pearl jam";
  tester = insert_front(tester, ac,"thunderstruck");
  tester = insert_front(tester, pearl, "alive");
  tester = insert_front(tester, pearl, "even flow");
  tester = insert_front(tester, pearl, "yellow ledbetter");
  tester = insert_front(tester, "pink floyd", "time");
  tester = insert_front(tester, "radiohead", "paranoid android");
  tester = insert_front(tester, "radiohead", "street spirit");
  printf("Testing print_list:\n");
  print_list(tester);

}
