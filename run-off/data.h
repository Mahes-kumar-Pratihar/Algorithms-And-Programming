#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9
// Function prototypes
int vote(int voter, int rank, char *name);
void tabulate();
int print_winner(void);
int find_min(void);
int is_tie(int min);
void eliminate(int min);

// preferences[i][j] is jth preference for voter i
int preferences[9][3];

// Candidates have name, vote count, eliminated status
typedef struct
{
    char name[20];
    int votes;
    int eliminated;
}
candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count;
int candidate_count;

