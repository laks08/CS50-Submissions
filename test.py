list1 = [22, 33, 43, 12, 26, 18, 47, 41]
list2 = ['Lavender', 22, 33, 43, 12, 26, 18, 47, 41]

a = set(list1)
b = set(list2[1:])

if a == b:
    print("The list1 and list2 are equal")
else:
    print("The list1 and list2 are not equal")