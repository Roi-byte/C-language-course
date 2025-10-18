

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "date.h" /* Custom header file for date-related structures and functions */

int main(int argc, char* argv[]) {
    FILE *ifp;
    char *file_name1 = argv[1]; /* File name provided as a command-line argument */
    char time1[LINE_LEN]; /* Buffer to hold the first date string */
    char time2[LINE_LEN]; /* Buffer to hold the second date string */
    time date1 = { 0 }; /* Initialize date structures */
    time date2 = { 0 }; /* Initialize date structures */

    /* Open the input file for reading */
    ifp = fopen(file_name1, "r");
    if (ifp == NULL) {
        perror("Failed to open file"); /* Print error message if file can't be opened */
        exit(0); /* Exit the program */
    }

    /* Read lines from the file */
    while (fgets(time1, LINE_LEN, ifp) != NULL) {
        /* Remove the newline character at the end of the string, if present */
        if (strchr(time1, '\n')) {
            *(strchr(time1, '\n')) = '\0';
        }

        /* Parse the first date string into the date1 structure */
        if (!(sscanf(time1, "%d,%d,%d,%d,%d,%d",
            &date1.day, &date1.month, &date1.year,
            &date1.hours, &date1.minutes, &date1.seconds) == 6 ||
            sscanf(time1, "%d/%d/%d,%d,%d,%d",
                &date1.day, &date1.month, &date1.year,
                &date1.hours, &date1.minutes, &date1.seconds) == 6 ||
            sscanf(time1, "%d %d %d %d %d %d",
                 &date1.day, &date1.month, &date1.year,
                &date1.hours, &date1.minutes, &date1.seconds) == 6)) {
            fprintf(stderr, "Invalid first date format\n"); /*error for incorrect format - it will never reach it */
}

        /* Read the second date string */
        if (fgets(time2, LINE_LEN, ifp) != NULL) {
            /* Remove the newline character at the end of the string, if present */
            if (strchr(time2, '\n')) {
                *(strchr(time2, '\n')) = '\0';
            }

            /* Parse the second date string into the date2 structure */
           if (!(sscanf(time2, "%d,%d,%d,%d,%d,%d",
                &date2.day, &date2.month, &date2.year,
                &date2.hours, &date2.minutes, &date2.seconds) == 6 ||
                sscanf(time2, "%d/%d/%d,%d,%d,%d",
                    &date2.day, &date2.month, &date2.year,
                    &date2.hours, &date2.minutes, &date2.seconds) == 6 ||
                sscanf(time2, "%d %d %d %d %d %d",
                    &date2.day, &date2.month, &date2.year,
                    &date2.hours, &date2.minutes, &date2.seconds) == 6)) {
                fprintf(stderr, "Invalid second date format\n"); /*error for incorrect format - it will never reach it */
	}

        }

        /* Compare the two dates and calculate the difference */
        while (1) { /*a loop to run untill EOF*/
            /* Check if date1 is earlier than date2 */
          
            /* Check if date1 (smaller) is earlier than date2 */
            if (date1.year < date2.year ||
                (date1.year == date2.year && date1.month < date2.month) ||
                (date1.year == date2.year && date1.month == date2.month && date1.day < date2.day) ||
                (date1.year == date2.year && date1.month == date2.month && date1.day == date2.day && date1.hours < date2.hours) ||
                (date1.year == date2.year && date1.month == date2.month && date1.day == date2.day && date1.hours == date2.hours && date1.minutes < date2.minutes) ||
                (date1.year == date2.year && date1.month == date2.month && date1.day == date2.day && date1.hours == date2.hours && date1.minutes == date2.minutes && date1.seconds < date2.seconds)) {
                dateDiff(date2, date1); /* Calculate difference assuming date2 is later */
		break;
            }
            else {
                dateDiff(date1, date2); /* Calculate difference assuming date1 is later (bigger) or they are the same(equal)*/
		break;
            }
        }
    }

    fclose(ifp); /* Close the input file */
    return 0;
}

/* Function to calculate the difference between two dates in seconds */
void dateDiff(time big, time small) {
    unsigned long int temp;
    temp = yearDiffSec(big.year, small.year); /* Add year difference in seconds */
    temp += monthDiffSec(big.month, small.month); /* Add month difference in seconds */
    temp += dayDiffSec(big.day, small.day); /* Add day difference in seconds */
    temp += hoursDiffSec(big.hours, small.hours); /* Add hour difference in seconds */
    temp += minDiffSec(big.minutes, small.minutes); /* Add minute difference in seconds */
    temp += (big.seconds - small.seconds); /* Add second difference */
    printf("The time difference in seconds between the two times is: %lu\n", temp);
}


/* Function to calculate year difference in seconds */
int yearDiffSec(int byear, int syear) {
    /* byear = the year of the larger time, syear= the year of the smaller time */
    return (byear - syear) * 31536000; /* 31536000 = 365 * 24 * 60 * 60 */
}

/* Function to calculate month difference in seconds */
int monthDiffSec(int bmonth, int smonth) {
    int i;
    int bdays = 0; /*The month of the larger time*/
    int sdays = 0; /*The month of the smaller time*/

    /* Calculate the number of days for the larger month */
    for (i = 1; i <= bmonth; i++) {
        bdays += daysInMonth(i); /*call a function that convert month to days*/
    }

    /* Calculate the number of days for the smaller month */
    for (i = 1; i <= smonth; i++) {
        sdays += daysInMonth(i); /*call a function that convert month to days*/
    }

    return (bdays - sdays) * 86400; /* Convert days to seconds */
}

/* Function to calculate day difference in seconds */
int dayDiffSec(int bdays, int sdays) {
    /* bdays = the day of the larger time, sdays= the day of the smaller time */
    return (bdays - sdays) * 86400; /* 86400 = 24 * 60 * 60 */
}

/* Function to calculate hour difference in seconds */
int hoursDiffSec(int bhour, int shour) {
    /* bhour = the hour of the larger time, shour= the hour of the smaller time */
    return (bhour - shour) * 3600; /* 3600 = 60 * 60 */
}

/* Function to calculate minute difference in seconds */
int minDiffSec(int bmin, int smin) {
    return (bmin - smin) * 60; /* bmin = the minute of the larger time, smin= the minute of the smaller time */
}

/* Function to determine the number of days in a given month */
int daysInMonth(int month) {
    switch (month) {
    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
        return 31; /* Months with 31 days */
    case 4: case 6: case 9: case 11:
        return 30; /* Months with 30 days */
    case 2:
        return 28; /* February (ignoring leap years for simplicity) */
    default:
        return 0; /* Invalid month */
    }
}


