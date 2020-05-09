#include "public.h"

driver_t *read_data(char *filename, int lap_number, driver_t *head);
driver_t *find_driver(driver_t *head, int id);
void Top_three(driver_t *head);

int main(int argc, char **argv)
{
    if(argc != 2){
        fprintf(stdout,"Error in command line args!");
        exit(EXIT_FAILURE);
    }
    FILE *fp;

    driver_t *head = NULL, *top;

    char filename[MAX_LENGTH];
    char line[MAX_LENGTH + MAX_LENGTH];

    int lap_number;
    strcpy(filename, argv[1]);
    fp = fopen(filename, "r");

    while(fgets(line, MAX_LENGTH + MAX_LENGTH, fp) != NULL){
          sscanf(line,"%d %s", &lap_number, filename);
          head = read_data(filename, lap_number, head);
    }

    best_driver(head);
    Top_three(head);
    free_list(head);
    return 0;
}
