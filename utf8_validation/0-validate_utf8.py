#!/usr/bin/python3
"""UTF-8 Validation"""


def validUTF8(data):
    """Returns True if data is UTF-8 encoded"""
    def is_start_byte(byte):
        return (byte >> 6) == 0b10

    i = 0
    while i < len(data):
        byte = data[i]

        length = 0

        if (byte >> 7) == 0:
            i += 1
        elif (byte >> 5) == 0b110:
            length = 2
            i += 1
        elif (byte >> 4) == 0b1110:
            length = 3
            i += 1
        elif (byte >> 3) == 0b11110:
            length = 4
            i += 1
        else:
            return False

        for j in range(length - 1):
            if i >= len(data):
                return False
            if not is_start_byte(data[i]):
                return False
            i += 1

    return True
