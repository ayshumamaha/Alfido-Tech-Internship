#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LOGFILE "logs.txt"
#define BACKUPFILE "backup_logs.txt"
#define MAX_LINE 200

/*=========================================================
                CREATE LOG FILE
=========================================================*/

void createLogFile()
{
    FILE *fp;

    fp = fopen(LOGFILE, "a");

    if(fp == NULL)
    {
        printf("\nError Creating Log File!\n");
        return;
    }

    fclose(fp);

    printf("\nLog File Ready.\n");
}

/*=========================================================
                ADD LOG ENTRY
=========================================================*/

void addLogEntry()
{
    FILE *fp;
    char message[MAX_LINE];

    fp = fopen(LOGFILE, "a");

    if(fp == NULL)
    {
        printf("\nUnable to Open Log File.\n");
        return;
    }

    getchar();

    printf("\nEnter Log Message:\n");
    fgets(message, MAX_LINE, stdin);

    fprintf(fp, "%s", message);

    fclose(fp);

    printf("\nLog Entry Added Successfully.\n");
}

/*=========================================================
                VIEW LOG FILE
=========================================================*/

void viewLogs()
{
    FILE *fp;
    char line[MAX_LINE];

    fp = fopen(LOGFILE, "r");

    if(fp == NULL)
    {
        printf("\nLog File Not Found.\n");
        return;
    }

    printf("\n========== LOG FILE ==========\n\n");

    while(fgets(line, MAX_LINE, fp) != NULL)
    {
        printf("%s", line);
    }

    printf("\n==============================\n");

    fclose(fp);
}

/*=========================================================
                COUNT LOG ENTRIES
=========================================================*/

void countLogs()
{
    FILE *fp;
    char line[MAX_LINE];
    int count = 0;

    fp = fopen(LOGFILE, "r");

    if(fp == NULL)
    {
        printf("\nLog File Not Found.\n");
        return;
    }

    while(fgets(line, MAX_LINE, fp) != NULL)
    {
        count++;
    }

    fclose(fp);

    printf("\nTotal Log Entries : %d\n", count);
}
/*=========================================================
                SEARCH LOG ENTRY
=========================================================*/

void searchLog()
{
    FILE *fp;
    char line[MAX_LINE];
    char keyword[MAX_LINE];
    int found = 0;

    fp = fopen(LOGFILE, "r");

    if(fp == NULL)
    {
        printf("\nLog File Not Found.\n");
        return;
    }

    getchar();

    printf("\nEnter Keyword to Search: ");
    fgets(keyword, MAX_LINE, stdin);

    keyword[strcspn(keyword, "\n")] = '\0';

    printf("\nMatching Log Entries:\n\n");

    while(fgets(line, MAX_LINE, fp) != NULL)
    {
        if(strstr(line, keyword) != NULL)
        {
            printf("%s", line);
            found = 1;
        }
    }

    if(!found)
        printf("No Matching Entry Found.\n");

    fclose(fp);
}

/*=========================================================
                BACKUP LOG FILE
=========================================================*/

void backupLogs()
{
    FILE *source;
    FILE *backup;
    char ch;

    source = fopen(LOGFILE, "r");

    if(source == NULL)
    {
        printf("\nLog File Not Found.\n");
        return;
    }

    backup = fopen(BACKUPFILE, "w");

    while((ch = fgetc(source)) != EOF)
    {
        fputc(ch, backup);
    }

    fclose(source);
    fclose(backup);

    printf("\nBackup Created Successfully.\n");
}

/*=========================================================
                FILE STATISTICS
=========================================================*/

void fileStatistics()
{
    FILE *fp;
    char line[MAX_LINE];
    int lines = 0;
    int characters = 0;

    fp = fopen(LOGFILE, "r");

    if(fp == NULL)
    {
        printf("\nLog File Not Found.\n");
        return;
    }

    while(fgets(line, MAX_LINE, fp) != NULL)
    {
        lines++;
        characters += strlen(line);
    }

    fclose(fp);

    printf("\n========== FILE STATISTICS ==========\n");
    printf("Total Log Entries : %d\n", lines);
    printf("Total Characters : %d\n", characters);
}
/*=========================================================
                CLEAR LOG FILE
=========================================================*/

void clearLogs()
{
    FILE *fp;

    fp = fopen(LOGFILE, "w");

    if(fp == NULL)
    {
        printf("\nUnable to Clear Log File.\n");
        return;
    }

    fclose(fp);

    printf("\nLog File Cleared Successfully.\n");
}

/*=========================================================
                DELETE LOG FILE
=========================================================*/

void deleteLogFile()
{
    if(remove(LOGFILE) == 0)
        printf("\nLog File Deleted Successfully.\n");
    else
        printf("\nUnable to Delete Log File.\n");
}

/*=========================================================
                        MAIN
=========================================================*/

int main()
{
    int choice;

    createLogFile();

    while(1)
    {
        printf("\n=====================================\n");
        printf("    LOG FILE MANAGEMENT SYSTEM\n");
        printf("=====================================\n");

        printf("1. Create Log File\n");
        printf("2. Add Log Entry\n");
        printf("3. View Log Entries\n");
        printf("4. Search Log Entry\n");
        printf("5. Count Log Entries\n");
        printf("6. File Statistics\n");
        printf("7. Backup Log File\n");
        printf("8. Clear Log File\n");
        printf("9. Delete Log File\n");
        printf("10. Exit\n");

        printf("\nEnter Choice : ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                createLogFile();
                break;

            case 2:
                addLogEntry();
                break;

            case 3:
                viewLogs();
                break;

            case 4:
                searchLog();
                break;

            case 5:
                countLogs();
                break;

            case 6:
                fileStatistics();
                break;

            case 7:
                backupLogs();
                break;

            case 8:
                clearLogs();
                break;

            case 9:
                deleteLogFile();
                break;

            case 10:
                printf("\nThank You!\n");
                return 0;

            default:
                printf("\nInvalid Choice!\n");
        }
    }

    return 0;
}