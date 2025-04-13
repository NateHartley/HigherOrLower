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

    int INTSIZE = sizeof(int);
    // = 4 bytes

    int STRINGSIZE = sizeof(char)+1;
    // = 1 byte + 1 byte (null space)
    
    srand(time(NULL));
    // Setting seed for rand

    int *rand_num1 = malloc(INTSIZE);
    int *rand_num2 = malloc(INTSIZE);
    // Malloc returns a pointer, so the type needs to be int* not int
    // Size of an int is 4 bytes

    char* usr_input = malloc(STRINGSIZE);
    // Allocated 2 bytes, 1 byte for the user input (h or l), and one byte for the null character. If we only set malloc to be 1 then only the null char will be stored there
    // Reserved a memory size of 2 on the heap for this var, which means that piece of memory will always be available for this var, however I can still write into another memory address if this var is greater that the allocated memory size
    // Prevention of buffer overflow does not happen during malloc, it happens when you use the var in other functions e.g. fgets

    char* yes_no = malloc(STRINGSIZE);

    int *score = calloc(1, INTSIZE);
    // calloc works the exact same as malloc but zeros the data at that memory address, whereas if you use malloc then immediately return whatever is in there, you might get random garbage
    // so here we can use it to instantly set the value of score to 0

    while(1){
        printf("The program will pick two random numbers between 0 and 10... \n");
        *score = 0;

        while(1){

            if (*score > 0) {
                printf("The program is picking a new set of random numbers...\n");
            }
    
            *rand_num1 = rand() % 10 + 1;
            *rand_num2 = rand() % 10 + 1;
            // Generate a random number between 0 and 10 and assign it to the memory addresses of rand_num1 and rand_num2
    
            printf("The first number is: %d \n", *rand_num1);
            // Have to specify * before rand_num1 so that we are derefencing the pointer rand_num1 so we get the actual value stored at that memory address
    
            printf("\nWill the second number be higher [h] or lower [l] than the first? \n");
            printf(">> ");
    
            if (fgets(usr_input, STRINGSIZE, stdin) != NULL){
            // Takes in a user input from the standard input (terminal), last character appended is a null character '\0'
            // E.g. size = 5, input = 'hello', output of that var = 'hell\0', output in terminal will look like = 'hell'
            // Limited to a input size of 2 which is either 'h' or 'l' and the auto null character '\0'
            // fgets also overwrites what is already in usr_input
    
                discard(usr_input);
                // We can allocate a certain number of input characters to a variable in fgets, but if we write more than this then it won't affect the current variable, but it will affect other stuff
                // These extra input characters are still in the standard input (terminal), they won't just disappear so this will bleed into other fgets unless we discard these overflow characters
    
            }
            printf("\n");
            
            if (strcmp(usr_input, "h") == 0 || strcmp(usr_input, "l") == 0) {
                // strcmp compares strings, since every string is a char* we can just use usr_input and "h" with no *
                // h and l have to be surrounded in double speak marks to make them literal strings, not literal chars
    
                if (*rand_num1 < *rand_num2 && strcmp(usr_input, "h") == 0) {
                    // Need to dereference rand_num with * to get actual value
    
                    printf("Correct! The second number, %d, is higher than the first, %d \n", *rand_num2, *rand_num1);
                    printf("+100 points\n");
                    *score = *score + 100;
    
                } else if (*rand_num1 > *rand_num2 && strcmp(usr_input, "h") == 0){
                    printf("Incorrect... The second number, %d, is lower than the first, %d \n", *rand_num2, *rand_num1);
                    break;
    
                } else if (*rand_num1 > *rand_num2 && strcmp(usr_input, "l") == 0){
                    printf("Correct! The second number, %d, is lower than the first, %d \n", *rand_num2, *rand_num1);
                    printf("+100 points\n");
                    *score = *score + 100;
    
                } else if (*rand_num1 < *rand_num2 && strcmp(usr_input, "l") == 0){
                    printf("Incorrect... The second number, %d, is higher than the first, %d \n", *rand_num2, *rand_num1);
                    break;
    
                } else {
                    printf("They are the same!\n");
                    printf("No points added\n");
                }
            } else {
                printf("This is not a valid input\n");
                break;
            }
            printf("\n");
    
        }

        printf("\nGAME OVER - You finished the game with %d points\n", *score);

        printf("\nPlay again? (y/n) \n");
        printf(">>");

        if (fgets(yes_no, STRINGSIZE, stdin) != NULL){
            discard(yes_no);
        }
        printf("\n");

        if (strcmp(yes_no, "y") == 0 || strcmp(yes_no, "n") == 0) {
            if (strcmp(yes_no, "n") == 0) {
                printf("Thanks for playing!\n");
                break;
            }
        } else {
            printf("This is not a valid input\n");
            break;
        }

    }
    
    free(usr_input);
    free(rand_num1);
    free(rand_num2);
    free(yes_no);
    free(score);
    // Free the variables once there is no more use for it to release its allocated memory and prevent a memory leak

    return 0;
    // main function is an int so need to return 0 afterwards to specify that the function ran without error
}
