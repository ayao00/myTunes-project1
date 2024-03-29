#include <stdio.h>
#include <stdlib.h>
#include<string.h>

#include "linkedlist.h"

struct song_node * insert_front(struct song_node * new, char * artist, char * name){
  struct song_node * new_node = (struct song_node *)malloc(sizeof(struct song_node));
  strcpy(new_node->artist, artist);
  strcpy(new_node->name, name);
  new_node->next = new;
  return new_node;
}

struct song_node * insert_order(struct song_node * front, char * artist, char * name){
  if (front == NULL){
    return insert_front(front, artist, name);
  }
  struct song_node * current = front;
  struct song_node * previous = NULL;
  while(current && strcmp(current->artist, artist) < 0){
    previous = current;
    current = current->next;
  }
  while(current && strcmp(current->artist, artist) == 0 && strcmp(current->name, name) < 0){
    previous = current;
    current = current->next;
  }
  if (previous == NULL){
    return insert_front(current, artist, name);
  }
  previous->next = insert_front(current, artist, name);
  return front;
}



void print_list(struct song_node * front){
  if(front == NULL){
    printf("Empty list: []\n");
  }else{
    while(front){
      printf("%s: %s | ", front->artist, front->name);
      front = front->next;
    }
    printf("\n");
  }
}

void print_node(struct song_node * front){
  if(front == NULL){
    printf("Empty list: []\n");
  }else{
    printf("%s: %s\n", front->artist, front->name);
  }
}

struct song_node * find_song(struct song_node * front, char * artist, char * name){
  printf("looking for [%s: %s]\n", artist, name);
  struct song_node * finder = (struct song_node *)malloc(sizeof(struct song_node));
  while(front->next != NULL){
    if(strcmp(front->artist, artist) == 0 && strcmp(front->name, name) == 0){
      strcpy(finder->artist, artist);
      strcpy(finder->name, name);
      finder->next = front->next;
      printf("song found! %s: %s\n", finder->artist, finder->name);
      return finder;
    }
    front = front->next;
  }
  printf("song not found\n");
  return front;
}

struct song_node * find_artist(struct song_node * front, char * artist){
  printf("looking for [%s]\n", artist);
  struct song_node * finder = (struct song_node *)malloc(sizeof(struct song_node));
  while(front->next != NULL){
    if(strcmp(front->artist, artist) == 0){
      finder = front;
      printf("artist found! ");
      print_list(finder);
      return finder;
    }
    front = front->next;
  }
  printf("artist not found\n");
  return front;
}

struct song_node * random_song(struct song_node * front){
  struct song_node * iterator = front;
  int index = rand();
  int length = 0;
  while (iterator) {
    length++;
    iterator = iterator->next;
  }
  iterator = front;
  if(length == 0){
    return iterator;
  }
  index = index % length;
  int i = 0;
  for(;i < index;i++){
    iterator = iterator->next;
  }
  return iterator;
}

struct song_node * remove_song(struct song_node *front, char * artist, char *name){
  printf("Removing [%s: %s]\n", artist, name);
  if(front == NULL){
    printf("Empty list\n");
    return front;
  }else{
    if(strcmp(front->artist, artist) == 0 && strcmp(front->name, name) == 0){
      return front->next;
    }else{
      struct song_node * previous = front;
      struct song_node * finder = front->next;
      while(finder != NULL){
        if(strcmp(finder->artist, artist) == 0 && strcmp(finder->name, name) == 0){
          previous->next = finder->next;
          free(finder);
          return front;
        }
        previous = finder;
        finder = finder->next;
      }
      printf("%s - %s not found", artist, name);
      return front;
    }
  }
}

struct song_node * free_list(struct song_node * current){
  struct song_node* next_node = current;
  while(current){
    current = current->next;
    printf("Freeing node: %s - %s\n", next_node->artist, next_node->name);
    free(current);
    next_node = current;
  }
  return current;
}
