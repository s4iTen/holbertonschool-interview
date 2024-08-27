#!/usr/bin/python3
"""
Rotate 2D Matrix
"""


def rotate_2d_matrix(matrix):
    """
    Rotates a 2D matrix 90 degrees clockwise in-place.

    Args:
    - matrix: A 2D matrix (list of lists) to be rotated

    Returns: None (modifies the matrix in-place)
    """
    n = len(matrix)

    # Transpose the matrix
    for i in range(n):
        for j in range(i, n):
            matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]

    # Reverse each row of the transposed matrix
    for i in range(n):
        matrix[i].reverse()
