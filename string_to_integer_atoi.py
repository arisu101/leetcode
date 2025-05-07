""""
  algorithm :
  whitespace : ignore any whitespace (" ")
  sign : determine the sign of int by checkint "-" or "+"
  conversion : read the integer by skipping any zero until a non-zero digit is
  encountered :: if no digit were read, the result is 0  round : if the integer
  is out of 32 bit range round to it's nearest :: as if int < -2^31, then round
  to -2^31 else if int > 2^31 - 1 round to 2^31 - 1
"""


class Solution:
    def myAtoi(self, s: str) -> int:
        INT_MIN, INT_MAX = -(2**31), 2**31 - 1

        i, n = 0, len(s)
        sign = 1

        while i < n and s[i] == " ":
            i += 1

        if i < n and (s[i] == "+" or s[i] == "-"):
            sign = -1 if s[i] == "-" else 1
            i += 1

        result = 0
        while i < n and s[i].isdigit():
            digit = int(s[i])
            if result > (INT_MAX - digit) // 10:
                return INT_MAX if sign == 1 else INT_MIN
            result = result * 10 + digit
            i += 1

        result *= sign

        if result < INT_MIN:
            return INT_MIN
        if result > INT_MAX:
            return INT_MAX

        return result


def main():
    test = "0-1"
    print(Solution().myAtoi(test))


if __name__ == "__main__":
    main()
