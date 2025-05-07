class Solution:
    def romanToInt(self, s: str) -> int:
        romans = {
            "I": 1,
            "V": 5,
            "X": 10,
            "L": 50,
            "C": 100,
            "D": 500,
            "M": 1000,
        }
        sum = 0
        n = len(s)
        i = 0
        while i < n:
            if i < n - 1 and romans[s[i]] < romans[s[i + 1]]:
                sum += romans[s[i + 1]] - romans[s[i]]
                i += 2
            else:
                sum += romans[s[i]]
                i += 1
        return sum


def main():
    ch = input("enter the roman")
    print(Solution().romanToInt(ch))


if __name__ == "__main__":
    main()
