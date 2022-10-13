class Node :
    def __init__ (self, data, link=None):
        self.data = data
        self.link = link

class LinkedStack :
    def __init__(self):
        self.__top = None

    def push(self, data) -> None:
        nNode = Node(data, self.__top)
        self.__top = nNode

    def pop(self):
        if self.__top == None :
            return None
        temp = self.__top
        self.__top = temp.link
        return temp.data

    def peek(self):
        if self.__top == None :
            return None
        return self.__top.data

    def isEmpty(self) -> bool:
        return self.__top == None
    
    def printStack(self):
        temp = self.__top
        print('\n STACK [', end = ' ')
        while temp :
            print(temp.data, end = ' ')
            temp = temp.link
        print(']\n')
