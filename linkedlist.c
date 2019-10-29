#include <stdio.h>
#include <stdlib.h>

#include "functions.h"

struct node * insert_front(struct song_node * new, char name, char artist){
  struct song_node * new_node = (struct song_node *)malloc(sizeof(struct song_node));
  new_node->name= name;
  new_node->artist = artist;
  new_node->next = new;
  return new_node;
}

void print_list(struct song_node * x){
  if(x == NULL){
    printf("Empty list: []\n");
  }else{
    printf("List:[");
    while(x->next != NULL){
      printf("%d, ", x->i);
      x = x->next;
    }
    printf("%d]\n", x->i);
  }
}

struct song_node * free_list(struct song_node * current){
  struct song_node* next_node = (struct song_node *)malloc(sizeof(struct song_node));
  if(current->next != NULL){
    next_node = current->next;
    printf("Freeing node: %d\n", current->i);
    free(current);
    free_list(next_node);
  }else{
    printf("List freed\n");
  }
  return NULL;
}

struct node * node_remove(struct song_node *front, int data){
  if(front == NULL){
    printf("Empty list\n");
    return front;
  }else{
    if(front->i == data){
      return front->next;
    }else{
      struct node * previous = front;
      struct node * finder = front->next;
      while(finder != NULL){
        if(finder->i == data){
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