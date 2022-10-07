//
//  main.c
//  5_Longest_Palindromic_Substring
//  1. use dynamic programming to handle O(n^2)
//  2. use central expand, needs to consider both even and odd condition
//  Created by 夏蜃詰 on 2022/8/6.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#define n 5
char * longestPalindrome(char * s){
    char *sub_string = s;
    uint32_t n = (uint32_t)strlen(s);
//    uint32_t n_half = n/2;
    if(n==1) return s;
    int32_t i = 0;
    int32_t j = 0;
    int32_t k = 0;
    uint32_t max_len = 1;
    
    for(i=0;i<n;i++)
    {
        /*even length*/
        j=i;
        k=i+1;
        while(j>=0 && k<n)
        {
            if(s[j]!=s[k]) break;
            if(k-j+1>max_len)
            {
                max_len = k-j+1;
                sub_string = &s[j];
            }
            k++;
            j--;
            
        }
        /*odd length*/
        k=i+1;
        j=i;
        while(j>=0 && k<n)
        {
            if(s[j]!=s[k+k-j]) break;
            if(k-j+k-j+1>max_len)
            {
                max_len = k-j+k-j+1;
                sub_string = &s[j];
            }
            j--;

        }
    }
    *(sub_string+max_len) = '\0';
    return sub_string;
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    char s[] = "ccc";
    char *ret;
    ret = longestPalindrome(s);

    printf("%s\n",ret);
    printf("\nHello, World!\n");
    return 0;
}
