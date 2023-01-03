# class Person
# name, family, nationality
# print info
# instancii na class student 

# class Student naslesqva class person kato se dobavq 2 novi poleta
# print_info()

# class Lecturer, nasledqva class Person
# dobavq university i expirience
#print_info() da se predifinira da otpecatva tezi 2 poleta

class Person:
    def __init__(self, name, family, age, nationality):
        self.name = name 
        self.family = family 
        self.age = age 
        self.nationality = nationality

    def print_info(self):
        print(self.name, self.family, self.age, self.nationality)

class Student(Person):
    def __init__(self, name, family, age, nationality, year, university):
        super().__init__(name, family, age, nationality)
        self.year = year
        self.university = university     
    
    def print_info(self):
        print(self.year, self.university)

class Lecturer(Person):
    def __init__(self, name, family, age, nationality, university, expirience):
        super().__init__(name, family, age, nationality)
        self.university = university
        self.expirience = expirience

    def print_info(self):
        print(self.university, self.expirience)

p1 = Person("Vladimir", "Putin", 50, "russian")
s1 = Student("Ivan", "Vazov", 80, "bulgarian", 1, "TU-Sofia")
l1 = Lecturer("Daniela", "Gotseva", 30, "bulgarian", "TU-Sofia", 29)

l = (p1, s1, l1)
for el in l:
    el.print_info()