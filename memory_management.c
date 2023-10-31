#include <stdio.h>
#include <stdlib.h>

void functionAddTwo(int number);
int functionAddThree(int number);

int global1;
int global2 = 20;
int global3 = 30;

void functionAddOne() {
  int local1;
  local1 = 10;
  printf("address of local1 is : %p\n", &local1);
  functionAddTwo(local1);
}

void functionAddTwo(int number) {
  int local2;
  local2 = 20 + number;
  printf("address of local2 is : %p\n", &local2);
  int result = functionAddThree(local2);
}

int functionAddThree(int number) {
  int local3;
  local3 = 30 + number;
  printf("address of local3 is : %p\n", &local3);
  return local3;
}

// Heap
void functionAllocate() {
  int *value1 = (int *)malloc(5 * sizeof(int));
  int *value2 = (int *)malloc(5 * sizeof(int));
  int *value3 = (int *)malloc(5 * sizeof(int));
  printf("address of pointer -> value1 : %p\n", value1);
  printf("address of pointer -> value2 : %p\n", value2);
  printf("address of pointer -> value3 : %p\n", value3);
  free(value1);
  free(value2);
  free(value3);
}

int add_stack_overflow(int num) {
  num += add_stack_overflow(num);
  return num;
}

void run_to_stack_overflow() {}

int main() {
  printf("///////////////////////////////////////////////\n");
  printf("/////////////////// STACK /////////////////////\n");
  functionAddOne();
  printf("-------------------------------\n");
  // show address global
  printf("//////////////////////////////////////////////\n");
  printf("////////////////// HEAP //////////////////////\n");

  functionAllocate();
  printf("//////////////////////////////////////////////\n");
  printf("------------- GlOBAL ------------------\n");
  printf("address of global1 (not assign value) is : %p\n", &global1);
  printf("address of global2 is : %p\n", &global2);
  printf("address of global3 is : %p\n", &global3);
  printf("---------------------------------------\n");
  printf(" start run add_stack_overflow . . .\n");
  add_stack_overflow(1);
}
