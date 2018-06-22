#so we are gonna redo the entire thing ones again

# so what we have  to do is create a program for finding out the best combination for arranging the cubes in the box
# so we have to plce the cubes in the box!
# first we are gonna create and add the given cube to that box in all possible ways



import numpy as np

# now lets create a matrices of zeros (14,8)

board = np.zeros((14,8))
board_row_len = len(board)
board_column_len = len(board[0])

# we created a board with all  the positions as empty
# now we have to add the cube which is given to the position
# we have to consider things like given below
# 1 -cubes must be placed from left to right
# 2 - cubes should not over lap another cube
# 3 - cubes should not over lap the board

L_cube = [[1,1],
          [1,0],
          [1,0]]
row = 0
column = 1

for i in range(len(L_cube)):
    for j in range(len((L_cube[0]))):
        #print(i,j)
        #so lets add the cube to the board
        board[row+i][column+j] = L_cube[i][j]

print(board)

# here we have added the cube into the board first row and column
# here we have to find out any of the current position of the cube in board is been occupied or not!
# to find that out we have to run a for loop checking the position values on board for each position in cube
for columns in range(0,8):
    for i in range(len(L_cube)):
        for j in range(len(L_cube[0])):
            if (row+i) < board_row_len :
                if (columns+j) < board_column_len:
                   if board[row+i][columns+j] != 0:
                       space = row+i,columns+j
                       #print(space)
# so now we have to create a function which takes row number and tells us whether the cube is gonna fit there or not
# how we do it? check the place where we want to place already occupied or not!
# if it is occupied add one more row and check again, and again so we can know that whether we can place that cube on the position


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

#print(place_checker(board,0,3,L_cube))

for i in range(0,8):
    result = place_checker(board,0,i,L_cube)
    if result == True:
        print(i)
    if result =="Column":
        break
    else:
        print(result)


#now we have to create a function to place the cube in the board

def cube_placing(board,row,column,cube):
    board_row_len = len(board)
    board_column_len =len(board[0])
    cube_row_len =len(cube)
    cube_column_len =len(cube[0])

    for i in range(cube_row_len):
        for j in range(cube_column_len):
            board[row+i][column+j] = cube[i][j]


    return  board



#print(cube_placing(board,0,3,L_cube))

#now we are gonna create a function for rotating the cubes

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



# here we have to get the cube with all rotations and then place each of thm into the board and get the returning board
rotated_cube_L = rotation_cube(L_cube,4)
for i in rotated_cube_L:
    board = np.zeros((14,8))
    cube_placed_board = cube_placing(board,0,0,i)
    print(cube_placed_board)