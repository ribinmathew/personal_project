import numpy as np


def check_row_full(matrix, row,column):
    row = row
    column = column
    matrix = matrix
    for i in range(0,14):
        if matrix[column][i] == 0:
            print("row is not full",)
            return False
        else:
            return True



