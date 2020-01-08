
#include <string.h>
#include <stdio.h>
#include <iostream>
#include <unistd.h>
#include <fcntl.h>

#include <termios.h>

//gestion des erreurs

#include <errno.h>



using namespace std;


int main(){
    
    const int BAUDRATE = 115200;
    
    int sfd = open("/dev/serial/by-id/usb-STMicroelectronics_STM32_STLink_066BFF323338424E43102325-if02" , O_RDONLY | O_NOCTTY );// ouvrir le fichier 
    
    if( sfd == -1 ){ // verifier si il y a une erreur
        printf( "ERROR %d\n" , errno);
        printf( "%s\n" , strerror(errno) );
        return (-1);
    }else{
        struct termios configTerm;
        
        bzero( &configTerm , sizeof(configTerm) );
        
        
        
        configTerm.c_cflag = BAUDRATE | CRTSCTS | CS8 | CLOCAL | CREAD //| IGNPAR | ICRNL;
        
        tcflush( sfd , TCIFLUSH );
        
        tcsetattr( sfd , TCSANOW , &configTerm );
        
        char buf[255];
        int res;
    
        cout << "Port série ouvert en lecture seule" << "\n"; // port ouvert avec succes 
        
        while( true ){
            res = read( sfd , buf , 255);
            buf[res] = 0;
            
            //if( res != 0 ){
                //printf( ":%s:%d\n" , buf , res);
                cout << buf;
            //}
            
            if( buf[0] == 'z') break;
            
        
        }
    }
    
    
    
    return 0;
    
    
}


