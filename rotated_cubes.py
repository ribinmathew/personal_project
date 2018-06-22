# here we are gonna make an algorithm where we will create all the possible rotations of each tile if we pass any tile

import numpy as np






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




L  = [[1,1],
        [1,0],
        [1,0]]


T =[[2,2,2],
    [0,2,0]]

I = [[3,3,3,3]]

J = [[0,4],
     [0,4],
     [4,4]]

O = [[5,5],
     [5,5]]

s = [[0,6,6],
     [6,6,0]]

Z = [[7,7,0],
     [0,7,7]]


#so we have done cube rotation

#print(len(tile))
#print(len(tile[0]))
tiles = rotation_cube(L,4)
