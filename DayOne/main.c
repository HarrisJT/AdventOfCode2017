#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INPUT "../../_inputs/day1.txt"

int CaptchaPart1(const char *kDigitSequence);
int CaptchaPart2(const char *kDigitSequence);

int main() {
  FILE *file = fopen(INPUT, "r");
  char *line = NULL;
  size_t length = 0;

  while (getline(&line, &length, file) != -1) {
    line[strcspn(line, "\r\n")] = 0;
    printf("Answer for Part 1: %d\nAnswer for Part 2: %d",
           CaptchaPart1(line), CaptchaPart2(line));
  }

  fclose(file);
  free(line);
  exit(EXIT_SUCCESS);
}

int CaptchaPart1(const char *kDigitSequence) {
  const size_t kLengthOfInteger = strlen(kDigitSequence);
  int search = 0;
  int solution = 0;
  for (int i = 0; i < kLengthOfInteger; i++) {
    int current_digit = kDigitSequence[i] - '0';

    if (current_digit < 0 || current_digit > 9) {
      search = 0;
      continue;
    }

    if (current_digit == search) {
      solution += current_digit;
    }

    search = current_digit;
  }

  if (kDigitSequence[0] - '0' == search) {
    solution += search;
  }

  return solution;
}

int CaptchaPart2(const char *kDigitSequence) {
  const size_t kLengthOfInteger = strlen(kDigitSequence);
  int solution = 0;
  const int kHalfLength = (int) (kLengthOfInteger / 2);
  for (int i = 0; i < kLengthOfInteger; i++) {
    int index_of_search = kHalfLength + i;
    int current_digit = kDigitSequence[i] - '0';

    if (index_of_search > kLengthOfInteger - 1) {
      index_of_search = i - kHalfLength;
    }

    if (current_digit == kDigitSequence[index_of_search] - '0') {
      solution += current_digit;
    }

  }

  return solution;
}