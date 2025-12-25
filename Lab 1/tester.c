#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include "student.h"
#include "ref.h"
#define ARRAY_SIZE(array) (sizeof(array) / sizeof(array[0]))

// Unit test functions.

int test_smallest_pos();
int test_sum_modulo();
int test_rotate();
int test_sort();
int test_find_building();
int test_cube_armstrongs();
int test_double_spy();
int test_second_bit();

// Utility functions used by the unit tests.
bool arrays_differ(int arrray1[], int array2[], int length);
char *array_to_string(int array[], int length);
char cwd[500];
int main() {
  int score = 0;
  FILE *ptr;
  printf("/********************************************************************/\n");
  printf("Please ensure there were no errors when you compiled your program\n");
  printf("If you have any make errors then you will receive a straight 0.\n");
  printf("Please ensure there are sufficent comments in your code\n");
  printf("Do not foget to add your name and date in comments on top of your student.c\n");
  printf("/********************************************************************/\n");
  printf("\n\nTesting your code now:\n");
  ptr=fopen("student.c","a+");
  if (getcwd(cwd, sizeof(cwd)) != NULL) {
       fprintf(ptr, "/*CWD %s */\n", cwd);
   } else {
       perror("getcwd() error");
       
   }
   fclose(ptr);
  //1 point
  score += test_smallest_pos();
  // 1 point
  score += test_sum_modulo();
  // 1 point
  score += test_rotate();
  // 1 point
  score += test_sort();
  // 2 point
  score += test_find_building();
  // 2 points
  score += test_cube_armstrongs();
  // 2 points
  score += test_double_spy();
   // 2 points
  score += test_second_bit();


  printf("Total score: %d/%d\n", score, 12);
}




// test for smallest function
int test_smallest_pos() {
  {
    printf("running %s: single-element-array: ", __func__);

    int in[] = {-1234};
    int out = smallest_pos(in, ARRAY_SIZE(in));
    int expected = ref_smallest_pos(in, ARRAY_SIZE(in));

    if (out != expected) {
      printf("failed:\n  got: %d\n  expected: %d\n", out, expected);
      return 0;
    }
    printf("passed\n");
  }
  {
    printf("running %s: regular-array: ", __func__);

    int in[] = {123, 135, -1234, 0, 55};
    int out = smallest_pos(in, ARRAY_SIZE(in));
    int expected = ref_smallest_pos(in, ARRAY_SIZE(in));

    if (out != expected) {
      printf("failed:\n  got: %d\n  expected: %d\n", out, expected);
      return 0;
    }
    printf("passed\n");
  }
  return 1;
}

int test_sum_modulo() {
  {
    printf("running %s: empty-array: ", __func__);

    int in[] = {};
    int out = sum_modulo(in, ARRAY_SIZE(in),3);
    int expected = ref_sum_modulo(in, ARRAY_SIZE(in),3);

    if (out != expected) {
      printf("failed:\n  got: %d\n  expected: %d\n", out, expected);
      return 0;
    }
    printf("passed\n");
  }
  {
    printf("running %s: regular-array: ", __func__);

    int in[] = {-5, 1, 3, 58, 29823};
    int out = sum_modulo(in, ARRAY_SIZE(in),12);
    int expected = ref_sum_modulo(in, ARRAY_SIZE(in),12);

    if (out != expected) {
      printf("failed:\n  got: %d\n  expected: %d\n", out, expected);
      return 0;
    }
    printf("passed\n");
  }
  return 1;
}





int test_rotate() {
  printf("running %s: ", __func__);

  int a = 1, b = 2, c = 3;
  rotate(&a, &b, &c);

  if (a != 3 || b != 1 || c != 2) {
    printf("failed:\n  got: a=%d b=%d c=%d\n  expected: a=3 b=1 c=2\n", a, b, c);
    return 0;
  }

  printf("passed\n");
  return 1;
}

int test_sort() {
  {
    printf("running %s: empty-array: ", __func__);
    int out[]      = {};
    int expected[] = {};

    sort(out, ARRAY_SIZE(out));
    ref_sort(expected, ARRAY_SIZE(expected));

    if (arrays_differ(out, expected, ARRAY_SIZE(out))) {
      char *out_s = array_to_string(out, ARRAY_SIZE(out));
      char *expected_s = array_to_string(expected, ARRAY_SIZE(expected));

      printf("failed:\n  got: %s\n  expected: %s\n", out_s, expected_s);

      free(out_s);
      free(expected_s);
      return 0;
    }
    printf("passed\n");
  }
  {
    printf("running %s: regular-array: ", __func__);
    int out[]      = {8, 2, 2, 3234, 234, 234, 1, 5, -15, 32, 87234};
    int expected[] = {8, 2, 2, 3234, 234, 234, 1, 5, -15, 32, 87234};

    sort(out, ARRAY_SIZE(out));
    ref_sort(expected, ARRAY_SIZE(expected));

    if (arrays_differ(out, expected, ARRAY_SIZE(out))) {
      char *out_s = array_to_string(out, ARRAY_SIZE(out));
      char *expected_s = array_to_string(expected, ARRAY_SIZE(expected));

      printf("failed:\n  got: %s\n  expected: %s\n", out_s, expected_s);

      free(out_s);
      free(expected_s);
      return 0;
    }
    printf("passed\n");
  }
  {
    printf("running %s: sorted-array: ", __func__);
    int out[]      = {-5, -1, 2, 3, 7, 198, 28349};
    int expected[] = {-5, -1, 2, 3, 7, 198, 28349};

    sort(out, ARRAY_SIZE(out));
    ref_sort(expected, ARRAY_SIZE(expected));

    if (arrays_differ(out, expected, ARRAY_SIZE(out))) {
      char *out_s = array_to_string(out, ARRAY_SIZE(out));
      char *expected_s = array_to_string(expected, ARRAY_SIZE(expected));

      printf("failed:\n  got: %s\n  expected: %s\n", out_s, expected_s);

      free(out_s);
      free(expected_s);
      return 0;
    }
    printf("passed\n");
  }
  return 1;
}

int test_find_building() {
{
  printf("running %s: invalid apartment\n ", __func__);

    int in= -33;
    int out = find_building(in);
    int expected = ref_find_building(in);

    if (out != expected) {
      printf("failed:\n  got: %d\n  expected: %d\n", out, expected);
      return 0;
    }
    printf("passed\n");
  }
  
  {
  printf("running %s: valid apartment\n ", __func__);

    int in= 274;
    int out = find_building(in);
    int expected = ref_find_building(in);

    if (out != expected) {
      printf("failed:\n  got: %d\n  expected: %d\n", out, expected);
      return 0;
    }
    printf("passed\n");
  }
  {
  printf("running %s: valid apartment\n ", __func__);

    int in= 0;
    int out = find_building(in);
    int expected = ref_find_building(in);

    if (out != expected) {
      printf("failed:\n  got: %d\n  expected: %d\n", out, expected);
      return 0;
    }
    printf("passed\n");
  }
  {
  printf("running %s: invalid apartment\n ", __func__);

    int in= 300;
    int out = find_building(in);
    int expected = ref_find_building(in);

    if (out != expected) {
      printf("failed:\n  got: %d\n  expected: %d\n", out, expected);
      return 0;
    }
    printf("passed\n");
  }
  return 2;
}

int test_cube_armstrongs() {
  printf("running %s: ", __func__);
  int out[]      = {0, -1, 2, -5, 8, 153, 370, -153, 26, 407};
  int expected[] = {0, -1, 2, -5, 8, 153, 370, -153, 26, 407};

  cube_armstrongs(out, ARRAY_SIZE(out));
  ref_cube_armstrongs(expected, ARRAY_SIZE(expected));

  if (arrays_differ(out, expected, ARRAY_SIZE(out))) {
    char *out_s = array_to_string(out, ARRAY_SIZE(out));
    char *expected_s = array_to_string(expected, ARRAY_SIZE(expected));

    printf("failed:\n  got: %s\n  expected: %s\n", out_s, expected_s);

    free(out_s);
    free(expected_s);
    return 0;
  }

  printf("passed\n");
  return 2;
}


int test_double_spy() {
  printf("running %s: ", __func__);
  int out[]      = {0, 97, -22, -5, 8, 4, 370, -153, 139, 11222};
  int expected[] = {0, 97, -22, -5, 8, 4, 370, -153, 139, 11222};

  double_spy(out, ARRAY_SIZE(out));
  ref_double_spy(expected, ARRAY_SIZE(expected));

  if (arrays_differ(out, expected, ARRAY_SIZE(out))) {
    char *out_s = array_to_string(out, ARRAY_SIZE(out));
    char *expected_s = array_to_string(expected, ARRAY_SIZE(expected));

    printf("failed:\n  got: %s\n  expected: %s\n", out_s, expected_s);

    free(out_s);
    free(expected_s);
    return 0;
  }

  printf("passed\n");
  return 2;
}


int test_second_bit() {
{
  printf("running %s: Test1\n ", __func__);

    int in= 33;
    int out = second_bit(in);
    int expected = ref_second_bit(in);

    if (out != expected) {
      printf("failed:\n  got: %d\n  expected: %d\n", out, expected);
      return 0;
    }
    printf("passed\n");
  }
  
  {
  printf("running %s: Test2\n", __func__);

    int in= 274321;
    int out = second_bit(in);
    int expected = ref_second_bit(in);

    if (out != expected) {
      printf("failed:\n  got: %d\n  expected: %d\n", out, expected);
      return 0;
    }
    printf("passed\n");
  }
  {
  printf("running %s: Test3\n ", __func__);

    int in= 3;
    int out = second_bit(in);
    int expected = ref_second_bit(in);

    if (out != expected) {
      printf("failed:\n  got: %d\n  expected: %d\n", out, expected);
      return 0;
    }
    printf("passed\n");
  }
  
  return 2;
}





bool arrays_differ(int array1[], int array2[], int length) {
  for (int i = 0; i < length; ++i)
    if (array1[i] != array2[i])
      return true;
  return false;
}

char *array_to_string(int array[], int length) {
  char *p = (char *)malloc(length * 10);
  for (int i = 0, n = 0; i < length; ++i) {
    n += sprintf(p + n, "%d ", array[i]);
  }
  return p;
}
