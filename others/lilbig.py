level=5
arr=[i for i in range(1,2**(level))]
def minimax(node,level,curr,maxturn):
    if curr==level-1:
        return arr[node]
    elif maxturn:       
        return max(minimax((node*2)+1,level,curr+1,False),minimax((node*2)+2,level,curr+1,False))
    else:
        return min(minimax((node*2)+1,level,curr+1,True),minimax((node*2)+2,level,curr+1,True))
print(arr)
print(minimax(0,level,0,True))

'''
level = 5
scoresArr = [i for i in range(1, 2**(level))]
def minimax(nodeIndex, currentLevel, maxTurn, maxLevel):
  if currentLevel == maxLevel:
    return scoresArr[nodeIndex]
  elif (maxTurn):
    return max(minimax(nodeIndex*2+1, currentLevel + 1,  False, maxLevel), minimax(nodeIndex * 2 + 2, currentLevel + 1, False, maxLevel))
  else:
    return min(minimax(nodeIndex * 2 + 1, currentLevel + 1,  True, maxLevel), minimax(nodeIndex * 2 + 2, currentLevel + 1,  True, maxLevel))

print(scoresArr)
print(minimax(0, 0, True,level))

'''
    