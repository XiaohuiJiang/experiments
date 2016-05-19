#!/usr/bin/tclsh

set fifo_name /tmp/fifo.[pid]
set es200_script_path [file dirname [info script]]

exec mkfifo $fifo_name
set fd_script [open "| $es200_script_path/es200_traffic.exp $fifo_name" r]

set wr [open $fifo_name w]

puts $wr "asdfasdhgqwjhg;sahg;"
flush $wr
puts [gets $fd_script]

#example code to send message from this tcl script to a FIFO($fifo_name),
#the message can be get by another script(es200_traffic.exp)
#this script can get the output from another script by PIPE

