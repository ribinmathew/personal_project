import numpy as np


tiles = [[1,1,1,1],]




#print(len(tiles))
# her we are creating a empty board of size `14x8

board = np.zeros((14,8))
print(board)
board_colum_len = len(board[0])
board_row_len = len(board)

tile_colum = len(tiles[0])
tile_row = len(tiles)
print(tile_row)
print(tile_colum)


colum =0
row = 0

if (colum + tile_colum) <= board_colum_len:
    if (row+tile_row) <= board_row_len:
        for i in range(tile_row):
         for j in range(tile_colum):

            print(i,j)
            if board[colum+i][row+j] == 0:

                board[row+i][colum+j] = tiles[i][j]





print(board)

# now we are gonna loop through each point in the board and check any thing is placed over there o
            #now we are gonna place each tile in to the matrix
            #for that we are gonna loop through all the tiles


#so we are defining a function to check whether the cube sit on the position or not
# how we are gonna do it
