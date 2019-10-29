struct song_node{
  char name[100];
  char artist[100];
  struct song_node *next;
};

struct node * insert_front(struct song_node * new, char * name, char * artist);
struct node * insert_order(struct song_node * new, char * name, char * artist);
void print_list(struct song_node * x);
struct node * find_artist(struct song_node * x, char * name, char * artist);
struct node * find_song(struct song_node * x, char * artist);
struct node * random_node(struct song_node * x);
struct node * node_remove(struct song_node *front, char * artist);
struct node * free_list(struct song_node * current);
