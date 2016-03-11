//
// Created by vassilis on 09.03.16.
//

#include "fileParser.h"

int getCoordinatesfromFile(char* filename, int* componentSum, int* fiducialSum, float coordinates[][2], float fiducials[][2]) {

    int cIndex = 0, fIndex = 0;
    char* designator;
    // Construct the parser
    CsvParser *csvparser = CsvParser_new(filename, ",", 1);
    CsvRow *header;
    CsvRow *row;

    // Get the number of rows (essentially the number of parts)
    *componentSum = CsvParser_getNumRows(filename)-2;

    // Extract the headers
    header = CsvParser_getHeader(csvparser);
    if (header == NULL) {
        printf("%s\n", CsvParser_getErrorMessage(csvparser));
        return 1;
    }

    // Parse the .csv file and store the coordinates
    while ((row = CsvParser_getRow(csvparser)) )
    {
        char **rowFields = CsvParser_getFields(row);
        designator = rowFields[DESIGNATOR_COLUMN];

        if(!regExMatcher(designator)) // Fiducial
        {
            fiducials[fIndex][0] = (float) atof(rowFields[X_COLUMN]); // Center-x
            fiducials[fIndex][1] = (float) atof(rowFields[Y_COLUMN]); // Center-y
            printf("F: x:%f y:%f\n", fiducials[fIndex][0], fiducials[fIndex][1]);
            fIndex++;
        }


        else // Component
        {
            coordinates[cIndex][0] = (float) atof(rowFields[X_COLUMN]); // Center-x
            coordinates[cIndex][1] = (float) atof(rowFields[Y_COLUMN]); // Center-y
            printf("C: x:%f y:%f\n", coordinates[cIndex][0], coordinates[cIndex][1]);
            cIndex++;

        }


        CsvParser_destroy_row(row);
    }


    *componentSum = cIndex;
    *fiducialSum = fIndex;
    CsvParser_destroy(csvparser); // destroy the parser

    return 0;
}



int regExMatcher(char* designator) {

    regex_t fiducialExp;
    int retval;

    regcomp(&fiducialExp, "[FID][0-9]", 0);


    if (regexec(&fiducialExp, designator, 0, NULL, 0))
        retval = 1;
    else
        retval = 0;

    regfree(&fiducialExp);

    return retval;

}
