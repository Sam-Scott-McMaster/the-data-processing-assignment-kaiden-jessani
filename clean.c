/*
 * Program: Data Cleaning Utility
 * Description: This program reads data, checks for a deletion flag, and cleans the data using either a deletion or imputation strategy.
 * Author: [Your Name]
 * Date: [Date]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"  // Include your header file

/*
 * Function: main
 * ----------------------------
 *   Main function to execute the data cleaning process.
 *
 *   argc: Argument count
 *   argv: Argument vector
 *
 *   returns: Exit status of the program
 */
int main(int argc, char *argv[]) {
    int rows, cols;
    int delete_flag = 0;
    
    // Check for the -d flag
    if (argc > 1 && strcmp(argv[1], "-d") == 0) {
        delete_flag = 1;
    }

    // Read the data
    float *data = read_data(&rows, &cols);

    if (delete_flag) {
        // Clean using deletion strategy
        int new_rows;
        float *cleaned_data = clean_delete(data, rows, cols, &new_rows);
        output_data(cleaned_data, new_rows, cols);
        free(cleaned_data);
    } else {
        // Clean using imputation strategy
        clean_impute(data, rows, cols);
        output_data(data, rows, cols);
    }

    // Free the allocated memory
    free(data);

    return 0;
}


