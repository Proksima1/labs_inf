from sys import argv
LENGTH_WORD = int(argv[-1])
with open('data.txt') as reader:
    data = reader.read()
    data = data.replace('\n', ' ')
    data = data.replace('\t', ' ')
    data = data.split()
count = 0
for i in data:
    countLetters = 0
    for j in i:
        if j.isalpha():
            countLetters += 1
    if countLetters <= LENGTH_WORD:
        count += 1
print(count)
