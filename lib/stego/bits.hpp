#ifndef BITS_HPP
#define BITS_HPP

#include <QBitArray>
#include <numeric>

/**
 * @href https://wiki.qt.io/Working_with_Raw_Data
 */
QBitArray toBitArray(const QByteArray &array);
QByteArray toByteArray(const QBitArray &array);

char changeBit(char byte, bool bit, int position = 0);

void copy(const QByteArray &src, QByteArray &dst);

#endif // BITS_HPP
