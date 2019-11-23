#!/bin/bash

date=`date -d '2 days ago' +%Y-%m-%d`
declare -a files
files=`find /data1/error/error-${date}_* -type f`
Npro=10 #并行10个子进程压缩
Pfifo="/tmp/$$.fifo"
mkfifo $Pfifo # 新建一个fifo类型的文件
exec 6<>$Pfifo # 将fd 6指向该文件
rm -f $Pfifo
for((i=1; i<=$Npro; i++)); do
        echo
done >&6 # 在fd 6指向的文件中放置$Npro个回车符，作为令牌

for file in $files
do
        read -u6 #从fd 6中读出减去一个回车符，然后向下执行
                    #如果fd 6中没有回车符了，进程阻塞在这儿
        {
                gzip -9 $file
                mv $file.gz /data1/error/$date/
                echo >&6 #向fd6加上一个回车符
        } & #花括号体内的程序后台运行
done
wait
exec 6>&- #关闭fd6