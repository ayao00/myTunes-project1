int index_finder(char * artist);
void insert_song(struct song_node *table[27], char * artist, char *name);
struct song_node * find_libsong(struct song_node * table[27], char * artist, char * name);
struct song_node * find_libartist(struct song_node * table[27], char * artist);
void print_letter(struct song_node * table[27], char * letter);
void print_artist(struct song_node * table[27]);
void print_library(struct song_node * table[27]);
struct song_node * shuffle(struct song_node * table[27]);
struct song_node * remove_libsong(struct song_node *table[27], char * artist, char *name);
struct song_node * clear_library(struct song_node * table[27]);
