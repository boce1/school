class Book:
    def __init__(self, name, code, price, year, author):
        self.book_name = name
        self.book_code = code
        self.book_price = price 
        self.book_year = year
        self.book_author = author

    def __repr__(self):
        return f"{self.book_name}"

def sort_name(l):
    n = len(l)
    out = [x for x in l]
    for i in range(n):
        for j in range(i + 1, n):
            if repr(l[j]) > repr(l[i]):
                out[i], out[j] = out[j], out[i]
    print(out) 

def author(l):
    n = len(l)
    d = dict()
    for i in range(n):
        d[l[i].book_author] = 0
    
    for i in range(n):
        d[l[i].book_author] += 1

    print(d)

def search_book(code):
    for book in books:
        if code == book.book_code:
            print(book.book_year)
            return
    print("The book is not found!")
    

authors = ["George Orwell", "Sharl Bodler", "William Shakespere", "Mark Twain"]
books = list()
for i in range(4):
    books.append(Book(f"name{i}", i, 10 + i * 10, 1984 + 1, authors[i]))

print(books)
sort_name(books)
print(books)