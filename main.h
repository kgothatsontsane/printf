#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* FLAGS */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* SIZES */
#define S_LONG 2
#define S_SHORT 1

/**
 * struct fmt - Struct operator
 *
 * @format: The format data member.
 * @fn: The function associated.
 */
struct fmt
{
	char format;
	int (*fn)(va_list, char[], int, int, int, int);
};

/**
 * typedef struct fmt fmt_t - Struct operator
 * @fmt: The format struct
 * @fm_t: The format type.
 */
typedef struct fmt fmt_t;

int _printf(const char *format, ...);
void print_to_buffer(char buffer[], int *buffer_index);
int print_handler(const char *format, int *index, va_list a_list, char buf[],
		  int flgs, int wd, int prec, int sz);

/* print chars and strings */
int print_char(va_list arguments, char output_buffer[],
			   int format_flags, int output_width,
			   int precision_spec, int spec_size);
int print_string(va_list arguments, char output_buffer[],
				 int format_flags, int output_width,
				 int precision_spec, int spec_size);
int print_percent(va_list arguments, char output_buffer[],
				  int format_flags, int output_width,
				  int precision_spec, int spec_size);

/* print numbers */
int print_int(va_list arguments, char output_buffer[],
			  int format_flags, int output_width,
			  int precision_spec, int spec_size);
int print_binary(va_list arguments, char output_buffer[],
				 int format_flags, int output_width,
				 int precision_spec, int spec_size);

int print_unsigned(va_list arguments, char output_buffer[], int format_flags,
		   int output_width, int precision_spec, int spec_size);

int print_octal(va_list arguments, char output_buffer[], int format_flags,
		int output_width, int precision_spec, int spec_size);

int print_hexadecimal(va_list arguments, char output_buffer[],
		      int format_flags, int output_width,
		      int precision_spec, int spec_size);

int print_hex_upper(va_list arguments, char output_buffer[], int format_flags,
		     int output_width, int precision_spec, int spec_size);

int print_hex_up_low(va_list arguments, char map_to[], char output_buffer[],
	       int format_flags, char flag_ch, int output_width,
	       int precision_spec, int spec_size);

/* print memory address */
int print_pointer(va_list arguments, char output_buffer[], int format_flags,
		  int output_width, int precision_spec, int spec_size);

/* print non printable characters */
int print_non_printable(va_list arguments, char output_buffer[],
			int format_flags, int output_width,
			int precision_spec, int spec_size);

/* print string in reverse*/
int print_reverse(va_list arguments, char output_buffer[], int format_flags,
		  int output_width, int precision_spec, int spec_size);

/* print a string in rot 13*/
int print_rot13string(va_list arguments, char output_buffer[],
		      int format_flags, int output_width,
		      int precision_spec, int spec_size);

/* specifier handlers */
int retrieve_flags(const char *formatted_string, int *index);
int extract_width(const char *formatted_string, int *index, va_list a_ist);
int detect_size(const char *formatted_string, int *index);
int determine_precision(const char *formatted_string,
			int *index, va_list a_list);

/* width handlers */
int write_char_to_buffer(char c, char buffer[], int flags,
		      int w, int prec, int sz);

int write_number_to_buffer(int negative, int index, char buf[],
		 int flgs, int w, int prec, int sz);

int write_num_to_buffer(int index, char buf[], int flgs, int w, int prec,
	      int len, char padding, char extrac);

int  write_pointer_to_buffer(char buf[], int index, int len, int w, int flgs,
		  char padding, char extrac, int padstart);

int write_unsigned_to_buffer(int negative, int index, char buf[],
		 int flgs, int w, int prec, int sz);

/* append hexadecimal to buffer*/
int append_hex_to_buffer(char, char[], int);

/* checkers**/
int digit(char);
int printable(char);

/* cast converters*/
long int cast_size_number(long int number, int c_size);
unsigned long int cast_size_unsigned(unsigned long int number, int c_size);

#endif /* MAIN_H */
