#include <stdio.h>
#include <stdlib.h>

#include "linkedlist.h"

struct song_node * insert_front(struct song_node * new, char * artist, char * name){
  struct song_node * new_node = (struct song_node *)malloc(sizeof(struct song_node));
  new_node->name= name;
  new_node->artist = artist;
  new_node->next = new;
  return new_node;
}

void print_list(struct song_node * front){
  if(front == NULL){
    printf("Empty list: []\n");
  }else{
    printf("List:[");
    while(front->next != NULL){
      printf("%s, %s, ", front->artist, front->name);
      front = front->next;
    }
    printf("%s, %s]\n", front->artist, front->name);
  }
}

struct song_node * free_list(struct song_node * current){
  struct song_node* next_node = (struct song_node *)malloc(sizeof(struct song_node));
  if(current->next != NULL){
    next_node = current->next;
    printf("Freeing node: %s\n", current->name);
    free(current);
    free_list(next_node);
  }else{
    printf("List freed\n");
  }
  return NULL;
}

struct song_node * random_song();

struct song_node * remove_song(struct song_node *front, char * artist){
  if(front == NULL){
    printf("Empty list\n");
    return front;
  }else{
    if(front->artist == artist){
      return front->next;
    }else{
      struct song_node * previous = front;
      struct song_node * finder = front->next;
      while(finder != NULL){
        if(finder->artist == artist){
          previous->next = finder->next;
          free(finder);
          return front;
        }
        previous = finder;
        finder = finder->next;
      }
      return front;
    }
  }
}
