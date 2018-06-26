# here we are gonna create the output where we place all the cubes avaiable!
# here we imported the place cheking function and cube placing function from cube arrangement

import numpy as np
from itertools import permutations





def rotation_cube(tile,rotation):
    rotation = rotation

    rotated_cubes = []
    count = 1
    for i in range(rotation):


        if count ==1:
          row = len(tile)
          column = len(tile[0])
          tiles = tile
          #print(tiles)
          #print(" ")
        #print(count)
        if count ==2:
           row = len(rotated_cubes[0])
           column = len(rotated_cubes[0][0])
           tiles = rotated_cubes[0]
           #print(tiles)
          # print(" ")
        if count == 3:
            row = len(rotated_cubes[0][0])
            column = len(rotated_cubes[0])
            tiles = rotated_cubes[1]
            #print(tiles)
          #  print(" ")

        if count == 4:
            row = len(rotated_cubes[0])
            column = len(rotated_cubes[0][0])
            tiles = rotated_cubes[2]
           # print(tiles)


            #print(tiles)
        #print(row,column)
        matrix = np.zeros((column, row))
        #print(matrix)

        for i in range(row):
            for j in range(column):
                matrix[j][row - i-1] = tiles[i][j]
                 #print(matrix)
                 #  print(matrix)
        matrix = np.reshape(matrix,(column,row))
            #print(matrix)
        rotated_cubes.append((matrix))
        count = count+1
        #




    return rotated_cubes





def place_checker(board,row,column,cube):
    cube_row = len(cube)
    cube_column = len(cube[0])
    board_row_len = len(board)
    board_column_len  = len(board[0])
    count = 0


    for i in range(cube_row):
        for j in range(cube_column):
            if (row + cube_row) <= board_row_len:
                #print(row+cube_row,board_row_len)
                if (column + cube_column) <= board_column_len:
                   # print((column + cube_column),board_column_len)
                    if board[row +i][column+j]!=0:
                       # print((row + i),(column+j))
                        return False
                    else:
                        count = count +1



                else:
                    return "Column"

            else:
                return "Row"
   # print(count)
    if count >= 4:
        return True

def cube_placing(board, row, column, cube):
        board_row_len = len(board)
        board_column_len = len(board[0])
        cube_row_len = len(cube)
        cube_column_len = len(cube[0])

        for i in range(cube_row_len):
            for j in range(cube_column_len):
                if board[row + i][column + j] == 0:
                    board[row + i][column + j] = cube[i][j]

        return board




L_cube = [[1,0],
          [1,0],
          [1,1]]
#print(L_cube)
T_cube = [[0,2,0],
          [2,2,2]]
I_cube = [[3,3,3,3]]

O = [[5,5],
     [5,5]]
Z = [[6,6,0],
     [0,6,6]]
S  = [[0,7,7],
      [7,7,0]]

J_cube = [[0,8],
          [0,8],
          [8,8]]
cube = [L_cube,T_cube,I_cube,O,Z,S,J_cube]

cubes = []



p_cubes = permutations(cube,len(cube))

cubes.append(p_cubes)
#print(cubes)
#count =0
#for i in range(len(cubes)):
    #for j in cubes[0]:
        #print(j)
        #count +=1

#print(count)

permuted_cubes = []


for i in (cubes):
    for j in i:
      # print(j)
       permuted_cubes.append(j)

#print(permuted_cubes)
counting_cubes = 0
for l in range(len(permuted_cubes)):
   #print(l)

   board = np.zeros((14, 8))
   #print(permuted_cubes[l])
   for i in permuted_cubes[l]:
      # i = np.array(i)
       #print(i)
       for j in range(0,14):
            for k in range(0,8):
                if place_checker(board,j,k,i) == True:
                    checked_row = j
                    checked_column = k
       cube = cube_placing(board,checked_row,checked_column,i)
       #cube = cube_placing(cube,checked_row,checked_column,i)

   counting_no= 0

   for i in range(0,8):
       #print(counting_no)
       if cube[13][i] !=0:
           if cube[12][i] != 0:
               if cube[11][i] != 0:
                   counting_no += 1


       if counting_no == 8:
           counting_cubes +=1
           print(cube)
print(counting_cubes)

#rotation = rotation_cube(L_cube,2)
#print(rotation)

# so we have our 3 cubes  now lets place each of them in their place

