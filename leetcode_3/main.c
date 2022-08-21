//
//  main.c
//  3.-Longest-Substring-Without-Repeating-Characters
//
//  Created by 夏蜃詰 on 2022/7/3.
//Time Complexity: O(N), where N is the length of the string.
//Space Complexity: O(min(N,M)), as HashSet is used. N is the length of the string and M is the size of the substrings.//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lengthOfLongestSubstring(char * s){
    unsigned int map[256] = {0};
    uint16_t ret = 0;
    uint16_t cnt = 0;
    char* index = s;
    char* index_2 = s;
    unsigned int char_number;

    while(*index_2)
    {
        char_number = (int)*(index_2);//search_char_number(*(s+index));

        
        if(map[char_number] == 1)
        {
            cnt = index_2-index;
            if(ret < cnt)
            {
                ret = cnt;
            }
            while(*index != *index_2)
            {
                /*kick of the repeating character**/
                char_number = (int)*(index);
                map[char_number] = 0;
                index++;
                
            }
            index++;
        }
        else
        {
            map[char_number]= 1;
        }
        index_2++;
    }
    cnt = index_2-index;
    if(ret < cnt)
    {
        ret = cnt;
    }
    return ret;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    char s[]="abcabcbb";
    int result = lengthOfLongestSubstring(s);
    printf("result = %d\n",result);
    return 0;
}
