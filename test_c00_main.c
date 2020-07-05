#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#define TESTCOUNT (9)

void ft_putchar(char c);
void ft_print_alphabet(void);
void ft_print_reverse_alphabet(void);
void ft_print_numbers(void);
void ft_is_negative(int n);
void ft_print_comb(void);
void ft_print_comb2(void);
void ft_putnbr(int nb);
void ft_print_combn(int n);

// ex05
// $>./a.out | cat -e
// 012, 013, 014, 015, 016, 017, 018, 019, 023, ..., 789$>

// ex06
// $>./a.out | cat -e
// 00 01, 00 02, 00 03, 00 04, 00 05, ..., 00 99, 01 02, ..., 97 99, 98 99$>

// ex07
// ft_putnbr(42) displays "42".

// ex08
// $>./a.out | cat -e
// 01, 02, 03, ..., 09, 12, ..., 79, 89$>


void printmsg(const char *msg, ...)
{
	char *newstr = (char*)malloc(strlen(msg) + 2);
	strcpy(newstr, msg);
	strcat(newstr, "\n");

    va_list args;
    va_start(args, msg);
    vprintf(newstr, args);
    va_end(args);
	// printf("%s\n", msg);
	free(newstr);
}

void printline()
{
	printf("\n------------------------------------------------------------\n");
}

void print_testing(const char* code)
{
	printmsg("\n## testing code :");
	printf("%s", code);
}

void test_ex00() {
	ft_putchar(67);
	ft_putchar('a');
	ft_putchar('9');
}
void test_ex01() {
	ft_print_alphabet();

}
void test_ex02() {
	ft_print_reverse_alphabet();
}
void test_ex03() {
	ft_print_numbers();
}
void test_ex04() {
	ft_is_negative(457);
	ft_is_negative(-132);
	ft_is_negative(0);
	ft_is_negative(-2147483648);
	ft_is_negative(2147483647);
}
void test_ex05() {
	ft_print_comb();
}
void test_ex06() {
	ft_print_comb2();
}
void test_ex07() {
	ft_putnbr(24);
	ft_putnbr(-42);
	ft_putnbr(0);
	ft_putnbr(-2147483648);
	ft_putnbr(2147483647);

}
void test_ex08() {
	ft_print_combn(1);
	ft_print_combn(4);
	ft_print_combn(9);
}
int main(void)
{
	void (*tests[TESTCOUNT])(void);
	tests[0] = test_ex00;
	tests[1] = test_ex01;
	tests[2] = test_ex02;
	tests[3] = test_ex03;
	tests[4] = test_ex04;
	tests[5] = test_ex05;
	tests[6] = test_ex06;
	tests[7] = test_ex07;
	tests[8] = test_ex08;
	const char* testing_code[TESTCOUNT][1000];

	strcpy((char*)testing_code[0],
		"ft_putchar(67);\n"
		"ft_putchar('a');\n"
		"ft_putchar('9');\n");
	strcpy((char*)testing_code[1],
		"ft_print_alphabet();\n"
	);
	strcpy((char*)testing_code[2],
		"ft_print_reverse_alphabet();\n"
	);
	strcpy((char*)testing_code[3],
		"ft_print_numbers();\n"
	);
	strcpy((char*)testing_code[4],
		"ft_is_negative(457);\n"
		"ft_is_negative(-132);\n"
		"ft_is_negative(0);\n"
		"ft_is_negative(-2147483648);\n"
		"ft_is_negative(2147483647);\n"
	);
	strcpy((char*)testing_code[5],
		"ft_print_comb();\n"
	);
	strcpy((char*)testing_code[6],
		"ft_print_comb2();\n"
	);
	strcpy((char*)testing_code[7],
		"ft_putnbr(24);\n"
		"ft_putnbr(-42);\n"
		"ft_putnbr(0);\n"
		"ft_putnbr(-2147483648);\n"
		"ft_putnbr(2147483647);\n"
	);
	strcpy((char*)testing_code[8],
		"ft_print_combn(1);\n"
		"ft_print_combn(4);\n"
		"ft_print_combn(9);\n"
	);

	// do test!

	for(int i=0;i<TESTCOUNT;i++) {
		printline();
		printmsg("## testing ex%02d", i);
		print_testing((char*)testing_code[i]);
		printmsg("\n## tesing result:");
		tests[i]();
		printmsg("$>\n");
	}

	return (0);
}
