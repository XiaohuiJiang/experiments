#!/bin/bash

#判断是否为SUSE操作系统
if [ ! -f "/etc/SuSE-release" -a ! -f "/etc/SUSE-brand" ];then echo "this is not SuSE Linux"; exit 1; fi

#首先确定操作系统版本
if [ -f "/etc/SuSE-release" ]; then
version=$(cat /etc/SuSE-release |grep -i version|awk '{print $NF}');
else
version=$(cat /etc/os-release | grep -i version_id | awk -F '"' '{print $2}' | awk -F '.' '{print $1}');
fi

echo "OS version is $version"

if [ $# != 1 ]; then echo "please input the start dir as parameter!";echo "example: $(basename $0) <path>"; exit 1; fi

top_dir=$1

echo -e "\nthe largest dirs under $top_dir:(subdir is not included)\n"
largest_dirs=$(du -k -x -S $top_dir | sort -nr -k 1 | head -n 20 | cut -f 2)
#echo $largest_dirs | sed -e "s/ /\n/g"
for dir in $largest_dirs; do
du -xshS $dir;
done


echo -e "\nthe largest files under $top_dir:\n"
files=""
for dir in $largest_dirs; do
files_t=$(find $dir -maxdepth 1 -type f | xargs du -k | sort -nr -k 1 | head -n 20 | cut -f 2)
files="$files $files_t"
done

#echo $files | sed -e "s/ /\n/g"

largest_files=$(du -k $files | sort -nr -k 1 | head -n 20 | cut -f 2)
#echo $largest_files | sed -e "s/ /\n/g"
du -h $largest_files

echo -e "\nthe inodes used by echo subdir under $top_dir:\n"
total_inodes_of(){
total=0;
tmp_f=`mktemp tmp.XXXXXXXXXX`
find $1 -mount -type d -fprint $tmp_f
while read -r line; do n_inode=`ls -1 $line 2>/dev/null | wc -l`; echo "$n_inode    $line"; total=$(($total + $n_inode)); done < $tmp_f
rm $tmp_f
echo "$total in all"
}
if [ $version -ge 12 ]; then
du --inode  -S -x $top_dir | sort -nr -k 1 | head -n 20;
else
total_inodes_of  $top_dir | sort -nr -k 1 | head -n 20;
fi
