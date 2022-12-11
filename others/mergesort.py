


board=[
[0,0,0,0,0,0,0,0],
[0,0,0,0,0,0,0,0],
[0,0,0,0,0,0,0,0],
[0,0,0,0,0,0,0,0],
[0,0,0,0,0,0,0,0],
[0,0,0,0,0,0,0,0],
[0,0,0,0,0,0,0,0],
[0,0,0,0,0,0,0,0]]
n=8
def isattack(i,j):
    for k in range(0,n):
        if board[i][k] ==1 or board[k][j] ==1:
            return True
    for k in range(0,n):
        for l in range(0,n):
            if (k+l==i+j) or (k-l==i-j):
                if board[k][l]==1:
                    return True
    
    return False


def nqueen(N):
    if N==0:
        return True
    for i in range(0,n):
        for j in range(0,n):
            if not (isattack(i,j)) and (board[i][j]!=1):
                board[i][j]=1

                if nqueen(N-1)==True:
                    return True
                board[i][j]=0
    return False

nqueen(8)
for i in range(0,8):
    print(board[i])