#ifndef mainh
#define mainh value



#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


#define MAX_WORD 20
#define MAX_LINE 50000
#define MAX_WORDS 70000





typedef struct topword
{
	char word[MAX_WORD];
	int count;
} s_word, * p_word;




extern int total_word;
extern int total_char;
extern int total_line;

extern char * source_text[MAX_LINE];
extern char * handled_text[MAX_LINE];

extern p_word buff_word ;

















#endif

