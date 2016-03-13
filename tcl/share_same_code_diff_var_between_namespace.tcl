#!/usr/bin/env tclsh

#define proc code as a string, eval the string in different namespace.
#in this way same code can handle different valules in each namespace.
#similiar to #define a MACRO in C language

set a_proc {proc a {} { variable b; puts "hah $b"}}
namespace eval fff { variable b 9;}
namespace eval fff {eval $::a_proc}
namespace eval ttt { variable b 5;}
namespace eval ttt {eval $::a_proc}
fff::a
ttt::a
