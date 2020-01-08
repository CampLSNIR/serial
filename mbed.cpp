
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#include <termios.h>

//gestion des erreurs

#include <errno.h>

int sfd = open("/dev/serial0" , O_RDWR | O_NOCTY );

if( sfd == -1 ){

}
