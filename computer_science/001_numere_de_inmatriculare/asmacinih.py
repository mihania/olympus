class Solution:
    def addDigits(self, n: int) -> int:
        while n >= 10:
            x = 0
            while n > 0:
                x += n % 10
                n = n // 10
            n = x

        return n
