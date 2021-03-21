#!/bin/bash

date;

head /proc/*/stack;
cat /proc/*/stat;
cat /proc/stat;

echo -e "\n---------------------\n"

#>> /var/log/kernel-monitor-$(date +\%F) 2>&1

#建议部署一个crontab， 定时收集内核的stack：
#crontab -u root -l
#*/2 * * * * /root/temp/sh_scripts/kernel-monitor.sh >> /var/log/kernel-monitor-$(date +\%F) 2>&1
#11 22 * * * find /var/log/ -name kernel-monitor-* -mtime +30  -exec rm {} \;


