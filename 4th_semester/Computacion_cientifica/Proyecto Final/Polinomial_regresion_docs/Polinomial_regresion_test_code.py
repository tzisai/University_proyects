# +----------------------------------------------------------------------------+
# | CARDUI WORKS v1.0.0
# +----------------------------------------------------------------------------+
# | Copyright (c) 2024 - 2025, CARDUI.COM (www.cardui.com)
# | Vanessa Reteguín <vanessa@reteguin.com>
# | Released under the MIT license
# | www.cardui.com/carduiframework/license/license.txt
# +----------------------------------------------------------------------------+
# | Author.......: Vanessa Reteguín <vanessa@reteguin.com>
# | First release: May 30th, 2025
# | Last update..: June 2nd, 2025
# | WhatIs.......: Polinomial regresion test code - Main
# +----------------------------------------------------------------------------+

degree = 5
x = [0, 5, 10, 15, 20, 25, 30]
y = [0.0000, 1.5297, 9.5120, 8.7025, 2.8087, 1.0881, 0.3537]

sums = [len(x)]
temp = x

for i in range(1, degree*2 + 1):
    temp = [0, 5, 10, 15, 20, 25, 30]
    for j in range(0, len(temp)):
        temp[j] **= i
    sums.append(sum(temp))

print(f"sums: {sums}")

b = []

for i in range(0, len(x)):
    temp[i] = (x[i]**0) * y[i]
b.append(sum(temp))

for i in range(1, degree+1):
    for j in range(0, len(x)):
        temp[j] = (x[j]**i) * y[j]
    b.append(sum(temp))

print(f"b: {b}")

# matrix: 6 x 6 | 1 x 6
a  = []
for i in range(0, degree + 1):
    temp = []
    for j in range(i, degree + i + 1):
        temp.append(sums[j])
    a.append(temp)

print(f"a: {a}")
