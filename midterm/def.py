# allDict = {}
# midList = {}

# with open('alldefs', 'r') as allDefinitions:
# 	for line in allDefinitions:
# 		colonIndex = line.index(':')
# 		word = line[:colonIndex].lower()
# 		definition = line[colonIndex+1:].strip()
# 		allDict[word] = definition

# with open('middefs', 'r') as midDefinitions:
# 	for line in midDefinitions:
# 		word = line.strip().lower()
# 		if word in allDict:
# 			midList[word] = allDict[word]
# 		else:
# 			midList[word] = "Insert Definition Here"

# with open('midterm_definitions.txt', 'w') as outFile:
# 	for k, v in sorted(midList.items()):
# 		outFile.write(k + ": " + v + "\n")

unfinished = {}

with open('midterm_definitions.txt', 'r') as inFile:
	for line in inFile:
		colonIndex = line.index(':')
		word = line[:colonIndex].lower()
		definition = line[colonIndex+1:].strip()
		unfinished[word] = definition
with open('correct_midterm_words.txt', 'w') as outFile:
	with open('correct_midterm_just_defs.txt', 'w') as outFile2:
		for k, v in sorted(unfinished.items()):
			outFile.write(k + "\n")
			outFile2.write(v + "\n")

