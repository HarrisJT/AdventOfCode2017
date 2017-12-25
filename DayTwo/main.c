#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define ADVENTOFCODE_INPUTS_DAY2_TXT_ "../../_inputs/day2.txt"
int FindChecksumOfLine(const int numbers[16]);
int FindDivisibleNumbersResult(const int numbers[16]);

int main() {
  char *line = NULL;
  size_t length = 0;
  FILE *file = fopen(ADVENTOFCODE_INPUTS_DAY2_TXT_, "r");
  if (file == NULL) {
    perror(ADVENTOFCODE_INPUTS_DAY2_TXT_);
    exit(1);
  }

  int checksum = 0;
  int calculation = 0;

  while (getline(&line, &length, file) != -1) {
    line[strcspn(line, "\r\n")] = 0;

    int numbers[16];
    int i = 0;
    char *p = strtok(line, "\t");

    while (p != NULL) {
      numbers[i++] = atoi(p);
      p = strtok(NULL, "\t");
    }

    checksum += FindChecksumOfLine(numbers);
    calculation += FindDivisibleNumbersResult(numbers);
  }

  printf("%d\n", checksum);
  printf("%d\n", calculation);

  return 0;
}

int FindChecksumOfLine(const int numbers[16]) {
  int smallest = INT_MAX;
  int largest = INT_MIN;

  for (int i = 0; i < 16; i++) {
    if (numbers[i] < smallest) {
      smallest = numbers[i];
    }
    if (numbers[i] > largest) {
      largest = numbers[i];
    }
  }

  return largest - smallest;
}

int FindDivisibleNumbersResult(const int numbers[16]) {
  int result, divisible;
  for (int i = 0; i < 16; i++) {
    int divisor1 = numbers[i];
    for (int j = 1; j < 16; j++) {
      int divisor2 = numbers[j];
      if (divisor1 == divisor2) {
        continue;
      } else if (divisor1 > divisor2) {
        divisible = divisor1 % divisor2;
        result = divisor1 / divisor2;
      } else {
        divisible = divisor2 % divisor1;
        result = divisor2 / divisor1;
      }

      if (divisible == 0) {
        return result;
      }
    }
  }
}