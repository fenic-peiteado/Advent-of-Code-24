import sys


datos = sys.stdin.read().strip()
lines = datos.split('\n')
counts = 0
counts2 = 0
# Solucion alternativa para comprobar metodos de python
# Slice
# Sorted
for i in lines:
  le = list(map(int,i.split()))
  exist_solution = False
  for i in range(len(le)):
    le_short = le[:i] + le[i+1:]
    type_or = (le_short == sorted(le_short) or le_short == sorted(le_short, reverse=True))
    check = True
    for i in range(len(le_short)-1):
      dif = abs(le_short[i] - le_short[i+1])
      if (not( 1 <= dif <= 3 )):
        check = False
    if (check and type_or):
      exist_solution = True
  if(exist_solution):
   counts2 += 1   
print(counts2)
