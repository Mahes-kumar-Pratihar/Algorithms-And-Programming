#include "data.h"
// Record preference if vote is valid
int vote(int voter, int rank, char* name)
{
    // TODO
    for(int i = 0; i < candidate_count; i++){
        if(strcmp(candidates[i].name, name) == 0){
            preferences[voter][i] = rank;
            return 1;
        }
    }
    return 0;
}

// Tabulate votes for non-eliminated candidates
void tabulate()
{
    // TODO
    int i, j, k;
    for(i = 0; i < candidate_count; i++){
        if(candidates[i].eliminated){
            for(j = 0; j < voter_count; j++){
                for(k = 0; k < candidate_count; k++){
                    if((1 + preferences[j][i] == preferences[j][k]) && k != i){
                        preferences[j][k] = preferences[j][i];
                        preferences[j][i] = 1000;
                    }
                }
            }
        }
        for(j = 0; j < candidate_count; j++){
           for(i = 0; i < voter_count; i++){
              if(preferences[i][j] == 0){
                 candidates[j].votes++;
              }
          }
       }
    }
    return;
}

// Print the winner of the election, if there is one
int print_winner(void)
{
    // TODO
    int i;
    for(i = 0; i < candidate_count; i++){
        if(candidates[i].votes >= (int)ceil((double)voter_count/2)){
            printf("The winner is -> %s", candidates[i].name);
            return 1;
        }
    }
    return 0;
}

// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    // TODO
    int i, min = 10000;
    for(i = 0; i < candidate_count; i++){
        if(candidates[i].votes < min && !candidates[i].eliminated){
            min = candidates[i].votes;
        }
    }
    return min;
}

// Return true if the election is tied between all candidates, false otherwise
int is_tie(int min)
{
    // TODO
    int i;
    for(i = 0; i < candidate_count; i++){
        if(candidates[i].votes != min && !candidates[i].eliminated){
            return 0;
        }
    }
    return 1;
}

// Eliminate the candidate (or candidiates) in last place
void eliminate(int min)
{
    // TODO
    for(int i = 0; i < candidate_count; i++){
        if(candidates[i].votes == min){
            candidates[i].eliminated = 1;
        }
    }
    return;
}


