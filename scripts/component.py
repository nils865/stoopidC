import os

src = os.path.join("src")

name = input("Enter the name of the component: ")
path = os.path.join(src, input("Enter the parent folder: "), name)

if not os.path.isdir(path):
    os.makedirs(path)
    
with open(os.path.join(".", path, name + ".c"), "w") as f:
    f.write("")

header = ""

if '_' in name:
    header = "#ifndef " + name.upper() + "_H\n" + "#define " + name.upper() + "_H\n\n" + "#endif"
else:
    headerName = ""
    
    for i in name:
        if i.isupper():
            headerName += "_"
        headerName += i.upper()
        
    header = "#ifndef " + headerName + "_H\n" + "#define " + headerName + "_H\n\n" + "#endif"

with open(os.path.join(path, name + ".h"), "w") as f:
    f.write(header)
