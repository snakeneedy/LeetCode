class RecentCounter:
    """
    Your RecentCounter object will be instantiated and called as such:
    obj = RecentCounter()
    param_1 = obj.ping(t)
    """

    def __init__(self):
        self.requests = []
        self.pos = 0

    def ping(self, t: int) -> int:
        rangeMin = t - 3000
        self.requests.append(t)
        while self.requests[self.pos] < rangeMin:
            self.pos += 1
        return len(self.requests) - self.pos


if __name__ == '__main__':
    obj = RecentCounter()
    tList = [1, 100, 3001, 3002]
    expectedList = [1, 2, 3, 3]
    for pos, t in enumerate(tList):
        result = obj.ping(t)
        expected = expectedList[pos]
        assert expected == result, f'expected {expected}, but {result}'
