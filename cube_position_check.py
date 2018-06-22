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

    for i in range(tile_row):
        for j in range(tile_colum):
            if (tile[i][j] >0 and matrix[row+i][colum+j]>0):
                return False
    return True


def placeTile(mat,tile,board_row,board_column,):
    rows = board_row
    column = board_column
    tiles = tile
    tile_row = len(tiles)
    tile_column = len(tiles[0])
    matrix = copy.deepcopy(mat)
    matrix_row = len(matrix)
    matrix_column = len(matrix[0])
    if (board_row + tile_row) > matrix_row or board_row < 0:
        raise ValueError("Row is out of bound")
    if (board_column+ tile_column) > matrix_column or board_column < 0:
        raise ValueError("Column is out if bound")


    for i in range(tile_row):
        for j in range(tile_column):
            matrix[rows+i][column+j] += tiles[i][j]
    return matrix





matrix = np.zeros((14,8))

T =[[2,2,2],
    [0,2,0]]

L  = [[1,1],
      [1,0],
      [1,0]]

for i in range(0,8):
    position = placeTile(matrix, T, 1, i, )
    print(position)


"""
print((position))
for i in range(0,8):
    for j in range(0,14):
        positoin1 = position_check(matrix,j,i,L)
        print(positoin1)

#print(positoin1)
"""