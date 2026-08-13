// https://www.geeksforgeeks.org/c/c-c-include-directive-with-examples/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// These were useful 
// https://everything.explained.today/Bus_error/
// https://stackoverflow.com/questions/72186275/trace-trap-when-using-strcat

// I have /ns at the end of printfs because otherwise the printing has a % at the end
// https://www.reddit.com/r/learnprogramming/comments/gzvus1/question_whenever_i_run_a_c_programcompiled_with/

// This lets me concat strings without dealing with char array size limits
// I don't really need to care about free()ing the result of this, remindme is so short in runtime.
// https://stackoverflow.com/questions/8465006/how-do-i-concatenate-two-strings-in-c
char* concat(const char *s1, const char *s2)
{
    char *result = malloc(strlen(s1) + strlen(s2) + 1); // +1 for the null-terminator
    // "in real code you would check for errors in malloc here", quoth the comment
    // Well I never.
    strcpy(result, s1);
    strcat(result, s2);
    return result;
}

// https://www.geeksforgeeks.org/cpp/command-line-arguments-in-c-cpp/
int main(int argc, char *argv[]) {

    // https://www.w3schools.com/c/c_booleans.php
    bool text_specified = false;
    char *text = "";
    bool path_specified = false;
    char *path = "./";
    bool delete = false;

    // Gather the args
    for (int i = 1; i < argc; i++) {
        if (text_specified) {
            // https://www.geeksforgeeks.org/c/concatenating-two-strings-in-c/
            text = concat(concat(text, " "), argv[i]);
            continue;
        }

        // https://www.geeksforgeeks.org/c/strcmp-in-c/
        if (strcmp(argv[i], "-p") == 0) {
            if (path_specified) {
                printf("You can only give the path parameter once\n");
                exit(EXIT_FAILURE);
            }
            if (argc <= i+1) {
                printf("You must provide the path to the .remindme file\n");
                exit(EXIT_FAILURE);
            }
            i ++;
            path = concat(argv[i], "/");
            path_specified = true;
        } else if (strcmp(argv[i], "-d") == 0) {
            delete = true;
        } else {
            if (delete) {
                printf("You cannot create a reminder and delete one in the same command\n");
                exit(EXIT_FAILURE);
            } else {
                text_specified = true;
                text = argv[i];
            }
        }
    }

    path = concat(path, ".remindme");

    // https://www.geeksforgeeks.org/c/format-specifiers-in-c/
    if (delete) {
        // https://www.geeksforgeeks.org/c/c-program-delete-file/
        if (remove(path) != 0) {
            printf("I couldn't delete any .remindme files at that path\n");
            exit(EXIT_FAILURE);
        }

    } else if (!text_specified) {
        // We are being asked to remind the user
        // https://stackoverflow.com/questions/12318866/relative-path-in-c-file-handling
        // https://www.geeksforgeeks.org/c/c-program-to-read-contents-of-whole-file/
        FILE *f = fopen(path, "r");

        if (f == NULL) {
            printf("I couldn't get any .remindme files in this directory\n");
            // https://www.tutorialspoint.com/c_standard_library/c_function_exit.htm
            exit(EXIT_FAILURE);
        }

        // https://stackoverflow.com/questions/174531/how-to-read-the-content-of-a-file-to-a-string-in-c
        // Seek to the end, get the length, and seek back to the start
        fseek(f, 0, SEEK_END);
        long length = ftell (f);
        fseek (f, 0, SEEK_SET);

        // Write to the buffer and close the file
        char *buffer = malloc (length);
        if (buffer)
        {
            fread (buffer, 1, length, f);
        }
        fclose (f);

        printf("%s\n", buffer);
    } else if (text_specified) {
        FILE *f = fopen(path, "w");

        if (f == NULL) {
            printf("I couldn't get any .remindme files in this directory\n");
            // https://www.tutorialspoint.com/c_standard_library/c_function_exit.htm
            exit(EXIT_FAILURE);
        }

        fprintf(f, "%s", text);
    }

    exit(EXIT_SUCCESS);
}
