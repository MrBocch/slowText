#include <stdio.h>
#include <unistd.h>

#define SPEED 60000

void main(int argc, char *argv[]){

    if(argc == 1){
        printf("You forgor");
        return;
    }

    char *message = argv[1];

    printf("\x1b[2J");
    printf("\x1b[%d;%dH", 3, 6);

    size_t i = 0;
    while(message[i] != '\0'){
        printf("%c", message[i]);
	    //printf("\a"); wouldn't this be cool? alert sound has to be fast
        usleep(SPEED);
        i++;
    }
    printf("\x1b[%d;%dH", 10, 0);
    return;
}
