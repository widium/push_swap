import random
from pathlib import Path
import json
import sys

min = sys.argv[1]
max = sys.argv[2]
pop = sys.argv[3]

generate = random.sample(range(int(min), int(max)), int(pop))

file = "number.log"
BASE_DIR = Path(__file__).resolve().parents[0]
BASE_FILE = BASE_DIR / file

space = ""
for n in generate:
    space = f"{space} {n}"
BASE_FILE.write_text(space)

print(space)
# with open(BASE_FILE,"w") as f :
#     json.dump(generate, f, indent=2)

# print(*generate, sep = ' ')

