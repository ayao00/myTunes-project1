#include <stdio.h>
#include <stdlib.h>

#include <time.h>
#include "linkedlist.h"
#include "library.h"

int main(){
  printf("LINKED LIST TESTS\n");
  printf("===========================\n\n");

  struct song_node * tester = (struct song_node*)malloc(sizeof(struct song_node));
  char * ac = "ac/dc";
  char * pearl = "pearl jam";
  tester = insert_front(tester, "radiohead", "street spirit (fade out)");
  tester = insert_front(tester, "radiohead", "paranoid android");
  tester = insert_front(tester, "pink floyd", "time");
  tester = insert_front(tester, pearl, "yellow ledbetter");
  tester = insert_front(tester, pearl, "even flow");
  tester = insert_front(tester, pearl, "alive");
  tester = insert_front(tester, ac, "thunderstruck");
  //tester = insert_order(tester, ac, "a");
  //tester = insert_order(tester, ac, "z");
  //tester = insert_order(tester, pearl, "i");
  printf("Testing print_list:\n");
  print_list(tester);
  printf("===========================\n\n");

  printf("Testing find_node:\n");
  find_song(tester, pearl, "even flow");
  find_song(tester, pearl, "daughter");
  printf("===========================\n\n");

  printf("Testing find_artist:\n");
  find_artist(tester, "pink floyd");
  find_artist(tester, pearl);
  find_artist(tester, "presidents of the united states of america");
  printf("===========================\n\n");
  srand(time(NULL));
  printf("Testing random:\n");
  print_node(random_song(tester));
  print_node(random_song(tester));
  printf("===========================\n\n");

  printf("Testing remove:\n");
  tester = remove_song(tester, pearl, "alive");
  print_list(tester);
  tester =remove_song(tester, pearl, "yellow ledbetter");
  print_list(tester);
  tester = remove_song(tester, "pink floyd", "alive");
  print_list(tester);
  printf("===========================\n\n");

  printf("Testing free_list\n");
  tester = free_list(tester);
  print_list(tester);

}
