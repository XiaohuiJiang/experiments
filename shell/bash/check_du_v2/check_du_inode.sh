#!/bin/bash

. ./check_os_is_suse.sh

if [ $# != 1 ]; then echo "please input the start dir as parameter!";echo "example: $(basename $0) <path>"; exit 1; fi

top_dir=$1

echo -e "\nthe inodes used by echo subdir under $top_dir:\n"
total_inodes_of(){
total=0;
tmp_f=`mktemp tmp.XXXXXXXXXX`
find $1 -mount -type d -fprint $tmp_f
while read -r line; do n_inode=`ls -f -1 "$line" 2>/dev/null | wc -l`; echo "$n_inode    $line"; total=$(($total + $n_inode)); done < $tmp_f
rm $tmp_f
echo "$total in all"
}

tmp_inode=tmp.used_many_inodes
total_inodes_of  $top_dir | sort -nr -k 1 | head -n 10 | tee $tmp_inode;
