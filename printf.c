#include<stdio.h>
#include<stdarg.h>
#include "main.h"

/**
 * printf - printf function
 * @*transverse: const char pointer
 * @*s: const char
 * @i: 
 * return: length
 */


int _printf(const char* format,...) 
{ 
    char *traverse; 
    unsigned int i; 
    char *s; 

    //Module 1: Initializing _printf's arguments 
    va_list arg; 
    va_start(arg, format); 

    for(traverse = format; *traverse != '\0'; traverse++) 
    { 
        while( *traverse != '%' ) 
        { 
            putchar(*traverse);
            traverse++; 
        } 

        traverse++; 

        //Module 2: Fetching and executing arguments
        switch(*traverse)
        {
            case 'c' : i = va_arg(arg,int);//Fetch char argument
                        _putchar(i);
                        break;
            case 'd' : i = va_arg(arg,int);//Fetch Dec/Int argument
                        if(i<0) 
                        { 
                            i = -i;
                            _putchar('-'); 
                        } 
                        _puts(convert(i,10));
                        break; 
            case 'o': i = va_arg(arg,unsigned int);//Fetch Octal
                        _puts(convert(i,8));
                        break;
            case 's': s = va_arg(arg,char *);//Fetch string
                        _puts(s);
                        break;
            case 'x': i = va_arg(arg,unsigned int);//Fetch Hex
                        _puts(convert(i,16));
                        break;
        }
    }

    //Module 3: Closing argument list to necessary clean-up
    va_end(arg); 
}
