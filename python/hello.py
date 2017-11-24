#!/usr/bin/env python -Qnew
# -*- coding: utf-8; mode: python; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- vim:fenc=utf-8:ft=python:et:sw=4:ts=4:sts=4

import getopt
import sys


def usage():
    print '''
NAME
    description
Usage
    python program.py [options]
'''


if __name__ == '__main__':
    try:
        opts, args = getopt.getopt(sys.argv[1:], "hf:", ["help", "file="])
    except getopt.GetoptError as err:
        # print help information and exit:
        print str(err) # will print something like "option -a not recognized"
        usage()
        sys.exit(2)

    file = ""

    for o, a in opts:
        if o in ("-h", "--help"):
            usage()
            sys.exit()
        elif o in ("-f", "--file"):
            file = a
        else:
            assert False, "unhandled option"

    print "hello world"

    sys.stdout.write("Haha by stdout\n")

    print 1 + 2 * 4

    import os

    print os.getcwd()

    for root,dirs,files in os.walk('./'):
        print 'root: ', root, 'dirs: ', dirs, 'files: ', files

    #os.system('./hello.py')
    os.system('ls -l')
    #example to read stdout from another process
    ppp = os.popen('ls -l')
    print ppp.read()
    help('file.read')
    help('ppp.read')
    print dir(ppp)
    ppp.close()

    print 'try -Qnew div method at cmdline:'
    print "3/2=", 3/2, "3//2=", 3//2
    print "3.0/2=", 3.0/2, "3.0//2=", 3.0//2
