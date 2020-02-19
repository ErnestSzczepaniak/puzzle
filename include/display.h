#ifndef _display_h
#define _display_h

/*
* project:	puzzle
* file:		display.h
* author:	en2
* date:		15-02-2020
*/

void d_open(int size_x, int size_y, const char * name);

void d_color(int r, int g, int b);

void d_pixel(int pos_x, int pos_yb);
void d_line(int start_x, int start_y, int end_x, int end_y);
void d_square(int start_x, int start_y, int size_x, int size_y);
void d_text(int pos_x, int pos_y, const char * text);

char d_input_wait();

void d_clear(int start_x, int start_y, int size_x, int size_y);
void d_flush();

void d_close();

void d_sleep(int ms);

#endif /*define: display_h*/