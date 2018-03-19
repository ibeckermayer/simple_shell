#include "ss_head.h"
/**
 * _itoa - converts int to character
 * Return: the int
 */
char *_itoa(int val, int base){
        
        static char buf[32] = {0};
        
        int i = 30;
        
        for(; val && i ; --i, val /= base)
                buf[i] = "0123456789abcdef"[val % base];
        
        return &buf[i+1];
        
}
