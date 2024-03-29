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
  if (table[i]){
    return find_song(table[i], artist, name);
  }
  else{
    printf("looking for [%s: %s]\n", artist, name);
    printf("song not found");
    return NULL;
  }
}

struct song_node * find_libartist(struct song_node * table[27], char * artist){
  int i = index_finder(artist);
  if (table[i]){
    return find_artist(table[i],artist);
  }
  else{
    printf("looking for [%s]\n", artist);
    printf("artist not found\n");
    return NULL;
  }

}

void print_letter(struct song_node * table[27], char * letter){
  int i = index_finder(letter);
  printf("%s list\n", letter);
  print_list(table[i]);
}

void print_artist(struct song_node * table[27], char *artist){
  int i = index_finder(artist);
  struct song_node * art = find_artist(table[i], artist);
  if(strcmp(art ->artist, artist)!=0){
    printf("artist not found\n");
  }else{
    printf("looking for [%s]\nartist found! ", artist);
    while(art){
      if(strcmp(art->artist,artist)==0){
        printf("%s: %s | ", art->artist, art->name);
      }
      art = art->next;
    }
    printf("\n");
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

void shuffle(struct song_node * table[27]){
  printf("shuffled playlist\n");

  int i = rand();
  i = (int) i % 10;
  for(int j = 0; j < i;){
    int index = rand() % 27;
    struct song_node * randomsong = random_song(table[index]);
    if(randomsong){
      printf("[%s, %s]\n", randomsong->artist, randomsong->name);
      j++;
    }
  }
}

struct song_node * remove_libsong(struct song_node *table[27], char * artist, char *name){
  int i = index_finder(artist);
  return remove_song(table[i],artist,name);
}

void clear_library(struct song_node * table[27]){
  int i = 0;
  for(; i< 27;i++){
    if(table[i]){
      table[i] = free_list(table[i]);
    }
  }
}
