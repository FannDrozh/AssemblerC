#include <stdio.h>
#include <locale.h>

int main(void)
{
	setlocale(LC_ALL, "Rus");
	summ(2, 3);
	summC(2, 3);
	min(5, 2);
	mul(4, 6);
	div(12, 5);
	ost(12, 5);
	sravnC3(3, 2, 5);
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
	printf("�����: %d\n", c);
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
	printf("��������: %d\n", c);
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
		mul ebx //������ ���������
		mov c, eax
	}
	printf("���������: %d\n", c);
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
	printf("�������: %d\n", c);
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
		mov c, edx //������� �� �������
		mov ebx, 0
		m1:
			mov eax, c
			mov ecx, b
			imul eax, 10

			mov edx, 0
			div ecx
			mov c, edx

			add ebx, 1 //i++
			cmp ebx, 3 //��������
		jne m1
	}
	printf("������� �� �������: %d\n", c);
}

int sravn(int a, int b)
{
	int c;
	int d = 1;
	__asm
	{
		mov eax, a
		mov ecx, b
		cmp eax, ecx
		jnz notAdd
			mov c, 1
		notAdd:
			mov c, 0


	}
	printf("�����: %d\n", c);
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
	printf("�����: %d\n", c);
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
	printf("�����: %d\n", d);
}


