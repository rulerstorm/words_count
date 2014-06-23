#include "main.h"
#include "functions.h"

//----------global--------------------
int total_word = 0;
int total_char = 0;
int total_line = 0;

char * source_text[MAX_LINE];
char * handled_text[MAX_LINE];

p_word buff_word ;






int main(int argc, char const *argv[])
{
	buff_word = (p_word)malloc(MAX_WORDS * sizeof(s_word));
	memset(buff_word, 0, MAX_WORDS * sizeof(s_word));

	char buf[50];
	get_text();

	char * temp;
	int index;
	int temp_top;

	while(fgets(buf, 50, stdin))
	{
		to_space(buf);

		remove_space(buf);
		if(NULL != (temp = strstr(buf, "search")))
		{
			if(-1 != (index = search_str(temp+6)))
			{
				printf("%s\n", source_text[index]);
			}
			else
				printf("None!\n");
		}

		if(NULL != (temp = strstr(buf, "wc-l")))
		{
			printf("There are %d lines\n", total_line);
		}

		if(NULL != (temp = strstr(buf, "wc-c")))
		{
			printf("There are %d charachers\n", total_char);
		}

		if(NULL != (temp = strstr(buf, "wc-w")))
		{
			printf("There are %d words\n", total_word);
		}

		if(NULL != (temp = strstr(buf, "top")))
		{
			sscanf(buf + 3, "%d", &temp_top);
			partial_sort(buff_word, 0, total_word-1, MAX_WORDS-1);

			for (int i = 0; i < temp_top; ++i)
			{
				printf("%d, %s\n", buff_word[i].count, buff_word[i].word );
			}

		}

	}


	return 0;
}