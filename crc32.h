#ifndef CRC32_H_
#define CRC32_H_

#include <stdint.h>
#include <stddef.h>

#ifdef __ZEPHYR__

#include <zephyr/sys/crc.h>

/// Реализация через crc32_ieee() подсистемы CRC Zephyr.
#define crc32__ieee crc32_ieee

#else /* __ZEPHYR__ */

/// @brief Вычислить CRC32 (IEEE 802.3, полином 0xEDB88320 отражённый, init/xorout 0xFFFFFFFF).
/// @param data - буфер с данными.
/// @param len - размер данных в байтах.
/// @return Значение CRC32. Для NULL или len == 0 возвращается 0.
uint32_t crc32__ieee(uint8_t const* const data, size_t const len);

#endif /* __ZEPHYR__ */

#endif // CRC32_H_
