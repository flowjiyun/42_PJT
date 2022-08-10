#include <stdio.h>
#include <limits.h>
#include "./ft_printf/include/ft_printf.h"

int main(void)
{
/*
	printf("==============c============\n");
	char c = 'a';
	char d = 'b';

	printf(" original: %d\n", printf("%c", c));
	printf(" ft: %d\n", ft_printf("%c", c));

	printf(" original: %d\n", printf("%-5c", c));
	printf(" ft: %d\n", ft_printf("%-5c", c));

	printf(" original: %d\n", printf("%5c", c));
	printf(" ft: %d\n", ft_printf("%5c", c));

	printf("======================s==================\n");
	char *str = "Hello";
	// char *str = NULL;
	printf(" original: %d\n", printf("%s", str));
	printf(" ft: %d\n", ft_printf("%s", str));

	printf(" original: %d\n", printf("%.7s ", str));
	printf(" ft: %d\n", ft_printf("%.7s ", str));

	printf(" original: %d\n", printf("%-10.7s ", str));
	printf(" ft: %d\n", ft_printf("%-10.7s ", str));

	printf(" original: %d\n", printf("%3.2s ", str));
	printf(" ft: %d\n", ft_printf("%3.2s ", str));

	printf(" original: %d\n", printf("%5.7s ", str));
	printf(" ft: %d\n", ft_printf("%5.7s ", str));

	printf(" original: %d\n", printf("%3.7s ", str));
	printf(" ft: %d\n", ft_printf("%3.7s ", str));

	printf("=====================d=========================\n");
	int a = 123;
	int b = -123;
	
	printf(" ft: %d\n", ft_printf("%d", a));

	printf("---------%%3.7d---------\n");
	printf(" original: %d\n", printf("%3.7d", a));
	printf(" ft: %d\n", ft_printf("%3.7d", a));
	printf(" original: %d\n", printf("%3.7d", b));
	printf(" ft: %d\n", ft_printf("%3.7d", b));

	printf("------------%%7.3d-------\n");
	printf(" original: %d\n", printf("%7.3d", a));
	printf(" ft: %d\n", ft_printf("%7.3d", a));
	printf(" original: %d\n", printf("%7.3d", b));
	printf(" ft: %d\n", ft_printf("%7.3d", b));

	printf("------------%% 3.7d-------\n");
	printf(" original: %d\n", printf("% 3.7d", a));
	printf(" ft: %d\n", ft_printf("% 3.7d", a));
	printf(" original: %d\n", printf("% 3.7d", b));
	printf(" ft: %d\n", ft_printf("% 3.7d", b));

	printf("------------%% 7.3d-------\n");
	printf(" original: %d\n", printf("% 7.3d", a));
	printf(" ft: %d\n", ft_printf("% 7.3d", a));
	printf(" original: %d\n", printf("% 7.3d", b));
	printf(" ft: %d\n", ft_printf("% 7.3d", b));

	printf("-----------%%03.7d---------\n");
	printf(" original: %d\n", printf("%03.7d", a));
	printf(" ft: %d\n", ft_printf("%03.7d", a));
	printf(" original: %d\n", printf("%03.7d", b));
	printf(" ft: %d\n", ft_printf("%03.7d", b));

	printf("-----------%%07.3d---------\n");
	printf(" original: %d\n", printf("%07.3d", a));
	printf(" ft: %d\n", ft_printf("%07.3d", a));
	printf(" original: %d\n", printf("%07.3d", b));
	printf(" ft: %d\n", ft_printf("%07.3d", b));

	printf("-----------%%-3.7d---------\n");
	printf(" original: %d\n", printf("%-3.7d", a));
	printf(" ft: %d\n", ft_printf("%-3.7d", a));
	printf(" original: %d\n", printf("%-3.7d", b));
	printf(" ft: %d\n", ft_printf("%-3.7d", b));

	printf("----------%%-7.3d----------\n");
	printf(" original: %d\n", printf("%-7.3d", a));
	printf(" ft: %d\n", ft_printf("%-7.3d", a));
	printf(" original: %d\n", printf("%-7.3d", b));
	printf(" ft: %d\n", ft_printf("%-7.3d", b));
	
	printf("-----------%%+3.7d---------\n");
	printf(" original: %d\n", printf("%+3.7d", a));
	printf(" ft: %d\n", ft_printf("%+3.7d", a));
	printf(" original: %d\n", printf("%+3.7d", b));
	printf(" ft: %d\n", ft_printf("%+3.7d", b));
	
	printf("-----------%%+7.3d---------\n");
	printf(" original: %d\n", printf("%+7.3d", a));
	printf(" ft: %d\n", ft_printf("%+7.3d", a));
	printf(" original: %d\n", printf("%+7.3d", b));
	printf(" ft: %d\n", ft_printf("%+7.3d", b));

	printf("-----------%%-+3.7d---------\n");
	printf(" original: %d\n", printf("%-+3.7d", a));
	printf(" ft: %d\n", ft_printf("%-+3.7d", a));
	printf(" original: %d\n", printf("%-+3.7d", b));
	printf(" ft: %d\n", ft_printf("%-+3.7d", b));

	printf("-----------%%-+7.3d---------\n");
	printf(" original: %d\n", printf("%-+7.3d", a));
	printf(" ft: %d\n", ft_printf("%-+7.3d", a));
	printf(" original: %d\n", printf("%-+7.3d", b));
	printf(" ft: %d\n", ft_printf("%-+7.3d", b));

	printf("-----------%%- 3.7d---------\n");
	printf(" original: %d\n", printf("%- 3.7d", a));
	printf(" ft: %d\n", ft_printf("%- 3.7d", a));
	printf(" original: %d\n", printf("%- 3.7d", b));
	printf(" ft: %d\n", ft_printf("%- 3.7d", b));

	printf("-----------%%- 7.3d---------\n");
	printf(" original: %d\n", printf("%- 7.3d", a));
	printf(" ft: %d\n", ft_printf("%- 7.3d", a));
	printf(" original: %d\n", printf("%- 7.3d", b));
	printf(" ft: %d\n", ft_printf("%- 7.3d", b));

	printf(" original: %d\n", printf("%010d", 123));
	printf(" ft: %d\n", ft_printf("%010d", 123));
	printf(" original: %d\n", printf("%010d", 0));
	printf(" ft: %d\n", ft_printf("%010d", 0));
	printf(" original: %d\n", printf("%010d", 10));
	printf(" ft: %d\n", ft_printf("%010d", 10));

	printf("============u=============\n");

	unsigned int ui = 110;

	printf("----------%%u---------\n");
	printf(" original: %d\n", printf("%u", ui));
	printf(" ft: %d\n", ft_printf("%u", ui));

	printf("----------%%-u---------\n");
	printf(" original: %d\n", printf("%-u", ui));
	printf(" ft: %d\n", ft_printf("%-u", ui));
	
	printf("----------%%0u---------\n");
	printf(" original: %d\n", printf("%0u", ui));
	printf(" ft: %d\n", ft_printf("%0u", ui));
	
	printf("----------%%5u---------\n");
	printf(" original: %d\n", printf("%5u", ui));
	printf(" ft: %d\n", ft_printf("%5u", ui));
	
	printf("----------%%.3u---------\n");
	printf(" original: %d\n", printf("%.3u", ui));
	printf(" ft: %d\n", ft_printf("%.3u", ui));

	printf("----------%%5.3u---------\n");
	printf(" original: %d\n", printf("%5.3u", ui));
	printf(" ft: %d\n", ft_printf("%5.3u", ui));

	printf("----------%%3.5u---------\n");
	printf(" original: %d\n", printf("%3.5u", ui));
	printf(" ft: %d\n", ft_printf("%3.5u", ui));
*/
/*
	printf("==================x=============\n");

	int x = 1000000;

	printf("------------%%#010.3x--------------\n");
	printf(" original: %d\n", printf("%#010.3x", x));
	printf(" ft: %d\n", ft_printf("%#010.3x", x));

	printf("------------%%x--------------\n");
	printf(" original: %d\n", printf("%x", x));
	printf(" ft: %d\n", ft_printf("%x", x));

	printf("------------%%.10x--------------\n");
	printf(" original: %d\n", printf("%.10x", x));
	printf(" ft: %d\n", ft_printf("%.10x", x));

	printf("------------%%3x--------------\n");
	printf(" original: %d\n", printf("%3x", x));
	printf(" ft: %d\n", ft_printf("%3x", x));

	printf("------------%%-.10x--------------\n");
	printf(" original: %d\n", printf("%-.10x", x));
	printf(" ft: %d\n", ft_printf("%-.10x", x));
	
	printf("------------%%#3.10x--------------\n");
	printf(" original: %d\n", printf("%#3.10x", x));
	printf(" ft: %d\n", ft_printf("%#3.10x", x));

	printf("------------%%#10.3x--------------\n");
	printf(" original: %d\n", printf("%#10.3x", x));
	printf(" ft: %d\n", ft_printf("%#10.3x", x));

	printf("------------%%#.1x--------------\n");
	printf(" original: %d\n", printf("%#.1x", x));
	printf(" ft: %d\n", ft_printf("%#.1x", x));

	printf("------------%%#.6x--------------\n");
	printf(" original: %d\n", printf("%#.6x", x));
	printf(" ft: %d\n", ft_printf("%#.6x", x));
	
	printf("------------%%10.6x--------------\n");
	printf(" original: %d\n", printf("%10.6x", x));
	printf(" ft: %d\n", ft_printf("%10.6x", x));

	printf("------------%%-#10.6x--------------\n");
	printf(" original: %d\n", printf("%-#10.6X", x));
	printf(" ft: %d\n", ft_printf("%-#10.6X", x));

	printf("------------%%10.10x---------------\n");
	printf(" original: %d\n", printf("%10.10X", x));
	printf(" ft: %d\n", ft_printf("%10.10X", x));

	printf("================p==================\n");

	int pp = 123;

	printf("------------%%-20.p----------------\n");
	printf(" original: %d\n", printf("%-20.p", &pp));
	printf(" ft: %d\n", ft_printf("%-20.p", &pp));

	printf("------------%%20.p----------------\n");
	printf(" original: %d\n", printf("%20.p", &pp));
	printf(" ft: %d\n", ft_printf("%20.p", &pp));
*/

	printf("==============%%==================\n");
	printf(" original: %d\n", printf("%%%20.p%%", "123"));
	printf(" ft: %d\n", ft_printf("%%%20.p%%", "123"));
	printf("==============LONG_MAX, LONG_MIN==================\n");
	printf(" original: %d\n", printf(" %p %p ", (void *)LONG_MAX, (void *)LONG_MIN));
	printf(" ft: %d\n", ft_printf(" %p %p ",(void *)LONG_MAX, (void *)LONG_MIN));

	
	printf("==============%%x negaive integer==================\n");
	printf(" original: %d\n", printf("%x", -42));
	printf(" ft: %d\n", ft_printf("%x", -42));
	printf("==============%%x zero==================\n");
	printf(" original: %d\n", printf("%-1X", 0));
	printf(" ft: %d\n", ft_printf("%-1X", 0));
	printf("==============%%x 04x==================\n");
	printf(" original: %d\n", printf("%04x", 9));
	printf(" ft: %d\n", ft_printf("%04x", 9));
	printf("==============%%x #zero==================\n");
	printf(" original: %d\n", printf("%#5x", 0));
	printf(" ft: %d\n", ft_printf("%#5x", 0));
	printf("==============%% -05%%==================\n");
	printf(" original: %d\n", printf("%-05%"));
	printf(" ft: %d\n", ft_printf("%-05%"));
	printf("==============%%s null%%==================\n");
	printf(" original: %d\n", printf("%23s", NULL));
	printf(" ft: %d\n", ft_printf("%23s", NULL));
	printf("==============%%.s null%%==================\n");
	printf(" original: %d\n", printf("%.s", NULL));
	printf(" ft: %d\n", ft_printf("%.s", NULL));
	printf("==============%%.03s null%%==================\n");
	printf(" original: %d\n", printf("%.03s", NULL));
	printf(" ft: %d\n", ft_printf("%.03s", NULL));
	printf("==============%%8.5i 34%%==================\n");
	printf(" original: %d\n", printf("%8.5i", 34));
	printf(" ft: %d\n", ft_printf("%8.5i", 34));
	printf("==============%%8.5d 34%%==================\n");
	printf(" original: %d\n", printf("%8.5d", -34));
	printf(" ft: %d\n", ft_printf("%8.5d", -34));
	printf("==============%%10.5d -216%%==================\n");
	printf(" original: %d\n", printf("%10.5d",-216));
	printf(" ft: %d\n", ft_printf("%10.5d", -216));
	printf("==============%%1.5d 123%%==================\n");
	printf(" original: %d\n", printf("%1.5d", 123));
	printf(" ft: %d\n", ft_printf("%1.5d", 123));
	printf("==============%% 10.5d 216%%==================\n");
	printf(" original: %d\n", printf("%+10.5d",-216));
	printf(" ft: %d\n", ft_printf("%+10.5d", -216));

	
	printf("==============%% +010d 216%%==================\n");
	printf(" original: %d\n", printf("%+010d",216));
	printf(" ft: %d\n", ft_printf("%+010d",216));
	return (0);
}
