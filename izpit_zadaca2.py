class Book:
    def __init__(self, book_name, book_code, book_price, book_year, book_author):
        self.book_name  = book_name 
        self.book_code  = book_code 
        self.book_price = book_price
        self.book_year  = book_year 
        self.book_author = book_author

    def __str__(self):
        return f"{self.book_code} {self.book_name} {self.book_price} {self.book_author} {self.book_year}"

    def __lt__(self, other):
        self.book_name < other.book_name

books = [
    Book("A1", 121, 12.34, 2022, "BC"),
    Book("A1", 124, 12.34, 2022, "BB"), 
    Book("A2", 125, 12.34, 2022, "BC"), 
    Book("A3", 120, 12.34, 2022, "AC") 

]

print()  