numbers = []
numbers.append(int(input()))
numbers.append(int(input()))
numbers.append(int(input()))

command = input()

print("Input number 1 stored.")
print("Input number 2 stored.")
print("Input number 3 stored.")

if command == "1":
    number_string = [str(x) for x in numbers]
    print("Original order: " + " ".join(number_string))
elif command == "2":
    numbers.sort(reverse = True)
    number_string = [str(x) for x in numbers]
    print("Descending order: " + " ".join(number_string))
elif command == "3":
    numbers.sort()
    number_string = [str(x) for x in numbers]
    print("Ascending order: " + " ".join(number_string))