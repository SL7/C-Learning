# MySQL C API

## Compiling

The Compile command for Linux is:  

```bash
gcc file.c -o out -L/usr/lib/mysql -lmysqlclient
```

But you need to install the dependencies first:

```bash
sudo apt-get install libmysql-*
```

## C - Connecting to MySQL Server

You create the MySQL Object using

```c
#include <mysql/mysql.h>

MYSQL *my;
```

Then you need to first create the object with 

```c
MYSQL *mysql_init(MYSQL *mysql);
```

If the initialization fails, the function will return `NULL`.  

To actually connect to the Server you use:  

```c
MYSQL *mysql_real_connect( MYSQL *sql,                  // MySQL Object
                           const char *host,            // Host address
                           const char *user,            // Username
                           const char *password,        // user password
                           const char *db,              // database name
                           unsigned int port,           // port (default=0)
                           const char *unix_socket,     // Socket (default=NULL)
                           unsigned int client_flag);   // Client flags (default=0)
```

On fail it will return NULL.  
when connecting to the server many error could occur, so to not write another own function to check the errors,
the MySQL Library provides the `mysql_errno()` and the `mysql_error()` function:  

```c
unsigned int mysql_errno(MYSQL *sql);
char *mysql_error(MYSQL *sql);
```

The first one provides the error code and the second the error message.  

To close an existing connection, you can use `mysql_close()`.  

```c
void mysql_close(MYSQL *sql);
```

Example program:

```c
#include <stdlib.h>
#include <stdio.h>
#include <mysql/mysql.h>

const char *user = "sl7";
const char *passwd = "***********";
const char *host = "localhost";
const char *db_name = "test";


int main() {
    MYSQL *my;                  //MySQL Object
    my = mysql_init(NULL);      // Create MySQL Object

    unsigned int mysql_err;
    

    if (my == NULL) {           // Check if init successful
        printf("[-] Error initializing MySQL Handle\n");
        exit(0);
    }
    printf("[+] MySQL Handle init successful\n");
    
    if ( mysql_real_connect(my, host, user, passwd, db_name, 0, NULL, 0)) {
        printf("[+] Connection to MySQL established\n");
    } else { 
        mysql_err = mysql_errno(my);
        fprintf(stderr, "Error mysql_real_connect(): %u (%s)\n", mysql_errno(my), mysql_error(my));
        exit(0);
    }
    
     
    mysql_close(my);
    return 0;
}

```


## MySQL Commandline arguments

???

## Server Requests

Two types of requests:
1. Client sends request -> Server does not answer  
2. Client sendd request -> Server give back request  

```c
int mysql_query(MYSQL *sql, const char *request);
int mysql_real_query(MYSQL *sql, const char *request, unsigned long len);
```

Here you send the request, but you should not write the `;` or a `\g` at the end.  

**Important Note:**  

If you want to send binary data you need to use the `mysql_real_query()` function.  
This is necessary because binary data can have a `\0` at the ends which end the request
when using `mysql_query()`.

Because `mysql_query()` does not have any reference to the request length, 
it is a big candidate for a buffer overflow - thats why it is better to use the
`mysql_real_query()` function to prevent errors like that.  


