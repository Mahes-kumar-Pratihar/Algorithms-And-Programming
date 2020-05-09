
#include "private.h"

driver_t *read_data(char *filename, int lap_number, driver_t *head){
          driver_t *driver;
          FILE *fp;
          int driverNumber, lapTime;
          char name[MAX_LENGTH], team[MAX_LENGTH];
          fp = fopen(filename, "r");

          while(fscanf(fp, "%d %s %s %d", &driverNumber, name, team, &lapTime) != EOF){
                driver = find_driver(head, driverNumber);
                if(driver == NULL){
                    driver = (driver_t *)malloc(sizeof(driver_t));
                    driver->next = NULL;

                    driver->id = driverNumber;
                    driver->name = strdup(name);
                    driver->car = strdup(team);
                    driver->lap_time = lapTime;

                    driver->lapnumber = lap_number;
                    driver->total_time = 0;
                    driver->position = 0;
                    driver->next = head;
                    head = driver;
                }
                driver->total_time += lapTime;
                if(driver->lap_time > lapTime){
                    driver->lap_time = lapTime;
                    driver->lapnumber = lap_number;
                }
          }
          fclose(fp);
          return head;
}
driver_t *find_driver(driver_t *head, int id){
        driver_t *temp = head;
        while(temp != NULL){
            if(temp->id == id){
                return temp;
            }
            temp = temp->next;
        }

        return NULL;
}
void best_driver(driver_t *head){
         driver_t *temp = head, *best = head;
         while(temp != NULL){
            if(temp->lap_time < best->lap_time){
                    best = temp;
            }
            temp = temp->next;
         }
         fprintf(stdout,"Fastest Lap: %s, %s, %d seconds, Lap %d", best->name, best->car, best->lap_time, best->lapnumber);
}
void Top_three(driver_t *head){
     driver_t *temp = head, *top = head;
     int i;
     fprintf(stdout,"\n\nDriver Ranking:\n");
     for(i = 0; i < 3; i++){

        while(temp != NULL){
            if(temp->total_time < top->total_time && temp->position == 0){
                top = temp;
            }
            temp = temp->next;
        }
        top->position = i + 1;
        fprintf(stdout,"%d %s, %s, %d seconds\n",top->position, top->name, top->car, top->total_time);
        temp = head;
        top = temp;
     }
}
void free_list(driver_t *head){
     driver_t *temp;
     while(head != NULL){
        temp = head;
        head = head->next;
        free(temp);
     }
     return;
}



