
class Student:
    def __init__(self, ime, prezime):
        self.ime = ime 
        self.prezime = prezime
        self.godini = 19
    
    def add(self):
        print(self.ime, self.prezime)

studen1 = Student("Melanija", "Bogdanovska")
studen1.add()
print(studen1.godini)

