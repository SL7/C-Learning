#include <stdlib.h>
#include <stdio.h>
#include <mysql/mysql.h>
#include <string.h>

void check_error(void);
void connect(void);
void close_conn(void);
void db_select(char *db);
void moviedata_put(void);
void moviedata_remove(void);
void moviedata_change(void);
void show_all_data(void);
void search_actor(char *);
void print_line(MYSQL_RES *res);

MYSQL *sql;

int main() {
    int selection;
    char actor[255];
    char *ptr;

    printf("Connecting to Database...\n\n");
    connect();
    db_select("test");

    do {
        printf("\n-1- add moviedata\n");
        printf("-2- delete moviedata\n");
        printf("-3- change moviedata\n");
        printf("-4- show moviedata\n");
        printf("-5- search movie\n");
        printf("-6- quit\n\n");
        printf("Selection: ");
        scanf("%d", &selection);
        getchar();

        switch(selection) {
            case 1:
                moviedata_put();
                break;
            case 2:
                moviedata_remove();
                break;
            case 3:
                moviedata_change();
                break;
            case 4:
                show_all_data();
                break;
            case 5:
                printf("Actor: ");
                fgets(actor, 254, stdin);
                if ((ptr=(char*)strchr(actor, '\n')) != NULL)
                    *ptr = '\0';
                search_actor(actor);
                break;
            case 6:
                printf("...closing connection\n");
                break;
            default:
                printf("Wrong selection\n");
        }
    } while(selection != 6);
    close_conn(); 

    return EXIT_SUCCESS;
}

void check_error(void) {
    if (mysql_errno(sql) != 0) {
        fprintf(stderr, "Error: %s\n", mysql_error(sql));
        exit(0);
    }
}

void connect(void) {
    sql = mysql_init(sql);
    check_error();

    mysql_real_connect(sql, "localhost", "sl7", "rrr", "test", 0, NULL, 0);
    check_error();
}

void close_conn(void) {
    mysql_close(sql);
}

void db_select(char *db) {
    mysql_select_db(sql, db);
    check_error();
}

void moviedata_put(void) {
    char title[255], actor[255], temp[6];
    unsigned int fsk, year;
    int i, size = 0;
    char *str[9], *query;
    char *ptr;

    printf("\n\nTitle: ");
    fgets(title, 254, stdin);
    if ((ptr = strchr(title, '\n')) != NULL)
        *ptr = '\0';
    printf("\nActor: ");
    fgets(actor, 254, stdin);
    if ((ptr = strchr(actor, '\n')) != NULL) 
        *ptr = '\0';
    printf("\nFSK: ");
    fgets(temp, 4, stdin);
    if(( ptr = strchr(temp, '\n')) != NULL)
        *ptr = '\0';
    sscanf(temp, "%u", &fsk);
    printf("Year: ");
    fgets(temp, 5, stdin);
    if ((ptr = strchr(temp, '\n')) != NULL) 
        *ptr = '\0';
    sscanf(temp, "%u", &year);

    str[0] = "INSERT INTO moviedata (title, actor, fsk, year) VALUES('";
    str[1] = malloc(strlen(title) + 1);
    strcpy(str[1],title);
    str[2] = ",";
    str[3] = malloc(strlen(actor) +1 );
    strcpy(str[3], actor);
    str[4] = ",";
    str[5] = malloc(5);
    sprintf(str[5], "%2u", fsk);
    str[6] = ",";
    str[7] = malloc(5);
    sprintf(str[6], "%4u", year);
    str[8] = ")";

    for(i = 0; i < 9; i++) {
        size += strlen(str[i]);
    }
    query = malloc(size + 1);
    strcpy(query, str[0]);
    for( i =1; i < 9; i++) {
        strcat(query, str[i]);
    }
    printf("%s\n", query);

    mysql_real_query(sql, query, strlen(query));
    check_error();
    free(query);
}


void moviedata_remove(void) {
    char del[255], temp[4];
    char *item[] = {"title", "actor", "fsk", "year"};
    char *ptr;
    char *str[5], *query = '\0';
    int selection, i, size = 0;
    unsigned long affected;

    printf("How do you want to delete the data?\n");
    printf("[1] = Title [2]=Actor [3]=FSK [4]Date = []\b\b");
    fgets(temp,3,stdin);
    if ((ptr = strchr(temp, '\n')) != NULL)
        *ptr = '\0';
    sscanf(temp, "%d", &selection);

    str[0] = "DELETE FROM moviedata WHERE ";
    if (selection > 0 && selection < 5) {
        str[1] = malloc(strlen(item[selection-1]+1);
        strcpy(str[1], item[selection-1]);
    } else {
        printf("No such Selection\n");
        return ;
    }
    str[2] = " = '";
    printf("Make Selection for \'%s\': ", item[selection-1]);
    fgets(del, 254, stdin);
    if ((ptr = strchr(del, '\n')) != NULL)
        *ptr = '\0';
    str[3] = malloc(strlen(del) + 1);
    strcpy(str[3], del);
    str[4] = "'";

    for(i = 0; i < 5; i++) {
        size += strlen(str[i]);
    }
    mysql_real_query(sql, query, strlen(query));
    check_error();
    if ((affected=(unsigned long)mysql_affected_rows(sql)) <= 0) {
        printf("no data was affected\n");
        check_error();
    } else {
        printf("%ld data affected\n", affected);
    }
    free(query);
}


void moviedata_change(void) {
    
    char change[255], replace[255], temp[4];
    char *item[] = {"title", "actor", "fsk", "year"};
    char *ptr;
    char *str[8], *query;
    int selection1, seletion2, i, size=0;
    unsigned int integer;
    unsigned long affected;
    
    printf("Which data do you want to change? \n");
    printf("[1]=Title [2]=Actor [3]=FSK [4]=Date: [] \b\b");

    fgets(temp, 3, stdin );
    if ((ptr = strchr(temp, '\n')) != NULL) {
        *ptr = '\0';
    }
    sscanf(temp, "%ld", &selection1);

}
