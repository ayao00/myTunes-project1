struct song_node{
  char artist[100];
  char name[100];
  struct song_node *next;
};

struct song_node * insert_front(struct song_node * new, char * name, char * artist);
struct song_node * insert_order(struct song_node * new, char * name, char * artist);
void print_list(struct song_node * x);
struct song_node * find_artist(struct song_node * x, char * name, char * artist);
struct song_node * find_song(struct song_node * x, char * artist);
struct song_node * random_node(struct song_node * x);
struct song_node * node_remove(struct song_node *front, char * artist);
struct song_node * free_list(struct song_node * current);
