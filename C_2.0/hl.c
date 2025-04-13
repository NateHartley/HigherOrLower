#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void discard(char* input) {
    // Prevents overflow characters from bleeding into other fgets when extra characters are still on the standard input
    // Should be used everytime fgets is called

    if (strchr(input, '\n') == NULL) {
        // If new line character cannot be found in input string because too much has been written into the input var and so the new line character is outside of this variable and still on the standard input

        while(getchar() != '\n');
        // Read the input stream byte, if it is not a new line character then do nothing with it and move on to the next byte
        // Exit once it reaches the new line character (indicating end of input stream)
    }

}


int main() {
    printf("The program will pick two random numbers between 0 and 10... \n");

    srand(time(NULL));
    // Setting seed for rand

    int* rand_num1 = malloc(sizeof(int));
    int* rand_num2 = malloc(sizeof(int));
    // Malloc returns a pointer, so the type needs to be int* not int
    // Size of an int is 4 bytes

    *rand_num1 = rand() % 10 + 1;
    *rand_num2 = rand() % 10 + 1;
    // Generate a random number between 0 and 10 and assign it to rand_num1 and rand_num2

    printf("The first number is: %d \n", *rand_num1);
    printf("Debug: %d \n", *rand_num2);

    printf("Will the second number be higher [h] or lower [l] than the first? \n");
    printf(">> ");

    // TODO: implement comparison of usr_input and rand_num2

    char* usr_input = malloc(2);
    // Allocated 2 bytes, 1 byte for the user input (h or l), and one byte for the null character. If we only set malloc to be 1 then only the null char will be stored there
    // Reserved a memory size of 2 on the heap for this var, which means that piece of memory will always be available for this var, however I can still write into another memory address if this var is greater that the allocated memory size
    // Prevention of buffer overflow does not happen during malloc, it happens when you use the var in other functions e.g. fgets

    if (fgets(usr_input, 2, stdin) != NULL){
    // Takes in a user input from the standard input (terminal), last character appended is a null character '\0'
    // E.g. size = 5, input = 'hello', output of that var = 'hell\0', output in terminal will look like = 'hell'
    // Limited to a input size of 2 which is either 'h' or 'l' and the auto null character '\0'

        discard(usr_input);
        // We can allocate a certain number of input characters to a variable in fgets, but if we write more than this then it won't affect the current variable, but it will affect other stuff
        // These extra input characters are still in the standard input (terminal), they won't just disappear so this will bleed into other fgets unless we discard these overflow characters

    }
    
    printf("print usr_input >  %s \n", usr_input);
    
    free(usr_input);
    free(rand_num1);
    free(rand_num2);
    // Free the variables once there is no more use for it to release its allocated memory and prevent a memory leak




    int TEST_SIZE = 5;
    char test_string[TEST_SIZE]; // allocated on stack
    
    fgets(test_string, TEST_SIZE, stdin);

    printf("test>> %s \n", test_string);


}


/*

- Choose random number 1
- Choose random number 2
- Ask user if 1 is higher or lower than 2
- If correct, award points, pick another two random numbers, loop
- If wrong, print total points, end

*/