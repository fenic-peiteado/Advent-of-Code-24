import sys


datos = sys.stdin.read().strip()

lines = datos.split('\n')
left = []
right = []
map_right = {}
for i in lines:
  element = i.split()
  print(element)
  left.append(int(element[0]))
  right.append(int(element[1]))
  map_right[int(element[1])] = map_right.get(int(element[1]), 0) + 1

left = sorted(left)
right = sorted(right)
print(left)
print(right)
result = 0
result2 = 0
for i in range(0, len(left)):
  result +=  abs(left[i] - right[i])
for i in range(0, len(left)):
  result2 += int(left[i]) * map_right.get(left[i], 0)
print(result)
print(result2)