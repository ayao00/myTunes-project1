#include <stdio.h>
#include <stdlib.h>
#include<string.h>

#include "linkedlist.h"
#include "library.h"

int index_finder(char * artist){
  return *artist - 97;
}



void insert_song(struct song_node *table[27], char * artist, char *name){
  int i = index_finder(artist);
  table[i] = insert_order(table[i], artist, name);
}

struct song_node * find_libsong(struct song_node * table[27], char * artist, char * name){
  int i = index_finder(artist);
  return find_song(table[i], artist, name);
}

struct song_node * find_libartist(struct song_node * table[27], char * artist){
  int i = index_finder(artist);
  return find_artist(table[i],artist);
}

void print_letter(struct song_node * table[27], char * letter){
  int i = index_finder(letter);
  printf("%s list", letter);
  print_list(table[i]);
}

void print_artist(struct song_node * table[27], char *artist){
  int i = index_finder(artist);
  struct song_node * art = find_artist(table[i]);
  if(strcmp(art ->artist, artist)!=0){
    printf("artist not found");
  }else{
    printf("looking for [%s]\nartist found! ", artist);
    while(art){
      if(strcmp(art->artist,artist)==0){
        printf("%s: %s | ", art->artist, art->name);
      }
      art = art->next;
    }
  }
}

void print_library(struct song_node * table[27]){
  int i = 0;
  for(;i < 27;i++){
    if(table[i]){
      if(i == 26){
        printf("Other letters: \n");
      }else{
        printf("%c list\n", 'a' + i);
      }
      print_list(table[i]);
    }
  }
}

struct song_node * shuffle(struct song_node * table[27]){
  printf("shuffled playlist\n");

  int i = rand();
  i = (int) rand() % 8;
  for(int j = 0; j < i;i++){
    int index = rand() % 27;
    struct song_node * randomsong = random_song(table[indext]);
    if(randomsong){
      printf("[%s, %s],", randomsong->artist, randomsong->name);
      count++;
    }
  }
}

struct song_node * remove_libsong(struct song_node *table[27], char * artist, char *name){
  int i = index_finder(artist);
  return remove_song(table[i],artist,name);
}
