#include <stdio.h>

/*Returns 1 if `c` is hexadecimal-like char, and 0 if it isn't.*/
int isHEX(char c);

/*Converts hexadecimal number to decimal.*/
int hex2int(char c);

/*Converts hexadecimal number with 2 digits to char's ASCII code.*/
int hex2ascii(char c, char d);

/*Gets space delimited char input and "encodes" it in ASCII codes view.*/
int encode();

/*Gets space delimited ASCII codes input and "decodes" it in normal char view.*/
int decode();

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("n/a\n");
        return 1;
    }

    int mode;
    sscanf(argv[1], "%d", &mode);

    if (mode) {
        decode();
    } else {
        encode();
    }

    return 0;
}

int isHEX(char c) { return (c >= '0' && c <= '9') || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F'); }

int hex2int(char c) {
    int first = c / 16 - 3;
    int second = c % 16;
    int result = first * 10 + second;
    if (result > 9) result--;

    return result;
}

int hex2ascii(char c, char d) {
    //! Boundary case: c and/or d are not hexadecimal
    if (!isHEX(c) || !isHEX(d)) {
        return 0;
    }

    int high = hex2int(c) * 16;
    int low = hex2int(d);

    return high + low;
}

int encode() {
    // Variables initialize
    char letter = '\0';
    char space_like = '\0';

    // Flag that indicates the first letter being processed
    int first = 1;

    // Flag that indicates if there are errors
    int error = 0;

    while (1) {
        // Getting 1st symbol in the loop
        letter = getchar();

        //! Special case: letter is a space or a whitespace
        error = letter == ' ' ? 1 : 0;
        if (letter == ' ' || letter == '\n') {
            break;
        }

        // Getting space_like char (2rd symbol in the loop)
        space_like = getchar();

        //! Special case: space_like is not whitespace or space
        if (space_like != ' ' && space_like != '\n') {
            error = 1;
            break;
        }

        //! Flag trigger: if it's not the first code, leave a space before it
        if (first) {
            printf("%X", letter);
            first = 0;
        } else {
            printf(" %X", letter);
        }

        // If space_like char is whitespace, then loop is over without errors
        if (space_like == '\n') {
            break;
        }
    }

    if (error) {
        printf("n/a\n");
    }

    return error;
}

int decode() {
    // Variables initialize
    char char1 = '\0';
    char char2 = '\0';
    char space_like = '\0';
    char letter = '\0';

    // Flag that indicates the first letter being processed
    int first = 1;

    // Flag that indicates if there are errors
    int error = 0;

    while (1) {
        // Getting 1st symbol in the loop
        char1 = getchar();

        //! Special case: char1 is a space or a whitespace
        error = char1 == ' ' ? 1 : 0;
        if (char1 == ' ' || char1 == '\n') {
            break;
        }

        // Getting 2nd symbol in the loop
        char2 = getchar();

        //! Special case: char2 is a space or a whitespace
        error = char2 == ' ' ? 1 : 0;
        if (char2 == ' ' || char2 == '\n') {
            break;
        }

        // Getting space_like char (3rd symbol in the loop)
        space_like = getchar();

        // Obtaining normal char from ASCII HEX code
        letter = (char)hex2ascii(char1, char2);

        //! Special case: space_like is not whitespace or space
        if (space_like != ' ' && space_like != '\n') {
            error = 1;
            break;
        }

        //! Special case: char2 is not a character
        if (char1 == ' ' || char2 == ' ') {
            error = 1;
            break;
        }

        //! Special case: char1 and/or char2 are not hexadecimal
        if (!letter) {
            error = 1;
            break;
        }

        //! Flag trigger: if it's not the first letter, leave a space before it
        if (first) {
            printf("%c", letter);
            first = 0;
        } else {
            printf(" %c", letter);
        }

        // If space_like char is whitespace, then loop is over without errors
        if (space_like == '\n') {
            break;
        }
    }

    if (error) {
        printf("n/a\n");
    }

    return error;
}
