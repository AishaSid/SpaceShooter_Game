
import os

str1="g++ -c main.cpp" #enter 1st command here
str2="g++ main.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio" #2nd command
str3="./sfml-app" #3rd command

print(str1)
os.system(str1)
print(str2)
os.system(str2)
print(str3)
os.system(str3)
