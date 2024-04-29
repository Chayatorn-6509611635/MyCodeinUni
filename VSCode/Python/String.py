'''
    index of str start at 0 and end with length-1
    len(name) => length of str (int)
    name.strip() => delete space of first and last index
    name.lower() => convert str to lowercase
    name.capitalize() => convert first letter to uppercase
    name.replace("a","b") => replace str a in name with letter b
    "a" in name => check if name has str a (Boolean)
    name.count("a") => count how many "a" in name (int)
    name.startwith("a") => check if name starts with "a" (Boolean)
    name.endwith("a") => check if name ends with "a" (Boolean)
'''

name = "anfield.cyt"
char = 'A'
print(name[0]) #print character index of 0
print(name[6]) #print character index of 6

print(name[0:3]) #print index 0 to 2
print(name[:3]) #same as above

print(name[-3]) #print index length - 3

print(len(name))
print(name.capitalize())
print(name.upper())

champion = " Kaisa "
print(len(champion))
champion = champion.strip()
print(len(champion))

print(champion)
print(champion.replace("Kai", "May"))

sentence = "I am a boy"
if "boy" in sentence:
    print(sentence.replace("boy", "girl"))
    
x = 'a' not in sentence # sentence has 'a'
print(x)

fname = "anfield "
lname = "cyt "
age = 80
fullname = fname + lname + str(age) #only str + str (cast other datatype to str)
print(fullname)
f = 420.25231
text = "name: {0}\t surname: {2}\t age: {1}\t salary: {3:.2f}" # {} => scope of variable when use format( {index} => place variable at index)
print(text.format(fname, age, lname, f))

introduce = "Hi my name is Anfield. My lastname is cyt. Anfield is a name of Liverpool Stadium"
print(introduce.count("name")) # output => 2
print(introduce.count('a')) # case Sensitive