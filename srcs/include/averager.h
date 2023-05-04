#ifndef AVERAGER_H
#define AVERAGER_H

// SYSTEM HEADERS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>

// COLORS
#define GREEN "\033[0;32m"
#define HGREEN "\033[1;32m"
#define DEF_COLOR "\033[0;39m"
#define CYAN "\033[0;36m"
#define HCYAN "\033[1;36m"
#define WHITE "\033[1;97m"
#define MAGENTA "\033[0;35m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define HBLUE "\033[1;34m"
#define HRED "\033[1;31m"
#define RED "\033[0;91m"
#define MT_LEN 624
#define MT_IA 397

// USER DEFINED TYPES
typedef unsigned int uint;

typedef struct MT {
    uint state[MT_LEN];
    int next;
} t_MT;

typedef struct s_args {
    int **table;
} t_args;

typedef struct s_uargs {
    uint **table;
} t_uargs;

// FUNCTION PROTOTYPES
int is_repeated100(uint **table, uint *tmp_arr, int count);
int is_repeated500(uint **table, uint *tmp_arr, int count);
int *next_permutation(int *arr, int last_index);
uint *seq_except(int exclude);
int *next_permutation(int *arr, int last_index);
void ft_free_arr(char **arr, void **aux);
void ft_free_arr_size(void **arr, uint size);
void shuffle_array(uint *arr, int len, uint seed);
void execute_bonus5(void *args_void);
void execute_bonus10(void *args_void);
void execute_bonus15(void *args_void);
void execute_bonus20(void *args_void);
void execute_bonus100(void *args_void);
void execute_bonus500(void *args_void);
void execute_bonus1000(void *args_void);
void build_bonus5_string(char memtest[], int i, int **table);
void build_reference5_string(char command[5000], int i, int **table);
void build_bonus10_string(char memtest[], int i, int **table);
void build_reference10_string(char memtest[], int i, int **table);
void build_bonus15_string(char memtest[], int i, int **table);
void build_reference15_string(char memtest[], int i, int **table);
void build_bonus20_string(char memtest[], int i, int **table);
void build_reference20_string(char memtest[], int i, int **table);
void build_bonus100_string(int i, int **table, char command[]);
void build_reference100_string(int i, int **table, char command[]);
void build_bonus500_string(int i, int **table, char command[]);
void build_reference500_string(int i, int **table, char command[]);
void build_bonus1000_string(int i, int **table, char *command);
void build_reference1000_string(int i, int **table, char *command);
int **init_table(void);

#endif