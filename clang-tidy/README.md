# Clang-Tidy sample

* Modernize: Simple sample, withoput compilation library. Run with `clang-tidy modernize.cpp -checks=modernize-*` or use the script `run-modernize.sh`

	```
	No compilation database found in /Users/Carlos.Jimenez/repos/personal/clang-tools-demo/clang-tidy or any parent directory
	fixed-compilation-database: Error while opening fixed database: No such file or directory
	json-compilation-database: Error while opening JSON database: No such file or directory
	Running without flags.
	9172 warnings generated.
	/Users/Carlos.Jimenez/repos/personal/clang-tools-demo/clang-tidy/modernize.cpp:5:5: warning: use a trailing return type for this function [modernize-use-trailing-return-type]
	int main()
	~~~ ^
	auto       -> int
	/Users/Carlos.Jimenez/repos/personal/clang-tools-demo/clang-tidy/modernize.cpp:9:5: warning: use range-based for loop instead [modernize-loop-convert]
	    for(int i = 0; i < v.size(); ++i) {
	    ^  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	       (int i : v)
	Suppressed 9170 warnings (9170 in non-user code).
	Use -header-filter=.* to display errors from all non-system headers. Use -system-headers to display errors from system headers as well.
	```
	