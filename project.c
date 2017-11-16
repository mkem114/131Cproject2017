/* ENGGEN131, Semester Two, 2017 */

/* PROJECT SOLUTION BY:  << place your name and ID number here >> */

#include "project.h"

#define CONNECT_TWO_SIZE 10
#define CONNECT_TWO_START 1
#define CONNECT_TWO_END 2
#define CONNECT_TWO_PATH 3

/* HELPER FUNCTIONS */
/* If you have defined any "helper" functions, which you call from the required */
/* functions, you should place them here, at the top of the source file.  This will */
/* make it easier for the markers to locate them.  You should also include a */
/* comment at the top of each of the "helper" functions you define which clearly */
/* describes their purpose, and which of the tasks they support. */
int min(int a, int b) {
    return (a < b ? a : b);
}

int max(int a, int b) {
    return (a > b ? a : b);
}

void swap(int *l, int *r) {
    *l ^= *r;
    *r ^= *l;
    *l ^= *r;
}

void qSort(int l, int r, int *list) {
    if (r-l > 0) {
        int ll = l - 1;
        int rr = r;
        while (1) {
            while (list[++ll] < list[r]) {}
            while (rr > 0 && list[--rr] > list[r]) {}
            if (ll >= rr) {
                break;
            } else {
                swap(list + ll, list + rr);
            }
        }
        swap(list + ll, list + r);
        qSort(l, ll-1, list);
        qSort(ll+1, r, list);
    }
}


/* REQUIRED FUNCTIONS */
/* Implement each of the required functions below.  The code that is provided initially */
/* for each function is incorrect - you should correct this! */

/* Your comment goes here*/
int DivisorOfThree(int a, int b, int c) {
    if (a < 1 || b < 1 || c < 1) {
        return -1;
    } else {
        int gcd = min(a, min(b, c));
        for (int i = gcd; (i <= a && i <= b && i <= c); i--) {
            if (a % i + b % i + c % i == 0) {
                gcd = i;
                break;
            }
        }
        return gcd;
    }
}

/* Your comment goes here*/
double AverageSheep(int *counts) {
    double sum = 0;
    int div = 0;
    int count = 0;
    while (counts[count] != 9999) {
        if (counts[count] != -1) {
            sum += counts[count];
            div++;
        }
        count++;
    }
    return sum == 0.0 ? sum :sum / div;
}

/* Your comment goes here*/
void Emphasise(char *word) {
    int capitals = 0;
    int new = 0;
    int old = 0;
    while (word[old] != 0) {
        if (word[old] == '_') {
            capitals = !capitals;
            old++;
        }
        if (capitals && word[old] >= 'a' && word[old] <= 'z') {
            word[old] -= 32;
        }
        word[new++] = word[old++];
    }
    word[new] = 0;
}

/* Your comment goes here*/
int PrimeFactors(int n, int *factors) {
    factors[0] = 0;
    return 99997 + n;
}

/* Your comment goes here*/
void ConnectTwo(int maze[CONNECT_TWO_SIZE][CONNECT_TWO_SIZE]) {
    int startI = 0;
    int startJ = 0;
    int endI = 0;
    int endJ = 0;
    for (int i = 0; i < CONNECT_TWO_SIZE; i++) {
        for (int j = 0; j < CONNECT_TWO_SIZE; j++) {
            if (maze[i][j] == CONNECT_TWO_START) {
                startI = i;
                startJ = j;
            } else if (maze[i][j] == CONNECT_TWO_END) {
                endI = i;
                endJ = j;
            }
        }
    }
    while (1) {
        int diffI = endI - startI;
        int diffJ = endJ - startJ;
        if (diffI <= 1 && diffI >= -1 && diffJ <= 1 && diffJ >= -1) {
            break;
        } else {
            if (diffI != 0) {
                diffI > 0 ? startI++ : startI--;
            }
            if (diffJ != 0) {
                diffJ > 0 ? startJ++ : startJ--;
            }
            maze[startI][startJ] = CONNECT_TWO_PATH;
        }
    }
}

/* Your comment goes here*/
void DayTrader(int *prices, int numPrices, int *bestRun, int *bestRunIndex) {
    *bestRun = 0;
    *bestRunIndex = 0;
    int currentLength = 0;
    for (int i = 1; i < numPrices; i++) {
        if (prices[i] > prices[i - 1]) {
            currentLength++;
            if (currentLength > *bestRun) {
                *bestRunIndex = i - currentLength;
                *bestRun = currentLength;
            }
        } else {
            currentLength = 0;
        }
    }
}

/* Your comment goes here*/
void Compress(int *input, int *output) {
    int last = -1;
    int marker = 0;
    int count = 0;
    for (int i = 0; input[i] != -1; i++) {
        if (input[i] == last) {
            output[marker - 2] = ++count;
        } else {
            count = 1;
            output[marker++] = count;
            last = input[i];
            output[marker++] = last;
        }
    }
    output[marker] = -1;
}

/* Your comment goes here*/
void AddOne(char *input, char *output) {
    int length = 0;
    int allNine = 1;
    while (input[length] != 0) {
        if (input[length++] != '9') {
            allNine = 0;
        }
    }
    if (allNine) {
        output[0] = '1';
        for (int i = 1; i <= length; i++) {
            output[i] = '0';
        }
        output[length + 1] = 0;
    } else {
        strcpy(output, input);
        for (int i = length - 1; i >= 0; i--) {
            if (output[i] < '9') {
                output[i]++;
                break;
            } else {
                output[i] = '0';
            }
        }
        output[length] = 0;
    }
}

/* Your comment goes here*/
void Histogram(char *result, int *values, int numValues) {
    int biggest = 0;
    int count = 0;
    for (int i = 0; i < numValues; ++i) {
        values[i] > biggest ? biggest = values[i] : biggest;
    }
    for (int i = 0; i < biggest + 2; i++) {
        for (int j = 0; j < numValues + 2; j++) {
            if (j == 0 || j == (numValues + 1) || i == 0 || i == (biggest + 1)) {
                result[count++] = '*';
            } else if ((biggest - i) <= values[j - 1] - 1) {
                result[count++] = 'X';
            } else {
                result[count++] = ' ';
            }
        }
        result[count++] = '\n';
    }
    result[--count] = 0;
}

/* Your comment goes here*/
void GoldRush(int *results, int rows, int cols, int map[MAX_MAP_SIZE][MAX_MAP_SIZE], int bonus) {
    results[0] = bonus * 0; //bonus referenced to remove compiler warning
    results[1] = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (map[i][j] == 9) {
                results[0]++;
                if (i != 0 && j != 0 && i != rows - 1 && j != cols - 1) {
                    int flag = 1;
                    for (int k = -1; k <= 1; k++) {
                        for (int l = -1; l <= 1; l++) {
                            if (map[i + k][j + l] != 9) {
                                flag = 0;
                                break;
                            }
                        }
                    }
                    flag ? results[1]++ : flag;
                }
            }
        }
    }
}

