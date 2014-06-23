#include "main.h"




void remove_space(char *str)
{
    int i = 0;
    char *p = str;
    while (*p)
    {
        if ((*p) != ' ')            //isalpha(*p) || isdigit(*p)
            str[i++] = *p;
        p++;
    }
    str[i] = '\0';
}


void to_space(char *str)
{
    char *p = str;
    while (*p)
    {
        if (!isalpha(*p) && !isdigit(*p) && (*p != '\0') && (*p != '-'))
            *p = ' ';

        if (isupper(*p))
        	*p = *p + 32;

        p++;
    }
}


int find_buff_word(char *str)       //找到返回0
{
    int i = 0;
    int flag = 0; 
    while (buff_word[i].count != 0)
    {
        if (0 == strcmp(buff_word[i].word, str))
        {
        	flag = 1;
        	++(buff_word[i].count);
        	i = MAX_WORDS-1;
        }	
        ++i;
    }
    if(flag == 1)
    	return 0;
    else
    	return 1;
}



void count_word(char * inn)
{
    char buffer[MAX_WORD];
    int i;
    char  * str = inn;

    while (*str)
    {
        i = 0;
    	memset(buffer, 0, MAX_WORD);
            // printf("ok\n");
        while ((*str)!=0 && (*str) == ' ')
        	++str;
            // printf("ok\n");
        while ((*str)!=0  && (*str) != ' ')
        {
			buffer[i] = *str;
            ++str;
            ++i;
        }
            // printf("ok\n");
        if (strlen(buffer)!=0 && find_buff_word(buffer))
        {    
		    strcpy(buff_word[total_word].word, buffer);
		    buff_word[total_word].count = 1;
		    ++total_word;
        }

    }

}





void get_text(void)
{
    char *temp_line_1;
    char *temp_line_2;
    int i = 0, j = 0;

    char buff[MAX_LINE] = {};

    FILE *bible = fopen("The_Holy_Bible.txt", "rb");

    while (fgets(buff, MAX_LINE, bible))
    {
        temp_line_1 = (char *)malloc(sizeof(char) * MAX_LINE);
        strcpy(temp_line_1, buff);
        source_text[i++] = temp_line_1;
        total_char += strlen(temp_line_1);


        temp_line_2 = (char *)malloc(sizeof(char) * MAX_LINE);
        strcpy(temp_line_2, buff);

        to_space(temp_line_2);

        count_word(temp_line_2);

        remove_space(temp_line_2);
        handled_text[j++] = temp_line_2;
    }

    total_line = j;
}




int search_str(char * inn)
{
	for (int i = 0; i < total_line; ++i)
	{
		if(strstr(handled_text[i], inn)!=NULL)
			return i;
	}
	return -1;

}




int partition(s_word arr[] ,int low,int high)
{                                    
    s_word pivot = arr[low];          
    while(low < high)               
    {
        while(low < high && arr[high].count <= pivot.count) 
            high--;                
		arr[low] = arr[high];      

		while(low < high && arr[low].count >= pivot.count)  
            low++;                     
		arr[high] = arr[low];    
    }                        
	
	arr[low] = pivot;          

    return low;                
}



void partial_sort(s_word arr[], int low, int high, int rank)
{
    if(low < high)              
    {  
        int mid = partition(arr, low, high);    
        if(mid > rank)       //单侧排序
            partial_sort(arr, low, mid-1 , rank); 
        else                //此时恢复为快排
        {
            partial_sort(arr, low , mid-1, rank);
            partial_sort(arr, mid+1, high, rank);  
        }         
    }  
}













