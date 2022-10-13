#include <stdio.h>
#include <locale.h>

int main(void)
{
	setlocale(LC_ALL, "Rus");
	summ(2, 3);
	summC(2, 3);
	min(5, 2);
	mul(4, 6);
	div(120, 5);
	ost(12, 5);
	sravnC(2, 5);
	CompareThree(3, 2, 5);
	return 0;
}

int summ(int a, int b) 
{
	int c;
	__asm
	{
		mov eax, a
		mov ebx, b
		add eax, ebx
		mov c, eax
	}
	printf("Сумма: %d\n", c);
}

int summC(int a, int b)
{
	int c = a + b;
	return c;
}

int min(int a, int b)
{
	int c;
	__asm 
	{
		mov eax, a
		mov ebx, b
		sub eax, ebx
		mov c, eax
	}
	printf("Разность: %d\n", c);
}

int minC(int a, int b) 
{
	int c = a - b;
	return c;
}

int mul(int a, int b)
{
	int c;
	__asm
	{
		mov eax, a
		mov ebx, b
		mul ebx //второй множитель
		mov c, eax
	}
	printf("Умножение: %d\n", c);
}

int mulC(int a, int b)
{
	int c = a * b;
	return c;
}

int div(int a, int b)
{
	int c;
	__asm
	{
		mov eax, a
		mov ecx, b
		mov edx, 0
		div ecx
		mov c, eax
	}
	printf("Деление: %d\n", c);
	return c;
}

int divC(int a, int b)
{
	int c = a / b;
	return c;
}

int ost(int a, int b)
{
	int c;
	__asm
	{
		mov eax, a
		mov ecx, b
		mov edx, 0
		div ecx
		mov c, edx //остаток от деления
	}
	printf("Остаток от деления: %d\n", c);
	return c;
}

int CompareTwo(int a, int b)
{
	_asm
	{
		mov eax, a
		mov ebx, b
		cmp eax, ebx
		je equal
		jg greater
		jmp less


		equal :
		mov a, 0
			jmp exit

			greater :
		mov a, 1
			jmp exit

			less :
		mov a, 2
			jmp exit

			exit :
	}
	printf("Ответ2: %d\n", a);
	return a;
}

int sravnC(int a, int b)
{
	int c;
	if (a > b) 
	{
		c = 1;
	}
	else if (a < b)
	{
		c = 2;
	}
	else if (a = b)
	{
		c = 0;
	}
	printf("Ответ2: %d\n", c);
	return c;
}

int CompareThree(int a, int b, int c)
{
	_asm
	{
		mov eax, a
		mov ebx, b
		mov ecx, c
		cmp eax, ebx
		je equal
		jg greater
		jmp less


		equal :
		cmp eax, ecx
			je equal2
			jg greater2
			jmp less2

			greater :
		cmp eax, ecx
			je equal2
			jg greater2
			jmp less2

			less :
		cmp ebx, ecx
			je equal2
			jg greater3
			jmp less2



		equal2:
		mov a, 0
			jmp exit

			greater2 :
		mov a, 1
			jmp exit

			less2 :
		mov a, 3
			jmp exit

			greater3 :
		mov a, 2
			jmp exit

			exit :
	}
	printf("Ответ3: %d\n", a);
	return a;
}

int sravnC3(int a, int b, int c)
{
	int d;
	if (a > b > c)
	{
		d = 1;
	}
	else if (a < b > c)
	{
		d = 2;
	}
	else if (a < b < c) 
	{
		d = 3;
	}
	else if (a = b = c)
	{
		d = 0;
	}
	printf("Ответ: %d\n", d);
	return d;
}


