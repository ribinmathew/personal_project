#here we are gonna check the position of the cube whether it overlaps or not

import numpy as np
import copy


def position_check(mat,board_row,board_colum,tile):
    row = board_row
    colum = board_colum
    tile_row = len(tile)
    tile_colum = len(tile[0])
    matrix = copy.deepcopy(mat)
    matrix_row = len(matrix)
    matrix_colum = len(matrix[0])


    if (board_row + tile_row) > matrix_row or board_row < 0 :
        return False
    if (board_colum + tile_colum) > matrix_colum or board_colum < 0:
        return False
    else:
        for i in range(tile_row):
            for j in range(tile_colum):
                if matrix[row+i][colum+j] == 0:
                    matrix[row+i][colum+j] = tile[i][j]
        return  matrix






matrix = np.zeros((14,8))
T = [[1,1],
    [1,0],
    [1,0]]

positoin = position_check(matrix,0,0,T)
print(positoin)