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
#     try:
#         os.rmdir(f"{curdir}/{k * 100:04}_{(k + 1) * 100 - 1:04}")
#     except Exception:
#         pass

# for k in range(30):
#     os.mkdir(f"{curdir}/{k * 100:04}_{(k + 1) * 100 - 1:04}")

# chidirs = []
# for k in range(15):
#     chidirs.append(f"{curdir}/{k * 200:04}_{(k + 1) * 200 - 1:04}")
#
# for chidir in chidirs:
#     for file in os.listdir(f"{chidir}"):
#         if os.path.isfile(f"{chidir}/{file}"):
#             if file.startswith("leetcode-no") and not file.endswith(".exe"):
#                 filename = file.split(".")[0]
#                 nums = int(filename[11:])
#                 if nums < 3000:
#                     nums = nums - nums % 100
#                     result = subprocess.run(["git", "mv", f"{chidir}/{file}", f"{curdir}/{nums:04}_{nums + 99:04}/{file}"])
                    # print(["git", "mv", f"{chidir}/{file}", f"{curdir}/{nums:04}_{nums + 99:04}/{file}"])

# for file in os.listdir():
#     if os.path.isfile(file):
#         if file.startswith("leetcode-no") and not file.endswith(".exe"):
#             filename = file.split(".")[0]
#             nums = int(filename[11:])
#             if nums < 3000:
#                 nums = nums - nums % 200
#                 result = subprocess.run(["git", "mv", f"{curdir}/{file}", f"{curdir}/{nums:04}_{nums + 199:04}/{file}"])

for k in range(15):
    try:
        os.rmdir(f"{curdir}/{k * 200:04}_{(k + 1) * 200 - 1:04}")
    except Exception:
        pass
