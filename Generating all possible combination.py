# here we are going to generate all the possible combination that can be generated from 2 cubes first

import numpy as np

# function for creating rotated cube
def rotation_cube(cube,rotation):
    rotation = rotation

    rotated_cubes = []
    count = 1
    for i in range(rotation):


        if count ==1:
          row = len(cube)
          column = len(cube[0])
          cubes = cube

        if count ==2:
           row = len(rotated_cubes[0])
           column = len(rotated_cubes[0][0])
           cubes = rotated_cubes[0]

        if count == 3:
            row = len(rotated_cubes[0][0])
            column = len(rotated_cubes[0])
            cubes= rotated_cubes[1]


        if count == 4:
            row = len(rotated_cubes[0])
            column = len(rotated_cubes[0][0])
            cubes = rotated_cubes[2]

        matrix = np.zeros((column, row))


        for i in range(row):
            for j in range(column):
                matrix[j][row - i-1] = cubes[i][j]

        matrix = np.reshape(matrix,(column,row))

        rotated_cubes.append((matrix))
        count = count+1
        #
    return rotated_cubes



# now we have to define all the cubes  available




O = [[[1, 1],
     [1, 1]],2]

L = [[[1, 1, 1],
     [1, 0, 0]],4]

J= [ [[1, 0, 0],
    [1, 1, 1]],4]

T = [ [[1,1,1],
      [0,1,0]],4]

I = [[[1,1,1,1]],2]

Z = [[[1,1,0],
    [0,1,1]],2]


S =[ [[0,1,1],
    [1,1,0]],2]

#print(O[0])



list = (O,L,J,T,I,Z,S)
cubes =  []
for i in list:
    #print(i)
    rotated_cubes = rotation_cube(i[0],i[1])
    cubes.append(rotated_cubes)

for i in range(len(cubes)):
    for j in range(len(cubes[0])):
        print(cubes[i][j])
        print(" ")
for i in range(len(cubes)):
    print(len(cubes[i]))
print(cubes[6][0])
print(cubes[6][1])