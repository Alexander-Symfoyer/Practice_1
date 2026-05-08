arr = [1,2,2,3,3,3,4,4,4,4]

arr.append(5)
print(arr)

arr.insert(0,100)
print(arr)

arr.pop(8)
print(arr)

arr.remove(3)
print(arr)

arr.sort()
print(arr)

arr.reverse()
print(arr)

arr.clear()
print(arr)

arr = [1,2,2,3,3,3,4,4,4,4,4]

print(len(arr))
print(arr.count(4))
print(min(arr))
print(max(arr))
print(sum(arr))
print(5 in arr)
print(2 in arr)

s = "How are you"
arr = s.split()
print(arr)

f = "10,500,050"
arr = f.split(',')
print(arr)

numbers = [int(x) for x in input("Enter : ").split()]
print(numbers)