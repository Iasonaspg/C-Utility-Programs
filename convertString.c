#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
 
int main(void)
{
    char str[] = "78";
    char* endptr;
    char* str1 = (char*)malloc(20*sizeof(*str1));
    str1 = "867";

    printf("%ld\n", strtoimax(" -123junk",&endptr,10)); /* base 10                    */
    printf("%ld\n", strtoimax(str1,&endptr,10)); /* base 10                    */
    printf("%ld\n", strtoimax("11111111",&endptr,2));   /* base 2                     */
    printf("%ld\n", strtoimax(str,&endptr,10));       /* base 36                    */
    printf("%ld\n", strtoimax("010",&endptr,0));        /* octal auto-detection       */
    printf("%ld\n", strtoimax("10",&endptr,0));         /* decimal auto-detection     */
    printf("%ld\n", strtoimax("0x10",&endptr,0));       /* hexadecimal auto-detection */
  
    return 0;
}