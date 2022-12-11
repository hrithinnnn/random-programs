n1=input("enter first persons name: ")
n2=input("enter second persons name: ")

l=len(n1)+len(n2)

flames={
    'f':"friends :(",
    'l':"lovers ooooo",
    'a':"affectionate :/",
    'm':"gonna marry lesgooo",
    'e':"enemies :)",
    's':"gonna bang lmfaooo"
}

str=['f','l','a','m','e','s']
for i in n1 and n2:
    l=l-2

while len(str)>1:
    x=len(str)
    y=l%x
    str.remove(str[y-1])
print(f'{n1} and {n2} are {flames.get(str[0])}')
#print(flames.get(str[0]))

