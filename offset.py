
#lets see what is off set


def offset(tile):
    for j in range(len(tile[0])):
        if tile[0][j] > 0:
            print(j)
            return -j
L = [[1, 1],
         [1, 0],
         [1, 0]]



tile = [
        [1, 1, 1],
        [1, 0, 0]    ]

print(offset(tile))
