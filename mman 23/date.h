#include <stdio.h>

/*
 * Structure to represent a date and time.
 * Contains fields for year, month, day, hours, minutes, and seconds.
 */
typedef struct {
    int year;    /* Year (e.g., 2024) */
    int month;   /* Month (1-12) */
    int day;     /* Day of the month (1-31) */
    int hours;   /* Hours (0-23) */
    int minutes; /* Minutes (0-59) */
    int seconds; /* Seconds (0-59) */
} time;

#define LINE_LEN 100 /* Maximum line length for reading input */

/* Function prototypes for date and time operations. */

 /*
  * Calculates the difference between two Time objects (big and small)
  * and prints the result in seconds.
  */
void dateDiff(time big, time small);

/*
 * Calculates the difference in seconds between two years.
 * Parameters:
 * - byear: The year of the larger time.
 * - syear: The year of the smaller time.
 * Returns: Difference in seconds.
 */
int yearDiffSec(int byear, int syear);

/*
 * Calculates the difference in seconds between two months within the same year.
 * Parameters:
 * - bmonth: The month of the larger time.
 * - smonth: The month of the smaller time.
 * Returns: Difference in seconds.
 */
int monthDiffSec(int bmonth, int smonth);

/*
 * Calculates the difference in seconds between two days within the same month.
 * Parameters:
 * - bdays: The day of the larger time.
 * - sdays: The day of the smaller time.
 * Returns: Difference in seconds.
 */
int dayDiffSec(int bdays, int sdays);

/*
 * Calculates the difference in seconds between two hour values within the same day.
 * Parameters:
 * - bhour: The hour of the larger time.
 * - shour: The hour of the smaller time. 
 * Returns: Difference in seconds
 */
int hoursDiffSec(int bhour, int shour);

/*
 * Calculates the difference in seconds between two minute values within the same hour.
 * Parameters:
 * - bmin: The minute of the larger time. 
 * - smin: The minute of the smaller time.
 * Returns: Difference in seconds.
 */
int minDiffSec(int bmin, int smin);

/*
 * Determines the number of days in a given month.
 * Parameters:
 * - month: The month (1-12).
 * Returns: Number of days in the specified month.
 */
int daysInMonth(int month);

