# ft_printf with bonus

## Contributors
<a href="https://github.com/veggie-garden/ft_printf_bonus/graphs/contributors">
  <img src="https://contrib.rocks/image?repo=veggie-garden/ft_printf_bonus" />
</a>

## Introduction
42서울 이너서클 스터디 저장소 (22.July.29 ~ )

## 1. Description
### What is [printf](https://man7.org/linux/man-pages/man3/printf.3.html)?
`printf()` is a function writes output to stdout, the standatd output stream. 

Upon successful return, function return the number of characters printed (excluding the null byte used to end output to strings). If an error occured, a negative value is returned.

`printf()`란 결과물을 표준 출력으로 츨력하는 함수입니다. 함수 실행에 성공했을 경우, 출력한 결과물의 길이를 반환하고 실패했을 경우 음수를 반환합니다. 

## 2. Implementation
```int	ft_print(const char *, ...)```

### Syntax
__`printf()`__  
```%[$][flags][width][.precision][length modifier]conversion```

__`ft_printf()`__  
```%[flags][width][.precision]conversion```

> **__NOTE:__**  `ft_printf()` do not implement the buffer management of the original printf(). It only handles `cspdiuxX%` conversions.

### Flags
|flag|%c|%s|%p|%d|%i|%u|%x|%X|%%|
|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
|width		|O|O|O|O|O|O|O|O|X|
|precision	|X|O|O|O|O|O|O|O|X|
|-			|O|O|O|O|O|O|O|O|X|
|0			|X|X|X|O|O|O|O|O|X|
|#			|X|X|X|X|X|X|O|O|X|
|space		|X|X|X|O|O|X|X|X|X|
|+			|X|X|X|O|O|X|X|X|X|

__Width > Precision__  
- `d`, `i`, `u`, `x`, `X`  
	- `precision`은 무시되고, `width`만큼 칸에 채워넣고 남은 칸에는 공백이 채워진다.
```
#include <stdio.h>

int main(void)
{
	printf("%3.d\n", 10);  // ' 10'
	printf("%3.i\n", 10);  // ' 10'
	printf("%3.u\n", 10);  // ' 10'
	printf("%3.x\n", 10);  // '  a'
	printf("%3.X\n", 10);  // '  A'
	printf("%#3.x\n", 10); // '0xa'
	printf("%#3.X\n", 10); // '0XA'
}
```

__Width < Precision__
- `d`, `i`, `u`, `x`, `X`
	- `width`는 무시되고, `precision`만큼 칸에 채워넣고 남은 칸에는 `0`이 채워진다.
```
#include <stdio.h>

int main(void)
{
	printf("%2.3d\n", 10);  // 010 
	printf("%2.3i\n", 10);  // 010 
	printf("%2.3u\n", 10);  // 010 
	printf("%2.3x\n", 10);  // 00a
	printf("%2.3x\n", 10);  // 00a
	printf("%#2.3X\n", 10); // 0x00A
	printf("%#2.3X\n", 10); // 0x00A
}
```
- `c`, `s`, `p`
	- `s`만 작동한다. `c`, `p` 모두 `.` 단독으로만 사용이 가능하다.
```
#include <stdio.h>

int main(void)
{
	printf("%4.3c", 'a'); // compile error
	printf("%4.3s", "Hello"); // " hel"
	printf("%4.3p", "a"); // compile error
}
```

__Width < length && Precision > length || width > length && precision < length__
- `d`, `i`, `u`, `x`, `X`
	- `precision`이든 `width`든 큰 수만큼 찍힌다. `width`가 크면 공백이, `precision`이 크면 `0`이 찍힌다.
```
#include <stdio.h>

int main(void)
{
	printf("%1.4d\n", 10); //  '10'
	printf("%1.4i\n", 10); //  '10'
	printf("%1.4u\n", 10); //  '10'
	printf("%#1.4x\n", 10); // '0xa'
	printf("%#1.4X\n", 10); // '0XA'
}
```
- 

__Precision만 있는 경우__
- `s`, `c`, `p`
	- `.` == `.0`이에서 `s`는 출력 안됨
	- `c`는 precision 뒤에 숫자 붙이면 에러남
	- `p`는 상관없음
```
#include <stdio.h>

int main(void)
{
	printf("%.s\n", "a"); // ''
	printf("%.c\n", 'a'); // 'a'
	printf("%.p\n", "a"); // '0x10c49cfa4'
}
```