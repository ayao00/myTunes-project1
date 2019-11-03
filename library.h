void print_library(struct song_node * front);
void print_letter(struct song_node * front);
struct song_node * find_song(struct song_node * front, char * artist, char * name);
struct song_node * find_artist(struct song_node * front, char * artist);
struct song_node * remove_song(struct song_node *front, char * artist, char *name);
struct song_node * clear_library(struct song_node * front);
void print_artist(struct song_node * front);
struct song_node * shuffle(struct song_node * front);
