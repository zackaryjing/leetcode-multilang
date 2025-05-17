#!/bin/bash

declare -a cols  # 用来存储转置后的列

# 读取文件内容
while IFS=' ' read -r -a row; do
    for i in "${!row[@]}"; do
        cols[i]="${cols[i]:-}${cols[i]:+ }${row[i]}";
    done
done < file.txt  # 从文件中读取内容

# 打印转置后的结果
for col in "${cols[@]}"; do
    echo "$col"
done

# 测试文件必须是LF结尾的（因为我是在wsl运行的，并且最后一行必须要有回车，否则不会读取最后一行）