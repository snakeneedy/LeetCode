class Solution:
    def removeStars(self, s: str) -> str:
        lst = []
        for w in s:
            if w == '*':
                lst.pop()
            else:
                lst.append(w)
        return ''.join(lst)


if __name__ == '__main__':
    sol = Solution()
    s = 'leet**cod*e'
    result = sol.removeStars(s)
    expected = 'lecoe'
    assert expected == result, f'expected {expected}, but {result}'

    s = 'erase*****'
    result = sol.removeStars(s)
    expected = ''
    assert expected == result, f'expected {expected}, but {result}'
