n = input().split()
num = input().split()
x=0
i=0
print (n)
while i<n:
    temp=input().split()
    x=x*num+temp
    i=i+1
n=input().split()
num=input().split()
y=0
i=0
while i<n:
    temp=input().split()
    y=y*num+temp
    i=i+1
if x<y:
    print ('<')
elif x==y:
    print ('=')
else:
    print ('>')