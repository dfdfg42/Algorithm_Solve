import sys
from math import gcd
def input(): return sys.stdin.readline().strip()


class Fraction:
    def __init__(self, up, down):
        self.up = up
        self.down = down

    def __add__(self, other):
        new_down = self.down * other.down
        new_up = self.up * other.down + other.up * self.down
        g = gcd(new_up, new_down)
        return Fraction(new_up // g, new_down // g)

    def div(self, other):
        new_down = other.up * self.down
        new_up = other.down * self.up
        g = gcd(new_up, new_down)
        return Fraction(new_up//g, new_down//g)


n = int(input())

s = input().replace(" ", "")
c = 0
ok = 1
for i in s:
    if i == '(':
        c += 1
    elif i == ')':
        c -= 1
    if c < 0:
        ok = 0
if not ok or c:
    print(-1)
    exit(0)
ix = 0


def func():
    global ix
    ix += 1
    if s[ix] == '(':
        a = func()
    else:
        a = Fraction(int(s[ix]), 1)
        ix += 1
    if s[ix] == '(':
        b = func()
    else:
        b = Fraction(int(s[ix]), 1)
        ix += 1
    if s[ix] == '(':
        c = func()
    else:
        c = Fraction(int(s[ix]), 1)
        ix += 1
    if s[ix] != ')':
        assert 0
    ix += 1
    return a + b.div(c)

try:
    ans = func()
except:
    print(-1)
    exit(0)
if ix != len(s):
    print(-1)
    exit(0)
g = gcd(ans.up, ans.down)
print(ans.up //g , ans.down // g)