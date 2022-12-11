
level = 3
scoresArr = [i for i in range(1, 2**(level))]
def minimax(nodeIndex, currentLevel, maxTurn, maxLevel):
  if currentLevel == maxLevel:
    return scoresArr[nodeIndex]
  elif (maxTurn):
    return max(minimax(nodeIndex * 2 + 1, currentLevel + 1, False, maxLevel), minimax(nodeIndex * 2 + 2, currentLevel + 1, False, maxLevel))
  else:
    return min(minimax(nodeIndex * 2 + 1, currentLevel + 1, True, maxLevel), minimax(nodeIndex * 2 + 2, currentLevel + 1, True, maxLevel))

print(scoresArr)
print(minimax(0, 0,True,2))
