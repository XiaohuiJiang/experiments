#!/bin/bash

#判断是否为SUSE操作系统
if [ ! -f "/etc/SuSE-release" -a ! -f "/etc/SUSE-brand" ];then echo "this is not SuSE Linux"; exit 1; fi


if [ $# != 1 ]; then echo "please input the start dir as parameter!";echo "example: $(basename $0) <path>"; exit 1; fi

top_dir=${1}

find_largest_dirs_then_files(){

#skip the dirs in "tmp.used_many_inodes"
tmp_inode=tmp.used_many_inodes
tmp_skip=tmp.skip_dirs
>$tmp_skip
if [ -f $tmp_inode ]; then
  awk '$1>100000 {for (i = 2; i < NF; ++i) printf $i" "; print $NF}' $tmp_inode >$tmp_skip
  [ -s $tmp_skip ] && echo -e "\nskip dirs:" && cat $tmp_skip && echo;
fi

tmp_f1=tmp.largest_dirs
tmp_f2=tmp.files
tmp_f3=tmp.largest_files

#echo -e "\nthe largest dirs under $1:(subdir is not included)\n"
du -k -x -S -X $tmp_skip "$1" | sort -nr -k 1 | head -n 10 | cut -f2 > $tmp_f1
#while read -r dir; do du -xshS -X $tmp_skip "$dir"; done < $tmp_f1

#echo -e "\nthe largest files under $1:\n"
>$tmp_f2
while read -r dir; do
#find "$dir" -maxdepth 1 -type f | xargs du -k | sort -nr -k 1 | head -n 10 | cut -f 2 >> $tmp_f2
find "$dir" -maxdepth 1 -type f >> $tmp_f2
done <$tmp_f1

while read -r file; do du -k "$file"; done <$tmp_f2 | sort -nr -k 1| head -n 10 | cut -f 2 >$tmp_f3
while read -r file; do du -sh "$file"; done < $tmp_f3
}

find_largest_dirs_then_files $top_dir
