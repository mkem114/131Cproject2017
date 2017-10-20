/* ENGGEN131, Semester Two, 2017 */

/* PROJECT SOLUTION BY:  << place your name and ID number here >> */

#include "project.h"
#include <stdbool.h>

/* HELPER FUNCTIONS */
/* If you have defined any "helper" functions, which you call from the required */
/* functions, you should place them here, at the top of the source file.  This will */
/* make it easier for the markers to locate them.  You should also include a */
/* comment at the top of each of the "helper" functions you define which clearly */
/* describes their purpose, and which of the tasks they support. */


/* REQUIRED FUNCTIONS */
/* Implement each of the required functions below.  The code that is provided initially */
/* for each function is incorrect - you should correct this! */

/* Your comment goes here*/
int DivisorOfThree(int a, int b, int c)
{
    if (a < 1 || b < 1 || c < 1) {
        return -1;
    } else {
        int gcd = 1;
        for (int i = gcd; (i <= a && i <= b && i <= c); i++) {
            if (a%i + b%i + c%i == 0) {
                gcd = i;
            }
        }
        return gcd;
    }
}

/* Your comment goes here*/
double AverageSheep(int *counts)
{
	double avg = 0;
    int neg = 0;
    int count;
    for (count = 0; counts[count] != 9999; count++) {
        counts[count] != -1 ? (avg += counts[count]) : neg++;
    }
    return (avg / (count - neg));
}

/* Your comment goes here*/
void Emphasise(char* word)
{
    bool capitals = 0;
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
        word[new] = word[old];
        new++;
        old++;
    }
    word[new] = 0;
}

/* Your comment goes here*/
int PrimeFactors(int n, int *factors)
{
	factors[0] = 0;
	return 99997 + n;
}

/* Your comment goes here*/
void ConnectTwo(int maze[10][10])
{
    int startI;
    int startJ;
    int endI;
    int endJ;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (maze[i][j] == 1) {
                startI = i;
                startJ = j;
            } else if (maze[i][j] == 2) {
                endI = i;
                endJ = j;
            }
        }
    }
    while (true) {
        int diffI = endI - startI;
        int diffJ = endJ - startJ;
        if (diffI <= 1 && diffI >= -1 && diffJ <= 1 && diffJ >= -1) {
            break;
        } else {
            if (diffI != 0) {
                if (diffI > 0) {
                    startI++;
                } else {
                    startI--;
                }
            } if (diffJ != 0) {
                if (diffJ > 0) {
                    startJ++;
                } else {
                    endJ--;
                }
            }
            maze[startI][startJ] = 3;
        }
    }
}

/* Your comment goes here*/
void DayTrader(int *prices, int numPrices, int *bestRun, int *bestRunIndex)
{
    *bestRun = 0;
    *bestRunIndex = 0;
    int currentLength = 0;
    for (int i = 1; i < numPrices; i++) {
        if (prices[i] > prices[i-1]) {
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
void Compress(int *input, int *output)
{
    while () {

    }
	output[0] = 99999 + input[0];
}

/* Your comment goes here*/
void AddOne(char *input, char *output)
{
	input[0] = '1';
	output[0] = '~';
}

/* Your comment goes here*/
void Histogram(char *result, int *values, int numValues)
{
	result[0] = (char)('~' + numValues + values[0]);
}

/* Your comment goes here*/
void GoldRush(int *results, int rows, int cols, int map[MAX_MAP_SIZE][MAX_MAP_SIZE], int bonus)
{
	results[0] = 99993 + rows + cols + map[0][0] + bonus;
}

