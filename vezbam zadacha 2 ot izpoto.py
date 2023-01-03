class Book:
    def __init__(self, name, code, year, author, price):
        self.book_name = name
        self.book_code = code
        self.book_year = year
        self.book_author = author
        self.book_price = price

    def __repr__(self):
        return f"{self.book_name} {self.book_code} {self.book_author} {self.book_year} {self.book_price}"

books = [
    Book("1984", 1, 1984, "Gorge Orwell", 50),
    Book("Lord of the rings", 2, 1980, "Tolkin", 50),
    Book("Geracite", 3, 1960, "Elin Pelin", 50),
    Book("Robinson Kruso", 3, 1800, "Daniel Defo", 50)
]

def sort_name(l):
    n = len(l)
    for i in range(n):
        for j in range(i, n):
            if l[j].book_name < l[i].book_name:
                temp = l[j]
                l[j] = l[i]
                l[i] = temp
    return l

def author(l):
    authors = dict()
    for el in l: # books
        authors[el.book_author] = []

    for el in l:
        authors[el.book_author].append(el.book_name)

    return authors

def search_book(l, code):
    for el in l:
        if el.book_code == code:
            return el.book_year
    return "The book is not found!"

print(books)
sort_name(books)
print(books)
print()

print(author(books))
print()

print(search_book(books, 2))
print(search_book(books, 5))
