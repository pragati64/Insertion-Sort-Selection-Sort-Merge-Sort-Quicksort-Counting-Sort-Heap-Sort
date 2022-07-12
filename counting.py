def count(arr):
    size = len(arr)
    output = [0] * size

    count = [0] * 10

    for i in range(0, size):
        count[arr[i]] += 1

    for i in range(1, 10):
        count[i] += count[i - 1]

    i = size - 1
    while i >= 0:
        output[count[arr[i]] - 1] = arr[i]
        count[arr[i]] -= 1
        i -= 1

    for i in range(0, size):
        arr[i] = output[i]


data = [5, 0, 9, 8, 2, 3, 1]
count(data)
print("Sorted array in Ascending Order: ")
print(data)
