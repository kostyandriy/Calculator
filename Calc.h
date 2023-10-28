#ifndef S_CALC_H
#define S_CALC_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE_STRING 256

typedef enum type_t {
  Number = 1,
  var_x = 2,
  left_bracket = 3,
  right_bracket = 4,
  op_plus = 5,
  op_minus = 6,
  op_mul = 7,
  op_div = 8,
  op_mod = 9,
  op_power = 10,
  f_sin = 11,
  f_cos = 12,
  f_tan = 13,
  f_asin = 14,
  f_acos = 15,
  f_atan = 16,
  f_sqrt = 17,
  f_ln = 18,
  f_log = 19
} my_type;

typedef struct Stack {
  double value;
  int priority;
  my_type type;
  struct Stack *next;
} Stack;

int valid_input(char *input);

void trim_input(char *input, char *result);

int brackets_par(char *input);
int is_bracket(char symbol);
int brackets_valid_in(char *input, int i);
int bracket_after_func(char *input);

int is_operator(char *input, int *i, int offset);
int valid_after_operator(char *input);
int valid_mul(char *input);
int valid_simple_mul(char *input, int i);
int valid_complex_mul(char *input, int *i);

int funcs(char *input, int *i, int offset);
int trigonometry(char *input, int *i, int offset);

int is_dot(char *input, int i);
int is_x(char symbol);
int is_number(char symbol);

void push_node(Stack **head, double value, int priority, my_type type);
void pop_node(Stack **head);
int peek_node(Stack *head);
void remove_node(Stack **head);

int get_priority(my_type type);
int get_type_simple(char symbol);
int get_type_complex(char *input, int *i);

void stack_from_str(Stack **node, char *input);
void simple_symbols(Stack **node, char symbol);
void complex_symbols(Stack **node, char *input, int *i);
void number_symbols(Stack **node, char *input, int *i);
void inverse_stack(Stack **input, Stack **result);

void first_part_notation(Stack **origin, Stack **result, Stack **support,
                         int *k);
void second_part_notation(Stack **origin, Stack **result, Stack **support,
                          int *k);
void notation_stack(Stack **origin, Stack **result, Stack **support);

#endif  // S_CALC_H