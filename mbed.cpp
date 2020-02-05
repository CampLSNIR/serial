
#include <string.h>
#include <stdio.h>
#include <iostream>
#include <unistd.h>
#include <fcntl.h>

#include <termios.h>
#include <sstream>

#include <errno.h>

#include <mariadb/mysql.h>



using namespace std;

void explode( string input, char sep ) { 

    istringstream buffer(input);

    string temp;
    
    string match = "Temp[0]";

    while (std::getline(buffer, temp, sep)){
        
        bool show = true;
        
        for( int i = 0 ; i < match.length() ; i++ ){
            if ( temp[i] != match[i] ){
                show = false;
            }
        }
        
        if ( show == true ){
            cout << temp << "\n";
        }
    }
}

int explode50( string input, char sep , int counter ) { 

    istringstream buffer(input);
    
    string temp;

    while (std::getline(buffer, temp, sep)){
        
        bool show = true;
        
        for( int i = 0 ; i < temp.length() ; i++ ){
            if ( temp[i] == '\n' ){
                counter++;
            }
        }
        
        if ( counter < 50 ){
            cout << counter << " " << temp << "\n";
        }
    }
    
    return counter;
}



int main(){

	MYSQL *conn;

	if ((conn = mysql_init(NULL)) == NULL){
		fprintf(stderr, "Could not init DB\n");
		return EXIT_FAILURE;
	}
	if (mysql_real_connect(conn, "localhost", "root", "eleve", "bts_tutorial", 0, NULL, 0) == NULL){
		fprintf(stderr, "DB Connection Error\n");
		return EXIT_FAILURE;
	}
	
	if (mysql_query(conn, "CREATE TABLE IF NOT EXISTS `Temp` (id INT PRIMARY KEY NOT NULL AUTO_INCREMENT , degres INT);") != 0){
		fprintf(stderr, "Query Failure\n");
		return EXIT_FAILURE;
	}

	if (mysql_query(conn, "INSERT INTO Temp (degres) VALUES ('30')") != 0){
		fprintf(stderr, "Query Failure\n");
		return EXIT_FAILURE;
	}

	
	const int BAUDRATE = 115200;
	
	int sfd = open("/dev/serial/by-id/usb-STMicroelectronics_STM32_STLink_066BFF323338424E43102325-if02" , O_RDONLY | O_NOCTTY );// ouvrir le fichier 
	
	if( sfd == -1 ){ // verifier si il y a une erreur
		printf( "ERROR %d\n" , errno);
		printf( "%s\n" , strerror(errno) );
		return (-1);
    }else{
        struct termios configTerm;
        
        bzero( &configTerm , sizeof(configTerm) );
        
        configTerm.c_cflag = BAUDRATE | CRTSCTS | CS8 | CLOCAL | CREAD;
        
        configTerm.c_iflag = IGNPAR | ICRNL;
        
        configTerm.c_lflag =  ICANON;
        
        tcflush( sfd , TCIFLUSH );
        
        tcsetattr( sfd , TCSANOW , &configTerm );
        
        char buf[255];
        char oldbuf[255];
        int res;
        bool newline = false;
        int counter = 0;
    
        cout << "Port série ouvert en lecture seule" << "\n"; // port ouvert avec succes 
        
        while( true ){
            res = read( sfd , buf , 255); // lire le buffer
            buf[res] = 0; // met le caractere fin de chaine a la fin du buffer
            //counter = explode50( (string)buf , '\n' , counter );
            explode( (string)buf , '\n' );
            //cout << buf; // afficher le buffer
            
        }
    }
    
    
    
    return 0;
    
    
}


