#include"common.h"
#include<limits.h>
#include<stdint.h>

# define HIMAGIC 0x8080808080808080L
# define LOMAGIC 0x0101010101010101L

# if ( __WORDSIZE == 64)
size_t	ft_strlen(const char*str)
{
	const char*char_ptr;
	const unsigned long long*longword_ptr;
	unsigned long long longword;
	for(char_ptr=str;((unsigned long long)char_ptr
				& 8)!=0;
			++char_ptr)
		if(*char_ptr=='\0')
			return char_ptr-str;
	longword_ptr=(unsigned long long*)char_ptr;
	for(;;)
	{
		longword=*longword_ptr++;

		if(((longword-LOMAGIC)&HIMAGIC))
		{
			const  char *cp=(const char*)(longword_ptr-1);

			if(!(*cp++) || !(*cp++) || !(*cp++) || !(*cp++))
				return cp-str;
			if(!(*cp++) || !(*cp++) || !(*cp++) || !(*cp++))
				return cp-str;
		}
	}
}
#endif
