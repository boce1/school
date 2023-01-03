class B:
    def check_bracket(self, s):
        if s.count("(") != s.count(")") or \
             s.count("[") != s.count("]") or \
                s.count("{") != s.count("}"):
                return False

        temp = "".join(s.split())
        n = len(temp)
        flag2 = True
        for i in range(n):
            if i < n - 1:
                if temp[i] == "(" and temp[i + 1] != ")" or\
                    temp[i] == "[" and temp[i + 1] != "]" or\
                        temp[i] == "{" and temp[i + 1] != "}":
                        flag2 = False
                        break
        return flag2

b1 = B()
print(b1.check_bracket("[] (){}{} ()  {}"))
