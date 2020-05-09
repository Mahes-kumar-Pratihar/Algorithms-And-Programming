#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define NUM_TRUCKS 4

typedef struct parcel_s{
        int row;
        int col;
        int id;
}parcel_t;

typedef struct truck_s{
        char symbol;
        int row;
        int col;
        int status;
}truck_t;

parcel_t *parcel_read(char *filename, int *num_parcel);
truck_t *truck_read(char *filename, int num_trucks);
int check_truck(int **truck, int x, int y, int truckX, int truckY, int truckRows, int truckCols);
void mark_truck(int **truck, int x, int y, int truckX, int truckY, int parcelID);
void check_capacity(truck_t *trucks, parcel_t *parcels, int num_parcels);
void wrapper(truck_t *trucks, parcel_t *parcels, int num_parcels);
int **malloc2D(int r, int c);
int filling_trucks(parcel_t *parcels, int **truck, int parcelID, int truckRow, int truckCol, int num);


int main(int argc, char **argv)
{
    parcel_t *parcel;
    truck_t *trucks;
    int num_parcel;
    if(argc != 3){
        fprintf(stdout,"Error in no. of command line arguments!");
        exit(EXIT_FAILURE);
    }

    parcel = parcel_read(argv[1], &num_parcel);
    trucks = truck_read(argv[2], NUM_TRUCKS);

    for(int i = 0; i < num_parcel; i++){
        printf("id - %d   ,row - %d   ,col - %d\n", parcel[i].id, parcel[i].row, parcel[i].col);
    }
    for(int j = 0; j < NUM_TRUCKS; j++){
        printf("symbol - %c   ,row - %d   ,col - %d\n",trucks[j].symbol, trucks[j].row, trucks[j].col);
    }
    return 0;
}

parcel_t *parcel_read(char *filename, int *num_parcel){
         parcel_t *parcel;
         FILE *fp;
         int row;
         int col;
         int i = 0;
         fp = fopen(filename, "r");
         if(fscanf(fp, "%d", num_parcel) == EOF){
            fprintf(stdout,"Error in file %s format", filename);
            exit(EXIT_FAILURE);
         }

         parcel = (parcel_t *)malloc(*num_parcel * sizeof(parcel_t));

         while(fscanf(fp,"%dx%d", &row, &col) != EOF){
              parcel[i].row = row;
              parcel[i].id = i + 1;
              parcel[i++].col = col;
         }

         fclose(fp);
         return parcel;
}

truck_t *truck_read(char *filename, int num_trucks){
         truck_t *trucks = malloc(num_trucks * sizeof(truck_t));
         FILE *fp;
         int row, col;
         char ch;
         char line[10];
         fp = fopen(filename, "r");

         int i = 0;
         while(fgets(line, 10, fp) != NULL){
            sscanf(line,"%c %dx%d", &ch, &row, &col);
            trucks[i].row = row;
            trucks[i].symbol = ch;
            trucks[i].status = 1;
            trucks[i++].col = col;
         }

         fclose(fp);
         return trucks;
    }
void check_capacity(truck_t *trucks, parcel_t *parcels, int num_parcels){
     int totalparcels = 0;
     int i;
     for(i = 0; i < num_parcels; i++){
        totalparcels += parcels[i].row * parcels[i].col;
     }
     for(i = 0; i < NUM_TRUCKS; i++){
        if(trucks[i].row * trucks[i].col < totalparcels)
            trucks[i].status = 0;
     }
}
int **malloc2D(int r, int c){
     int **mat;
     int i, j;
     mat = malloc(r * sizeof(int));
     for(i = 0; i < r; i++){
        mat[i] = malloc(c * sizeof(int));
        for(j = 0; j < c; j++){
            mat[i][j] = 0;
        }
     }
     return mat;
}

void wrapper(truck_t *trucks, parcel_t *parcels, int num_parcels){
     int i = 0;
     int **formation;
     for(i = 0; i < NUM_TRUCKS; i++){
         if(trucks[i].status){
            formation = malloc2D(trucks[i].row, trucks[i].col);
            if(filling_trucks(parcels, formation, 1, trucks[i].row, trucks[i].col, num_parcels));
         }
     }

}
int filling_trucks(parcel_t *parcels, int **truck, int parcelID, int truckRow, int truckCol, int num){
    int x, y, i, j;
    if(parcelID == num){
        return 1;
    }

    x = parcels[parcelID].row;
    y = parcels[parcelID].col;

    for(i = 0; i < truckRow; i++){
        for(j = 0; j < truckCol; j++){
            if(check_truck(truck, x, y, i, j, truckRow, truckCol)){
                mark_truck(truck, x, y, i, j, parcelID);
                if(filling_trucks(parcels, truck, parcelID + 1, truckRow, truckCol, num)){
                    return 1;
                }
                mark_truck(truck, x, y, i, j, 0);
            }
            if(check_truck(truck, y, x, i, j, truckRow, truckCol)){
                mark_truck(truck, y, x, i, j, parcelID);
                if(filling_trucks(parcels, truck, parcelID + 1, truckRow, truckCol, num)){
                    return 1;
                }
                mark_truck(truck, y, x, i, j, 0);
            }

        }
    }
   return 0;
}

int check_truck(int **truck, int x, int y, int truckX, int truckY, int truckRows, int truckCols){
    if(x+ truckX > truckRows || y+truckY > truckCols){
        return 0;
    }
    int i, j;
    for(i = truckX; i < truckX + x; i++){
        for(j = truckY; j < truckY + y; j++){
            if(truck[i][j] != 0)
                return 0;
        }
    }

    return 1;
}
void mark_truck(int **truck, int x, int y, int truckX, int truckY, int parcelID){
    int i, j;
    for( i = truckX; i < truckX + x; i++){
        for( j = truckY; j < truckY + y; j++){
            truck[i][j] = parcelID;
        }
    }
}
