def permute(nums):
    # Base case: If nums is empty, return an empty list
    if len(nums) == 0:
        return []

    # Base case: If nums has only one element, return that element in a list
    if len(nums) == 1:
        return [nums]

    # List to store all permutations
    result = []

    # Iterate through nums and recursively find permutations
    for i in range(len(nums)):
        # Take nums[i] as the first element
        current = nums[i]

        # Remaining elements except nums[i]
        remaining = nums[:i] + nums[i+1:]

        # Recursively find permutations of the remaining elements
        for p in permute(remaining):
            result.append([current] + p)

    return result

# Example usage
nums = [1, 2, 3]
print(permute(nums))
