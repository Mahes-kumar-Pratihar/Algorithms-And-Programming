#ifndef _PRIVATE
#define _PRIVATE

#include "public.h"


typedef struct driver_s driver_t;


struct driver_s{
        char *name;
        char *car;
        int lapnumber;
        int total_time;
        int lap_time;
        int id;
        int position;
        driver_t *next;
};

driver_t *read_data(char *, int, driver_t *);
driver_t *find_driver(driver_t *, int);
void Top_three(driver_t *);
void free_list(driver_t *);

#endif // _PRIVATE
