#include "private.h"

void read_file(char *filename);// for reading the file
void binary_generation_r(int BASE, int *sol, int pos, int k, clause_t *clauses, int numClauses);// for generating binary combinations
void filling_clause(int *sol, int numClauses, clause_t *clauses);// filling the clause i.e. the struct clause_t
int check_solution(clause_t *clauses, int numClauses);// checking if all clauses give the result true or false
