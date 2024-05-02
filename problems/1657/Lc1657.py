from collections import Counter


class Solution:
    def closeStrings(self, word1: str, word2: str) -> bool:
        freq1 = Counter(word1)
        freq2 = Counter(word2)
        return (len(word1) == len(word2)
                and set(freq1.keys()) == set(freq2.keys())
                and sorted(freq1.values()) == sorted(freq2.values()))


if __name__ == '__main__':
    sol = Solution()

    word1 = 'abc'
    word2 = 'bca'
    result = sol.closeStrings(word1, word2)
    expected = True
    assert expected == result, f'expected {expected}, but {result}'

    word1 = 'a'
    word2 = 'aa'
    result = sol.closeStrings(word1, word2)
    expected = False
    assert expected == result, f'expected {expected}, but {result}'

    word1 = 'cabbba'
    word2 = 'abbccc'
    result = sol.closeStrings(word1, word2)
    expected = True
    assert expected == result, f'expected {expected}, but {result}'

    word1 = 'abbzccca'
    word2 = 'babzzczc'
    result = sol.closeStrings(word1, word2)
    expected = True
    assert expected == result, f'expected {expected}, but {result}'

    word1 = 'aaabbbbccddeeeeefffff'
    word2 = 'aaaaabbcccdddeeeeffff'
    result = sol.closeStrings(word1, word2)
    expected = False
    assert expected == result, f'expected {expected}, but {result}'

    word1 = 'uau'
    word2 = 'ssx'
    result = sol.closeStrings(word1, word2)
    expected = False
    assert expected == result, f'expected {expected}, but {result}'
