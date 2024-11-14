# -*- coding: utf-8 -*-
"""
This script automatically organize my file in a more reasonable manner.
"""


import subprocess
import os
import shutil

print(os.listdir())
print(os.getcwd())
curdir = os.getcwd()

# for k in range(30):
#     os.mkdir(f"{curdir}/{k * 100:04}_{(k + 1) * 100 - 1:04}")
#     print(f"{curdir}/{k * 100:04}_{(k + 1) * 100 - 1:04}")
#
for file in os.listdir():
    if os.path.isfile(file):
        if file.startswith("leetcode-no") and not file.endswith(".exe"):
            filename = file.split(".")[0]
            nums = int(filename[11:].strip("_"))
            if nums < 3000:
                nums = nums - nums % 100
                result = subprocess.run(["git", "mv", f"{curdir}/{file}", f"{curdir}/{nums:04}_{nums + 99:04}/{file}"])
