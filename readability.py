from cs50 import get_string

text = get_string('Text: ')
i = 0
let = 0
word = 1
sent = 0
for i in range(len(text)):
    if text[i].isalpha():
        let += 1
    elif text[i] == ' ' and text[i + 1]:
        word += 1
    elif text[i] == '?' or text[i] == '!' or text[i] == '.':
        sent += 1

L = float(let / word * 100)
S = float(sent / word * 100)
index = round((float)(0.0588 * L - 0.296 * S - 15.8))
if (index >= 16):
    print('Grade 16+')
elif (index < 1):
    print('Before Grade 1')
else:
    print('Grade', index)