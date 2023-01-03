def scope_test():
    def do_local():
        spam = "local scope"
        def do_inner():
            nonlocal spam
            spam = "inner"
        do_inner()
        print(spam)

    def do_nonlocal():
        nonlocal spam
        spam = "nonlocal scope"

    def do_global():
        global spam
        spam = "global scope"
    
    spam = "test"
    #do_local()
    do_global()
    print(f"local spam: {spam}")


scope_test()
print(spam)