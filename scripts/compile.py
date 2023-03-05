###########################
# How to use
# 
# compile with `python3 scripts/compile.py`
#
# Args:
#  - smart          only compiles files that have been modified
#  - all            compiles all files
#  - --no-col       disables colors in the output
###########################

import hashlib, os, json, subprocess, sys, time

start_time = time.perf_counter()

MODE = sys.argv[1]
COMPILER = sys.argv[2]

if len(sys.argv) < 4:
    COL_MODE = ""
else:
    COL_MODE = sys.argv[3]

if "--no-col" == COL_MODE:
    COL_RESET = ""
    COL_GREEN = ""
else:
    COL_RESET = "\u001b[0m"
    COL_GREEN = "\u001b[32m"

print("\n--------------------------------\n")

# get all files
filelist = []
filetypes = (".c", ".cpp")

def getFiles(path):
    global filelist, filetypes
    
    files = os.listdir(path)
    
    for f in files:
        if f.endswith(filetypes):
            filelist.append(os.path.join(path, f))
        elif os.path.isdir(os.path.join(path, f)):
            getFiles(os.path.join(path, f))
    
getFiles(os.path.join("src"))

if not os.path.isdir(os.path.join("bin")):
    os.mkdir("bin")

# get filehash
hashlist = {}

def getHash(file):
    with open(file, 'rb') as opened:
        content = opened.read()
        md5 = hashlib.md5()
        md5.update(content)
        return md5;
 
for f in filelist:
    hashlist[f] = getHash(f).hexdigest()
    
def compile(name):
    print(f'Compiling {COL_GREEN + name + COL_RESET}')
    p = subprocess.Popen([COMPILER, "-Wall", "-c", os.path.join("..", name)], cwd=os.path.join("bin"))
    print(f'finished compiling {COL_GREEN + name + COL_RESET}\n')

# compare filehashes and compile if needed
if "smart" == MODE:
    if os.path.isfile(os.path.join("bin", "hashlist.json")):
        with open(os.path.join("bin", "hashlist.json"), "r") as f:
            oldhashlist = json.load(f)
            
            for n in hashlist:
                if n in oldhashlist:
                    if hashlist[n] != oldhashlist[n]:
                        compile(n)
                else:
                    compile(n)
    else:
        for n in hashlist:
            compile(n)
            
elif "all" == MODE:
    for n in hashlist:
        compile(n)
else:
    print("Error")
    exit(0)
    
# if on windows
if os.name == "nt":
    os.system(f'windres .rc -o {os.path.join("bin", "project_data.o")}')
else:
    os.system(f'objcopy --input binary --output elf32-i386 --binary-architecture i386 icon.ico {os.path.join("bin", "project_data.o")}')
            
# save file hash in file
with open(os.path.join("bin", "hashlist.json"), 'w') as f:
    f.write(json.dumps(hashlist, indent=4))
    
if not os.path.isdir(os.path.join("build")):
    os.mkdir("build")

print("--------------------------------\n")
print(f'Compiling Executable in {COL_GREEN + os.path.join("build") + COL_RESET} as {COL_GREEN}stoopid{COL_RESET}')

os.system(f'{COMPILER} -o {os.path.join("build", "stoopid")} {os.path.join("bin", "*.o")}')

print(f'Finished compiling executable at {COL_GREEN + os.path.join("build", "stoopid") + COL_RESET}')

print("\n--------------------------------\n")
print(f'Compilation took {round(time.perf_counter() - start_time, 2)}s\n')
