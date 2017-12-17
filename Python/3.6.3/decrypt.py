def decrypt():
  initial = input('Give the message to encrypt (CAPITALS - no space or special characters) : ')
  key = input('Give the key (lowercase letters - no space or special characters) : ')
  lkey = len(key)
  numeros1 = [ord(i) for i in key]
  numeros2 = [ord(i) for i in initial]
  output = ''
  for i in range(len(numeros2)):
    value = (numeros2[i] - numeros1[i % lkey]) % 26
    output += chr(value + 65)
  print('The decrypted message is : ' + output)
