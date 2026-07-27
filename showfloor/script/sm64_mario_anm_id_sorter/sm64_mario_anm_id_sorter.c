#include <stdio.h>
#include <string.h>

#define ID_INPUT_FILENAME "ids.h"
#define ID_NEW_FILENAME "ids_NEW.h"

// Only 256 animations can be sorted at most
#define MAX_LENGTH 256

// All current IDs are stored here
unsigned int curIDArray[MAX_LENGTH] = {};
// Count of all existing IDs, used to properly assign each ID
unsigned int IDCount = 0;

// This script sorts Mario's animation IDs if the animtion order was changed in any way. 

/*
 * Should be fairly self-explanatory, copies the line from "ids.h" with the animation name and ID but with the proper ID instead.
 */
void copy_line_with_new_id(FILE *outputFile, char *line, unsigned int IDCount) {
    char mario_anm_name[100];
    
    sscanf(line + 15, "%[^\n]", mario_anm_name); // line + 15 because there are 15 chars before the anim name in the decomp format

    fprintf(outputFile, "    /* 0x%02X */ %s\n", IDCount, mario_anm_name);
}

/*
 * Read an input file called "ids.h" (in the same format as "mario_animaiton_ids.h" from the SM64 decomp),
 * and correct it if the IDs are not in sequential order. Create a copy, "ids_NEW.h", with the IDs properly numbered
 */
int script_1st_half() {
    FILE *inputFile, *outputFile;
    char line[MAX_LENGTH];

    inputFile = fopen(ID_INPUT_FILENAME, "r");
    
    // Check if "ids.h" is missing
    if (inputFile == NULL) {
        printf("ERROR! Could not open '%s'.\n", ID_INPUT_FILENAME);
        return 1;
    }

    outputFile = fopen(ID_NEW_FILENAME, "w");

    // Start reading the input file from top to bottom
    while (fgets(line, sizeof(line), inputFile) != NULL) {
        unsigned int currentID = 0;
        // Look for IDs inside /* */ comments
        if (strstr(line, "/* 0x")) {
            //printf("found ID on line %s", line);

            sscanf(line, "    /* %x */", &currentID); // Take the current ID inside the /* */ comments
            //printf("hex value is 0x%02X\n", currentID);

            curIDArray[IDCount] = currentID; // Store it in the array
            //printf("Stored to %d\n", IDCount);

            copy_line_with_new_id(outputFile, line, IDCount); // Copy current line with the proper ID

            IDCount++; // Increase the count       
        } else {
            fprintf(outputFile, "%s", line); // If there are no ID comments, simply copy the current line
        }
    }

    // Not needed anymore, close both files
    fclose(inputFile);
    fclose(outputFile);

    // If no IDs were found, stop execution
    if (IDCount == 0) {
        printf("ERROR! No IDs found in '%s'.\n", ID_INPUT_FILENAME);
        return 1;    
    }

    // Check for any duplicate IDs, stop excecution if a duplicate is found
    for (int i = 0; i < IDCount; i++) {
        for (int j = i + 1; j < IDCount; j++) {
            if (curIDArray[i] == curIDArray[j]) {
                printf("ERROR! Duplicate ID found (0x%02X)\n", curIDArray[i]);
                return 1;
            }
        }
    }

    printf("'%s' created succesfully!\n", ID_NEW_FILENAME);

    return 0;
}

/*
 * Replace the current ID in an inc.c file with the proper one, uses pointer arithmetic to 
 * make sure everything before and after the ID is maintained, with only the ID being replaced
 */
void replace_curr_id_in_line(FILE *outputFile, char *line, int properID) {
    char *target = "anim_";

    // Find where "anim_" begins
    char *match = strstr(line, target);

    // Find where the ID begins
    char *IDStart = match + strlen(target);

    // Get everything after the ID
    char *suffix = IDStart + 2;

    // Calculate the amount of chars before the ID
    int lengthBeforeID = IDStart - line;

    // Finally, write the line with the ID changed
    fprintf(outputFile, "%.*s%02X%s", lengthBeforeID, line, properID, suffix);
}

/*
 * Same thing as the previous function, except it replaces an instance of both IDs in an inc.c file (XX_YY)
 */
void replace_both_curr_ids_in_line(FILE *outputFile, char *line, int properID) {
    char *target = "anim_";

    // Find where "anim_" begins
    char *match = strstr(line, target);

    // Find where the IDs begin
    char *IDsStart = match + strlen(target);

    // Get everything after the IDs
    char *suffix = IDsStart + 5; // 5 and not 4 because of the "_" between both IDs

    // Calculate the amount of chars before the IDs
    int lengthBeforeIDs = IDsStart - line;

    // Finally, write the line with the IDs changed
    fprintf(outputFile, "%.*s%02X_%02X%s", lengthBeforeIDs, line, (properID - 1), properID, suffix);
}

/*
 * Replaces all instances of the current ID in the inc.c file, including the filename.
 * The inc.c files with the replaced IDs are stored in a separate folder, "anims_NEW"
 */
void replace_ids_incc_file(FILE *inputFile, FILE *outputFile, int properID, int has2IDs) {
    char outFilename[50];
    char currIDTarget[10];
    char line[MAX_LENGTH];

    if (has2IDs != 1) { // If there's only 1 ID
        //printf("only 1 ID!\n");
        
        // Create a copy of the file with the proper ID in the name
        snprintf(outFilename, sizeof(outFilename), "./anims_NEW/anim_%02X.inc.c", properID);
        outputFile = fopen(outFilename, "w");

        // Create a target to look for in the input file (the current ID)
        snprintf(currIDTarget, sizeof(currIDTarget), "_%02X", curIDArray[properID]);

        while (fgets(line, sizeof(line), inputFile) != NULL) {
            // Look for the current ID
            if (strstr(line, currIDTarget)) {
                // If it's found, replace with the proper ID
                replace_curr_id_in_line(outputFile, line, properID);  
            } else {
                fprintf(outputFile, "%s", line); // If there is no ID found, simply copy the current line
            }
        }
    } else { // If there are 2 IDs
        //printf("there's 2 IDs!\n");

        // There need to be 3 targets when there are 2 IDs, since the inc.c has both together, and each individually
        char bothIDsTarget[10];
        char firstIDTarget[5];
        char secondIDTarget[5];

        // Create a copy of the file with the proper IDs in the name
        snprintf(outFilename, sizeof(outFilename), "./anims_NEW/anim_%02X_%02X.inc.c", (properID- 1), properID);
        outputFile = fopen(outFilename, "w");

        // Create a target to look for in the input file ("anim_")
        snprintf(currIDTarget, sizeof(currIDTarget), "anim_");

        // Target that has both IDs (XX_YY)
        snprintf(bothIDsTarget, sizeof(bothIDsTarget), "_%02X_%02X", (curIDArray[properID] - 1), curIDArray[properID]);

        // Target with only the first ID (XX)
        snprintf(firstIDTarget, sizeof(firstIDTarget), "_%02X", (curIDArray[properID] - 1));

        // Target with only the second ID (YY)
        snprintf(secondIDTarget, sizeof(secondIDTarget), "_%02X", curIDArray[properID]);

        while (fgets(line, sizeof(line), inputFile) != NULL) {
            // Look for "anim_"
            if (strstr(line, currIDTarget)) {                
                // Check if it has both IDs
                if (strstr(line, bothIDsTarget)) {
                    // If both IDs are found, replace with the proper IDs
                    replace_both_curr_ids_in_line(outputFile, line, properID);
                } 
                // Check if it has only the first ID
                else if (strstr(line, firstIDTarget)) {
                    // If it's found, replace with the proper ID
                    replace_curr_id_in_line(outputFile, line, (properID - 1)); 
                } 
                // Check if it has only the second ID
                else if (strstr(line, secondIDTarget)) {
                    // If it's found, replace with the proper ID
                    replace_curr_id_in_line(outputFile, line, properID);
                }                 
            } else {
                fprintf(outputFile, "%s", line); // If there's no "anim_" found, simply copy the current line
            }
        }
    }
}

/*
 * Opens every inc.c file inside the "anims" folder sequentially,
 * and calls a function to replace the IDs of each inc.c file with the proper ones
 */
int script_2nd_half() {
    FILE *incCFile, *incCOutput;

    char filename[50];

    for (int i = 0; i < IDCount; i++) {
        int has2IDs = 0; // Used to handle files with two IDs differently

        // look for every inc.c file in order
        snprintf(filename, sizeof(filename), "./anims/anim_%02X.inc.c", curIDArray[i]);
        incCFile = fopen(filename, "r");

        // If the inc.c file with only 1 ID isn't found, look for one with two IDs at once
        if (incCFile == NULL) {
            snprintf(filename, sizeof(filename), "./anims/anim_%02X_%02X.inc.c", curIDArray[i], (curIDArray[i] + 1));        
            incCFile = fopen(filename, "r");

            if (incCFile != NULL) {
                i++; // Increase the counter twice if an inc.c with 2 IDs is found
                has2IDs = 1; // And set this variable to 1 so it properly handles 2 IDs
            }
        } else {
            has2IDs = 0; // Keep it zero if the file only has 1 ID
        }

        // If it's not found after looking for the version with both IDs, stop excecution
        if (incCFile == NULL) {
            printf("ERROR! inc.c animation '%02X' not found in the 'anims' folder.\n", curIDArray[i]);
            return 1;    
        } else {
            // Replace the IDs if the inc.c has been found
            replace_ids_incc_file(incCFile, incCOutput, i, has2IDs);
            
            // Print every file that was succesfully replaced
            printf("%s replaced!\n", filename);
        }
    }

    // Not needed anymore, close the file
    fclose(incCFile);

    printf("inc.c files replaced succesfully!\n");

    return 0;
}

/*
 * Main script
 */
int main() {    
    // Execute the 1st half of the script, creates "ids_NEW.h"
    if (script_1st_half() != 0) {
        printf("1st half failure... STOP.\n");
        return 1;
    }

    printf("1st half success!\n");

    // Exceute the 2nd half of the script, replaces IDs of the inc.c files inside the "anims" folder
    if (script_2nd_half() != 0) {
        printf("2nd half failure... STOP.\n");
        return 1;
    }

    printf("2nd half success! END.\n");

    return 0;
}