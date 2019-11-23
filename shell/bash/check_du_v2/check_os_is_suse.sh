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
