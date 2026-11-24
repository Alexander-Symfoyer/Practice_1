import sys

randomlist=['a',0,2]

for entry in randomlist:
    try:
        print("The entry is",entry)
        r = 1/int(entry)
        break
    except:
        print("Oops!",sys.exc_info()[0],"occured.")
        print("Next entry.")
        print()
print("The reciprocal of",entry,"is",r)

try:
    x = int(input(">>"))
    y = int(input(">>"))
    print(x/y)
except ValueError:
    print("Error! Please re-enter NUMBER")
except ZeroDivisionError:
    print("Error! You can't enter 0")
except:
    print("ERROR !!!!!")


x = "hello"
assert x == "good bye","x should be 'hello'"

for i in range(10):
    assert i < 5,"Error"
    print(i)