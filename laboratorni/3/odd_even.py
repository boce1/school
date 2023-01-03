def even_nums(l):
    return [x for x in l if x % 2 == 0] 

def odd_nums(l):
    return [x for x in l if x % 2 != 0] 
    
def nums(l):
    result = list()
    result.append(even_nums(l))
    result.append(odd_nums(l))
    return result

ls = list(map(int, input("Enter the list and separate the numbers with spaces: ").split()))
print(nums(ls))