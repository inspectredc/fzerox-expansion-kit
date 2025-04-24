#!/usr/bin/env python3

def apply(config, args):
    config['baseimg'] = 'baserom.jp.z64dd'
    config['myimg'] = 'build/fzerox-expansion.jp.z64dd'
    config['mapfile'] = 'build/fzerox-expansion.jp.map'
    config['source_directories'] = ['./src','./include']
    config['objdump_flags'] = ['-M','reg-names=32']
    config['makeflags'] = ["KEEP_MDEBUG=1"]
