# ==============================================================================
#
#     Use:
#     decrypt("Zijvw Gnhvh!", "mysecretkey")
#     => "Hello World!"
#
# ==============================================================================


def decrypt(initial, key):

	msg = []
	output = ''
	for char in initial:
		if ord(char) in range(65,91):
			msg.append((ord(char) - 65,0))
		elif ord(char) in range(97,123):
			msg.append((ord(char) - 97,1))
		else: msg.append(char)

	key = [ord(char) - 65 for char in key.lower()]



	for i in range(len(msg)):
		if type(msg[i]) == type(''): output += msg[i]
		else:
			value   = (msg[i][0] - key[i % len(key)]) % 26
			output += chr(value + 65 + msg[i][1] * 32)

	return output
