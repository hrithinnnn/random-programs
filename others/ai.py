

def dfs(i,level,h):
        if level<h:
            if visited[i]==0:
                visited[i]=1
                print(i)
                for j in g[i]:
                    dfs(j,level+1,h)
g={1:[2,3],2:[4,5],3:[6,7],4:[],5:[],6:[],7:[]}

for i in range(1,4):
    visited= [0 for i in range(8)]
    dfs(1,0,i)
    print("\n")
    

