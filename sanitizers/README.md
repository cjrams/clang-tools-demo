# Sanitizers sample

* Memory sanitizer: Compile the application `clang++ -O1 -g -fsanitize=address -fno-omit-frame-pointer example_UseAfterFree.cc` and the run the appplication`./a.out`. Or run the script `address-sanitizer.sh`

	```
	=================================================================
	==22719==ERROR: AddressSanitizer: heap-use-after-free on address 0x614000000044 at pc 0x00010bfddf48 bp 0x7ffee3c227c0 sp 0x7ffee3c227b8
	READ of size 4 at 0x614000000044 thread T0
	    #0 0x10bfddf47 in main DeletedMemory.cpp:4
	    #1 0x7fff72e3f7fc in start (libdyld.dylib:x86_64+0x1a7fc)
	
	0x614000000044 is located 4 bytes inside of 400-byte region [0x614000000040,0x6140000001d0)
	freed by thread T0 here:
	    #0 0x10c035d4d in wrap__ZdaPv (libclang_rt.asan_osx_dynamic.dylib:x86_64h+0x51d4d)
	    #1 0x10bfddf0e in main DeletedMemory.cpp:3
	    #2 0x7fff72e3f7fc in start (libdyld.dylib:x86_64+0x1a7fc)
	
	previously allocated by thread T0 here:
	    #0 0x10c03593d in wrap__Znam (libclang_rt.asan_osx_dynamic.dylib:x86_64h+0x5193d)
	    #1 0x10bfddf03 in main DeletedMemory.cpp:2
	    #2 0x7fff72e3f7fc in start (libdyld.dylib:x86_64+0x1a7fc)
	
	SUMMARY: AddressSanitizer: heap-use-after-free DeletedMemory.cpp:4 in main
	Shadow bytes around the buggy address:
	  0x1c27ffffffb0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
	  0x1c27ffffffc0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
	  0x1c27ffffffd0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
	  0x1c27ffffffe0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
	  0x1c27fffffff0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
	=>0x1c2800000000: fa fa fa fa fa fa fa fa[fd]fd fd fd fd fd fd fd
	  0x1c2800000010: fd fd fd fd fd fd fd fd fd fd fd fd fd fd fd fd
	  0x1c2800000020: fd fd fd fd fd fd fd fd fd fd fd fd fd fd fd fd
	  0x1c2800000030: fd fd fd fd fd fd fd fd fd fd fa fa fa fa fa fa
	  0x1c2800000040: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
	  0x1c2800000050: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
	Shadow byte legend (one shadow byte represents 8 application bytes):
	  Addressable:           00
	  Partially addressable: 01 02 03 04 05 06 07 
	  Heap left redzone:       fa
	  Freed heap region:       fd
	  Stack left redzone:      f1
	  Stack mid redzone:       f2
	  Stack right redzone:     f3
	  Stack after return:      f5
	  Stack use after scope:   f8
	  Global redzone:          f9
	  Global init order:       f6
	  Poisoned by user:        f7
	  Container overflow:      fc
	  Array cookie:            ac
	  Intra object redzone:    bb
	  ASan internal:           fe
	  Left alloca redzone:     ca
	  Right alloca redzone:    cb
	  Shadow gap:              cc
	==22719==ABORTING
	Abort trap: 6
	```
* Thread sanitizer: Compile the application `clang -fsanitize=thread -g -O1 tiny_race.c`  and the run the appplication`./a.out`. Or run the script `thread-sanitizer.sh`

	```
	==================
	WARNING: ThreadSanitizer: data race (pid=24280)
	  Write of size 4 at 0x00010aec5048 by main thread:
	    #0 main tiny_race.c:10 (a.out:x86_64+0x100000ea9)
	
	  Previous write of size 4 at 0x00010aec5048 by thread T1:
	    #0 Thread1 tiny_race.c:4 (a.out:x86_64+0x100000e51)
	
	  Location is global 'Global' at 0x00010aec5048 (a.out+0x000100002048)
	
	  Thread T1 (tid=122760, finished) created by main thread at:
	    #0 pthread_create <null> (libclang_rt.tsan_osx_dynamic.dylib:x86_64h+0x8b0d)
	    #1 main tiny_race.c:9 (a.out:x86_64+0x100000e9a)
	
	SUMMARY: ThreadSanitizer: data race tiny_race.c:10 in main
	==================
	ThreadSanitizer: reported 1 warnings
	Abort trap: 6

	```

* Memory sanitizer: Compile the application `clang -fsanitize=memory -fno-omit-frame-pointer -g -O2 umr.cc`  and the run the appplication`./a.out`. Or run the script `memory-sanitizer.sh`. Sadly this sanitizer in not working on osx.

* Undefined Behavior sanitizer: Compile the application `clang++ -fsanitize=undefined test.cc`  and the run the appplication`./a.out`. Or run the script `ub-sanitizer.sh`. 
	
	```
	test.cc:3:5: runtime error: signed integer overflow: 2147483647 + 1 cannot be represented in type 'int'
	```
All tests results samples were compiled and run on OSX with `clang++` version 9.0.1

Original files for samples from clang documentation

 * [Address sanitizer](https://clang.llvm.org/docs/AddressSanitizer.html)
 * [Thead sanitizer](https://clang.llvm.org/docs/ThreadSanitizer.html)
 * [Memory sanitizer](https://clang.llvm.org/docs/MemorySanitizer.html)
 * [Undefined Behaviour sanitizer](https://clang.llvm.org/docs/UndefinedBehaviorSanitizer.html)
 * [Data flow sanitizer](https://clang.llvm.org/docs/DataFlowSanitizer.html)
