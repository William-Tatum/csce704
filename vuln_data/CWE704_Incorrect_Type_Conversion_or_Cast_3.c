#include <stdio.h>
#include <stdint.h>

int main() {
    int32_t num = -1;
    uint32_t u_num = (uint32_t)num;
    printf("Converted value: %u\n", u_num);
    return 0;
}