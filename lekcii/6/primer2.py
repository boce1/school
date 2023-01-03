class Parent:
    pass

class Child(Parent):
    i = 100 # class/static variable

    def __init__(self): # constructor
        self.x = 200 # instance variable
    

    def f(): # class/static method
        return "hi OPP"

    def ff(self): # instance method 
        return self.x

c1 = Child()
print(c1.ff())