def encrypt(initial, key):
  """ Use : encrypt("MESSAGEINCAPITALS", "keyword")
  => 'COWUUDNYXGCJFCQVW'
  """
  lkey = len(key)
  list1 = [ord(i) for i in key]
  list2 = [ord(i) for i in initial]
  output = ''
  for i in range(len(list2)):
    value = (list2[i] + list1[i % lkey]) % 26
    output += chr(value + 65)
  
  return output
