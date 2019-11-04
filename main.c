#include <stdio.h>
#include <stdlib.h>

#include <time.h>
#include "linkedlist.h"
#include "library.h"

int main(){
  printf("LINKED LIST TESTS\n");
  printf("===========================\n\n");

  struct song_node * tester = (struct song_node*)malloc(sizeof(struct song_node));
  tester = NULL;
  char * ac = "ac/dc";
  char * pearl = "pearl jam";
  tester = insert_front(tester, "radiohead", "street spirit (fade out)");
  tester = insert_front(tester, "radiohead", "paranoid android");
  tester = insert_front(tester, "pink floyd", "time");
  tester = insert_front(tester, pearl, "yellow ledbetter");
  tester = insert_front(tester, pearl, "even flow");
  tester = insert_front(tester, pearl, "alive");
  tester = insert_front(tester, ac, "thunderstruck");
  tester = insert_order(tester, ac, "a");
  tester = insert_order(tester, ac, "z");
  tester = insert_order(tester, pearl, "i");
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
  printf("===========================\n\n");


//_____________________________________________________________________________
  printf("MUSIC LIBRARY TESTS\n");
  printf("===========================\n\n");
  struct song_node * table[27];
  for(int i = 0;i < 27;i++){
    table[i]= NULL;
  }
  insert_song(table, "radiohead", "street spirit (fade out)");
  insert_song(table, "radiohead", "paranoid android");
  insert_song(table, "pink floyd", "time");
  insert_song(table, pearl, "yellow ledbetter");
  insert_song(table, pearl, "even flow");
  insert_song(table, pearl, "alive");
  insert_song(table, ac, "thunderstruck");
  insert_song(table, "presidents of the united states", "peaches");

  printf("Testing print_library:\n");
  print_library(table);
  printf("===========================\n\n");

  printf("Testing print_letter:\n");
  print_letter(table, "p");
  printf("===========================\n\n");

  printf("Testing find:\n");
  find_libsong(table, pearl, "alive");
  find_libsong(table, pearl, "time");
  printf("===========================\n\n");

  printf("Testing find_artist:\n");
  find_libartist(table, pearl);
  find_libartist(table, "pink floyd");
  find_libartist(table, "bob dylan");
  printf("===========================\n\n");

  printf("Testing remove_song:\n");
  table[index_finder(pearl)] = remove_libsong(table, pearl, "alive");
  print_library(table);
  table[index_finder(pearl)] = remove_libsong(table, pearl, "yellow ledbetter");
  print_library(table);
  printf("===========================\n\n");

  printf("Testing clear_library:\n");
  print_library(table);
  clear_library(table);
  printf("Library after clear:\n");
  print_library(table);
  printf("===========================\n\n");

  printf("Adding songs to empty library\n");
  insert_song(table, ac, "thunderstruck");
  insert_song(table, pearl, "alive");
  insert_song(table, pearl, "even flow");
  insert_song(table, pearl, "yellow ledbetter");
  insert_song(table, "pink floyd", "time");
  print_library(table);
  printf("===========================\n\n");

  printf("Testing print_artist:\n");
  print_artist(table, pearl);
  printf("\n");
  print_artist(table, ac);
  printf("===========================\n\n");

  printf("Testing shuffle\n");
  shuffle(table);
  printf("===========================\n\n");



}
