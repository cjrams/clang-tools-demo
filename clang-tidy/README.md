# Clang-Tidy sample

* Modernize: Simple sample, without compilation library. Run with `clang-tidy modernize.cpp -checks=modernize-*` or use the script `run-modernize.sh`

	```
	No compilation database found in ../clang-tools-demo/clang-tidy or any parent directory
	fixed-compilation-database: Error while opening fixed database: No such file or directory
	json-compilation-database: Error while opening JSON database: No such file or directory
	Running without flags.
	9172 warnings generated.
	../clang-tools-demo/clang-tidy/modernize.cpp:5:5: warning: use a trailing return type for this function [modernize-use-trailing-return-type]
	int main()
	~~~ ^
	auto       -> int
	../clang-tools-demo/clang-tidy/modernize.cpp:9:5: warning: use range-based for loop instead [modernize-loop-convert]
	    for(int i = 0; i < v.size(); ++i) {
	    ^  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	       (int i : v)
	Suppressed 9170 warnings (9170 in non-user code).
	Use -header-filter=.* to display errors from all non-system headers. Use -system-headers to display errors from system headers as well.
	```
	
* Fix test with `clang-tidy modernize.cpp -checks=modernize-* --fix` or use the script `run-modernize-auto-fix.sh`
	
	Check the fixes applied, using clang-tidy 9.0.1 result is on the file `modernize.fixed.cpp`
	
* Removed on warning, test with `clang-tidy modernize.cpp -checks=modernize-*,-modernize-use-trailing-return-type` or use the script `run-modernize-no-trailing.sh`. Check one warning is removed, the one referring the usage of a trailing return type.
	
	```
	Error while trying to load a compilation database:
	Could not auto-detect compilation database for file "modernize.cpp"
	No compilation database found in ../clang-tools-demo/clang-tidy or any parent directory
	fixed-compilation-database: Error while opening fixed database: No such file or directory
	json-compilation-database: Error while opening JSON database: No such file or directory
	Running without flags.
	2123 warnings generated.
	../clang-tools-demo/clang-tidy/modernize.cpp:9:5: warning: use range-based for loop instead [modernize-loop-convert]
	    for(int i = 0; i < v.size(); ++i) {
	    ^  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	       (int i : v)
	Suppressed 2122 warnings (2122 in non-user code).
	Use -header-filter=.* to display errors from all non-system headers. Use -system-headers to display errors from system headers as well.
	```
	
* Finally we can run from a file using `clang-tidy modernize.cpp --config=` or `run-modernize-file.sh` script. To generate the configuration file you can run `clang-tidy -checks=-*,modernize-*,-modernize-use-trailing-return-type --dump-config > config.txt` ot the script `run-modernize-dump.sh`. For a reason this dump duplicates the checks from the config file `.clang-tidy` and the ones on the parameter list.
