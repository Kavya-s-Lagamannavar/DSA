def quick_sort(arr):
    # Check if the array is empty or has only one element
    if len(arr) < 2:
        return arr

    # Initialize stack with the first and last index of the array
    stack = [(0, len(arr) - 1)]

    # Loop until the stack is empty
    while stack:
        # Pop the top element from the stack
        start, end = stack.pop()

        # Partition the subarray and get the pivot index
        pivot_index = partition(arr, start, end)

        # If there are elements to the left of the pivot, push their indices onto the stack
        if pivot_index - 1 > start:
            stack.append((start, pivot_index - 1))

        # If there are elements to the right of the pivot, push their indices onto the stack
        if pivot_index + 1 < end:
            stack.append((pivot_index + 1, end))

    return arr

def partition(arr, start, end):
    # Choose the rightmost element as the pivot
    pivot = arr[end]

    # Initialize the pivot index and the left pointer
    pivot_index = start
    left = start

    # Loop through the subarray
    for i in range(start, end):
        # If the current element is less than or equal to the pivot, swap it with the element at the left pointer
        if arr[i] <= pivot:
            arr[i], arr[left] = arr[left], arr[i]
            left += 1

        # Update the pivot index if the current element is equal to the pivot
        if arr[i] == pivot:
            pivot_index = i

    # Swap the pivot with the element at the left pointer
    arr[left], arr[end] = arr[end], arr[left]
    pivot_index = left

    return pivot_index
