/*
 * Program: Data Cleaning Utility
 * Description: This program reads data, cleans it using either a deletion or imputation strategy, and outputs the cleaned data.
 * Author: [Your Name]
 * Date: [Date]
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
 * Function: read_data
 * ----------------------------
 *   Reads data from standard input.
 *
 *   rows: Pointer to the number of rows
 *   cols: Pointer to the number of columns
 *
 *   returns: Pointer to the allocated data array
 */
float* read_data(int* rows, int* cols) {
    scanf("%d %d", rows, cols);
    float* data = (float*)malloc((*rows) * (*cols) * sizeof(float));
    for (int i = 0; i < *rows; i++) {
        for (int j = 0; j < *cols; j++) {
            scanf("%f", &data[i * (*cols) + j]);
        }
    }
    return data;
}

/*
 * Function: clean_delete
 * ----------------------------
 *   Cleans data by deleting rows with NaN values.
 *
 *   data: Pointer to the data array
 *   rows: Number of rows in the data
 *   cols: Number of columns in the data
 *   new_rows: Pointer to the number of rows after cleaning
 *
 *   returns: Pointer to the cleaned data array
 */
float* clean_delete(float* data, int rows, int cols, int* new_rows) {
    float* cleaned_data = (float*)malloc(rows * cols * sizeof(float));
    int k = 0;
    *new_rows = 0;
    for (int i = 0; i < rows; i++) {
        int has_nan = 0;
        for (int j = 0; j < cols; j++) {
            if (isnan(data[i * cols + j])) {
                has_nan = 1;
                break;
            }
        }
        if (!has_nan) {
            for (int j = 0; j < cols; j++) {
                cleaned_data[k++] = data[i * cols + j];
            }
            (*new_rows)++;
        }
    }
    cleaned_data = (float*)realloc(cleaned_data, (*new_rows) * cols * sizeof(float));
    return cleaned_data;
}

/*
 * Function: clean_impute
 * ----------------------------
 *   Cleans data by imputing NaN values with the column average.
 *
 *   data: Pointer to the data array
 *   rows: Number of rows in the data
 *   cols: Number of columns in the data
 */
void clean_impute(float* data, int rows, int cols) {
    for (int j = 0; j < cols; j++) {
        float sum = 0;
        int count = 0;
        for (int i = 0; i < rows; i++) {
            if (!isnan(data[i * cols + j])) {
                sum += data[i * cols + j];
                count++;
            }
        }
        float avg = (count > 0) ? sum / count : 0;
        for (int i = 0; i < rows; i++) {
            if (isnan(data[i * cols + j])) {
                data[i * cols + j] = avg;
            }
        }
    }
}

/*
 * Function: output_data
 * ----------------------------
 *   Outputs the data to standard output.
 *
 *   data: Pointer to the data array
 *   rows: Number of rows in the data
 *   cols: Number of columns in the data
 */
void output_data(float* data, int rows, int cols) {
    printf("%d %d\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%.3f ", data[i * cols + j]);
        }
        printf("\n");
    }
}