import os

src = os.path.join("src")

name = input("Enter the name of the component: ")
path = os.path.join(src, input("Enter the parent folder: "), name)

if not os.path.isdir(path):
    os.makedirs(path)
    
with open(os.path.join(".", path, name + ".c"), "w") as f:
    f.write("")

with open(os.path.join(path, name + ".h"), "w") as f:
    f.write("")
