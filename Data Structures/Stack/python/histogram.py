class stack:
    data = []
    def __init__(self):  # Constructor
        data = []  # list - instance vaiable
        self.top = -1  # top - instance variable

    def size(self):  # getter funciton - size
        return len(self.data)  # length - of data

    def peek(self):
        return self.data(self.top)
    def push(self,item):
        self.data.append(item)
        self.top += 1
    def pop(self):
        rev =  self.data.pop(self.top)
        self.top -= 1
        return rev
    def isEmpty(self):
        return len(self.data) == 0
    def display(self):
        print(self.data)

n = int(input())
s = stack()
a=[]
for i in range(0, n):
    a.append(int(input()))

var ,ans, mx, i = 0, 0, 0, 0

while i < len(a):

    if s.isEmpty() or