#here we have to create all the permutations including the rotated cubes
#so first we have to create a list of permutations with rotated cubes for each!


from itertools import permutations
import numpy as np
import itertools

def rotation_cube(tile,rotation):


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
       # print(matrix)
             #print(matrix)
        rotated_cubes.append(matrix)
        count = count+1
        #




    return rotated_cubes[-1]


L_cube = [[[1,0],
          [1,0],
          [1,1]],4]
#print(L_cube)
T_cube = [[[0,2,0],
          [2,2,2]],4]
I_cube = [[[3],[3],[3],[3]],2]

O = [[[5,5],
     [5,5]],1]
Z = [[[6,6,0],
     [0,6,6]],2]
S  = [[[0,7,7],
      [7,7,0]],2]

J_cube = [[[0,8],
          [0,8],
          [8,8]],4]
cube = [L_cube,T_cube,I_cube,O,S,J_cube]

rotated_cube_list = []

"""
for j in cube:
    #print(j[0])
    #print(j[1])
    rotated_cubes = rotation_cube(j[0],j[1])
    rotated_cube_list.append([rotated_cubes])

   # rotated_cube_list.append(rotated_cubes)



#per =   itertools.chain(itertools.product(l_cube, t_cube), itertools.product(t_cube, l_cube))

per_cube= []
#for i in per:
#    per_cube.append([i])
    #print(i)

print(per_cube[3])
#print(t_cube[0])
#print(l_cube[0])

for i in range(len(rotated_cube_list)):
    for j in range(len(rotated_cube_list[i][0])):
        print(rotated_cube_list[i][0][j])
        print(" ")
"""
r = rotation_cube(L_cube[0],4)
print(r)