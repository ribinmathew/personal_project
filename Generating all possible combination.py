# here we are going to generate all the possible combination that can be generated from 2 cubes first

import numpy as np
from itertools import permutations
from itertools import combinations


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
#print(cubes[6][1])

l = [0,1]
j = [2,4,11,21]
T = [8,6]
count =0
loop = [l,j,T]



#shift = permutations(loop,2)
count= 0
ppt = ("l1","l2","l3","l4","j1","j2","j3","j4","t1","t2","t3","t4","o","I1","I2","s1","s2","z1","z2")
permutation = [("l1","j1","t1","o","i1","s1","z1"),("l2","j1","t1","o","i1","s1","z"),("l3","j1","t1","o","i1","s1","z1"),("l4","j1","t1","o","i1","s1","z1")]

shifts = []
for i in range(len(permutation)):
    shift = permutations(permutation[i],4)
    shifts.append(shift)



#for i in range(len(shifts)):
 #   print(shifts[i])
count  = 0

#print(count)

#print(shifts[0])
print(len(shifts))
for i in range(len(shifts)):
    for i in shifts[i]:
        print(i)
        count += 1

print(count)


# at last we reached a stage where we are pretty sure that permutations wont work!
# the reason is simple if you go for the permutation its gonna be a huge number!
# so we have to just loop through what ever cube we have and produce the op by placing each cube