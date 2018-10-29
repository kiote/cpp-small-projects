import random 

def pow(c):
  return 2**c

while (True):
  pow = random.randrange(1, 14)
  result = raw_input("2^" + str(pow) + "=?")
  if (2**pow == int(result)):
    print "yes"
  else:
    print "no it's " + str(2**pow)