#include <stdlib.h>
#include <stdio.h>
#include <mysql/mysql.h>

const char *user = "sl7";
const char *passwd = "rrr";
const char *host = "localhost";
const char *db_name = "test";


int main() {
    MYSQL *my;
    my = mysql_init(NULL);

    unsigned int mysql_err;
    
    char *p;
    int port_num = 0;
    char *socket_name = NULL;
    if ((p = getenv("MYSQL_TCP_PORT")) != NULL)
        port_num = atoi(p);
    if ((p = getenv("MYSQL_UNIX_PORT")) != NULL)
        socket_name = p;


    if (my == NULL) {
        printf("[-] Error initializing MySQL Handle\n");
        exit(0);
    }
    printf("[+] MySQL Handle init successful\n");
    
    if ( mysql_real_connect(my, host, user, passwd, db_name, port_num, socket_name, 0)) {
        printf("[+] Connection to MySQL established\n");
    } else { 
        mysql_err = mysql_errno(my);
        fprintf(stderr, "Error mysql_real_connect(): %u (%s)\n", mysql_errno(my), mysql_error(my));
        exit(0);
    }
    
     
    mysql_close(my);
    return 0;
}
