int is_valid = 0;
int user_input = /* some input value */;

if (user_input == 1) {
    is_valid = 1;
} else if (user_input < 0 || user_input > 1) {
    printf("Input is not valid.\n");
    return;
}

if (is_valid) {
    printf("Input is valid.\n");
} else {
    printf("Input is not valid.\n");
}