class Animal:
    n = 10

    def __init__(self, name):
        self.name = name
    def foo(self):
        print("I'm an animal.")

    @staticmethod
    def func():
        print("lol")

    @classmethod
    def f(cls):
        print(cls.n)

    def __repr__(self):
        return f"Animal {self.name}"

class Dog(Animal):
    def __init__(self, name):
        self.name = name

    def bark(self):
        print("bark")

a = Animal("Frank")
b = Dog("Fifi")

b.f()
#print(a.__repr__())
#print(b.__repr__())