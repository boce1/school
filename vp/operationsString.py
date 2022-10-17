def num_rows(text):
    return "Number of rows: {0}".format(text.count("\n") + 1)

def num_words(text):
    n = txt.count(" ") 
    if text[-1] != " ":
        n += 1
    return n

def first_letter_upper(text):
    output = ""
    n = len(text)
    for i in range(n):
        if i == 0 or text[i - 1] == " ":
            output += text[i].upper()
        else:
            output += text[i]
    return output

txt = input("Enter text:\n")

print(first_letter_upper(txt))
