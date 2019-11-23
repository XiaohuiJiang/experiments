#!/bin/bash

#判断是否为SUSE操作系统
if [ ! -f "/etc/SuSE-release" ];then echo "/etc/SuSE-release not exist"; exit 1; fi

#首先确定操作系统版本,备份fstsb文件
version=`cat /etc/SuSE-release |grep -i version|awk '{print $NF}'`

echo "OS version is $version"

#disable firewall service
if [ $version == 11 -o $version == 10 ]; then 
/sbin/rcSuSEfirewall2 stop
chkconfig SuSEfirewall2_init off
chkconfig SuSEfirewall2_setup off
fi

if [ $version == 12 ]; then
 systemctl stop SuSEfirewall2
 systemctl disable SuSEfirewall2
 systemctl status SuSEfirewall2
 fi

#echo "clear existing iptables rules"
iptables -F
iptables -X
iptables -Z

echo "show iptables rules before changing, defaut accept all"
iptables -L -n -v

echo "set global rules"
iptables -A INPUT -s 127.0.0.1 -d 127.0.0.1 -j ACCEPT               #允许本地回环接口(即运行本机访问本机)
iptables -A INPUT -m state --state ESTABLISHED,RELATED -j ACCEPT    #允许已建立的或相关连的通行
iptables -A OUTPUT -j ACCEPT         #允许所有本机向外的访问
iptables -A INPUT -p icmp -j ACCEPT    #允许icmp

echo "enable tcp and udp ports"
function enable_ports () {
iptables -A INPUT -p tcp --dport $1 -j ACCEPT    #允许访问22端口
iptables -A INPUT -p udp --dport $1 -j ACCEPT    #允许访问22端口
}

enable_ports 21:22
enable_ports 30000:30200


echo "disable all others INPUT and FORWARD"
iptables -A INPUT -j REJECT       #禁止其他未允许的规则访问
iptables -A FORWARD -j REJECT     #禁止其他未允许的规则访问

echo "show iptables rules after changing"
iptables -L -n -v
