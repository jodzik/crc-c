#include <crc32.h>

#include <stdio.h>
#include <string.h>

static int check_crc(char const* const name, uint8_t const* const data, size_t const size, uint32_t const expected) {
    uint32_t const crc = crc32__ieee(data, size);

    if (crc != expected) {
        fprintf(stderr, "%s: crc32__ieee() = 0x%08X, expected 0x%08X\n", name, crc, expected);
        return -1;
    }

    printf("%s: 0x%08X OK\n", name, crc);

    return 0;
}

int main(void) {
    int rc = 0;
    int check = 0;

    uint8_t const check_data[] = "123456789";
    uint8_t const zeros[16] = {0};
    uint8_t const abc[] = "abc";

    // NULL и пустой буфер.
    check = check_crc("null", NULL, 0, 0);
    if (0 != check) rc = check;

    check = check_crc("empty", check_data, 0, 0);
    if (0 != check) rc = check;

    // Классический CHECK вектор CRC-32/ISO-HDLC.
    check = check_crc("123456789", check_data, sizeof(check_data) - 1, 0xCBF43926u);
    if (0 != check) rc = check;

    // "abc" -> 0x352441C2.
    check = check_crc("abc", abc, sizeof(abc) - 1, 0x352441C2u);
    if (0 != check) rc = check;

    // 16 нулей -> 0xECBB4B55.
    check = check_crc("zeros16", zeros, sizeof(zeros), 0xECBB4B55u);
    if (0 != check) rc = check;

    if (0 == rc) {
        printf("All tests passed\n");
    } else {
        fprintf(stderr, "Tests FAILED\n");
    }

    return rc;
}
