
#include "public.h"

int main(int argc, char **argv){

    if(argc != 2){
        fprintf(stdout,"Error in opening the file");
        exit(EXIT_FAILURE);
    }

    read_file(argv[1]);


    return 0;
}















