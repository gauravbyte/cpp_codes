def getFinalData(data, updates):
    n = len(data)
    a = [0 for _ in range(n + 1)]
    prefix_sum = [0 for _ in range(n)]

    for l, r in updates:
        # Since the problem used 1-indexed updates
        # l, r + 1 ----> l - 1, r
        a[l - 1] += 1
        a[r] -= 1

    prefix_sum[0] = a[0]
    for i in range(1, n):
        prefix_sum[i] = prefix_sum[i - 1] + a[i]

    return [
        -num if prefix_sum[i] % 2 == 1 else num for i, num in enumerate(data)
    ]



def solve(s, k):
    res = []
    for c in s:
        opt = min((ord(c)-ord('a'))%26,(ord('a')-ord(c))%26) 
        if opt > k:
            res.append(chr(ord(c)-k))
        else:
            res.append('a')
        k -= min(k, opt)
    return "".join(res)
print(solve("bdzz", 2))


from collections import Counter
def solve(nums, d):
    n = len(nums)
    counter = Counter()
    res = 0
    for j in range(n-2,-1,-1):
        counter[nums[j+1]%d] += 1
        for i in range(j):
            res += counter[-(nums[i]+nums[j])%d] 
    return res
print(solve([3,3,4,7,8], 5))